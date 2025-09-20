#define digitL portc.f1
#define digitR portc.f2

// Common anode 7-segment display pattern
unsigned char array[] = {
   0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90
};

void main() {
    //int i = 0;
    int i = 10;
    int j, Left_digit = 0, Right_digit = 0;

    TRISB = 0x00;   // PORTB as output (segments)
    TRISC = 0x00;   // PORTC as output (digit control)
    portb = 0x00;
    portc = 0x00;

    while (1) {
        Left_digit = i / 10;
        Right_digit = i % 10;

        for (j = 0; j < 30; j++) {
            // Display Left digit
            portb = array[Left_digit]; // Send pattern
            digitL = 1;                // Enable left digit (common anode = HIGH)
            digitR = 0;                // Disable right digit
            delay_ms(5);              // Small delay
            digitL = 0;               // Turn off left digit

            // Display Right digit
            portb = array[Right_digit];
            digitR = 1;                // Enable right digit
            digitL = 0;                // Disable left digit
            delay_ms(5);
            digitR = 0;                // Turn off right digit
        }

        i++;
        //if (i > 99) i = 0;
        if(i > 20) i = 10; // Reset after 99
    }
}

/* ----- দ্বি-ডিজিট ৭-সেগমেন্ট ডিসপ্লে (Two Digit Display) প্রোগ্রাম -----
 * এই প্রোগ্রামটি দুটি ৭-সেগমেন্ট ডিসপ্লেতে ১০-২০ পর্যন্ত কাউন্ট প্রদর্শন করে।
 *
 * হার্ডওয়্যার সংযোগ:
 * - PORTB: সেগমেন্ট প্যাটার্ন আউটপুট (a-g সেগমেন্ট)
 * - PORTC: ডিজিট সিলেকশন
 * - digitL (RC1): বাম ডিজিট নিয়ন্ত্রণ
 * - digitR (RC2): ডান ডিজিট নিয়ন্ত্রণ
 *
 * কমন অ্যানোড কনফিগারেশন:
 * - array[]: 0-9 সংখ্যার জন্য কমন অ্যানোড প্যাটার্ন
 * - HIGH সিগন্যাল দিয়ে ডিজিট সক্রিয় করা হয়
 *
 * মাল্টিপ্লেক্সিং কৌশল:
 * ১. Left_digit = i/10: দশকের অংক বের করা
 * ২. Right_digit = i%10: একক সংখ্যার অংক বের করা
 * ৩. প্রতিটি ডিজিট ৫ms করে ৩০ বার প্রদর্শন
 * ৪. দ্রুত সুইচিং এর কারণে দুটো ডিজিট একসাথে দেখায়
 *
 * টাইম-ডিভিশন মাল্টিপ্লেক্সিং:
 * - বাম ডিজিট চালু → প্যাটার্ন পাঠানো → ৫ms অপেক্ষা → বন্ধ
 * - ডান ডিজিট চালু → প্যাটার্ন পাঠানো → ৫ms অপেক্ষা → বন্ধ
 * - এই প্রক্রিয়া ৩০ বার পুনরাবৃত্তি (মোট ৩০০ms)
 *
 * কাউন্টিং রেঞ্জ:
 * - i = 10 থেকে শুরু (১০ প্রদর্শন)
 * - i > 20 হলে আবার i = 10 (১০-২০ সাইক্লিক কাউন্ট)
 *
 * পার্সিসটেন্স অফ ভিশন:
 * - চোখের জড়তার কারণে দুটি ডিজিট একসাথে স্থির দেখায়
 * - ৫ms এর কম সময় চোখে ফ্লিকারিং ধরা পড়ে না
 *
 * ব্যবহার: ডিজিটাল ঘড়ি, স্কোরবোর্ড, কাউন্টার, টাইমার ইত্যাদিতে।
 */

