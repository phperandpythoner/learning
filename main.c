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
//ָ���С
int main()
{
    //32λ������ʹ��32λ��С��4�ֽڣ������ַ
    //64λ������ʹ��64λ��С��8�ֽڣ������ַ

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

    // *p�ȼ��� *(p+0),Ҳ�ȼ���p[0]
    *(p+0) = 20;
    printf("a = %d\n", a);
    p[0] = 30;
    printf("a = %d\n", a);

    return 0;
}
*/

/*
//ָ��Ĳ���
int main()
{
    //ָ��ļӷ�������ѧ���㷽ʽ��������ָ����������;���

    int a;
    int *p = &a;
    printf("p=%d, p+1=%d\n", p, p+1);

    char b;
    char *q = &b;
    printf("q=%d, q+1=%d\n", q, q+1);

    //���н��
    //p=6356540, p+1=6356544
    //q=6356539, q+1=6356540

    return 0;
}
*/

/*
//����ָ��
int main()
{
    //void�����Զ����ָ����������ģ�void*ָ�� Ҳ��������ָ��

    void *p = NULL;
    int a = 10;
    p = &a; //������a���׵�ַ

    * ((int *)p) = 20; // ��ֵ��Ҫ�����ͽ���ת��
    printf("a=%d\n", a);

    return 0;
}
*/

/*
//const����
int main()
{
    int a = 10;
    //const����*������ָ����ָ����ڴ���ֻ��
    const int *p = &a;
    p = NULL; //right
    //*p = 100; // error

    //const����*������ָ����ָ����ڴ���ֻ��
    int const *p2 = &a;
    //*p2 = 200; //error
    p2 = NULL; //right

    //const���α�������ʾָ�������ֵΪֻ��
    int * const p3 = &a;
    *p3 = 300; //right
    //p3 = NULL; //error
    printf("a=%d\n", a);

    return 0;
}
*/


/*
//ָ��������Ԫ�ص�ָ��
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
//ͨ��ָ��ļӼ�����������
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = a; //��������Ԫ�ظ���ָ��
    p = &a[0];  //��������Ԫ�ظ���ָ��
    printf("sizeof(a)=%d, sizeof(*a)=%d\n", sizeof(a), sizeof(*a)); //sizeof(a)=40, sizeof(*a)=4
    int n = sizeof(a)/sizeof(*a);
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d,", *p);
        p++;
    }
    printf("\n");

    //����һ��ָ��ָ������βԪ��
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
//����ָ��
int main()
{
    int a[3] = {0,1,2};
    int n;
    int i;
    // ָ�����飬�������飬ÿ��Ԫ�ض���ָ��
    int *p[3];

    printf("%d\n", sizeof(a));

    //���鸳ֵָ�����飬����һ
    //p[0] = &a[0];
    //p[1] = &a[1];
    //p[2] = &a[2];

    //���鸳ֵָ�����飬������
    //p[0] = a;
    //p[1] = a+1;
    //p[2] = a+2;

    n = sizeof(p)/sizeof(p[0]);

    //���鸳ֵָ�����飬������
    for(i=0;i<n;i++)
    {
        p[i] = &a[i]; // a+i
    }

    //��ӡָ������
    for(i=0;i<n;i++)
    {
        // p[i]ȡָ�������ֵ��*p[i]ȡָ����ָ���ڴ��ֵ
        //printf("%d\n", *p[i]);

        //p[1]==*(p+1),����ȼ���
        printf("%d\n", *(*(p+i)));
    }

    return 0;
}
*/

/*
//ֵ����
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
//��ַ����
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
//�β��е�����
//1���β��е����飬�������飬����ָͨ�����
//2���β����飺int a[], int a[100], int *a�Ա��������ԣ�û������
//3�����������ǵ���int *����
//4���β��е�����ͷ��β��е����������β��е�������ָ����������β��е�����������
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

//��ȷ����
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
//����ֵ��ָ��
//����˵����������һ�������ľֲ�����ʱ���������˺�ֲ��������ͷţ������õ�ָ�����Ұָ�루����ָ�룩
//Linux 64λ�Ļᱨ��
int *fun()
{
    int a;

    return &a;
}
int main()
{
    int *p = NULL;
    p = fun(); //���պ������صĵ�ַ
    *p = 100; //����ָ����ָ����ڴ�
    printf("*p=%p\n", *p); //*p=0000000000000064

    return 0;
}
*/

