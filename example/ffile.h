#include <stdio.h>

#define l_withFilesOrStdin(paths, ...) do { withFilesOrStdin(paths, l((FILE *file, const char *path), __VA_ARGS__ )); } while (0)

typedef void (*processFile)(FILE *, const char *);

extern void withFile(const char *path, const char *mode, processFile);
extern void withFilesOrStdin(char *const paths[], processFile);
