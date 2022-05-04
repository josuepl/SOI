#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){

printf("Hola Mundo: PID:%d, PPID:%d\n",getpid(),getppid());

}
