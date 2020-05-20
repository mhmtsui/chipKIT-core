/*******************************************************************************
  Direct Memory Access Controller (DMAC) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_dmac.c

  Summary
    Source for DMAC peripheral library interface Implementation.

  Description
    This file defines the interface to the DMAC peripheral library. This
    library provides access to and control of the DMAC controller.

  Remarks:
    None.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include <p32xxxx.h>
#include "wiring.h"
#include "wiring_private.h"
#include "plib_dmac.h"

void DMA0_InterruptHandler( void );
void DMA1_InterruptHandler( void );
void DMA2_InterruptHandler( void );
void DMA3_InterruptHandler( void );
void DMA4_InterruptHandler( void );
void DMA5_InterruptHandler( void );
void DMA6_InterruptHandler( void );
void DMA7_InterruptHandler( void );

/* All the handlers are defined here.  Each will call its PLIB-specific function. */
void __USER_ISR DMA0_Handler (void)
{
    DMA0_InterruptHandler();
}

void __USER_ISR DMA1_Handler (void)
{
    DMA1_InterruptHandler();
}

void __USER_ISR DMA2_Handler (void)
{
    DMA2_InterruptHandler();
}

void __USER_ISR DMA3_Handler (void)
{
    DMA3_InterruptHandler();
}

void __USER_ISR DMA4_Handler (void)
{
    DMA4_InterruptHandler();
}

void __USER_ISR DMA5_Handler (void)
{
    DMA5_InterruptHandler();
}

void __USER_ISR DMA6_Handler (void)
{
    DMA6_InterruptHandler();
}

void __USER_ISR DMA7_Handler (void)
{
    DMA7_InterruptHandler();
}

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

static DMAC_CHANNEL_OBJECT  gDMAChannelObj[8];

#define KVA_TO_PA(v)  ((v) & 0x1fffffff)
#define PA_TO_KVA0(pa)  ((pa) | 0x80000000)  // cachable
#define PA_TO_KVA1(pa)  ((pa) | 0xa000000

#define ConvertToPhysicalAddress(a) ((uint32_t)KVA_TO_PA(a))
#define ConvertToVirtualAddress(a)  PA_TO_KVA1(a)

// *****************************************************************************
// *****************************************************************************
// Section: DMAC PLib Local Functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
   static void DMAC_ChannelSetAddresses

  Summary:
    Converter to physical start addresses for DMA address registers to use

  Description:
    Calculates physical start addresses and stores into source and destination
    address registers DCHxSSA and DCHxDSA.

  Parameters:
    DMAC_CHANNEL channel - DMA channel this function call pertains to
    const void *srcAddr - starting address of source buffer to transfer
    const void *destAddr - starting address of destination buffer to transfer

  Returns:
    void
*/
static void DMAC_ChannelSetAddresses( DMAC_CHANNEL channel, const void *srcAddr, const void *destAddr)
{
    uint32_t sourceAddress = (uint32_t)srcAddr;
    uint32_t destAddress = (uint32_t)destAddr;
    volatile uint32_t * regs;

    /* Set the source address */
    /* Check if the address lies in the KSEG2 for MZ devices */
    if ((sourceAddress >> 29) == 0x6)
    {
        if ((sourceAddress >> 28)== 0xc)
        {
            // EBI Address translation
            sourceAddress = ((sourceAddress | 0x20000000) & 0x2FFFFFFF);
        }
        else if((sourceAddress >> 28)== 0xD)
        {
            //SQI Address translation
            sourceAddress = ((sourceAddress | 0x30000000) & 0x3FFFFFFF);
        }
    }
    else if ((sourceAddress >> 29) == 0x7)
    {
        if ((sourceAddress >> 28)== 0xE)
        {
            // EBI Address translation
            sourceAddress = ((sourceAddress | 0x20000000) & 0x2FFFFFFF);
        }
        else if ((sourceAddress >> 28)== 0xF)
        {
            // SQI Address translation
            sourceAddress = ((sourceAddress | 0x30000000) & 0x3FFFFFFF);
        }
    }
    else
    {
        /* For KSEG0 and KSEG1, The translation is done by KVA_TO_PA */
        sourceAddress = ConvertToPhysicalAddress(sourceAddress);
    }

    /* Set the source address, DCHxSSA */
    regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60 + (channel * 0xC0) + 0x30);
    *(volatile uint32_t *)(regs) = sourceAddress;

    /* Set the destination address */
    /* Check if the address lies in the KSEG2 for MZ devices */
    if ((destAddress >> 29) == 0x6)
    {
        // EBI Address translation
        if ((destAddress >> 28)== 0xc)
        {
            destAddress = ((destAddress | 0x20000000) & 0x2FFFFFFF);
        }
        //SQI Address translation
        else if ((destAddress >> 28)== 0xd)
        {
            destAddress = ((destAddress | 0x30000000) & 0x3FFFFFFF);
        }
    }
    else if ((destAddress >> 29) == 0x7)
    {   /* Check if the address lies in the KSEG3 for MZ devices */
        // EBI Address translation
        if ((destAddress >> 28)== 0xe)
        {
            destAddress = ((destAddress | 0x20000000) & 0x2FFFFFFF);
        }
        //SQI Address translation
        else if ((destAddress >> 28)== 0xf)
        {
            destAddress = ((destAddress | 0x30000000) & 0x3FFFFFFF);
        }
    }
    else
    {
        /*For KSEG0 and KSEG1, The translation is done by KVA_TO_PA */
        destAddress = ConvertToPhysicalAddress(destAddress);
    }

    /* Set destination address, DCHxDSA */
    regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60 + (channel * 0xC0) + 0x40);
    *(volatile uint32_t *)(regs) = destAddress;
}

