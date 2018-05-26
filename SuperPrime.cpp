#include <iostream>
using namespace std; 

class Prime {
public:
  Prime(int num):mNum(num){
  }
  ~Prime(){
  }

  bool isPrime(){
  	for(int i=2;i<mNum;i++){
  		if(mNum%i==0){
  			return false;
  		}
  	}
  	return true;
  }
private:
  const int mNum;
};

class SuperPrime : public Prime {
public:
  SuperPrime(int num):num(num),Prime(num){
	//this->num=num;
  }
  ~SuperPrime(){
  }

  bool isPrime(){
  	if(sumBit().isPrime()&&multiBit().isPrime()&&sqaureSumBit().isPrime()){
  		return true;
  	}
  	return false;
  }

  Prime sumBit(){
  	int sum=0,temp=num;
  	while(temp!=0){
  		int t_bit=temp%10;
  		temp/=10;
  		sum+=t_bit;
  	}
  	Prime Psum(sum);
  	return Psum;
  }
  Prime multiBit(){
  	int mul=1,temp=num;
  	while(temp!=0){
  		int t_bit=temp%10;
  		temp/=10;
  		mul*=t_bit;
  	}
  	Prime Pmul(mul);
  	return Pmul;
  }
  Prime sqaureSumBit(){
  	int sqr=0,temp=num;
  	while(temp!=0){
  		int t_bit=temp%10;
  		temp/=10;
  		sqr+=t_bit*t_bit;
  	}
  	Prime Psqr(sqr);
  	return Psqr;
  }
private:
  const int num;
};
int main()
{
    SuperPrime sp(113);
    if(sp.isPrime()) {
        cout<<"It is a super prime."<<endl;
    }
}
