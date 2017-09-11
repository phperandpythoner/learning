#include <stdio.h>

/*
int main()
{
    printf("Hellod world!\n");
    return 0;
}
*/


/*
//指针大小
int main()
{
    //32位编译器使用32位大小（4字节）保存地址
    //64位编译器使用64位大小（8字节）保存地址

    int a = sizeof(int *);
    int b = sizeof(char *);
    double *p;
    int c = sizeof(p);
    printf("a=%d,b=%d,c=%d\n", a, b, c);
    return 0;
}
*/

/*
int main()
{
    int a = 10;
    int *p = &a;

    printf("a=%d, &a=%x, p=%x, *p=%d\n", a, &a, p, *p);

    // *p等价于 *(p+0),也等价于p[0]
    *(p+0) = 20;
    printf("a = %d\n", a);
    p[0] = 30;
    printf("a = %d\n", a);

    return 0;
}
*/

/*
//指针的步长
int main()
{
    //指针的加法不是数学运算方式，步长由指针的数据类型决定

    int a;
    int *p = &a;
    printf("p=%d, p+1=%d\n", p, p+1);

    char b;
    char *q = &b;
    printf("q=%d, q+1=%d\n", q, q+1);

    //运行结果
    //p=6356540, p+1=6356544
    //q=6356539, q+1=6356540

    return 0;
}
*/

/*
//万能指针
int main()
{
    //void不可以定义除指针类型以外的，void*指针 也叫做万能指针

    void *p = NULL;
    int a = 10;
    p = &a; //保存了a的首地址

    * ((int *)p) = 20; // 赋值需要对类型进行转换
    printf("a=%d\n", a);

    return 0;
}
*/

/*
//const修饰
int main()
{
    int a = 10;
    //const修饰*，代表指针所指向的内存是只读
    const int *p = &a;
    p = NULL; //right
    //*p = 100; // error

    //const修饰*，代表指针所指向的内存是只读
    int const *p2 = &a;
    //*p2 = 200; //error
    p2 = NULL; //right

    //const修饰变量，表示指针变量的值为只读
    int * const p3 = &a;
    *p3 = 300; //right
    //p3 = NULL; //error
    printf("a=%d\n", a);

    return 0;
}
*/


/*
//指向数组首元素的指针
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = NULL;
    p = &a[0];
    printf("*p=%x\n", *p);
    p = a;
    int i;
    for(i=0;i<10;i++){
        //printf("%d,", a[i]);

        //printf("%d,", *(a+i));

        //printf("%d,", p[i]);

        printf("%d,", *(p+i));
    }


    return 0;
}
*/

/*
//通过指针的加减法访问数组
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = a; //把数组首元素赋给指针
    p = &a[0];  //把数组首元素赋给指针
    printf("sizeof(a)=%d, sizeof(*a)=%d\n", sizeof(a), sizeof(*a)); //sizeof(a)=40, sizeof(*a)=4
    int n = sizeof(a)/sizeof(*a);
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d,", *p);
        p++;
    }
    printf("\n");

    //定义一个指针指向数组尾元素
    int *q = &a[n-1];
    printf("&a[n-1]=%d\n", &a[n-1]); //&a[n-1]=6356516
    q = a+n-1;
    printf("a+n-1=%d\n", a+n-1); //a+n-1=6356516
    for(i=0;i<n;i++)
    {
        printf("%d,",*q);
        q--;
    }
    printf("\n");

    return 0;
}
*/

int main()
{
    int a[3] = {1,2,3,4,5};
    printf("%d\n", sizeof(a));


    return 0;
}
