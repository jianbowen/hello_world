CFLAGS=-DDEBUG -I../include -Iinclude

export CFLAGS

all:
	make -C rawlist
	make -C userlist
	make -C mydatabase
	make -C server
	make -C client
	make -C obj
clean:
	rm obj/*.o server_app client_app
