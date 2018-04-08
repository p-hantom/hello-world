#include <iostream>
using namespace std;

class Parallelogram {
	public:
		Parallelogram(){
		}
		~Parallelogram(){
		}
		void show(){
			cout<<"the height is:"<<height1<<endl;
			cout<<"the length is"<<length1<<endl;
		}
		void area(){
			cout<<"the area is:"<<length1*height1<<endl;
		}
		int height(){
			return height1;
		}
		int length(){
			return length1;
		}
	private:
		int height1;
		int length1;
};
int main() {
  Parallelogram pg;
  pg.show();
  pg.area();
  pg.height();
  pg.length();
  return 0;
}
