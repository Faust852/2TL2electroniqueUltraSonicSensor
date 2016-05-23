#include <18F458.h>
#device ADC=10
#use delay(crystal=20000000)
#use FIXED_IO( B_outputs=PIN_B7,PIN_B6 )
#use FIXED_IO( C_outputs=PIN_C6,PIN_C0 )
#define ledR PIN_B6
#define ledV PIN_B7
#define trig PIN_C0 
#define echo PIN_C1 

#use rs232(baud=9600, parity=N, xmit=PIN_C6, rcv=PIN_C7, stop=1, bits=8)

