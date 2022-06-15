#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

 int pid;
 int res = 0, a = 4, b = 7;
 //PROCESO PADRE
 // fork -> 0 cuando se crea el proceso de manera erronea
 // fork -> >0 cuando se creo de manera exitosa

 //PROCESO HIJO
 // fork -> 0 el proceso hijo se encuentra ejecutandose
 // fork -> <0 el proceso se encuentra finalizado

if(( pid = fork()) == 0){// HIJO
 res = a + b;
 printf("Hola, HIJOA: PID:%d, PPID:%d, FPID:%d \n",getpid(),getppid(),pid);
 printf("A-Resultado: %d \n",res);
}
else{//PADRE
sleep(1);
 if(( pid = fork()) == 0){// HIJO
  res = a * b;
  printf("Hola, HIJOB: PID:%d, PPID:%d, FPID:%d \n",getpid(),getppid(),pid);
  printf("B-Resultado: %d \n",res);
 }
 else{//PADRE
   sleep(1);
   res = a - b;
   printf("Hola, PADRE: PID:%d, PPID:%d, FPID:%d \n",getpid(),getppid(),pid);
   printf("P-Resultado: %d \n",res);
  }
 }
 
}
