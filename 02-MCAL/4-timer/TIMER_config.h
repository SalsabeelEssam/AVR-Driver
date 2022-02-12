/***************************************************************************************************
 *  File Name        : TIMER_config.h
 *  Module           : TIMER CONFIG
 *  Description      : to interface TIMER
 *  Created on       : may 24, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*******************************************************************/
/* TIMER0 CONFIGRATION */

// NORMAL_MODE =0 , PHASE_CORRECT_MODE=  1 , CTC_MODE =2 , FAST_PWM = 1
#define TIMER0_SELECT_MODE        FAST_PWM


// NO_CLCK_SOURCE =0 , NO_PRECALING =1  CLCK_DIV_8 = 2 , CLCK_DIV_64 = 3, CLCK_DIV_256 = 4,CLCK_DIV_1024 = 5
#define TIMER0_PRESCALER_SELECTION    CLCK_DIV_8


//  DISABLE_INT = 0, ENABLE_INT = 1
#define TIMER0_NORMAL_MODE_INTERRUPT   DISABLE_INT


//  DISABLE_INT = 0, ENABLE_INT = 1
#define TIMER0_CTC_MODE_INTERRUPT      DISABLE_INT


//NORMAL_PORT_OPERATION = 0  INVERTED_MODE =1   , NON_INVERTED_MODE =2
#define TIMER0_FAST_PWM_MODE_SELECTION   NON_INVERTED_MODE

//  NORMAL_PORT_OPERATION = 0  INVERTED_MODE =1   , NON_INVERTED_MODE =2
#define TIMER0_PHASE_CORRECT_MODE_SELECTION   NORMAL_PORT_OPERATION

// NORMAL_PORT_OPERATION = 0 TOGGLE_OC0_ON_COMPARE_MATCH =1   , CLEAR_OC0_ON_COMPARE_MATCH =2 , SET_OC0_ON_COMPARE_MATCH = 3 ,
#define TIMER0_COMPARE_MODE_SELECTION   NORMAL_PORT_OPERATION



// MAX PRELOAD IS 255
#define TIMER0_PRELOAD_VALUE    0

// STE DUTU CYCLE
#define TIMER0_SET_DUTY_CYCLE    128
/*********************************************************************/

/*  TIMER 2 CONFIGRATION*/

// NORMAL_MODE =0 , PHASE_CORRECT_MODE=  1 , CTC_MODE =2 , FAST_PWM = 1
#define TIMER2_SELECT_MODE        CTC_MODE


// NO_CLCK_SOURCE =0 , NO_PRECALING =1  CLCK_DIV_8 = 2 ,CLCK_DIV_32 = 6  CLCK_DIV_64 = 3, CLCK_DIV_128 = 7, CLCK_DIV_256 = 4, CLCK_DIV_1024 = 5
#define TIMER2_PRESCALER_SELECTION    CLCK_DIV_256


//  DISABLE_INT = 0, ENABLE_INT = 1
#define TIMER2_NORMAL_MODE_INTERRUPT   DISABLE_INT


//  DISABLE_INT = 0, ENABLE_INT = 1
#define TIMER2_CTC_MODE_INTERRUPT      ENABLE_INT


//NORMAL_PORT_OPERATION = 0  INVERTED_MODE =1   , NON_INVERTED_MODE =2
#define TIMER2_FAST_PWM_MODE_SELECTION   NORMAL_PORT_OPERATION

//  NORMAL_PORT_OPERATION = 0  INVERTED_MODE =1   , NON_INVERTED_MODE =2
#define TIMER2_PHASE_CORRECT_MODE_SELECTION   NORMAL_PORT_OPERATION

// NORMAL_PORT_OPERATION = 0 TOGGLE_OC0_ON_COMPARE_MATCH =1   , CLEAR_OC0_ON_COMPARE_MATCH =2 , SET_OC0_ON_COMPARE_MATCH = 3 ,
#define TIMER2_COMPARE_MODE_SELECTION   NORMAL_PORT_OPERATION


// MAX PRELOAD IS 255
#define TIMER2_PRELOAD_VALUE    0

// STE DUTU CYCLE
#define TIMER2_SET_DUTY_CYCLE    250


/*********************************************************************/

/*  TIMER 1 CONFIGRATION*/

