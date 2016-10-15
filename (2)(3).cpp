/*(2) ��ȯ���� ���α׷��� for, while, do�� ���� �ݺ� ������ ����� ���ȯ���� ���α׷����� �ٲٽÿ�.
  (3) ���ȯ ���α׷��� �ð� ���⵵(time complexity)�� O�� ǥ���Ͻÿ�.*/

#include<stdio.h>

int nonrecur_Ackerman(int m, int n){
	
	int list[10000];
	int num=0;
	int count=0;	//�ð� ���⵵�� ����ϱ� ���� ������ �� ī��Ʈ

	list[num++]=m;	//list[0]�� m���� �Է�
	list[num]=n;	//list[1]�� n���� �Է�

	if(m<0||n<0)	//�Է� ���� m,n�� �� �� �ϳ��� (-)���̸� 0�� ��ȯ
		return 0;

	while(true){				
		if(list[num-1]==0){					//A(0,n)�� ��
			list[num-1] =list[num]+1;		//n+1�� �ϰ�
			num -= 1;						//�ε��� ��ȣ�� �ϳ� ���δ�.

			count+=2;
			printf("%d\n",count);			//�� �� ������ ������ count++, ���� �Է��� �ص� count++
		}
		else if(list[num]==0){				//A(m,0)�� ��
			list[num-1] -= 1;				//m=m-1 ���� �ְ�
			list[num]=1;					//n=1 ���� �־��ش�.

			count+=2;
			printf("%d\n",count);
		}
		else{								//A(m,n)�� ��
			list[num+1]=list[num]-1;			//n�� �ڸ��� A(m,n-1)�� ǥ���ؾ��ϹǷ� �ε��� ��ȣ�� �ϳ� �� �ø���. n�� A(m,n)�� n�ڸ��� n-1�� ���� �ְ�
			list[num]=list[num-1];			//n�� A(m,n)�� m�ڸ��� ������ m�� ���� �ְ�
			list[num-1]=list[num-1]-1;		//������ m�� m-1�� �־��ش�.
			num = num + 1;					//�ε��� ��ȣ�� �÷ȴٰ� �˷��ش�.

			count+=4;
			printf("%d\n",count);
		}
		
		if(num==0)						//list[0]�̸� �� ���� return
			return list[num];
		
	}
}


void main(){
	
	int n,m,result;

	printf("####### Ackerman �Լ� ######\n");
	printf("A(0,n)=n+1\n");
	printf("A(m,0)=A(m-1,1)\n");
	printf("A(m,n)=A(m-1,A(m,n-1))\n");
	printf("############################\n\n");

	printf("(2) �ݺ� ������ ����� ���ȯ�� ���α׷�\n");
	printf("m�� n�� ���� �Է��Ͻÿ�: ");
	scanf("%d %d",&m,&n);
	result=nonrecur_Ackerman(m,n);
	printf("A(%d,%d)�� ���� %d�Դϴ�.\n\n",m,n,result);
		
	printf("(3) ���ȯ ���α׷��� �ð� ���⵵��\n");
	printf("    O(n!)�̴�.\n");
}