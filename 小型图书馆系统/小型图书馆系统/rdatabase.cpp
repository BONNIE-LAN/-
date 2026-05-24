#include"stdafx.h"
#include<fstream>
#include"rdatabase.h"
using namespace std;
RDatabase::RDatabase()
{
	top = -1;
	ifstream file;
	file.open("reader.dat", ios::in | ios::binary);
	if (file.is_open())
	{
		Reader s;
		while (file.read(reinterpret_cast<char*>(&s), sizeof(s)))
		{
			if (top + 1 >= Maxr)
			{
				cerr << "错误：读者超出最大限制" << endl;
				break;
			}
			if (s.getnote() == 0)
			{
				top++;
				read[top] = s;
			}
		}
		file.close();
	}
}

void RDatabase::clear()
{
	top = -1;
}
Reader* RDatabase::query(int readerid)
{
	
	for (int i = 0; i <= top; i++)
	{
		if (read[i].getnumber() == readerid && read[i].getnote() == 0)
			return &read[i];
	}
	return NULL;
}
int RDatabase::addreader(int n, char* na)
{
	cout << "正在添加读者，编号：" << n << endl;
	Reader* p = query(n);
	if (p == NULL)
	{
		top++;
		read[top].addreader(n, na);
		cout << "读者添加成功" << endl;
		return 1;
	}
	cout << "该读者已存在" << endl;
	return 0;
}
void RDatabase::list()
{
	for (int i = 0; i <= top; i++)
	{
		if(read[i].getnote()==0)//只显示未被删除的读者
		read[i].list();
	}
}
RDatabase::~RDatabase()
{
	fstream file;
	file.open("reader.dat", ios::out | ios::binary);
	for (int i = 0; i <= top; i++)
	{
		if (read[i].getnote() == 0)
		{
			file.write((char*)&read[i], sizeof(Reader));
		}
	}
	file.close();
}
void RDatabase::readerdata()
{
	int choice = 1;
	char readername[20];
	int readerid;
	Reader* r;
	bool justCleared = false;
	while (choice != 0)
	{
		cout << "读者维护：" << endl;
		cout << "---------------------------------" << endl;
		cout << "1.新增 2.更改 3.删除 4.查找 5.显示 6.全删 0.退出" << endl;
		cout << "请选择你想要的功能：" << endl;
		cin >> choice;
		cout << "---------------------------------" << endl;
		switch (choice)
		{
		case 1:
			cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (r != NULL)
			{
				cout << "该读者已存在，不能添加" << endl;
				break;
			}
			cout << "输入读者姓名：";
			cin >> readername;
			addreader(readerid, readername);
			break;
		case 2:
			cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在！" << endl;
				break;
			}
			cout << "输入新的姓名：";
			cin >> readername;
			r->setname(readername);
			cout << "读者姓名更改成功" << endl;
			break;
		case 3:
			cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在！" << endl;
				break;
			}
			r->delreader();
			cout << "该读者已删除" << endl;
			break;
		case 4:
			cout << "输入读者编号：";
			cin >> readerid;
			cout << "正在查询读者：" << readerid << endl;
			r = query(readerid);
			if(r==NULL)
			{
				cout << "该读者不存在！" << endl;
				break;
			}
			cout << "这是你要查找的读者信息" << endl;
			r->list();
			break;
		case 5:
			if (justCleared)
			{
				cout << "读者已被全部清除" << endl;
			}
			list();
			break;
		case 6:
			clear();
			cout << "读者已被全部清除" << endl;
			justCleared = true;
			break;
		case 0:
			break;
		default:
			cout << "请输入对应操作的正确编号" << endl;
		}
	}
}