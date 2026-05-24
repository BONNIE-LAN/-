#include"stdafx.h"
#include<iomanip>
#include<cstring>
#include"book.h"
Book::Book()
{
	note = 0;
	number = 0;
	name[0] = '\0';
	onshelf = 1;
}
char* Book::getname()
{
	return name;
}
int Book::getnote()
{
	return note;
}
int Book::getnumber()
{
	return number;
}
void Book::setname(char na[])
{
	strcpy_s(name, sizeof(name),na);
}
void Book::addbook(int n, const char* na)
{
	note = 0;
	number = n;
	strcpy_s(name, sizeof(name), na);
	onshelf = 1;
}
void Book::delbook()
{
	note = 1;
}
int Book::borrowbook()
{
	if (onshelf == 1)
	{
		onshelf = 0;
		cout << "借书成功！" << endl;
		return 1;
	}
	return 0;
}
void Book::retbook()
{
	if(onshelf==0)//如果书是借出状态
	{
		onshelf = 1;//设置为在架状态
	}
	
}
void Book::list()
{
	cout << setw(5) << "图书编号："<<number << setw(10)<<"图书名：" << name << endl;
    cout<< "是否上架（是为1，否为0）："<<setw(3) << onshelf << endl;
}