// *****************************************************************************
// *****************************************************************************
// Section: DMAC PLib Interface Implementations
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
void DMAC_Initialize(DMAC_CHANNEL chn, uint8_t vec){
  switch (chn){
    case DMAC_CHANNEL_0:
      DMA0_Initialize(vec);
    break;
    case DMAC_CHANNEL_1:
      DMA1_Initialize(vec);    
    break;
    case DMAC_CHANNEL_2:
      DMA2_Initialize(vec);    
    break;
    case DMAC_CHANNEL_3:
      DMA3_Initialize(vec);    
    break;
    case DMAC_CHANNEL_4:
      DMA4_Initialize(vec);    
    break;
    case DMAC_CHANNEL_5:
      DMA5_Initialize(vec);    
    break;
    case DMAC_CHANNEL_6:
      DMA6_Initialize(vec);
    break;
    case DMAC_CHANNEL_7:
      DMA7_Initialize(vec);    
    break;            
  }
}

/* Function:
   void DMA0_Initialize( void )

  Summary:
    This function initializes the DMA0 controller of the device.

  Description:
    Sets up a DMA controller for subsequent transfer activity.

  Parameters:
    none

  Returns:
    void
*/
void DMA0_Initialize(uint8_t vec){
    DMAC_CHANNEL_OBJECT *chanObj;

    /* Enable the DMA module */
    DMACONSET = _DMACON_ON_MASK;

    /* Initialize the available channel objects */
    chanObj             =   (DMAC_CHANNEL_OBJECT *)&gDMAChannelObj[0];

    chanObj->inUse          =    false;
    chanObj->pEventCallBack =    NULL;
    chanObj->hClientArg     =    0;
    chanObj->errorInfo      =    DMAC_ERROR_NONE;


    /* DMACON register */
    /* ON = 1          */
    DMACON = 0x8000;

    /* DMA channel-level control registers.  They will have additional settings made when starting a transfer. */
    /* DMA channel 0 configuration */
    /* CHPRI = 0 */
    DCH0CON = 0x3;
    /* CHSIRQ = vec, SIRQEN = 1 */
    DCH0ECON = ((vec << 8) | (1 << 4));
    /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
    DCH0INT = 0xB0000;
    /* Set up priority / subpriority of enabled interrupts */
    IPC33SET = 0x80000 | 0x0;  /* DMA0:  Priority 2 / Subpriority 0 */
    setIntVector(_DMA0_VECTOR, DMA0_Handler);

    /* Enable DMA channel interrupts */
    IEC4SET |= 0x40;
}

/* Function:
   void DMA1_Initialize( void )

  Summary:
    This function initializes the DMA1 controller of the device.

  Description:
    Sets up a DMA controller for subsequent transfer activity.

  Parameters:
    none

  Returns:
    void
*/
void DMA1_Initialize(uint8_t vec){
    DMAC_CHANNEL_OBJECT *chanObj;

    /* Enable the DMA module */
    DMACONSET = _DMACON_ON_MASK;

    /* Initialize the available channel objects */
    chanObj             =   (DMAC_CHANNEL_OBJECT *)&gDMAChannelObj[1];

    chanObj->inUse          =    false;
    chanObj->pEventCallBack =    NULL;
    chanObj->hClientArg     =    0;
    chanObj->errorInfo      =    DMAC_ERROR_NONE;


    /* DMACON register */
    /* ON = 1          */
    DMACON = 0x8000;

    /* DMA channel-level control registers.  They will have additional settings made when starting a transfer. */
    /* DMA channel 1 configuration */
    /* CHPRI = 0 */
    DCH1CON = 0x2;
    /* CHSIRQ = vec, SIRQEN = 1 */
    DCH1ECON =  ((vec << 8) | (1 << 4));
    /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
    DCH1INT = 0xB0000;
    /* Set up priority / subpriority of enabled interrupts */
    IPC33SET = 0x8000000 | 0x0;  /* DMA1:  Priority 2 / Subpriority 0 */
    setIntVector(_DMA1_VECTOR, DMA1_Handler);
    /* Enable DMA channel interrupts */
    IEC4SET |= 0x80;
}

/* Function:
   void DMA2_Initialize( void )

  Summary:
    This function initializes the DMA2 controller of the device.

  Description:
    Sets up a DMA controller for subsequent transfer activity.

  Parameters:
    none

  Returns:
    void
*/
void DMA2_Initialize(uint8_t vec){
    DMAC_CHANNEL_OBJECT *chanObj;

    /* Enable the DMA module */
    DMACONSET = _DMACON_ON_MASK;

    /* Initialize the available channel objects */
    chanObj             =   (DMAC_CHANNEL_OBJECT *)&gDMAChannelObj[2];

    chanObj->inUse          =    false;
    chanObj->pEventCallBack =    NULL;
    chanObj->hClientArg     =    0;
    chanObj->errorInfo      =    DMAC_ERROR_NONE;


    /* DMACON register */
    /* ON = 1          */
    DMACON = 0x8000;

    /* DMA channel-level control registers.  They will have additional settings made when starting a transfer. */
    /* DMA channel 2 configuration */
    /* CHPRI = 0 */
    DCH2CON = 0x1;
    /* CHSIRQ = vec, SIRQEN = 1 */
    DCH2ECON =  ((vec << 8) | (1 << 4));
    /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
    DCH2INT = 0xB0000;
    /* Set up priority / subpriority of enabled interrupts */
    IPC34SET = 0x8 | 0x0;  /* DMA2:  Priority 2 / Subpriority 0 */
    setIntVector(_DMA2_VECTOR, DMA2_Handler);
    /* Enable DMA channel interrupts */
    IEC4SET |= 0x100;
}

