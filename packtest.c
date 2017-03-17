#include <stdio.h>
#include <stdbool.h>

struct foo1 {
    char *p; // 8 bytes
    char c; // 1 byte
    // 补齐 7 bytes
    long x; // 8 bytes
}; // 24 bytes

struct foo2 {
    char c;      // 1 byte
    char pad[7]; // 7 bytes
    char *p;     // 8 bytes
    long x;      // 8 bytes
}; // 24 bytes

struct foo3 {
    char *p;     // 8 bytes
    char c;      // 1 byte
    // 补齐 7 bytes
}; // 16 bytes

struct foo4 {
    short s;     // 2 bytes
    char c;      // 1 byte
    // 补齐 1 byte
}; // 4 bytes

struct foo5 {
    char c; // 1 byte
    // 补齐 7 bytes
    struct foo5_inner {
        char *p; // 8 bytes
        short x; // 2 bytes
        // 补齐 6 bytes
    } inner;
}; // 24 bytes

struct foo6 {
    short s; // 2 bytes
    char c; // 1 byte
    int flip :1; // 1 bit
    int nybble :4; // 4 bits
    // 补齐 1 bit
    int septet :7; // 7 bits
    // 补齐 25 bits
}; // 8 bytes

struct foo7 {
    int bigfield :31; // 31 bits
    int littlefield :1; // 1 bit
}; // 4 bytes

struct foo8 {
    int bigfield1 :31; // 31 bits
    int littlefield1 :1; // 1 bit
    int bigfield2 :31; // 31 bits
    int littlefield2 :1; // 1 bit
}; // 8 bytes

struct foo9 {
    int bigfield1 :31; // 31 bits
    // 补齐 1 bit
    int bigfield2 :31; // 31 bits
    // 补齐 1 bit
    int littlefield1 :1; // 1 bit
    int littlefield2 :1; // 1 bit
    // 补齐 30 bits
}; // 12 bytes

struct foo10 {
    char c; // 1 byte
    // 补齐 7 bytes
    struct foo10 *p; // 8 bytes
    short x; // 2 bytes
    // 补齐 6 bytes
}; // 24 bytes

struct foo11 { 
    struct foo11 *p; // 8 bytes
    short x; // 2 bytes
    char c; // 1 byte
    // 补齐 5 bytes
}; // 16 bytes

struct foo12 {
    struct foo12_inner {
        char *p; // 8 bytes
        short x; // 2 bytes
        // 补齐 6 bytes
    } inner;
    char c; // 1 byte
    // 补齐 7 bytes
}; // 24 bytes

int main(int argc, const char *argv[]) {
    printf("sizeof(char *)        = %zu\n", sizeof(char *));
    printf("sizeof(long)          = %zu\n", sizeof(long));
    printf("sizeof(int)           = %zu\n", sizeof(int));
    printf("sizeof(short)         = %zu\n", sizeof(short));
    printf("sizeof(char)          = %zu\n", sizeof(char));
    printf("sizeof(float)         = %zu\n", sizeof(float));
    printf("sizeof(double)        = %zu\n", sizeof(double));
    printf("sizeof(struct foo1)   = %zu\n", sizeof(struct foo1));
    printf("sizeof(struct foo2)   = %zu\n", sizeof(struct foo2));
    printf("sizeof(struct foo3)   = %zu\n", sizeof(struct foo3));
    printf("sizeof(struct foo4)   = %zu\n", sizeof(struct foo4));
    printf("sizeof(struct foo5)   = %zu\n", sizeof(struct foo5));
    printf("sizeof(struct foo6)   = %zu\n", sizeof(struct foo6));
    printf("sizeof(struct foo7)   = %zu\n", sizeof(struct foo7));
    printf("sizeof(struct foo8)   = %zu\n", sizeof(struct foo8));
    printf("sizeof(struct foo9)   = %zu\n", sizeof(struct foo9));
    printf("sizeof(struct foo10)   = %zu\n", sizeof(struct foo10));
    printf("sizeof(struct foo11)   = %zu\n", sizeof(struct foo11));
    printf("sizeof(struct foo12)   = %zu\n", sizeof(struct foo12));

    return 0;
}