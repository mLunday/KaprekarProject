#include<math.h>
#include<stdlib.h>
#include <stdio.h>
#include "kaprekarUtils.h"

/**
 * <p>This function tests whether the given input <code>n</code>
 * is a Kaprekar Number or not.  A Kaprekar Number is a non-negative
 * integer n whose square can be split into two positive integers
 * whose sum is equal to the original number.  For the purposes of
 * this method, we restrict our consideration to base-10 representations.</p>
 *
 * For example, 45 is a Kaprekar number, because
 *   45<sup>2</sup> = 2025
 * and
 *   20 + 25 = 45.
 *
 * <p>See Wikipedia's
 * <a href="https://en.wikipedia.org/wiki/Kaprekar_number">Kaprekar Number</a>
 * article for more information.</p>
 *
 * @param n
 * @return <code>true</code> if <code>n</code> is a Kaprekar Number,
 * <code>false</code> otherwise.
 */
int isKaprekar(int n);

int main(int argc, char **argv) {
  int m, x;
  printf("please enter a number to check if it is a kaprekar.\n");
  scanf ("%d", &m);

  x = isKaprekar (m);
  if(isKaprekar(m)){
    printf("The number %d is a kaprekar number.", m );

  } else if (!isKaprekar(m)){
    printf("The number %d is not a kaprekar number.", m );
  }
  return 0;
}

int isKaprekar (int n) {

  if(n < 1) {
    return 0;
  }

  int i;
  //compute the square
  long square = (long)n * n;
  //compute the number of digits of the square
  int numDigits = (int) log10(square) + 1;
  long modulus = 1;
  long first, second;

  //printf("%d, %li\n", numDigits, square);

  //for each possible "split" of the square...
  for(i=1; i<=numDigits; i++) {
    //increase the modulus by a factor of 10
    modulus *= 10;

    //split the square into two parts
    first = square / modulus;
    second = square % modulus;

    //test if the split makes a Kaprekar number
    //the second part cannot be zero and if
    //the sum of the two parts is equal to n, then it is
    if(second > 0 && n == first + second) {
      return 1;
    }
  }// for loop
  //printf("%li, %li", first, second);
  return 0;

}