/*
//����ȫ�ֱ����ĵ�ַ
//1����{}���涨��ı���������ȫ�ֱ�����ȫ�ֱ����κεط�������ʹ��
//2��ȫ�ֱ������������ʱ�����ͷ�
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

    //fun()���ص�ַ��*(fun())��ֵָ����ָ���ڴ��ֵ
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

    //1��%s ����Ԫ�ؿ�ʼ��ӡ��ֱ������λ��
    //2��%s ��������ָ����ָ�������
    printf("str=%s\n", str);

    //2��str����Ԫ�ص�ַ�����ӡstr�����ֵ��%p,%x,%d,%o
    printf("str = %p\n", str);

    //3��*str�����0��Ԫ�أ�����char����
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
//�ַ�ָ��
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
//�ַ�������
int main()
{
    //�ַ����������Ǵ��ַ�������Ԫ�ص�ַ
    printf("%p\n", "hello world"); //0000000000404000

    char *p1 = "hello world";
    printf("%p\n", p1); //0000000000404000

    char *p2 = "hello world";
    printf("%p\n", p2);//0000000000404000

    //�ַ������������ֳ��������ַ�����ֻ���������޸�
    printf("%c\n", *p1);

    //p1ָ����ַ����������ַ�������Ϊֻ���������޸�
    //*p1 = 'a';

    char *p3 = "hello";
    //p3ָ�����ֳ������������޸�
    //strcpy(p3, "abc");

    return 0;
}
*/

/*
//main��������˵��
//argv[]:�������飬����ÿ��Ԫ�ض���char *��ÿ��Ԫ�ض����ַ���ַ
//argc:argv[]Ԫ�ظ���
//main()������������Ҫ�û�����
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
//����ƥ���ַ������ֵĴ���
int main()
{
    char *p = "11abcdzxzxzabcd555abcd777gfdabcdss";
    int i;
    char *temp = NULL;
    while(1)
    {
        //strstr:�ҳ�str2�ַ�����str1�ַ����е�һ�γ��ֵ�λ�ã�������str2�Ĵ��������������ظ�λ�õ�ָ�룬���Ҳ��������ؿ�ָ��
        temp = strstr(p, "abcd");
        if(temp == NULL)//û�ҵ�
        {
            break;//����ѭ��
        }
        else//�ҵ�
        {
            i++;//�ۼ�
            p = temp + strlen("abcd");//�������ò�ѯ��ʼλ��
        }
    }
    printf("%d\n", i);

    return 0;
}
*/

/*
#include <string.h>
//��ͷ��ģ��
int main()
{
    char *p = "      123456789     ";
    char *start = p; //��Ԫ�ص�ַ
    char *end = p+strlen(p)-1; //βԪ�ص�ַ
    int n;

    //��������
    while( *start == ' ' && *start != '\0')
    {
        start++;
    }

    //��������
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
//��ͨ�ֲ�����
int main()
{
    //1����{}����ı������Ǿֲ�����
    //2��ֻ��ִ�е�������������䣬ϵͳ�Ż��������ռ�
    //3�����뿪{}����static�ֲ��������ͷ�
    //4���ֲ�����������{}���뿪{}���޷�ʹ�ñ���
    //5��{}����ͨ�ֲ��������Ӳ���auto�ؼ��ֵȼۣ���ͨ�ֲ�����Ҳ���Զ�����
    //6����ͬ��{}�У�����������һ������ʹ��ʱ���ݾͽ�ԭ��

    return 0;
}
*/

