David
main.c
Last week
Atom Zycreated and shared an item in
Thu. 7:10 pm
Google Drive Folder
ProjetCodeC (1)
Created items:
C
main.c
Can edit
You
Can edit
François Marchal
Can edit
Nekrozys Ravenheart
No recorded activity before 19 May 2016

#include "main.h"
#include "LCD420.c"

float distance;
float tempDistance;
float time;
float limite = 400;

/*#INT_RDA
void rs232_kesme() 
{ 
   disable_interrupts(int_rda); 
   limite=getc();  
}*/
void main()
{ 
   delay_ms(100);                              // Boot-up delay, for troubleshooting 

   setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);     // initiating timer
   setup_low_volt_detect(FALSE);
    enable_interrupts(INT_TIMER1);
   enable_interrupts(INT_EXT);
   
   enable_interrupts(GLOBAL);
   
   lcd_init();
   delay_ms(500);
   lcd_gotoxy(1,1);
   lcd_putc("  Culem Adrien");
   delay_ms(500);
   lcd_putc('\f');
   lcd_putc("  Marchal Francois");
   delay_ms(500);
   lcd_putc('\f');
   lcd_putc("  Micciche David");
   delay_ms(500);
   lcd_putc('\f');
   lcd_putc("  Massart Florian");
   delay_ms(500);
   
   while(TRUE)
   {
      enable_interrupts(INT_RDA);
      tempDistance = distance;
      //tempLimite = limite;
      
      output_high(trig);                         // ping the sonar 
      delay_ms(20);                            // sending 20us pulse 
      output_low(trig); 
      
      while(!input(echo))                       // wait for high state of echo pin 
      {} 
      
      set_timer1(0);                           // setting timer zero 
      
      while(input(echo))                       // Wait for high state of echo pin 
      {}
      
      time=get_timer1();                       // Getting the time 
      
      distance=time*0.028 + 1.093 ; // Calculating the distance
      
      //distance = (time/2)/29.1;
      //limite = getc();
      //limite = fgetc();
      if(distance < limite){
        output_high(ledV);
        output_low(ledR);
      } else{
        output_low(ledV);
        output_high(ledR);
        delay_ms(100);
        output_low(ledR);
      }
      
      lcd_putc('\f');
      lcd_gotoxy(1,1);
      printf(LCD_PUTC, " Distance = %f",distance);
      printf(LCD_PUTC, " \n  Limite = %f", limite);
      if(tempDistance != distance){
         printf("%f\n", distance);
      }
      delay_ms(750);
   } 

}

