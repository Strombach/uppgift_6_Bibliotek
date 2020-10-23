#include <stdio.h>
#include "calc_power.h"

int main()
{
  float power_r = calc_power_r(12, 20); // should return 7.2
  float power_i = calc_power_i(12, 5);  // should return 5.0

  printf("Power_R: %f\n", power_r);
  printf("Power_I: %f\n", power_i);

  return 0;
}