/*
//static�ֲ�����
void static_fun()
{
    //1����{}����ı������Ǿֲ�����
    //2��static�ֲ����������ڱ���׶ξ��ѷ���ռ䣬����û�е���֮ǰ���Ѿ�����
    //3�����뿪{}��static�ֲ����������ͷţ�ֻ�г��������static�����Ż��ͷ�
    //4���ֲ�����������{}���뿪{}���޷�ʹ�ñ���
    //5����ͬ��{}�У�����������һ������ʹ��ʱ���ݾͽ�ԭ��
    //6�����static�ֲ���������ʼ����Ĭ��ֵΪ0
    //7��static�ֲ�������ʼ�����ִֻ��һ�Σ������Զ�θ�ֵ
    //8��static�ֲ�����ֻ���ó�����ʼ����ע�⣩

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
//�ڴ��������--memset()
int main()
{
    int a;
    memset(&a, 0, sizeof(a)); //���ã�������ձ���ֵ
    printf("a=%d\n", a);

    //�м������Ȼ�����ͣ�����acssi�ַ�����
    memset(&a, 97, sizeof(a));
    printf("a1=%c\n", a);

    //Ҳ�����û���ֵ
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
//�ڴ��������--memcpy()
#include <string.h>
int main()
{
    char p[] = "hello\0world";
    char buf[100];
    printf("sizeof(p)=%lu\n", sizeof(p));

    //strncpy����������'\0'���ͽ���
    strncpy(buf, p, sizeof(p));
    printf("buf1=%s\n", buf);
    printf("buf2=%s\n", buf+strlen("hello")+1);

    memset(buf, 0, sizeof(buf));
    //�ѱ�����������buf��
    memcpy(buf, p, sizeof(p));
    printf("buf3=%s\n", buf);
    printf("buf4=%s\n", buf+strlen("hello")+1);

    return 0;
}
*/

/*
//�ڴ��������--memmove()
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[10];

    //������������ָ�����ڴ���ܴ�С
    //memcpy(b, a, 10 * sizeof(int));
    //���������
    //memcpy(b, a, sizeof(a));

    //ʹ��memcpy��ñ�����ص�����������ڴ��ص�����ʹ��memmove
    memmove(&a[2], a, 5 * sizeof(int));

    return 0;
}
*/

/*
//�ڴ��������--memcmp(),��Ҫ���ڱȽ��ڴ����������Ƿ����
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
//ָ��ָ������ռ�
int main()
{
    //malloc(sizeof(int))
    //������ָ������������Ŀռ�
    //����ֵ���ɹ��򷵻ض����ռ���Ԫ�ص�ַ��ʧ���򷵻�NULL

    //ԭ�ͣ�extern void *malloc(unsigned int num_bytes);
    //ͷ�ļ���#include <malloc.h> �� #include <alloc.h> (ע�⣺alloc.h �� malloc.h ����������ȫһ�µġ�)
    //���ܣ����䳤��Ϊnum_bytes�ֽڵ��ڴ��
    //˵�����������ɹ��򷵻�ָ�򱻷����ڴ��ָ�룬���򷵻ؿ�ָ��NULL��
    //���ڴ治��ʹ��ʱ��Ӧʹ��free()�������ڴ���ͷš�

    int *p = NULL;
    p = (int *) malloc(sizeof(int));
    if(p == NULL)
    {
        printf("����ռ�ʧ��\n");
        return -1;//��������
    }

    *p = 10;
    printf("*p=%d\n", *p);

    if(NULL != p)
    {
        free(p);
        p = NULL;
    }

    //˵����
    //1����̬����Ŀռ䣬�������û�н����������Զ��ͷ�
    //2��һ��ʹ���꣬��Ҫ��Ϊ�ͷ�free(p)
    //3��free(p);�����ͷ�p���������ͷ�p��ָ����ڴ�
    //4��ͬһ������ڴ�ֻ���ͷ�һ��
    //5���ͷ���ָϵͳ�����ˣ�����û����ã����ǲ����Ƿ��ڴ�

    return 0;
}
*/

