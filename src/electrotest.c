#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libresistance.h"
#include "libpower.h"
#include "libcomponent.h"
#define OMEGA "\u03a9"
#define MAX_RES 3

int main() 
{
	int count, i;  
	char conn[2];
	char str[10];			
	float volt, current, orig_resistance, power;
	float *res_array = (float*)malloc(MAX_RES * sizeof(float));

	//Ange spänningskälla i V:
	printf("Ange spänningskälla i V: ");
	fgets (str, sizeof(str), stdin);
	volt = atof(str);

	//Ange koppling[S | P]:
	while(strcmp(conn,"S") != 0 &&
	   	  strcmp(conn,"P") != 0 && 
	      strcmp(conn,"s") != 0 &&
	   	  strcmp(conn,"p") != 0	)
	   	{
		printf("Ange koppling[S | P]: ");
		fgets(conn, sizeof(conn), stdin);
		}

	//Antal komponenter:
	printf("Antal komponenter: ");
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF); //rensar upp i stdin
	fgets (str, sizeof(str), stdin);
	count = atoi(str);
	float *array = (float*) malloc(count * sizeof(float));

	//Komponent x i ohm:
	for (i = 0; i < count; i++)
		{
		printf("Komponent %d i ohm: ", i+1);
		fgets (str, sizeof(str), stdin);
		array[i] = atof(str);
		}
	
	//Ersättningsresistans:
	printf("count : %d\n", count);
	printf("conn : %s\n", conn);
	for (i=0;i < 3; i++) 
		{
    	printf("conn %d : %lf\n", i, array[i]);
		}
	

	orig_resistance = calc_resistance(count, conn, array);

	//Effekt:
	current = volt / orig_resistance;
	power   = (calc_power_i(volt, current) + calc_power_r(volt, orig_resistance)) / 2;

	//Erättningsresistanser i E12-serien kopplade i serie:
	count = e_resistance(orig_resistance, res_array);
	
	//Presentera resultaten
	printf("Ersättningsresistans:\n%.1f %s\n", orig_resistance, OMEGA);
	printf("Effekt:\n%.2f W\n", power);
	printf("Ersättningsresistanser i E12-serien kopplade i serie:\n");
	for(i = 0; i < count; i++) 
		{
	        printf("%.2f%s\n", res_array[i], OMEGA);
	    }

	//Avslut...    
    free(res_array);
    free(array);

    return 0;
}





