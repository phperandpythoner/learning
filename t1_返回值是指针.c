#include <stdio.h>

int *fun()
{
	int a;
	return &a;
}

int main()
{
	int *p = NULL;
	p = fun();
	*p = 100;
	printf("*p=%p\n", *p);	

	return 0;
}