/*
//�����ռ�Խ��
#include <string.h>
#include <stdlib.h>
int main()
{
    char *p = NULL;
    p = (char *)malloc(0);//Ϊ�ַ�ָ�����p����ռ��СΪ0
    if(p == NULL)
    {
        printf("����ʧ��\n");
    }
    strcpy(p, "hello world");
    printf("p=%s\n", p);

    free(p);

    return 0;
}
*/

/*
//ֵ����
void fun(int *tmp)
{
    *tmp = 100;
}

int main()
{
    int *p = NULL;
    //malloc�����ڶ���Ϊp����ռ�
    p = (int *)malloc(sizeof(int));
    //���ú���fun(p)��tmp����ָ��p�ڶ����Ŀռ䣬��fun()�Զ��ͷ�ջ��tmp�������������ͷŶ�����Ŀռ�
    fun(p);
    printf("*p=%d\n", *p);

    return 0;
}
*/


/*
//���ض�����ַ
int *fun()
{
    int *tmp = NULL;
    tmp = (int *)malloc(sizeof(int));
    *tmp = 100;
    return tmp;//���ض�����ַ�����ص�����ϣ����ͷ�
}
int main()
{
    int *p = NULL;
    p = fun();
    printf("*p=%d\n", *p);

    //�����ռ�ʹ����ϣ��ֶ��ͷ�
    if(p != NULL)
    {
        free(p);
        p = NULL;
    }

    return 0;
}
*/


/*
//�ṹ����ʹ��
#include <string.h>
struct Student
{
    //�ṹ���ڲ���ֱ�Ӹ�ֵ����Ա����Ϊû�з���ռ�
    int age;
    char name[50];
    int score;
};//�зֺ�

//�������ֲ����õĽṹ�嶨�巽��
//1���ڶ���ṹ��ʱ��������������ҿ��Ը�������ֵ
struct Student1
{
    int age;
    char name[50];
    int score;
}s1={20, "xiaoming", 60}, s2;
//2�������ṹ��
struct
{
    int age;
    char name[50];
    int score;
}s3={30, "test", 70}, s4;

int main()
{
    //����ṹ�����
    //1����������������
    struct Student stu;

    //1���ṹ�������ʼ����������һ����Ҫʹ�ô�����
    //2��ֻ���ڶ���ʱ���ܳ�ʼ��
    struct Student stu2 = {19, "allen", 100};

    //ʹ�ýṹ���Ա������ֱ��ʹ�ã���Ҫ���ýṹ�����������
    struct Student tmp;

    //�������ͨ����ʹ��.�������
    tmp.age = 18;
    //tmp.name = "mike";//name��Ա�����������������ǳ����������޸�
    strcpy(tmp.name, "mike");
    tmp.score = 99;

    //�����ָ�������ʹ��->
    //�����ָ�룬ָ���кϷ�ָ�򣬲��ܲ����ṹ���Ա
    struct Student *p;
    p = &tmp;//�Ϸ�ָ��
    p->age = 17;
    strcpy(p->name, "mike");
    p->score = 98;

    //�κνṹ�����������ʹ��.��->������Ա
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
//�ṹ������
#include <string.h>
struct Student
{
    //�ṹ���ڲ���ֱ�Ӹ�ֵ����Ա����Ϊû�з���ռ�
    int age;
    char name[50];
    int score;
};//�зֺ�

int main()
{
    //���ṹ�����鸳ֵ1
    printf("********** ���ṹ�����鸳ֵ1 **************\n");
    struct Student s[5]; //�ṹ������
    //����Ԫ��
    s[0].age = 18;
    strcpy(s[0].name, "test1");
    s[0].score = 60;

    (*(s+1)).age = 19;
    strcpy((*(s+1)).name, "test2");
    (*(s+1)).score = 61;

    //������ַ

    (s+2)->age = 20;
    strcpy((s+2)->name, "test3");
    (s+2)->score = 62;

    //ͨ��ָ�����
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


    //���ṹ�����鸳ֵ2
    printf("\n********** ���ṹ�����鸳ֵ2 **************\n");
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


    //���ṹ�����鸳ֵ3
    printf("\n********** ���ṹ�����鸳ֵ3 **************\n");
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
//�ṹ���Ƕ��
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

    struct Student *p = &s;//��������飬�����������׵�ַ���������ͨ����������Ҫ��ȡ��ַ&
    p->info.age = 19;
    strcpy(p->info.name, "iverson");
    p->score = 20;
    printf("%d, %s, %d\n", p->info.age, p->info.name, p->score);

    //�ڶ������ʱֱ�Ӹ�ֵ
    struct Student tmp = {21, "xiaoming", 62};
    printf("%d, %s, %d\n", tmp.info.age, tmp.info.name, tmp.score);

    return 0;
}
*/


