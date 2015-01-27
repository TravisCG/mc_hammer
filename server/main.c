#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int main(int argc, char **argv){
   int s, client;
   struct sockaddr_rc local = {0}, remote;
   socklen_t opt = sizeof(remote);

   s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
   local.rc_family  = AF_BLUETOOTH;
   local.rc_bdaddr  = *BDADDR_ANY;
   local.rc_channel = (uint8_t) 1;

   bind(s, (struct sockaddr*) &local, sizeof(local));

   listen(s, 1);

   client = accept(s, (struct sockaddr*) &remote, &opt);

   return(EXIT_SUCCESS);
}
