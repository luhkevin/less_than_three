/*
 *
 * Initializes windows, panels, etc...
 *
 *
 */

/* Create the in-game announcement panel */

/* Create the main game window */

/* Create the menu */




/*
 * main game loop: 
 *
 * Render room (0-0 first) and player <-*
 *                                      |
 * Process keys                         |
 *                                      |
 * Detect collisions/Dialogue           |
 *                                      |
 * Go back and re-render things --------*
 *
 *
 * Render: done in render.c (called in main)
 * --> room creation done in world.c/rooms.c
 *
 * Process keys, detect collisions: done in main, which passes
 * off the detected collisions/keys to the appropriate subroutines
 *
 */

