#include <iostream>
using namespace std;

class Clock {
	public:
		Clock(){
			s=0;
			h=0;
			m=0;		
		}
		~Clock(){
		}
		void tick(){
			if(s<59)
				s++;
			else{
				s=0;
				if(m<59)
					m++;
				else{
					m=0;
					if(h<23)
						h++;
					else{
						h=0;
					}
				}
			}
		}
		void show(){
			if(h<10)
				cout<<"0"<<h<<":";
			else
				cout<<h<<":";
			if(m<10)
				cout<<"0"<<m<<":";
			else
				cout<<m<<":";
			if(s<10)
				cout<<"0"<<s<<endl;
			else
				cout<<s<<endl;
		}
		void adjust(int hour1,int minute1,int second1){
			if(hour1>=24||minute1>=60||second1>=60){
				cout<<"wrong adjustment"<<endl;
			}
			h=hour1;
			m=minute1;
			s=second1;
		}
	private:
		int h,m,s;
		
};

int main() {
  Clock ck;
  ck.tick();
  ck.show();
  ck.adjust(16,45,0);
  ck.show();
  return 0;
}
