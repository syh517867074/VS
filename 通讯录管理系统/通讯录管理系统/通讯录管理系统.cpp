//封装函数显示该界面
//-在main函数中调用封装好的函数

#include <iostream>
using namespace std;

//菜单界面
void showMenu()
{
	cout << "**********************" << endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出通讯录*****" << endl;
	cout << "**********************" << endl;
}

int main()
{
	//菜单的调用
	int select;
	while (true)
	{
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1://添加
			break;
		case 2://显示
			break;
		case 3://删除
			break;
		case 4://查找
			break;
		case 5://修改
			break;
		case 6://清空
			break;
		case 0://退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	
	}
	return 0;
}