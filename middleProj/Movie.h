#pragma once
#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include<vector>
#include<map>
using namespace std;
class Movie
{
private:
	string name, seat;
	int age;
	int movieTimeArr[4] = { 0 };
	map<string, vector<string>>movieSeat;
public:
	Movie(string n, int a, string s);
	~Movie();
	string getName() const { return name; }
	string getSeat() const { return seat; }
	int getmovieTime(int num) { return movieTimeArr[num]; }
	void addPersonTime(int person, int time) { movieTimeArr[time] += person; }
	void replacePersonTime(int time) { movieTimeArr[time] = 0; }
	int getAge() const { return age; }
	void getmovieSeat(Movie* m, int menu);
	void printMovieSeat(Movie* m, int person, int menu);
};
#endif