/*
//ͬ���͵Ľṹ�������ֵ
struct Student
{
    //�ṹ���ڲ���ֱ�Ӹ�ֵ����Ա����Ϊû�з���ռ�
    int age;
    char name[50];
    int score;
};//�зֺ�

int main()
{
    //��ͬ���͵������ṹ������໥��ֵ
    //���������ṹ�������һ��������������ʱû�й�ϵ�Ķ����ڴ�
    struct Student s1 = {18, "allen", 60};
    struct Student s2;
    s2 = s1;
    printf("%d, %s, %d\n", s2.age, s2.name, s2.score);

    return 0;
}
*/

/*
//ָ��ָ������ռ�
#include <string.h>
struct Student
{
    //�ṹ���ڲ���ֱ�Ӹ�ֵ����Ա����Ϊû�з���ռ�
    int age;
    char name[50];
    int score;
};//�зֺ�

int main()
{
    struct Student *p = NULL;

    //ָ��ָ������ռ�
    p = (struct Student *)malloc(sizeof(struct Student));
    if(p == NULL)
    {
        printf("����ʧ��");
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
//�ṹ���Աָ��ָ��data����ջ����ָ�����
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
    s.name = buf;//ָ��ջ���ռ�
    strcpy(s.name, "mike");

    s.score = 59;
    printf("buf=%s\n", buf);

    //��Ա����ָ��ָ������ռ�
    s.nickname = (struct Student *)malloc( strlen("allen") + 1 );
    strcpy(s.nickname, "allen");

    printf("%d, %s, %d, %s\n", s.age, s.name, s.score, s.nickname);

    return 0;
}
*/


/*
//�ṹ����һ��ָ��
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

    //p->name = (char *)malloc((strlen("allen")+1) * sizeof(char));//��׼д��
    p->name = (char *)malloc( strlen("mike") + 1 );//�����˶δ���

    p->age = 18;
    strcpy(p->name, "mike");
    p->score = 59;
    printf("%d, %s, %d\n", p->age, p->name, p->score);

    //�����ռ��ͷţ����ͷ��ӽڵ㣬���ͷŸ��ڵ�
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
//�����壨�����壩
union Test
{
    unsigned char a;//1�ֽ�
    unsigned short b;//2�ֽ�
    unsigned int c;//4�ֽ�
};

int main()
{
    //������Ĵ�СΪ����Ա�Ĵ�С
    printf("%lu\n", sizeof(union Test));

    //�����幫��һ���ڴ棬���г�Ա�ĵ�ַһ��
    union Test obj;
    printf("%p, %p, %p, %p\n", obj, obj.a, obj.b, obj.c);

    //��ĳ����Ա��ֵ��Ӱ�쵽������Ա
    //����Ǹ�λ���ұ��ǵ�λ
    //��λ�Ÿߵ�ַ����λ�ŵ͵�ַ��С�ˣ�
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
//ö������
//enum�ǹؼ���
//����ĳ�Ա��һ����ʶ����ö�ٳ���
//ö������enum Color
//��һ��û�и�ֵ��Ĭ��ֵΪ0����һ����Ա����һ����Ա��1
//��Ա��ö�ٳ�Ա��ö�ٳ���
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

    //ö�ٱ���
    enum Color flag2;

    //����ʹ��ö�ٳ�Ա��flag2��ֵ
    flag2 = black;

    return 0;
}
*/


