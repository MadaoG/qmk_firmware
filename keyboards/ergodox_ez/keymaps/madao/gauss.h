
int gauss(int x, int a, int m, int s)
{
  return (int)floor(a * exp(-0.5 * (x - m) * (x - m) / (s * s)));
}

int brightness_very_slow(int time, int offset)
{
  return gauss(time, 255, offset, 150);
}

int brightness_slow(int time, int offset)
{
  return gauss(time, 255, offset, 100);
}

int brightness_middle(int time, int offset)
{
  return gauss(time, 255, offset, 70);
}

int brightness_fast(int time, int offset)
{
  return gauss(time, 255, offset, 50);
}

int brightness_very_fast(int time, int offset)
{
  return gauss(time, 255, offset, 30);
}

int brightness_fast_double(int time, int offset1, int offset2)
{
  return brightness_fast(time, offset1)
       + brightness_fast(time, offset2);
}

int brightness_very_fast_double(int time, int offset1, int offset2)
{
  return brightness_very_fast(time, offset1)
       + brightness_very_fast(time, offset2);
}

int brightness_very_fast_triple(int time, int offset1, int offset2, int offset3)
{
  return brightness_very_fast(time, offset1)
       + brightness_very_fast(time, offset2)
       + brightness_very_fast(time, offset3);
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
