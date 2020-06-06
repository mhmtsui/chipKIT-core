#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>

//    #define  _OCMP1_BASE_ADDRESS ((uint32_t) &OC1CON)
    #define  _TIMER_1_IRQ _TIMER_1_VECTOR
    #define  _TIMER_4_IRQ _TIMER_4_VECTOR

/* ------------------------------------------------------------ */
/*				Public Board Declarations						*/
/* ------------------------------------------------------------ */
/* The following define symbols that can be used in a sketch to
** refer to periperhals on the board generically.
*/

#define	_BOARD_NAME_	"Hestia V3"
#define _USB

/* Define the Microcontroller peripherals available on the board.
*/
#define	NUM_DIGITAL_PINS	71
#define	NUM_ANALOG_PINS		14
#define NUM_OC_PINS			9
#define	NUM_IC_PINS			5
#define	NUM_TCK_PINS		4
#define	NUM_INT_PINS		5

#define	NUM_SERIAL_PORTS	6   
#define	NUM_SPI_PORTS		1   
#define	NUM_I2C_PORTS		1   

#define NUM_DSPI_PORTS		4
#define	NUM_DTWI_PORTS		2

/* Define I/O devices on the board.
*/
#define	NUM_LED				2
#define NUM_BTN				0
#define	NUM_SWT				3
#define NUM_SERVO			0

/* Define the number of pins including extended i/o pins.
** These are pins that are not native to the microcontroller, such
** as implemented via an i/o expander or external A/D or D/A.
** This board doesn't have any.
*/
#define	NUM_DIGITAL_PINS_EXTENDED	NUM_DIGITAL_PINS
#define	NUM_ANALOG_PINS_EXTENDED	NUM_ANALOG_PINS

/* ------------------------------------------------------------ */
/*					Virtual Program Button						*/
/* ------------------------------------------------------------ */
#define USE_VIRTUAL_PROGRAM_BUTTON      1
#define VIRTUAL_PROGRAM_BUTTON_TRIS     TRISCbits.TRISC12
#define VIRTUAL_PROGRAM_BUTTON          LATCbits.LATC12

/* ------------------------------------------------------------ */
/*						LED Declarations						*/
/* ------------------------------------------------------------ */

/* Define the pin numbers for the LEDs.
*/
#define	PIN_LED1	13
#define	PIN_LED2	43

/* ------------------------------------------------------------ */
/*					Button Declarations							*/
/* ------------------------------------------------------------ */

/* Define buttons on this board.
*/

/* ------------------------------------------------------------ */
/*					Switch Declarations							*/
/* ------------------------------------------------------------ */

/* No switches on this board.
*/
#define PIN_SWT1	8
#define PIN_SWT2	59
#define PIN_SWT3	56

/* ------------------------------------------------------------ */
/*					Pots and Monitor Declarations   			*/
/* ------------------------------------------------------------ */

/* Define other components on the board
*/

/* ------------------------------------------------------------ */
/*					Servo Pin Declarations						*/
/* ------------------------------------------------------------ */

/* No servo connectors on this board.
*/

/* ------------------------------------------------------------ */
/*					Timer Pin Declarations						*/
/* ------------------------------------------------------------ */

// #define PIN_OC1		3
// #define	PIN_OC2		5
// #define	PIN_OC3		6
// #define	PIN_OC4		9
// #define	PIN_OC5		10
// #define	PIN_OC6		11
#define PIN_OC7     11
#define PIN_OC4     12
#define	PIN_OC2		34

// #define PIN_IC1		2      
// #define PIN_IC2		7      
// #define PIN_IC3		8      
// #define PIN_IC4		10
// #define PIN_IC5		35

//#define	PIN_TCK1	not connected
// #define	PIN_TCK2	34      
// #define	PIN_TCK3	35      
// #define	PIN_TCK4	36      
// #define	PIN_TCK5	38

/* ------------------------------------------------------------ */
/*					Interrupt Pin Declarations					*/
/* ------------------------------------------------------------ */
// #define	PIN_INT0	3   // uno32 is on 38
// #define	PIN_INT1	2
// #define PIN_INT2	7
// #define	PIN_INT3	8
// #define	PIN_INT4	59  // used by MRF and is not on uno32 pin 35.

/* ------------------------------------------------------------ */
/*					SPI Pin Declarations						*/
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h
*/
static const uint8_t SS   = 16;		// for SPI master operation, shared with pin 16
static const uint8_t MOSI = 35;		// PIC32 SDO2
static const uint8_t MISO = 54;		// PIC32 SDI2
static const uint8_t SCK  = 13;		// PIC32 SCK2

