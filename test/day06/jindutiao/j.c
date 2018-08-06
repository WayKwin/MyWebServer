#include<unistd.h>
#include<stdio.h>
int main()
{
	int i=0;
	char sym[]="/-\\|";
	char buf[100]={'#'};
	for(i=1;i<=100;i++)
	{
		buf[i]='#';
		printf("[%-100s][%d%%]",buf,i);
		printf("[%c]\r",sym[i%4]);
		fflush(stdout);
		usleep(100000);
	}
	printf("\n");
}
