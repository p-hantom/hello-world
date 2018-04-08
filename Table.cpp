#include <iostream>
#include <vector> 
#include <string>
#include <stdlib.h>
using namespace std;
//add\del均为增/删最后一行/列 
//c++文档：
//http://www.cplusplus.com/reference/vector/vector/erase/
class Table{
	public:
		Table(){
			nRow = 3;
			nCol = 3;
			initTable();	
		}
		Table(int rr,int cc){
			nRow = rr;
			nCol = cc;
			initTable();
		}
		void initTable(){
			defaultVal = "___";
			for(int i=0;i<nRow;i++){
				vector<string>  v;
				for(int j=0; j<nCol; j++){
					v.push_back(defaultVal);
				}
				tb.push_back(v);
			}
		}
		void show(){
			cout<<"nRow = "<<nRow<<", nCol = "<<nCol<<endl;;			
			for(int i=0;i<tb.size();i++) {
				for(int j=0;j<tb[i].size();j++){
					cout<<tb[i][j]<<" ";
				}
				cout<<endl<<endl;
			}
		}
		void addRow(){
			nRow++;
			cout<<"One row added. "<<endl<<endl;			
			vector<string> v;			
			for(int j=0; j<nCol; j++){
				v.push_back(defaultVal);
			}
			tb.push_back(v);
		}
		void addColumn(){
			nCol++;
			cout<<"One column added."<<endl<<endl;;	
			for(int i=0; i<nRow; i++){
				tb[i].push_back(defaultVal);
			}
		}
		void delRow(int i){			
			if(i>0 && i<nRow){
				tb.erase(tb.begin()+i-1); 
				nRow--;
				cout<<"One row deleted. "<<endl<<endl;
			}
			else{
				cout<<"Row index out of range. "<<endl<<endl;
			}
		}
		void delColumn(int i){
			if(i>0 && i<nCol){
				for(int k=0; k<nRow; k++){
					tb[k].erase(tb[k].begin()+i-1);
				}
				nCol--;
				cout<<"One column deleted. "<<endl<<endl;
			}
			else{
				cout<<"Column index out of range. "<<endl<<endl;
			}
		}

		void set(int rr,int cc,string val){
			tb[rr-1][cc-1]=val;
		}
		void set(int rr,int cc,int val){
			char buffer [20];
			itoa(val,buffer,10);
			tb[rr-1][cc-1]=string(buffer);
		}
		
	private:
		vector<vector<string> > tb;
		int nRow,nCol;
		string defaultVal;
};

void f1(){
	//用vector实现二维数组
	vector<vector<int> > v(3) ;
	//v有3个元素，每个元素都是vector<int> 容器
	for(int i=0;i<v.size();i++) {
		for(int j=0;j<4;j++){
			v[i].push_back(j);
		}
	}
	
	for(int i=0;i<v.size();i++) {
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	
	
  Table tb;
  tb.show();
  tb.addRow();
  tb.show();
  tb.addColumn();
  tb.show();
  
  Table tb1(5,5);
  tb1.show();
  tb1.set(1,1,30);
  tb1.set(2,2,"hello");
  tb1.show();
  tb1.delRow(1);
  tb1.show();
  tb1.delColumn(1);
  tb1.show();
  return 0;
}