/* The Digilent DSPI library uses these ports.
*/
#define	PIN_DSPI0_SS	16      // SS2; W25Q128
#define	PIN_DSPI1_SS	38      // SS1; 
#define	PIN_DSPI2_SS	17      // SS3; W5500
#define	PIN_DSPI3_SS	43      // SS4;
#define	PIN_DSPI6_SS	15      // SS6; 595

/* ------------------------------------------------------------ */
/*					Analog Pins									*/
/* ------------------------------------------------------------ */
/* Define symbols for accessing the analog pins. This table is
** used to map an analog pin number to the corresponding digital
** pin number.
*/
// #define	A0		14      // AN45
// #define	A1		15      // AN49
// #define A2		16      // AN21
// #define A3		17      // AN10
// #define A4		18      // AN13
// #define A5		19      // AN12
// #define A6		20      // AN3
// #define A7		21      // AN2
// #define A8		22      // AN4
// #define A9		23      // AN1
// #define A10		24      // AN48
// #define A11		25      // AN0
// #define A12		48      // AN8
// #define A13		49      // AN7

/* ------------------------------------------------------------ */
/*					Change Notice Pins							*/
/* ------------------------------------------------------------ */
/* These define the pin numbers for the various change notice
** pins.
*/
#define	PIN_CN0		0
#define	PIN_CN1		1
#define	PIN_CN2		2      
#define	PIN_CN3		3      
#define	PIN_CN4		4
#define	PIN_CN5		5
#define	PIN_CN6		6
#define	PIN_CN7		7
#define	PIN_CN8		8
#define	PIN_CN9		9
#define	PIN_CN10	10
#define	PIN_CN11	11
#define	PIN_CN12	12
#define	PIN_CN13	13
#define	PIN_CN14	14      
#define	PIN_CN15	15
#define	PIN_CN16	16
#define	PIN_CN17	17      
#define	PIN_CN18	18      
#define	PIN_CN19	19
#define	PIN_CN20	20
#define	PIN_CN21	21
#define	PIN_CN22	22
#define	PIN_CN23	23      
#define	PIN_CN24	24
#define	PIN_CN25	25
#define	PIN_CN26	26      
#define	PIN_CN27	27      
#define	PIN_CN28	28      
#define	PIN_CN29	29      
#define	PIN_CN30	30
#define	PIN_CN31	31
#define	PIN_CN32	32
#define	PIN_CN33	33
#define	PIN_CN34	34      
#define	PIN_CN35	35
#define	PIN_CN36	36
#define	PIN_CN37	37      
#define	PIN_CN38	38      
#define	PIN_CN39	39
#define	PIN_CN40	40
#define	PIN_CN41	41

/* ------------------------------------------------------------ */
/*					Pin Mapping Macros							*/
/* ------------------------------------------------------------ */
/* This section contains the definitions for pin mapping macros that
** are being redefined for this board variant.
*/

// NUM_ANALOG_PINS == 14, the first analog pin as represented as a digital pin is also 14
// if the analog pin is less than 14, then you can put in the analog number 
// if the pin is greater than 14, it must be a digital pin number.

#undef digitalPinToAnalog
//#define	digitalPinToAnalog(P) (digital_pin_to_analog_PGM[P])
#define digitalPinToAnalog(P) (((P) < NUM_ANALOG_PINS) ? (P) : (digital_pin_to_analog_PGM[P]))

#undef analogInPinToChannel
#define analogInPinToChannel(P) (analog_pin_to_channel_PGM[P])


/* ------------------------------------------------------------ */
/*					Data Declarations							*/
/* ------------------------------------------------------------ */

/* The following declare externals to access the pin mapping
** tables. These tables are defined in Board_Data.c.
*/

#if !defined(OPT_BOARD_DATA)

extern const uint32_t	port_to_tris_PGM[];
extern const uint8_t	digital_pin_to_port_PGM[];
extern const uint16_t	digital_pin_to_bit_mask_PGM[];
extern const uint16_t	digital_pin_to_timer_PGM[];

extern const uint8_t	output_compare_to_digital_pin_PGM[];
extern const uint8_t	external_int_to_digital_pin_PGM[];

extern const uint8_t	analog_pin_to_channel_PGM[];
extern const uint8_t 	digital_pin_to_analog_PGM[];

