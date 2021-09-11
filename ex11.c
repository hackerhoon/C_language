#include <stdio.h>

int main(int argc, char *argv[])
{
	int numbers[4] = { 0 };
	char name[4] = {'a'};
	//먼저 초기화된 배열을 보여줌
	printf("numbers: %d %d %d %d\n", numbers[0],numbers[1],numbers[2],numbers[3]);

	printf("name each: %c %c %c %c\n", name[0],name[1],name[2],name[3]);

	printf("name: %s\n", name);

	//numbers 배열을 셋업한다.
	numbers[0] = "a";
	numbers[1] = "b";
	numbers[2] = "c";
	numbers[3] = "d";

	//name 배열을 셋업한다.
	name[0] = 'Z';
	name[1] = 'e';
	name[2] = 'd';
	name[3] = '\0';
	//그다음에 셋업된 배열의 내용을 출력한다.
	

	printf("numbers: %d %d %d %d\n", numbers[0],numbers[1],numbers[2],numbers[3]);

	printf("name each: %c %c %c %c\n", name[0],name[1],name[2],name[3]);

	
	printf("name: %s\n", name);

	char *another ="Zed";
	
	printf("another: %s\n", another);
		
	printf("another: %c %c %c %c\n", another[0],another[1],another[2],another[3]);
	
	return 0;
}
