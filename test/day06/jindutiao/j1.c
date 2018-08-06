
#include<unistd.h>
#include<stdio.h>
int main()
{
	int i=0;
	char buf[102]={'#'};
	for(i=1;i<=100;i++)
	{
		buf[i]='#';
		printf("[%-100s][%d%%]\r",buf,i);
		fflush(stdout);
	}
	printf("\n");
}
