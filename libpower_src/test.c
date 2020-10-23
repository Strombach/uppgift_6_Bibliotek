#include <stdio.h>
#include "calc_power.h"

int main()
{
  float effect_r = calc_power_r(12, 20);

  printf("Effect: %f", effect_r);

  return 0;
}
