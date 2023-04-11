#include <stdio.h>
#include <stdlib.h>
#include "qsort.h"

void show();


struct data{
	char *s;
	double c;
	double m;
	int index;
	};

struct data data[] ={
{ "Mercedes", 299.0, 80.6 },
{ "VW", 200.0, 83.0 },
{ "BMW", 161.0, 66.4 },
{ "Biontech", 133.8, 35.6 },
{ "Allianz", 85.9, 89.0 },
{ "Siemens", 80.1, 117.3 },
{ "BASF", 72.0, 44.0 },
{ "SAP", 68.3, 133.9 },
{ "Deutsche Post", 65.7, 51.1 },
{ "Eon", 60.9, 27.2 },
{ "Porsche Holding", 59.3, 8.8 },
{ "Airbus", 54.8, 97.5 },
{ "Dt. Telekom", 54.3, 105.7 },
{ "Porsche", 52.4, 52.3 },
{ "Merck", 39.7, 23.0 },
{ "K+S", 38.8, 4.3 },
{ "Munich Re.", 38.1, 45.8 },
{ "Vonovia", 34.8, 18.3 },
{ "Dt. Bank", 30.8, 23.8 },
{ "Daimler Truck", 30.5, 26.2 },
{ "Adidas", 27.6, 26.2 },
{ "Fresenius", 23.6, 14.0 },
{ "Heindelberg Cement", 22.9, 12.7 },
{ "Siemens Health.", 22.5, 56.8 },
{ "LEG Immo.", 22.4, 5.1 },
{ "Henkel", 21.3, 29.3 },
{ "Covestro", 21.0, 7.8 },
{ "Continental", 18.9, 14.5 },
{ "Hannover Rück", 16.0, 21.8 },
{ "Deutsche Börse", 15.7, 31.6 },
{ "Infineon", 15.2, 44.6 },
{ "Bayer", 13.0, 56.6 },
{ "FMC", 12,6, 10.7 },
{ "Evonik", 9.7, 9.7 },
{ },
};



		
double pivot_value;

void
pivot(int i)
{
	int ii;

	ii= data[i].index;
	
	pivot_value= data[ii].c / data[ii].m;
}



int 
comp(int i)
{
	int ii;
//	static int n;
	ii= data[i].index;
	return data[ii].c / data[ii].m < pivot_value;
}



void
swap(int a, int b)
{
	int h;
	static int n;

	printf("swap %d %d mit %d\n", ++n, a, b);
	h= data[a].index;
	data[a].index= data[b].index;
	data[b].index= h;
}


void
show()
{
	int i, ii;
	for(i=0; data[i].s; i++){
		ii= data[i].index;
		printf("%d %d %s, %f, %f, %f\n", i, ii, 
		data[ii].s, data[ii].c, data[ii].m,
			data[ii].c / data[ii].m);
	}
}

	
int 
main()
{

	int i;


	for(i=0; data[i].s; i++){
		data[i].index= i;
	}
	show();
	printf("\n");

	qqsort(0, i-1, pivot, comp, swap);

	show();

	return 0;
}



