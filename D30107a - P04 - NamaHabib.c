/* =================================================================================
Pemrogram      : Kelompok RE-2D/3
  1. 03 - Amin bagus Hari Saputro           NIM:4.34.23.3.03
  2. 10 - Habib Muhammad Zihni Miftah       NIM:4.34.23.3.10
  3. 15 - Muhammad Rafi Athallah            NIM:4.34.23.3.15
  4. 22 - Santo Nugroho                     NIM:4.34.23.3.22
Tgl.Praktikum  : Rabu, 2 Oktober 2024
====================================================================================
P04-Luaran Dot Matriks
  program untuk menampilkan Huruf Kelompok
------------------------------------------------------------------------------------
Materi baru:
- Dot Matriks
------------------------------------------------------------------------------------
Komponen:
- Dot Matrix Display
- 8x R150
- Transistor
==================================================================================*/

#include <mega8535.h>
#include <delay.h>

#include <mega8535.h>
char karakterC[7] ={ 0b00001111,
                     0b00011111,
                     0b00011000,
                     0b00011000,
                     0b00011000,
                     0b00011111,
                     0b00001111 };

char buatD[7] = {0b11111110, 
                 0b11111101,
                 0b11111011,
                 0b11110111,
                 0b11101111,
                 0b11011111,
                 0b10111111, }; 
                 
void main(void)
{   
    int i;
    DDRD = 0xFF;
    DDRB = 0xFF;
    while (1)
    {
        for (i = 0; i < 7; i++)
    	{
          PORTD = ~buatD[i];
          PORTB = ~karakterC[i]; 
          delay_ms(1);
        }  
    }
}
