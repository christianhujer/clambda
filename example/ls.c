#include <dirent.h>
#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int exitStatus;

#define WARN(fmt, ...) do { warn(fmt, ##__VA_ARGS__); exitStatus = 1; } while (0)

void lsdir(const char *path)
{
	DIR *dir = opendir(path);
	if (!dir) {
		warn("%s", path);
		exitStatus = 1;
		return;
	}
	struct dirent *dirent;
	while ((dirent = readdir(dir)))
		printf("%s\n", dirent->d_name);
	if (errno) {
		warn("%s", path);
		exitStatus = 1;
	}
	closedir(dir);
}

void ls(const char *path)
{
	struct stat stat;
	int fd = open(path, 0);
	if (fd < 0 || fstat(fd, &stat)) {
		warn("%s", path);
		exitStatus = 1;
		return;
	}
	close(fd);

	if (S_ISDIR(stat.st_mode)) {
		lsdir(path);
	} else {
		printf("%s\n", path);
	}
}

int main(int argc, char *argv[])
{
	if (!*++argv) ls(".");
	else while (*argv) ls(*argv++);
	exit(exitStatus);
}
