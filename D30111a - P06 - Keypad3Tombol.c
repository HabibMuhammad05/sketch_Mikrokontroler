/* =================================================================================
Pemrogram      : Kelompok RE-2D/3
  1. 03 - Amin bagus Hari Saputro           NIM:4.34.23.3.03
  2. 10 - Habib Muhammad Zihni Miftah       NIM:4.34.23.3.10
  3. 15 - Muhammad Rafi Athallah            NIM:4.34.23.3.15
  4. 22 - Santo Nugroho                     NIM:4.34.23.3.22
Tgl.Praktikum  : Rabu, 16 oktober 2024
====================================================================================
P06 - masukan tombol
  program untuk menyalakan tampilan LCD dengan masukan tombol
------------------------------------------------------------------------------------
Materi baru:

------------------------------------------------------------------------------------
Komponen:
- 16x2 LCD Monokrom
- 15x Push Button
==================================================================================*/
#include <mega8535.h>
#include <delay.h>
#include <alcd.h>
#include <stdio.h>

#define sw1 PINA.0
#define sw2 PINA.1
#define sw3 PINA.2
 

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
 
    while (1) {      
                                               
        if (!sw1) {                     //Jika tombol di PA0 ditekan
            lcd_gotoxy(10,1);     
            lcd_puts("tmbl ");          // Tampilkan "tmbl"  
            lcd_puts("1");              // Tampilkan "1"  
            delay_ms(500);              // Delay untuk menghindari bouncing
        }     
        if (sw2 == 0) {                 // Jika tombol di PA1 ditekan
            lcd_gotoxy(10,1);   
            lcd_puts("tmbl ");          // Tampilkan "1"  
            lcd_puts("2");              // Tampilkan "2" 
            delay_ms(500);              // Delay untuk menghindari bouncing
        }
        if (PINA.2 == 0) {              // Jika tombol di PA2 ditekan
            lcd_gotoxy(10,1);
            lcd_puts("tmbl ");          // Tampilkan "1"  
            lcd_puts("3");              // Tampilkan "3"  
            delay_ms(500);              // Delay untuk menghindari bouncing
        }   
 
    }
}