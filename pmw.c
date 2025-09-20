
void main()
{
    short duty = 0; //initial value for duty

    TRISD = 0xFF; //PORTD as input
    TRISB = 0x00; //PORTB as output
    //Run motor in anticlock wise
    PORTB.F0=0xff;
    PORTB.F1=0x00;

    PWM1_Init(1000); //Initialize PWM1
    PWM1_Start(); //start PWM1
    PWM1_Set_Duty(duty); //Set current duty for PWM1

    while (1) // endless loop
    {
            if (RD0_bit && duty<250)
            {
                duty = duty + 10; //increment current_duty
                PWM1_Set_Duty(duty); //Change the duty cycle
            }


        if (RD1_bit && duty>0) //button on RD1 pressed
        {
            Delay_ms(100);
            if (RD1_bit && duty>0)
            {
                duty = duty - 10; //decrement duty
                PWM1_Set_Duty(duty);
            }
        }
        Delay_ms(10); // slow down change pace a little
    }
}

/* ----- PWM মোটর নিয়ন্ত্রণ (PWM Motor Control) প্রোগ্রাম -----
 * এই প্রোগ্রামটি PWM সিগন্যাল ব্যবহার করে ডিসি মোটরের গতি নিয়ন্ত্রণ করে।
 *
 * হার্ডওয়্যার সংযোগ:
 * - PORTD: ইনপুট (বাটন সংযোগ)
 * - PORTB: আউটপুট (মোটর ড্রাইভার)
 * - RD0: স্পিড বৃদ্ধি বাটন
 * - RD1: স্পিড কমানো বাটন
 *
 * PWM কনফিগারেশন:
 * - PWM1_Init(1000): ১০০০ Hz ফ্রিকুয়েন্সি
 * - PWM1_Start(): PWM সিগন্যাল চালু
 * - PWM1_Set_Duty(duty): ডিউটি সাইকেল সেট করা
 *
 * মোটর দিক নিয়ন্ত্রণ:
 * - PORTB.F0=1, F1=0: বিপরীত ঘড়ির কাঁটায় ঘূর্ণন
 *
 * বাটন অপারেশন:
 * - RD0: ডিউটি ১০ করে বাড়ায় (সর্বোচ্চ ২৫০)
 * - RD1: ডিউটি ১০ করে কমায় (সর্বনিম্ন ০)
 *
 * ব্যবহার: ফ্যান স্পিড কন্ট্রোল, পাম্প মোটর, রোবট চালনা।
 */
