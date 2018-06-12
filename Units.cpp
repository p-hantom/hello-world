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
			cout<<"**********��λת��**********"<<endl;
			cout<<"��ѡ���ͣ�1.���� 2.���� 3.�� 4.��� 5.ʱ�� 6.�ٶ� 7.�¶� 8.�Ƕ�"<<endl;					
		}	
		void outUnit(){   //�����ʾ��ѡ�ĵ�λ 
			//filename="data\\����.txt";
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
			cout<<endl<<"��ת����ֵ:";
			cin>>srcValue;
			while (cin.fail())  
			{  
				string num_input_string;
				cin.clear();  
				cin >> num_input_string;  
				cout << "�����"<< num_input_string<<"�������֣�������һ����: "; //�����ʱ����Ĳ������֣�
				//��cin.fail()�����ķ���ֵ��true����while()ѭ���У����ȵ���istream��ĳ�Ա����clear()����մ����־��
				//��Ϊcin.fail()����trueʱ���Ὣ�������е�failbitλ�������־λ����Ϊ1��Ϊ���ܹ��ں����Ķ��������������������ݣ�
				//������ͨ��cin.clear()��failbitλ������0����������ͨ��cin�����������>>����������������string���͵ı����У�
				//�������������ʾ��Ϣ������ٴ�ͨ��cin�ȴ���ȷ�������ֱ�����������Ϊ����ʱ������Ż�����while()��䡣 
				cin >> srcValue;  
			}  
			
			
			cout<<"ԭ��λ:";
			cin>>srcUnit;	
			it1=mymap.find(srcUnit);
			if(it1==mymap.end()){
				cout<<"wrong input"<<endl;
				return;
			}
			
			cout<<"�µ�λ:";
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
			const char*fn="data\\����.txt";
			setFilename(fn);
		}
};

class Weight:public Unit{
	public:
		Weight(){
			const char*fn="data\\����.txt";
			setFilename(fn);
		}
};

class Force:public Unit{
	public:
		Force(){
			const char*fn="data\\��.txt";
			setFilename(fn);
		}
};

class Area:public Unit{
	public:
		Area(){
			const char*fn="data\\���.txt";
			setFilename(fn);
		}
};

class Time:public Unit{
	public:
		Time(){
			const char*fn="data\\ʱ��.txt";
			setFilename(fn);
		}
};

class Velocity:public Unit{
	public:
		Velocity(){
			const char*fn="data\\�ٶ�.txt";
			setFilename(fn);
		}
};

class Temperature:public Unit{
	public:
		Temperature(){
			const char*fn="data\\�¶�.txt";
			setFilename(fn);
		}
};

class Angle:public Unit{
	public:
		Angle(){
			const char*fn="data\\�Ƕ�.txt";
			setFilename(fn);
		}
};

int main(){	
	Unit unit;	
	unit.showMenu();   
	
	int srcType;	
	cout<<"����:";
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
