//(1) Ackerman 함수를 구하는 순환적인 프로그램을 작성하시오.

#include<stdio.h>

int Ackerman(int m, int n){
	
	if(m<0||n<0)		//입력 받은 m,n의 값 중 하나라도 (-)값이면 0을 반환한다.
		return 0;

	if(m==0)
		return n+1;
	else if(n==0)
		return Ackerman(m-1,1);		//순환 호출
	else
		return Ackerman(m-1,Ackerman(m,n-1));	//순환 호출
	
}

void main(){
	
	int n,m,result;

	printf("####### Ackerman 함수 ######\n");
	printf("A(0,n)=n+1\n");
	printf("A(m,0)=A(m-1,1)\n");
	printf("A(m,n)=A(m-1,A(m,n-1))\n");
	printf("############################\n\n");

	printf("(1) 순환적인 프로그램\n"); 
	printf("m과 n의 값을 입력하시오: ");
	scanf("%d %d",&m,&n);
	result=Ackerman(m,n);
	printf("A(%d,%d)의 값은 %d입니다.\n\n",m,n,result);
	
}