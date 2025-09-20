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

/* ----- এডিসি (ADC - Analog-to-Digital Converter) প্রোগ্রাম -----
 * এই প্রোগ্রামটি মাইক্রোকন্ট্রোলারের এডিসি মডিউল ব্যবহার করে এনালগ সিগন্যালকে ডিজিটাল ভ্যালুতে রূপান্তর করে।
 *
 * কিভাবে কাজ করে:
 * ১. valADC ভেরিয়েবল - এডিসির ডিজিটাল ভ্যালু সংরক্ষণ করে (০-১০২৩ রেঞ্জে)
 * ২. voltage ভেরিয়েবল - গণনা করা ভোল্টেজ ভ্যালু সংরক্ষণ করে (০-৫ভোল্ট)
 * ৩. x[7] অ্যারে - স্ট্রিং হিসেবে ভ্যালু প্রদর্শনের জন্য বাফার
 *
 * প্রধান কার্যাবলী:
 * - UART1_Init(9600): সিরিয়াল কমিউনিকেশন শুরু করে ৯৬০০ বড রেটে
 * - ADC_Init(): এডিসি মডিউল চালু করে
 * - ADC_Read(0): চ্যানেল ০ (RA0 পিন) থেকে এনালগ ভ্যালু পড়ে
 * - ভোল্টেজ গণনা: (ADC_value × 5V) ÷ 1023 = প্রকৃত ভোল্টেজ
 * - IntToStr() এবং FloatToStr(): সংখ্যাকে স্ট্রিং-এ রূপান্তর করে
 * - UART1_Write_Text(): UART দিয়ে ডেটা পাঠায়
 * - Delay_ms(1000): ১ সেকেন্ড অপেক্ষা করে
 *
 * ব্যবহার: এনালগ সেন্সর (যেমন: তাপমাত্রা সেন্সর, আলোর সেন্সর) থেকে ডেটা পড়ার জন্য।
 * আউটপুট: কম্পিউটারের সিরিয়াল মনিটরে এডিসি ভ্যালু এবং ভোল্টেজ প্রদর্শিত হবে।
 */
