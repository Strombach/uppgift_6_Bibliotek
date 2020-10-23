float calc_power_r(float volt, float resistance)
{
  float poweredBy = 2;
  float u_poweredBy = 0;
  float effect;

  for (int i = 0; i < poweredBy; i++)
  {
    if (u_poweredBy == 0)
    {
      u_poweredBy = volt;
    }
    else
    {
      u_poweredBy *= volt;
    }
  }

  effect = u_poweredBy / resistance;

  return effect;
}
