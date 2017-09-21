#include <stdio.h>
#include <string.h>

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

/*
#include <string.h>
//字符串常量
int main()
{
    //字符串常量就是次字符串的首元素地址
    printf("%p\n", "hello world"); //0000000000404000

    char *p1 = "hello world";
    printf("%p\n", p1); //0000000000404000

    char *p2 = "hello world";
    printf("%p\n", p2);//0000000000404000

    //字符串常量，文字常量区的字符串，只读，不能修改
    printf("%c\n", *p1);

    //p1指向的字符串常量，字符串常量为只读，不能修改
    //*p1 = 'a';

    char *p3 = "hello";
    //p3指向文字常量区，不能修改
    //strcpy(p3, "abc");

    return 0;
}
*/

/*
//main函数参数说明
//argv[]:它是数组，数组每个元素都是char *，每个元素都是字符地址
//argc:argv[]元素个数
//main()函数参数，需要用户传递
int main(int argc, char *argv[])
{
    int i = 0;
    for(i=0;i<argc;i++)
    {
        printf("%s\n", argv[i]);
    }

    return 0;
}
*/

/*
#include <string.h>
//查找匹配字符串出现的次数
int main()
{
    char *p = "11abcdzxzxzabcd555abcd777gfdabcdss";
    int i;
    char *temp = NULL;
    while(1)
    {
        //strstr:找出str2字符串在str1字符串中第一次出现的位置（不包括str2的串结束符）。返回该位置的指针，如找不到，返回空指针
        temp = strstr(p, "abcd");
        if(temp == NULL)//没找到
        {
            break;//跳出循环
        }
        else//找到
        {
            i++;//累加
            p = temp + strlen("abcd");//重新设置查询起始位置
        }
    }
    printf("%d\n", i);

    return 0;
}
*/

/*
#include <string.h>
//两头堵模型
int main()
{
    char *p = "      123456789     ";
    char *start = p; //首元素地址
    char *end = p+strlen(p)-1; //尾元素地址
    int n;

    //从左往右
    while( *start == ' ' && *start != '\0')
    {
        start++;
    }

    //从右往左
    while(*end == ' ' && *end != p)
    {
        end--;
    }

    n = end - start + 1;
    printf("start=%d\n", start);
    printf("end=%d\n", end);
    printf("string len=%d\n", n);

    return 0;
}
*/

/*
//普通局部变量
int main()
{
    //1、在{}定义的变量就是局部变量
    //2、只有执行到定义变量这个语句，系统才会分配变量空间
    //3、当离开{}，非static局部变量才释放
    //4、局部变量作用在{}，离开{}，无法使用变量
    //5、{}的普通局部变量，加不加auto关键字等价，普通局部变量也叫自动变量
    //6、不同的{}中，变量名可以一样，但使用时根据就近原则

    return 0;
}
*/

/*
//static局部变量
void static_fun()
{
    //1、在{}定义的变量就是局部变量
    //2、static局部变量，是在编译阶段就已分配空间，函数没有调用之前就已经存在
    //3、当离开{}，static局部变量不会释放，只有程序结束，static变量才会释放
    //4、局部变量作用在{}，离开{}，无法使用变量
    //5、不同的{}中，变量名可以一样，但使用时根据就近原则
    //6、如果static局部变量不初始化，默认值为0
    //7、static局部变量初始化语句只执行一次，但可以多次赋值
    //8、static局部变量只能用常量初始化（注意）

    static int i = 0;
    i++;
    printf("static_fun i = %d\n", i);

    //int a = 10;
    //static int j = a; //error:initializer element is not constant
}

int main()
{
    static_fun();
    static_fun();
    static_fun();

    return 0;
}
*/

/*
//内存操作函数--memset()
int main()
{
    int a;
    memset(&a, 0, sizeof(a)); //常用，用作清空变量值
    printf("a=%d\n", a);

    //中间参数虽然是整型，但以acssi字符处理
    memset(&a, 97, sizeof(a));
    printf("a1=%c\n", a);

    //也可以用户赋值
    char str[10];
    memset(str, 'a', sizeof(str));
    int i;
    int n = sizeof(str)/sizeof(str[0]);
    for(i=0;i<n;i++)
    {
        printf("%c,", str[i]);
    }
    printf("\n");

    return 0;
}
*/

