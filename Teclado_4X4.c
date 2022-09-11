#include "Teclado_4X4.h"

void teclado_init(void)
{
    Key_col_config_out();
    Key_row_config_in();
    Key_use_pull_up(SI);
    Key_enable_cambio_estado();
    Key_clear_columns();
    Key_Read_Port();
}


unsigned char key_press(void)
{
    unsigned char tmp=0;
    Key_clear_columns();
    tmp=R3;
    tmp=(tmp<<1)|R2;
    tmp=(tmp<<1)|R1;
    tmp=(tmp<<1)|R0;
    if(tmp!=0x0F)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

unsigned char key_read(volatile unsigned char *tecla)
{
    unsigned char key=0xFF,tmp=0XFE,i=0;
    tmp=0XFE;
    for(i=0;i<4;i++)
    {                
        C0=tmp&1;
        C1=(tmp>>1)&1;
        C2=(tmp>>2)&1;
        C3=(tmp>>3)&1;
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        if(R0==0)
        {
            key=(i&3);
        }
        else if(R1==0)
        {
            key=(0x04)|(i&3);
        }
        else if(R2==0)
        {
            key=(0x08)|(i&3);
        }
        else if(R3==0)
        {
            key=(0x0c)|(i&3);
        }
        tmp=(tmp<<1)|1;        
    }                
    Key_clear_columns();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    if(key==0xFF)
    {
        *tecla=0;
        return 0;
    }
    else
    {
        *tecla=key;
        return 1;
    }
}