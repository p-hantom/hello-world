#include <iostream>
#include <stdio.h>
using namespace std;

class Prime {
public:
  Prime(int num);
  ~Prime();

  bool isPrime();

  Prime sumBit();
  Prime multiBit();
  Prime sqaureSumBit();
private:
  const int m;
};

Prime::Prime(int num):m(num) {
}

Prime::~Prime(){
} 

bool Prime::isPrime(){
	for(int i=2;i<m;i++){
		if(m%i==0){
			return false;
		}
	}
	return true;
}

Prime Prime::sumBit(){
	int temp=m;
	int sum=0;
	while(temp!=0){
		int t=temp%10;
		temp/=10;
		sum+=t;
	}
	Prime p(sum);
	return p;
}

Prime Prime::multiBit(){
	int temp=m;
	int sum=1;
	while(temp!=0){
		int t=temp%10;
		temp/=10;
		sum*=t;
	}
	Prime p(sum);
	return p;
}

Prime Prime::sqaureSumBit(){
	int temp=m;
	int sum=0;
	while(temp!=0){
		int t=temp%10;
		temp/=10;
		sum+=t*t;
	}
	Prime p(sum);
	return p;
}

int main() {
  Prime pm(113);
  Prime sb = pm.sumBit();
  Prime mb = pm.multiBit();
  Prime ssb = pm.sqaureSumBit();
  if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime()){
  	cout<<"it's a super prime."<<endl;
  }

  return 0;
}
