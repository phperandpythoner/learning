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

/*
//数组指针
int main()
{
    int a[3] = {0,1,2};
    int n;
    int i;
    // 指针数组，它是数组，每个元素都是指针
    int *p[3];

    printf("%d\n", sizeof(a));

    //数组赋值指针数组，方法一
    //p[0] = &a[0];
    //p[1] = &a[1];
    //p[2] = &a[2];

    //数组赋值指针数组，方法二
    //p[0] = a;
    //p[1] = a+1;
    //p[2] = a+2;

    n = sizeof(p)/sizeof(p[0]);

    //数组赋值指针数组，方法三
    for(i=0;i<n;i++)
    {
        p[i] = &a[i]; // a+i
    }

    //打印指针数组
    for(i=0;i<n;i++)
    {
        // p[i]取指针变量的值，*p[i]取指针所指向内存的值
        //printf("%d\n", *p[i]);

        //p[1]==*(p+1),上面等价于
        printf("%d\n", *(*(p+i)));
    }

    return 0;
}
*/

/*
//值传递
void swap(int m, int n)
{
    int temp;

    printf("m=%d, n=%d\n", m, n);

    temp = m;
    m = n;
    n = temp;
    printf("m=%d, n=%d\n", m, n);
}

int main()
{
    int a = 10;
    int b = 20;
    swap(a, b);

    return 0;
}
*/

/*
//地址传递
void swap(int *m, int *n)
{
    int temp;
    temp = *m;
    *m = *n;
    *n = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    printf("a=%d,b=%d\n", a, b);
    swap(&a, &b);
    printf("a=%d,b=%d\n", a, b);

    return 0;
}
*/

/*
//形参中的数组
//1、形参中的数组，不是数组，是普通指针变量
//2、形参数组：int a[], int a[100], int *a对编译器而言，没有区别
//3、编译器都是当做int *处理
//4、形参中的数组和非形参中的数组区别：形参中的数组是指针变量，非形参中的数组是数组
//void printf_array(int a[])
//void printf_array(int a[100])
void printf_array(int *a)
{
    int n = sizeof(a)/sizeof(a[0]);
    int i;

    for(i=0;i<n;i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
}

//正确调用
void printf_array2(int a[], int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = {1,-2,3,-4,5,-6,7,-8,9};
    int n = sizeof(a)/sizeof(a[0]);
    int j;
    int i;
    int temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    //printf_array(a);
    printf_array2(a, n);

    return 0;
}
*/

/*
//返回值是指针
//案例说明：当调用一个函数的局部变量时，调用完了后局部变量会释放，则引用的指针会变成野指针（泛型指针）
//Linux 64位的会报错
int *fun()
{
    int a;

    return &a;
}
int main()
{
    int *p = NULL;
    p = fun(); //接收函数返回的地址
    *p = 100; //操作指针所指向的内存
    printf("*p=%p\n", *p); //*p=0000000000000064

    return 0;
}
*/

/*
//返回全局变量的地址
//1、在{}外面定义的变量，就是全局变量，全局变量任何地方都可以使用
//2、全局变量当程序结束时，才释放
int a;

int *fun()
{
    return &a;
}
int main()
{
    int *p = NULL;
    p = fun();
    *p = 100;
    printf("a=%d\n", a);

    //fun()返回地址，*(fun())赋值指针所指向内存的值
    *(fun()) = 200;
    printf("a=%d\n", a);

    return 0;
}
*/

/*
int main()
{
    char str[] = "hello world";
    int i = 0;

    //1、%s 从首元素开始打印，直到结束位置
    //2、%s 操作的是指针所指向的内容
    printf("str=%s\n", str);

    //2、str是首元素地址，想打印str本身的值，%p,%x,%d,%o
    printf("str = %p\n", str);

    //3、*str代表第0个元素，它是char类型
    printf("*str=%c\n", *str);

    while(str[i] != '\0') //str[i] == *(str+i)
    {
        printf("%c", str[i]);
        i++;
    }
    printf("\n");

    return 0;
}
*/

/*
//字符指针
int main()
{
    char str[] = "hello";
    str[0] = '1';
    str[1] = '2';
    printf("%s\n", str); //12llo

    char *p = NULL;
    p = str; //p = str[0];

    *p = 'a';
    p++;
    *p = 'b';
    printf("%s\n", str); //abllo
    printf("p=%s\n", p); //p=bllo
    printf("p-1=%s\n", p-1); //p-1=abllo

    return 0;
}
*/
