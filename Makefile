CC=gcc
FLAGS=-std=gnu99
LIBRARIES=-lCello
OUTPUT=StaC
FILES=src/StaC.c src/test.c

deps:
	git clone https://github.com/orangeduck/Cello.git && cd Cello && make
	cp Cello/include/Cello.h src/
	cp Cello/libCello.a src/

clean:
	-rm $(OUTPUT)
	-rm -rf Cello
	-rm src/Cello.h
	-rm src/libCello.a

local:
	$(CC) $(FLAGS) $(FILES) -Lsrc $(LIBRARIES) -o $(OUTPUT)

all:
	@make clean
	@make deps
	@make local

test:
	@make all
	./$(OUTPUT)
