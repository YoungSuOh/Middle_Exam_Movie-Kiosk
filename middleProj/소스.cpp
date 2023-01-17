#include"Movie.h"
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<>distrib(1, 4);
int result = 0;
void printMenu()
{
	cout << "=============================================\n";
	cout << "1. ��ȭ ����\n2. ���α׷� ����\n";
	cout << "=============================================\n";
	cout << "���Ͻô� �޴��� ������ �ּ���: ";
}
void Print_Movie_list(Movie* m)
{
	cout << "=============================================\n";
	for (int i = 0;i < 4;i++)
	{
		cout << i + 1 << ". " << m[i].getName() << " / " << m[i].getAge() << "�� ������ / " << m[i].getSeat() << "��" << endl;
	}
	cout << "�����Ͻ� ��ȭ�� �������ּ���: ";
}
void movieTime(int menu, Movie* m)
{
	cout << "=============================================\n";
	if (menu == 1)
	{
		cout << "1. 8:00" << setw(10) << m[0].getmovieTime(0) << "/" << 90 << endl;
		cout << "2. 12:00" << setw(10) << m[0].getmovieTime(1) << "/" << 90 << endl;
		cout << "3. 15:00" << setw(10) << m[0].getmovieTime(2) << "/" << 90 << endl;
		cout << "4. 21:00" << setw(10) << m[0].getmovieTime(3) << "/" << 90 << endl;
	}
	else if (menu == 2)
	{
		cout << "1. 7:20" << setw(10) << m[1].getmovieTime(0) << "/" << 140 << endl;
		cout << "2. 11:30" << setw(10) << m[1].getmovieTime(1) << "/" << 140 << endl;
		cout << "3. 13:00" << setw(10) << m[1].getmovieTime(2) << "/" << 140 << endl;
		cout << "4. 23:00" << setw(10) << m[1].getmovieTime(3) << "/" << 140 << endl;
	}
	else if (menu == 3)
	{
		cout << "1. 7:20" << setw(10) << m[2].getmovieTime(0) << "/" << 90 << endl;
		cout << "2. 23:30" << setw(10) << m[2].getmovieTime(1) << "/" << 90 << endl;
	}
	else if (menu == 4)
	{
		cout << "1. 9:50" << setw(10) << m[3].getmovieTime(0) << "/" << 140 << endl;
		cout << "2. 18:00" << setw(10) << m[3].getmovieTime(1) << "/" << 140 << endl;
		cout << "3. 21:15" << setw(10) << m[3].getmovieTime(2) << "/" << 140 << endl;
	}
	cout << "�����Ͻ� �ð��� �������ּ���: ";
}
void movieTimeSale(int menu, int time)
{
	if (menu == 1)
	{
		if (time == 1)
			cout << "���� �ð����Դϴ�. ������ 50% ���ε˴ϴ�.\n\n";
	}
	else if (menu == 2)
	{
		if (time == 1)
			cout << "���� �ð����Դϴ�. ������ 50% ���ε˴ϴ�.\n\n";
		if (time == 4)
			cout << "�߰� �ð����Դϴ�. ������ 50% ���ε˴ϴ�.\n\n";
	}
	else if (menu == 3)
	{
		if (time == 1)
			cout << "���� �ð����Դϴ�. ������ 50% ���ε˴ϴ�.\n\n";
		if (time == 2)
			cout << "�߰� �ð����Դϴ�. ������ 50% ���ε˴ϴ�.\n\n";
	}
	else if (menu == 4)
	{
		if (time == 1)
			cout << "���� �ð����Դϴ�. ������ 50% ���ε˴ϴ�.\n\n";
	}
}
void moviePerson(int person, Movie* m, int* arr, int menu)
{
	int a;
	cout << person << "���� ���̴�? ";
	for (int i = 0;i < person;i++)
	{
		cin >> a;
		if (a < m[menu-1].getAge())
		{
			result = -1;
			cout << "������ ���� ���̴� �����Ͻ� �� �����ϴ�.\n";
			break;
		}
		if (a < 12) { arr[0] += 1; }
		else if (a >= 12 && a <= 17) { arr[1] += 1; }
		else { arr[2] += 1; }
		cout << "���̴�? ";
	}
	cout << endl;
}
void countMovieBills(int person, int arr[])
{
	int result = arr[0] * 5000 + arr[1] * 9000 + arr[2] * 11000;
	cout << "���ο� : " << person << "��, (��� " << arr[0] << "��, û�ҳ� " << arr[1] << "��, ���� " << arr[2] << "��)\n\n";

	cout << "�� �ݾ�: " << result << "��\n";
	cout << "=============================================\n";
}
Movie* movie = new Movie[]
{
	Movie("����",15,"A"),Movie("ž��-�Ź���",12,"B"),Movie("Ÿ¥",18,"A"),
	Movie("���� ���̺� �� ���� : ���̴� ����",0,"B")
};
int main()
{
	int person = distrib(gen);
	int num, menu, time;
	int countPersonArr[3] = { 0 };  // ���, �л�, ����
	result = 0;
	printMenu();	
	cin >> num;
	if (num == 1)             // ���α׷� ������ ���
	{
		Print_Movie_list(movie);  // ��ȭ ��� ���
		cin >> menu;              // ��ȭ ����
		movieTime(menu,movie);    //  �� ��ȭ������ ��ȭ �ð� ���
		cin >> time;              //  �� ��ȭ �ð� ����
		movieTimeSale(menu, time);                        // ����, �߰� ���� ����
		movie[menu-1].addPersonTime(person, time-1);        // �ڸ��� ������Ŵ
		moviePerson(person, movie,countPersonArr,menu);  // �ο����� ���� ���̷� ���, �л�, ���� ���� �� ���� �̿� �������� �Ÿ�
		if (result != -1)
		{
			movie->printMovieSeat(movie,person,menu);       // �¼� ���
			countMovieBills(person, countPersonArr);        // �ο��� ������ �°� ��� �������
			cout << "������ּż� �����մϴ�. �ʱ�ȭ������ ���ư��ϴ�.\n\n";
			main();
		}
		else
		{
			movie[menu - 1].replacePersonTime(time - 1);    // ���� ������ �ɷ��� ����̱� ������ �ٽ� �ڸ��� �ʱ�ȭ
			main();
		}			
	}
	else if (num == 2)          // ���α׷� ������ ���
	{		
		delete[] movie;                     // ���α׷��� ������ ��쿡 movie ��ü ����
		movie = nullptr;
		cout << "���α׷��� �����մϴ�." << endl;
	}
	else                         // 1,2 �̿��� ���� ���
	{
		cout << "�߸��� �Է��Դϴ�." << endl;		
		main();
	}
	return 0;	
}