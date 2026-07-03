/*
 * Exercise 4-14 from K&R: Define a macro swap(t,x,y) that interchanges two
 * arguments of type t.
 */

#define swap(t, x, y) { t z; z = x; x = y; y = z; }
