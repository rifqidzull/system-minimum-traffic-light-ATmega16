/*
this was made in CVAVR

in CVAVR create new file and use Code Wizard AVR
- chose chip AVR  AT90, ATtiny, ATmega
- chip : ATmega 16, clock : 16 Mhz
- Ports : A 0-3 = Input P
          B 0-7 = Output 0
          C default  don't need change
          D 0-7 = Output 0
- Alphanumeric LCD Enable : Controller type = HD44780
                            Character line = 16
                            LCD module AVR = all PORT C
*/



/*
Project : SISTEM MINIMUM TRAFICT LIGHT ATMEGA 16
Author  : RIFQI DZULFIQAR
*/

#include <mega16.h>
#include <alcd.h>
#include <delay.h>
#include <stdio.h>

unsigned char lcd[16];
int counter1_1 = 5;
int counter1_2 = 3;
int counter2_1 = 5;
int counter2_2 = 3;
int counter3_1 = 5;
int counter3_2 = 3;
int counter4_1 = 5;
int counter4_2 = 3;

int counterB1_1 = 3;
int counterB1_2 = 10;
int counterB1_3 = 3;

int counterB2 = 5;

int counterB3 = 5;

int counterK = 3;
int counterH = 5;

int i;

// THIS CODE APPEARS ON THE LCD START

// MAIN CODE LCD TRAFFIC START
// LCD CROSSROADS 1
void LCD_COUNTER1_1(){
counter1_1--;
lcd_clear();
lcd_putsf("CROSSROADS 1");
lcd_gotoxy(0,1);
lcd_putsf("MOVE : ");
sprintf(lcd,"%1i",counter1_1);
lcd_puts(lcd);
delay_ms(1000);
}

//LCD CROSSROADS 1-2
void LCD_COUNTER1_2(){
counter1_2--;
lcd_clear();
lcd_putsf("CROSSROADS 2");
lcd_gotoxy(0,1);
lcd_putsf("GET READY : ");
sprintf(lcd,"%1i",counter1_2);
lcd_puts(lcd);
delay_ms(1000);
}

//LCD CROSSROADS 2
void LCD_COUNTER2_1(){
counter2_1--;
lcd_clear();
lcd_putsf("CROSSROADS 2");
lcd_gotoxy(0,1);
lcd_putsf("MOVE : ");
sprintf(lcd,"%1i",counter2_1);
lcd_puts(lcd);
delay_ms(1000);
}

//LCD CROSSROADS 2-3
void LCD_COUNTER2_2(){
counter2_2--;
lcd_clear();
lcd_putsf("CROSSROADS 3");
lcd_gotoxy(0,1);
lcd_putsf("GET READY : ");
sprintf(lcd,"%1i",counter2_2);
lcd_puts(lcd);
delay_ms(1000);
}

//LCD CROSSROADS 3
void LCD_COUNTER3_1(){
counter3_1--;
lcd_clear();
lcd_putsf("CROSSROADS 3");
lcd_gotoxy(0,1);
lcd_putsf("MOVE : ");
sprintf(lcd,"%1i",counter3_1);
lcd_puts(lcd);
delay_ms(1000);
}

//LCD CROSSROADS 3-4
void LCD_COUNTER3_2(){
counter3_2--;
lcd_clear();
lcd_putsf("CROSSROADS 4");
lcd_gotoxy(0,1);
lcd_putsf("GET READY : ");
sprintf(lcd,"%1i",counter3_2);
lcd_puts(lcd);
delay_ms(1000);
}

//LCD CROSSROADS 4
void LCD_COUNTER4_1(){
counter4_1--;
lcd_clear();
lcd_putsf("CROSSROADS 4");
lcd_gotoxy(0,1);
lcd_putsf("MOVE : ");
sprintf(lcd,"%1i",counter4_1);
lcd_puts(lcd);
delay_ms(1000);
}

// LCD CROSSROADS 4-1
void LCD_COUNTER4_2(){
counter4_2--;
lcd_clear();
lcd_putsf("CROSSROADS 1");
lcd_gotoxy(0,1);
lcd_putsf("GET READY : ");
sprintf(lcd,"%1i",counter4_2);
lcd_puts(lcd);
delay_ms(1000);
}
// MAIN CODE LCD TRAFFIC END

// MAIN CODE LCD BUTTON START
// LCD BUTTON 1_1
void LCD_COUNTER_BUTTON1_1(){
counterB1_1--;
lcd_clear();
lcd_gotoxy(0,0);
lcd_putsf("PEDESTRIAN");
lcd_gotoxy(0,1);
lcd_putsf("GET READY : ");
sprintf(lcd,"%1i",counterB1_1);
lcd_puts(lcd);
delay_ms(1000);
}

