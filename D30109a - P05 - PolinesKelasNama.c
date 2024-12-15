/* =================================================================================
Pemrogram      : Kelompok RE-2D/3
  1. 03 - Amin bagus Hari Saputro           NIM:4.34.23.3.03
  2. 10 - Habib Muhammad Zihni Miftah       NIM:4.34.23.3.10
  3. 15 - Muhammad Rafi Athallah            NIM:4.34.23.3.15
  4. 22 - Santo Nugroho                     NIM:4.34.23.3.22
Tgl.Praktikum  : Rabu, 9 Oktober 2024
====================================================================================
P05-Luaran LCD
  program untuk menampilkan tulisan Polines-Kelas-Nama pada LCD
------------------------------------------------------------------------------------
Materi baru:
- LCD display
------------------------------------------------------------------------------------
Komponen:
- LCD Display
==================================================================================*/

#include <mega8535.h>
#include <alcd.h>
#include <delay.h>
#include <stdio.h>

void main(void)
{
    int i;
    lcd_init(16);
    lcd_clear();
    lcd_gotoxy(1,0);
    lcd_putsf("POLINES-RE2D"); 
    lcd_gotoxy(5,1);
    lcd_putsf("HABIB");

    while (1)
    {
    }
}