/* Function:
   void DMA3_Initialize( void )

  Summary:
    This function initializes the DMA3 controller of the device.

  Description:
    Sets up a DMA controller for subsequent transfer activity.

  Parameters:
    none

  Returns:
    void
*/
void DMA3_Initialize(uint8_t vec){
    DMAC_CHANNEL_OBJECT *chanObj;

    /* Enable the DMA module */
    DMACONSET = _DMACON_ON_MASK;

    /* Initialize the available channel objects */
    chanObj             =   (DMAC_CHANNEL_OBJECT *)&gDMAChannelObj[3];

    chanObj->inUse          =    false;
    chanObj->pEventCallBack =    NULL;
    chanObj->hClientArg     =    0;
    chanObj->errorInfo      =    DMAC_ERROR_NONE;


    /* DMACON register */
    /* ON = 1          */
    DMACON = 0x8000;

    /* DMA channel-level control registers.  They will have additional settings made when starting a transfer. */
    /* DMA channel 3 configuration */
    /* CHPRI = 0 */
    DCH3CON = 0x0;
    /* CHSIRQ = vec, SIRQEN = 1 */
    DCH3ECON =  ((vec << 8) | (1 << 4));
    /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
    DCH3INT = 0xB0000;
    /* Set up priority / subpriority of enabled interrupts */
    IPC34SET = 0x800 | 0x0;  /* DMA3:  Priority 2 / Subpriority 0 */    
    setIntVector(_DMA3_VECTOR, DMA3_Handler);
    /* Enable DMA channel interrupts */
    IEC4SET |= 0x200;
}


/* Function:
   void DMA4_Initialize( void )

  Summary:
    This function initializes the DMA4 controller of the device.

  Description:
    Sets up a DMA controller for subsequent transfer activity.

  Parameters:
    none

  Returns:
    void
*/
void DMA4_Initialize(uint8_t vec){
    DMAC_CHANNEL_OBJECT *chanObj;

    /* Enable the DMA module */
    DMACONSET = _DMACON_ON_MASK;

    /* Initialize the available channel objects */
    chanObj             =   (DMAC_CHANNEL_OBJECT *)&gDMAChannelObj[4];

    chanObj->inUse          =    false;
    chanObj->pEventCallBack =    NULL;
    chanObj->hClientArg     =    0;
    chanObj->errorInfo      =    DMAC_ERROR_NONE;


    /* DMACON register */
    /* ON = 1          */
    DMACON = 0x8000;

    /* DMA channel-level control registers.  They will have additional settings made when starting a transfer. */
    /* DMA channel 4 configuration */
    /* CHPRI = 0 */
    DCH4CON = 0x3;
    /* CHSIRQ = vec, SIRQEN = 1 */
    DCH4ECON =  ((vec << 8) | (1 << 4));
    /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
    DCH4INT = 0xB0000;
    /* Set up priority / subpriority of enabled interrupts */
    IPC34SET = 0x80000 | 0x0;  /* DMA4:  Priority 2 / Subpriority 0 */    
    setIntVector(_DMA4_VECTOR, DMA4_Handler);
    /* Enable DMA channel interrupts */
    IEC4SET |= 0x400;
}

/* Function:
   void DMA5_Initialize( void )

  Summary:
    This function initializes the DMA5 controller of the device.

  Description:
    Sets up a DMA controller for subsequent transfer activity.

  Parameters:
    none

  Returns:
    void
*/
void DMA5_Initialize(uint8_t vec){
    DMAC_CHANNEL_OBJECT *chanObj;

    /* Enable the DMA module */
    DMACONSET = _DMACON_ON_MASK;

    /* Initialize the available channel objects */
    chanObj             =   (DMAC_CHANNEL_OBJECT *)&gDMAChannelObj[5];

    chanObj->inUse          =    false;
    chanObj->pEventCallBack =    NULL;
    chanObj->hClientArg     =    0;
    chanObj->errorInfo      =    DMAC_ERROR_NONE;


    /* DMACON register */
    /* ON = 1          */
    DMACON = 0x8000;

    /* DMA channel-level control registers.  They will have additional settings made when starting a transfer. */
    /* DMA channel 5 configuration */
    /* CHPRI = 0 */
    DCH5CON = 0x2;
    /* CHSIRQ = vec, SIRQEN = 1 */
    DCH5ECON =  ((vec << 8) | (1 << 4));
    /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
    DCH5INT = 0xB0000;
    /* Set up priority / subpriority of enabled interrupts */
    IPC34SET = 0x8000000 | 0x0;  /* DMA5:  Priority 2 / Subpriority 0 */     
    setIntVector(_DMA5_VECTOR, DMA5_Handler);
    /* Enable DMA channel interrupts */
    IEC4SET |= 0x800;
}