// LCD BUTTON 1_2
void LCD_COUNTER_BUTTON1_2(){
counterB1_2--;
lcd_clear();
lcd_gotoxy(0,0);
lcd_putsf("BE CAREFUL");
lcd_gotoxy(7,1);
sprintf(lcd,"%1i",counterB1_2);
lcd_puts(lcd);
delay_ms(1000);
}

// LCD BUTTON 1_3
void LCD_COUNTER_BUTTON1_3(){
counterB1_3--;
lcd_clear();;
lcd_gotoxy(0,0);
lcd_putsf("TRAFFIC");
lcd_gotoxy(0,1);
lcd_putsf("GET READY : ");
sprintf(lcd,"%1i",counterB1_3);
lcd_puts(lcd);
delay_ms(1000);
}

// LCD BUTTON 2
void LCD_COUNTER_BUTTON2(){
counterB2--;
lcd_clear();
lcd_gotoxy(0,0);
lcd_putsf("RUNNING LED 1");
lcd_gotoxy(0,1);
lcd_putsf("ROTATION : ");
sprintf(lcd,"%1i",counterB2);
lcd_puts(lcd);
}

// LCD BUTTON 3
void LCD_COUNTER_BUTTON3(){
counterB3--;
lcd_clear();
lcd_gotoxy(0,0);
lcd_putsf("RUNNING LED 2");
lcd_gotoxy(0,1);
lcd_putsf("ROTATION : ");
sprintf(lcd,"%1i",counterB3);
lcd_puts(lcd);
}
// MAIN CODE LCD BUTTON END
// THE CODE APPEARS ON THE LCD END

// MAIN CODE BUTTON START
// BUTTON 1
void BUTTON1(){
if (PINA.0==0){
        counterB1_1 = 3;
        for(i=1; i<=counterK; i++){
            PORTD = 0b00100010;
            PORTB = 0b00100010;
            delay_ms(1000);
            PORTD = 0x00;
            PORTB = 0x00;
            LCD_COUNTER_BUTTON1_1();
            }

        counterB1_2 = 10;
        for(i=1; i<=10; i++){
            PORTD = 0b10101010;
            PORTB = 0b10101010;
            delay_ms(1000);
            PORTD = 0b10001000;
            PORTB = 0b10001000;
            LCD_COUNTER_BUTTON1_2();
            }

        counterB1_3 = 3;
        for(i=1; i<=counterK; i++){
            PORTD = 0b00100010;
            PORTB = 0b00100010;
            delay_ms(1000);
            PORTB = 0x00;
            PORTD = 0x00;
            LCD_COUNTER_BUTTON1_3();
            }
        }
}

//BUTTON 2
void BUTTON2(){
if(PINA.1 == 0){
counterB2 = 5;
    for (i = 1; i<=5; i++){
    LCD_COUNTER_BUTTON2();
    PORTB = 0b00000001;
    PORTD = 0b00000000;
    delay_ms(100);
    PORTB = 0b000000010;
    delay_ms(100);
    PORTB = 0b000000100;
    delay_ms(100);
    PORTB = 0b000001000;
    delay_ms(100);
    PORTB = 0b000010000;
    delay_ms(100);
    PORTB = 0b000100000;
    delay_ms(100);
    PORTB = 0b001000000;
    delay_ms(100);
    PORTB = 0b010000000;
    delay_ms(100);
    PORTB = 0b100000000;
    delay_ms(100);
    PORTB = 0b00000000;
    PORTD = 0b00000001;
    delay_ms(100);
    PORTD = 0b00000010;
    delay_ms(100);
    PORTD = 0b00000100;
    delay_ms(100);
    PORTD = 0b00001000;
    delay_ms(100);
    PORTD = 0b00010000;
    delay_ms(100);
    PORTD = 0b00100000;
    delay_ms(100);
    PORTD = 0b01000000;
    delay_ms(100);
    PORTD = 0b10000000;
    delay_ms(100);
    };

}
}

//BUTTON 3
void BUTTON3(){
if (PINA.2 == 0){
    counterB3 = 5;
    for (i = 1; i <= 5; i++){
        LCD_COUNTER_BUTTON3();
        PORTB = 0b01000100;
        PORTD = 0b01000100;
        delay_ms(300);
        PORTB = 0b10101010;
        PORTD = 0b10101010;
        delay_ms(300);
        PORTB = 0b00010001;
        PORTD = 0b00010001;
        delay_ms(300);
        };
    };
}

