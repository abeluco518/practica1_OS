#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "splitCommand.h"
#define MAX_LEN 4096

int main(){
    char buff[MAX_LEN];
    while(1){
        //Leemos el terminal
        int bytes_readed=read(0,buff,sizeof(buff)-1);

        //Añadimos \0 al final para que funcion el strcmp
        buff[bytes_readed]='\0';
        
        if(strcmp(buff,"SINGLE\n")==0){
            //Leomes el terminal de nuevo
            bytes_readed=read(0,buff,sizeof(buff)-1);
            buff[bytes_readed]='\0';
            
            //Copiamos el proceso
            int proc=fork();
            
            if (proc==0){//Si es el hijo ejecutamos el comando

                
                char** argv;
                argv=split_command(buff);
                execvp(argv[0],argv);
                _exit(1);
            }
            else{//si es el padre espera
                wait(NULL);

            }
        }
        else if (strcmp(buff,"CONCURRENT\n")==0){

        }
        else if (strcmp(buff,"PIPED\n")==0){

        }
        else if(strcmp(buff,"EXIT\n")==0){
            break;
        }
    }

}