/*
//内存操作函数--memcpy()
#include <string.h>
int main()
{
    char p[] = "hello\0world";
    char buf[100];
    printf("sizeof(p)=%lu\n", sizeof(p));

    //strncpy遇到结束符'\0'，就结束
    strncpy(buf, p, sizeof(p));
    printf("buf1=%s\n", buf);
    printf("buf2=%s\n", buf+strlen("hello")+1);

    memset(buf, 0, sizeof(buf));
    //把变量整拷贝到buf中
    memcpy(buf, p, sizeof(p));
    printf("buf3=%s\n", buf);
    printf("buf4=%s\n", buf+strlen("hello")+1);

    return 0;
}
*/

/*
//内存操作函数--memmove()
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[10];

    //第三个参数是指拷贝内存的总大小
    //memcpy(b, a, 10 * sizeof(int));
    //这两个相等
    //memcpy(b, a, sizeof(a));

    //使用memcpy最好别出现重叠，如果出现内存重叠，，使用memmove
    memmove(&a[2], a, 5 * sizeof(int));

    return 0;
}
*/

/*
//内存操作函数--memcmp(),主要用于比较内存里两数据是否相等
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[10] = {1,2,3,4,5,6,7,8,9,11};
    int flag = memcmp(a, b, 10 * sizeof(int));
    if(flag < 0)
    {
        printf("a < b\n");
    }
    else if(flag > 0)
    {
        printf("a > b\n");
    }
    else if(flag == 0)
    {
        printf("a == b");
    }

    return 0;
}
*/

/*
//指针指向堆区空间
int main()
{
    //malloc(sizeof(int))
    //参数是指定堆区分配多大的空间
    //返回值：成功则返回堆区空间首元素地址；失败则返回NULL

    //原型：extern void *malloc(unsigned int num_bytes);
    //头文件：#include <malloc.h> 或 #include <alloc.h> (注意：alloc.h 与 malloc.h 的内容是完全一致的。)
    //功能：分配长度为num_bytes字节的内存块
    //说明：如果分配成功则返回指向被分配内存的指针，否则返回空指针NULL。
    //当内存不再使用时，应使用free()函数将内存块释放。

    int *p = NULL;
    p = (int *) malloc(sizeof(int));
    if(p == NULL)
    {
        printf("分配空间失败\n");
        return -1;//结束程序
    }

    *p = 10;
    printf("*p=%d\n", *p);

    if(NULL != p)
    {
        free(p);
        p = NULL;
    }

    //说明：
    //1、动态分配的空间，如果程序没有结束，不会自动释放
    //2、一般使用完，需要人为释放free(p)
    //3、free(p);不是释放p变量，是释放p所指向的内存
    //4、同一块堆区内存只能释放一次
    //5、释放是指系统回收了，如果用户再用，就是操作非法内存

    return 0;
}
*/

/*
//堆区空间越界
#include <string.h>
#include <stdlib.h>
int main()
{
    char *p = NULL;
    p = (char *)malloc(0);//为字符指针变量p分配空间大小为0
    if(p == NULL)
    {
        printf("分配失败\n");
    }
    strcpy(p, "hello world");
    printf("p=%s\n", p);

    free(p);

    return 0;
}
*/

/*
//值传递
void fun(int *tmp)
{
    *tmp = 100;
}

int main()
{
    int *p = NULL;
    //malloc函数在堆区为p分配空间
    p = (int *)malloc(sizeof(int));
    //调用函数fun(p)，tmp变量指向p在堆区的空间，当fun()自动释放栈区tmp变量，但不会释放堆区里的空间
    fun(p);
    printf("*p=%d\n", *p);

    return 0;
}
*/


/*
//返回堆区地址
int *fun()
{
    int *tmp = NULL;
    tmp = (int *)malloc(sizeof(int));
    *tmp = 100;
    return tmp;//返回堆区地址，返回调用完毕，不释放
}
int main()
{
    int *p = NULL;
    p = fun();
    printf("*p=%d\n", *p);

    //堆区空间使用完毕，手动释放
    if(p != NULL)
    {
        free(p);
        p = NULL;
    }

    return 0;
}
*/


