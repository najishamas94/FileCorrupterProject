#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

char * buffer;

int main()
{
	int ret, fd;
	buffer = malloc(sizeof(char *))
	char stringToSend[buffer];
	printf("Initializing module test...]\n");
	fd = open("/dev/filec", O_RDWR);
	if(fd < 0)
	{
		perror("Failed to open device");
		return errno;
	}
	printf("enter a string\n");
	scanf("%[^\n]%*c", stringToSend);
	printf("Writing message to device [%s]. \n", stringToSend);
	ret = write(fd, stringToSend, strlen(stringToSend));
	if(ret < 0)
	{
		perror("failed to write the message to the device");
		return errno;
	}
	printf("End of program\n");
	return 0;

}