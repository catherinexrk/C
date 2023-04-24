#include <bits/stdc++.h>
using namespace std;

//利用deque和vector实现一个一群评委打分去除最高分最低分得到选手的最终平均成绩

/*
1. 创建五名选手，放到vector中
2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
3. sort算法对deque容器中分数排序，去除最高和最低分
4. deque容器遍历一遍，累加总分
5. 获取平均分
*/

//存放选手的个人信息
class Person{
public:
	Person(string name,int score){
		this->m_Name=name;
		this->m_Score=score;
	}
	
public:
	string m_Name;//选手姓名
	int m_Score;//选手分数
};

class myCompare{
public:
	bool operator()(Person &p1,Person &p2){
		return p1.m_Score>p2.m_Score;
	
	}
};

//初始化选手个人信息
void createPerson(vector<Person> & v){
	string nameSeed="abcde";
	for(int i=0;i<5;i++){
		string name="选手"; 
		name += nameSeed[i];//选手姓名
		int score=0;
		
		Person p(name,score);
		v.push_back(p);//插入选手信息
	}
}

void setScore(vector<Person> &v){
	//10个评委进行全部打分
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
		//deque队列存储所有评委的打分
		deque<int> d;
		for(int i=0;i<10;i++){
			//随机生成分数属
			int score=rand()%41+60;
			d.push_back(score);
		}
		sort(d.begin(),d.end());
		//去除最高最低分
		{
			d.pop_front();
			d.pop_back();
		}
		//求取平均分数
		int sum=0;
		for(deque<int>::iterator it=d.begin();it!=d.end();it++){
			sum +=*it;
		}
		int avg=sum/d.size();
		//平均分赋值到选手身上
		it->m_Score=avg;
	}
}

void showPerson(vector<Person> &v){
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
		cout<<it->m_Name<<"得分为"<<it->m_Score<<endl;
	}
}

void func(){
	//创建五名选手
	vector<Person> v;
	createPerson(v);
	
	//给选手打分
	setScore(v);
	
	//展示选手
	showPerson(v);
	
	//可以进行按照分数大小进行选手展示
	sort(v.begin(),v.end(),myCompare());
	cout<<"降序排布的选手成绩"<<endl;
	showPerson(v);
	
	
	
}

int main()
{
	func();
	return 0;
}