/*
//结构基本使用
#include <string.h>
struct Student
{
    //结构体内不能直接赋值给成员，因为没有分配空间
    int age;
    char name[50];
    int score;
};//有分号

//介绍两种不常用的结构体定义方法
//1、在定义结构体时定义变量名，并且可以给变量赋值
struct Student1
{
    int age;
    char name[50];
    int score;
}s1={20, "xiaoming", 60}, s2;
//2、匿名结构体
struct
{
    int age;
    char name[50];
    int score;
}s3={30, "test", 70}, s4;

int main()
{
    //定义结构体变量
    //1、类型名、变量名
    struct Student stu;

    //1、结构体变量初始化，和数组一样，要使用大括号
    //2、只有在定义时才能初始化
    struct Student stu2 = {19, "allen", 100};

    //使用结构体成员，不能直接使用，需要借用结构体变量来引用
    struct Student tmp;

    //如果是普通变量使用.点运算符
    tmp.age = 18;
    //tmp.name = "mike";//name成员是数组名，数组名是常量，不能修改
    strcpy(tmp.name, "mike");
    tmp.score = 99;

    //如果是指针变量，使用->
    //如果是指针，指针有合法指向，才能操作结构体成员
    struct Student *p;
    p = &tmp;//合法指向
    p->age = 17;
    strcpy(p->name, "mike");
    p->score = 98;

    //任何结构体变量都可以使用.和->操作成员
    (&tmp)->age = 17;

    (*p).score = 97;

    printf("(&tmp)=%d\n", (&tmp)->age);
    printf("(*p).score=%d\n", (*p).score);

    //result:
    //(&tmp)=17
    //(*p).score=97

    printf("s1.age=%d, s1.name=%s, s1.score=%d\n", s1.age, s1.name, s1.score);
    printf("s3.age=%d, s3.name=%s, s3.score=%d\n", s3.age, s3.name, s3.score);

    return 0;
}
*/


/*
//结构体数组
#include <string.h>
struct Student
{
    //结构体内不能直接赋值给成员，因为没有分配空间
    int age;
    char name[50];
    int score;
};//有分号

int main()
{
    //给结构体数组赋值1
    printf("********** 给结构体数组赋值1 **************\n");
    struct Student s[5]; //结构体数组
    //操作元素
    s[0].age = 18;
    strcpy(s[0].name, "test1");
    s[0].score = 60;

    (*(s+1)).age = 19;
    strcpy((*(s+1)).name, "test2");
    (*(s+1)).score = 61;

    //操作地址

    (s+2)->age = 20;
    strcpy((s+2)->name, "test3");
    (s+2)->score = 62;

    //通过指针操作
    struct Student *p = s;
    //p = &s[0];
    (p+3)->age = 21;
    strcpy((p+3)->name, "test4");
    (p+3)->score = 63;

    p[4].age = 22;
    strcpy(p[4].name, "test5");
    p[4].score = 64;

    int n = sizeof(s)/sizeof(s[0]);
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d, %s, %d\n", s[i].age, s[i].name, s[i].score);
    }


    //给结构体数组赋值2
    printf("\n********** 给结构体数组赋值2 **************\n");
    struct Student s2[5] = {
        {23, "test6", 65},
        {24, "test7", 66},
        {25, "test8", 67},
        {26, "test9", 68},
        {27, "test10", 69}
    };
    int n2 = sizeof(s2)/sizeof(s2[0]);
    for(i = 0; i < n2; i++)
    {
        printf("%d, %s, %d\n", s2[i].age, s2[i].name, s2[i].score);
    }


    //给结构体数组赋值3
    printf("\n********** 给结构体数组赋值3 **************\n");
    struct Student s3[5] = {
        23, "test6", 70,
        24, "test7", 71,
        25, "test8", 72,
        26, "test9", 73,
        27, "test10", 74
    };
    int n3= sizeof(s3)/sizeof(s3[0]);
    for(i = 0; i < n3; i++)
    {
        printf("%d, %s, %d\n", s3[i].age, s3[i].name, s3[i].score);
    }

    return 0;
}
*/

/*
//结构体的嵌套
#include <string.h>
struct Info
{
    int age;
    char name[50];
};

struct Student
{
    struct Info info;
    int score;
};

int main()
{
    struct Student s;
    s.info.age = 18;
    strcpy(s.info.name, "allen");
    s.score = 60;
    printf("%d, %s, %d\n", s.info.age, s.info.name, s.score);

    struct Student *p = &s;//如果是数组，数组名则是首地址；如果是普通变量，则需要加取地址&
    p->info.age = 19;
    strcpy(p->info.name, "iverson");
    p->score = 20;
    printf("%d, %s, %d\n", p->info.age, p->info.name, p->score);

    //在定义变量时直接赋值
    struct Student tmp = {21, "xiaoming", 62};
    printf("%d, %s, %d\n", tmp.info.age, tmp.info.name, tmp.score);

    return 0;
}
*/


