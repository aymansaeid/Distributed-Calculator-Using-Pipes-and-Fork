CC = gcc
CFLAGS = -Wall -O2

all: calculation sum2numbers subtract2numbers multiply2numbers divide2numbers saver

calculation: calculation.c
	$(CC) $(CFLAGS) calculation.c -o calculation

sum2numbers: sum2numbers.c
	$(CC) $(CFLAGS) sum2numbers.c -o sum2numbers

subtract2numbers: subtract2numbers.c
	$(CC) $(CFLAGS) subtract2numbers.c -o subtract2numbers

multiply2numbers: multiply2numbers.c
	$(CC) $(CFLAGS) multiply2numbers.c -o multiply2numbers

divide2numbers: divide2numbers.c
	$(CC) $(CFLAGS) divide2numbers.c -o divide2numbers

saver: saver.c
	$(CC) $(CFLAGS) saver.c -o saver

clean:
	rm -f calculation sum2numbers subtract2numbers multiply2numbers divide2numbers saver results.txt
