/* =================================================================================
Pemrogram      : Kelompok RE-2D/3
  1. 03 - Amin bagus Hari Saputro           NIM:4.34.23.3.03
  2. 10 - Habib Muhammad Zihni Miftah       NIM:4.34.23.3.10
  3. 15 - Muhammad Rafi Athallah            NIM:4.34.23.3.15
  4. 22 - Santo Nugroho                     NIM:4.34.23.3.22
Tgl.Praktikum  : Rabu, 20 November 2024
====================================================================================
P11 - Interrupt
  program untuk menggunakan pin interrupt
------------------------------------------------------------------------------------
Materi baru:
- Interrupt
------------------------------------------------------------------------------------
Komponen:
- LCD 16x2
==================================================================================*/

// I/O Registers definitions
#include <mega8535.h>
#include <delay.h>

// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here

// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void)
{
    lcd_gotoxy(0,1);                     
    lcd_putsf("INT0 = Any Change");
    delay_ms(2000);
}

// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void)
{
    lcd_clear();
    lcd_gotoxy(0,1);                     
    lcd_putsf("INT1 = FALLING   ");
    delay_ms(2000);
}

// External Interrupt 2 service routine
interrupt [EXT_INT2] void ext_int2_isr(void)
{
    lcd_clear();
    lcd_gotoxy(0,1);                     
    lcd_putsf("INT2 = RISING   ");
    delay_ms(2000);

}

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=P Bit2=P Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (1<<PORTB3) | (1<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=P Bit2=P Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (1<<PORTD3) | (1<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Any change
// INT1: On
// INT1 Mode: Falling Edge
// INT2: On
// INT2 Mode: Rising Edge
GICR|=(1<<INT1) | (1<<INT0) | (1<<INT2);
MCUCR=(1<<ISC11) | (0<<ISC10) | (0<<ISC01) | (1<<ISC00);  // untuk mengganti mode interupt
MCUCSR=(1<<ISC2);
GIFR=(1<<INTF1) | (1<<INTF0) | (1<<INTF2);

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS: PORTC Bit 0
// RD: PORTC Bit 1
// EN: PORTC Bit 2
// D4: PORTC Bit 3
// D5: PORTC Bit 4
// D6: PORTC Bit 5
// D7: PORTC Bit 6
// Characters/line: 16
lcd_init(16);

// Globally enable interrupts
#asm("sei")

while (1)
      {       
      lcd_clear();
      lcd_gotoxy(0,1);
      lcd_putsf("Coba EXT Interup");
      delay_ms(200);

      }
}
