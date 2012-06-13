#include<stdio.h>

int add(int a, int b)
{
	return a+b;
}

int main()
{
	int i=10;
	int j=20;
	int sum=0;
	sum=add(i,j);
	printf("sum=%d\n",sum);
	return 0;
}
