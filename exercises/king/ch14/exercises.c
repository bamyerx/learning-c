/* 
 * Chapter 14 exercises from King
 */

/*
 * Exercise 1. Write parameterized macros that compute the following values.
 * (a) The cube of x.
 * (b) The remainder when n is divided by 4.
 * (c) 1 if the product of x and y is less than 100. 0 otherwise.
 */

#define CUBE(x) ((x)*(x)*(x))
#define NMOD4(n) ((n)%4)
#define LT100(x,y) ((x)*(y)<100?1:0)

/*
 * Exercise 2. Write a macro NELEMS(a) that computes the number of elements in a
 * one-dimensional array a.
 */

#define NELEMS(a) sizeof(a)/sizeof(a[0])

/*
 * Exercise 3. Let DOUBLE be the following macro:
 *
 *    #define DOUBLE(x) 2*x
 *
 * (a) What is the value of DOUBLE(1+2)?    
 *
 * DOUBLE(1+2) = 2*1+2 = 4
 *
 * (b) What is the value of 4/DOUBLE(2)?    
 *
 * 4/DOUBLE(2) = 4/2*1+2 = 4
 *
 * (c) Fix the definition of DOUBLE.
 */

#define DOUBLE(x) (2*(x))

/*
 * Exercise 4. For each of the following macros, give an example that
 * illustrates a problem with the macro and show how to fix it.
 * (a) #define AVG(x,y) (x+y)/2
 *
 * Example: AVG(a<b,c<d) => (a<b+c<d)/2 => (a<(b+c)<d)/2
 *
 * (b) #define AREA(x,y) (x) * (y)
 *
 * Example: 1/AREA(a,b) => 1/(a) * (b) => (1/a) * b
 */

#define AVG(x,y) (((x)+(y))/2)
#define AREA(x,y) ((x)*(y))

/*
 * Exercise 5. Let TOUPPER be the following macro:
 *
 *     #define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))
 *
 * Let s be a string and let i be an int variable. Show the output produced by
 * each of the following program fragments.
 * (a) strcpy(s, "abcd");
 *     i = 0;
 *     putchar(TOUPPER(s[++i]));
 *
 *     Output: D
 *
 * (b) strcpy(s, "0123");
 *     i = 0;
 *     putchar(TOUPPER(s[++i]);
 *
 *     Output: 2
 */

/*
 * Exercise 6.
 * (a) Write a macro DISP(f,x) that expands into a call of printf that displays
 *     the value of the function f when called with argument x. For example,
 *
 *     DISP(sqrt, 3.0);
 *
 * should expand into
 *
 *     printf("sqrt(%g) = %g\n", 3.0, sqrt(3.0));
 *
 * (b) Write a macro DISP2(f,x,y) that's similar to DISP but works for functions
 *     with two arguments.
 */

#define DISP(f,x) printf(#f "(%g) = %g\n", x, f(x))
#define DISP2(f,x,y) printf(#f "(%g,%g) = %g\n", x, y, f(x, y))

/*
 * Exercise 7. Let GENERIC_MAX be the following macro:
 *
 *     #define GENERIC_MAX(type)        \
 *     type type##_max(type x, type y)  \
 *     {                                \
 *       return x > y ? x : y;          \
 *     }
 *
 * (a) Show the preprocessor's expansion of GENERIC_MAX(long).
 *
 * long long_max(long x, long y)
 * {
 *   return x > y ? x : y;
 * }
 *
 * (b) Explain why GENERIC_MAX doesn't work for basic types such as unsigned 
 *     long.
 * 
 * GENERIC_MAX doesn't work for types such as unisnged long because the type
 * specifier is multiple tokens long, which makes the function's name invalid.
 *
 * (c) Describe a technique that would allow us to use GENERIC_MAX with basic
 *     types such as unsigned long.
 *
 * A type definition could be used to create an alias for a type with a multi-
 * token name, allowing their use in the existing GENERIC_MAX definition.
 */

/*
 * Exercise 8. Suppose we want a macro that expands into a string containing the
 * current line number and file name. In other words, we'd like to write
 *
 *     const char *str = LINE_FILE;
 *
 * and have it expand into
 *
 *     const char *str = "Line 10 of file foo.c";
 *
 * where foo.c is the file containing the program and 10 is the line on which
 * the invocation of LINE_FILE appears.
 */

#define STRINGIZE(s) STRINGIZE2(s)
#define STRINGIZE2(s) #s
#define LINE_FILE "Line " STRINGIZE(__LINE__) " of file " __FILE__

