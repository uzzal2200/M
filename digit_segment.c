char arraycc[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int clk=0,bt_zero=0,bt_one=0,bt_two=0 ,bt_three=0;

int button_response( int bt )
 {
      if(portd.f1==1)
      {
        delay_ms(150);
        if(portd.f1==1)
         {
           bt++;
            if(bt==10)
             {
              bt=0;
             }
         }
      }

      return bt;
 }

   void button_click()
   {
     if(portd.f0==1)
     {
       delay_ms(100);
       if(portd.f0==1)
        {
         clk++;
          if(clk==4)
          {
            clk=0;
          }
        }
     }
     switch(clk)
     {

        case 0:
           bt_zero= button_response( bt_zero);
           break;
        case 1:
           bt_one= button_response( bt_one);
           break;
        case 2:
           bt_two= button_response( bt_two);
           break;
        case 3:
           bt_three= button_response( bt_three);
           break;


     }

   }




void main() {
   TrisB=0x00;//initialize as output
   TrisC=0x00;// initialize as output
   TrisD=0xff; //initialize as input
   portb=0x00;
   portc=0x00;


   while(1)
   {
    button_click();

        //display in 7segment display
   portc.f0=0;
   portb=arraycc[bt_zero];
   delay_ms(10);
   portc.f0=1;

   portc.f1=0;
   portb=arraycc[bt_one];
   delay_ms(10);
   portc.f1=1;

   portc.f2=0;
   portb=arraycc[bt_two];
   delay_ms(10);
   portc.f2=1;

   portc.f3=0;
   portb=arraycc[bt_three];
   delay_ms(10);
   portc.f3=1;

   }



}