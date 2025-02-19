//    Anahtarların ve Ledlerin kullanımı.  //
//        MikroC v6.2 - STM32F407VG        //
// ARMapp-18 Deney Seti için yazılmıştır   //
/* 	SW7 - LED0
	SW6 - LED1
	SW5 - LED2
	SW4 - LED3
	SW3 - LED4
	SW2 - LED5 
	SW1 - LED6
	SW0 - LED7
    eşleşmesi ile anahtarların eşleştikleri ledlerin durumlarını kontrol etmelerini sağlayınız.*/


void main()                                           // Ana Program Bloğu
{
 GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_0|    // 'E' Portunun 0-7. pinleri dijital
                                  _GPIO_PINMASK_1|    //  çıkış olarak ayarlanıyor.
                                  _GPIO_PINMASK_2|
                                  _GPIO_PINMASK_3|
                                  _GPIO_PINMASK_4|
                                  _GPIO_PINMASK_5|
                                  _GPIO_PINMASK_6|
                                  _GPIO_PINMASK_7);

 GPIO_Digital_Input(&GPIOE_BASE, _GPIO_PINMASK_13|   // 'E' Portunun 13,14 ve 15. pinleri dijital
                                 _GPIO_PINMASK_14|   //  giriş olarak ayarlanıyor.
                                 _GPIO_PINMASK_15);

 GPIO_Digital_Input(&GPIOB_BASE, _GPIO_PINMASK_15);  // 'B' Portunun 15. pini dijital
                                                     // giriş olarak ayarlanıyor.

 GPIO_Digital_Input(&GPIOC_BASE, _GPIO_PINMASK_8 );  // 'C' Portunun 8. pini dijital
                                                     // giriş olarak ayarlanıyor.
 
 GPIO_Digital_Input(&GPIOD_BASE, _GPIO_PINMASK_9 |   // 'D' Portunun 9,10 ve 11. pinleri dijital
                                 _GPIO_PINMASK_10|   // giriş olarak ayarlanıyor.
                                 _GPIO_PINMASK_11);
                                 
 while(1)                                            // Sonsuz döngü
    {
     char switches;                                  // char tipinde 'switches' isminde bir değişken oluşturuluyor.
     switches.b7=GPIOE_IDR.B13;                      // 'E' portunun 13. pininin değeri okunarak
                                                     // 'switches' değişkeninin 0. bitine aktarılıyor.
     switches.b6=GPIOE_IDR.B14;                      // 'E' portunun 14. pininin değeri okunarak
                                                     // 'switches' değişkeninin 1. bitine aktarılıyor.
     switches.b5=GPIOE_IDR.B15;                      // 'E' portunun 15. pininin değeri okunarak
                                                     // 'switches' değişkeninin 2. bitine aktarılıyor.
     switches.b4=GPIOB_IDR.B15;                      // 'B' portunun 15. pininin değeri okunarak
                                                     // 'switches' değişkeninin 3. bitine aktarılıyor.
     switches.b3=GPIOC_IDR.B8 ;                      // 'C' portunun 18. pininin değeri okunarak
                                                     // 'switches' değişkeninin 4. bitine aktarılıyor.
     switches.b2=GPIOD_IDR.B9 ;                      // 'D' portunun 9. pininin değeri okunarak
                                                     // 'switches' değişkeninin 5. bitine aktarılıyor.
     switches.b1=GPIOD_IDR.B10;                      // 'D' portunun 10. pininin değeri okunarak
                                                     // 'switches' değişkeninin 6. bitine aktarılıyor.
     switches.b0=GPIOD_IDR.B11;                      // 'D' portunun 11. pininin değeri okunarak
                                                     // 'switches' değişkeninin 7. bitine aktarılıyor.
     GPIOE_ODR=switches;                             // 'E' portuna switches değişkeni aktarılarak anahtarların
                                                     // durumu ledlerde gösteriliyor.
    }
}