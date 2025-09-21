// Declare variables
int valADC;                // Variable to store ADC value (digital representation)
char x[7];                 // Buffer to store the string representation of the ADC value (at least 7 chars)
float voltage;             // Variable to store the calculated voltage value

void main()
{
    // Initialize UART communication at a baud rate of 9600
    UART1_Init(9600);

    // Initialize ADC (Analog-to-Digital Converter) for reading analog values
    ADC_Init();

    while(1)  // Infinite loop to keep reading ADC value continuously
    {
        // Read the ADC value from channel 0 (RA0 pin)
        valADC = ADC_Read(0);

        // Convert the ADC value to a voltage (5V reference voltage, 10-bit ADC resolution)
        voltage = (valADC * 5.0) / 1023.0;

        // Convert the ADC value (integer) to a string for displaying it
        IntToStr(valADC, x);

        // Send "ADC = " text through UART
        UART1_Write_Text("ADC = ");

        // Send the string version of the ADC value through UART
        UART1_Write_Text(x);

        // Send a new line (carriage return) to move to the next line
        UART1_Write(13);

        // Delay for 1 second before reading the next ADC value
        Delay_ms(1000);

        // Convert the voltage value (float) to a string for displaying it
        FloatToStr(voltage, x);

        // Send "Actual voltage = " text through UART
        UART1_Write_Text("Actual voltage = ");

        // Send the string version of the calculated voltage value through UART
        UART1_Write_Text(x);

        // Send a new line (carriage return) to move to the next line
        UART1_Write(13);

        // Delay for 1 second before reading the next ADC value
        Delay_ms(1000);
    }
}

