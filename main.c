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

int main()
{
    int a[3] = {1,2,3,4,5};
    printf("%d\n", sizeof(a));


    return 0;
}
