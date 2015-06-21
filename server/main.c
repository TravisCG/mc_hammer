#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int main(int argc, char **argv){
   int s, client, r;
   struct sockaddr_rc local = {0}, remote = {0};
   socklen_t opt = sizeof(remote);

   s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
   if(s < 0){
      printf("Socket error\n");
      return(EXIT_FAILURE);
   }

   local.rc_family  = AF_BLUETOOTH;
   local.rc_bdaddr  = *BDADDR_ANY;
   local.rc_channel = (uint8_t) 1;

   r = bind(s, (struct sockaddr*) &local, sizeof(local));
   if(r < 0){
      printf("Bind error:%d\n", errno);
      return(EXIT_FAILURE);
   }

   r = listen(s, 1);
   if(r < 0){
      printf("Listen error:%d\n", errno);
   }

   client = accept(s, (struct sockaddr*) &remote, &opt);

   return(EXIT_SUCCESS);
}
