CC = gcc
CFLAGS = -g -Wall
TARGET = myprog
SRC = double_linked_list.c
OBJ = double_linked_list.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGETm -f *.o $(TARGET)