/*
//typedefʹ��
//��struct Test�ṹ����һ������Info
typedef struct Test
{
    int age;
}Info;

int main()
{
    //typedef��һ�����ڵ�������һ������
    //typedef���ܴ���������
    typedef int int64;//��intȡһ������int64

    //����һ������
    Info info;
    info.age = 19;
    printf("%d\n", info.age);


    return 0;
}
*/


/*
//��׼�ļ�ָ��
int main()
{
    printf("123\n");
    //fclose(stdout);//�رձ�׼����ļ�ָ��
    printf("456\n");

    //��ӡ�⺯��ʧ�ܵ�ԭ��
    perror("result");
    fclose(stderr);//�رձ�׼��������ļ�ָ��
    perror("result2");

    int a;
    printf("enter a:");
    fclose(stdin); //�رձ�׼�����ļ�ָ��
    scanf("%d", &a);
    printf("a=%d\n", a);

    return 0;
}
*/


/*
//��׼�ļ�ָ��
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    //printf()�������ڲ�ʵ�֣�����׼����豸(1)д����
    printf("before aaaaaaaaaaaaaaaaa\n");
    //fclose(stdout);
    close(1);//1�����׼����豸���ر��ˣ�1���ǿ��е�����

    int fd = open("1.txt", O_WRONLY, 0777);

    //printf()�������ڲ�ʵ�֣���1д���ݣ���������1��1.txt������printf������д��1.txt
    printf("fd = %d\n", fd);

    printf("after bbbbbbbbbbbb1\n");
    printf("after cccccccccccc2\n");
    printf("after dddddddddddd3\n");

    return 0;
}
*/

/*
//fputc()����
#include <string.h>
int main()
{
    //1�����ļ�
    FILE *fp = NULL;
    fp = fopen("2.txt", "w");
    if(fp == NULL)
    {
        perror("fopen file fialed");
        return -1;
    }

    //2��д�ļ�
    char ch = 'a';
    while(ch <= 'z')//�ַ����ԱȽϴ�С
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

    //3���ر��ļ�
    fclose(fp);
    fp = NULL;

    return 0;
}
*/

/*
//fgetc()����
#include <string.h>
int main()
{
    //1�����ļ�
    FILE *fp = NULL;
    fp = fopen("2.txt", "r");
    if(fp == NULL)
    {
        perror("fopen file fialed");
        return -1;
    }

    //2�����ļ�
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

    //3���ر��ļ�
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
            //sscanf���buffer��������ݣ�����format�ĸ�ʽ������д�뵽argument��
            sscanf(buf, "%d%c%d", &a, &ch, &b);
            //sprintf() ���ڽ�����浽�ַ�������
            //����ԭ�ͣ�sprintf(char *buffer, const char *format, [argument]);
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

//fprintf():��agars(������)�ڸ����ֵ����format(��ʽ�����ַ���)����ʾ�ĸ�ʽ�������ݸ�ʽΪ�ַ�������ʽд�뵽�ļ�ָ��fpָ����ļ��С�
//ԭ�ͣ�fprintf(FILE *fp, const char *format, agars)
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

//fscanf():���ļ�ָ��fpָ����ļ��У���format�ж�Ӧ�Ŀ��Ƹ�ʽ��ȡ���ݣ����洢��agars��Ӧ�ı����У�
//ԭ��: fscanf(FILE *fp, const char *format, agars)
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

//��C������fwrite()���������ｫһ���ڴ������е�����д�뵽�����ı�
//size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);
//-- buffer:ָ�����ݿ��ָ��
//-- size:ÿ�����ݵĴ�С����λΪByte(���磺sizeof(int)����4)
//-- count:���ݸ���
//-- stream:�ļ�ָ��
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
//���ã���һ���ļ����ж�ȡ����
//size_t fread(void *buffer, size_t size, size_t count, FILE *stream);
//  -- buffer:ָ�����ݿ��ָ��
//  -- size:ÿ�����ݵĴ�С����λΪByte(���磺sizeof(int)����4)
//  -- count:���ݸ���
//  -- stream:�ļ�ָ��
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
