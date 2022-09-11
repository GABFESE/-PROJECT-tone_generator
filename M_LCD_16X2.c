#include "M_LCD_16X2.h"

void LCD_init(void)
{
    DIR_RS=0;
    DIR_E=0;
    DIR_D0=0;
    DIR_D1=0;
    DIR_D2=0;
    DIR_D3=0;
    
    RS=0;
    E=0;
    D0=0;
    D1=0;
    D2=0;
    D3=0;
    delay_ms(15);
    
    LCD_cmd4(0x30);
    delay_ms(5);
    LCD_cmd4(0x30);
    delay_us(200);
    LCD_cmd4(0x30);
    delay_us(200);
    LCD_cmd4(0x20);
    LCD_cmd(0x28);
    LCD_cmd(0x0f);
    LCD_cmd(0x06);
    LCD_cmd(0x01);
    delay_ms(2);
}

static void LCD_cmd4(unsigned char cmd)
{
    RS=0;
    D0=(cmd>>4)&1;
    D1=(cmd>>5)&1;
    D2=(cmd>>6)&1;
    D3=(cmd>>7)&1;
    Nop();
    Nop();
    E=1;
    delay_us(1);
    E=0;
    delay_us(50);
}

static void LCD_cmd(unsigned char cmd)
{
    RS=0;
    D0=(cmd>>4)&1;
    D1=(cmd>>5)&1;
    D2=(cmd>>6)&1;
    D3=(cmd>>7)&1;
    Nop();
    Nop();
    E=1;
    delay_us(1);
    E=0;
    Nop();
    Nop();
    D0=(cmd)&1;
    D1=(cmd>>1)&1;
    D2=(cmd>>2)&1;
    D3=(cmd>>3)&1;
    Nop();
    Nop();
    E=1;
    delay_us(1);
    E=0;
    delay_us(50);
}

static void LCD_data(unsigned char dato)
{
    RS=1;
    D0=(dato>>4)&1;
    D1=(dato>>5)&1;
    D2=(dato>>6)&1;
    D3=(dato>>7)&1;
    Nop();
    Nop();
    E=1;
    delay_us(1);
    E=0;
    Nop();
    Nop();
    D0=(dato)&1;
    D1=(dato>>1)&1;
    D2=(dato>>2)&1;
    D3=(dato>>3)&1;
    Nop();
    Nop();
    E=1;
    delay_us(1);
    E=0;
    delay_us(50);
    RS=0;
}

void LCD_puts(unsigned char *msg)
{
    while(*(msg)!='\0')
    {
        LCD_data(*(msg++));
    }
}

void LCD_putc(unsigned char caracter)
{
    LCD_data(caracter);
}


void lcd_xy(unsigned char x, unsigned char y)
{
    unsigned char tmp=0;
    tmp=x|0x80;
    if(y!=0)
    {
        tmp|=0x40;
    }
    LCD_cmd(tmp);
}

void lcd_clrscr(void)
{
    LCD_cmd(0x01);
    delay_ms(2);
}

void nombre_tonos(void)
{
    lcd_xy(3,0);
    LCD_puts((unsigned char *)"GEN  TONOS\0");
    
    lcd_xy(0,1);
    LCD_puts(((unsigned char *)"1-H Birthday       "));
    delay_ms(1000);
    
    lcd_xy(0,1);
    LCD_puts(((unsigned char *)"2-The Simpsons       "));
    delay_ms(1000);
    
    lcd_xy(0,1);
    LCD_puts(((unsigned char *)"3-M Impossible       "));
    delay_ms(1000);
    
    lcd_xy(0,1);
    LCD_puts(((unsigned char *)"4-Star Wars       "));
    delay_ms(1000);
    
    lcd_xy(0,1);
    LCD_puts(((unsigned char *)"5-SW Imperial March       "));
    delay_ms(1000);
    
    lcd_xy(0,1);
    LCD_puts(((unsigned char *)"6-Super Mario       "));
    delay_ms(1000);
    
    lcd_xy(0,1);
    LCD_puts(((unsigned char *)"ingrese un valor"));
}