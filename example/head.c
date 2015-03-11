#include <err2.h>
#include <stdio.h>
#include <stdlib.h>
#include "ffile.h"

static void head(FILE *file, const char *path)
{
	int lines = 0;
	for (int c; lines < 10 && (c = getc(file)) != EOF; lines += c == '\n')
		putchar(c);
	if (ferror(file)) warn("%s", path);
}

int main(int argc, char *argv[])
{
	withFilesOrStdin(++argv, head);
	exit(exitStatus);
}
