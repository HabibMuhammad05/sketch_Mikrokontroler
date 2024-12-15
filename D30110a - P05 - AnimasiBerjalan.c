/* =================================================================================
Pemrogram      : Kelompok RE-2D/3
  1. 03 - Amin bagus Hari Saputro           NIM:4.34.23.3.03
  2. 10 - Habib Muhammad Zihni Miftah       NIM:4.34.23.3.10
  3. 15 - Muhammad Rafi Athallah            NIM:4.34.23.3.15
  4. 22 - Santo Nugroho                     NIM:4.34.23.3.22
Tgl.Praktikum  : Rabu, 9 Oktober 2024
====================================================================================
P05-Luaran Seven Segment
  program untuk menampilkan karakter kustom dengan efek berjalan
------------------------------------------------------------------------------------
Materi baru:
- LCD pembuatan karakter kustom
------------------------------------------------------------------------------------
Komponen:
- LCD Display
==================================================================================*/

#include <mega8535.h>
#include <delay.h>
#include <alcd.h>

flash unsigned char c1[8] = {     0b00000,
                                  0b00000,
                                  0b00000,
                                  0b00100,
                                  0b01110,
                                  0b10101,
                                  0b00100,
                                  0b00100 };
                                      
flash unsigned char c2[8] = {     0b00000,
                                  0b00000,
                                  0b00100,
                                  0b01110,
                                  0b10101,
                                  0b00100,
                                  0b00100,
                                  0b00100 };   
                                      
flash unsigned char c3[8] = {     0b00000,
                                  0b00100,
                                  0b01110,
                                  0b10101,
                                  0b00100,
                                  0b00100,
                                  0b00100,
                                  0b00100 }; 
                                                                   
flash unsigned char c4[8] = {     0b00100,
                                  0b01110,
                                  0b10101,
                                  0b00100,
                                  0b00100,
                                  0b00100,
                                  0b00100,
                                  0b00100 };
                                   
void buatKarakter (unsigned char flash *pc, unsigned char char_kode)
{
    unsigned char i, alamat;
    
    alamat = char_kode << 3 | 0x40;
    
    for (i = 0; i < 8; i++)
        {
            lcd_write_byte(alamat++, *pc++);
        }
}


void main(void)
{
    int i;
    lcd_init(16);
    buatKarakter(c1, 0);        
    buatKarakter(c2, 9);
    buatKarakter(c3, 2);
    buatKarakter(c4, 3);
    while (1)
    {            
        lcd_clear();
        delay_ms(1000); 
        lcd_gotoxy(0, 0);
        lcd_putchar(0);
         
        lcd_clear();
        lcd_putchar(9); 
        delay_ms(1000);   
        
        lcd_clear();
        lcd_putchar(2); 
        delay_ms(1000);  
        
        lcd_clear();
        lcd_putchar(3); 
        delay_ms(1000);

    }
}