/*
//同类型的结构体变量赋值
struct Student
{
    //结构体内不能直接赋值给成员，因为没有分配空间
    int age;
    char name[50];
    int score;
};//有分号

int main()
{
    //相同类型的两个结构体可以相互赋值
    //尽管两个结构体的内容一样，但两个变量时没有关系的独立内存
    struct Student s1 = {18, "allen", 60};
    struct Student s2;
    s2 = s1;
    printf("%d, %s, %d\n", s2.age, s2.name, s2.score);

    return 0;
}
*/

/*
//指针指向堆区空间
#include <string.h>
struct Student
{
    //结构体内不能直接赋值给成员，因为没有分配空间
    int age;
    char name[50];
    int score;
};//有分号

int main()
{
    struct Student *p = NULL;

    //指针指向堆区空间
    p = (struct Student *)malloc(sizeof(struct Student));
    if(p == NULL)
    {
        printf("分配失败");
        return 0;
    }

    p->age = 18;
    strcpy(p->name, "allen");
    p->score = 60;
    printf("%d, %s, %d\n", p->age, p->name, p->score);

    if(p != NULL)
    {
        free(p);
        p = NULL;
    }

    return 0;
}
*/

/*
//结构体成员指针指向data区或栈区和指向堆区
#include <string.h>
#include <stdlib.h>
struct Student
{
    int age;
    char *name;
    int score;
    char *nickname;
};

int main()
{
    struct Student s;
    s.age = 18;

    char buf[100];
    s.name = buf;//指向栈区空间
    strcpy(s.name, "mike");

    s.score = 59;
    printf("buf=%s\n", buf);

    //成员变量指针指向堆区空间
    s.nickname = (struct Student *)malloc( strlen("allen") + 1 );
    strcpy(s.nickname, "allen");

    printf("%d, %s, %d, %s\n", s.age, s.name, s.score, s.nickname);

    return 0;
}
*/


/*
//结构体套一级指针
#include <string.h>
#include <stdlib.h>
struct Student
{
    int age;
    char *name;
    int score;
};

int main()
{
    struct Student *p;
    p = (struct Student *)malloc(sizeof(struct Student));
    if(p = NULL)
    {
        printf("malloc error\n");
        return 0;
    }

    //p->name = (char *)malloc((strlen("allen")+1) * sizeof(char));//标准写法
    p->name = (char *)malloc( strlen("mike") + 1 );//出现了段错误

    p->age = 18;
    strcpy(p->name, "mike");
    p->score = 59;
    printf("%d, %s, %d\n", p->age, p->name, p->score);

    //堆区空间释放，先释放子节点，在释放根节点
    if(p->name != NULL)
    {
        free(p->name);
        p->name = NULL;
    }

    if(p != NULL)
    {
        free(p);
        p = NULL;
    }

    return 0;
}
*/


/*
//共用体（联合体）
union Test
{
    unsigned char a;//1字节
    unsigned short b;//2字节
    unsigned int c;//4字节
};

int main()
{
    //共用体的大小为最大成员的大小
    printf("%lu\n", sizeof(union Test));

    //共用体公用一块内存，所有成员的地址一样
    union Test obj;
    printf("%p, %p, %p, %p\n", obj, obj.a, obj.b, obj.c);

    //给某个成员赋值会影响到其他成员
    //左边是高位，右边是低位
    //高位放高地址，低位放低地址（小端）
    obj.c = 0x44332211;
    printf("obj.c=%x\n", obj.c);
    printf("obj.b=%x\n", obj.b);
    printf("obj.a=%x\n", obj.a);

    obj.b = 0xbbaa;
    printf("obj.c=%x\n", obj.c);
    printf("obj.b=%x\n", obj.b);
    printf("obj.a=%x\n", obj.a);

    return 0;
}
*/


/*
//枚举类型
//enum是关键字
//里面的成员是一个标识符，枚举常量
//枚举类型enum Color
//第一个没有赋值，默认值为0，下一个成员比上一个成员多1
//成员：枚举成员，枚举常量
enum Color
{
    red, blue, yellow, green, pink=10, black, white
};

int main()
{
    int flag = 1;
    if(flag == blue)
    {
        printf("blue\n");
    }

    //枚举变量
    enum Color flag2;

    //可以使用枚举成员给flag2赋值
    flag2 = black;

    return 0;
}
*/


