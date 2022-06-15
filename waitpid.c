#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
pid_t pa, pb, pc;
int estado;

if((pa = fork())== 0){// HIJOA
 //sleep(1);
 printf("HIJOA-> PID:%d, PPID:%d \n",getpid(),getppid());
}
else{ //PADRE MAIN
 //sleep(1);
 waitpid(pa,NULL,0);
 if((pb = fork())== 0){// HIJOB
  printf("HIJOB-> PID:%d, PPID:%d \n",getpid(),getppid());
 } 
 else{
  //sleep(2);
  //waitpid(pa,&estado,0);
  waitpid(pb,&estado,0);
  printf("PADRE-> PID:%d, PPID:%d \n",getpid(),getppid());  
 }
}

return 0;
}
