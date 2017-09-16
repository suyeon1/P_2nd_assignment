#include <stdio.h>
#include <math.h>
int checkprime(int n);
int checkarmstrong(int n);
int two_prime_number(int n);
int main()
{
	int x,n;
	printf("1.Display prime numbers between intervals using functiion.\n");
	printf("2.Check prime or armstrong number using user-defined function\n");
	printf("3.Check whether a nuber can be expressed as sum of two prime numbers\n");
	printf("Enter the number:");
	scanf("%d",&x);
	if(x==1){
		int n,n1,n2;
		printf("Enter two number:");
		scanf("%d %d",&n1, &n2);
		for(n=n1; n<=n2; n++)
			between_prime(n);
		puts("");
	}
 
	else if(x==2){
		int n,flag;
		printf("Enter a number:");
		scanf("%d",&n);
		flag = checkprime(n);
		if(flag==1)
			printf("%d is a prime number.\n",n);
		else
			printf("%d is not a prime number.\n",n);
		flag = checkarmstrong(n);
		if(flag==1)
			printf("%d is an armstrong number.\n",n);
		else
			printf("%d is not a armstrong number.\n",n);
		return 0;
	}
	else if(x==3){
		int n,i,flag=0;
		printf("Enter a number:");
		scanf("%d",&n);
		for(i=2; i<=n/2; ++i){
			if(checkprime(i)==1){
				if(checkprime(n-i)==1){
					printf("%d = %d + %d\n",n,i,n-i);
					flag=1;
				}
			}
		}
	}
	return 0;
}
int between_prime(int n){
	int i;
	for(i=2; i<=n; i++){
		if(n%i==0)
			break;
	}
	if(n==i)
		printf(" %d ",n);
}
int checkprime(int n){
	int i,flag=0;
	for(i=1; i<=n; i++){
		if(n%i==0)
			flag++;
	}
	return (flag==2);
}
int checkarmstrong(int n){
	int original_number, remainder, result=0, number=0, flag;
	original_number=n;
	while(original_number != 0)
	{
		original_number/=10;
		++number;
	}
	original_number=n;
	while(original_number!=0)
	{
		remainder = original_number % 10;
		result += pow(remainder,number);
		original_number/=10;
	}
	if(result==n)
		flag=1;
	else
		flag=0;
	return flag;
}