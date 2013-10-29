# modify the first two lines to fit your needs
# PROGRAM is the name of the final program
PROGRAM = less_than_three
# UNITS lists the base names of the .c files used in your program
UNITS   = main render map world1

# here, put all of the header dependencies
map.o : map.h
render.o: render.h map.h player.h 
main.o: render.h player.h world1.h
world1.o: world1.h

CC      = gcc
CFLAGS  = -g -Wall 
LDFLAGS = -g -lncurses

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
