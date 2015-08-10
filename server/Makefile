CC=gcc
CFLAGS=-Wall -W -pedantic
CLIBS=-lbluetooth

mc_server: main.o
	$(CC) $(CFLAGS) *.o $(CLIBS) -o mc_server
main.o: main.c
	$(CC) $(CFLAGS) main.c -c

clean:
	rm *.o mc_server
