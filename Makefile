AS1 = as1
AS2 = as2
EXE1 = exe1
EXE2 = exe2

API= API

CFALGS = -Wall -g 
IFLAGS = -I$(API)
#MEMFALGS = -fsanitize=address
CC = gcc $(CFALGS) $(IFLAGS)

MAIN1 = $(wildcard $(AS1)/*.c)
MAIN2 = $(wildcard $(AS2)/*.c)

SOURCE_WILDCARD = *.c		\
				  $(API)/*.c
SOURCE = $(wildcard $(SOURCE_WILDCARD))
OBJECT = $(subst .c,.o,$(SOURCE))
HEADER = $(subst .c,.h,$(SOURCE))

ASS1: $(OBJECT)
	$(CC) $(MAIN1) $(SOURCE) $(MEMFALGS) -o $(EXE1)

ASS2: $(OBJECT)
	make clean
	$(CC) $(MAIN2) $(SOURCE) $(MEMFALGS) -o $(EXE2)

clean:
	rm *.o
	rm $(API)/*.o

