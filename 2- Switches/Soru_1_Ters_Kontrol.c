//    Anahtarlar�n ve Ledlerin kullan�m�.  //
//        MikroC v6.2 - STM32F407VG        //
// ARMapp-18 Deney Seti i�in yaz�lm��t�r   //
// Ledlerin anahtarlar 0 konumuna al�nd���nda yanmas�n� sa�lay�n�z.//

void main()                                           // Ana Program Blo�u
{
 GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_0|    // 'E' Portunun 0-7. pinleri dijital
                                  _GPIO_PINMASK_1|    //  ��k�� olarak ayarlan�yor.
                                  _GPIO_PINMASK_2|
                                  _GPIO_PINMASK_3|
                                  _GPIO_PINMASK_4|
                                  _GPIO_PINMASK_5|
                                  _GPIO_PINMASK_6|
                                  _GPIO_PINMASK_7);

 GPIO_Digital_Input(&GPIOE_BASE, _GPIO_PINMASK_13|   // 'E' Portunun 13,14 ve 15. pinleri dijital
                                 _GPIO_PINMASK_14|   //  giri� olarak ayarlan�yor.
                                 _GPIO_PINMASK_15);

 GPIO_Digital_Input(&GPIOB_BASE, _GPIO_PINMASK_15);  // 'B' Portunun 15. pini dijital
                                                     // giri� olarak ayarlan�yor.

 GPIO_Digital_Input(&GPIOC_BASE, _GPIO_PINMASK_8 );  // 'C' Portunun 8. pini dijital
                                                     // giri� olarak ayarlan�yor.
 
 GPIO_Digital_Input(&GPIOD_BASE, _GPIO_PINMASK_9 |   // 'D' Portunun 9,10 ve 11. pinleri dijital
                                 _GPIO_PINMASK_10|   // giri� olarak ayarlan�yor.
                                 _GPIO_PINMASK_11);
                                 
 while(1)                                            // Sonsuz d�ng�
    {
     char switches;                                  // char tipinde 'switches' isminde bir de�i�ken olu�turuluyor.
     switches.b0=!GPIOE_IDR.B13;                      // 'E' portunun 13. pininin de�eri okunuyor ve de�ili al�narak
                                                     // 'switches' de�i�keninin 0. bitine aktar�l�yor.
     switches.b1=!GPIOE_IDR.B14;                      // 'E' portunun 14. pininin de�eri okunuyor ve de�ili al�narak
                                                     // 'switches' de�i�keninin 1. bitine aktar�l�yor.
     switches.b2=!GPIOE_IDR.B15;                      // 'E' portunun 15. pininin de�eri okunuyor ve de�ili al�narak
                                                     // 'switches' de�i�keninin 2. bitine aktar�l�yor.
     switches.b3=!GPIOB_IDR.B15;                      // 'B' portunun 15. pininin de�eri okunuyor ve de�ili al�narak
                                                     // 'switches' de�i�keninin 3. bitine aktar�l�yor.
     switches.b4=!GPIOC_IDR.B8 ;                      // 'C' portunun 18. pininin de�eri okunuyor ve de�ili al�narak
                                                     // 'switches' de�i�keninin 4. bitine aktar�l�yor.
     switches.b5=!GPIOD_IDR.B9 ;                      // 'D' portunun 9. pininin de�eri okunuyor ve de�ili al�narak
                                                     // 'switches' de�i�keninin 5. bitine aktar�l�yor.
     switches.b6=!GPIOD_IDR.B10;                      // 'D' portunun 10. pininin de�eri okunuyor ve de�ili al�narak
                                                     // 'switches' de�i�keninin 6. bitine aktar�l�yor.
     switches.b7=!GPIOD_IDR.B11;                      // 'D' portunun 11. pininin de�eri okunuyor ve de�ili al�narak
                                                     // 'switches' de�i�keninin 7. bitine aktar�l�yor.
     GPIOE_ODR=switches;                             // 'E' portuna switches de�i�keni aktar�l�yor ve anahtarlar�n
                                                     // durumu ledlerde g�steriliyor.
     
  /* char switches;                                  // char tipinde 'switches' isminde bir de�i�ken olu�turuluyor.
     switches.b0=GPIOE_IDR.B13;                      // 'E' portunun 13. pininin de�eri okunarak
                                                     // 'switches' de�i�keninin 0. bitine aktar�l�yor.
     switches.b1=GPIOE_IDR.B14;                      // 'E' portunun 14. pininin de�eri okunarak
                                                     // 'switches' de�i�keninin 1. bitine aktar�l�yor.
     switches.b2=GPIOE_IDR.B15;                      // 'E' portunun 15. pininin de�eri okunarak
                                                     // 'switches' de�i�keninin 2. bitine aktar�l�yor.
     switches.b3=GPIOB_IDR.B15;                      // 'B' portunun 15. pininin de�eri okunarak
                                                     // 'switches' de�i�keninin 3. bitine aktar�l�yor.
     switches.b4=GPIOC_IDR.B8 ;                      // 'C' portunun 18. pininin de�eri okunarak
                                                     // 'switches' de�i�keninin 4. bitine aktar�l�yor.
     switches.b5=GPIOD_IDR.B9 ;                      // 'D' portunun 9. pininin de�eri okunarak
                                                     // 'switches' de�i�keninin 5. bitine aktar�l�yor.
     switches.b6=GPIOD_IDR.B10;                      // 'D' portunun 10. pininin de�eri okunarak
                                                     // 'switches' de�i�keninin 6. bitine aktar�l�yor.
     switches.b7=GPIOD_IDR.B11;                      // 'D' portunun 11. pininin de�eri okunarak
                                                     // 'switches' de�i�keninin 7. bitine aktar�l�yor.
     GPIOE_ODR=~switches;                             // 'E' portuna switches de�i�keni toggle de�i�keni
                                                     // ile ters �evrilerek aktar�l�yor ve anahtarlar�n
                                                     // durumu ledlerde g�steriliyor.
   */
    }
}