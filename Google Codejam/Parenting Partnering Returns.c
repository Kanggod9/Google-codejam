#include <stdio.h>
#define MAX 1000
main(){
	int i,j,T,N;
	scanf("%d",&T);
	
	int Sc,Sj,Ec,Ej,s,e;
	
	int t = 1;
	
	int input[MAX][3];
	int a,b,c;
	while(t <= T){
		scanf("%d",&N);
		i = 0;
		int k = 2;
		while(i < N){
			input[i][2] = i;
			scanf("%d %d",&input[i][0],&input[i][1]);
			i++;
		}	

		for(i = N-1; i >= 1; i--){
			for(j = 0; j <= i - 1; j++ )
			if(input[j][0] > input[j + 1][0]){
				a = input[j][0];
				b = input[j][1];
				c = input[j][2];
				input[j][0] = input[j + 1][0];
				input[j][1] = input[j + 1][1];
				input[j][2] = input[j + 1][2];
				input[j + 1][0] = a;
				input[j + 1][1] = b;
				input[j + 1][2] = c;
			}
		}
/*	for(i = 0; i < N; i++){
		for(j = 0; j < 2; j++)
		printf("%d ",input[i][j]);}*/
	
		Sc = input[0][0];
		Ec = input[0][1];
		Sj = input[1][0];
		Ej = input[1][1];
		char task[N];
		task[0] = 'C';
		task[1] = 'J';

		for(i = 2; i < N; i++){
			s = input[i][0];
			e = input[i][1];
		
			if(s < Ec && s < Ej) break;
		    if(s >= Ec){ task[k++] = 'C'; Ec = e;}
			else if(s >= Ej) { task[k++] = 'J'; Ej = e;}
		
		
		}
	
		if(i < N) printf("Case #%d: IMPOSSIBLE\n",t);
		else {
			char output[N];
			for(i = 0; i < N; i++)
				output[input[i][2]] = task[i];
			output[N] = '\0';
			printf("Case #%d: %s\n",t,output);
		}
		t = t + 1;
	
	}
}

