#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <string.h>


int suma(){
 int x = 4, y =5;
 return x+y;
}

int resta(){
 int x = 5, y = 1;
 return x-y;
}

int fibo(){
 int x = 4;
 int fibo = 0;
 int index;
 for(index = 0; index < 4; index++){
  fibo = fibo + index;
 }
return fibo;
}


int main(int argc, char *argv[]){
 int sock, tam, n;
 socklen_t origenTam;
 struct sockaddr_in origen;
 struct sockaddr_in servidor;
 char buffer[1024];
 
 if(argc < 2){
  printf("Error en la cantidad de parametros, se requiere establecer un puerto \n");
  exit(0);
  return 0;
 }
 
 sock = socket(AF_INET, SOCK_DGRAM, 0);
 tam = sizeof(servidor);
 bzero(&servidor,tam);
 servidor.sin_family = AF_INET;
 servidor.sin_addr.s_addr = INADDR_ANY;
 servidor.sin_port = htons(atoi(argv[1]));
 if(bind(sock,(struct sockaddr *)&servidor, tam) < 0){
  printf("Error de Conexion \n");
  return 0;
 }
 origenTam = sizeof(struct sockaddr_in);
 printf("SERVIDOR ACTIVO ------- ESPERA A RECIBIR MENSAJES--------\n");
 while(1){
  n = recvfrom(sock,buffer,1024,0,(struct sockaddr *)&origen,&origenTam);
  if(n < 0){
   printf("error recibir datos \n");
   exit(0);
  }
  write(1, "Se ha recibido un datagrama: ",28);
  write(1,buffer,n);
  int aux = 0;
  //printf("bufffer: %s aux: %d \n",buffer, aux);
  if(strcmp(buffer,"suma") == 10){
   printf("Ingreso a la operacion de suma \n");
   aux = suma();
   printf("SUMA: %d \n",aux);
  }
  else if(strcmp(buffer,"resta") == 10){
   write(1,"Ingreso a la operacion de resta \n",34);
   aux = resta();
   printf("RESTA: %d \n",aux);
  }
  else if(strcmp(buffer,"fibo") == 10){
   write(1,"Ingreso a la operacion de fibo \n",33);
   aux = fibo();
   printf("FIBO: %d \n",aux);
  }
  char res[10];
  res[0]  = aux + '0';
  res[1] = '\n';
  n = sendto(sock,"Servidor: He recibido tu msg \n",31,0, (struct sockaddr *)&origen, origenTam);
  if(n < 0){
   printf("error al enviar  datos \n");
   exit(0);  
  }
  if(aux != 0){ 
   char msg[100]= "El resultado es: ";
   strcat(msg,res);
   aux = strlen(msg);
   printf("SALIDA: %s tam: %d \n",msg,aux);
   n = sendto(sock,msg,aux+1,0, (struct sockaddr *)&origen, origenTam);
   if(n < 0){
    printf("error al enviar  datos \n");
    exit(0);  
   } 
  }
 }
 return 0;
 
}
