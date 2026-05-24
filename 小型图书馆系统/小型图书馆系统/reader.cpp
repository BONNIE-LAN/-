#include<iomanip>
#include"stdafx.h"
#include"reader.h"
Reader::Reader()
{
	note = 0;
	number = 0;
	name[0] = '\0';
	for (int i = 0; i < Maxbor; i++)
	{
		borbook[i] = 0;
	}
}
char* Reader::getname()
{
	return name;
}
int Reader::getnote()
{
	return note;
}
int Reader::getnumber()
{
	return number;
}
void Reader::setname(char na[])
{
	strcpy_s(name,sizeof(name), na);
}
void Reader::addreader(int n, const char* na)
{
	note = 0;
	number = n;
	strcpy_s(name,sizeof(name),na);
	for (int i = 0; i < Maxbor; i++)
	{
		borbook[i] = 0;
	}
}
void Reader::delreader()
{
	note = 1;
}
void Reader::borrowbook(int bookid)
{
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] == 0)
		{
			borbook[i] = bookid;
			break;
		}
	}
}
int Reader::retbook(int bookid)
{
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] == bookid)
		{
			borbook[i] = 0;
			return 1;
		}
	}
	return 0;
}
void Reader::list()
{
	cout << "这是你的读者信息" << endl;
	cout << setw(5) <<"读者编号："<< number << setw(10)<<"读者姓名:" << name <<" "<<"借书编号：[";
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] !=0)
		{
			cout << borbook[i] << " ";
		}
	}
	cout << "]" << endl;
}
