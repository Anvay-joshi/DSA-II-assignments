EXE = exe
CFALGS = -Wall -g 
#MEMFALGS = -fsanitize=address
CC = gcc $(CFALGS)
SOURCE = $(wildcard *.c)
OBJECT = $(subst .c,.o,$(SOURCE))
HEADER = $(subst .c,.h,$(SOURCE))
run: $(OBJECT)
	$(CC) $(OBJECT) $(MEMFALGS) -o $(EXE)


clean:
	rm *.o

