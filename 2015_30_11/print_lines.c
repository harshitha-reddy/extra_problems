#include<stdio.h>
#include<stdlib.h>
int main(){

	FILE* fp;
	char filename[50],line[50],ch;
	int num,count=0,i=0;
	printf("\nEnter file name : ");
	scanf(" %[^\n]", filename);
	printf("\nEnter no of lines to be printed : ");
	scanf("%d", &num);
	fp = fopen(filename, "r");
	while ((ch = fgetc(fp))!=EOF){
		if (ch == '\n')
			count++;
		}
	count = count - num;
	while (i < count){
		ch =fgetc(fp);
		if (ch == '\n')
			i++;
		}
		while ((ch = fgetc(fp)) != EOF)
			fprintf(stdout, "%c", ch);
	getchar();
	getchar();

	}
