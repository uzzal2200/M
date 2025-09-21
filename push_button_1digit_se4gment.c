char array[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};

void main() {

  int i = 0;
  TRISB = 0x00;  // Set PORTB as output
  TRISD = 0xFF;  // Set PORTD as input


  while(1) {
    PORTB = array[i];  // Output the value from the array to PORTB

    if (PORTD.F0 && i < 9) {  // Check if button is pressed and i < 9
      delay_ms(150);  // Wait for 1 second
      i++;  // Move to the next index
    }

    if (PORTD.F1 && i > 0) {  // Check if the other button is pressed and i > 0
      delay_ms(150);  // Shorter delay
      i--;  // Move to the previous index
    }
  }
}