/* Function:
   void DMA6_Initialize( void )

  Summary:
    This function initializes the DMA6 controller of the device.

  Description:
    Sets up a DMA controller for subsequent transfer activity.

  Parameters:
    none

  Returns:
    void
*/
void DMA6_Initialize(uint8_t vec){
    DMAC_CHANNEL_OBJECT *chanObj;

    /* Enable the DMA module */
    DMACONSET = _DMACON_ON_MASK;

    /* Initialize the available channel objects */
    chanObj             =   (DMAC_CHANNEL_OBJECT *)&gDMAChannelObj[6];

    chanObj->inUse          =    false;
    chanObj->pEventCallBack =    NULL;
    chanObj->hClientArg     =    0;
    chanObj->errorInfo      =    DMAC_ERROR_NONE;


    /* DMACON register */
    /* ON = 1          */
    DMACON = 0x8000;

    /* DMA channel-level control registers.  They will have additional settings made when starting a transfer. */
    /* DMA channel 6 configuration */
    /* CHPRI = 0 */
    DCH6CON = 0x1;
    /* CHSIRQ = vec, SIRQEN = 1 */
    DCH6ECON =  ((vec << 8) | (1 << 4));
    /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
    DCH6INT = 0xB0000;
    /* Set up priority / subpriority of enabled interrupts */
    IPC35SET = 0x8 | 0x0;  /* DMA6:  Priority 2 / Subpriority 0 */
    setIntVector(_DMA6_VECTOR, DMA6_Handler);
    /* Enable DMA channel interrupts */
    IEC4SET |= 0x1000;
}

/* Function:
   void DMA7_Initialize( void )

  Summary:
    This function initializes the DMA7 controller of the device.

  Description:
    Sets up a DMA controller for subsequent transfer activity.

  Parameters:
    none

  Returns:
    void
*/
void DMA7_Initialize(uint8_t vec){
    DMAC_CHANNEL_OBJECT *chanObj;

    /* Enable the DMA module */
    DMACONSET = _DMACON_ON_MASK;

    /* Initialize the available channel objects */
    chanObj             =   (DMAC_CHANNEL_OBJECT *)&gDMAChannelObj[7];

    chanObj->inUse          =    false;
    chanObj->pEventCallBack =    NULL;
    chanObj->hClientArg     =    0;
    chanObj->errorInfo      =    DMAC_ERROR_NONE;


    /* DMACON register */
    /* ON = 1          */
    DMACON = 0x8000;

    /* DMA channel-level control registers.  They will have additional settings made when starting a transfer. */
    /* DMA channel 7 configuration */
    /* CHPRI = 0 */
    DCH7CON = 0x0;
    /* CHSIRQ = vec, SIRQEN = 1 */
    DCH7ECON =  ((vec << 8) | (1 << 4));
    /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
    DCH7INT = 0xB0000;
    /* Set up priority / subpriority of enabled interrupts */
    IPC35SET = 0x800 | 0x0;  /* DMA7:  Priority 2 / Subpriority 0 */
    setIntVector(_DMA7_VECTOR, DMA7_Handler);
    /* Enable DMA channel interrupts */
    IEC4SET |= 0x2000;
}


// /* Function:
//    void DMAC_Initialize( void )

//   Summary:
//     This function initializes the DMAC controller of the device.

//   Description:
//     Sets up a DMA controller for subsequent transfer activity.

//   Parameters:
//     none

//   Returns:
//     void
// */
// void DMAC_Initialize( void )
// {
//     uint8_t chanIndex;
//     DMAC_CHANNEL_OBJECT *chanObj;

//     /* Enable the DMA module */
//     DMACONSET = _DMACON_ON_MASK;

//     /* Initialize the available channel objects */
//     chanObj             =   (DMAC_CHANNEL_OBJECT *)&gDMAChannelObj[0];

//     for(chanIndex = 0; chanIndex < 8; chanIndex++)
//     {
//         chanObj->inUse          =    false;
//         chanObj->pEventCallBack =    NULL;
//         chanObj->hClientArg     =    0;
//         chanObj->errorInfo      =    DMAC_ERROR_NONE;
//         chanObj                 =    chanObj + 1;  /* linked list 'next' */
//     }

//     /* DMACON register */
//     /* ON = 1          */
//     DMACON = 0x8000;

//     /* DMA channel-level control registers.  They will have additional settings made when starting a transfer. */
//     /* DMA channel 0 configuration */
//     /* CHPRI = 0 */
//     DCH0CON = 0x0;
//     /* CHSIRQ = 147, SIRQEN = 1 */
//     DCH0ECON = 0x9310;
//     /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
//     DCH0INT = 0xB0000;
//     /* Set up priority / subpriority of enabled interrupts */
//     IPC33SET = 0x40000 | 0x0;  /* DMA0:  Priority 1 / Subpriority 0 */

//     /* DMA channel 1 configuration */
//     /* CHPRI = 0 */
//     DCH1CON = 0x0;
//     /* CHSIRQ = 146, SIRQEN = 1 */
//     DCH1ECON = 0x9210;
//     /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
//     DCH1INT = 0xB0000;
//     /* Set up priority / subpriority of enabled interrupts */
//     IPC33SET = 0x4000000 | 0x0;  /* DMA1:  Priority 1 / Subpriority 0 */
    

//     /* DMA channel 2 configuration */
//     /* CHPRI = 0 */
//     DCH2CON = 0x0;
//     /* CHSIRQ = 0, SIRQEN = 0 */
//     DCH2ECON = 0x0;
//     /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
//     DCH2INT = 0xB0000;
//     /* Set up priority / subpriority of enabled interrupts */
//     IPC34SET = 0x4 | 0x0;  /* DMA2:  Priority 1 / Subpriority 0 */

