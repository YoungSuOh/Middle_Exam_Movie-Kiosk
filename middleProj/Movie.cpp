#include "Movie.h"

Movie::Movie(string n, int a, string s) :name(n), age(a), seat(s)
{
	string arr[7] = { "A","B","C","D","E","F","G"};
	vector<string>v;
	for (int i = 0;i < 20;i++)
	{
		v.push_back("��");
	}
	for (int i = 0;i <7;i++)
	{
		movieSeat[arr[i]] = v;
	}
}
Movie::~Movie(){}
void Movie::getmovieSeat(Movie* m,int menu)
{
	int column[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	map<string, vector<string>>::iterator iter;
	cout << "   ";
	for (int i = 0;i < 20;i++)
	{
		cout << setw(3) << column[i];
	}
	cout << endl;
	for (iter = m[menu-1].movieSeat.begin();iter != m[menu-1].movieSeat.end();iter++)
	{
		cout << setw(3) << iter->first;
		for (int j = 0;j < 20;j++)
		{
			cout << setw(3) << iter->second[j];
		}
		cout << endl;
	}
}
void Movie::printMovieSeat(Movie* m, int person,int menu)
{
	string row;
	int coloumn;
	map<string, vector<string>>::iterator iter;
	for (int i = 1; i <= person;i++)
	{
		getmovieSeat(m,menu);
		cout << i << "��° �������� ���� ������ �ּ��� (���ĺ�): ";
		cin >> row;
		cout << i << "��° �������� �¼���ȣ�� ������ �ּ��� (����): ";
		cin >> coloumn;
		cout << "�����߽��ϴ�.\n";
		for (iter = m[menu-1].movieSeat.begin();iter != m[menu-1].movieSeat.end();iter++)
		{
			if (iter->first == row)
			{
				if (iter->second[coloumn - 1] == "*")
				{
					cout << "�̹� �����̵� �ڸ��Դϴ�. �ٽ� �����Ͽ� �ֽʽÿ�." << endl;
					i--;
				}								
				else
				{
					iter->second[coloumn - 1] = "*";
				}
			}
		}
	}
}
