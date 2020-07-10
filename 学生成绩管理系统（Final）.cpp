#include <iostream>
#include <iomanip>
#include <string>

const int MAX_STUDENT_NUM = 40;

using namespace std;

struct Student {
public:
	void inputId(int a);
	void inputName();
	void inputRegularGrade(float a);
	void inputFinalExam(float a);
	int getId();
	static void heading();//����ɼ�����
	void output();//����ɼ���Ϣ
	float CalTotalMark();//���������ɼ�=ƽʱ*50%+��ĩ*50%
private:
	int id;//ѧ��
	char name[20];//����
	float regularGrade, finalExam;//ƽʱ�ɼ�����ĩ���Գɼ�
};

void Input(Student stu[], int& num);//���뺯��
void Output(Student stu[], int num);//�������
void Statis(Student stu[], int num);//ͳ�ƺ���
void Order(Student stu[], int num);//������
void Search(Student stu[], int num);//���Һ���
void Delete(Student stu[], int& num);//ɾ������
void menu();//��ʾ�����溯��


void Student::inputId(int a)
{
	id = a;
}

void Student::inputName()
{
	cin >> name;
}

void Student::inputRegularGrade(float a)
{
	regularGrade = a;
}

void Student::inputFinalExam(float a)
{
	finalExam = a;
}

int Student::getId()
{
	return id;
}

void Student::heading()
{
	cout << setfill(' ') << setw(8) << "ѧ��"<<"\t  ����\t   ƽʱ\t   ��ĩ\n";
}

void Student::output()
{
	cout << setfill(' ')<<setw(8) << id << setw(14) << name<< '\t' << setw(7) << fixed << setprecision(1) << regularGrade << '\t' << setw(7) << finalExam << endl;
}
float Student::CalTotalMark()
{
	float result = regularGrade * (float)0.5 + finalExam * (float)0.5;
	return result;
}

void menu()//��������ʾ����
{
	cout << '\t' << setfill('=') << setw(41) << '='<<endl;
	cout << '\t' << "=\t   ��ӭʹ�óɼ�����ϵͳ   \t=" << endl;
	cout << '\t' << "=\t1=¼��ѧ��\t2=��ʾ��Ϣ\t=" << endl;
	cout << '\t' << "=\t3=��������\t4=����ѧ��\t=" << endl;
	cout << '\t' << "=\t5=����ѧ��\t6=ɾ��ѧ��\t=" << endl;
	cout << '\t' << "=\t7=ͳ������\t0=�˳�    \t=" << endl;
	cout << '\t' << setfill('=') << setw(41) <<'='<< endl;
	cout << "��ѡ��";
}

void Input(Student stu[], int& num)//�ѵ������
{
sign:
	if (num == 40)
	{
		cout << "�����Ѵﵽ40�����ޣ��޷������룡";
		goto end;
	}
	{
		int id;
		cout << "������ѧ�ţ�1-40֮�䣩��";
		while (1)//��������ѧ���Ƿ��ڷ�Χ��
		{
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
				string id_string;
				cin >> id_string;
				cout<< "�������ѧ��Ӧ����1��40֮�䣡\n";
				cout << "������ѧ�ţ�1-40֮�䣩��";
				continue;
			}
			else
				if (id >= 1 && id <= 40)
				{
					int i = 0;
					while (i <= num)
					{
						if (i == num)
						{
							stu[num].inputId(id);
							goto sign2;
						}
						if (stu[i].getId() == id)
						{
							cout << "ѧ�Ų������ظ�����ѧ���Ѵ��ڣ�\n";
							cout << "������ѧ�ţ�1-40֮�䣩��";
							break;
						}
						i++;
					}
				}
				else
				{
					cout << "�������ѧ��Ӧ����1��40֮�䣡\n";
					cout << "������ѧ�ţ�1-40֮�䣩��";
					continue;
				}
		}
	sign2:
		cout << "������������";
		stu[num].inputName();
		float result1;
		cout << "������ƽʱ�ɼ���0~100����";
		while (1)
		{
			cin >> result1;
			if (cin.fail())
			{
				cin.clear();
				string result1_string;
				cin >> result1_string;
				cout << "������󣬳ɼ�Ӧ����0��100֮�䣡\n";
				cout << "������ƽʱ�ɼ���0~100����";
				continue;
			}
			else if (result1 >= 0 && result1 <= 100)
				 {
					 stu[num].inputRegularGrade(result1);
					 break;
				 }
				 else
				 {
					 cout << "������󣬳ɼ�Ӧ����0��100֮�䣡\n";
					 cout << "������ƽʱ�ɼ���0~100����";
					 continue;
				 }
		}
		float result2;
		cout << "��������ĩ���Գɼ���0~100����";
		while (1)
		{
			cin >> result2;
			if (cin.fail())
			{
				cin.clear();
				string result2_string;
				cin >> result2_string;
				cout << "������󣬳ɼ�Ӧ����0��100֮�䣡\n";
				cout << "��������ĩ���Գɼ���0~100����";
				continue;
			}
			else if (result2 >= 0 && result2 <= 100)
				 {
					stu[num].inputFinalExam(result2);
					break;
				 }
				 else
				 {
					 cout << "������󣬳ɼ�Ӧ����0��100֮�䣡\n";
					 cout << "��������ĩ���Գɼ���0~100����";
					 continue;
				 }
		}
		num++;
		string go;
		cout << "��������ѧ�������밴y��Y��";
		cin >> go;
		if (go == "y" || go == "Y")//�ж��Ƿ��������
			goto sign;
	}
