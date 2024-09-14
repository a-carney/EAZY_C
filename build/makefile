CC = gcc
CFLAGS = -I../include -Wall -Wextra -O2
AR = ar
ARFLAGS = rcs
RM = rm -f

SRC = ../src/gc.c ../src/easyc.c
OBJ = $(SRC:.c=.o)
LIB = libeasyc.a

all: $(LIB)

$(LIB): $(OBJ)
	$(AR) $(ARFLAGS) $(LIB) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(LIB)

.PHONY: all clean
