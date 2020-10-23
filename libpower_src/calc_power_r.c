float calc_power_r(float volt, float resistance)
{
  float exponent = 2;
  float voltPoweredByExponent = 0;

  float power;

  for (int i = 0; i < exponent; i++)
  {
    if (voltPoweredByExponent == 0)
    {
      voltPoweredByExponent = volt;
    }
    else
    {
      voltPoweredByExponent *= volt;
    }
  }

  power = voltPoweredByExponent / resistance;

  return power;
}
