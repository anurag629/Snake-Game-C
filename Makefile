$(CC) = gcc

final: main.o drawBox.o getSize.o random.o key.o checkPosition.o
		$(CC) main.o drawBox.o getSize.o random.o key.o checkPosition.o -o snake

main.o: main.c header.h
		$(CC) -c main.c

drawBox.o: drawBox.c header.h
		$(CC) -c drawBox.c

getSize.o: getSize.c header.h
		$(CC) -c getSize.c
		
random.o: random.c header.h
		$(CC) -c random.c

key.o: key.c header.h
	$(CC) -c key.c

checkPosition.o: checkPosition.c header.h
	$(CC) -c checkPosition.c

clean:
	rm *.o snake
