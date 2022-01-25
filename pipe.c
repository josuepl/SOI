#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
int x;
pid_t pa, pb;
x = 4;
if((pa = fork()) == 0){// proceso Hijo A
  printf("PA-> x;%d P:%d PP;%d ",x,getpid(),getppid());
}
else{// Proceso Padre - Main
  printf("PM-> x;%d P:%d PP;%d ",x,getpid(),getppid());
}

return 0;
}
