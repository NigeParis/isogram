EXEC=isogram
CFLAGS=-Wall
CFLAGS+=-Wextra
CFLAGS+=-Werror
CC=gcc
SRC_FILE=isogram

.PHONY: run
run:	$(EXEC)
		@echo "\nRunning..................."
		./$(EXEC)

$(EXEC): main.o $(SRC_FILE).o
	@echo "\nLinking..........................."
	$(CC) $^ -o $(EXEC)

main.o: main.c $(SRC_FILE).h
	@clear
	@echo "\nCompiling main with headers............................."
	$(CC) $(CFLAGS) -c main.c

$(SRC_FILE).o: $(SRC_FILE).c
	@echo "\nCompiling source files ......................."
	$(CC) $(CFLAGS) -c $(SRC_FILE).c

.PHONY: clean
clean:
	@clear
	@echo "\nCleaning .............."
	rm -rf $(EXEC) *.o
	ls -l
