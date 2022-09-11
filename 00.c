#include "SystemPIC32MX.h"
#include <stdio.h>
#include "delay.h"
#include "M_Timers.h"
#include "Teclado_4X4.h"
#include "M_LCD_16X2.h"

const unsigned int tiempos[6][100]={{16,32,32,32,8,32,8,32,8,32,40,16,16,32,32,32,8,32,8,32,8,32,4,8,16,32,32,32,8,32,8,32,8,32,8,32,8,32,16,32,32,32,8,32,8,32,8,32,4,40,40},	//51 tiempos Happy birthday
                                    {4,4,4,8,4,4,4,8,8,8,8,2,4,8,8,8,8,4,8,8,8,4,40,40},    //24 the simpsons
                                    {16,8,16,8,16,16,16,16,16,8,16,8,16,16,16,16,16,8,16,8,16,16,16,16,16,8,16,8,16,16,16,16,16,16,2,32,16,16,2,32,16,16,2,16,16,16,40,40},     //48 Mission Impossible
                                    {8,8,16,2,2,8,16,8,2,4,8,16,8,2,4,8,16,8,2,8,8,16,2,2,8,16,8,2,4,8,16,8,2,4,8,16,8,2,4,16,2,8,8,8,8,8,16,8,16,4,4,4},     //52 Star Wars
                                    {4,4,4,4,16,4,4,16,2,4,4,4,4,16,4,4,16,2,4,4,16,4,4,16,16,16,4,8,4,4,16,16,16,4,8,4,4,16,4,4,16,2,4,4,16,4,4,16,16,16,40,40},       //52Imperial March
                                    {12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,9,9,9,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,9,9,9,12,12,12,12,12,12,12,12,12,12,12,12,40,40}};    //80Mario Bross

const unsigned int notas[6][100]={{262,1,262,1,294,1,262,1,349,1,329,1,262,1,262,1,294,1,262,1,392,1,349,1,262,1,262,1,523,1,440,1,349,1,330,1,294,1,466,1,466,1,440,1,349,1,392,1,349,1,1}, //51 notas Happy birthday
                                 {523,659,740,880,784,659,523,440,370,370,370,340,1,370,370,370,392,466,523,523,523,523,1,1},        //24 notas The Simpsons
                                 {784,1,784,1,698,1,740,1,784,1,784,1,932,1,1047,1,784,1,784,1,698,1,740,1,784,1,784,1,932,1,1047,1,932,784,587,1,932,784,554,1,932,784,523,1,466,523,1,1},  //48 notas Mission Impossible
                                 {277,277,277,370,554,494,466,415,740,554,494,466,415,740,554,494,466,494,415,277,277,277,370,554,494,466,391,740,554,494,466,415,740,554,494,466,494,415,277,277,311,554,494,466,415,370,370,415,466,415,1,1},  //52 Star Wars 
                                 {440,440,440,349,523,440,349,523,440,659,659,659,698,523,415,349,523,440,440,440,440,880,831,784,740,698,740,466,622,587,554,523,494,523,349,415,349,415,523,440,523,659,880,440,440,880,831,784,740,698,1,1},
                                 {2637,2637,1,2637,1,2093,2637,1,3136,1,1,1,1568,1,1,1,2093,1,1,1568,1,1,1319,1,1,1760,1,1976,1,1865,1760,1,1568,2637,3136,3520,1,2784,3136,1,2637,1,2093,2349,3951,1,1,2093,1,1,1566,1,1,1319,1,1,1760,1,1976,1,1865,1760,1,1568,2637,3136,3520,1,2794,3136,1,2637,1,2093,2349,1976,1,1,1,1}};     //80Mario Bross

typedef struct{
    unsigned Teclado:1;
}soft_flags;

volatile unsigned char bandera_tiempo=0x0, tecla_key=0;
volatile soft_flags banderas;
unsigned char msg[20];
const unsigned char Key_deco[16]={1,2,3,10,4,5,6,11,7,8,9,12,13,0,14,15};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void __ISR(_TIMER_1_VECTOR,IPL7SOFT) Timer_tiempos(void){
    bandera_tiempo=1;
    IFS0bits.T1IF=0;
}

void __ISR(_TIMER_2_VECTOR,IPL7SOFT) Timer_notas(void){
    LATAINV=0X00000001;     // EN EL PIN #0 GENERA UN TOOGLE
    IFS0bits.T2IF=0;
}

