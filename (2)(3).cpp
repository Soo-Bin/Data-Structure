/*(2) 순환적인 프로그램을 for, while, do와 같은 반복 구조를 사용한 비순환적인 프로그램으로 바꾸시오.
  (3) 비순환 프로그램의 시간 복잡도(time complexity)를 O로 표현하시오.*/

#include<stdio.h>

int nonrecur_Ackerman(int m, int n){
	
	int list[10000];
	int num=0;
	int count=0;	//시간 복잡도를 계산하기 위해 연산의 빈도 카운트

	list[num++]=m;	//list[0]에 m값을 입력
	list[num]=n;	//list[1]에 n값을 입력

	if(m<0||n<0)	//입력 받은 m,n의 값 중 하나라도 (-)값이면 0을 반환
		return 0;

	while(true){				
		if(list[num-1]==0){					//A(0,n)일 때
			list[num-1] =list[num]+1;		//n+1을 하고
			num -= 1;						//인덱스 번호를 하나 줄인다.

			count+=2;
			printf("%d\n",count);			//한 줄 연산할 때마다 count++, 값을 입력을 해도 count++
		}
		else if(list[num]==0){				//A(m,0)일 때
			list[num-1] -= 1;				//m=m-1 값을 넣고
			list[num]=1;					//n=1 값을 넣어준다.

			count+=2;
			printf("%d\n",count);
		}
		else{								//A(m,n)일 때
			list[num+1]=list[num]-1;			//n의 자리에 A(m,n-1)를 표현해야하므로 인덱스 번호를 하나 더 늘린다. n의 A(m,n)의 n자리에 n-1의 값을 넣고
			list[num]=list[num-1];			//n의 A(m,n)의 m자리에 원래의 m의 값을 넣고
			list[num-1]=list[num-1]-1;		//원래의 m에 m-1을 넣어준다.
			num = num + 1;					//인덱스 번호를 늘렸다고 알려준다.

			count+=4;
			printf("%d\n",count);
		}
		
		if(num==0)						//list[0]이면 그 값을 return
			return list[num];
		
	}
}


void main(){
	
	int n,m,result;

	printf("####### Ackerman 함수 ######\n");
	printf("A(0,n)=n+1\n");
	printf("A(m,0)=A(m-1,1)\n");
	printf("A(m,n)=A(m-1,A(m,n-1))\n");
	printf("############################\n\n");

	printf("(2) 반복 구조를 사용한 비순환적 프로그램\n");
	printf("m과 n의 값을 입력하시오: ");
	scanf("%d %d",&m,&n);
	result=nonrecur_Ackerman(m,n);
	printf("A(%d,%d)의 값은 %d입니다.\n\n",m,n,result);
		
	printf("(3) 비순환 프로그램의 시간 복잡도는\n");
	printf("    O(n!)이다.\n");
}