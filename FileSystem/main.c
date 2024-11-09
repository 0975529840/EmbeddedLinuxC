#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <sys/sysmacros.h>
int main(int argc, char * argv[])
{
	struct stat statbuf;
	if (argc != 2)
	{
		fprintf(stderr, "Usage %s <pathname>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stdin, "Access succesfull\n");
	}
	
	if (-1 == stat(argv[1],&statbuf))
	{
		perror("lstart");
		exit(EXIT_FAILURE);
	}
	printf("Device file : major = %d, minor = %d\n", major(statbuf.st_dev),minor(statbuf.st_dev));
	printf("File type:");
	switch(statbuf.st_mode & S_IFMT)
	{
		case S_IFBLK:
			printf("block device\n");
			break;
		case S_IFCHR:
			printf("character device\n");
			break;
		case S_IFDIR:
			printf("directory\n");
			break;
		case S_IFIFO:
			printf("FIFO/pipe\n");
			break;
		case S_IFLNK:
			printf("symlink\n");
			break;
		case S_IFREG:
			printf("regular file\n");
			break;
		case S_IFSOCK:
			printf("socket\n");
			break;
		default:
			printf("unknown file\n");
			break;
	}
	printf("Inode number : %lx\n",statbuf.st_ino);
	printf("File type and mode: %x\n",statbuf.st_mode);
	printf("Size of file: %ld\n", statbuf.st_size);
	printf("Last status change:       %s",ctime(&statbuf.st_ctime));
	printf("Last file access:         %s",ctime(&statbuf.st_atime));
	printf("Last file modification:   %s",ctime(&statbuf.st_mtime));
	
	exit(EXIT_SUCCESS);
}
