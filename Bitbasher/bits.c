/*
 * CS:APP Data Lab
 *
 * Colton Hagan haganc3
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

/*
 Name: Colton Hagan
 Email: haganc3@wwu.edu
 Class: CSCSI
 Contents: This file contains the question and anwsers for project 1.
*/
#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/*
 *
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 * int test_dl10(int parameter1, int parameter2)
 * {
 *   int result = 0;
 *   int i;
 *   for (i = parameter2; i <= parameter1; i++)
 *   result |= 1 << i;
 *   return result;
 *  }
 *
 *   Assume 0 <= parameter2 <= 31, and 0 <= parameter1 <= 31
 *   If parameter2 > parameter1, then return 0
 *   Legal ops: ~ & + <<
 *   Max ops: 12
 *   Rating: 3
 */
int dl10(int highbit, int lowbit) {
    /* Uses -1/~0 as a mask to shift bits to get a mask of all
     1’s then & together to get answer */
    return ~((~0 << (highbit)) << 1) & ((~0) << lowbit);
}
/*
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl11(int x, int y)
 *   {
 *       return ~(x|y);
 *   }
 *
 *
 *   Legal ops: ~ &
 *   Max ops: 5
 *   Rating: 1
 */
int dl11(int x, int y) {
    /* There is a rule that states x|y = ~(~x&~y)
    that can be modified to work here */
    return (~x & ~y);
}
/*
 * int test_dl12(int x, int y)
 * {
 *    return x|y;
 * }
 *
 *
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int dl12(int x, int y) {
    /* There is a rule that states x|y = ~(~x&~y)
    that can be reversed to work here */
    return ~(~x & ~y);
}
/*
 *
 *  int test_dl13(int x) {
 *  int result = 0;
 *  int i;
 *  for (i = 0; i < 32; i++)
 *  result ^=  (x >> i) & 0x1;
 *  return result; }
 *
 *   Legal ops: ! & ^  >>
 *   Max ops: 20
 *   Rating: 4
 */
int dl13(int x) {
    /* using shifts to ^ all the bits at LSB then &
    with 1 to check if even/odd # of 1’s */
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    return x & 1;
}
/*
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *
 * int test_dl14(int x, int y)
 * {
 *   return x^y; }
 *
 *
 *
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int dl14(int x, int y) {
    /* Uses ~(~x&~y) to replication or and then & and ~ to change to ^ */
    return ~(~x & ~y) & ~(x & y);
}
/*
 *
 *
 *
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 * asumming a little endiamachine
 * least significant byte stored first
 *
 * int test_dl15(int x, int n, int m)
 * {
 *
 *   unsigned int nmask, mmask;
 *
 *   switch(n) {
 *   case 0:
 *     nmask = x & 0xFF;
 *     x &= 0xFFFFFF00;
 *     break;
 *   case 1:
 *     nmask = (x & 0xFF00) >> 8;
 *     x &= 0xFFFF00FF;
 *     break;
 *   case 2:
 *     nmask = (x & 0xFF0000) >> 16;
 *     x &= 0xFF00FFFF;
 *     break;
 *   default:
 *     nmask = ((unsigned int)(x & 0xFF000000)) >> 24;
 *     x &= 0x00FFFFFF;
 *     break;
 *    }
 *
 *   switch(m) {
 *   case 0:
 *     mmask = x & 0xFF;
 *     x &= 0xFFFFFF00;
 *     break;
 *   case 1:
 *     mmask = (x & 0xFF00) >> 8;
 *     x &= 0xFFFF00FF;
 *     break;
 *   case 2:
 *     mmask = (x & 0xFF0000) >> 16;
 *     x &= 0xFF00FFFF;
 *     break;
 *   default:
 *     mmask = ((unsigned int)(x & 0xFF000000)) >> 24;
 *     x &= 0x00FFFFFF;
 *     break;
 *   }
 *
 *   nmask <<= 8*m;
 *   mmask <<= 8*n;
 *
 *   return x | nmask | mmask;
 * }
 *
 *
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int dl15(int x, int n, int m) {
  /* Mostly x shifts to deal with rare other cases */
  //Double check on linux in morning
  return 2;
}
/*
 *
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *
 *
 *
 * int test_dl16(int x, int y, int z)
 * {
 *   return x?y:z;
 *  }
 *
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int dl16(int x, int y, int z) {
     /* Uses ^ to give y or z depending if you mask all 1’s or all 0’s */
     return z ^ ((y ^ z) & ((!x) + ~0));
}
/*
 *
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *
 *
 *  int test_dl17(int x)
 *  {
 *   return (x & 0x1) ? -1 : 0;
 *  }
 *
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int dl17(int x) {
    /* Uses -x =  ~x+1 to solve */
    return ~(x & 1) + 1;
}
/*
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *
 *
 * int test_dl18(int x, int n)
 * {
 *    int p2n = 1<<n;
 *    return x/p2n;
 *
 * }
 *
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int dl18(int x, int n) {
    /* Uses right shift to replicate divison */
    return (x + (x & 127)) >> n;

}
/*
 *
 *
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *
 *
 *
 *
 *  int test_dl19(void) {
 *  int result = 0;
 *  int i;
 *  for (i = 0; i < 32; i+=2)
 *    result |= 1<<i;
 *  return result; }
 *
 *   Legal ops: |  <<
 *   Max ops: 6
 *   Rating: 1
 */
