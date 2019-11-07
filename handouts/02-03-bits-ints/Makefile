CFLAGS = -Og
CC = gcc

all: show-bytes32 show-bytes64

show-bytes32: show-bytes.c
	$(CC) $(CFLAGS) -m32 show-bytes.c -o show-bytes32

show-bytes64: show-bytes.c
	$(CC) $(CFLAGS) -m64 show-bytes.c -o show-bytes64

clean:
	rm -f *~ *.o show-bytes32 show-bytes64
