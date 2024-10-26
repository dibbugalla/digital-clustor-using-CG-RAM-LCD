 #include<lpc21xx.h>			   
 #define s8 char
#define u8 unsigned char
#define u32 unsigned int
typedef struct can1_msg

{
	u32 id;
	u32 rtr;
	u32 dlc;
	u32 byteA;
	u32 byteB;


}can1;
	
extern void delay_sec(unsigned int ) ;
extern void delay_ms(unsigned int);
extern void lcd_data(unsigned char);
extern void lcd_cmd(unsigned char);
extern void lcd_init(void);
extern void lcd_cgram(void);
extern void lcd_cgram1(void);
extern void lcd_cgram2(void);
extern void lcd_cgram3(void);
extern void lcd_cgram4(void);
extern void lcd_cgram5(void);
extern void lcd_cgram6(void);
extern void adc_init(void);
extern u32 adc_read(u8);
extern void lcd_integer(int);
extern void lcd_float(float);
extern void uart0_init(u32 );
extern void uart0_tx(u8 data);
extern u8 uart0_rx(void);
extern void uart0_tx_string(s8*);
extern void uart0_rx_string(u8*,u8);
extern void uart0_tx_integer(int );
extern void uart0_tx_float(float);
extern void config_vic_for_timer1(void);
extern void config_t1(int );
extern void config_can1(void);
extern void config_vic_for_can1(void);
extern void can1_init(void);
extern void can1_tx(can1);
















