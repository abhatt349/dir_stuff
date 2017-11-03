#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>

//function to return size of directory
int dir_size() {
	struct stat a;
	DIR *p;
	struct dirent *d;
  int size;
  p = opendir("./");
	while ((d = readdir(p)) != NULL) {
		stat(d->d_name, &a);
		size += a.st_size;
	}
	closedir(p);
	return size;
}

//function to go through directories
void dir_read() {
  DIR *p;
  struct dirent *d;
  p = opendir("./");
  printf("Directories:\n");
	while ((d = readdir(p)) != NULL) {
		if (d->d_type == DT_DIR) {
			printf("\t%s\n", d->d_name);
		}
	}
	rewinddir(p);
  printf("Regular files:\n");
  while ((d = readdir(p)) != NULL) {
		if (d->d_type != DT_DIR) {
			printf("\t%s\n", d->d_name);
		}
  }
  closedir(p);
}

//testing function
int main() {
  printf("Stats for dir:\n");
  printf("Dir Size: %d bytes\n", dir_size());
  dir_read();
  return 0;
}
