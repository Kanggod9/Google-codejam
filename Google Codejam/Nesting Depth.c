#include <stdio.h>
#define MAX 100
int main ()
{	char input[MAX][MAX+1];
	char output[MAX][MAX*3];
	int i,T;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%s",input+i);
	}

	for(i=0;i<T;i++){
		int count;
		char *p = input+i;
		char *q = output+i;
		while(*p!='\0'){
			if(*p=='0') *q++=*p++;
			else {
				count = 1;
				while(*p=='1'){
					if(count == 1) *q++ = '(';
					*q++ = *p++;
					count=0;
					}
				*q++= ')';
				
			}
		}
		*q='\0';
	}
	for(i=0;i<T;i++){
		char *p = output[i];
		printf("Case #%d: ",i+1);
		while(*p != '\0'){
			if(*p == '(' || *p == ')') printf("%c",*p);
			else printf("%d",*p-'0');
			p ++ ;
		}
		printf("\n");
		
	}
return 0; } 