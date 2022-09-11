/* 
 * File:   M_Timers.h
 * Author: Juancho
 *
 * Created on 26 de abril de 2018, 22:15
 */

#ifndef M_TIMERS_H
#define	M_TIMERS_H
#include "systemPIC32MX.h"

#define TMR1_TGATE 0x00000080
#define TMR1_PRESCALA_1 0x00000000
#define TMR1_PRESCALA_8 0x00000010
#define TMR1_PRESCALA_64 0x00000020
#define TMR1_PRESCALA_256 0x00000030
#define TMR1_EXT_CLK_SYNC 0x00000004
#define TMR1_EXTERNAL_CLK 0x00000002

#define TMR2_TGATE 0x00000080
#define TMR2_PRESCALA_1 0x00000000
#define TMR2_PRESCALA_2 0x00000010
#define TMR2_PRESCALA_4 0x00000020
#define TMR2_PRESCALA_8 0x00000030
#define TMR2_PRESCALA_16 0x00000040
#define TMR2_PRESCALA_32 0x00000050
#define TMR2_PRESCALA_64 0x00000060
#define TMR2_PRESCALA_256 0x00000070
#define TMR2_EXTERNAL_CLK 0x00000002

/*Funciones para el timer 1*/
void Timer1_config(unsigned int config, unsigned int periodo);

void Timer1_cntrl(unsigned char on_off);

void Timer1_periodo(unsigned int periodo);

unsigned int Timer1_Read(void);

void Timer1_write(unsigned int valor);

unsigned char Timer1_test(void);



/*Funciones para el Timer 2*/
void Timer2_config(unsigned int config, unsigned int periodo);

void Timer2_cntrl(unsigned char on_off);

void Timer2_periodo(unsigned int periodo);

unsigned int Timer2_Read(void);

void Timer2_write(unsigned int valor);

unsigned char Timer2_test(void);
#endif	/* M_TIMERS_H */