extern const uint8_t	digital_pin_to_pps_out_PGM[];
extern const uint8_t	digital_pin_to_pps_in_PGM[];

#endif

/* ------------------------------------------------------------ */
/*				Internal Declarations							*/
/* ------------------------------------------------------------ */
/* The following declarations are used to map peripherals for	*/
/* the core and libraries and to provide configuration options	*/
/* for the core. They are not normally needed by a user sketch.	*/
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_INTERNAL)

/* ------------------------------------------------------------ */
/*				Core Configuration Declarations					*/
/* ------------------------------------------------------------ */
/*																*/
/* These are conditional compilation switches that control the	*/
/* board core configuration functions. These functions provide	*/
/* hooks that can call from some of the core functions into		*/
/* functions defined below that can be used to extend or		*/
/* replace the default behavior of the core function. To use	*/
/* this, enter the appropriate code into the appropriate		*/
/* function skeleton below and then set the appropriate switch	*/
/* value to 1. This will cause the configuration function to be	*/
/* compiled into the build and will cause the code to call the	*/
/* hook function to be compiled into the core function.			*/
/*																*/
/* ------------------------------------------------------------ */

#define	OPT_BOARD_INIT			0	//board needs no special init code
#define	OPT_BOARD_DIGITAL_IO	0	//board does not extend digital i/o functions
#define	OPT_BOARD_ANALOG_READ	0	//board does not extend analogRead
#define	OPT_BOARD_ANALOG_WRITE	0	//board does not extend analogWrite


/* ------------------------------------------------------------ */
/*  JTAG Support, set to 1 if you want JTAG enabled             */
/*  otherwise JTAG will be disabled                             */
/* ------------------------------------------------------------ */
// Wi-FIRE supports JTAG
#define _JTAG 0

/* ------------------------------------------------------------ */

#endif	// OPT_BOARD_INTERNAL

/* ------------------------------------------------------------ */
/*					Serial Port Declarations					*/
/* ------------------------------------------------------------ */

/* Serial0 UART4 USB Serial
*/
#define	_SER0_BASE      _UART4_BASE_ADDRESS
#define	_SER0_IRQ       _UART4_FAULT_VECTOR
#define	_SER0_VECTOR    _UART4_FAULT_VECTOR
#define	_SER0_IPL_ISR   IPL2SRS
#define	_SER0_IPL       4
#define	_SER0_SPL       0
#define _SER0_TX_OUT    PPS_OUT_U4TX     // (RPF8R = 0b0010)   RF8 -> U4TX   
#define _SER0_TX_PIN    1                // REBIRDY2/RPF8/SCL3/RF8   
#define _SER0_RX_IN     PPS_IN_U4RX      // (U4RXR = 0b1011)    RPF2 -> U4RX
#define _SER0_RX_PIN    0                // EBIRDY3/RPF2/SDA3/RF2 

/* Serial1 UART1 Heater
*/
#define	_SER1_BASE		_UART1_BASE_ADDRESS
#define	_SER1_IRQ		_UART1_FAULT_VECTOR
#define	_SER1_VECTOR	_UART1_FAULT_VECTOR
#define	_SER1_IPL_ISR	IPL2SRS
#define	_SER1_IPL		4
#define	_SER1_SPL		0
#define _SER1_TX_OUT    PPS_OUT_U1TX
#define _SER1_TX_PIN    57               // RF5
#define _SER1_RX_IN     PPS_IN_U1RX
#define _SER1_RX_PIN    61               // RF4

/* Serial2 UART2
*/
#define	_SER2_BASE		_UART2_BASE_ADDRESS
#define	_SER2_IRQ		_UART2_FAULT_VECTOR
#define	_SER2_VECTOR	_UART2_FAULT_VECTOR
#define	_SER2_IPL_ISR	IPL2SRS
#define	_SER2_IPL		4
#define	_SER2_SPL		0
#define _SER2_TX_OUT    PPS_OUT_U2TX
#define _SER2_TX_PIN    2                // RE8
#define _SER2_RX_IN     PPS_IN_U2RX
#define _SER2_RX_PIN    7                // RE9

/* Serial3 UART3 STM32
*/
#define	_SER3_BASE		_UART3_BASE_ADDRESS
#define	_SER3_IRQ		_UART3_FAULT_VECTOR
#define	_SER3_VECTOR	_UART3_FAULT_VECTOR
#define	_SER3_IPL_ISR	IPL2SRS
#define	_SER3_IPL		4
#define	_SER3_SPL		0
#define _SER3_TX_OUT    PPS_OUT_U3TX
#define _SER3_TX_PIN    14               // RB5
#define _SER3_RX_IN     PPS_IN_U3RX
#define _SER3_RX_PIN    20               // RB3

