#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "letter.h"

/*minued top sub bottom*/

char* usage = "usage : -h help -o operation -m minuend -s subtrahend -d difference ./program";

char* helpstring = "-o \t mathematical operation: add/sub\n-m  \t minued\n-s  \t subtrahend\n-d  \t difference\n";

void print_help(char* missingvalue){
	printf("Error missing %s, see -h flag for help\n", missingvalue);
	return;
}

void copy_arg(char** dest, char* source){
	int len = strlen(source) + 1;
	printf("%s Len is %d\n",source, len);
	*dest = (char*)malloc(len * sizeof(char));
	if ( dest != NULL)
		strcpy(*dest, source);
	*dest[len] = '\0';
	return;
}

int main(int argc, char** argv){
	char* sub = NULL;
	char* min = NULL;
	char* diff = NULL;
	int is_add;
	int sflag =0, mflag =0, dflag =0 ,oflag = 0;
	int option;
	while (( option = getopt(argc, argv, "ho:d:s:m:")) != -1)
	{
		switch(option)
		{
			case 's':
				sflag = 1;
				copy_arg(&sub, optarg);
				printf("Subtrahend assigned to %s\n", optarg);
				break;
			case 'm':
				mflag = 1;
				copy_arg(&min, optarg);
				printf("Minued assigned from default  to %s\n", optarg);
				break;
			case 'd':
				dflag = 1;
				copy_arg(&diff, optarg);
				printf("Difference assigned to %s\n", optarg);
				break;
			case 'o':
				if( strcmp(optarg, "add")==0 ){
					oflag = 1;
					is_add = 1;
				} else if ( strcmp(optarg, "sub")==0){
					oflag = 1;
					is_add = 0;
				} else {
					oflag = 0;
					printf("operation %s is not valid, use add/sub\n", optarg); }
				break;
			case 'h':
				puts(helpstring);
				return 0;
			case '?':
				puts(usage);
				return 1;
		}
	}
	if(sflag == 0){
		print_help("Subtrahend");
		if(sub == NULL)free(sub);
	}
	if(dflag == 0){
		print_help("Difference");
		if(diff == NULL)free(diff);
	}
	if(mflag == 0){
		print_help("Minued");
		if(min == NULL)free(min);
	}
	if(oflag == 0){
		print_help("Operation");
		return 0;
	}

	char l;
	int i;
	for(i = 0; sub[i]; i++){
		printf("letter is %c\n", sub[i]);
	}









	/*free each things here*/
	free(sub);
	free(diff);
	free(min);
	return 0;

	error:
		puts(usage);
}
