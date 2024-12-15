/* =================================================================================
Pemrogram      : Kelompok RE-2D/3
  1. 03 - Amin bagus Hari Saputro           NIM:4.34.23.3.03
  2. 10 - Habib Muhammad Zihni Miftah       NIM:4.34.23.3.10
  3. 15 - Muhammad Rafi Athallah            NIM:4.34.23.3.15
  4. 22 - Santo Nugroho                     NIM:4.34.23.3.22
Tgl.Praktikum  : Rabu, 25 September 2024
====================================================================================
P03-Luaran Seven Segment
  program untuk menampilkan Angka Kelompok pada seven segment
------------------------------------------------------------------------------------
Materi baru:
- Seven Segment
------------------------------------------------------------------------------------
Komponen:
- SevenSegment Display
- 8x R150
- Transistor
==================================================================================*/

#include <mega8535.h>
#include <delay.h>

char angkaArr[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
char posTampil[4] = { 0xFE, 0xFD, 0xFB, 0xF7}; 

void main(void)
{       
    DDRD = 0xFF;
    DDRB = 0xFF;
    
    while (1)
    {          
        PORTB = posTampil[3]; 
        PORTD = ~angkaArr[3]; 
    }
}