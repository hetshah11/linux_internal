#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    struct stat st1;

    stat("code1.c", &st1);

    printf("file size: %lu\n", st1.st_size);
    printf("file inode: %lu\n", st1.st_ino);
    printf("size disc of blocks = %lu\n", st1.st_blksize);
    printf("No. of 512 byte blocks allocated = %d\n", st1.st_blocks);
    printf("Permissions = %o\n", st1.st_mode);
    printf("Owner id = %lu\n", st1.st_uid);
    printf("Group id = %lu\n", st1.st_gid);
    printf("Last modified time = %s\n", ctime(&st1.st_mtime));
    printf("Last accessed time = %s\n", ctime(&st1.st_atime));
    printf("\n");
    return 0;
}

