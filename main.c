#include <stdio.h>

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

