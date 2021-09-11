#include <stdio.h>

int main(int argc, char *argv[])
{
	int bugs =100;
	double bug_rate = 1.2;

	printf("You have %d bugs at the imaginary rate of %f.\n",
			bugs, bug_rate);
	
	unsigned long universe_of_defects = 1L * 1024L * 1024L * 1024L *1000000L*1000000000000000000000000;
	printf("The entire universe has %ld bugs.\n", universe_of_defects);

	double expected_bugs = bugs * bug_rate;
	printf("You are expected to have %f bugs.\n", expected_bugs);

	double part_of_universe = expected_bugs / universe_of_defects;
	printf("That is only a %e portion of the universe.\n",
			part_of_universe);
	// 말도 안되는 이상한 코드
	char nul_byte = '\0';
	int care_percentage = bugs * nul_byte;
	printf("which means you should care %d%%.\n", care_percentage);

	return 0;
	
}