/* Serial4 UART5 LCD
*/
#define	_SER4_BASE		_UART5_BASE_ADDRESS
#define	_SER4_IRQ		_UART5_FAULT_VECTOR
#define	_SER4_VECTOR	_UART5_FAULT_VECTOR
#define	_SER4_IPL_ISR	IPL2SRS
#define	_SER4_IPL		4
#define	_SER4_SPL		0
#define _SER4_TX_OUT    PPS_OUT_U5TX
#define _SER4_TX_PIN    58               // RG0
#define _SER4_RX_IN     PPS_IN_U5RX
#define _SER4_RX_PIN    60               // RG1

/* Serial5 UART6 Aux
*/
#define	_SER5_BASE		_UART6_BASE_ADDRESS
#define	_SER5_IRQ		_UART6_FAULT_VECTOR
#define	_SER5_VECTOR	_UART6_FAULT_VECTOR
#define	_SER5_IPL_ISR	IPL2SRS
#define	_SER5_IPL		4
#define	_SER5_SPL		0
#define _SER5_TX_OUT    PPS_OUT_U6TX
#define _SER5_TX_PIN    24               // RB8
#define _SER5_RX_IN     PPS_IN_U6RX
#define _SER5_RX_PIN    21               // RB2

/* ------------------------------------------------------------ */
/*					SPI Port Declarations						*/
/* ------------------------------------------------------------ */

/* The Digilent DSPI and standard SPI libraries uses these ports.
*/

// W25Q128
#define	_DSPI0_BASE			_SPI2_BASE_ADDRESS
#define	_DSPI0_ERR_IRQ		_SPI2_FAULT_VECTOR
#define	_DSPI0_RX_IRQ		_SPI2_RX_VECTOR
#define	_DSPI0_TX_IRQ		_SPI2_TX_VECTOR
#define	_DSPI0_VECTOR		_SPI2_FAULT_VECTOR
#define _DSPI0_IPL_ISR		IPL3SRS
#define	_DSPI0_IPL			5
#define	_DSPI0_SPL			0

#define _DSPI0_MISO_IN		PPS_IN_SDI2
#define _DSPI0_MISO_PIN		54		    // RC4
#define _DSPI0_MOSI_OUT		PPS_OUT_SDO2
#define _DSPI0_MOSI_PIN		35		    // RC1


// DSPI1
#define	_DSPI1_BASE			_SPI1_BASE_ADDRESS
#define	_DSPI1_ERR_IRQ		_SPI1_FAULT_VECTOR
#define	_DSPI1_RX_IRQ		_SPI1_RX_VECTOR
#define	_DSPI1_TX_IRQ		_SPI1_TX_VECTOR
#define	_DSPI1_VECTOR		_SPI1_FAULT_VECTOR
#define _DSPI1_IPL_ISR		IPL3SRS
#define	_DSPI1_IPL			5
#define	_DSPI1_SPL			0

#define _DSPI1_MISO_IN		PPS_IN_SDI1
#define _DSPI1_MISO_PIN		6		        // RD2
#define _DSPI1_MOSI_OUT		PPS_OUT_SDO1
#define _DSPI1_MOSI_PIN		9		        // RD3

// W5500
#define	_DSPI2_BASE			_SPI3_BASE_ADDRESS
#define	_DSPI2_ERR_IRQ		_SPI3_FAULT_VECTOR
#define	_DSPI2_RX_IRQ		_SPI3_RX_VECTOR
#define	_DSPI2_TX_IRQ		_SPI3_TX_VECTOR
#define	_DSPI2_VECTOR		_SPI3_FAULT_VECTOR
#define _DSPI2_IPL_ISR		IPL3SRS
#define	_DSPI2_IPL			5
#define	_DSPI2_SPL			0

#define _DSPI2_MISO_IN		PPS_IN_SDI3
#define _DSPI2_MISO_PIN		39		    // RD14
#define _DSPI2_MOSI_OUT		PPS_OUT_SDO3
#define _DSPI2_MOSI_PIN		53		    // RB10

