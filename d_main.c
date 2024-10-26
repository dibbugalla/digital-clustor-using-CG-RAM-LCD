#include"d_header.h"
int main()
{
u32 adc_out,v;
float vout,temperature;
uart0_init(9600);
adc_init();
lcd_init();
uart0_tx_string("Adc\r\n");
   lcd_data('A') ;
while(1)
{ 
lcd_cmd(0x01);
v=adc_read(2);
if(v==0)
{
lcd_cgram();
lcd_cmd(0x80);

//lcd_integer(v);
   lcd_data(0);
  }
   else if(v>=1 && v<=250)
   {	 lcd_cmd(0x01);
   lcd_cgram1();
   	lcd_cmd(0x80);
   lcd_data(1);
   } 
   else if(v>=251&&v<=500)
   {
   lcd_cmd(0x01);
   lcd_cgram2();
   lcd_cmd(0x80);
   lcd_data(2);
   } 
   else if(v>=501&&v<=750)
   {
   lcd_cmd(0x01);
   lcd_cgram3();
   lcd_cmd(0x80);
   lcd_data(3);
   } 
   else if(v>=751&&v<=1023)
   {
   lcd_cmd(0x01);
   lcd_cgram4();
   lcd_cmd(0x80);
   lcd_data(4);
   } 
uart0_tx_integer(v);
uart0_tx_string("\r\n");
adc_out=adc_read(1);
vout=(adc_out*3.3)/1023;
temperature=(vout-0.5)/0.01;
lcd_cmd(0xc0);
lcd_float(temperature);
lcd_data('c');
uart0_tx_float(temperature);
uart0_tx('c');
uart0_tx_string("\r\n");
delay_sec(1);


}


}
