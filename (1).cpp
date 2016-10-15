//(1) Ackerman �Լ��� ���ϴ� ��ȯ���� ���α׷��� �ۼ��Ͻÿ�.

#include<stdio.h>

int Ackerman(int m, int n){
	
	if(m<0||n<0)		//�Է� ���� m,n�� �� �� �ϳ��� (-)���̸� 0�� ��ȯ�Ѵ�.
		return 0;

	if(m==0)
		return n+1;
	else if(n==0)
		return Ackerman(m-1,1);		//��ȯ ȣ��
	else
		return Ackerman(m-1,Ackerman(m,n-1));	//��ȯ ȣ��
	
}

void main(){
	
	int n,m,result;

	printf("####### Ackerman �Լ� ######\n");
	printf("A(0,n)=n+1\n");
	printf("A(m,0)=A(m-1,1)\n");
	printf("A(m,n)=A(m-1,A(m,n-1))\n");
	printf("############################\n\n");

	printf("(1) ��ȯ���� ���α׷�\n"); 
	printf("m�� n�� ���� �Է��Ͻÿ�: ");
	scanf("%d %d",&m,&n);
	result=Ackerman(m,n);
	printf("A(%d,%d)�� ���� %d�Դϴ�.\n\n",m,n,result);
	
}