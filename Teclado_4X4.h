/* 
 * File:   Teclado_4X4.h
 * Author: Juancho
 *
 * Created on 9 de mayo de 2018, 16:16
 */

#ifndef TECLADO_4X4_H
#define	TECLADO_4X4_H
#include "systemPIC32MX.h"


#define CN_PORTA 0
#define CN_PORTB 1

#define SI 1
#define NO 0

// definicion de los pines para las columnas del teclado
#define C0  LATAbits.LATA1
#define C1  LATAbits.LATA2
#define C2  LATAbits.LATA3
#define C3  LATAbits.LATA4

#define DIR_C0  TRISAbits.TRISA1
#define DIR_C1  TRISAbits.TRISA2
#define DIR_C2  TRISAbits.TRISA3
#define DIR_C3  TRISAbits.TRISA4

#define R0  PORTBbits.RB9
#define R1  PORTBbits.RB10
#define R2  PORTBbits.RB11
#define R3  PORTBbits.RB13

#define DIR_R0  TRISBbits.TRISB9
#define DIR_R1  TRISBbits.TRISB10
#define DIR_R2  TRISBbits.TRISB11
#define DIR_R3  TRISBbits.TRISB13


#define PULL_UP_R0(control) CNPUBbits.CNPUB9=control
#define PULL_UP_R1(control) CNPUBbits.CNPUB10=control
#define PULL_UP_R2(control) CNPUBbits.CNPUB11=control
#define PULL_UP_R3(control) CNPUBbits.CNPUB13=control


#if CN_PORTA && CN_PORTB    
    #define CN_ON() CNCONBbits.ON=1; CNCONAbits.ON=1
    #define Key_Read_Port() PORTA; PORTB
#elif CN_PORTB
    #define CN_ON() CNCONBbits.ON=1
    #define Key_Read_Port() PORTB
#elif CN_PORTA
    #define CN_ON() CNCONAbits.ON=1
    #define Key_Read_Port() PORTA
#else
    #define CN_ON()
    #define Key_Read_Port() 
#endif

#if CN_PORTA || CN_PORTB

    #define CN_R0() CNENBbits.CNIEB9=1
    #define CN_R1() CNENBbits.CNIEB10=1
    #define CN_R2() CNENBbits.CNIEB11=1
    #define CN_R3() CNENBbits.CNIEB13=1

#else

    #define CN_R0() 
    #define CN_R1() 
    #define CN_R2() 
    #define CN_R3() 

#endif



#define Key_col_config_out() DIR_C0=0; DIR_C1=0; DIR_C2=0; DIR_C3=0
#define Key_row_config_in() DIR_R0=1; DIR_R1=1; DIR_R2=1; DIR_R3=1
#define Key_use_pull_up(cntrl) PULL_UP_R0(cntrl); PULL_UP_R1(cntrl); PULL_UP_R2(cntrl); PULL_UP_R3(cntrl)
#define Key_clear_columns() C0=0; C1=0; C2=0; C3=0
#define Key_enable_cambio_estado() CN_ON(); CN_R0(); CN_R1(); CN_R2(); CN_R3()


void teclado_init(void);

unsigned char key_press(void);

unsigned char key_read(volatile unsigned char *tecla);



#endif	/* TECLADO_4X4_H */

