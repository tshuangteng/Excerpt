#include<stdio.h>

/*
 指针与数组    指针的自增自减

 ++a表示取a的地址，增加它的内容，然后把值放在寄存器中；
 a++表示取a的地址，把它的值装入寄存器，然后增加内存中的a的值；

 在非内置类型的时候，尽量使用前置++ 效率高（后置自增，效率低）

 指针是地址变量，而数组名代表数组的首地址，是指针常量，不能进行自加自减运算。
 数组名在运算中可以作为指针参与，但不允许被赋值，指针可变，允许指向别的位置

 危险操作: 自减后的指向不可预测，因为可能占用了系统正常运行所需要的内存，有可能导致系统瘫痪
 */

int main() {
    /* ---------- */
    int arr[] = {11, 12, 13, 14, 15};
    int *ptr = arr;  // arr表示的是数组的第一个元素地址, 指针常量. (注意不是整个数组)
    *(ptr++) += 100;  // ++在后, 先用++
    printf("%d %d\n", *ptr, *(++ptr));  // printf的两个参数压栈顺序为从右至左，故也先计算*(++ptr).
    //    13 13


    /* ---------- */
    char a[] = "hello world";
    char *p = a;  // 定义指针变量p
    //    指针和数组常见等价操作 ---> 指针操作 数组操作 说明
    //    p &a[0] 数组首地址
    //    p+i &a[i] 数组的第i个元素的地址

    //    *p a[0] 数组的第一个元素
    //    *(p+i) a[i] 数组的第i个元素
    //    *p+b a[0]+b 数组的第一个元素的值加b
    //    *(p+i)+b a[i]+b 数组的第i个元素的值加b


    /* ---------- */
    // 指针数组的引用可以认为是一个指向指针的指针，因为数组名本身代表地址，可以做指针参与运算（不能改变其值）数组元素的值是指针，因此是二级指针，**p
    // c/c++中,输出字符指针就是输出字符串,程序会自动在遇到\0后停止

    char *ta[2] = {"one", "two"}, **tp = a;  // a中的元素都是指向char值的指针
    printf("size of ta: %d\n", sizeof(ta));  // 占用字节数 即 2个指针所占的字节大小为16; one在前8字节, two在后8字节.
    // 指针数组ta,存储的是{"one", "two"}的首地址.  tp是指向指针的指针
    // *tp中的p是一级指针, tp的值为{"one", "two"}的首地址, 故*tp的内容为"one\0"
    // **中的tp是为二级指针, 因为*tp的值是"one\0"的首地址, 所以**tp的内容是'o'

    printf("%s\t", (*tp + 1));  // *tp的值是"one\0"的首地址, 加1即为字符'n'的地址. 结果: ne
    printf("%s\t", *(tp + 1));  // tp的值为{"one", "two"}的首地址, 加1表示 移动1个sizeof(指针)单位, 到后8字节. 结果: two
    printf("%c\t", **tp);  // **中的tp是为二级指针, 因为*tp的值是"one\0"的首地址, 所以**tp的内容是'o'. 结果: o
    printf("%s\t", *(tp++) + 1);  // tp++后置的话,先用tp. 则首先是 *tp+1 到字符'n'的地址. 结果: ne
    printf("%c\n", **tp - 1);   // 接着继续参与上述没完成的指针的++运算, tp移动到字符't', 然后再执行普通运算 t-1. 结果: s

    printf("%s\t", *(--tp) + 1);  // 接着, 指针运算--在前先运算,向后移动1个指针字节单位,tp移动到了字符'o'的位置,然后再执行加1字节,到'n'. 结果: ne
    printf("%s\t", *(++tp) + 1);  // 接着运算, 思路参上,先移动到后8字节,tp移动到了字符't'的位置, 然后再执行加1字节, 到'w'. 结果: wo
    printf("%c\t", **tp);  // 接着, 因为此时tp在字符't'的位置, **中的tp是为二级指针, 因为*tp的值是"two\0"的首地址, 所以**tp的内容是't'. 结果: t
    printf("%c\t", **(tp--));  // 接着, --在后,先用, 故同上. 结果: t
    printf("%s\n", *tp);  // 接着, 先接着执行上面未完成的--, tp移动到了字符'o'的位置, 所以*tp的内容是'one'. 结果: one

    //    ne      two     o       ne      s
    //    ne      wo      t       t       one

    return 0;
}