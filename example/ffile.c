#include "ffile.h"
#include "err2.h"

void withFile(const char *path, const char *mode, processFile processFile)
{
	FILE *file = fopen(path, mode);
	if (file) {
		processFile(file, path);
		fclose(file);
	} else warn("%s", path);
}

void withFilesOrStdin(char *const paths[], processFile processFile)
{
	if (!*paths) processFile(stdin, "<stdin>");
	else for (; *paths; paths++) withFile(*paths, "r", processFile);
}
