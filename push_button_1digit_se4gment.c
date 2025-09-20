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

/* ----- পুশ বাটন সহ একক ডিজিট সেগমেন্ট ডিসপ্লে প্রোগ্রাম -----
 * এই প্রোগ্রামটি দুটি বাটন ব্যবহার করে ৭-সেগমেন্ট ডিসপ্লেতে ০-৯ সংখ্যা প্রদর্শন করে।
 *
 * হার্ডওয়্যার সংযোগ:
 * - PORTB: ৭-সেগমেন্ট ডিসপ্লে (আউটপুট)
 * - PORTD: বাটন ইনপুট
 * - RD0: ইনক্রিমেন্ট বাটন (বৃদ্ধি)
 * - RD1: ডিক্রিমেন্ট বাটন (হ্রাস)
 *
 * ৭-সেগমেন্ট প্যাটার্ন অ্যারে:
 * - array[10]: ০-৯ সংখ্যার জন্য বিট প্যাটার্ন
 * - কমন ক্যাথোড কনফিগারেশনের জন্য
 * - উদাহরণ: 0x40 = '0', 0x79 = '1'
 *
 * কিভাবে কাজ করে:
 * ১. i ভেরিয়েবল: বর্তমান সংখ্যা (০-৯ রেঞ্জে)
 * ২. PORTB = array[i]: প্যাটার্ন ডিসপ্লেতে পাঠানো
 * ৩. বাটন চেক:
 *    - RD0 চাপলে এবং i<9 হলে: i++ (বৃদ্ধি)
 *    - RD1 চাপলে এবং i>0 হলে: i-- (হ্রাস)
 * ৪. delay_ms(150): বাটন ডিবাউন্সিং
 *
 * সেগমেন্ট ম্যাপিং (a-g):
 *  aaa
 * f   b
 * f   b
 *  ggg
 * e   c
 * e   c
 *  ddd
 *
 * ব্যবহার: কাউন্টার, স্কোর ডিসপ্লে, ডিজিটাল মিটার ইত্যাদিতে।
 */
