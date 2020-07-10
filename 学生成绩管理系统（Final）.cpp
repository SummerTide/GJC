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
	static void heading();//输出成绩标题
	void output();//输出成绩信息
	float CalTotalMark();//计算总评成绩=平时*50%+期末*50%
private:
	int id;//学号
	char name[20];//姓名
	float regularGrade, finalExam;//平时成绩和期末考试成绩
};

void Input(Student stu[], int& num);//输入函数
void Output(Student stu[], int num);//输出函数
void Statis(Student stu[], int num);//统计函数
void Order(Student stu[], int num);//排序函数
void Search(Student stu[], int num);//查找函数
void Delete(Student stu[], int& num);//删除函数
void menu();//显示主界面函数


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
	cout << setfill(' ') << setw(8) << "学号"<<"\t  姓名\t   平时\t   期末\n";
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

void menu()//主界面显示函数
{
	cout << '\t' << setfill('=') << setw(41) << '='<<endl;
	cout << '\t' << "=\t   欢迎使用成绩管理系统   \t=" << endl;
	cout << '\t' << "=\t1=录入学生\t2=显示信息\t=" << endl;
	cout << '\t' << "=\t3=排序总评\t4=查找学生\t=" << endl;
	cout << '\t' << "=\t5=插入学生\t6=删除学生\t=" << endl;
	cout << '\t' << "=\t7=统计人数\t0=退出    \t=" << endl;
	cout << '\t' << setfill('=') << setw(41) <<'='<< endl;
	cout << "请选择：";
}

void Input(Student stu[], int& num)//已调试完毕
{
sign:
	if (num == 40)
	{
		cout << "人数已达到40人上限，无法再输入！";
		goto end;
	}
	{
		int id;
		cout << "请输入学号（1-40之间）：";
		while (1)//检测输入的学号是否在范围内
		{
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
				string id_string;
				cin >> id_string;
				cout<< "输入错误，学号应该在1到40之间！\n";
				cout << "请输入学号（1-40之间）：";
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
							cout << "学号不允许重复，该学号已存在！\n";
							cout << "请输入学号（1-40之间）：";
							break;
						}
						i++;
					}
				}
				else
				{
					cout << "输入错误，学号应该在1到40之间！\n";
					cout << "请输入学号（1-40之间）：";
					continue;
				}
		}
	sign2:
		cout << "请输入姓名：";
		stu[num].inputName();
		float result1;
		cout << "请输入平时成绩（0~100）：";
		while (1)
		{
			cin >> result1;
			if (cin.fail())
			{
				cin.clear();
				string result1_string;
				cin >> result1_string;
				cout << "输入错误，成绩应该在0到100之间！\n";
				cout << "请输入平时成绩（0~100）：";
				continue;
			}
			else if (result1 >= 0 && result1 <= 100)
				 {
					 stu[num].inputRegularGrade(result1);
					 break;
				 }
				 else
				 {
					 cout << "输入错误，成绩应该在0到100之间！\n";
					 cout << "请输入平时成绩（0~100）：";
					 continue;
				 }
		}
		float result2;
		cout << "请输入期末考试成绩（0~100）：";
		while (1)
		{
			cin >> result2;
			if (cin.fail())
			{
				cin.clear();
				string result2_string;
				cin >> result2_string;
				cout << "输入错误，成绩应该在0到100之间！\n";
				cout << "请输入期末考试成绩（0~100）：";
				continue;
			}
			else if (result2 >= 0 && result2 <= 100)
				 {
					stu[num].inputFinalExam(result2);
					break;
				 }
				 else
				 {
					 cout << "输入错误，成绩应该在0到100之间！\n";
					 cout << "请输入期末考试成绩（0~100）：";
					 continue;
				 }
		}
		num++;
		string go;
		cout << "继续输入学生数据请按y或Y：";
		cin >> go;
		if (go == "y" || go == "Y")//判断是否继续输入
			goto sign;
	}
end:
	cout << endl;
}

void Output(Student stu[], int num)//已调试完毕
{
	cout << endl;
	Student::heading();
	for (int n = 0; n < num; n++)
	{
		stu[n].output();
	}
	cout << endl;
}

void Order(Student stu[], int num)//已调试完毕
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

void Statis(Student stu[], int num)//已调试完毕
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
	cout << "请输入您要查找的学号：";
	cin >> find;
	if (cin.fail())
	{
		cin.clear();
		string find_string;
		cin >> find_string;
		cout << "请输入正确的学号！\n";
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
			cout << "没有该学号学生信息！\n";
			cout << "继续查找请按y或Y：";
			cin >> go;
			if (go == "y" || go == "Y")
				goto sign;
		}
		if (n == num - 1 && times != 0)
		{
			cout << "继续查找请按y或Y：";
			cin >> go;
			if (go == "y" || go == "Y")
				goto sign;
			cout << endl;
		}
	}
}

void Delete(Student stu[], int& num)//已调试完毕
{
sign:
	if (num == 0)
	{
		cout << "没有学生信息" << endl;
		goto sign2;
	}
	int id;
	cout << "请输入您要删除学生的学号：";
	cin >> id;
	if (cin.fail())
	{
		cin.clear();
		string id_string;
		cin >> id_string;
		cout << "请输入正确的学号！\n";
		goto sign;
	}
	for (int n = 0; n < num; n++)
	{
		if (stu[n].getId() == id && n != num - 1)
		{
			num--;
			for (int m = n; m < num; m++)
				stu[m] = stu[m + 1];
			cout << id << "号学生信息删除成功！\n";
			goto sign2;
		}
		if (stu[n].getId() == id && n == num - 1)
		{
			num--;
			cout << id << "号学生信息删除成功！\n";
			goto sign2;
		}
		if (n == num - 1)
			cout << "没有该学号学生！\n";	
	}
sign2:
	string go;
	cout << "继续删除其他学生请按y或Y：";
	cin >> go;
	if (go == "y" || go == "Y")
		goto sign;
	cout << endl;
}

int main()
{
	menu();
	Student stu[MAX_STUDENT_NUM];//定义数组，上限40
	stu[0].inputId(0);
	int x,i = 0;//i为总人数
	while (1)
	{
		cin >> x;
		if (cin.fail())
		{
			cin.clear();
			string x_string;
			cin >> x_string;
			cout << "输入非法，请重新输入！\n";
			menu();
			continue;
		}
		else
			switch (x)
			{
			case 0:return 0; break;
			case 1:cout << "您选择了1=录入学生\n"; Input(stu, i); break;
			case 2:cout << "您选择了2=显示信息\n"; Output(stu, i); break;
			case 3:cout << "您选择了3=排序总评\n"; Order(stu, i); break;
			case 4:cout << "您选择了4=查找学生\n"; Search(stu, i); break;
			case 5:cout << "您选择了5=插入学生\n"; Input(stu, i); break;
			case 6:cout << "您选择了6=删除学生\n"; Delete(stu, i); break;
			case 7:cout << "您选择了7=统计学生\n"; Statis(stu, i); break;
			default:cout << "输入非法，请重新输入！\n";
			}
		menu();
	}
	return 0;
}