/*
//typedef使用
//给struct Test结构体起一个别名Info
typedef struct Test
{
    int age;
}Info;

int main()
{
    //typedef给一个存在的类型起一个别名
    //typedef不能创建新类型
    typedef int int64;//给int取一个别名int64

    //定义一个变量
    Info info;
    info.age = 19;
    printf("%d\n", info.age);


    return 0;
}
*/


/*
//标准文件指针
int main()
{
    printf("123\n");
    //fclose(stdout);//关闭标准输出文件指针
    printf("456\n");

    //打印库函数失败的原因
    perror("result");
    fclose(stderr);//关闭标准错误输出文件指针
    perror("result2");

    int a;
    printf("enter a:");
    fclose(stdin); //关闭标准输入文件指针
    scanf("%d", &a);
    printf("a=%d\n", a);

    return 0;
}
*/


/*
//标准文件指针
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    //printf()函数的内部实现，往标准输出设备(1)写内容
    printf("before aaaaaaaaaaaaaaaaa\n");
    //fclose(stdout);
    close(1);//1代表标准输出设备，关闭了，1就是空闲的数字

    int fd = open("1.txt", O_WRONLY, 0777);

    //printf()函数的内部实现，往1写内容，但是现在1和1.txt关联，printf的内容写到1.txt
    printf("fd = %d\n", fd);

    printf("after bbbbbbbbbbbb1\n");
    printf("after cccccccccccc2\n");
    printf("after dddddddddddd3\n");

    return 0;
}
*/

/*
//fputc()函数
#include <string.h>
int main()
{
    //1、打开文件
    FILE *fp = NULL;
    fp = fopen("2.txt", "w");
    if(fp == NULL)
    {
        perror("fopen file fialed");
        return -1;
    }

    //2、写文件
    char ch = 'a';
    while(ch <= 'z')//字符可以比较大小
    {
        fputc(ch, fp);
        ch++;
    }

    char ch2[] = "-12-13-14-15-16";
    int i;
    int n = strlen(ch2);
    for(i = 0; i < n; i++)
    {
        fputc(ch2[i], fp);
    }

    //3、关闭文件
    fclose(fp);
    fp = NULL;

    return 0;
}
*/

/*
//fgetc()函数
#include <string.h>
int main()
{
    //1、打开文件
    FILE *fp = NULL;
    fp = fopen("2.txt", "r");
    if(fp == NULL)
    {
        perror("fopen file fialed");
        return -1;
    }

    //2、读文件
    char ch;
    while(1)
    {
        ch = fgetc(fp);
        printf("%d\n", ch);
        //if(ch == -1)
        //if(ch == EOF) //EOF == -1
        if(feof(fp))
        {
            break;
        }
    }

    //3、关闭文件
    fclose(fp);
    fp = NULL;

    return 0;
}
*/

/*
int calc(int a, int b, char ch)
{
    switch(ch)
    {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        default:
            return 0;
    }

    return 0;
}

void write_file()
{
    FILE *fp = fopen("3.txt", "w");

    char *buf[4];
    buf[0] = "10+10=\n";
    buf[1] = "10-10=\n";
    buf[2] = "10*10=\n";
    buf[3] = "10/10=\n";

    int i;
    int n = sizeof(buf)/sizeof(buf[0]);
    for(i = 0; i < n; i++)
    {
        fputs(buf[i], fp);
        //printf("%s\n", buf[i]);
    }

    fclose(fp);

}

void read_file()
{
    FILE *fp = fopen("3.txt", "r");

    char buf[1024];
    char tmp[2048] = {0};
    while(1)
    {
        memset(buf, 0, sizeof(buf));
        fgets(buf, sizeof(buf), fp);
        if(strlen(buf) > 0)
        {
            int a,b;
            char ch;
            //printf("%s\n", buf);
            //sscanf会从buffer里读进数据，依照format的格式将数据写入到argument里
            sscanf(buf, "%d%c%d", &a, &ch, &b);
            //sprintf() 用于将输出存到字符缓冲中
            //函数原型：sprintf(char *buffer, const char *format, [argument]);
            sprintf(buf, "%d%c%d=%d\n", a, ch, b, calc(a,b,ch));
            strcat(tmp, buf);
        }
        if(feof(fp))
        {
            break;
        }
    }

    //printf("%s\n", tmp);

    fclose(fp);

    fp = fopen("4.txt", "w");
    fputs(tmp, fp);
    fclose(fp);
}

int main()
{
    //write_file();

    read_file();

    return 0;
}
*/


