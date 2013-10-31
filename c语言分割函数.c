#include<stdio.h>
#include<string.h>
#define SIZE 10
int my_split(char *p[SIZE], char str[],char const *sep)
{
	int num = 0;
	for(p[num] = strtok(str,sep); p[num] != NULL; p[++num] = strtok(NULL,sep));
	return num;//返回被分割成单独部分的个数
}
int main( )
{
	char line[] = "split@string/to#many single,part]ok";
	char *p[SIZE];
	char const *token = " ,/@#]";
	int num = my_split( p, line,token);
	for(int i = 0; i < num; i ++ )
	{
		printf("%s\n",p[i]);
	}
	return 0;
}