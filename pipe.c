#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>

int main(){
int x, fd[2],i;
// fd es descriptor de archivos -> referencia a un espacio o una direccion
// dentro del SO fd[0]-> Leer, read || fd[1]-> Escribir, write
char buffer[10];
pid_t pa, pb, pa1;
x = 4;
pipe(fd);
if((pa = fork()) == 0){// proceso Hijo A
  x = 10 + x;
  buffer[0]= 'H';
  buffer[1]= 'O';
  write(fd[1],buffer,2);
  printf("PA-> BUFFER:%s P:%d PP:%d \n",buffer,getpid(),getppid());
  if((pa1 = fork()) == 0){//NIETO
   read(fd[0],buffer,2);
   buffer[2]= 'L';
   buffer[3]= 'A';
   write(fd[1],buffer,4);
  }
  else{
   waitpid(pa1,NULL,0);
  }
 //printf("PA ->El valor de x es :%d \n",x);
}
else{// Proceso Padre - Main
 x = -8 + x;
  waitpid(pa,NULL,0);
  read(fd[0],buffer,4);
  char aux[4];
  for( i = 0; i <= 3; i++){
    aux[i] = tolower((unsigned char)buffer[i]);
    printf("C:%c-",aux[i]);
  }
  printf("\n");
  printf("AUX:%s \n",aux);
  write(fd[1],aux,4);
 //printf("PADRE ->El valor de x es :%d \n",x);

  if((pb = fork()) == 0 ){// Proceso Hijo B
   x = x + 10;
 
   read(fd[0],buffer,4);
   buffer[4]= 'm';
   buffer[5]= 'u';
   buffer[6]= 'n';
   buffer[7]= 'd';
   buffer[8]= 'o';
   write(fd[1],buffer,9);
  
 printf("PB ->El valor de x es :%d \n",x);

  }else{// Proceso Padre - Main
   waitpid(pb,NULL,0);
   read(fd[0],buffer,9);
   printf("PM-> BUFFER:%s P:%d PP:%d \n",buffer,getpid(),getppid());
   //printf("PADRE ->El valor de x es :%d \n",x);

  }
}

return 0;
}
