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

int main()
{
	//�˵��ĵ���
	int select;
	while (true)
	{
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1://���
			break;
		case 2://��ʾ
			break;
		case 3://ɾ��
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