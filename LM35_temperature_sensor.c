// LCD module connections
sbit LCD_RS at RB0_bit;
sbit LCD_EN at RB1_bit;
sbit LCD_D4 at RB2_bit;
sbit LCD_D5 at RB3_bit;
sbit LCD_D6 at RB4_bit;
sbit LCD_D7 at RB5_bit;
sbit LCD_RS_Direction at TRISB0_bit;
sbit LCD_EN_Direction at TRISB1_bit;
sbit LCD_D4_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB3_bit;
sbit LCD_D6_Direction at TRISB4_bit;
sbit LCD_D7_Direction at TRISB5_bit;
// End LCD module connections
char display[16]="";
void main()
{
unsigned int result;
float volt,temp;
trisb=0x00;
trisa=0xff;
adcon1=0x80;
lcd_init();
lcd_cmd(_lcd_clear);
lcd_cmd(_LCD_CURSOR_OFF);
while(1)
{
result=adc_read(0);
volt=result*4.88;
temp=volt/10;
lcd_out(1,1,"Temp = ");
floattostr(temp,display);
lcd_out_cp(display);
lcd_chr(1,16,223); //print at pos(row=1,col=13) "�" =223 =0xdf
lcd_out_cp("  C"); //celcius
}
}

/* ----- LM35 তাপমাত্রা সেন্সর (Temperature Sensor) প্রোগ্রাম -----
 * এই প্রোগ্রামটি LM35 তাপমাত্রা সেন্সর থেকে ডেটা পড়ে এবং LCD তে সেলসিয়াস তাপমাত্রা প্রদর্শন করে।
 *
 * হার্ডওয়্যার সংযোগ:
 * LCD সংযোগ (4-bit মোড):
 * - RS → RB0, EN → RB1
 * - D4 → RB2, D5 → RB3, D6 → RB4, D7 → RB5
 * - PORTA: ADC ইনপুট (LM35 সেন্সর সংযুক্ত)
 *
 * LM35 সেন্সর বৈশিষ্ট্য:
 * - আউটপুট: ১০mV/°C (প্রতি ডিগ্রি সেলসিয়াসে ১০ মিলিভোল্ট)
 * - রেঞ্জ: 0°C থেকে 100°C
 * - লিনিয়ার আউটপুট ভোল্টেজ
 *
 * কিভাবে কাজ করে:
 * ১. ADC কনফিগারেশন: ADCON1=0x80 (ADC চালু, AN0 চ্যানেল)
 * ২. result = adc_read(0): AN0 চ্যানেল থেকে ADC ভ্যালু পড়া
 * ৩. ভোল্টেজ গণনা: volt = result × 4.88 (5V/1024 × 1000 = 4.88mV/count)
 * ৪. তাপমাত্রা গণনা: temp = volt/10 (LM35: 10mV/°C)
 *
 * LCD প্রদর্শন:
 * - lcd_init(): LCD চালু করা
 * - lcd_cmd(_lcd_clear): স্ক্রিন পরিষ্কার
 * - lcd_cmd(_LCD_CURSOR_OFF): কার্সার বন্ধ
 * - lcd_out(1,1,"Temp = "): ১ম লাইনে "Temp = " লেখা
 * - floattostr(temp,display): তাপমাত্রাকে স্ট্রিং-এ রূপান্তর
 * - lcd_chr(1,16,223): ডিগ্রি চিহ্ন (°) প্রদর্শন (ASCII 223)
 *
 * ব্যবহার: আবহাওয়া পর্যবেক্ষণ, ইনকিউবেটর, এয়ার কন্ডিশনার নিয়ন্ত্রণ ইত্যাদিতে।
 */