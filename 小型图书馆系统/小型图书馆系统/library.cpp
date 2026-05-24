#include"stdafx.h"
#include"reader.h"
#include"rdatabase.h"
#include"book.h"
#include"bdatabase.h"
#include<fstream>
int main(int argc,char *argv[])
{
	//创建初始book.dat文件
	{
		
		ofstream bookFile("book.dat", ios::binary);
		if (bookFile.is_open())
		{
			Book book;
			book.addbook(101, "计算机网络");
			bookFile.write(reinterpret_cast<char*>(&book), sizeof(Book));
			book.addbook(102, "数据与结构");
			bookFile.write(reinterpret_cast<char*>(&book), sizeof(Book));
			book.addbook(103, "计算机组成原理");
			bookFile.write(reinterpret_cast<char*>(&book), sizeof(Book));
			book.addbook(104, "编译原理");
			bookFile.write(reinterpret_cast<char*>(&book), sizeof(Book));
			book.addbook(105, "线性代数");
			bookFile.write(reinterpret_cast<char*>(&book), sizeof(Book));
			book.addbook(106, "计算机导论");
			bookFile.write(reinterpret_cast<char*>(&book), sizeof(Book));
			book.addbook(107, "高数");
			bookFile.write(reinterpret_cast<char*>(&book), sizeof(Book));
			book.addbook(110, "数字逻辑电路");
			bookFile.write(reinterpret_cast<char*>(&book), sizeof(Book));
			book.addbook(111, "离散数学");
			bookFile.write(reinterpret_cast<char*>(&book), sizeof(Book));
			book.addbook(112, "C++程序设计");
			bookFile.write(reinterpret_cast<char*>(&book), sizeof(Book));
			bookFile.close();
		}
	}
	//创建初始的reader.dat文件
	{
		ofstream readerFile("reader.dat", ios::binary);
		if (readerFile.is_open()) {
			Reader reader;
			reader.addreader(1001, "张三");
			readerFile.write(reinterpret_cast<char*>(&reader), sizeof(Reader));
			reader.addreader(1002, "李四");
			readerFile.write(reinterpret_cast<char*>(&reader), sizeof(Reader));
			reader.addreader(1003, "王五");
			readerFile.write(reinterpret_cast<char*>(&reader), sizeof(Reader));
			reader.addreader(1004, "赵六");
			readerFile.write(reinterpret_cast<char*>(&reader), sizeof(Reader));
			reader.addreader(1005, "吴七");
			readerFile.write(reinterpret_cast<char*>(&reader), sizeof(Reader));
			readerFile.close();
		}
	}

	setlocale(LC_ALL, "");//设置控制台编码
	int choice = 1, bookid, readerid;
	RDatabase ReaderDB;
	BDatabase BookDB;
	Reader* r;
	Book* b;
	cout << "欢迎进入“小小图书馆”管理软件" << endl;
	cout << "*************************************" << endl;
	while (choice != 0)
	{
		cout << "-------------------------------------" << endl;
		cout << "1：借书 2：还书 3：图书维护 4：读者维护 0：离开" << endl;
		cout << "请选择你想要的功能:" << endl;
		cin >> choice;
		cout << "-------------------------------------" << endl;
		switch (choice)
		{
		case 1:
			cout << "输入借书读者编号: ";
			cin >> readerid;
			cout << "输入图书编号: ";
			cin >> bookid;
			r = ReaderDB.query(readerid);
		    if(r == NULL)
			{
				cout << "该读者不存在，不能借书！" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在，不能借书！" << endl;
				break;
			}
			if (b->borrowbook() == 0)
			{
				cout << "该图书已借出，不能借书！" << endl;
				break;
			}
			r->borrowbook(b->getnumber());
			break;
		case 2:
			cout << "输入还书读者编号：";
			cin >> readerid;
			cout << "输入图书编号:";
			cin >> bookid;
			r = ReaderDB.query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在，不能还书！" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在，不能还书！" << endl;
				break;
			}
			if (r->retbook(bookid))//添加还书提示语句
			{
				b->retbook();
				cout << "还书成功！" << endl;
			}
			else
			{
				cout << "该读者没有借到这本书，不能还书！" << endl;
			}
			break;
		case 3:
			BookDB.bookdata();
			break;
		case 4:
			ReaderDB.readerdata();
			break;
		}
	}
	return 0;
}