# modify the first two lines to fit your needs
# PROGRAM is the name of the final program
PROGRAM = less_than_three
# UNITS lists the base names of the .c files used in your program
UNITS   = main render map world1 player collisions dialogue

# here, put all of the header dependencies
map.o : map.h
render.o: render.h map.h player.h 
world1.o: world.h
player.o: player.h
main.o: render.h player.h world.h collisions.h dialogue.h
collisions.o: collisions.h interact.h
dialogue.o: dialogue.h

CC      = gcc
CFLAGS  = -g -Wall 
LDFLAGS = -g -lncurses -lpanel

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