// DSPI3
#define	_DSPI3_BASE			_SPI4_BASE_ADDRESS
#define	_DSPI3_ERR_IRQ		_SPI4_FAULT_VECTOR
#define	_DSPI3_RX_IRQ		_SPI4_RX_VECTOR
#define	_DSPI3_TX_IRQ		_SPI4_TX_VECTOR
#define	_DSPI3_VECTOR		_SPI4_FAULT_VECTOR
#define _DSPI3_IPL_ISR		IPL3SRS
#define	_DSPI3_IPL			5
#define	_DSPI3_SPL			0

#define _DSPI3_MISO_IN		PPS_IN_SDI4
#define _DSPI3_MISO_PIN		11		    // RD11
#define _DSPI3_MOSI_OUT		PPS_OUT_SDO4
#define _DSPI3_MOSI_PIN		3		    // RD4

// DSPI6
#define	_DSPI6_BASE			_SPI6_BASE_ADDRESS
#define	_DSPI6_ERR_IRQ		_SPI6_FAULT_VECTOR
#define	_DSPI6_RX_IRQ		_SPI6_RX_VECTOR
#define	_DSPI6_TX_IRQ		_SPI6_TX_VECTOR
#define	_DSPI6_VECTOR		_SPI6_FAULT_VECTOR
#define _DSPI6_IPL_ISR		IPL3SRS
#define	_DSPI6_IPL			5
#define	_DSPI6_SPL			0

#define _DSPI6_MOSI_OUT		PPS_OUT_SDO6
#define _DSPI6_MOSI_PIN		64		    // RF12


/* ------------------------------------------------------------ */
/*					I2C Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard I2C port uses I2C4 (SCL4/SDA4). These come to pins
** A4/A5 pins 18/19 on the analog connector.
*/
#define	_TWI_BASE		_I2C4_BASE_ADDRESS
#define	_TWI_BUS_IRQ	_I2C4_BUS_VECTOR
#define	_TWI_SLV_IRQ	_I2C4_SLAVE_VECTOR
#define	_TWI_MST_IRQ	_I2C4_MASTER_VECTOR
#define	_TWI_VECTOR		_I2C4_BUS_VECTOR
#define _TWI_IPL_ISR	IPL3SRS
#define _TWI_IPL		3
#define	_TWI_SPL		0

/* Declarations for Digilent DTWI library.
**		DTWI0 is SDA2/SCL2 on A4/A5 pins 18/19 (see above comment).
*/

// DTWI0 unused
#define	_DTWI0_BASE		_I2C4_BASE_ADDRESS
#define	_DTWI0_BUS_IRQ	_I2C4_BUS_VECTOR
#define	_DTWI0_VECTOR	_I2C4_BUS_VECTOR
#define	_DTWI0_IPL_ISR	IPL3SRS 
#define	_DTWI0_IPL		3
#define	_DTWI0_SPL		0
#define _DTWI0_SCL_PIN  19 
#define _DTWI0_SDA_PIN  18

// DTWI1 MLX90614
#define	_DTWI1_BASE		_I2C2_BASE_ADDRESS
#define	_DTWI1_BUS_IRQ	_I2C2_BUS_VECTOR
#define	_DTWI1_VECTOR	_I2C2_BUS_VECTOR
#define	_DTWI1_IPL_ISR	IPL3SRS 
#define	_DTWI1_IPL		3
#define	_DTWI1_SPL		0
#define _DTWI1_SCL_PIN  37 
#define _DTWI1_SDA_PIN  4

/* ------------------------------------------------------------ */
/*  On MZ parts, ports are defined                              */
/* ------------------------------------------------------------ */

#define _PORTA
#define _PORTB
#define _PORTC
#define _PORTD
#define _PORTE
#define _PORTF
#define _PORTG
/* ------------------------------------------------------------ */
/*					A/D Converter Declarations					*/
/* ------------------------------------------------------------ */
#define ADCRANGE        4096ul              // analog read will return a max number of ADCRANGE-1
#define ADCTADFREQ      25000000ul          // How fast to run the TAD ADC clock
#define ADCTADSH        68ul                // How many TADs the Sample and Hold will charge
#define __ALT_ADC_IMPL__
extern void initADC(void);
extern int convertADC(uint8_t channelNumber);

#define	PIN_W5500_RST   48 // RB13
#define PIN_SPI_SS_ETHERNET_LIB 17 // RB15 SS3

#define PIN_SPIFLASH_SS  16 //RC2 SS2

#define	PIN_HEATER_EN   47 // RA4

#endif	// BOARD_DEFS_H

/************************************************************************/