void __ISR(_CHANGE_NOTICE_VECTOR,IPL6SOFT) Change_Notice(void){
    if(IFS1bits.CNAIF==1 || IFS1bits.CNBIF==1){
        delay_us(100);
        if(key_press()){
           banderas.Teclado=key_read(&tecla_key);      
        }  
        Key_Read_Port();
        IFS1bits.CNAIF=0;
        IFS1bits.CNBIF=0;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(void){
    ANSELA=0;
    ANSELB=0;
    float periodof, frecuenciaf, tiempof;
    unsigned int periodo=1, frecuencia=247, tiempo=0, tiempotemp, x=0, y=0, c=0, t=0;
    unsigned char cnt1=0, selector=1, in=0;
    unsigned char vect[10];
    unsigned char Tecla=0;
        
    bandera_tiempo=0x1;
    
    teclado_init();
    LCD_init();
    nombre_tonos();
    
    __builtin_disable_interrupts(); 
    Timer1_config(TMR1_PRESCALA_256,39062-1);
    Timer1_cntrl(0);
    INTCONbits.MVEC=1;
    IPC1bits.T1IP=7;
    IPC1bits.T1IS=1;
    IFS0bits.T1IF=0;
    IEC0bits.T1IE=1;
    
    Timer2_config(TMR2_PRESCALA_256,39062-1);
    Timer2_cntrl(0);
    INTCONbits.MVEC=1;
    IPC2bits.T2IP=7;
    IPC2bits.T2IS=1;
    IFS0bits.T2IF=0;
    IEC0bits.T2IE=1;
    
    IPC8bits.CNIP=6;
    IPC8bits.CNIS=1;
    IFS1bits.CNBIF=0;
    IEC1bits.CNBIE=1;
    __builtin_enable_interrupts();
    
    TRISAbits.TRISA0=0; //poner salida el pin A0   

    while(1){
        if(banderas.Teclado==1){ // SI SE PRECIONO UNA TECLA...
            banderas.Teclado=0;
            Tecla=Key_deco[tecla_key];
            if(Tecla>=0 && Tecla<10){    // SI LA TECLA ES >=0 0 <10
                vect[cnt1]=Tecla+48;    // SE LLENA UN VECTOR CON EL RESPECTIVO VALOR DE ASSCI
                cnt1++;
            }
            if(Tecla==15&&cnt1!=0){
                vect[cnt1]='\0';
                cnt1=0;
                selector=atoi(vect);
                x=0;
                switch(selector){
                    case 1: 
                        lcd_xy(0,1);
                        LCD_puts(((unsigned char *)"1-H Birthday       "));
                        y=0;
                        c=50;
                        t=125.0;
                        in=1;
                    break;
                    case 2: 
                        lcd_xy(0,1);
                        LCD_puts(((unsigned char *)"2-The Simpsons       "));
                        y=1;
                        c=23;
                        t=160.0;
                        in=1;
                    break;
                    case 3: 
                        lcd_xy(0,1);
                        LCD_puts(((unsigned char *)"3-M Impossible       "));
                        y=2;
                        c=47;
                        t=100.0;
                        in=1;
                    break;
                    case 4: 
                        lcd_xy(0,1);
                        LCD_puts(((unsigned char *)"4-Star Wars       "));
                        y=3;
                        c=51;
                        t=100.0;
                        in=1;
                    break;
                    case 5: 
                        lcd_xy(0,1);
                        LCD_puts(((unsigned char *)"5-SW Imperial March       "));
                        y=4;
                        c=51;
                        t=112.0;
                        in=1;
                    break;
                    case 6: 
                        lcd_xy(0,1);
                        LCD_puts(((unsigned char *)"6-Super Mario       "));
                        y=5;
                        c=79;
                        t=120.0;
                        in=1;
                    break;
                    default:
                        lcd_xy(0,1);
                        LCD_puts(((unsigned char *)" valor invalido "));
                        Timer1_cntrl(0);
                        Timer2_cntrl(0);
                        x=0;
                }
             }
            else if(Tecla==10){  // tecla A o el 15 
                Timer1_cntrl(0);
                Timer2_cntrl(0);    
                x=0;
                lcd_xy(0,1);
                LCD_puts(((unsigned char *)"                    \0"));
                lcd_xy(5,1);
                LCD_puts(((unsigned char *)"STOP\0"));
            }
            else if(Tecla==11){  // tecla B o el 15
                Timer1_cntrl(0);
                Timer2_cntrl(0);
                lcd_xy(0,1);
                LCD_puts(((unsigned char *)"                    \0"));
                lcd_xy(5,1);
                LCD_puts(((unsigned char *)"PAUSE\0"));
            }
            else if(Tecla==12){  // tecla c o el 15
                Timer1_cntrl(1);
                Timer2_cntrl(1);
                lcd_xy(0,1);
                LCD_puts(((unsigned char *)"                    \0"));
                lcd_xy(5,1);
                LCD_puts(((unsigned char *)"PLAY\0"));
            }
        }
                
        if(bandera_tiempo==1 && in==1){
            bandera_tiempo=0;
            tiempo=(tiempos[y][x]);
            tiempof=1.0/(240.0/(t*((float)tiempo)));
            tiempotemp = (int)tiempof;
            periodof = SYSCLK*tiempotemp/(512);  // valor que se ingresa como periodo al timer
            periodo = (int)periodof;
            Timer1_cntrl(0);    // apaga el timer
            Timer1_write(0);    // reinicia el timer   
            Timer1_periodo(periodo-1);  // ingresa el nuevo periodo
            Timer1_cntrl(1);    // inicia el timer

            frecuencia=(notas[y][x]);
            if(frecuencia == 1){
                Timer2_cntrl(0);
            }
            else{
                periodo=SYSCLK/(256*2*frecuencia);  // valor que se ingresa como periodo al timer
                Timer2_cntrl(0);    // apaga el timer
                Timer2_write(0);    // reinicia el timer   
                Timer2_periodo(periodo-1);  // ingresa el nuevo periodo
                Timer2_cntrl(1);    // inicia el timer
            }
            x = (x<c) ? x+1 : 0;
        }
    }
}
