#include <stdio.h>

int sum_bit(int num) {
	int temp=num;
	int sum=0;
	while(temp!=0){
		int t=temp%10;
		temp/=10;
		sum+=t;
	}
  return sum;
}

int multi_bit(int num) {
	int temp=num;
	int sum=1;
	while(temp!=0){
		int t=temp%10;
		temp/=10;
		sum*=t;
	}
  return sum;
}

int square_sum_bit(int num) {
	int temp=num;
	int sum=0;
	while(temp!=0){
		int t=temp%10;
		temp/=10;
		sum+=t*t;
	}
  return sum;
}

int isprime(int num) {
	int i;
  for(i=2;i<num;i++){
		if(num%i==0){
			return 0;
		}
	}
	return 1;
}

int main() {
  if(isprime(113)&&isprime(sum_bit(113))&&isprime(multi_bit(113))&&isprime(square_sum_bit(113))){
  	printf("it's a super prime\n");
  }
    //to do sth
}
