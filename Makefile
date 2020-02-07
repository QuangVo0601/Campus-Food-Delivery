# A simple Makefile
# Quang Vo G01122283
# CS 262, Lab Section 201
# Proj3

# The compiler: gcc for C programs, g++ for C++ programs, etc
CC = gcc
CFLAGS=-g -Wall -O0 -pedantic-errors

TARGET1 = proj3_qvo8_201
TARGET2 = itemList_qvo8_201
TARGET3 = order_qvo8_201
all : $(TARGET1) 

$(TARGET1): $(TARGET1).c
	$(CC) $(CFLAGS) -o $(TARGET1) $(TARGET1).c $(TARGET2).c $(TARGET3).c

clean: 
	rm $(TARGET1) 

