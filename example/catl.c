#include <err2.h>
#include <stdio.h>
#include <stdlib.h>
#include <clambda.h>
#include "ffile.h"

#define foreach(name, array) for (typeof(*array) name; (name = *array); array++)
#define l_foreach(name, array, ...) do { foreach(name, array) { __VA_ARGS__ ;} } while (0)

int main(int argc, char *argv[])
{
	l_withFilesOrStdin(++argv,
		for (int c; (c = getc(file)) != EOF; )
			putchar(c);
		if (ferror(file)) warn("%s", path);
	);
	exit(exitStatus);
}

