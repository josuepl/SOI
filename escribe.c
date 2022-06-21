#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
 int fd; //Descriptor de archivo
 char buffer[10];
 fd = open("datos.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
 printf("Ingresa la cadena a almacenar: \n");
 scanf("%*c%[^\n]",buffer);
 //scanf("%s",buffer);
 //fgets(buffer,10,stdin);
 printf("La cadena es: %s \n",buffer);
 //printf("La cadena es: %s \n",buffer);
 printf("fd: %d TamCad:%d \n",fd,sizeof(buffer));
 write(fd, &buffer, sizeof(buffer));
 close(fd);
 return 0;
}
