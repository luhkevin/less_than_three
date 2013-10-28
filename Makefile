# modify the first two lines to fit your needs
# PROGRAM is the name of the final program
PROGRAM = less_than_three
# UNITS lists the base names of the .c files used in your program
UNITS   = main

# here, put all of the header dependencies
map.o : map.h

CC      = gcc
CFLAGS  = -g -Wall
LDFLAGS = -g

OBJS    = $(UNITS:%=%.o)

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $<

.PHONY: clean all
.DEFAULT_GOAL = all

clean:
	rm -f $(OBJS) $(PROGRAM)