//BUTTON 4
void BUTTON4(){

int kolom = 0;

    if (PINA.3 == 0){
    lcd_clear();
    lcd_gotoxy(0,0);
    lcd_putsf("FLIP FLOP");
    lcd_gotoxy(0,1);
    lcd_putsf("PORT B");
    PORTB = 0b00001111;
    PORTD = 0b00000000;
    delay_ms(1000);
    PORTB = 0b11110000;
    delay_ms(1000);
    PORTB = 0b00001111;
    delay_ms(1000);
    PORTB = 0b11110000;
    delay_ms(1000);

    lcd_clear();
    lcd_gotoxy(0,0);
    lcd_putsf("FLIP FLOP");
    lcd_gotoxy(0,1);
    lcd_putsf("PORT D");
    PORTB = 0b00000000;
    PORTD = 0b00001111;
    delay_ms(1000);
    PORTD = 0b11110000;
    delay_ms(1000);
    PORTD = 0b00001111;
    delay_ms(1000);
    PORTD = 0b11110000;
    delay_ms(1000);

    lcd_clear();
    lcd_gotoxy(kolom, 0);
    lcd_putsf("VARIASI");
    PORTB = 0b00001111;
    PORTD = 0x00;
    delay_ms(1000);
    kolom ++;
    PORTD = 0b00001111;
    PORTB = 0x00;
    delay_ms(1000);
    kolom ++;
    PORTB = 0b11110000;
    PORTD = 0x00;
    delay_ms(1000);
    kolom ++;
    PORTD = 0b11110000;
    PORTB = 0x00;
    delay_ms(1000);
    kolom ++;
    PORTB = 0b11110000;
    PORTD = 0b00001111;
    delay_ms(1000);
    kolom ++;
    PORTB = 0b00001111;
    PORTD = 0b11110000;
    delay_ms(1000);
    kolom ++;
    PORTB = 0b11110000;
    PORTD = 0b11110000;
    delay_ms(1000);
    kolom ++;
    PORTB = 0b00001111;
    PORTD = 0b00001111;
    delay_ms(1000);
    }
}
// MAIN CODE BUTTON END

void main(void)
{
PORTA = 0xFF; 
DDRA = 0x00; 

PORTB = 0x00; 
DDRB = 0xFF; 

PORTC = 0x00; 
DDRC = 0xFF; 

PORTD = 0x00; 
DDRD = 0xFF; 

//START UP LCD
lcd_init(16);
lcd_clear();
lcd_gotoxy(0,0);
lcd_putsf("INITIALIZATION");
lcd_gotoxy(0,1);
lcd_putsf("TRAFFIC LIGHT");
delay_ms(5000);
lcd_clear();

while (1){
        // MAIN CODE TRAFFIC LIGHT
        counter1_1 = 5;
        for(i=1; i<=counterH; i++){
            PORTB = 0b00010100;
            PORTD = 0b00010001;
            LCD_COUNTER1_1();
            BUTTON1();
            BUTTON2();
            BUTTON3();
            BUTTON4();
            }

        counter1_2 = 3;
        for(i=1; i<=counterK; i++){
            PORTB = 0b00100001;
            PORTD = 0b00010001;
            LCD_COUNTER1_2();
            BUTTON1();
            BUTTON2();
            BUTTON3();
            BUTTON4();
            }

        counter2_1 = 5;
        for(i=1; i<=counterH; i++){
            PORTB = 0b01000001;
            PORTD = 0b00010001;
            LCD_COUNTER2_1();
            BUTTON1();
            BUTTON2();
            BUTTON3();
            BUTTON4();
            }

        counter2_2 = 3;
        for(i=1; i<=counterK; i++){
            PORTB = 0b00010001;
            PORTD = 0b00010010;
            LCD_COUNTER2_2();
            BUTTON1();
            BUTTON2();
            BUTTON3();
            BUTTON4();
            }

        counter3_1 = 5;
        for(i=1; i<=counterH; i++){
            PORTB = 0b00010001;
            PORTD = 0b00010100;
            LCD_COUNTER3_1();
            BUTTON1();
            BUTTON2();
            BUTTON3();
            BUTTON4();
            }

        counter3_2 = 3;
        for(i=1; i<=counterK; i++){
            PORTB = 0b00010001;
            PORTD = 0b00100001;
            LCD_COUNTER3_2();
            BUTTON1();
            BUTTON2();
            BUTTON3();
            BUTTON4();
            }

        counter4_1 = 5;
        for(i=1; i<=counterH; i++){
            PORTB = 0b00010001;
            PORTD = 0b01000001;
            LCD_COUNTER4_1();
            BUTTON1();
            BUTTON2();
            BUTTON3();
            BUTTON4();
            }

        counter4_2 = 3;
        for(i=1; i<=counterK; i++){
            PORTB = 0b00010010;
            PORTD = 0b00010001;
            LCD_COUNTER4_2();
            BUTTON1();
            BUTTON2();
            BUTTON3();
            BUTTON4();
            }
        }
}