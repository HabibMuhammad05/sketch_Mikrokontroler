/* =================================================================================
Pemrogram      : Kelompok RE-2D/3
  1. 03 - Amin bagus Hari Saputro           NIM:4.34.23.3.03
  2. 10 - Habib Muhammad Zihni Miftah       NIM:4.34.23.3.10
  3. 15 - Muhammad Rafi Athallah            NIM:4.34.23.3.15
  4. 22 - Santo Nugroho                     NIM:4.34.23.3.22
Tgl.Praktikum  : Rabu, 18 September 2024
====================================================================================
P02-Luaran- LED Berjalan
  program untuk menampilkan Led dengan efek berjalan.
------------------------------------------------------------------------------------
Materi baru:
- luaran digital
- jeda
------------------------------------------------------------------------------------
Komponen:
- 8x LED
- 8x R150
==================================================================================*/

#include <mega8535.h> 
#include <delay.h>

char posLed = 0x01;

void main(void)
{ 
  int i;
  DDRD = 0xFF;
    
while (1)
    {              
      PORTD = posLed; 
      for (i = 0; i < 8; i++)
          {                      
             delay_ms(1000);         
             posLed = posLed << 1;  
             PORTD = posLed; 
          }
    }
}
