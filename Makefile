# modify the first two lines to fit your needs
# PROGRAM is the name of the final program
PROGRAM = less_than_three
# UNITS lists the base names of the .c files used in your program
UNITS   = main render rooms world player collisions dialogue world_creation

# here, put all of the header dependencies
main.o: render.h player.h world.h collisions.h dialogue.h constants.h
rooms.o : rooms.h
render.o: render.h rooms.h player.h 
world.o: world.h
player.o: player.h
collisions.o: collisions.h interact.h
dialogue.o: dialogue.h
world_creation.o: world_creation.h world.h

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
