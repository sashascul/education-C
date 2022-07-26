#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define PX printf("X = %d\n", x)
#define FMT "X = %d\n"
#define SQUARE(X) X*X
#define PSQR(X) printf ("Square X is %d", (X)*(X))
#define SQR(x) printf ("Squate "#x" is %d\n", (x)*(x)) //замена #x на то, что будет компилироваться
#define XNAME(n) x ## n // слияние x и n. Если n = 1, то получим x1
#define PRXNAME(n) printf ("x"#n" is %d\n", x ## n)
#define PR(...) printf (__VA_ARGS__) // переменное число аргументов. Можно подставлять любые конструкции
#define PR1(X, ...) printf ("Message "#X": " __VA_ARGS__)
#define LIMIT 400
#define JUST_CHECKING
#define SIZE 228
#define MYTYPE(X) _Generic((X), \
  int: "int",\
  float: "float",\
  double: "double",\
  char: "char",\
  default: "other"\
)
#define SIN(X) _Generic((X), long double: sinl(X), float: sinf(X), default: sin(X))
#define SQRT(X) _Generic((X), long double: sqrtl, float: sqrtf, default: sqrt) (X)

#undef LIMIT
            /* отмена определения LIMIT, т.е. LIMIT можно инициализоровать по новой через define */

/*

#ifdef MAVIS
  #include "horse.h" // выполняется, если идентификатор МAVIS определен
  #define STABLES 5
#else
  #include "cow.h"  // выполняется, если идентификатор MAVIS не определен
  #define STABLES 15
#endif

*/

#ifndef SIZE  // #ifndef выясняет, не определен ли следующий за ней идентификатор
  #define SIZE 100
#endif

/*

#if SYS == 1
  #include "ibmpc.h"
#elif SYS == 2
  #include "vax.h"
#elif SYS == 3
  #include "mac.h"
#else
  #include "general.h"
#endif

*/

void why_me();
void sign_off (void);
void too_bad (void);
int sort_func (const void * p1, const void * p2);

inline static void eatline () {
  while (getchar() != '\n')
    continue;
}

int main () {

    /*

  	int x = 2;
  	PX; // ---> define
  	x = 4;
  	printf (FMT, x);

    */

    /*

  	int x = 2;
  	const char * fmt = "X = %d\n";
  	printf (fmt, x);

    */

    /*

  	int x = 3;
  	x = SQUARE(x); // ---> define
  	printf ("%d", x);

    */

    /*

  	int x = 4;
  	PSQR (x);

    */

    /*

  	int z = 2;
  	SQR (z);

    */

    /*

  	int XNAME(1) = 14;
  	PRXNAME(1);
  	putchar('\n');
  	printf ("x = %d", x1);

  	*/

    //PR ("Hello, world!\n");
    //int x = 2;
    //PR ("x = %d\n", x);

    /*

    double x = 48, y;
    y = sqrt(x);
    PR1 (1, "x = %lf\n", x);
    PR1 (2, "x = %lf, y = %lf\n", x, y);

    */

    /*

    int i, total = 0;
    for (i = 1; i < 4; i++) {
      total += 2 * i * i + 1;
#ifdef JUST_CHECKING // если убрать определение в начале файла, то не будут выводиться промежуточные суммы
      printf ("i = %d, subsum = %d\n", i, total);
#endif
    }

    printf ("Full sum = %d\n", total);

    */

    //printf ("%d", SIZE);

    /*

    printf ("File: %s\n", __FILE__);
    printf ("Date: %s\n", __DATE__);
    printf ("Time: %s\n", __TIME__);
    printf ("Version: %ld\n", __STDC_VERSION__);
    printf ("This string: %d\n", __LINE__);
    printf ("This function: %s\n", __func__);
    putchar ('\n');
    why_me();

    */

    /*

#line 1000  // переустанавливает текущий номер строки в 1000
#line 10 "cool.c" //переустанавливает номер строки в 10, а имя файла - в cool.c

    */

/*

#if __STDC_VERSION__ != 201112L
#error NO C11!
#endif

*/

  /*

  int d = 11;
  char ch = 'c';
  double a = 21.22;
  char * pt;

  printf ("%s\n", MYTYPE(d));
  printf ("%s\n", MYTYPE(ch));
  printf ("%s\n", MYTYPE(a));
  printf ("%s\n", MYTYPE(pt));

  */


  //eatline();

  //int d = 11;
  //printf ("%s\n", MYTYPE(d));

  /*

  float x = 45;
  double xx = 45;
  long double xxx = 45;
  long double y = SQRT(x);
  long double yy = SQRT(xx);
  long double yyy = SQRT(xxx);
  printf ("%.17Lf\n", y);
  printf ("%.17Lf\n", yy);
  printf ("%.17Lf\n", yyy);
  int i = 45;
  y = SQRT(i);
  printf ("%.17Lf\n", y);
  yyy = SIN(xxx);
  printf ("%.17Lf\n", yyy);

  */

  /*

  int n;
  atexit (sign_off); // первый зарегистрировался - последний вышел
                     // последний зарегистрировался - первый вышел
  puts ("Input whole number");
  if (scanf ("%d", &n) != 1) {
    puts ("It's not whole number!");
    atexit (too_bad);
    exit (EXIT_FAILURE);
  }
  printf ("%d is %s\n", n, (n % 2 == 0)? "even" : "uneven");

  */

  /*

  double arr[100];
  double * pt = arr;
  int i;

  for (i = 0; i < 100; i++)
    arr[i] = (rand() % 100);
  puts ("Before: ");
  for (i = 0; i < 100; i++) {
    if (i % 10 == 0)
      putchar ('\n');
    printf ("%.1lf ", arr[i]);
  }
  putchar ('\n');
  putchar ('\n');
  puts ("After: ");

  qsort (arr, 100, sizeof (double), sort_func);

  for (i = 0; i < 100; i++) {
    if (i % 10 == 0)
      putchar ('\n');
    printf ("%.1lf ", arr[i]);
  }

  */

  /*

  int a, b;
  puts ("Input 2 numbers: ");
  while (scanf ("%d %d", &a, &b) == 2) {
    int res = a * a - b * b;
    assert (res >= 0);
    printf ("a^2 - b^2 = %d\n", res);
    puts ("Input 2 numbers: ");
  }

  */

  //int a = 2;
  //_Static_assert (CHAR_BIT == 16);

  /*

  int arr1[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int arr2[10] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};

  memcpy (arr2, arr1, 16); // void * memcpy (void *s1, const void *s2, size_t count); - копирует count байтов из arr1 в arr2;
  int i;
  for (i = 0; i < 10; i++)
    printf ("%d ", arr2[i]);

  */




  return 0;
}

void why_me() {
  printf ("This function: %s\n", __func__);
  printf ("This string: %d\n", __LINE__);
}

void sign_off (void) {
  puts ("The end of program from");
  puts ("SeeSaw Software!");
}

void too_bad (void) {
  puts ("ERROR!");
}

int sort_func (const void * p1, const void * p2) {
  const double * a1 = (const double *) p1;
  const double * a2 = (const double *) p2;

  if (*a1 < *a2)
    return -1;
  if (*a1 == *a2)
    return 0;
  else
    return 1;

}

double sum (int lim, ...) {
  va_list ap;
  double total = 0;
  int i;
  va_start (ap, lim);

}
