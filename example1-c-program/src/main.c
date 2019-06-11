#include <config.h>
#include <stdio.h>
int main (void)
{
	puts ("Hello World!");
	puts ("This is " PACKAGE_STRING ".");
	printf("MYID:%d\n",MYID);
	return 0;
}
