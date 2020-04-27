# Makefile for klibc
CC			= g++
INC_DIR		= ../inc
INC			= $(foreach d, $(INC_DIR), -I$d)
CFLAGS      := -Wall -O3 -std=c++0x
LIBS		= -lpthread -lm -lc -lgcc
LIB         = klib.a
OBJS		= Exception.o
TEST		= main.o

all : $(LIB) $(TEST)
	$(CC) -o a.out $(TEST) $(LIB) $(LIBS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC) $(LIBS)
    
$(LIB) : $(OBJS)
	rm -f $@
	ar cr $@ $(OBJS)
	rm -f $(OBJS)

clean:
	rm -f $(OBJ) $(TARGET) $(LIB)

