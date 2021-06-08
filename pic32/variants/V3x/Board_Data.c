#if !defined(BOARD_DATA_C)
#define BOARD_DATA_C

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*                    Data Tables                               */
/* ------------------------------------------------------------ */
/* The following declarations define data used in pin mapping.  */
/* ------------------------------------------------------------ */
#if defined(OPT_BOARD_DATA)

/* ------------------------------------------------------------ */
/* This table is used to map from port number to the address of
** the TRIS register for the port. This is used for setting the
** pin direction.
*/
const uint32_t port_to_tris_PGM[] = {
    NOT_A_PORT,                //index value 0 is not used

#if defined(_PORTA)
    (uint32_t)&TRISA,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTB)
    (uint32_t)&TRISB,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTC)
    (uint32_t)&TRISC,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTD)
    (uint32_t)&TRISD,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTE)
    (uint32_t)&TRISE,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTF)
    (uint32_t)&TRISF,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTG)
    (uint32_t)&TRISG,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTH)
    (uint32_t)&TRISH,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTJ)
    (uint32_t)&TRISJ,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTK)
    (uint32_t)&TRISK,
#else
    NOT_A_PORT,
#endif

    NOT_A_PORT,
};

/* ------------------------------------------------------------ */
/* This table is used to map the digital pin number to the port
** containing that pin.
*/
const uint8_t digital_pin_to_port_PGM[] = {
    _IOPORT_PH,    //	0	RH10
    _IOPORT_PD,    //	1	RD15
    _IOPORT_PH,    //	2	RH7
    _IOPORT_PH,    //	3	RH5
    _IOPORT_PB,    //	4	RB13
    _IOPORT_PF,    //	5	RF12
    _IOPORT_PA,    //	6	RA1
    _IOPORT_PK,    //	7	RK2
    _IOPORT_PH,    //	8	RH11
    _IOPORT_PH,    //	9	RH9
    _IOPORT_PD,    //	10	RD14
    _IOPORT_PH,    //	11	RH6
    _IOPORT_PH,    //	12	RH4
    _IOPORT_PB,    //	13	RB12
    _IOPORT_PF,    //	14	RF13
    _IOPORT_PK,    //	15	RK3
    _IOPORT_PB,    //	16	RB11
    _IOPORT_PH,    //	17	RH3
    _IOPORT_PH,    //	18	RH1
    _IOPORT_PA,    //	19	RA10
    _IOPORT_PJ,    //	20	RJ15
    _IOPORT_PB,    //	21	RB0
    _IOPORT_PJ,    //	22	RJ13
    _IOPORT_PB,    //	23	RB4
    _IOPORT_PK,    //	24	RK1
    _IOPORT_PB,    //	25	RB8
    _IOPORT_PH,    //	26	RH2
    _IOPORT_PH,    //	27	RH0
    _IOPORT_PA,    //	28	RA9
    _IOPORT_PJ,    //	29	RJ14
    _IOPORT_PB,    //	30	RB2
    _IOPORT_PJ,    //	31	RJ11
    _IOPORT_PD,    //	32	RD5
    _IOPORT_PD,    //	33	RD7
    _IOPORT_PF,    //	34	RF1
    _IOPORT_PJ,    //	35	RJ2
    _IOPORT_PA,    //	36	RA6
    _IOPORT_PJ,    //	37	RJ4
    _IOPORT_PJ,    //	38	RJ6
    _IOPORT_PE,    //	39	RE0
    _IOPORT_PJ,    //	40	RJ1
    _IOPORT_PD,    //	41	RD6
    _IOPORT_PF,    //	42	RF0
    _IOPORT_PJ,    //	43	RJ3
    _IOPORT_PK,    //	44	RK7
    _IOPORT_PA,    //	45	RA7
    _IOPORT_PJ,    //	46	RJ5
    _IOPORT_PJ,    //	47	RJ7
    _IOPORT_PG,    //	48	RG12
    _IOPORT_PE,    //	49	RE2
    _IOPORT_PE,    //	50	RE4
    _IOPORT_PA,    //	51	RA5
    _IOPORT_PE,    //	52	RE6
    _IOPORT_PC,    //	53	RC1
    _IOPORT_PJ,    //	54	RJ9
    _IOPORT_PJ,    //	55	RJ10
    _IOPORT_PG,    //	56	RG14
    _IOPORT_PG,    //	57	RG13
    _IOPORT_PE,    //	58	RE3
    _IOPORT_PG,    //	59	RG15
    _IOPORT_PE,    //	60	RE5
    _IOPORT_PE,    //	61	RE7
    _IOPORT_PJ,    //	62	RJ8
    _IOPORT_PJ,    //	63	RJ12
    _IOPORT_PF,    //	64	RF5
    _IOPORT_PF,    //	65	RF4
    _IOPORT_PH,    //	66	RH13
    _IOPORT_PA,    //	67	RA4
    _IOPORT_PG,    //	68	RG0
    _IOPORT_PG,    //	69	RG1
    _IOPORT_PH,    //	70	RH14
    _IOPORT_PD,    //	71	RD12
    _IOPORT_PD,    //	72	RD1
    _IOPORT_PH,    //	73	RH15
    _IOPORT_PD,    //	74	RD2
    _IOPORT_PD,    //	75	RD3
    _IOPORT_PD,    //	76	RD13
    _IOPORT_PJ,    //	77	RJ0
    _IOPORT_PE,    //	78	RE1
    _IOPORT_PA,    //	79	RA3
    _IOPORT_PA,    //	80	RA2
    _IOPORT_PH,    //	81	RH12
    _IOPORT_PA,    //	82	RA15
    _IOPORT_PA,    //	83	RA14
    _IOPORT_PK,    //	84	RK5
    _IOPORT_PK,    //	85	RK4
    _IOPORT_PD,    //	86	RD10
    _IOPORT_PD,    //	87	RD11
    _IOPORT_PC,    //	88	RC2
    _IOPORT_PB,    //	89	RB5
    _IOPORT_PB,    //	90	RB3
    _IOPORT_PG,    //	91	RG6
    _IOPORT_PB,    //	92	RB15
    _IOPORT_PB,    //	93	RB10
    _IOPORT_PB,    //	94	RB9
    _IOPORT_PB,    //	95	RB14
    _IOPORT_PH,    //	96	RH8
    _IOPORT_PF,    //	97	RF8
    _IOPORT_PF,    //	98	RF2
    _IOPORT_PE,    //	99	RE8
    _IOPORT_PE,    //100	RE9
    _IOPORT_PD     //  101 RD4

};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t digital_pin_to_bit_mask_PGM[] = 
{
    _BV(10),        //  	0	RH10
    _BV(15),        //  	1	RD15
    _BV(7),	        //  2	RH7
    _BV(5),	        //  3	RH5
    _BV(13),        //  	4	RB13
    _BV(12),        //  	5	RF12
    _BV(1),	        //  6	RA1
    _BV(2),	        //  7	RK2
    _BV(11),        //  	8	RH11
    _BV(9),	        //  9	RH9
    _BV(14),        //  	10	RD14
    _BV(6),	        //  11	RH6
    _BV(4),	        //  12	RH4
    _BV(12),        //  	13	RB12
    _BV(13),        //  	14	RF13
    _BV(3),	        //  15	RK3
    _BV(11),        //  	16	RB11
    _BV(3),	        //  17	RH3
    _BV(1),	        //  18	RH1
    _BV(10),        //  	19	RA10
    _BV(15),        //  	20	RJ15
    _BV(0),	        //  21	RB0
    _BV(13),        //  	22	RJ13
    _BV(4),	        //  23	RB4
    _BV(1),	        //  24	RK1
    _BV(8),	        //  25	RB8
    _BV(2),	        //  26	RH2
    _BV(0),	        //  27	RH0
    _BV(9),	        //  28	RA9
    _BV(14),        //  	29	RJ14
    _BV(2),	        //  30	RB2
    _BV(11),        //  	31	RJ11
    _BV(5),	        //  32	RD5
    _BV(7),	        //  33	RD7
    _BV(1),	        //  34	RF1
    _BV(2),	        //  35	RJ2
    _BV(6),	        //  36	RA6
    _BV(4),	        //  37	RJ4
    _BV(6),	        //  38	RJ6
    _BV(0),	        //  39	RE0
    _BV(1),	        //  40	RJ1
    _BV(6),	        //  41	RD6
    _BV(0),	        //  42	RF0
    _BV(3),	        //  43	RJ3
    _BV(7),	        //  44	RK7
    _BV(7),	        //  45	RA7
    _BV(5),	        //  46	RJ5
    _BV(7),	        //  47	RJ7
    _BV(12),        //  	48	RG12
    _BV(2),	        //  49	RE2
    _BV(4),	        //  50	RE4
    _BV(5),	        //  51	RA5
    _BV(6),	        //  52	RE6
    _BV(1),	        //  53	RC1
    _BV(9),	        //  54	RJ9
    _BV(10),        //  	55	RJ10
    _BV(14),        //  	56	RG14
    _BV(13),        //  	57	RG13
    _BV(3),	        //  58	RE3
    _BV(15),        //  	59	RG15
    _BV(5),	        //  60	RE5
    _BV(7),	        //  61	RE7
    _BV(8),	        //  62	RJ8
    _BV(12),        //  	63	RJ12
    _BV(5),	        //  64	RF5
    _BV(4),	        //  65	RF4
    _BV(13),        //  	66	RH13
    _BV(4),	        //  67	RA4
    _BV(0),	        //  68	RG0
    _BV(1),	        //  69	RG1
    _BV(14),        //  	70	RH14
    _BV(12),        //  	71	RD12
    _BV(1),	        //  72	RD1
    _BV(15),        //  	73	RH15
    _BV(2),	        //  74	RD2
    _BV(3),	        //  75	RD3
    _BV(13),        //  	76	RD13
    _BV(0),	        //  77	RJ0
    _BV(1),	        //  78	RE1
    _BV(3),	        //  79	RA3
    _BV(2),	        //  80	RA2
    _BV(12),        //  	81	RH12
    _BV(15),        //  	82	RA15
    _BV(14),        //  	83	RA14
    _BV(5),	        //  84	RK5
    _BV(4),	        //  85	RK4
    _BV(10),        //  	86	RD10
    _BV(11),        //  	87	RD11
    _BV(2),	        //  88	RC2
    _BV(5),	        //  89	RB5
    _BV(3),	        //  90	RB3
    _BV(6),	        //  91	RG6
    _BV(15),        //  	92	RB15
    _BV(10),        //  	93	RB10
    _BV(9),	        //  94	RB9
    _BV(14),        //  	95	RB14
    _BV(8),	        //  96	RH8
    _BV(8),	        //  97	RF8
    _BV(2),	        //  98	RF2
    _BV(8),	        //  99	RE8
    _BV(9),	        //  100	RE9
    _BV(4),         //  101 RD4
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint16_t digital_pin_to_timer_PGM[] =
{
    NOT_ON_TIMER,   //	0	RH10
    NOT_ON_TIMER,   //	1	RD15
    NOT_ON_TIMER,   //	2	RH7
    NOT_ON_TIMER,   //	3	RH5
    NOT_ON_TIMER,   //	4	RB13
    NOT_ON_TIMER,   //	5	RF12
    NOT_ON_TIMER,   //	6	RA1
    NOT_ON_TIMER,   //	7	RK2
    NOT_ON_TIMER,   //	8	RH11
    NOT_ON_TIMER,   //	9	RH9
    NOT_ON_TIMER,   //	10	RD14
    NOT_ON_TIMER,   //	11	RH6
    NOT_ON_TIMER,   //	12	RH4
    NOT_ON_TIMER,   //	13	RB12
    NOT_ON_TIMER,   //	14	RF13
    NOT_ON_TIMER,   //	15	RK3
    NOT_ON_TIMER,   //	16	RB11
    NOT_ON_TIMER,   //	17	RH3
    NOT_ON_TIMER,   //	18	RH1
    NOT_ON_TIMER,   //	19	RA10
    NOT_ON_TIMER,   //	20	RJ15
    NOT_ON_TIMER,   //	21	RB0
    NOT_ON_TIMER,   //	22	RJ13
    NOT_ON_TIMER,   //	23	RB4
    NOT_ON_TIMER,   //	24	RK1
    NOT_ON_TIMER,   //	25	RB8
    NOT_ON_TIMER,   //	26	RH2
    NOT_ON_TIMER,   //	27	RH0
    NOT_ON_TIMER,   //	28	RA9
    NOT_ON_TIMER,   //	29	RJ14
    NOT_ON_TIMER,   //	30	RB2
    NOT_ON_TIMER,   //	31	RJ11
    NOT_ON_TIMER,   //	32	RD5
    NOT_ON_TIMER,   //	33	RD7
    NOT_ON_TIMER,   //	34	RF1
    NOT_ON_TIMER,   //	35	RJ2
    NOT_ON_TIMER,   //	36	RA6
    NOT_ON_TIMER,   //	37	RJ4
    NOT_ON_TIMER,   //	38	RJ6
    NOT_ON_TIMER,   //	39	RE0
    NOT_ON_TIMER,   //	40	RJ1
    NOT_ON_TIMER,   //	41	RD6
    _TIMER_OC4,	    // 42	RF0
    NOT_ON_TIMER,   //	43	RJ3
    NOT_ON_TIMER,   //	44	RK7
    NOT_ON_TIMER,   //	45	RA7
    NOT_ON_TIMER,   //	46	RJ5
    NOT_ON_TIMER,   //	47	RJ7
    NOT_ON_TIMER,   //	48	RG12
    NOT_ON_TIMER,   //	49	RE2
    NOT_ON_TIMER,   //	50	RE4
    NOT_ON_TIMER,   //	51	RA5
    NOT_ON_TIMER,   //	52	RE6
    NOT_ON_TIMER,   //	53	RC1
    NOT_ON_TIMER,   //	54	RJ9
    NOT_ON_TIMER,   //	55	RJ10
    NOT_ON_TIMER,   //	56	RG14
    NOT_ON_TIMER,   //	57	RG13
    NOT_ON_TIMER,   //	58	RE3
    NOT_ON_TIMER,   //	59	RG15
    NOT_ON_TIMER,   //	60	RE5
    NOT_ON_TIMER,   //	61	RE7
    NOT_ON_TIMER,   //	62	RJ8
    NOT_ON_TIMER,   //	63	RJ12
    NOT_ON_TIMER,   //	64	RF5
    NOT_ON_TIMER,   //	65	RF4
    NOT_ON_TIMER,   //	66	RH13
    NOT_ON_TIMER,   //	67	RA4
    NOT_ON_TIMER,   //	68	RG0
    NOT_ON_TIMER,   //	69	RG1
    NOT_ON_TIMER,   //	70	RH14
    NOT_ON_TIMER,   //	71	RD12
    NOT_ON_TIMER,   //	72	RD1
    NOT_ON_TIMER,   //	73	RH15
    NOT_ON_TIMER,   //	74	RD2
    NOT_ON_TIMER,   //	75	RD3
    NOT_ON_TIMER,   //	76	RD13
    NOT_ON_TIMER,   //	77	RJ0
    NOT_ON_TIMER,   //	78	RE1
    NOT_ON_TIMER,   //	79	RA3
    NOT_ON_TIMER,   //	80	RA2
    NOT_ON_TIMER,   //	81	RH12
    NOT_ON_TIMER,   //	82	RA15
    NOT_ON_TIMER,   //	83	RA14
    NOT_ON_TIMER,   //	84	RK5
    NOT_ON_TIMER,   //	85	RK4
    NOT_ON_TIMER,   //	86	RD10
    NOT_ON_TIMER,   //	87	RD11
    NOT_ON_TIMER,   //	88	RC2
    NOT_ON_TIMER,   //	89	RB5
    NOT_ON_TIMER,   //	90	RB3
    NOT_ON_TIMER,   //	91	RG6
    NOT_ON_TIMER,   //	92	RB15
    NOT_ON_TIMER,   //	93	RB10
    NOT_ON_TIMER,   //	94	RB9
    NOT_ON_TIMER,   //	95	RB14
    NOT_ON_TIMER,   //	96	RH8
    NOT_ON_TIMER,   //	97	RF8
    NOT_ON_TIMER,   //	98	RF2
    NOT_ON_TIMER,   //	99	RE8
    NOT_ON_TIMER,   //	100	RE9
    NOT_ON_TIMER,   //  101 RD4
};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** analog pin number.
*/
const uint8_t digital_pin_to_analog_PGM[] = {
    NOT_ANALOG_PIN,	 //  0	RH10
    NOT_ANALOG_PIN,	 //  1	RD15
    NOT_ANALOG_PIN,	 //  2	RH7
    NOT_ANALOG_PIN,	 //  3	RH5
    NOT_ANALOG_PIN,	 //  4	RB13
    NOT_ANALOG_PIN,	 //  5	RF12
    NOT_ANALOG_PIN,	 //  6	RA1
    NOT_ANALOG_PIN,	 //  7	RK2
    NOT_ANALOG_PIN,	 //  8	RH11
    NOT_ANALOG_PIN,	 //  9	RH9
    NOT_ANALOG_PIN,	 //  10	RD14
    NOT_ANALOG_PIN,	 //  11	RH6
    NOT_ANALOG_PIN,	 //  12	RH4
    NOT_ANALOG_PIN,	 //  13	RB12
    NOT_ANALOG_PIN,	 //  14	RF13
    NOT_ANALOG_PIN,	 //  15	RK3
    NOT_ANALOG_PIN,	 //  16	RB11
    NOT_ANALOG_PIN,	 //  17	RH3
    NOT_ANALOG_PIN,	 //  18	RH1
    NOT_ANALOG_PIN,	 //  19	RA10
    NOT_ANALOG_PIN,	 //  20	RJ15
    NOT_ANALOG_PIN,	 //  21	RB0
    NOT_ANALOG_PIN,	 //  22	RJ13
    NOT_ANALOG_PIN,	 //  23	RB4
    NOT_ANALOG_PIN,	 //  24	RK1
    NOT_ANALOG_PIN,	 //  25	RB8
    NOT_ANALOG_PIN,	 //  26	RH2
    NOT_ANALOG_PIN,	 //  27	RH0
    NOT_ANALOG_PIN,	 //  28	RA9
    NOT_ANALOG_PIN,	 //  29	RJ14
    NOT_ANALOG_PIN,	 //  30	RB2
    NOT_ANALOG_PIN,	 //  31	RJ11
    NOT_ANALOG_PIN,	 //  32	RD5
    NOT_ANALOG_PIN,	 //  33	RD7
    NOT_ANALOG_PIN,	 //  34	RF1
    NOT_ANALOG_PIN,	 //  35	RJ2
    NOT_ANALOG_PIN,	 //  36	RA6
    NOT_ANALOG_PIN,	 //  37	RJ4
    NOT_ANALOG_PIN,	 //  38	RJ6
    NOT_ANALOG_PIN,	 //  39	RE0
    NOT_ANALOG_PIN,	 //  40	RJ1
    NOT_ANALOG_PIN,	 //  41	RD6
    NOT_ANALOG_PIN,	 //  42	RF0
    NOT_ANALOG_PIN,	 //  43	RJ3
    NOT_ANALOG_PIN,	 //  44	RK7
    NOT_ANALOG_PIN,	 //  45	RA7
    NOT_ANALOG_PIN,	 //  46	RJ5
    NOT_ANALOG_PIN,	 //  47	RJ7
    NOT_ANALOG_PIN,	 //  48	RG12
    NOT_ANALOG_PIN,	 //  49	RE2
    NOT_ANALOG_PIN,	 //  50	RE4
    NOT_ANALOG_PIN,	 //  51	RA5
    NOT_ANALOG_PIN,	 //  52	RE6
    NOT_ANALOG_PIN,	 //  53	RC1
    NOT_ANALOG_PIN,	 //  54	RJ9
    NOT_ANALOG_PIN,	 //  55	RJ10
    NOT_ANALOG_PIN,	 //  56	RG14
    NOT_ANALOG_PIN,	 //  57	RG13
    NOT_ANALOG_PIN,	 //  58	RE3
    NOT_ANALOG_PIN,	 //  59	RG15
    NOT_ANALOG_PIN,	 //  60	RE5
    NOT_ANALOG_PIN,	 //  61	RE7
    NOT_ANALOG_PIN,	 //  62	RJ8
    NOT_ANALOG_PIN,	 //  63	RJ12
    NOT_ANALOG_PIN,	 //  64	RF5
    NOT_ANALOG_PIN,	 //  65	RF4
    NOT_ANALOG_PIN,	 //  66	RH13
    NOT_ANALOG_PIN,	 //  67	RA4
    NOT_ANALOG_PIN,	 //  68	RG0
    NOT_ANALOG_PIN,	 //  69	RG1
    NOT_ANALOG_PIN,	 //  70	RH14
    NOT_ANALOG_PIN,	 //  71	RD12
    NOT_ANALOG_PIN,	 //  72	RD1
    NOT_ANALOG_PIN,	 //  73	RH15
    NOT_ANALOG_PIN,	 //  74	RD2
    NOT_ANALOG_PIN,	 //  75	RD3
    NOT_ANALOG_PIN,	 //  76	RD13
    NOT_ANALOG_PIN,	 //  77	RJ0
    NOT_ANALOG_PIN,	 //  78	RE1
    NOT_ANALOG_PIN,	 //  79	RA3
    NOT_ANALOG_PIN,	 //  80	RA2
    NOT_ANALOG_PIN,	 //  81	RH12
    NOT_ANALOG_PIN,	 //  82	RA15
    NOT_ANALOG_PIN,	 //  83	RA14
    NOT_ANALOG_PIN,	 //  84	RK5
    NOT_ANALOG_PIN,	 //  85	RK4
    NOT_ANALOG_PIN,	 //  86	RD10
    NOT_ANALOG_PIN,	 //  87	RD11
    NOT_ANALOG_PIN,	 //  88	RC2
    NOT_ANALOG_PIN,	 //  89	RB5
    NOT_ANALOG_PIN,	 //  90	RB3
    NOT_ANALOG_PIN,	 //  91	RG6
    NOT_ANALOG_PIN,	 //  92	RB15
    NOT_ANALOG_PIN,	 //  93	RB10
    NOT_ANALOG_PIN,	 //  94	RB9
    NOT_ANALOG_PIN,	 //  95	RB14
    NOT_ANALOG_PIN,	 //  96	RH8
    NOT_ANALOG_PIN,	 //  97	RF8
    NOT_ANALOG_PIN,	 //  98	RF2
    NOT_ANALOG_PIN,	 //  99	RE8
    NOT_ANALOG_PIN,	 //  100	RE9
    NOT_ANALOG_PIN   //  101 RD4
};


/* ------------------------------------------------------------ */
/* This table is used to map from the analog pin number to the
** actual A/D converter channel used for that pin.
*/
const uint8_t analog_pin_to_channel_PGM[] =
{
    45,         //*    A0                       AN45
    49,         //*    A1                       AN49
    21,         //*    A2                       AN21
    10,         //*    A3                       AN10
    13,         //*    A4                       AN13
    12,         //*    A5                       AN12
    3,          //*    A6                       AN3
    2,          //*    A7                       AN2
    4,          //*    A8                       AN4
    1,          //*    A9                       AN1
    48,         //*    A10                      AN48
    0,          //*    A11                      AN00
    8,          //*    A12                      AN8
    7,          //*    A13                      AN7
};


/* ------------------------------------------------------------ */
/*                PPS Mappings                                    */
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** PPS register. This register is used to select the peripheral output
** connected to the pin. The register is set to 0 to disconnedt the
** pin from any peripheral so it can be used as GPIO.
** For PIC32MX1xx/2xx series devices, the PPS output select registers
** are arranged as a contiguous series of 32 bit registers. This table
** treats these registers as an array of DWORDs an stores the index
** to the register.
*/
const uint8_t digital_pin_to_pps_out_PGM[] = {
    NOT_PPS_PIN,        //  0	RH10
    _PPS_OUT(_PPS_RPD15R),        //  1	RD15
    NOT_PPS_PIN,        //  2	RH7
    NOT_PPS_PIN,        //  3	RH5
    NOT_PPS_PIN,        //  4	RB13
    _PPS_OUT(_PPS_RPF12R),        //  5	RF12
    NOT_PPS_PIN,        //  6	RA1
    NOT_PPS_PIN,        //  7	RK2
    NOT_PPS_PIN,        //  8	RH11
    NOT_PPS_PIN,        //  9	RH9
    _PPS_OUT(_PPS_RPD14R),        //  10	RD14
    NOT_PPS_PIN,        //  11	RH6
    NOT_PPS_PIN,        //  12	RH4
    NOT_PPS_PIN,        //  13	RB12
    _PPS_OUT(_PPS_RPF13R),        //  14	RF13
    NOT_PPS_PIN,        //  15	RK3
    NOT_PPS_PIN,        //  16	RB11
    NOT_PPS_PIN,        //  17	RH3
    NOT_PPS_PIN,        //  18	RH1
    NOT_PPS_PIN,        //  19	RA10
    NOT_PPS_PIN,        //  20	RJ15
    _PPS_OUT(_PPS_RPB0R),        //  21	RB0
    NOT_PPS_PIN,        //  22	RJ13
    NOT_PPS_PIN,        //  23	RB4
    NOT_PPS_PIN,        //  24	RK1
    _PPS_OUT(_PPS_RPB8R),        //  25	RB8
    NOT_PPS_PIN,        //  26	RH2
    NOT_PPS_PIN,        //  27	RH0
    NOT_PPS_PIN,        //  28	RA9
    NOT_PPS_PIN,        //  29	RJ14
    _PPS_OUT(_PPS_RPB2R),        //  30	RB2
    NOT_PPS_PIN,        //  31	RJ11
    _PPS_OUT(_PPS_RPD5R),        //  32	RD5
    _PPS_OUT(_PPS_RPD7R),        //  33	RD7
    _PPS_OUT(_PPS_RPF1R),        //  34	RF1
    NOT_PPS_PIN,        //  35	RJ2
    NOT_PPS_PIN,        //  36	RA6
    NOT_PPS_PIN,        //  37	RJ4
    NOT_PPS_PIN,        //  38	RJ6
    NOT_PPS_PIN,        //  39	RE0
    NOT_PPS_PIN,        //  40	RJ1
    _PPS_OUT(_PPS_RPD6R),        //  41	RD6
    _PPS_OUT(_PPS_RPF0R),        //  42	RF0
    NOT_PPS_PIN,        //  43	RJ3
    NOT_PPS_PIN,        //  44	RK7
    NOT_PPS_PIN,        //  45	RA7
    NOT_PPS_PIN,        //  46	RJ5
    NOT_PPS_PIN,        //  47	RJ7
    NOT_PPS_PIN,        //  48	RG12
    NOT_PPS_PIN,        //  49	RE2
    NOT_PPS_PIN,        //  50	RE4
    NOT_PPS_PIN,        //  51	RA5
    NOT_PPS_PIN,        //  52	RE6
    _PPS_OUT(_PPS_RPC1R),        //  53	RC1
    NOT_PPS_PIN,        //  54	RJ9
    NOT_PPS_PIN,        //  55	RJ10
    NOT_PPS_PIN,        //  56	RG14
    NOT_PPS_PIN,        //  57	RG13
    _PPS_OUT(_PPS_RPE3R),        //  58	RE3
    NOT_PPS_PIN,        //  59	RG15
    _PPS_OUT(_PPS_RPE5R),        //  60	RE5
    NOT_PPS_PIN,        //  61	RE7
    NOT_PPS_PIN,        //  62	RJ8
    NOT_PPS_PIN,        //  63	RJ12
    _PPS_OUT(_PPS_RPF5R),        //  64	RF5
    _PPS_OUT(_PPS_RPF4R),        //  65	RF4
    NOT_PPS_PIN,        //  66	RH13
    NOT_PPS_PIN,        //  67	RA4
    _PPS_OUT(_PPS_RPG0R),        //  68	RG0
    _PPS_OUT(_PPS_RPG1R),        //  69	RG1
    NOT_PPS_PIN,        //  70	RH14
    _PPS_OUT(_PPS_RPD12R),        //  71	RD12
    _PPS_OUT(_PPS_RPD1R),        //  72	RD1
    NOT_PPS_PIN,        //  73	RH15
    _PPS_OUT(_PPS_RPD2R),        //  74	RD2
    _PPS_OUT(_PPS_RPD3R),        //  75	RD3
    NOT_PPS_PIN,        //  76	RD13
    NOT_PPS_PIN,        //  77	RJ0
    NOT_PPS_PIN,        //  78	RE1
    NOT_PPS_PIN,        //  79	RA3
    NOT_PPS_PIN,        //  80	RA2
    NOT_PPS_PIN,        //  81	RH12
    _PPS_OUT(_PPS_RPA15R),        //  82	RA15
    _PPS_OUT(_PPS_RPA14R),        //  83	RA14
    NOT_PPS_PIN,        //  84	RK5
    NOT_PPS_PIN,        //  85	RK4
    _PPS_OUT(_PPS_RPD10R),        //  86	RD10
    _PPS_OUT(_PPS_RPD11R),        //  87	RD11
    _PPS_OUT(_PPS_RPC2R),        //  88	RC2
    _PPS_OUT(_PPS_RPB5R),        //  89	RB5
    _PPS_OUT(_PPS_RPB3R),        //  90	RB3
    _PPS_OUT(_PPS_RPG6R),        //  91	RG6
    _PPS_OUT(_PPS_RPB15R),        //  92	RB15
    _PPS_OUT(_PPS_RPB10R),        //  93	RB10
    _PPS_OUT(_PPS_RPB9R),        //  94	RB9
    _PPS_OUT(_PPS_RPB14R),        //  95	RB14
    NOT_PPS_PIN,        //  96	RH8
    _PPS_OUT(_PPS_RPF8R),        //  97	RF8
    _PPS_OUT(_PPS_RPF2R),        //  98	RF2
    _PPS_OUT(_PPS_RPE8R),        //  99	RE8
    _PPS_OUT(_PPS_RPE9R),        //  100	RE9
    _PPS_OUT(_PPS_RPD4R),        //  101 RD4
 };

/* ------------------------------------------------------------ */
/* This table maps from the digital pin number to the value to be
** loaded into a PPS input select register to select that pin.
** It also maps from digital pin number to input/output pin set to 
** which the pin belongs. The set mask is in the high four bits,
** the select value is in the low four bits.
** Note: if the PIC32 device has more than four pin sets, or more than
** 16 pin mapping choices per input function, then this table will have
** to be redefined as a table of uint16_t values and the macros used to
** access the table redefined as well.
*/
const uint8_t digital_pin_to_pps_in_PGM[] = {
    NOT_PPS_PIN,        //  0	RH10
    _PPS_IN(_PPS_RPD15),        //  1	RD15
    NOT_PPS_PIN,        //  2	RH7
    NOT_PPS_PIN,        //  3	RH5
    NOT_PPS_PIN,        //  4	RB13
    _PPS_IN(_PPS_RPF12),        //  5	RF12
    NOT_PPS_PIN,        //  6	RA1
    NOT_PPS_PIN,        //  7	RK2
    NOT_PPS_PIN,        //  8	RH11
    NOT_PPS_PIN,        //  9	RH9
    _PPS_IN(_PPS_RPD14),        //  10	RD14
    NOT_PPS_PIN,        //  11	RH6
    NOT_PPS_PIN,        //  12	RH4
    NOT_PPS_PIN,        //  13	RB12
    _PPS_IN(_PPS_RPF13),        //  14	RF13
    NOT_PPS_PIN,        //  15	RK3
    NOT_PPS_PIN,        //  16	RB11
    NOT_PPS_PIN,        //  17	RH3
    NOT_PPS_PIN,        //  18	RH1
    NOT_PPS_PIN,        //  19	RA10
    NOT_PPS_PIN,        //  20	RJ15
    _PPS_IN(_PPS_RPB0),        //  21	RB0
    NOT_PPS_PIN,        //  22	RJ13
    NOT_PPS_PIN,        //  23	RB4
    NOT_PPS_PIN,        //  24	RK1
    _PPS_IN(_PPS_RPB8),        //  25	RB8
    NOT_PPS_PIN,        //  26	RH2
    NOT_PPS_PIN,        //  27	RH0
    NOT_PPS_PIN,        //  28	RA9
    NOT_PPS_PIN,        //  29	RJ14
    _PPS_IN(_PPS_RPB2),        //  30	RB2
    NOT_PPS_PIN,        //  31	RJ11
    _PPS_IN(_PPS_RPD5),        //  32	RD5
    _PPS_IN(_PPS_RPD7),        //  33	RD7
    _PPS_IN(_PPS_RPF1),        //  34	RF1
    NOT_PPS_PIN,        //  35	RJ2
    NOT_PPS_PIN,        //  36	RA6
    NOT_PPS_PIN,        //  37	RJ4
    NOT_PPS_PIN,        //  38	RJ6
    NOT_PPS_PIN,        //  39	RE0
    NOT_PPS_PIN,        //  40	RJ1
    _PPS_IN(_PPS_RPD6),        //  41	RD6
    _PPS_IN(_PPS_RPF0),        //  42	RF0
    NOT_PPS_PIN,        //  43	RJ3
    NOT_PPS_PIN,        //  44	RK7
    NOT_PPS_PIN,        //  45	RA7
    NOT_PPS_PIN,        //  46	RJ5
    NOT_PPS_PIN,        //  47	RJ7
    NOT_PPS_PIN,        //  48	RG12
    NOT_PPS_PIN,        //  49	RE2
    NOT_PPS_PIN,        //  50	RE4
    NOT_PPS_PIN,        //  51	RA5
    NOT_PPS_PIN,        //  52	RE6
    _PPS_IN(_PPS_RPC1),        //  53	RC1
    NOT_PPS_PIN,        //  54	RJ9
    NOT_PPS_PIN,        //  55	RJ10
    NOT_PPS_PIN,        //  56	RG14
    NOT_PPS_PIN,        //  57	RG13
    _PPS_IN(_PPS_RPE3),        //  58	RE3
    NOT_PPS_PIN,        //  59	RG15
    _PPS_IN(_PPS_RPE5),        //  60	RE5
    NOT_PPS_PIN,        //  61	RE7
    NOT_PPS_PIN,        //  62	RJ8
    NOT_PPS_PIN,        //  63	RJ12
    _PPS_IN(_PPS_RPF5),        //  64	RF5
    _PPS_IN(_PPS_RPF4),        //  65	RF4
    NOT_PPS_PIN,       //  66	RH13
    NOT_PPS_PIN,        //  67	RA4
    _PPS_IN(_PPS_RPG0),        //  68	RG0
    _PPS_IN(_PPS_RPG1),        //  69	RG1
    NOT_PPS_PIN,        //  70	RH14
    _PPS_IN(_PPS_RPD12),        //  71	RD12
    _PPS_IN(_PPS_RPD1),        //  72	RD1
    NOT_PPS_PIN,        //  73	RH15
    _PPS_IN(_PPS_RPD2),        //  74	RD2
    _PPS_IN(_PPS_RPD3),        //  75	RD3
    NOT_PPS_PIN,        //  76	RD13
    NOT_PPS_PIN,        //  77	RJ0
    NOT_PPS_PIN,        //  78	RE1
    NOT_PPS_PIN,        //  79	RA3
    NOT_PPS_PIN,        //  80	RA2
    NOT_PPS_PIN,        //  81	RH12
    _PPS_IN(_PPS_RPA15),        //  82	RA15
    _PPS_IN(_PPS_RPA14),        //  83	RA14
    NOT_PPS_PIN,        //  84	RK5
    NOT_PPS_PIN,        //  85	RK4
    _PPS_IN(_PPS_RPD10),        //  86	RD10
    _PPS_IN(_PPS_RPD11),        //  87	RD11
    _PPS_IN(_PPS_RPC2),        //  88	RC2
    _PPS_IN(_PPS_RPB5),        //  89	RB5
    _PPS_IN(_PPS_RPB3),        //  90	RB3
    _PPS_IN(_PPS_RPG6),        //  91	RG6
    _PPS_IN(_PPS_RPB15),        //  92	RB15
    _PPS_IN(_PPS_RPB10),        //  93	RB10
    _PPS_IN(_PPS_RPB9),        //  94	RB9
    _PPS_IN(_PPS_RPB14),        //  95	RB14
    NOT_PPS_PIN,        //  96	RH8
    _PPS_IN(_PPS_RPF8),        //  97	RF8
    _PPS_IN(_PPS_RPF2),        //  98	RF2
    _PPS_IN(_PPS_RPE8),        //  99	RE8
    _PPS_IN(_PPS_RPE9),        //  100	RE9
    _PPS_IN(_PPS_RPD4),        //  101 RD4
};

/* ------------------------------------------------------------ */
/* This table maps from an output compare number as stored in the
** digital_pin_to_timer_PGM table to the digital pin number of the
** pin that OC is connected to. This table is only required for
** devices that support peripheral pin select (PPS), i.e. PIC32MX1xx/2xx
** devices.
*/

/*const uint8_t output_compare_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,
    PIN_OC1,                  
    PIN_OC2,            
    PIN_OC3,            
    PIN_OC4,            
    PIN_OC5,            
    PIN_OC6,            
};*/
const uint8_t output_compare_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    PIN_OC4,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN
};

