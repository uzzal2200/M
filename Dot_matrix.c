void MSDelay(unsigned char Time)
{
    unsigned char y,z;
    for(y=0;y<Time;y++)
        for(z=0;z<250;z++);
}

void main()
{
    TRISC = 0x00;
    TRISD = 0x00;
    while(1)
    {
        PORTD = 0x80;
        PORTC = 0x00;
        MSDelay(10);

        PORTD = 0x40;
        PORTC = 0xFF;
        MSDelay(10);

        PORTD = 0x20;
        PORTC = 0xFF;
        MSDelay(10);

        PORTD = 0x10;
        PORTC = 0x18;
        MSDelay(10);

        PORTD = 0x08;
        PORTC = 0x18;
        MSDelay(10);

        PORTD = 0x04;
        PORTC = 0xFF;
        MSDelay(10);

        PORTD = 0x02;
        PORTC = 0xFF;
        MSDelay(10);

        PORTD = 0x01;
        PORTC = 0x00;
        MSDelay(10);
    }
}