//     /* DMA channel 3 configuration */
//     /* CHPRI = 0 */
//     DCH3CON = 0x0;
//     /* CHSIRQ = 0, SIRQEN = 0 */
//     DCH3ECON = 0x0;
//     /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
//     DCH3INT = 0xB0000;
//     /* Set up priority / subpriority of enabled interrupts */
//     IPC34SET = 0x400 | 0x0;  /* DMA3:  Priority 1 / Subpriority 0 */    

//     /* DMA channel 4 configuration */
//     /* CHPRI = 0 */
//     DCH4CON = 0x0;
//     /* CHSIRQ = 0, SIRQEN = 0 */
//     DCH4ECON = 0x0;
//     /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
//     DCH4INT = 0xB0000;
//     /* Set up priority / subpriority of enabled interrupts */
//     IPC34SET = 0x40000 | 0x0;  /* DMA4:  Priority 1 / Subpriority 0 */    

//     /* DMA channel 5 configuration */
//     /* CHPRI = 0 */
//     DCH5CON = 0x0;
//     /* CHSIRQ = 0, SIRQEN = 0 */
//     DCH5ECON = 0x0;
//     /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
//     DCH5INT = 0xB0000;
//     /* Set up priority / subpriority of enabled interrupts */
//     IPC34SET = 0x4000000 | 0x0;  /* DMA5:  Priority 1 / Subpriority 0 */     

//     /* DMA channel 6 configuration */
//     /* CHPRI = 0 */
//     DCH6CON = 0x0;
//     /* CHSIRQ = 0, SIRQEN = 0 */
//     DCH6ECON = 0x0;
//     /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
//     DCH6INT = 0xB0000;
//     /* Set up priority / subpriority of enabled interrupts */
//     IPC35SET = 0x4 | 0x0;  /* DMA6:  Priority 1 / Subpriority 0 */

//     /* DMA channel 7 configuration */
//     /* CHPRI = 0 */
//     DCH7CON = 0x0;
//     /* CHSIRQ = 0, SIRQEN = 0 */
//     DCH7ECON = 0x0;
//     /* CHBCIE = 1, CHTAIE=1, CHERIE=1 */
//     DCH7INT = 0xB0000;
//     /* Set up priority / subpriority of enabled interrupts */
//     IPC35SET = 0x400 | 0x0;  /* DMA7:  Priority 1 / Subpriority 0 */

//     /* Enable DMA channel interrupts */
//     IEC4SET = 0 | 0x40 | 0x80 | 0x100 | 0x200 | 0x400 | 0x800 | 0x1000 | 0x2000 ;
// }

// *****************************************************************************
/* Function:
   void DMAC_ChannelCallbackRegister

  Summary:
    Callback function registration function

  Description:
    Registers the callback function (and context pointer, if used) for a given DMA interrupt.

  Parameters:
    DMAC_CHANNEL channel - DMA channel this callback pertains to
    const DMAC_CHANNEL_CALLBACK eventHandler - pointer to callback function
    const uintptr_t contextHandle - pointer of context information callback is to use (set to NULL if not used)

  Returns:
    void
*/
void DMAC_ChannelCallbackRegister(DMAC_CHANNEL channel, const DMAC_CHANNEL_CALLBACK eventHandler, const uintptr_t contextHandle)
{
    gDMAChannelObj[channel].pEventCallBack = eventHandler;

    gDMAChannelObj[channel].hClientArg = contextHandle;
}

// *****************************************************************************
/* Function:
   bool DMAC_ChannelTransfer

  Summary:
    DMA channel transfer function

  Description:
    Sets up a DMA transfer, and starts the transfer if user specified a
    software-initiated transfer in Harmony.

  Parameters:
    DMAC_CHANNEL channel - DMA channel to use for this transfer
    const void *srcAddr - pointer to source data
    const void *destAddr - pointer to where data is to be moved to
    size_t blockSize - the transfer size to use

  Returns:
    false, if DMA already is busy / true, if DMA is not busy before calling function
*/
bool DMAC_ChannelTransfer( DMAC_CHANNEL channel, const void *srcAddr, size_t srcSize, const void *destAddr, size_t destSize, size_t cellSize)
{
    bool returnStatus = false;
    volatile uint32_t *regs;

    if(gDMAChannelObj[channel].inUse == false)
    {
        gDMAChannelObj[channel].inUse = true;
        returnStatus = true;

        /* Set the source / destination addresses, DCHxSSA and DCHxDSA */
        DMAC_ChannelSetAddresses(channel, srcAddr, destAddr);

        /* Set the source size, DCHxSSIZ */
        regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60 + (channel * 0xC0) + 0x50);
        *(volatile uint32_t *)(regs) = srcSize;

        /* Set the destination size (set same as source size), DCHxDSIZ */
        regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60 + (channel * 0xC0) + 0x60);
        *(volatile uint32_t *)(regs) = destSize;

        /* Set the cell size (set same as source size), DCHxCSIZ */
        regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60 + (channel * 0xC0) + 0x90);
        *(volatile uint32_t *)(regs) = cellSize;

        /* Enable the channel */
        /* CHEN = 1 */
        regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60 + (channel * 0xC0) + 0x0)+2;
        *(volatile uint32_t *)(regs) = _DCH0CON_CHEN_MASK;

        /* Check Channel Start IRQ Enable bit - SIRQEN */
         regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60 + (channel * 0xC0) + 0x10);

        /* Initiate transfer if user did not set up channel for interrupt-initiated transfer. */
        if((*(volatile uint32_t *)(regs) & _DCH1ECON_SIRQEN_MASK) == 0)
        {
            /* CFORCE = 1 */
            regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60 + (channel * 0xC0) + 0x10)+2;
            *(volatile uint32_t *)(regs) = _DCH0ECON_CFORCE_MASK;
        }
    }

    return returnStatus;
}

