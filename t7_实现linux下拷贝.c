#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *rfp = fopen(argv[1], "r");
	
	FILE *wfp = fopen(argv[2], "w");

	//循环操作
	//从源文件读取内容，再把内容写到目的文件，读多少写多少
	char buf[4*1024];
	int len;
	while(1)
	{
		len = fread(buf, 1, sizeof(buf), rfp);
		printf("len = %d\n", len);
		if(len == 0)
		{
			break;
		}
		fwrite(buf, 1, len, wfp);
	}

	fclose(rfp);
	fclose(wfp);
	
	return 0;
}