/*
 * 1 --> NORMAL_MODE_TIMER1
 *
 * 2 --> PWM_PHASE_CORRECT_8BIT
 * 3 --> PWM_PHASE_CORRECT_9BIT
 * 4 --> PWM_PHASE_CORRECT_10BIT
 *
 * 5 --> CTC_MODE_OCR1
 *
 * 6 --> FAST_PWM_8BIT
 * 7 --> FAST_PWM_9BIT
 * 8 --> FAST_PWM_10BIT
 *
 * 9 --> PWM_PHASE_AND_FREQUANCY_CORRECT_ICR1
 * 10 --> PWM_PHASE_AND_FREQUANCY_CORRECT_OCR1
 *
 * 11 --> PWM_PHASE_CORRECT_ICR1
 * 12 --> PWM_PHASE_CORRECT_OCR1
 *
 * 13 --> CTC_MODE_ICR1
 *
 * 15 --> FAST_PWM_ICR1
 * 16 --> FAST_PWM_OCR1
 * */
#define TIMER1_SELECT_MODE                    NORMAL_MODE_TIMER1


// NO_CLCK_SOURCE =0 , NO_PRECALING =1  CLCK_DIV_8 = 2 ,  CLCK_DIV_64 = 3, CLCK_DIV_256 = 4, CLCK_DIV_1024 = 5
#define TIMER1_PRESCALER_SELECTION            CLCK_DIV_8


//  DISABLE_INT = 0, ENABLE_INT = 1
#define TIMER1_NORMAL_MODE_INTERRUPT          DISABLE_INT

//  DISABLE_INT = 0, ENABLE_INT = 1
#define TIMER1_CTC_A_MODE_INTERRUPT           DISABLE_INT

//  DISABLE_INT = 0, ENABLE_INT = 1
#define TIMER1_CTC_B_MODE_INTERRUPT           DISABLE_INT

//  DISABLE_INT = 0, ENABLE_INT = 1
#define TIMER1_INPUT_CAPTURE_MODE_INTERRUPT   DISABLE_INT

/*****************************************************************/
//NORMAL_PORT_OPERATION = 0  INVERTED_MODE =1   , NON_INVERTED_MODE =2, TOGGLE_OCR1A_COMPARE_OC1B_DISCONNECTED = 3
#define TIMER1_FAST_PWM_MODE_A_SELECTION             NORMAL_PORT_OPERATION

//NORMAL_PORT_OPERATION = 0  INVERTED_MODE =1   , NON_INVERTED_MODE =2 , TOGGLE_OCR1A_COMPARE_OC1B_DISCONNECTED = 3
#define TIMER1_FAST_PWM_MODE_B_SELECTION             NORMAL_PORT_OPERATION

/*********************************************************************/
//  NORMAL_PORT_OPERATION = 0  INVERTED_MODE =1   , NON_INVERTED_MODE =2, TOGGLE_OCR1A_COMPARE_OC1B_DISCONNECTED = 3
#define TIMER1_PHASE_CORRECT_MODE_A_SELECTION        NORMAL_PORT_OPERATION

//  NORMAL_PORT_OPERATION = 0  INVERTED_MODE =1   , NON_INVERTED_MODE =2, TOGGLE_OCR1A_COMPARE_OC1B_DISCONNECTED = 3
#define TIMER1_PHASE_CORRECT_MODE_B_SELECTION        NORMAL_PORT_OPERATION

/***********************************************************************/
// NORMAL_PORT_OPERATION = 0 TOGGLE_OC1_A_B_ON_COMPARE_MATCH =1   , CLEAR_OC1_A_B_ON_COMPARE_MATCH =2 , SET_OC1_A_B_ON_COMPARE_MATCH = 3
#define TIMER1_COMPARE_A_MODE_SELECTION              NORMAL_PORT_OPERATION

// NORMAL_PORT_OPERATION = 0 TOGGLE_OC1_A_B_ON_COMPARE_MATCH =1   , CLEAR_OC1_A_B_ON_COMPARE_MATCH =2 , SET_OC1_A_B_ON_COMPARE_MATCH = 3
#define TIMER1_COMPARE_B_MODE_SELECTION              NORMAL_PORT_OPERATION
/*********************************************************************/
// ENABLE_CANCELER = 0,       DISABLE_CANCELER =1
#define TIMER1_INPUT_CAPTURE_NOISE_CANCELER        DISABLE_CANCELER

// RISING_EDGE = 0,       FALLING_EDGE =1
#define TIMER1_INPUT_CAPTURE_EDGE_SELECT        FALLING_EDGE
/*************************************************************************/
// MAX PRELOAD IS 255
#define TIMER1_PRELOAD_VALUE    0

// STE DUTU CYCLE
#define TIMER1_SET_DUTY_CYCLE    250
#endif /* TIMER_CONFIG_H_ */
