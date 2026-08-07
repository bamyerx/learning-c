/*
 * Exercise 7-9 from K&R: Functions like isupper can be implemented to save
 * space or to save time. Explore both possibilities.
 */

/*
 * A typical save-spacing implementation would be a simple range comparison:
 */
int isupper1(int c)
{
	return c >= 'A' && c <= 'Z';
}

/*
 * A typical time-saving implementation would be a table lookup, as is often
 * the case for ctype.h. In the macro definitions below, _ctype is a bitmask
 * array containing character properties.
 */
#define _UPPER 0x01
#define isupper(c) (_ctype[c] & _UPPER)

/*
 * The range comparison minimizes data storage but must compute the result and
 * the table lookup guarantees constant-time lookup but requires the table to
 * be saved and stored.
 */
