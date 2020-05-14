//封装函数显示该界面
//-在main函数中调用封装好的函数

#include <iostream>
#include <string>
using namespace std;
#define MAX 1000
//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别 1 男 2 女
	int n_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;

};

//通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录联系人个数
	int m_Size;
};
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
//添加联系人
void addPerson(Addressbooks *abs)
{
	//判断通讯录是否满了，满了就不再添加了
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	//添加姓名
	string name;
	cout << "请输入姓名: " << endl;
	cin >> name;
	abs->personArray[abs->m_Size].m_Name = name;

	cout << "请输入性别：" << endl;
	cout << "1------男" << endl;
	cout << "2------女" << endl;
	int sex = 0;
	while (true)
	{
		//如果输入的是1或者2可以退出循环，因为输入的是正确值
		//输入有误，重新输入
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArray[abs->m_Size].n_Sex = sex;
			break;
		}
		
	}

	cout << "请输入年龄：" << endl;
	int age;
	cin >> age;
	abs->personArray[abs->m_Size].m_Age = age;

	cout << "请输入电话：" << endl;
	string phone;
	cin >> phone;
	abs->personArray[abs->m_Size].m_Phone = phone;

	cout << "请输入地址：" << endl;
	string addr;
	cin >> addr;
	abs->personArray[abs->m_Size].m_Addr = addr;
	abs->m_Size++;
	cout << "添加成功" << endl;

	system("cls");


}


//显示所有的联系人
void showPerson(Addressbooks *abs)
{
	//判断通讯录中人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < abs->m_Size; i++)
	{
		cout << "姓名:" << abs->personArray[i].m_Name << "\t";
		cout << "年龄:" << (abs->personArray[i].m_Age==1?"男":"女") << "\t";
		cout << "性别:" << abs->personArray[i].n_Sex << "\t";
		cout << "电话:" << abs->personArray[i].m_Phone << "\t";
		cout << "地址:" << abs->personArray[i].m_Addr<<endl;
		//cout << "-------------------------" << endl;
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks*abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;//找到了返回对应的数组下标结果
		}
	}
	return -1;
}
//删除联系人
void deletePerson(Addressbooks *abs)
{
	cout << "请输入要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
int main()
{
	//创建通讯录的结构体变量
	Addressbooks abs;
	//初始话通讯录中当前人数个数
	abs.m_Size = 0;
	//菜单的调用
	int select;
	while (true)
	{
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1://添加
			addPerson(&abs);
			break;
		case 2://显示
			showPerson(&abs);
			break;
		case 3://删除
			deletePerson(&abs);
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