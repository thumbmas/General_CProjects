# Define compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Final executable name
TARGET = hivepocket

# Automatically find all .c files and convert them to .o files
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile individual .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET)