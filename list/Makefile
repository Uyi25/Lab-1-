# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Author>
list: list.c main.c
	gcc list.c main.c -o list
SOURCES = list.c main.c
OBJS = $(SOURCES:.c=.o)
TARGET = list

CC = gcc
CFLAGS = -Wall

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
