#include <stdio.h>

int main(int argc, char * argv[])
{
	int i = 25;
	while (i <= 25 && i >=0) {
		printf("%d", i);
		i--;
	}
	printf("============\n");
	printf("i: %d",i);
	return 0;
}
