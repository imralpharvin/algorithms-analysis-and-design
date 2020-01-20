CC          =	gcc

CFLAGS      =	 -Wall -g -std=c11

main: main.c P11.c P12.c P21.c P22.c
	$(CC) $(CFLAGS) main.c P11.c P12.c P21.c P22.c -lm -Iinclude -o main

clean:
	rm main
