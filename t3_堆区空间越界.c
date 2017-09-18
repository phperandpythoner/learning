#include <stdio.h>
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
