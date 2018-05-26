#include <vector>
#include <string>
#include <iostream>
using namespace std; 

class Cell {
public:
  Cell(string con){
  	content=con;
  	if(con.empty()){
  		content="*";
  	} 	
  }
  ~Cell(){
  }

  void show(){
  	cout<<content<<" "; 
  }
  void set(string con){
  	content=con;
  }
private:
  string content;
};

class Table {
public:
  Table(){
  	row=1;
  	col=1;
  	Cell tmp("");
  	cells.push_back(tmp);
  }
  Table(int x,int y):row(x),col(y){
  	for(int i=0;i<x;i++){
  		for(int j=0;j<y;j++){
  			Cell tmp("");
  			cells.push_back(tmp);
  		}
  	}
  }
  void show();
  void addRow();
  void delRow(int n);
  void set(int x,int y,int val);
  void set(int x,int y,string val);
  void addColumn();
  void delColumn(int n);
private:
  int row,col;
  vector<Cell> cells;
};

void Table::show(){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			//cout<<cells[i*col+j]<<" ";
			cells[i*col+j].show();
		}
		cout<<endl;
	}
	cout<<endl;
}

void Table::addRow(){
	for(int i=0;i<col;i++){
		Cell tmp("");
		cells.push_back(tmp);
	}
	row++;
}

void Table::addColumn(){
	for(int i=0;i<row;i++){
		Cell tmp("");
		cells.insert(cells.begin()+(i+1)*col,tmp);
	}
	col++;
}

void Table::set(int x,int y,int val){
	//string s_val=to_string(val);
	//cells[x*col+y].content=s_val;
}

void Table::set(int x,int y,string val){
	cells[x*col+y].set(val);
}

void Table::delColumn(int n){
	col--;
	for(int i=0;i<row;i++){
		cells.erase(cells.begin()+i*col+n);
	}
}

void Table::delRow(int n){
	cells.erase(cells.begin()+n*col,cells.begin()+(n+1)*col);
	row--;
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
//  tb1.set(1,1,30);
  tb1.set(2,2,"hello");
  tb1.show();
  tb1.delRow(1);
  tb1.show();
  tb1.delColumn(2);
  tb1.show();
  return 0;
}
