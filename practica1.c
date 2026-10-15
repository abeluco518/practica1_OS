#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1000

int main(){
    char* buff[MAX_LEN];
    while(1){
        read(0,buff,sizeof(buff));
        
        if(strcmp(buff,"SINGLE")==0){
            int n=fork();
            if (n==0){//Si es el hijo
                execvp();
            }
            else{//si es el padre

            }
        }
        else if (strcmp(buff,"CONCURRENT")==0){

        }
        else if (strcmp(buff,"PIPED")==0){

        }
        else if(strcmp(buff,"SINGLE")==0){

        }
    }

}