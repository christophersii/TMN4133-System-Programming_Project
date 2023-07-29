#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "FileOperation.c"
#include "DirectoryOperations.c"
#include "KeyLoggerOperation.c"

int main(int argc, char *argv[]){
    char *function_name=argv[1];
    char *function_name2= argv[2];
    char *filename=argv[3];
    char *path=argv[4];

    while (strcmp(argv[1], "1") && strcmp(argv[1], "2") && strcmp(argv[1], "3") != 0){
        printf("Invalid option. Please refer man and enter your option again.\n");
        exit(1);
    }   

    while (strcmp(argv[1], "1") ==0 && strcmp(argv[2], "1") && strcmp(argv[2], "2") && strcmp(argv[2], "3") && strcmp(argv[2], "4") != 0){
        printf("Invalid sub-option. Please refer man and enter your option again.\n");
        exit(1);
    }

    while (strcmp(argv[1], "2") ==0 && strcmp(argv[2], "1") && strcmp(argv[2], "2") && strcmp(argv[2], "3") && strcmp(argv[2], "4") != 0){
        printf("Invalid sub-option. Please refer man and enter your option again.\n");
        exit(1);
    }
          
    if(strcmp(function_name,"3")==0){
        KeyLogger();   
    }

    if(strcmp(function_name,"2")==0){

        if(strcmp(function_name2,"3")==0){
                get_current_working_directory();
        }
        else if(strcmp(function_name2,"4")==0){
                list_current_directory();
        }
    }
    
    if(strcmp(function_name,"1")==0){
        if(strcmp(function_name2,"1")==0){
            createOrOpenFile(filename,path);
        }
        else if(strcmp(function_name2,"3")==0){
            readAndPrintFile(filename,path);
        }
        else if(strcmp(function_name2,"4")==0){
            removeFile(filename,path);
        }
    }
    
    if(strcmp(function_name,"2")==0){
            if(strcmp(function_name2,"1")==0){
                create_directory(filename,path);
            }
            else if(strcmp(function_name2,"2")==0){
                delete_directory(filename,path);
            }
        }

    if(strcmp(function_name,"1")==0){
        if(strcmp(function_name2,"2")==0){
            mode_t mode = (mode_t)strtoul(argv[5], NULL, 8);
            changePermission(filename,path,mode);
        }
    }

    return 0;

}