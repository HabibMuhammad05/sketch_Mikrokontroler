/* =================================================================================
Pemrogram      : Kelompok RE-2D/3
  1. 03 - Amin bagus Hari Saputro           NIM:4.34.23.3.03
  2. 10 - Habib Muhammad Zihni Miftah       NIM:4.34.23.3.10
  3. 15 - Muhammad Rafi Athallah            NIM:4.34.23.3.15
  4. 22 - Santo Nugroho                     NIM:4.34.23.3.22
Tgl.Praktikum  : Rabu, 2 Oktober 2024
====================================================================================
P04-Luaran Dot Matriks
  program untuk menampilkan Nama "HABIB"
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

char buatD[7] = {0b11111110, 
                 0b11111101,
                 0b11111011,
                 0b11110111,
                 0b11101111,
                 0b11011111,
                 0b10111111, }; 
                 

char charH[] = { 0b00010001,
                 0b00010001,
                 0b00010001,
                 0b00001111,
                 0b00010001,
                 0b00010001,
                 0b00010001 };    
                 
char charA[] = { 0b00000100,
                 0b00001010,
                 0b00010001,
                 0b00011111,
                 0b00010001,
                 0b00010001,
                 0b00010001 };
                 
char charB[] = { 0b00011110,
                 0b00010001,
                 0b00010001,
                 0b00011110,
                 0b00010001,
                 0b00010001,
                 0b00011110 }; 
                 
char charI[] = { 0b00001110,
                 0b00000100,
                 0b00000100,
                 0b00000100,
                 0b00000100,
                 0b00000100,
                 0b00001110 };


void tampilData(char buatB[])
{   
    int i;
    for (i = 0; i < 7; i++)
    {
        PORTD = ~buatD[i];
        PORTB = ~buatB[i]; 
        delay_ms(1);
     }  
}
                 
void main(void)
{   
    int j;
    DDRD = 0xFF;
    DDRB = 0xFF;
    while (1)
    {
        for (j = 0; j < 100; j++)
        {
            tampilData(charH);
        }                   
        
        for (j = 0; j < 100; j++)
        {
            tampilData(charA);
        }   
         
        for (j = 0; j < 100; j++)
        {
            tampilData(charB);
        }   
        for (j = 0; j < 100; j++)
        {
            tampilData(charI);
        }   
        for (j = 0; j < 100; j++)
        {
            tampilData(charB);
        }    
    }
}
