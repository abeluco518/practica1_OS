#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc,char* argv[]){
    //usamos open y no fopen ya que estamos en sistemas operativos (accediendo al kernell)
    int fd = open(argv[1], O_WRONLY | O_CREAT , 0644); //o create serveix per crear l'arxiu si no existeic
    //Manejamos el error
    if(fd==-1){
        //manejo de error
    }
    int *buffer=mallox(1000*sizeof(int));
    for(int i=0; i<100000;i+=1000){
        for(int j;j<1000;++j){
            buffer[j]=(i+j)*(i*j);
        }
        //write(puntero archivo, puntero del dato que queremos escribir, tamaño de lo que escribimos (buffer))
        write(fd,buffer,sizeof(int));
    }
    close(fd);//buenas practicas

}