# Squared 6.0

A Pebble Watchface for Pebble, Pebble Time and Pebble Time Round

 * Original source code by lastfuture
 * SDK 2.0beta4 port by Jnm
 * SDK 3.0 port and colorizing by hexahedria
 * Adaptations for Chalk and Aplite by lastfuture

 ## Changes in this fork
 * Configurable colors
 * Use clay instead of hosted config page (offline config)
 * Ported to Pebble Time 2
 * Big font mode removed
 * Somewhat in C++
 * All positions are calculated at compile time instead of runtime

## Notes
 * Clay configuration page does not hide elements that are ignored if others are enabled. This is purely cosmetic though.

## TODO
 * Fix redraw on return from menu
 * Check for leftover math in the drawing logic
 * Figure out if the config page can be wrapped inside the pbw. Original config page by lastfuture has been archived
 * Fix sizes on round pebbles
 * Investigate possible race condition with handle_tick
