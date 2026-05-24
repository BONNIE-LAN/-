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
	strcpy_s(name, strlen(na+1),na);
}
void Book::addbook(int n, char* na)
{
	note = 0;
	number = n;
	strcpy_s(name, strlen(na+1), na);
	onshelf = 1;
}
void Book::delbook()
{
	note = 1;
}
int Book::borrowbook()
{
	return onshelf;
}
void Book::retbook()
{
	onshelf = 1;
}
void Book::list()
{
	cout << "这是关于这本书的信息：" << endl;
	cout << setw(5) << number << setw(10) << name << endl;
    cout<< "是否上架（是为1，否为0）："<<setw(10) << onshelf << endl;
}
int main()
{
    Book b;
    b.borrowbook();
    return 0;
}