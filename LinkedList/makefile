CXX := gcc
CFLAGS := -g
INCLUDES := ./includes/*.h
EXECUTABLE := untitled
OBJDIR := ./obj

OBJ := *.o

build:
	make obj
	make exec
	make clean_obj
	mkdir ./build
	mv $(EXECUTABLE).exe ./build

run:
	make obj
	make exec
	./untitled
	make clean_run

exec:
	$(CXX) $(OBJ) -o $(EXECUTABLE)

obj:
	$(CXX) $(INCLUDES) $(CFLAGS) -c ./src/*.c 
	mkdir $(OBJDIR)	
	mv *.o $(OBJDIR)

clean_obj:
	rm ./includes/*.gch
	rm $(OBJDIR)/*.o

clean_run:
	make clean_obj
	rm $(EXECUTABLE).exe

clean_build:
	rm ./build/*
	rmdir ./build