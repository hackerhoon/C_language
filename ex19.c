#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

void test_debug()
{
	// \n is not needed.
	debug("I have Brown Hair.");

	// transfer argument like printf
	debug("I an %d years old.", 37);
}

void test_log_err()
{
	log_warn("You can safely ignore this.");
	log_warn("Maybe consider looking at: %s.", "\etc\passwd");
}

void test_log_info()
{
	log_info("Well I did something mundane.");
	log_info("It happened %f times today.", 1.3f);
}

int test_check(char *file_name)
{
	FILE *input = NULL;
	char *block = NULL;

	block = malloc(100);
	check_mem(block);//should run

	input = fopen(file_name, "r");
	check(input, "Failed to open %s.", file_name);
}
