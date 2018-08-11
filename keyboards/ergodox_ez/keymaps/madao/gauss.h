// #define _POSIX_C_SOURCE 200809L

// #include <inttypes.h>
// #include <math.h>
// #include <stdio.h>
#include <timer.h>

// void print_current_time_with_ms (void)
// {
//     long            ms; // Milliseconds
//     time_t          s;  // Seconds
//     struct timespec spec;

//     clock_gettime(CLOCK_REALTIME, &spec);

//     s  = spec.tv_sec;
//     ms = round(spec.tv_nsec / 1.0e6); // Convert nanoseconds to milliseconds
//     if (ms > 999) {
//         s++;
//         ms = 0;
//     }

//     printf("Current time: %"PRIdMAX".%03ld seconds since the Epoch\n",
//            (intmax_t)s, ms);
// }


uint16_t t = 0;         // time count for leds: 0 -- 1000

int gauss_curve(int x, int a, int m, int s)
{
  return (int)floor(a * exp(-0.5 * (x - m) * (x - m) / (s * s)));
}

int brightness_very_slow(int offset)
{
  return gauss_curve(t, 255, offset, 150);
}

int brightness_slow(int offset)
{
  return gauss_curve(t, 255, offset, 100);
}

int brightness_middle(int offset)
{
  return gauss_curve(t, 255, offset, 70);
}

int brightness_fast(int offset)
{
  return gauss_curve(t, 255, offset, 50);
}

int brightness_very_fast(int offset)
{
  return gauss_curve(t, 255, offset, 30);
}

int brightness_fast_double(int offset1, int offset2)
{
  return brightness_fast(offset1) 
       + brightness_fast(offset2);
}

int brightness_very_fast_double(int offset1, int offset2)
{
  return brightness_very_fast(offset1) 
       + brightness_very_fast(offset2);
}

int brightness_very_fast_triple(int offset1, int offset2, int offset3)
{
  return brightness_very_fast(offset1) 
       + brightness_very_fast(offset2)
       + brightness_very_fast(offset3);
}

void ergodox_set_red(int brightness)
{
  if (brightness == 0) {
    ergodox_right_led_1_off();
  } else {
    if (brightness > 255) brightness = 255;
    ergodox_right_led_1_on();
    ergodox_right_led_1_set(brightness);
  }
}

void ergodox_set_green(int brightness)
{
  if (brightness == 0) {
    ergodox_right_led_2_off();
  } else {
    if (brightness > 255) brightness = 255;
    ergodox_right_led_2_on();
    ergodox_right_led_2_set(brightness);
  }
}

void ergodox_set_blue(int brightness)
{
  if (brightness == 0) {
    ergodox_right_led_3_off();
  } else {
    if (brightness > 255) brightness = 255;
    ergodox_right_led_3_on();
    ergodox_right_led_3_set(brightness);
  }
}
