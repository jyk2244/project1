#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count(char** string,char* search,int n);

int main()
{
	int i,n=0,len;

	scanf("%d",&n);
	
	char **string= malloc(sizeof(char) * n);
	char buffer[10];
	char search[10];

	for(i=0;i<n;i++)
	{
		scanf("%s",buffer);
		len= strlen(buffer);
		string[i]= (char*)malloc(sizeof(char) *(len+1));	
		strcpy(string[i],buffer);
	}
	scanf("%s",search);
	printf("%d\n",count(string,search,n));
}

int count(char** string, char* search, int n)
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(string[i],search) ==0 )
		{
			count++;
		}
	}
	return count;
}
