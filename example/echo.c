#include <stdio.h>

int main(int argc, char *argv[])
{
	const char *formatOthers = " %s";
	const char *formatFirst = &formatOthers[1];
	for (const char *format = formatFirst; *++argv; format = formatOthers)
		printf(format, *argv);
	putchar('\n');
	return 0;
}
