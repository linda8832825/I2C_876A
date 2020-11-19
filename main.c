//#include <xc.h>
#include <htc.h>
#include "I2C_LCD.h"
// CONFIG
#pragma config FOSC = HS        // ¿ï¾Ühs ¥~³¡¾_Àú
void Delay(unsigned int counter);
void write(void);
void main(void) {
    TRISB0=0;
    I2C_Master_Init();
    LCD_Init(0x4E); // Initialize LCD module with I2C address = 01001110
    write();
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
    LCD_Write_String(" iiiiiiiiiiii");
    LCD_Set_Cursor(2, 1);
    LCD_Write_String(" 222222222222"); 
    LCD_Set_Cursor(3, 1);
    LCD_Write_String(" cccccccccc"); 
    LCD_Set_Cursor(4, 1);
    LCD_Write_String(" :)))))))))))))))"); 
}
void Delay(unsigned int counter)
{
  while(counter>0) counter--;  
}  