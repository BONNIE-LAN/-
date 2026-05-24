#include"stdafx.h"
#include<fstream>
#include<vector>
#include"bdatabase.h"
using namespace std;
BDatabase::BDatabase()
{
	Book s;
	top = -1;
	fstream file;
	file.open("book.dat", ios::in | ios::binary);
	while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
		if (top + 1 >= Maxb)
		{
			cerr << "错误：图书数量超出最大限制" << endl;
			break;
		}
		if (!file.eof()) 
		{
			top++;
			book[top] = s;
		}
	}
	file.close();
}
void BDatabase::clear()
{
	top = -1;
}
Book* BDatabase::query(int bookid)
{
	
	for (int i = 0; i <= top; i++)
	{
		if (book[i].getnumber() == bookid && book[i].getnote() == 0)
		{
			return &book[i];
		}
	}
	return NULL;
}
int BDatabase::addbook(int n, char* na)
{
	std::cout << "正在添加图书,编号：" << n << endl;
	Book* p = query(n);
	if (p == NULL)
	{
		top++;
		book[top].addbook(n, na);
		std::cout << "添加图书成功" << endl;
		return 1;
	}
	std::cout << "该图书已存在" << endl;
	return 0;
}
void BDatabase::list()
{
	for (int i = 0; i <= top; i++)
	{
		if(book[i].getnote() == 0)
		book[i].list();
	}
}
BDatabase::~BDatabase()
{
	fstream file;
	file.open("book.dat", ios::out | ios::binary);
	if (!file.is_open())
	{
		cerr << "错误：无法打开book.dat文件写入" << endl;
		return;
	}
	for (int i = 0; i <= top; i++)
	{
		if (book[i].getnote() == 0)
		{
			file.write((char*)&book[i], sizeof(book[i]));
			if (!file)
			{
				cerr << "错误：写入图书记录失败" << endl;
			}
		}
	}
	file.close();
}
void BDatabase::bookdata()
{
	int choice = 1;
	char bookname[20];
	int bookid;
	Book* b;
	bool justCleared = false;//添加一个标志变量
	while (choice != 0)
	{
		std::cout << "图书维护：" << endl;
		std::cout << "------------------------------------------" << endl;
		std::cout << "1：新增 2：更改 3：删除 4：查找 5：显示 6:全删 0:退出" << endl;
		cout << "请选择你想要的功能：" << endl;
		std::cin >> choice;
		std::cout << "------------------------------------------" << endl;
		switch (choice)
		{
		case 1:
			std::cout << "输入图书编号：";
			std::cin >> bookid;
			b = query(bookid);//添加一个检测
			if (b != NULL)
			{
				std::cout << "该图书编号已存在。无法添加" << endl;
				break;
			}
			std::cout << "输入图书名：";
			std::cin >> bookname;
			addbook(bookid, bookname);
			break;
		case 2:
			std::cout << "输入图书编号：";
			std::cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				std::cout << "该图书不存在！" << endl;
				break;
			}
			std::cout << "输入新的图书名：";
			std::cin >> bookname;
			b->setname(bookname);
			std::cout << "图书名更改成功" << endl;
			break;
		case 3:
			std::cout << "输入图书编号：";
			std::cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				std::cout << "该图书不存在！" << endl;
				break;
			}
			b->delbook();
			std::cout << "图书已删除" << endl;
			break;
		case 4:
			std::cout << "输入图书编号：";
			std::cin >> bookid;
			std::cout << "正在查询图书：" << bookid << endl;
			b = query(bookid);
			if (b == NULL)
			{
				std::cout << "该图书不存在！" << endl;
				break;
			}
			std::cout << "这是你要查找的图书：" << endl;
			b->list();
			break;
		case 5:
			if (justCleared)
			{
				std::cout << "图书已被清空" << endl;
			}
			list();
			justCleared = false;
			break;
		case 6:
			clear();
			std::cout << "图书已被全部删除" << endl;
			justCleared = true;
			break;
		case 0:
			break;
		default:
			std::cout << "请输入操作对应的正确数字！" << endl;
		}
    }
}