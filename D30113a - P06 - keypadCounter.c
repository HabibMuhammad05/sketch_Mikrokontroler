/* =================================================================================
Pemrogram      : Kelompok RE-2D/3
  1. 03 - Amin bagus Hari Saputro           NIM:4.34.23.3.03
  2. 10 - Habib Muhammad Zihni Miftah       NIM:4.34.23.3.10
  3. 15 - Muhammad Rafi Athallah            NIM:4.34.23.3.15
  4. 22 - Santo Nugroho                     NIM:4.34.23.3.22
Tgl.Praktikum  : Rabu, 16 oktober 2024
====================================================================================
P06 - masukan tombol penghitung 
  program untuk menyalakan tampilan LCD penghitung angka dengan masukan tombol
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

#define sw1  PINA.0
#define sw2  PINA.1
#define sw3  PINA.2
 
int posisiNomor = 0;
char buffer[4];
 
void tampilAngka(){
    lcd_gotoxy(10,1);               
    sprintf(buffer, "%4d", posisiNomor); 
    lcd_puts(buffer);                     // Tampilkan isi variabel buffer 
    //delay_ms(500);                      // Delay untuk menghindari bouncing
}


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
    lcd_puts("   nilai :****  ");
 
    while (1) {      
        if (sw1 == 0) {                //Jika tombol di PA0 ditekan 
            while (sw1 == 0)
            {
                delay_ms(100);
            } 
            posisiNomor++;                //jalankan fungsi tampilAngka
            tampilAngka();
        }     
        if (sw2 == 0) {                // Jika tombol di PA1 ditekan
            while (sw2 == 0)
            {
                delay_ms(100);
            } 
            posisiNomor--;                //jalankan fungsi tampilAngka
            tampilAngka();
        }
        if (sw3 == 0) {                // Jika tombol di PA2 ditekan 
            while (sw3 == 0)
            {
                delay_ms(100);
            } 
            posisiNomor = 0;              //jalankan fungsi tampilAngka
            tampilAngka();
        }   
 
    }
}