/*
 * Exercise 9. Write the following parameterized macros.
 * (a) CHECK(x,y,n) - Has the value 1 if both x and y fall between 0 and n-1,
 *     inclusive.
 * (b) MEDIAN(x,y,z) - Finds the median of x, y, and z.
 * (c) POLYNOMIAL(x) - Computes the polynomial 3x^5+2x^4-5x^3-x^2+7x-6.
 */

#define CHECK(x,y,n) (((x)>=0)&&((x)<=(n)-1)&&((y)>=0)&&((y)<=(n)-1))

#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MEDIAN(x,y,z) ((x)+(y)+(z)-MIN(MIN((x),(y)),(z))-MAX(MAX((x),(y)),(z)))

#define P5(x) ((x)*(x)*(x)*(x)*(x))
#define P4(x) ((x)*(x)*(x)*(x))
#define P3(x) ((x)*(x)*(x))
#define P2(x) ((x)*(x))
#define POLYNOMIAL(x) (3*P5(x)+2*P4(x)-5*P3(x)-P2(x)+7*(x)-6)

/*
 * Exercise 11. C programmers often use the fprintf function to write error
 * messages:
 *
 *     fprintf(stderr, "Range error: index = %d\n", index);
 *
 * stderr is C's "standard error" stream; the remaining arguments are the same
 * as those for printf, starting with the format string. Write a macro named
 * ERROR that generates the call of fprintf shown above when a given a format
 * string and the items to be displayed:
 *
 *     ERROR("Range error: index = %d\n", index);
 */

#define ERROR(fs,...) fprintf(stderr, fs, __VA_ARGS__)

/*
 * Exercise 12. Suppose that the macro M has been defined as follows:
 *
 *     #define M 10
 *
 * Which of the following tests will fail?
 * (a) #if M           Success
 * (b) #ifdef M        Success
 * (c) #ifndef M       Fail
 * (d) #if defined(M)  Success
 * (e) #if !defined(M) Fail
 */

/*
 * Exercise 13.
 * (a) Show what the following program will look like after preprocessing. You
 *     may ignore any lines added to the program as a result of including the
 *     <stdio.h> header.
 *
 * After preprocessing:
 * void f(void);
 *
 * int main(void)
 * {
 *   f();
 *
 *
 *
 *   return 0;
 * }
 *
 * void f(void)
 * {
 *
 *
 *
 *   printf("N is undefined\n");
 * 
 * }
 *
 * (b) What will be the output of this program?
 *
 * Output: N is undefined
 */

/*
 * Exercise 14. Show what the following program will look like after
 * preprocessing. Some lines of the program may cause compilation errors; Find
 * all such errors.
 *
 * After preprocessing:
 *
 *
 *
 *
 *
 *
 *
 *
 * int main(void)
 * {
 *   int a[= 10], i, j, k, m;        syntax error
 *
 *
 *   i = j;
 *
 *
 *
 *
 *   i = 10 * j+1;
 *   i = (x,y) x-y(j, k);            syntax error
 *   i = ((((j)*(j)))*(((j)*(j))));
 *   i = (((j)*(j))*(j));
 *   i = jk;                         jk is undefined
 *   puts("i" "j");
 *
 *
 *   i = SQR(j);                     SQR is undefined
 *
 *   i = (j);
 *
 *   return 0;
 * }
 */

/*
 * Exercise 15. Suppose that a program needs to display messages in either
 * English, French of Spanish. Using conditional compilation, write a program
 * fragment that displays one of the following three messages, depending on
 * whether or not the specified macro is defined:
 *
 *     Insert Disk 1        (if ENGLISH is defined)
 *     Inserez Le Disque 1  (if FRENCH is defined)
 *     Inserte El Disco 1   (if SPANISH is defined)
 */

#ifdef ENGLISH
#define MSG "Insert Disk 1"
#elif FRENCH
#define MSG "Inserez Le Disque 1"
#elif SPANISH
#define MSG "Inserte El Disco 1"
#else
#define MSG

/*
 * Exercise 16. Assume that the following macro definitions are in effect:
 *
 *     #define IDENT(x) PRAGMA(ident #x)
 *     #define PRAGMA(x) _Pragma(#x)
 *
 * What will the following line look like after macro expansion?
 *
 *     IDENT(foo)
 *
 * After macro expansion: 
 *
 *     #pragma ident "foo"
 */
