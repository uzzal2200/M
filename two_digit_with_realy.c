char array []= {0x3F, 0x06, 0x5B,0x4F, 0x66, 0x6D, 0x7D,  0x07, 0x7F, 0x6F };

void main() {
int i,j, left, right;
TRISB = 0x00;
TRISC = 0x00;
portb=0x00;
portc=0x00;

while(1)
{
   for(i = 0; i<100; i++)
   {
       left = i / 10;
       right = i % 10;
       for(j = 0;j<50;j++)
       {
          portc.f0=0;
          portb = array [left];
          Delay_ms(5);
          portc.f0=1;

          portc.f1 = 0;
          portb = array[right];
          Delay_ms(5);
          portc.f1 = 1;

       }

   }

}


}
