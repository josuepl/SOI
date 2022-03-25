#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
int c11[2], c12[2], c21[2],c22[2];
char matrizA[2][3], matrizB[2][3];
char resultado[5];
pid_t h00,h01,h10,h11;

// Tuberias
pipe(c11);
pipe(c12);
pipe(c21);
pipe(c22);

// ingresar datos
matrizA[0][0]= 'a';
matrizA[0][1]= 'b';
matrizA[0][2]='\0';
matrizA[1][0]= 'c';
matrizA[1][1]= 'd';
matrizA[1][2]='\0';

matrizB[0][0]= 'f';
matrizB[0][1]= 'g';
matrizB[0][2]='\0';
matrizB[1][0]= 'h';
matrizB[1][1]= 'i';
matrizB[1][2]='\0';

printf("matriz A: \n [%s] \n [%s]\n",matrizA[0], matrizA[1]);
printf("matriz B: \n [%s] \n [%s]\n",matrizB[0], matrizB[1]);
// --.--
write(c11[1],matrizA[0],1);
write(c11[1],matrizB[0],1);

if((h00 = fork()) == 0){//hijo
 char aux[2];
 read(c11[0],aux,2);
 printf("HIJO00: %s PID:%d, PPID:%d\n",aux,getpid(),getppid());
 write(c11[1],aux,2);
}
else{// padre
 sleep(3);
 printf("PADRE: -----");
 read(c11[0],resultado,2);
 printf("Resultado: %s \n",resultado);
}

}
