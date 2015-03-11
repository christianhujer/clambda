#include <err2.h>
#include <stdio.h>
#include <stdlib.h>
#include "ffile.h"

static void cat(FILE *file, const char *path)
{
	for (int c; (c = getc(file)) != EOF; )
		putchar(c);
	if (ferror(file)) warn("%s", path);
}

int main(int argc, char *argv[])
{
	withFilesOrStdin(++argv, cat);
	exit(exitStatus);
}
