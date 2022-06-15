#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
pid_t p1, p2, p3, p4, p5, p6;
int estado;

if((p1 = fork())== 0){// HIJO1
 //sleep(1);
printf("(1)-> HIJO 1-> PID:%d, PPID:%d \n",getpid(),getppid());
}
else{ //PADRE MAIN
 //sleep(1);
 waitpid(p1,&estado,0);
 if((p3 = fork())== 0){// HIJO3
  if((p2 = fork()) == 0){//HIJO2
   printf("(2)-> HIJO 2-> PID:%d, PPID:%d \n",getpid(),getppid());
  }
  else{//PADRE H3
   waitpid(p2,&estado,0);
   printf("(3)-> HIJO 3-> PID:%d, PPID:%d \n",getpid(),getppid());
  }
 
 } 
 else{//PADRE MAIN
  waitpid(p3,&estado,0);
  if((p5 = fork())== 0){//HIJO5
   if((p4 = fork())== 0){//HIJO4
     printf("(4)-> HIJO 4-> PID:%d, PPID:%d \n",getpid(),getppid());
   }
   else{//PADRE H5
    waitpid(p4,&estado,0);
    printf("(5)-> HIJO 5-> PID:%d, PPID:%d \n",getpid(),getppid()); 
   }
  }
  else{//PADRE MAIN
   waitpid(p5,&estado,0);
   if((p6 = fork()) ==0){//HIJO 6
     printf("(6)-> HIJO 6-> PID:%d, PPID:%d \n",getpid(),getppid());
   }
   else{//PADRE MAIN
     waitpid(p6,&estado,0);
     printf("(7)-> PADRE-> PID:%d, PPID:%d \n",getpid(),getppid());  
   }
  }
 }
} 

return 0;
}
