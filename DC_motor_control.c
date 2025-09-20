
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
        if (RD0_bit && duty<250) //if button on RD0 pressed
        {
            Delay_ms(100);
            if (RD0_bit && duty<250)
            {
                duty = duty + 10; //increment current_duty
                PWM1_Set_Duty(duty); //Change the duty cycle
            }
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

/* ----- ডিসি মোটর নিয়ন্ত্রণ (DC Motor Control) প্রোগ্রাম -----
 * এই প্রোগ্রামটি PWM (Pulse Width Modulation) ব্যবহার করে ডিসি মোটরের গতি নিয়ন্ত্রণ করে।
 *
 * হার্ডওয়্যার সংযোগ:
 * - PORTD: ইনপুট পোর্ট (বাটন সংযোগের জন্য)
 * - PORTB: আউটপুট পোর্ট (মোটর ড্রাইভারের জন্য)
 * - RD0: গতি বৃদ্ধির বাটন
 * - RD1: গতি কমানোর বাটন
 * - PORTB.F0 এবং F1: মোটরের দিক নিয়ন্ত্রণ
 *
 * কিভাবে কাজ করে:
 * ১. duty ভেরিয়েবল: PWM এর ডিউটি সাইকেল সংরক্ষণ করে (০-২৫০ রেঞ্জে)
 * ২. PWM1_Init(1000): ১০০০ Hz ফ্রিকুয়েন্সিতে PWM শুরু করে
 * ৩. PORTB.F0=1, F1=0: মোটর বিপরীত ঘড়ির কাঁটায় ঘোরে
 *
 * বাটন নিয়ন্ত্রণ:
 * - RD0 চাপলে: ডিউটি সাইকেল ১০ করে বৃদ্ধি পায় (সর্বোচ্চ ২৫০)
 * - RD1 চাপলে: ডিউটি সাইকেল ১০ করে কমে (সর্বনিম্ন ০)
 * - বাটন ডিবাউন্সিং এর জন্য ১০০ms বিলম্ব
 *
 * PWM নীতি:
 * - ডিউটি সাইকেল ০% = মোটর বন্ধ
 * - ডিউটি সাইকেল ১০০% = সর্বোচ্চ গতি
 * - PWM1_Set_Duty() দিয়ে গতি পরিবর্তন করা হয়
 *
 * ব্যবহার: ফ্যান নিয়ন্ত্রণ, রোবটিক্স, অটোমোবাইল স্পিড কন্ট্রোল ইত্যাদিতে ব্যবহৃত হয়।
 */
