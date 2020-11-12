#include <xc.h>
#include <htc.h>
#include "I2C_LCD.h"
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
void Delay(unsigned int counter);
void write(void);
void write2(void);
void main(void) {
    TRISB0=0;
    I2C_Master_Init();
    LCD_Init(0x4E); // Initialize LCD module with I2C address = 01001110
    write();
    write2();
    while(1){
        RB0=1;
        Delay(50000);
        RB0=0;
        Delay(50000);
    }
  return;
}
void write(void)
{
    LCD_Set_Cursor(1, 1);
    LCD_Write_String(" Khaled Magdy");
    LCD_Set_Cursor(2, 1);
    LCD_Write_String(" DeepBlue"); 
    LCD_Set_Cursor(3, 1);
    LCD_Write_String(" 123"); 
}
void write2(void)
{
    LCD_Set_Cursor(1, 1);
    LCD_Write_String(" Khaled Magdy");
    LCD_Set_Cursor(2, 1);
    LCD_Write_String(" DeepBlue"); 
    LCD_Set_Cursor(3, 1);
    LCD_Write_String(" 456"); 
}
void Delay(unsigned int counter)
{
  while(counter>0) counter--;  
}  