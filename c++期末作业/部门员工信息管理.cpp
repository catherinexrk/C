#include <bits/stdc++.h>
using namespace std;

#define CEHUA 1
#define MEISHU 2
#define YANFA 3

//存储员工信息
class Worker{
public:
	string name;
	int salary;
};

//员工信息存储
void createWorker(vector<Worker> &v){

	//员工姓名合并
	string nameSeed="ABCDEFGHIJ";
	for(int i=0;i<10;i++){
		Worker worker;
		//员工姓名
		worker.name=nameSeed[i];
		//员工薪资
		worker.salary=rand()%10000+10000;
		//存储员工信息
		v.push_back(worker);
	}
}

//员工分组
void setGroup(vector<Worker> &v,multimap<int,Worker> &m){
	for(vector<Worker>::iterator it=v.begin();it!=v.end();it++){
		//员工部门号
		int deptId=rand()%3+1;//部门号码 1,2,3
		
		//员工进行组号与个人信息进行一个绑定
		m.insert(make_pair(deptId,*it));
	}
}

//展示员工信息
void showWorker(multimap<int,Worker>&m){
	//根据部门进行显示
	cout<<"策划部门员工"<<endl;
	
	//查找策划部门的员工的迭代器即位置
	multimap<int,Worker>::iterator pos=m.find(CEHUA);
	//策划部门员工总数量
	int count=m.count(CEHUA);
	
	int index=0;
	for(;pos!=m.end()&&index<count;index++,pos++){
		cout << "姓名:"<< pos->second.name << " 工资:"<< pos->second.salary << endl;
	}
	
	cout<<"美术部门员工"<<endl;
	pos=m.find(MEISHU);
	count=m.count(MEISHU);
	index=0;
	for(;pos!=m.end()&&index<count;index++,pos++){
		cout << "姓名:"<< pos->second.name << " 工资:"<< pos->second.salary << endl;
	}
	
	cout<<"研发部门员工"<<endl;
	pos=m.find(YANFA);
	count=m.count(YANFA);
	index=0;
	for(;pos!=m.end()&&index<count;index++,pos++){
		cout << "姓名:"<< pos->second.name << " 工资:"<< pos->second.salary << endl;
	}
	
}

int main(){
	//随机数字
	srand((unsigned)time(NULL));
	
	//员工信息录入
	vector<Worker> worker;
	createWorker(worker);
	
	//分组
	multimap<int,Worker>m;
	setGroup(worker,m);
	
	//成员展示
	showWorker(m);
	
	return 0;
}

