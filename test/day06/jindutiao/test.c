#include<unistd.h>
#include<stdio.h>
int main()
{
	char buf[101]={'#'};
	int i;
	for(i=1;i<=100;i++)
	{
		printf("%c",buf[i]);
	}
	return 0;
}
