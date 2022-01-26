#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
int x, fd[2];
char buffer[10];
pid_t pa, pb;
x = 4;
pipe(fd);
if((pa = fork()) == 0){// proceso Hijo A
  buffer[0]= 'h';
  buffer[1]= 'o';
  buffer[2]= 'l';
  buffer[3]= 'a';
  write(fd[1],buffer,4);
  printf("PA-> BUFFER:%s P:%d PP:%d \n",buffer,getpid(),getppid());
 
}
else{// Proceso Padre - Main
  waitpid(pa,NULL,0);
  read(fd[0],buffer,4);
  printf("PM-> BUFFER:%s P:%d PP:%d \n",buffer,getpid(),getppid());
}

return 0;
}
