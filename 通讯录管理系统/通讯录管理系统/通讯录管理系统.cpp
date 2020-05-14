//��װ������ʾ�ý���
//-��main�����е��÷�װ�õĺ���

#include <iostream>
#include <string>
using namespace std;
#define MAX 1000
//�����ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա� 1 �� 2 Ů
	int n_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;

};

//ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
};
//�˵�����
void showMenu()
{
	cout << "**********************" << endl;
	cout << "*****1.�����ϵ��*****" << endl;
	cout << "*****2.��ʾ��ϵ��*****" << endl;
	cout << "*****3.ɾ����ϵ��*****" << endl;
	cout << "*****4.������ϵ��*****" << endl;
	cout << "*****5.�޸���ϵ��*****" << endl;
	cout << "*****6.�����ϵ��*****" << endl;
	cout << "*****0.�˳�ͨѶ¼*****" << endl;
	cout << "**********************" << endl;

}
//�����ϵ��
void addPerson(Addressbooks *abs)
{
	//�ж�ͨѶ¼�Ƿ����ˣ����˾Ͳ��������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	//�������
	string name;
	cout << "����������: " << endl;
	cin >> name;
	abs->personArray[abs->m_Size].m_Name = name;

	cout << "�������Ա�" << endl;
	cout << "1------��" << endl;
	cout << "2------Ů" << endl;
	int sex = 0;
	while (true)
	{
		//����������1����2�����˳�ѭ������Ϊ���������ȷֵ
		//����������������
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArray[abs->m_Size].n_Sex = sex;
			break;
		}
		
	}

	cout << "���������䣺" << endl;
	int age;
	cin >> age;
	abs->personArray[abs->m_Size].m_Age = age;

	cout << "������绰��" << endl;
	string phone;
	cin >> phone;
	abs->personArray[abs->m_Size].m_Phone = phone;

	cout << "�������ַ��" << endl;
	string addr;
	cin >> addr;
	abs->personArray[abs->m_Size].m_Addr = addr;
	abs->m_Size++;
	cout << "��ӳɹ�" << endl;

	system("cls");


}


//��ʾ���е���ϵ��
void showPerson(Addressbooks *abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < abs->m_Size; i++)
	{
		cout << "����:" << abs->personArray[i].m_Name << "\t";
		cout << "����:" << (abs->personArray[i].m_Age==1?"��":"Ů") << "\t";
		cout << "�Ա�:" << abs->personArray[i].n_Sex << "\t";
		cout << "�绰:" << abs->personArray[i].m_Phone << "\t";
		cout << "��ַ:" << abs->personArray[i].m_Addr<<endl;
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
			return i;//�ҵ��˷��ض�Ӧ�������±���
		}
	}
	return -1;
}
//ɾ����ϵ��
void deletePerson(Addressbooks *abs)
{
	cout << "������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
int main()
{
	//����ͨѶ¼�Ľṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��������
	abs.m_Size = 0;
	//�˵��ĵ���
	int select;
	while (true)
	{
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1://���
			addPerson(&abs);
			break;
		case 2://��ʾ
			showPerson(&abs);
			break;
		case 3://ɾ��
			deletePerson(&abs);
			break;
		case 4://����
			break;
		case 5://�޸�
			break;
		case 6://���
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	
	}
	return 0;
}