int dl19(void) {
    /* Uses shifts and | to repeat pattern of 0x55 */
    int shift_1 = (85 << 8) | 85;
    return (shift_1 << 16) | shift_1;

}
/*
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int dl1(int x) {return (x < 0) ? -x : x; }
 *
 *   Example: dl1(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int dl1(int x) {
    /* Uses shift mask to set to ~0 if negative and
    then sets to positive version of number */
    int mask = x >> 31;
    return (mask + x) ^ (mask);
}
/*
 *
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *
 *
 *
 *   int test_dl20(int x)
 *   {
 *      return (x*3)/4;
 *   }
 *
 *   Legal ops: ! ~ & + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int dl20(int x) {
    /* Uses shifts to act as multiplication/ division */
    int w_bias = (x + (x & 127));
    return ((w_bias << 1) + w_bias) >> 2;

}
/*
 * Reproduce the functionality of the following C function
 * unsigned test_dl21(unsigned uf) {
 * float f = u2f(uf);
 * float hf = 0.5*f;
 * if (isnan(f))
 *   return uf;
 * else
 *   return f2u(hf);
 * }
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned dl21(unsigned uf) {
    /* Checks if nan and if not returns .5fp
    using varous shifts and masks to find said fp*/
    int temp = ((7 << 28) | (0xF8 << 20));
    int exp = uf & temp;
    int s = uf & (8 << 28);
    int frac = uf & (0x7F << 16 | 0xFF << 8 | 0xFF);
    if (exp == temp) {
      return uf;
    }
    if ((!exp) || (exp == (8 << 20))) {
      frac = frac | exp;
      frac = (uf & (0xFF << 16 | 0xFF << 8 | 0xFF)) >> 1;
      frac = frac + (((uf & 3) >> 1) & (uf & 1));
     	return s | frac;
    }
    return s | ((exp - 1) & temp) | frac;
}
/*
 * reproduce the functionality of the following C function
 * unsigned test_dl22(int x) {
 * float f = (float) x;
 * return f2u(f);
 * }
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned dl22(int x) {
    /* Remakes a fp to unsigned conversion by breaking apart into fp parts
    and reassembling unsigned using varous shifts and masks (Sorry if vague)
    but the there is not short deceive way without going line by line */
    int e = 158;
    int mask = 1 << 31;
    int s = x & mask;
    int frac;
    if (x == mask) {
        return mask | (158 << 23);
    }
    if (!x) {
        return 0;
    }
    if (s) {
        x = ~x + 1;
    }
    while (!(x & mask)) {
  		  x = x << 1;
  		    e--;
    }
    frac = (x & (~mask)) >> 8;
    if (x & 0x80 && ((x & 0x7F) > 0 || frac & 1)) {
         frac++;
    }
    return (s + (e << 23) + frac);
}

/*
 * reproduce the functionality of the following C function
 * unsigned test_dl23(unsigned uf) {
 *  float f = u2f(uf);
 *  float tf = 2*f;
 *  if (isnan(f))
 *    return uf;
 *  else
 *    return f2u(tf);
 * }
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned dl23(unsigned uf) {
    /* Checks if nan and if not returns 2fp using varous shifts and masks */
    //double check for linux in mornign
    if (uf == 0 || uf == (8 << 28)) {
        return uf;
    }
    if (((uf >> 23) & 0xFF) == 0xFF) {
        return uf;
    }
    if (((uf >> 23) & 0xFF) == 0) {
        return (uf & (1 << 31)) | (uf << 1);
    }
    return (uf + (1 << 23));
}

