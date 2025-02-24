#include <stdio.h>
#include <stdlib.h>

#define STR_LENGTH 100

int main(int argc, char *argv[]) {

    	FILE *fp = NULL;
        char buffer[STR_LENGTH];


    if (argc == 0) 
    exit(0);    
    for (int i = 1; i < argc; i++) {

        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            perror("wcat");
			printf("wcat: cannot open file\n");
			return 1;
        }

        while(fgets(buffer,STR_LENGTH,fp) != NULL){
            printf("%s",buffer);
        }
        fclose(fp);
    }
    return 0;


}


// #include <stdio.h>
// #include <stdlib.h>

// #define STR_LENGTH 100

// int main ( int argc , char * argv[])
// {
// 	FILE *f = NULL;
// 	char str[STR_LENGTH] ;
// 	if (argc == 0)
// 	 exit(0) ;
// 	for(int i =1 ; i< argc ; i++)
// 	{
// 		f = fopen(argv[i],"r");
// 		if(f == NULL)
// 		{
// 			printf("wcat: cannot open file\n");
// 			exit(1);
// 		}
// 		while (fgets(str,STR_LENGTH,f) != NULL)
// 		{
// 			printf("%s",str);
// 		}
// 		fclose(f);
// 	}
// 	exit(0);

// }