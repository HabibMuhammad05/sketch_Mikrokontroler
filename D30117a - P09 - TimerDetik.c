/* =================================================================================
Pemrogram      : Kelompok RE-2D/3
  1. 03 - Amin bagus Hari Saputro           NIM:4.34.23.3.03
  2. 10 - Habib Muhammad Zihni Miftah       NIM:4.34.23.3.10
  3. 15 - Muhammad Rafi Athallah            NIM:4.34.23.3.15
  4. 22 - Santo Nugroho                     NIM:4.34.23.3.22
Tgl.Praktikum  : Rabu, 6 November 2024
====================================================================================
P09 - Internal TImer
  program untuk toggle LED setiap detik berdasarkan Timer internal.
------------------------------------------------------------------------------------
Materi baru:
- Timer Internal
------------------------------------------------------------------------------------
Komponen:
- 8x LED
- 8x Resistor
==================================================================================*/

#include <mega8535.h>

void main(void)
{
DDRD = 0XFF;
while (1)
    {
    TCNT1 = 3035;                       // NILAI AWAL UNTUK MENCAPAI OVERFLOW DALAM WAKTU 1 DETIK 
                                        // 65535 - 62500 = 3035
                                        // 65535-->NILAI MAKSIMAL TCNT1 (16 BIT), 62500--> JUMLAH PULSA YANG DIBUTUHKAN UNTUK MENCAPAI OVERFLOW UNTUK MEMBUAT TIMER 1 DETIK
                                        // XTAL YANG DIPAKAI 16 MHz, DENGAN PRESCALLER (PEMBAGI FREKUENSI XSTAL) 256 
    
    TCCR1B = 0b100;                     // pemilihan prescaller di 256 dan timer mulai menghitung (timer start)
    while ((TIFR & 0b00000100) == 0);   // menunggu sampai TCNT1 overflow ditandai dengsn register TIFR pada bit TOV1 bernilai 1
    TCCR1B = 0;                         // TIMER 1 STOP
    TIFR   = 0b00000100;                // RESET NILAI TOV1 MENJADI 0
    
    PORTD = ~PORTD;
    
      

    }
}