/* ------------------------------------------------------------ */
/* This table maps from an external interrupt number to the digital
** pin for that interrupt.
*/

/*const uint8_t external_int_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,        
    PIN_INT1,            
    PIN_INT2,            
    PIN_INT3,            
    PIN_INT4            
};*/
const uint8_t external_int_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,        
    NOT_PPS_PIN,            
    NOT_PPS_PIN,            
    NOT_PPS_PIN,            
    NOT_PPS_PIN            
};

/* ------------------------------------------------------------ */
/*                Board Customization Functions                    */
/* ------------------------------------------------------------ */
/*                                                                */
/* The following can be used to customize the behavior of some    */
/* of the core API functions. These provide hooks that can be    */
/* used to extend or replace the default behavior of the core    */
/* functions. To use one of these functions, add the desired    */
/* code to the function skeleton below and then set the value    */
/* of the appropriate compile switch above to 1. This will        */
/* cause the hook function to be compiled into the build and    */
/* to cause the code to call the hook function to be compiled    */
/* into the appropriate core function.                            */
/*                                                                */
/* ------------------------------------------------------------ */
/***    _board_init
**
**    Parameters:
**        none
**
**    Return Value:
**        none
**
**    Errors:
**        none
**
**    Description:
**        This function is called from the core init() function.
**        This can be used to perform any board specific init
**        that needs to be done when the processor comes out of
**        reset and before the user sketch is run.
*/
#if    (OPT_BOARD_INIT != 0)

