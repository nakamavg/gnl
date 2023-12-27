#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main()
{
	int fd;
	char buf[255];
	int char_read;
	int index = 0;

	fd = open("test.txt", O_RDONLY);
	while(char_read = read(fd, buf,5))
	{
		
		buf[char_read] = '\0';
		printf("buffer-> %s \n", buf);
	}
	return (0);
}