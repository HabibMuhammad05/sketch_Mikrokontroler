/* =================================================================================
Pemrogram      : Kelompok RE-2D/3
  1. 03 - Amin bagus Hari Saputro           NIM:4.34.23.3.03
  2. 10 - Habib Muhammad Zihni Miftah       NIM:4.34.23.3.10
  3. 15 - Muhammad Rafi Athallah            NIM:4.34.23.3.15
  4. 22 - Santo Nugroho                     NIM:4.34.23.3.22
Tgl.Praktikum  : Rabu, 16 oktober 2024
====================================================================================
P06 - masukan tombol pembacaan toggle
  program untuk menyalakan tampilan LCD teks toggle dengan masukan tombol
------------------------------------------------------------------------------------
Materi baru:

------------------------------------------------------------------------------------
Komponen:
- 16x2 LCD Monokrom
- 3x Push Button
==================================================================================*/
#include <mega8535.h>
#include <delay.h>
#include <alcd.h>
#include <stdio.h>

#define sw1 PINA.0
 
int posisiNomor = 0;

void main(void) {    
    // Set PORTC sebagai input dan aktifkan pull-up resistor
    DDRA.0 = 0;                         // PA0 sebagai input
    DDRA.1 = 0;                         // PA1 sebagai input
    DDRA.2 = 0;                         // PA2 sebagai input
 
    PORTA.0 = 1;                        // Aktifkan pull-up untuk PA0
    PORTA.1 = 1;                        // Aktifkan pull-up untuk PA1
    PORTA.2 = 1;                        // Aktifkan pull-up untuk PA2
 
    // Inisialisasi LCD
    lcd_init(16);                       // Inisialisasi LCD 16 karakter
                                    
    lcd_puts("  Kel RE-2D/03  ");     
    //lcd_puts("   Pilihan : *  ");    
    lcd_puts("   nomor :****  ");
 
    while (1) 
    {                  
        if (sw1 == 0 && posisiNomor == 0) { // Jika tombol di PC0 ditekan
            lcd_gotoxy(10,1);
            lcd_puts("ON  ");           // Tampilkan "ON"  
            posisiNomor = 1;
            delay_ms(500);              // Delay untuk menghindari bouncing
        }     
        if (sw1 == 0 && posisiNomor == 1) { // Jika tombol di PC0 ditekan
            lcd_gotoxy(10,1);
            lcd_puts("OFF ");           // Tampilkan "OFF"  
            posisiNomor = 0;
            delay_ms(500);              // Delay untuk menghindari bouncing
        }   
 
    }
}