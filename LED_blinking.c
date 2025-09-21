void main() {
  TRISB = 0x00; // set PorB as Output
  portb = 0x00; // initialize portb as off

  while(1)
  {
   portb.f0 = 1;
   portb.f1 = 0;
   delay_ms(500);
   portb.f0 = 0;
   portb.f1 = 1;
   delay_ms(500);
  }

}