/* =================================================================================
Pemrogram      : Kelompok RE-2D/3
  1. 03 - Amin bagus Hari Saputro           NIM:4.34.23.3.03
  2. 10 - Habib Muhammad Zihni Miftah       NIM:4.34.23.3.10
  3. 15 - Muhammad Rafi Athallah            NIM:4.34.23.3.15
  4. 22 - Santo Nugroho                     NIM:4.34.23.3.22
Tgl.Praktikum  : Rabu, 18 September 2024
====================================================================================
P02-Luaran- LED Absen
  program untuk menampilkan Biner Led sesuai dengan absen 
------------------------------------------------------------------------------------
Materi baru:
- luaran digital
------------------------------------------------------------------------------------
Komponen:
- 8x LED
- 8x R150
==================================================================================*/

#include <mega8535.h> 

char absen10 = 00001010;

void main(void)
{ 
  PORTD = 0xFF;
    
while (1)
    {    
      DDRD = absen10;
    }
}
