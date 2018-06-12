#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Unit{
	public:
		Unit(){
		}
		void showMenu(){
			cout<<"**********单位转换**********"<<endl;
			cout<<"可选类型：1.长度 2.质量 3.力 4.面积 5.时间 6.速度 7.温度 8.角度"<<endl;					
		}	
		void outUnit(){   //输出提示可选的单位 
			//filename="data\\长度.txt";
			f.open(filename,ios::in);
			char temp[100];
			f.getline(temp,100);
			
			int i=0;
			while(!f.eof()){
				double value;
				string key;
				char *p,*pnum;
				p=strtok(temp," (");
				value=strtold(p,NULL);			
				p=strtok(NULL," (");
				key=p;
				mymap[key]=value;
				
				if(i%7==0){
					cout<<endl;
				}
				//cout<<value<<" "<<key<<endl;
				cout<<setw(10)<<key;
				i++;
				
				f.getline(temp,100);				
			}			
		}	
				
		virtual void convert(){
			double srcValue;
			string srcUnit;
			string desUnit;
			double desValue;
			map<string,double>::iterator it1,it2;
			cout<<endl<<"需转换的值:";
			cin>>srcValue;
			while (cin.fail())  
			{  
				string num_input_string;
				cin.clear();  
				cin >> num_input_string;  
				cout << "输入的"<< num_input_string<<"不是数字，请输入一个数: "; //如果此时输入的不是数字，
				//则cin.fail()函数的返回值是true。在while()循环中，首先调用istream类的成员函数clear()来清空错误标志，
				//因为cin.fail()返回true时，会将输入流中的failbit位（错误标志位）置为1，为了能够在后续的动作中正常接收输入数据，
				//必须先通过cin.clear()将failbit位重新置0。接下来，通过cin和输入操作符>>将错误的输出保存在string类型的变量中，
				//并且输出错误提示信息。最后，再次通过cin等待正确的输出，直到输入的数据为数字时，程序才会跳出while()语句。 
				cin >> srcValue;  
			}  
			
			
			cout<<"原单位:";
			cin>>srcUnit;	
			it1=mymap.find(srcUnit);
			if(it1==mymap.end()){
				cout<<"wrong input"<<endl;
				return;
			}
			
			cout<<"新单位:";
			cin>>desUnit;				
			it2=mymap.find(desUnit);
			if(it2==mymap.end()){
				cout<<"wrong input"<<endl;
				return;
			}
			
			double x=it2->second/it1->second;
			//cout<<it2->second<<" "<<it1->second<<endl;
			desValue=x*srcValue;
			cout<<desValue<<endl;			
			//return desValue;	
		}
		void setFilename(const char*fn){
			filename=fn;
		} 
	private:		
		map<string,double> mymap;
		fstream f;
		const char* filename; 
}; 

class Length:public Unit{
	public:
		Length(){
			const char*fn="data\\长度.txt";
			setFilename(fn);
		}
};

class Weight:public Unit{
	public:
		Weight(){
			const char*fn="data\\质量.txt";
			setFilename(fn);
		}
};

class Force:public Unit{
	public:
		Force(){
			const char*fn="data\\力.txt";
			setFilename(fn);
		}
};

class Area:public Unit{
	public:
		Area(){
			const char*fn="data\\面积.txt";
			setFilename(fn);
		}
};

class Time:public Unit{
	public:
		Time(){
			const char*fn="data\\时间.txt";
			setFilename(fn);
		}
};

class Velocity:public Unit{
	public:
		Velocity(){
			const char*fn="data\\速度.txt";
			setFilename(fn);
		}
};

class Temperature:public Unit{
	public:
		Temperature(){
			const char*fn="data\\温度.txt";
			setFilename(fn);
		}
};

class Angle:public Unit{
	public:
		Angle(){
			const char*fn="data\\角度.txt";
			setFilename(fn);
		}
};

int main(){	
	Unit unit;	
	unit.showMenu();   
	
	int srcType;	
	cout<<"类型:";
	cin>>srcType;			
	//input(srcType,srcValue);
	
	Unit *pUnit;
	Length l;Weight w;Force f;Area a;Time t;Velocity v;
	Temperature t1;Angle a1;
	switch(srcType){
		case 1:pUnit=&l;break;
		case 2:pUnit=&w;break;
		case 3:pUnit=&f;break;
		case 4:pUnit=&a;break;
		case 5:pUnit=&t;break;
		case 6:pUnit=&v;break;
		case 7:pUnit=&t1;break;
		case 8:pUnit=&a1;break;
	}
	pUnit->outUnit();
	
	pUnit->convert();
	
	
	return 0;
}
