/*
 * ADC_Private.h
 *
 *  Created on: Jun 8, 2021
 *      Author: Salsabeel Essam
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_



#define ADMUX    (*(volatile u8*)  0x27)
#define ADCSRA   (*(volatile u8*)  0x26)
#define ADC      (*(volatile u16*) 0x24)
#define ADCL     (*(volatile u8*)  0x24)
#define ADCH     (*(volatile u8*)  0x25)
#define SFIOR    (*(volatile u8*)  0x50)

/**ADMUX Register **/
#define REFS1  7
#define REFS0  6
#define ADLAR  5
#define MUX4   4
#define MUX3   3
#define MUX2   2
#define MUX1   1
#define MUX0   0

/**ADCSRA Register **/
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

/**ADCSRA Register **/
#define ADTS2    7
#define ADTS1    6
#define ADTS0    5


/***nUMBER OF CHANNEL***********/
#define  ADC_U8_CHANNEL_0    0
#define  ADC_U8_CHANNEL_1    1
#define  ADC_U8_CHANNEL_2    2
#define  ADC_U8_CHANNEL_3    3
#define  ADC_U8_CHANNEL_4    4
#define  ADC_U8_CHANNEL_5    5
#define  ADC_U8_CHANNEL_6    6
#define  ADC_U8_CHANNEL_7    7

/*****SELECT VOLTAGE REFERENCE********/
#define AREF_INTERNAL_VREF_TURNED_OFF      0
#define  AVCC_AT_AREF_PIN                  1
#define INTERNAL_2_56_VOLTAGE_REFERENCE    3

/*****ADC_PRESENTATION_CONVERSION_THE_RESULT****/
#define  LEFT_ADJUST_THE_RESULT        1
#define  RIGHT_ADJUST_THE_RESULT       0

/*******ADC_ENABLE_TURNED_ON********/
#define  ADC_ENABLE         1
#define   ADC_DISABLE        0

/******* ADC_START_CONVERTION_IN_MODE ***********/
#define ADC_SINGLE_CONVERSTION_MODE   0
#define ADC_OUTO_TRIGGER_MODE         1

/************PRESCALING *******************/
#define CLCK_DIV_2           0
#define CLCK_DIV_2_2         1
#define CLCK_DIV_4           2
#define CLCK_DIV_8           3
#define CLCK_DIV_16          4
#define CLCK_DIV_32          5
#define CLCK_DIV_64          6
#define CLCK_DIV_128         7


#endif /* ADC_PRIVATE_H_ */