void DMAC_ChannelForceStart(DMAC_CHANNEL channel){
    volatile uint32_t *regs;
    /* CFORCE = 1 */
    regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60 + (channel * 0xC0) + 0x10)+2;
    *(volatile uint32_t *)(regs) = _DCH0ECON_CFORCE_MASK;
}

// *****************************************************************************
/* Function:
   void DMAC_ChannelDisable (DMAC_CHANNEL channel)

  Summary:
    This function disables the DMA channel.

  Description:
    Disables the DMA channel specified.

  Parameters:
    DMAC_CHANNEL channel - the particular channel to be disabled

  Returns:
    void
*/
void DMAC_ChannelDisable (DMAC_CHANNEL channel)
{
    volatile uint32_t * regs;

    if(channel < 8)
    {
        /* Disable channel in register DCHxCON */
        /* CHEN = 0 */
        regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60 + (channel * 0xC0) + 0x0)+1;
        *(volatile uint32_t *)(regs) = _DCH0CON_CHEN_MASK;

        gDMAChannelObj[channel].inUse = false;

    }
}

// *****************************************************************************
/* Function:
   bool DMAC_ChannelIsBusy (DMAC_CHANNEL channel)

  Summary:
    Reads the busy status of a channel.

  Description:
    Reads the busy status of a channel and returns status to caller.

  Parameters:
    DMAC_CHANNEL channel - the particular channel to be interrogated

  Returns:
    true - channel is busy
    false - channel is not busy
*/
bool DMAC_ChannelIsBusy (DMAC_CHANNEL channel)
{
    return (gDMAChannelObj[channel].inUse);

}


