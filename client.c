
#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );
  while(1){
    char response[BUFFER_SIZE];
    printf("Type Message to Server:");
    fgets(response,BUFFER_SIZE,stdin);
    response[strlen(response)-1]='\0';
    write(to_server,response,strlen(response));
    char data[BUFFER_SIZE];
    read(from_server,data,BUFFER_SIZE);
    printf("The server says %s\n",data);
  }
}