end:
	cout << endl;
}

void Output(Student stu[], int num)//�ѵ������
{
	cout << endl;
	Student::heading();
	for (int n = 0; n < num; n++)
	{
		stu[n].output();
	}
	cout << endl;
}

void Order(Student stu[], int num)//�ѵ������
{
	cout << endl;
	for (int n = 0; n < num; n++)
	{
		for (int m = n + 1; m < num; m++)
		{
			if (stu[n].CalTotalMark() < stu[m].CalTotalMark())
				swap(stu[n], stu[m]);
		}
	}
	Student::heading();
	for (int n = 0; n < num; n++)
	{
		stu[n].output();
	}
	cout << endl;
}

void Statis(Student stu[], int num)//�ѵ������
{
	int statis[5] = { 0 };
	for (int n = 0; n < num; n++)
	{
		if (stu[n].CalTotalMark() >= 90)
			statis[0]++;
		else
			if (stu[n].CalTotalMark() >= 80)
				statis[1]++;
			else
				if (stu[n].CalTotalMark() >= 70)
					statis[2]++;
				else
					if (stu[n].CalTotalMark() >= 60)
						statis[3]++;
					else
						statis[4]++;
	}
	cout << "    100~90     89~80    79~70    69~60    <60    \n";
	cout << setfill(' ') << setw(8) << statis[0] << setw(10) << statis[1] << setw(9) << statis[2] << setw(9) << statis[3] << setw(8) << statis[4] << endl;
}

void Search(Student stu[], int num)
{
	sign:
	float find;
	cout << "��������Ҫ���ҵ�ѧ�ţ�";
	cin >> find;
	if (cin.fail())
	{
		cin.clear();
		string find_string;
		cin >> find_string;
		cout << "��������ȷ��ѧ�ţ�\n";
		goto sign;
	}
	string go;
	for (int n = 0, times = 0; n < num; n++)
	{
		if (stu[n].getId() == find)
		{
			times++;
			Student::heading();
			stu[n].output();
		}
		if (n == num - 1 && times == 0)
		{
			cout << "û�и�ѧ��ѧ����Ϣ��\n";
			cout << "���������밴y��Y��";
			cin >> go;
			if (go == "y" || go == "Y")
				goto sign;
		}
		if (n == num - 1 && times != 0)
		{
			cout << "���������밴y��Y��";
			cin >> go;
			if (go == "y" || go == "Y")
				goto sign;
			cout << endl;
		}
	}
}

void Delete(Student stu[], int& num)//�ѵ������
{
sign:
	if (num == 0)
	{
		cout << "û��ѧ����Ϣ" << endl;
		goto sign2;
	}
	int id;
	cout << "��������Ҫɾ��ѧ����ѧ�ţ�";
	cin >> id;
	if (cin.fail())
	{
		cin.clear();
		string id_string;
		cin >> id_string;
		cout << "��������ȷ��ѧ�ţ�\n";
		goto sign;
	}
	for (int n = 0; n < num; n++)
	{
		if (stu[n].getId() == id && n != num - 1)
		{
			num--;
			for (int m = n; m < num; m++)
				stu[m] = stu[m + 1];
			cout << id << "��ѧ����Ϣɾ���ɹ���\n";
			goto sign2;
		}
		if (stu[n].getId() == id && n == num - 1)
		{
			num--;
			cout << id << "��ѧ����Ϣɾ���ɹ���\n";
			goto sign2;
		}
		if (n == num - 1)
			cout << "û�и�ѧ��ѧ����\n";	
	}
sign2:
	string go;
	cout << "����ɾ������ѧ���밴y��Y��";
	cin >> go;
	if (go == "y" || go == "Y")
		goto sign;
	cout << endl;
}

int main()
{
	menu();
	Student stu[MAX_STUDENT_NUM];//�������飬����40
	stu[0].inputId(0);
	int x,i = 0;//iΪ������
	while (1)
	{
		cin >> x;
		if (cin.fail())
		{
			cin.clear();
			string x_string;
			cin >> x_string;
			cout << "����Ƿ������������룡\n";
			menu();
			continue;
		}
		else
			switch (x)
			{
			case 0:return 0; break;
			case 1:cout << "��ѡ����1=¼��ѧ��\n"; Input(stu, i); break;
			case 2:cout << "��ѡ����2=��ʾ��Ϣ\n"; Output(stu, i); break;
			case 3:cout << "��ѡ����3=��������\n"; Order(stu, i); break;
			case 4:cout << "��ѡ����4=����ѧ��\n"; Search(stu, i); break;
			case 5:cout << "��ѡ����5=����ѧ��\n"; Input(stu, i); break;
			case 6:cout << "��ѡ����6=ɾ��ѧ��\n"; Delete(stu, i); break;
			case 7:cout << "��ѡ����7=ͳ��ѧ��\n"; Statis(stu, i); break;
			default:cout << "����Ƿ������������룡\n";
			}
		menu();
	}
	return 0;
}