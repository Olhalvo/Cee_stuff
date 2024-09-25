CXX := gcc
CFLAGS := -g -Wall
SRC := $(wildcard ./src/*.c)
OBJ := $(SRC:.c=.o)
EXEC := run

%.o: %.c
	@$(CXX)  -o $@ -c $(CFLAGS) $^


all: $(OBJ)
	@$(CXX) -o $(EXEC) $(CFLAGS) $^

run: all
	@clear
	@./$(EXEC)
	@printf "\n%s\n" "Press enter to continue..."
	@read ans
	@make clean_all

clean_obj:
	@rm -f $(OBJ)

clean_all: clean_obj
	@rm $(EXEC)
	@clear