void _board_init(void) {
    
}

#endif

/* ------------------------------------------------------------ */
/***    _board_pinMode
**
**    Parameters:
**        pin        - digital pin number to configure
**        mode    - mode to which the pin should be configured
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the pinMode
**        function. It can perform any special processing needed
**        when setting the pin mode. If this function returns zero,
**        control will pass through the normal pinMode code. If
**        it returns a non-zero value the normal pinMode code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_pinMode(uint8_t pin, uint8_t mode) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_getPinMode
**
**    Parameters:
**        pin        - digital pin number
**        mode    - pointer to variable to receive mode value
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the getPinMode
**        function. It can perform any special processing needed
**        when getting the pin mode. If this function returns zero,
**        control will pass through the normal getPinMode code. If
**        it returns a non-zero value the normal getPinMode code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_getPinMode(uint8_t pin, uint8_t * mode) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_digitalWrite
**
**    Parameters:
**        pin        - digital pin number
**        val        - value to write to the pin
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the digitalWrite
**        function. It can perform any special processing needed
**        in writing to the pin. If this function returns zero,
**        control will pass through the normal digitalWrite code. If
**        it returns a non-zero value the normal digitalWrite code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_digitalWrite(uint8_t pin, uint8_t val) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_digitalRead
**
**    Parameters:
**        pin        - digital pin number
**        val        - pointer to variable to receive pin value
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the digitalRead
**        function. It can perform any special processing needed
**        in reading from the pin. If this function returns zero,
**        control will pass through the normal digitalRead code. If
**        it returns a non-zero value the normal digitalRead code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_digitalRead(uint8_t pin, uint8_t * val) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogRead
**
**    Parameters:
**        pin        - analog channel number
**        val        - pointer to variable to receive analog value
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the analogRead
**        function. It can perform any special processing needed
**        in reading from the pin. If this function returns zero,
**        control will pass through the normal analogRead code. If
**        it returns a non-zero value the normal analogRead code isn't
**        executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int    _board_analogRead(uint8_t pin, int * val) {

    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogReference
**
**    Parameters:
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the analogReference
**        function. It can perform any special processing needed
**        to set the reference voltage. If this function returns zero,
**        control will pass through the normal analogReference code. If
**        it returns a non-zero value the normal analogReference code isn't
**        executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int    _board_analogReference(uint8_t mode) {

    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogWrite
**
**    Parameters:
**        pin        - pin number
**        val        - analog value to write
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the analogWrite
**        function. It can perform any special processing needed
**        in writing to the pin. If this function returns zero,
**        control will pass through the normal analogWrite code. If
**        it returns a non-zero value the normal analogWrite code isn't
**        executed.
*/
#if (OPT_BOARD_ANALOG_WRITE != 0)

int    _board_analogWrite(uint8_t pin, int val) {

    return 0;

}

#endif

#endif // OPT_BOARD_DATA

/* ------------------------------------------------------------ */

#endif    // BOARD_DATA_C

/************************************************************************/
