#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 500

void write_file()
{
	FILE *fp = NULL;
	fp = fopen("./tmp/1.txt", "w");
	if(fp == NULL)
	{
		printf("open file faild\n");
		return;
	}
	
	//设置随机数种子
	srand( (unsigned int)time(NULL) );
	
	int i = 0;
	int num;
	char buf[100];
	for(i = 0; i < MAX; i++)
	{
		num = rand() % 100;
		sprintf(buf, "%d\n", num);
		fputs(buf, fp);	
	}	

	fclose(fp);
}

void read_file()
{
	FILE *fp = NULL;

	fp = fopen("./tmp/1.txt", "r");
	if(fp == NULL)
	{
		perror("read_file fopen");
		return;
	}
	
	int i = 0;
	char buf[100];
	int num;
	int a[1024] = {0};
	//统计个数
	while(1)
	{	
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), fp);
		//printf("%s", buf);
		if(strlen(buf) > 0)
		{
			//printf("%s", buf);
			sscanf(buf, "%d\n", &num);
			a[i] = num;
			i++;
		}
		if(feof(fp))
		{
			break;
		}
	}
	//冒泡排序
	int n = i;//个数
	int j,tmp;
	for(i = 0; i < n-1;i++)
	{
		for(j = 0; j < n-1-i; j++)
		{
			if(a[j]>a[j+1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}

	fclose(fp);
	fp = NULL;

	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}

	char drc[4*1024] = {0};
	char src[1024];
	for(i=0; i<n; i++)
	{
		//把a[i]的内容以 "%d\n" 格式 存放到缓冲区src里
		sprintf(src, "%d\n", a[i]);
		//链接内容
		strcat(drc, src);
	}

	fp = fopen("./tmp/排序后文件.txt", "w");
	fputs(drc, fp);
	fclose(fp);
	fp = NULL;

}

int main()
{
	//write_file();	
	
	read_file();

	return 0;
}
