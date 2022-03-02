#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
 int fd;
 char buffer;
 fd = open("datos.txt",O_RDONLY);

 //validar si el archivo existe
 if(fd != -1){
 while(read(fd,&buffer,sizeof(buffer)!= 0)){
  printf("%c",buffer);
  }
 printf("\n");
 }

 close(fd);
 return 0;
}