#include <stdlib.h>
typedef struct Student
{
    int age;
    char name[50];
    int score;
}Stu;

//fprintf():将agars(参数表)内各项的值，按format(格式控制字符串)所表示的格式，将数据格式为字符串的形式写入到文件指针fp指向的文件中。
//原型：fprintf(FILE *fp, const char *format, agars)
void file_fprintf()
{
    FILE *fp = NULL;
    fp = fopen("tmp/fprintf.txt", "w+");
    if(fp == NULL)
    {
        perror("fopen");
        return;
    }

    Stu s[4] = {
        18, "allen", 59,
        19, "iverson", 60,
        20, "kobe", 61,
        21, "yao", 62
    };

    int n = sizeof(s)/sizeof(s[0]);
    int i = 0;;
    for(i = 0; i < n; i++)
    {
        fprintf(fp, "%d, %s, %d\n", s[i].age, s[i].name, s[i].score);
    }

    fclose(fp);
    fp = NULL;
}

//fscanf():从文件指针fp指向的文件中，按format中对应的控制格式读取数据，并存储在agars对应的变量中；
//原型: fscanf(FILE *fp, const char *format, agars)
void file_fscanf()
{
    FILE *fp = NULL;
    fp = fopen("tmp/fprintf.txt", "r+");
    if(fp == NULL)
    {
        perror("fopen");
        return;
    }

    Stu s[4];
    int n = sizeof(s)/sizeof(s[0]);
    int i = 0;
    int age,score;
    char name[50];

    while(1)
    {
        memset(name, 0, sizeof(name));
        fscanf(fp, "%d, %s, %d\n", &age, &name, &score);
        //printf("%d,%s,%d\n", age, name, score);
        if(strlen(name) > 0)
        {
            s[i].age = age;
            strcpy(s[i].name, name);
            s[i].score = score;
        }

        if(feof(fp))
        {
            break;
        }
        i++;
    }

    for(i=0;i<n;i++)
    {
        printf("age=%d, name=%s, score=%d\n", s[i].age, s[i].name, s[i].score);
    }


    fclose(fp);
    fp = NULL;
}

//在C语言中fwrite()函数常用语将一块内存区域中的数据写入到本地文本
//size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);
//-- buffer:指向数据块的指针
//-- size:每个数据的大小，单位为Byte(例如：sizeof(int)就是4)
//-- count:数据个数
//-- stream:文件指针
void file_fwrite()
{
    FILE *fp = NULL;
    fp = fopen("./tmp/fwrite.txt", "w+");
    if(fp == NULL)
    {
        perror("fwrite fopen");
        return;
    }

    Stu s[4] = {
        18, "allen", 59,
        19, "iverson", 60,
        20, "kobe", 61,
        21, "yao", 62
    };

    int i = 0;
    int n = sizeof(s)/sizeof(s[0]);
    for(i=0;i<n;i++)
    {
        int ret = fwrite(&s[i], 1, sizeof(s[i]), fp);
        printf("ret = %d\n", ret);
    }

    fclose(fp);
    fp = NULL;
}

//fread()
//作用：从一个文件流中读取数据
//size_t fread(void *buffer, size_t size, size_t count, FILE *stream);
//  -- buffer:指向数据块的指针
//  -- size:每个数据的大小，单位为Byte(例如：sizeof(int)就是4)
//  -- count:数据个数
//  -- stream:文件指针
void file_fread()
{
    FILE *fp = NULL;
    fp = fopen("./tmp/fwrite.txt", "r");
    if(fp == NULL)
    {
        perror("fread fopen");
        return;
    }

    Stu s[4];

    int i = 0;
    int ret = fread(&s[0], 1, sizeof(s)*4, fp);

    int n = sizeof(s)/sizeof(s[0]);

    for(i=0;i<n;i++)
    {
        printf("%d, %s, %d\n", s[i].age, s[i].name, s[i].score);
    }

    fclose(fp);
}

int main()
{
    //file_fprintf();

    //file_fscanf();

    //file_fwrite();

    file_fread();

    return 0;
}
