CFLAGS=-O3 -std=c99
LIBRARIES=-lm
CC?=gcc
OBJS = Nussinov.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99
debug: all
		
plain: $(OBJS)
	$(CC) Nussinov-wrapper.c -o Nussinov $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)
	$(CC) Nussinov-wrapper.c -o Nussinov.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) Nussinov_verify.o
	$(CC) Nussinov-wrapper.c -o Nussinov.verify $(OBJS) Nussinov_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) Nussinov_verify.o
	$(CC) Nussinov-wrapper.c -o Nussinov.verify-rand $(OBJS) Nussinov_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

Nussinov.o : Nussinov.c
	$(CC) Nussinov.c -o Nussinov.o $(CFLAGS) -c

Nussinov_verify.o : Nussinov_verify.c
	$(CC) Nussinov_verify.c -o Nussinov_verify.o $(CFLAGS) -c

clean:
	rm -f *.o Nussinov Nussinov.check Nussinov.verify Nussinov.verify-rand
