#include "qsort.h"


static void (*pivot)(int);
static int (*comp)(int);
static void (*swap)(int,int);


static void
qs(int a, int b)
{
	int a2, b2;

	pivot(a);
	a2= a+1; b2= b;
	do {
		if (!comp(b2)) b2--;
		else {
			while (a2 < b2){
				if (comp(a2)) a2++;
				else  {
					swap(a2++, b2--);
					goto next;
				}
			}
			goto pivot;
		}
next:
	} while(a2 <= b2);
	if (a == b2) goto inorder;
pivot:
	swap(a, b2);
	if (b2 -a >2) qs(a, b2-1);
inorder:
	if (b- b2 >2) qs(b2+1, b);
}



void
qqsort(int a, int b, void (*p)(int), int (*c)(int), void (*s)(int, int))
{
	pivot= p;
	comp= c;
	swap= s;
	qs(a,b);
}


