#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#define BUFFERSIZE 256

char* usage = "usage : -s subtrahend -m minuend ./program"

int main(int argc, char** argv){
	int subflag;
	int minflag;

	int return_code = 0;
	while (( option = getopt(argc, argv, "ip:")) != -1)
	{
		switch(option)
		{
			case 's':
				
				printf("");
			break;
			case 'm':
				/*parse the port option*/
				fprintf("Port assigned from default  to %s", optarg)
			case '?':
				puts(usage);
				return 1;
		}
	}

	return 0;
}
