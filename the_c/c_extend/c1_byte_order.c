#include <stdio.h>
#include "windows.h"


BYTE b = 0x12;
WORD w = 0x1234;
DWORD dw = 0x12345678;
char str[] = "abcde";

int main(int argc, char *argv[]) {
    byte lb = b;
    WORD lw = w;
    DWORD ldw = dw;
    char *lstr = str;

    unsigned int c = 257;
    unsigned int *a = &c;
    unsigned char *b = (unsigned char *) &c;  // 强制转换类型

    printf("%d\n", *a); // 输出 257
    printf("%d\n\n", *b); // 输出 1  字节小端存储

    /*
     * adjust byte big or little endian
     */
//    union {
//        short i;
//        char a[2];
//    } u;
//    u.a[0] = 0x11;
//    u.a[1] = 0x22;
//    printf("0x%x\n\n", u.i);  // 0x2211 是小端



    union {
        int m;
        char n;
    } check_point;

    check_point.m = 1;  // 联合体的访问不论对哪个变量的存取都是从 union 的首地址位置开始
    if (check_point.n == 1) {
        printf("little endian\n");
    } else {
        printf("Big endian\n");
    }



    /*
     * adjust big or little endian
     */
    int i = 1;
    printf("%d\n", *(char *) &i);
    (*(char *) &i == 1) ? printf("little endian\n") : printf("big endian\n");

    return 0;
}