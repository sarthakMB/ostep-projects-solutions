#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

    if(argc == 1){
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }

    // printf("%d\n", argc);

    if(argc == 2){
        char line[1024];
        while(fgets(line, sizeof(line), stdin)){
            if(strstr(line, argv[1]) != NULL){
                printf("%s", line);
            }
        }
    }

    for(int i = 2; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        if(fp == NULL){
            // perror("Error opening file");
            printf("wgrep: cannot open file\n");
            return 1;
        }

        char line[1024];    
        while(fgets(line, sizeof(line), fp)){
            if(strstr(line, argv[1]) != NULL){
                printf("%s", line);
            }
        }

        fclose(fp);
    }

    return 0;
} 