// *****************************************************************************
/* Function:
   void DMA0_InterruptHandler (void)

  Summary:
    Interrupt handler for interrupts from DMA0.

  Description:
    None

  Parameters:
    none

  Returns:
    void
*/
void DMA0_InterruptHandler (void)
{
    DMAC_CHANNEL_OBJECT *chanObj;
    DMAC_TRANSFER_EVENT dmaEvent = DMAC_TRANSFER_EVENT_NONE;
    bool retVal;

    /* Find out the channel object */
    chanObj = (DMAC_CHANNEL_OBJECT *) &gDMAChannelObj[0];

    /* Check whether the active DMA channel event has occurred */
    retVal = DCH0INTbits.CHBCIF;

    if(true == retVal) /* irq due to transfer complete */
    {
        /* Channel is by default disabled on completion of a block transfer */
        /* Clear the Block transfer complete flag */
        DCH0INTCLR = _DCH0INT_CHBCIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_COMPLETE;
    }
    else if(true == DCH0INTbits.CHTAIF) /* irq due to transfer abort */
    {
        /* Channel is by default disabled on Transfer Abortion */
        /* Clear the Abort transfer complete flag */
        DCH0INTCLR = _DCH0INT_CHTAIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }
    else if(true == DCH0INTbits.CHERIF)
    {
        /* Clear the Block transfer complete flag */
        DCH0INTCLR = _DCH0INT_CHERIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_ADDRESS_ERROR;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }

    chanObj->inUse = false;

    IFS4CLR = 0x40;

    /* Clear the interrupt flag and call event handler */
    if((NULL != chanObj->pEventCallBack) && (DMAC_TRANSFER_EVENT_NONE != dmaEvent))
    {
        chanObj->pEventCallBack(dmaEvent, chanObj->hClientArg);
    }


}
// *****************************************************************************
/* Function:
   void DMA1_InterruptHandler (void)

  Summary:
    Interrupt handler for interrupts from DMA1.

  Description:
    None

  Parameters:
    none

  Returns:
    void
*/
void DMA1_InterruptHandler (void)
{
    DMAC_CHANNEL_OBJECT *chanObj;
    DMAC_TRANSFER_EVENT dmaEvent = DMAC_TRANSFER_EVENT_NONE;
    bool retVal;

    /* Find out the channel object */
    chanObj = (DMAC_CHANNEL_OBJECT *) &gDMAChannelObj[1];

    /* Check whether the active DMA channel event has occurred */
    retVal = DCH1INTbits.CHBCIF;

    if(true == retVal) /* irq due to transfer complete */
    {
        /* Channel is by default disabled on completion of a block transfer */
        /* Clear the Block transfer complete flag */
        DCH1INTCLR = _DCH1INT_CHBCIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_COMPLETE;
    }
    else if(true == DCH1INTbits.CHTAIF) /* irq due to transfer abort */
    {
        /* Channel is by default disabled on Transfer Abortion */
        /* Clear the Abort transfer complete flag */
        DCH1INTCLR = _DCH1INT_CHTAIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }
    else if(true == DCH1INTbits.CHERIF)
    {
        /* Clear the Block transfer complete flag */
        DCH1INTCLR = _DCH1INT_CHERIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_ADDRESS_ERROR;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }

    chanObj->inUse = false;

    IFS4CLR = 0x80;

    /* Clear the interrupt flag and call event handler */
    if((NULL != chanObj->pEventCallBack) && (DMAC_TRANSFER_EVENT_NONE != dmaEvent))
    {
        chanObj->pEventCallBack(dmaEvent, chanObj->hClientArg);
    }


}
// *****************************************************************************
/* Function:
   void DMA2_InterruptHandler (void)

  Summary:
    Interrupt handler for interrupts from DMA2.

  Description:
    None

  Parameters:
    none

  Returns:
    void
*/
void DMA2_InterruptHandler (void)
{
    DMAC_CHANNEL_OBJECT *chanObj;
    DMAC_TRANSFER_EVENT dmaEvent = DMAC_TRANSFER_EVENT_NONE;
    bool retVal;

    /* Find out the channel object */
    chanObj = (DMAC_CHANNEL_OBJECT *) &gDMAChannelObj[2];

    /* Check whether the active DMA channel event has occurred */
    retVal = DCH2INTbits.CHBCIF;

    if(true == retVal) /* irq due to transfer complete */
    {
        /* Channel is by default disabled on completion of a block transfer */
        /* Clear the Block transfer complete flag */
        DCH2INTCLR = _DCH2INT_CHBCIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_COMPLETE;
    }
    else if(true == DCH2INTbits.CHTAIF) /* irq due to transfer abort */
    {
        /* Channel is by default disabled on Transfer Abortion */
        /* Clear the Abort transfer complete flag */
        DCH2INTCLR = _DCH2INT_CHTAIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }
    else if(true == DCH2INTbits.CHERIF)
    {
        /* Clear the Block transfer complete flag */
        DCH2INTCLR = _DCH2INT_CHERIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_ADDRESS_ERROR;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }

    chanObj->inUse = false;

    IFS4CLR = 0x100;

    /* Clear the interrupt flag and call event handler */
    if((NULL != chanObj->pEventCallBack) && (DMAC_TRANSFER_EVENT_NONE != dmaEvent))
    {
        chanObj->pEventCallBack(dmaEvent, chanObj->hClientArg);
    }


}
// *****************************************************************************
/* Function:
   void DMA3_InterruptHandler (void)

  Summary:
    Interrupt handler for interrupts from DMA3.

  Description:
    None

  Parameters:
    none

  Returns:
    void
*/
void DMA3_InterruptHandler (void)
{
    DMAC_CHANNEL_OBJECT *chanObj;
    DMAC_TRANSFER_EVENT dmaEvent = DMAC_TRANSFER_EVENT_NONE;
    bool retVal;

    /* Find out the channel object */
    chanObj = (DMAC_CHANNEL_OBJECT *) &gDMAChannelObj[3];

    /* Check whether the active DMA channel event has occurred */
    retVal = DCH3INTbits.CHBCIF;

    if(true == retVal) /* irq due to transfer complete */
    {
        /* Channel is by default disabled on completion of a block transfer */
        /* Clear the Block transfer complete flag */
        DCH3INTCLR = _DCH3INT_CHBCIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_COMPLETE;
    }
    else if(true == DCH3INTbits.CHTAIF) /* irq due to transfer abort */
    {
        /* Channel is by default disabled on Transfer Abortion */
        /* Clear the Abort transfer complete flag */
        DCH3INTCLR = _DCH3INT_CHTAIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }
    else if(true == DCH3INTbits.CHERIF)
    {
        /* Clear the Block transfer complete flag */
        DCH3INTCLR = _DCH3INT_CHERIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_ADDRESS_ERROR;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }

    chanObj->inUse = false;

    IFS4CLR = 0x200;

    /* Clear the interrupt flag and call event handler */
    if((NULL != chanObj->pEventCallBack) && (DMAC_TRANSFER_EVENT_NONE != dmaEvent))
    {
        chanObj->pEventCallBack(dmaEvent, chanObj->hClientArg);
    }


}
// *****************************************************************************
/* Function:
   void DMA4_InterruptHandler (void)

  Summary:
    Interrupt handler for interrupts from DMA4.

  Description:
    None

  Parameters:
    none

  Returns:
    void
*/
void DMA4_InterruptHandler (void)
{
    DMAC_CHANNEL_OBJECT *chanObj;
    DMAC_TRANSFER_EVENT dmaEvent = DMAC_TRANSFER_EVENT_NONE;
    bool retVal;

    /* Find out the channel object */
    chanObj = (DMAC_CHANNEL_OBJECT *) &gDMAChannelObj[4];

    /* Check whether the active DMA channel event has occurred */
    retVal = DCH4INTbits.CHBCIF;

    if(true == retVal) /* irq due to transfer complete */
    {
        /* Channel is by default disabled on completion of a block transfer */
        /* Clear the Block transfer complete flag */
        DCH4INTCLR = _DCH4INT_CHBCIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_COMPLETE;
    }
    else if(true == DCH4INTbits.CHTAIF) /* irq due to transfer abort */
    {
        /* Channel is by default disabled on Transfer Abortion */
        /* Clear the Abort transfer complete flag */
        DCH4INTCLR = _DCH4INT_CHTAIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }
    else if(true == DCH4INTbits.CHERIF)
    {
        /* Clear the Block transfer complete flag */
        DCH4INTCLR = _DCH4INT_CHERIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_ADDRESS_ERROR;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }

    chanObj->inUse = false;

    IFS4CLR = 0x400;

    /* Clear the interrupt flag and call event handler */
    if((NULL != chanObj->pEventCallBack) && (DMAC_TRANSFER_EVENT_NONE != dmaEvent))
    {
        chanObj->pEventCallBack(dmaEvent, chanObj->hClientArg);
    }


}
// *****************************************************************************
/* Function:
   void DMA5_InterruptHandler (void)

  Summary:
    Interrupt handler for interrupts from DMA5.

  Description:
    None

  Parameters:
    none

  Returns:
    void
*/
void DMA5_InterruptHandler (void)
{
    DMAC_CHANNEL_OBJECT *chanObj;
    DMAC_TRANSFER_EVENT dmaEvent = DMAC_TRANSFER_EVENT_NONE;
    bool retVal;

    /* Find out the channel object */
    chanObj = (DMAC_CHANNEL_OBJECT *) &gDMAChannelObj[5];

    /* Check whether the active DMA channel event has occurred */
    retVal = DCH5INTbits.CHBCIF;

    if(true == retVal) /* irq due to transfer complete */
    {
        /* Channel is by default disabled on completion of a block transfer */
        /* Clear the Block transfer complete flag */
        DCH5INTCLR = _DCH5INT_CHBCIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_COMPLETE;
    }
    else if(true == DCH5INTbits.CHTAIF) /* irq due to transfer abort */
    {
        /* Channel is by default disabled on Transfer Abortion */
        /* Clear the Abort transfer complete flag */
        DCH5INTCLR = _DCH5INT_CHTAIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }
    else if(true == DCH5INTbits.CHERIF)
    {
        /* Clear the Block transfer complete flag */
        DCH5INTCLR = _DCH5INT_CHERIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_ADDRESS_ERROR;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }

    chanObj->inUse = false;

    IFS4CLR = 0x800;

    /* Clear the interrupt flag and call event handler */
    if((NULL != chanObj->pEventCallBack) && (DMAC_TRANSFER_EVENT_NONE != dmaEvent))
    {
        chanObj->pEventCallBack(dmaEvent, chanObj->hClientArg);
    }


}
// *****************************************************************************
/* Function:
   void DMA6_InterruptHandler (void)

  Summary:
    Interrupt handler for interrupts from DMA6.

  Description:
    None

  Parameters:
    none

  Returns:
    void
*/
void DMA6_InterruptHandler (void)
{
    DMAC_CHANNEL_OBJECT *chanObj;
    DMAC_TRANSFER_EVENT dmaEvent = DMAC_TRANSFER_EVENT_NONE;
    bool retVal;

    /* Find out the channel object */
    chanObj = (DMAC_CHANNEL_OBJECT *) &gDMAChannelObj[6];

    /* Check whether the active DMA channel event has occurred */
    retVal = DCH6INTbits.CHBCIF;

    if(true == retVal) /* irq due to transfer complete */
    {
        /* Channel is by default disabled on completion of a block transfer */
        /* Clear the Block transfer complete flag */
        DCH6INTCLR = _DCH6INT_CHBCIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_COMPLETE;
    }
    else if(true == DCH6INTbits.CHTAIF) /* irq due to transfer abort */
    {
        /* Channel is by default disabled on Transfer Abortion */
        /* Clear the Abort transfer complete flag */
        DCH6INTCLR = _DCH6INT_CHTAIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }
    else if(true == DCH6INTbits.CHERIF)
    {
        /* Clear the Block transfer complete flag */
        DCH6INTCLR = _DCH6INT_CHERIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_ADDRESS_ERROR;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }

    chanObj->inUse = false;

    IFS4CLR = 0x1000;

    /* Clear the interrupt flag and call event handler */
    if((NULL != chanObj->pEventCallBack) && (DMAC_TRANSFER_EVENT_NONE != dmaEvent))
    {
        chanObj->pEventCallBack(dmaEvent, chanObj->hClientArg);
    }


}
// *****************************************************************************
/* Function:
   void DMA7_InterruptHandler (void)

  Summary:
    Interrupt handler for interrupts from DMA7.

  Description:
    None

  Parameters:
    none

  Returns:
    void
*/
void DMA7_InterruptHandler (void)
{
    DMAC_CHANNEL_OBJECT *chanObj;
    DMAC_TRANSFER_EVENT dmaEvent = DMAC_TRANSFER_EVENT_NONE;
    bool retVal;

    /* Find out the channel object */
    chanObj = (DMAC_CHANNEL_OBJECT *) &gDMAChannelObj[7];

    /* Check whether the active DMA channel event has occurred */
    retVal = DCH7INTbits.CHBCIF;

    if(true == retVal) /* irq due to transfer complete */
    {
        /* Channel is by default disabled on completion of a block transfer */
        /* Clear the Block transfer complete flag */
        DCH7INTCLR = _DCH7INT_CHBCIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_COMPLETE;
    }
    else if(true == DCH7INTbits.CHTAIF) /* irq due to transfer abort */
    {
        /* Channel is by default disabled on Transfer Abortion */
        /* Clear the Abort transfer complete flag */
        DCH7INTCLR = _DCH7INT_CHTAIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }
    else if(true == DCH7INTbits.CHERIF)
    {
        /* Clear the Block transfer complete flag */
        DCH7INTCLR = _DCH7INT_CHERIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_ADDRESS_ERROR;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }

    chanObj->inUse = false;

    IFS4CLR = 0x2000;

    /* Clear the interrupt flag and call event handler */
    if((NULL != chanObj->pEventCallBack) && (DMAC_TRANSFER_EVENT_NONE != dmaEvent))
    {
        chanObj->pEventCallBack(dmaEvent, chanObj->hClientArg);
    }


}
