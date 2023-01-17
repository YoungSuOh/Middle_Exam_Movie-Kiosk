#include"Movie.h"
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<>distrib(1, 4);
int result = 0;
void printMenu()
{
	cout << "=============================================\n";
	cout << "1. 영화 예매\n2. 프로그램 종료\n";
	cout << "=============================================\n";
	cout << "원하시는 메뉴를 선택해 주세요: ";
}
void Print_Movie_list(Movie* m)
{
	cout << "=============================================\n";
	for (int i = 0;i < 4;i++)
	{
		cout << i + 1 << ". " << m[i].getName() << " / " << m[i].getAge() << "세 관람가 / " << m[i].getSeat() << "관" << endl;
	}
	cout << "관람하실 영화를 선택해주세요: ";
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
	cout << "관람하실 시간을 선택해주세요: ";
}
void movieTimeSale(int menu, int time)
{
	if (menu == 1)
	{
		if (time == 1)
			cout << "조조 시간대입니다. 가격이 50% 할인됩니다.\n\n";
	}
	else if (menu == 2)
	{
		if (time == 1)
			cout << "조조 시간대입니다. 가격이 50% 할인됩니다.\n\n";
		if (time == 4)
			cout << "야간 시간대입니다. 가격이 50% 할인됩니다.\n\n";
	}
	else if (menu == 3)
	{
		if (time == 1)
			cout << "조조 시간대입니다. 가격이 50% 할인됩니다.\n\n";
		if (time == 2)
			cout << "야간 시간대입니다. 가격이 50% 할인됩니다.\n\n";
	}
	else if (menu == 4)
	{
		if (time == 1)
			cout << "조조 시간대입니다. 가격이 50% 할인됩니다.\n\n";
	}
}
void moviePerson(int person, Movie* m, int* arr, int menu)
{
	int a;
	cout << person << "명의 나이는? ";
	for (int i = 0;i < person;i++)
	{
		cin >> a;
		if (a < m[menu-1].getAge())
		{
			result = -1;
			cout << "성인의 동행 없이는 관람하실 수 없습니다.\n";
			break;
		}
		if (a < 12) { arr[0] += 1; }
		else if (a >= 12 && a <= 17) { arr[1] += 1; }
		else { arr[2] += 1; }
		cout << "나이는? ";
	}
	cout << endl;
}
void countMovieBills(int person, int arr[])
{
	int result = arr[0] * 5000 + arr[1] * 9000 + arr[2] * 11000;
	cout << "총인원 : " << person << "명, (어린이 " << arr[0] << "명, 청소년 " << arr[1] << "명, 성인 " << arr[2] << "명)\n\n";

	cout << "총 금액: " << result << "원\n";
	cout << "=============================================\n";
}
Movie* movie = new Movie[]
{
	Movie("마녀",15,"A"),Movie("탑건-매버릭",12,"B"),Movie("타짜",18,"A"),
	Movie("비욘드 라이브 더 무비 : 샤이니 월드",0,"B")
};
int main()
{
	int person = distrib(gen);
	int num, menu, time;
	int countPersonArr[3] = { 0 };  // 어린이, 학생, 성인
	result = 0;
	printMenu();	
	cin >> num;
	if (num == 1)             // 프로그램 실행일 경우
	{
		Print_Movie_list(movie);  // 영화 목록 출력
		cin >> menu;              // 영화 지정
		movieTime(menu,movie);    //  각 영화마다의 영화 시간 출력
		cin >> time;              //  볼 영화 시간 지정
		movieTimeSale(menu, time);                        // 조조, 야간 할인 받음
		movie[menu-1].addPersonTime(person, time-1);        // 자리수 누적시킴
		moviePerson(person, movie,countPersonArr,menu);  // 인원수에 맞춰 나이로 어린이, 학생, 성인 구분 및 관람 이용 나이제한 거름
		if (result != -1)
		{
			movie->printMovieSeat(movie,person,menu);       // 좌석 출력
			countMovieBills(person, countPersonArr);        // 인원의 정보에 맞게 요금 계산해줌
			cout << "사용해주셔서 감사합니다. 초기화면으로 돌아갑니다.\n\n";
			main();
		}
		else
		{
			movie[menu - 1].replacePersonTime(time - 1);    // 나이 제한이 걸렸을 경우이기 때문에 다시 자리수 초기화
			main();
		}			
	}
	else if (num == 2)          // 프로그램 종료일 경우
	{		
		delete[] movie;                     // 프로그램을 종료할 경우에 movie 객체 제거
		movie = nullptr;
		cout << "프로그램을 종료합니다." << endl;
	}
	else                         // 1,2 이외의 값일 경우
	{
		cout << "잘못된 입력입니다." << endl;		
		main();
	}
	return 0;	
}