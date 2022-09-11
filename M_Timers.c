#include "M_Timers.h"


/*Funciones para el timer 1*/
void Timer1_config(unsigned int config, unsigned int periodo)
{
    T1CON=config;
    Timer1_periodo(periodo);
    Timer1_write(0);
}

void Timer1_cntrl(unsigned char on_off)
{
    T1CONbits.ON=(on_off&1);
}

void Timer1_periodo(unsigned int periodo)
{
    PR1=periodo;
}

unsigned int Timer1_Read(void)
{
    return TMR1;
}

void Timer1_write(unsigned int valor)
{
    TMR1=valor;
}

unsigned char Timer1_test(void)
{
    if(IFS0bits.T1IF==1)
    {
        IFS0bits.T1IF=0;
        return 1;
    }
    else
    {
        return 0;
    }
}



/*Funciones para el Timer 2*/
void Timer2_config(unsigned int config, unsigned int periodo)
{
    T2CON=config;
    Timer2_periodo(periodo);
    Timer2_write(0);
}

void Timer2_cntrl(unsigned char on_off)
{
    T2CONbits.ON=(on_off&1);
}

void Timer2_periodo(unsigned int periodo)
{
    PR2=periodo;
}

unsigned int Timer2_Read(void)
{
    return TMR2;
}

void Timer2_write(unsigned int valor)
{
    TMR2=valor;
}

unsigned char Timer2_test(void)
{
    if(IFS0bits.T2IF==1)
    {
        IFS0bits.T2IF=0;
        return 1;
    }
    else
    {
        return 0;
    }
}
