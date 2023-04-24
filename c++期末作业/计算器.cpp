#include <bits/stdc++.h>
using namespace std;

//利用纯虚数来实现一个计算机功能

class AbstractCalculate{	
public:
	virtual int getResult()=0;

	int m_A;
	int m_B;
};

//加法运算
class AddCalculate:public AbstractCalculate{
public:
	int getResult(){
		return m_A+m_B;
	}
};

//乘法运算
class MutiplyCalculate:public AbstractCalculate{
public:
	int getResult(){
		return m_A*m_B;
	}
};

void func(){
	//加法计算器
	AbstractCalculate * a=new AddCalculate;
	cout<<"scan m_A:";
	cin>>a->m_A;
	cout<<"scan m_B:";
	cin>>a->m_B;
	cout<<"add result:"<<a->getResult()<<endl;
	delete(a);
	//乘法计算器
	AbstractCalculate * b=new MutiplyCalculate;
	cout<<"scan m_A:";
	cin>>b->m_A;
	cout<<"scan m_B:";
	cin>>b->m_B;
	cout<<"multiple result:"<<b->getResult()<<endl;
	delete(b);
}

int main(){
	func();
	return 0;
}
