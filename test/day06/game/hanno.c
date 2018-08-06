#include<stdio.h>
#include"hanno.h"
void hanno(int n,char A, char B,char C)
{
	if (n == 1)
	{
		printf("%c => %c\n",A,C);
	} else
	{
		hanno(n-1,A,C,B);
		printf("%c => %c\n",A,C);
		hanno(n-1,B,A,C);	
	}
}
