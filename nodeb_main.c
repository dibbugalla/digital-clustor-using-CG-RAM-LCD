#include"d_header.h"
#define HL_LED (1<<17)
#define RI (1<<18)
#define LI (1<<19)
can1 m1;
unsigned char flag;
unsigned char T_F;
main()
{


float vout,temperature;
u32 battery;
unsigned char temp;
lcd_init();
can1_init();

adc_init();
config_vic_for_can1();
config_can1();
	config_vic_for_timer1();
	config_t1(250);
	IODIR0|=HL_LED|RI|LI;
IOSET0|=HL_LED|RI|LI;
while(1)
{

if(flag==1)
{
flag=0;

switch((m1.byteA)&0xff)
{	 

case 0x10:
		IOCLR0=HL_LED;
		lcd_cgram5();
		lcd_cmd(0x82);
   		lcd_data(5);
		break;
case 0x11:IOSET0=HL_LED;
			lcd_cmd(0x82);
   		    lcd_data(' ');
			break;
case 0x12: temp=m1.byteA;
           IOSET0=RI;IOCLR0=LI;
			lcd_cgram6();
			lcd_cmd(0x84);
			lcd_data(6);
			break;
case 0x13:	 temp=m1.byteA;
             IOSET0=LI;
			lcd_cmd(0x84);
			lcd_data(' ');
			break;
case 0x14:	temp=m1.byteA;
            IOSET0=LI;IOCLR0=RI;
				lcd_cgram6();
			lcd_cmd(0x86);
			lcd_data(7);
			break;
case 0x15:	temp=m1.byteA;
           IOSET0=RI;
		    lcd_cmd(0x86);
			lcd_data(' ');
			break;	
} 


if((m1.id==0x314))
 {
//T_F=0;
vout=((float)((m1.byteA)&0x3ff)*3.3)/(float)1023;

temperature=(vout-0.5)/0.01;

lcd_cmd(0xc0);

lcd_float(temperature);

lcd_data('c');

battery=((m1.byteB));
 if(battery==0)

{

lcd_cgram();

lcd_cmd(0x80);

   lcd_data(0);

  }

   else if(battery>=1 && battery<=250)

   {	

   lcd_cgram1();

   	lcd_cmd(0x80);

   lcd_data(1);

   } 

   else if(battery>=251&&battery<=500)

   {
   lcd_cgram2();

   lcd_cmd(0x80);

   lcd_data(2);

   } 

   else if(battery>=501&&battery<=750)

   {

   

   lcd_cgram3();

   lcd_cmd(0x80);

   lcd_data(3);

   } 

   else if(battery>=751&&battery<=1023)

   {

   lcd_cgram4();

   lcd_cmd(0x80);

   lcd_data(4);

   } 
  }
}
if((temp==0x12)&&(T_F==1))
{  	 
IOCLR0=LI;
  lcd_cgram6();
  lcd_cmd(0x84);
   lcd_data(6);
  lcd_data(' '); 

}
else if (temp==0x14&& T_F==1)
{	  //T_F=0;
IOCLR0=RI;
	lcd_cgram6();
	lcd_cmd(0X86);
	lcd_data(7);
	 lcd_data(' ');
}
else
{						  
   IOSET0=LI;
   IOSET0=RI;
   lcd_cmd(0x84);
    lcd_data(' ');
   lcd_cmd(0x86);

   lcd_data(' ');
} 

}


}
