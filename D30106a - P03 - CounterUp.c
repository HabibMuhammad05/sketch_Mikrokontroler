/* =================================================================================
Pemrogram      : Kelompok RE-2D/3
  1. 03 - Amin bagus Hari Saputro           NIM:4.34.23.3.03
  2. 10 - Habib Muhammad Zihni Miftah       NIM:4.34.23.3.10
  3. 15 - Muhammad Rafi Athallah            NIM:4.34.23.3.15
  4. 22 - Santo Nugroho                     NIM:4.34.23.3.22
Tgl.Praktikum  : Rabu, 25 September 2024
====================================================================================
P03-Luaran Seven Segment Counter up
  program untuk menampilkan Penghitung(0-9999)
------------------------------------------------------------------------------------
Materi baru:

------------------------------------------------------------------------------------
Komponen:
- SevenSegment Display
- 8x R150
- Transistor
==================================================================================*/

#include <mega8535.h>
#include <delay.h>

char ribuan, ratusan, puluhan, satuan;
char nomorSatu[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
char posTampil[4] = { 0xFE, 0xFD, 0xFB, 0xF7}; 

void tampil(int bilangan)
{ 
        ribuan = bilangan/1000;
        ratusan = bilangan/100 % 10;  
        puluhan = bilangan/10 % 10;  
        satuan = bilangan % 10;
       
        PORTB = posTampil[0]; 
        PORTD = ~nomorSatu[ribuan];
        delay_ms(1);
        PORTB = posTampil[1]; 
        PORTD = ~nomorSatu[ratusan];
        delay_ms(1);
        PORTB = posTampil[2]; 
        PORTD = ~nomorSatu[puluhan];
        delay_ms(1);
        PORTB = posTampil[3]; 
        PORTD = ~nomorSatu[satuan];
        delay_ms(1);      
}

void main(void)
{       
    int cnt, j;
    DDRD = 0xFF;
    DDRB = 0xFF;
    
    while (1)
    {           
         for (cnt = 0; cnt < 10000; cnt++)
            {            
            for (j = 0; j < 100; j++)
                {  
                tampil(cnt); 
                }
            }
              
    }
}