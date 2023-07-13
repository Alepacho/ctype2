#include <stdio.h>

#define CTYPE2_IMPLEMENTATION
#include "ctype2.h"

#define CHECK(v) (v > 0 ? "YES" : "NO")

int main() {
    const char* string = "Hello, World!";
    // const int value = 00000001;
    // double test = +009.e+10;

    printf("%s\n", string);
    printf("isinteger(): %s\n", CHECK(isinteger("")));
    printf("isinteger(0): %s\n", CHECK(isinteger("0")));
    printf("isinteger(-0): %s\n", CHECK(isinteger("-0")));
    printf("isinteger(+0): %s\n", CHECK(isinteger("+0")));
    printf("isinteger(00): %s\n", CHECK(isinteger("00")));
    printf("isinteger(000001): %s\n", CHECK(isinteger("000001")));
    printf("isinteger(+000001): %s\n", CHECK(isinteger("+000001")));
    printf("isinteger(-000001): %s\n", CHECK(isinteger("-000001")));
    printf("isinteger(-00): %s\n", CHECK(isinteger("-00")));
    printf("isinteger(+00): %s\n", CHECK(isinteger("+00")));
    printf("isinteger(-01): %s\n", CHECK(isinteger("-01")));
    printf("isinteger(01): %s\n", CHECK(isinteger("01")));
    printf("isinteger(+01): %s\n", CHECK(isinteger("+01")));
    printf("isinteger(a): %s\n", CHECK(isinteger("a")));
    printf("isinteger(1): %s\n", CHECK(isinteger("1")));
    printf("isinteger(100): %s\n", CHECK(isinteger("100")));
    printf("isinteger(-1): %s\n", CHECK(isinteger("-1")));
    printf("isinteger(--1): %s\n", CHECK(isinteger("--1")));
    printf("isinteger(1337): %s\n", CHECK(isinteger("1337")));
    printf("isinteger(+1337): %s\n", CHECK(isinteger("+1337")));
    printf("isinteger(+21635.9487): %s\n", CHECK(isinteger("+21635.9487")));
    printf("isinteger(-2147483648): %s\n", CHECK(isinteger("-2147483648")));
    printf("isinteger(21474836480): %s\n", CHECK(isinteger("21474836480")));
    printf("isinteger(214748364800): %s\n", CHECK(isinteger("214748364800")));
    printf("isinteger(4294967295): %s\n", CHECK(isinteger("4294967295")));
    printf("isinteger(42949672950): %s\n", CHECK(isinteger("42949672950")));
    printf("\n");
    printf("isdouble(): %s\n", CHECK(isdouble("")));
    printf("isdouble(+21635.9487): %s\n", CHECK(isdouble("+21635.9487")));
    printf("isdouble(+21635.9487): %s\n", CHECK(isdouble("+21635.9487")));
    printf("\n");
    printf("isbool(): %s\n", CHECK(isbool("")));
    printf("isbool(+21635.9487): %s\n", CHECK(isbool("+21635.9487")));
    printf("isbool(False): %s\n", CHECK(isbool("False")));
    printf("isbool(false): %s\n", CHECK(isbool("false")));
    printf("isbool(true): %s\n", CHECK(isbool("true")));
    printf("isbool(TRUE): %s\n", CHECK(isbool("TRUE")));
    printf("isbool(tru): %s\n", CHECK(isbool("tru")));
    printf("\n");
    printf("isidentifier(): %s\n", CHECK(isidentifier("")));
    printf("isidentifier(tru): %s\n", CHECK(isidentifier("tru")));
    printf("isidentifier(test69): %s\n", CHECK(isidentifier("test69")));
    printf("isidentifier(test ): %s\n", CHECK(isidentifier("test ")));
    printf("isidentifier(_this): %s\n", CHECK(isidentifier("_this")));
    printf("isidentifier(IS): %s\n", CHECK(isidentifier("IS")));
    printf("isidentifier(a): %s\n", CHECK(isidentifier("a")));
    printf("isidentifier(7est): %s\n", CHECK(isidentifier("7est")));
    printf("isidentifier(ThisIsATest): %s\n", CHECK(isidentifier("ThisIsATest")));
    printf("isidentifier(this_is_a_test): %s\n", CHECK(isidentifier("this_is_a_test")));
    printf("isidentifier(xX_DeStR0y3r_Xx): %s\n", CHECK(isidentifier("xX_DeStR0y3r_Xx")));

    return 0;
}