/*dl24 - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples:dl24(12) = 5
 *           dl24(298) = 10
 *           dl24(-5) = 4
 *           dl24(0)  = 1
 *           dl24(-1) = 1
 *           dl24(0x80000000) = 32
 * Here is a C function that accomplishes this. Reproduce the functionality
 * of this function using only the legal operations described below.
 * int test_dl24(int x) {
 *   unsigned int a, cnt;
 *
 *   x = x<0 ? -x-1 : x;
 *   a = (unsigned int)x;
 *   for (cnt=0; a; a>>=1, cnt++)
 *       ;
 *   return (int)(cnt + 1);
 * }
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int dl24(int x) {
    /* Removes negative and finds log2 before adding for sign */
    int s = x >> 31;
    x = (s & ~x) | (~s & x);

    int sixteen = !!(x >> 16) << 4;
    x = x >> sixteen;
    int eight = !!(x >> 8) << 3;
    x = x >> eight;
    int four = !!(x >> 4) << 2;
    x = x >> four;
    int two = !!(x >> 2) << 1;
    x = x >> two;
    int one = !!(x >> 1);
    x = x >> one;
    return sixteen + eight + four + two + one + x + 1;
}
/*
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl2(int x, int y)
 *   { long long lsum = (long long) x + y;
 *    return lsum == (int) lsum;}
 *
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int dl2(int x, int y) {
    //Adds x + y and then checks tmax or tmin
    int added = (x >> 1) + (y >> 1) + (x & y & 1);
    return !((added ^ (added << 1)) & (1 << 31)); 
}
/*
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl3(int x) {
 *    int i;
 *    for (i = 0; i < 32; i+=2)
 *       if ((x & (1<<i)) == 0)
 *	  return 0;
 *    return 1; }
 *
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int dl3(int x) {
    /* Masks and then ^ to check for non-shared binary */
    int mask = (0x55 << 24) | (0x55 << 16) | (0x55 << 8) | 0x55;
    return !((x & mask) ^ mask);
}
/*
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl4(int x) {
 *   int i;
 *   for (i = 1; i < 32; i+=2)
 *     if ((x & (1<<i)) == 0)
 *	  return 0;
 *    return 1; }
 *
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int dl4(int x) {
    /* Masks and then ^ to check for non-shared binary */
    int mask = 0xAA << 24 | 0xAA << 16 | 0xAA << 8 | 0xAA;
    return !((x & mask) ^ mask);
}
/*
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl5(int x) {
 *   int i;
 *   for (i = 0; i < 32; i+=2)
 *     if (x & (1<<i))
 *	  return 1;
 *   return 0; }
 *
 *   Legal ops: ! ~ &  | + << >>
 *   Max ops: 10
 *   Rating: 2
 */
int dl5(int x) {
    /* Just uses ! on dl3 to flip 1 and 0 */
    int mask = (0x55 << 24) | (0x55 << 16) | (0x55 << 8) | 0x55;
    return !!((x & mask) & mask);
}
/*
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *  int test_dl6(int x) {
 *   int i;
 *   for (i = 1; i < 32; i+=2)
 *       if (x & (1<<i))
 *	     return 1;
 *   return 0; }
 *
 *   Legal ops: ! &  | <<
 *   Max ops: 10
 *   Rating: 2
 */
int dl6(int x) {
    /* Just uses ! on dl4 to flip 1 and 0 */
    int mask = 0xAA << 24 | 0xAA << 16 | 0xAA << 8 | 0xAA;
    return !!((x & mask) ^ mask);
}
/*
*
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl7(int x)
 *   {
 *      return !x;
 *   }
 *
 *   Legal ops: ~ & ^ | + >>
 *   Max ops: 10
 *   Rating: 4
 */
int dl7(int x) {
    /*makes all non 0’s -1 with inverting sign |
    then shifting far right then adds 1 */
    return (((~x + 1) | x) >> 31) + 1;
}
/*
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl8(int x, int y)
 *   {
 *      return x&y;
 *   }
 *
 *   Legal ops: ~ |
 *   Max ops: 6
 *   Rating: 1
 */
int dl8(int x, int y) {
    /* There is a rule that states x|y = ~(~x&~y)
    that can be modified to work here */
    return ~(~x|~y);
}
/*
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl9(int x) {
 *   int result = 0;
 *   int i;
 *   for (i = 0; i < 32; i++)
 *   result +=  (x >> i) & 0x1;
 *       return result;
 *   }
 *
 *   Legal ops: & | + << >>
 *   Max ops: 38
 *   Rating: 4
 */
int dl9(int x) {
    /* uses shifts and masks to count 1's */
    int temp = 0x11 | (0x11 << 8);
    int mask = temp | (temp << 16);
    int with_mask = x & mask;
    with_mask = with_mask + (x >> 1 & mask);
    with_mask = with_mask + (x >> 2 & mask);
    with_mask = with_mask + (x >> 3 & mask);
    with_mask = with_mask + (with_mask >> 16);
    mask = 0xF | (0xF << 8);
    with_mask = (with_mask & mask) + ((with_mask >> 4) & mask);
    return (with_mask + (with_mask >> 8)) & 0x3F;
}
cd 
