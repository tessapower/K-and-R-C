#include "fileutils.h"
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void fsize(char* name) {
  struct stat stbuf;

  if (stat(name, &stbuf) == -1) {
    fprintf(stderr, "fsize: can't access %s\n", name);

    return;
  }

  if (S_ISDIR(stbuf.st_mode)) {
    dirwalk(name, fsize);
    printf("\n");
  }

  printf("%s\n", name);
  printf("File size:                              %8ld\n",  stbuf.st_size);
  printf("File serial no:                         %8ld\n",  stbuf.st_ino);
  printf("Time of last access:                    %8ld\n",  stbuf.st_atime);
  printf("Group ID of the file's group:           %8d\n",   stbuf.st_gid);
  printf("Time of last modification:              %8ld\n",  stbuf.st_mtime);
  printf("Time of last status change:             %8ld\n",  stbuf.st_ctime);
  printf("User ID of the file's owner:            %8d\n",   stbuf.st_uid);
  printf("Number of hard links to the file:       %8ld\n",  stbuf.st_nlink);
  printf("Preferred I/O block size for the file:  %8ld\n",  stbuf.st_blksize);
  printf("Number of blocks allocated:             %8ld\n",  stbuf.st_blocks);
  printf("Device ID:                              %8ld\n",  stbuf.st_dev);
  printf("Device type:                            %8ld\n",  stbuf.st_rdev);
  printf("File type:                              %8d\n\n", stbuf.st_mode);
}

#define MAX_PATH 1024

void dirwalk(char* dir, void (*fcn)(char*)) {
  char name[MAX_PATH];
  struct dirent* dp;
  DIR* dfd;

  if ((dfd = opendir(dir)) == NULL) {
    fprintf(stderr, "dirwalk: can't open %s", dir);

    return;
  }

  while ((dp = readdir(dfd)) != NULL) {
    // Skip self and parent
    if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) continue;

    // Handle long paths
    if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name)) {
      fprintf(stderr, "dirwalk: name %s/%s too long", dir, dp->d_name);

    } else {
      sprintf(name, "%s/%s", dir, dp->d_name);

      (*fcn)(name);
    }
  }

  closedir(dfd);
}
