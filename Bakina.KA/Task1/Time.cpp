#include <iostream>
#include <cstdlib>
#include <locale>
#include "Time.h"
using namespace std;

//����������� �� ���������
Time::Time()
{
	hou = 0;
	min = 0;
	sec = 0;
}
//����������� �����������
Time::Time(const Time& t)
{
	hou = t.hou;
	min = t.min;
	sec = t.sec;

}

//����������� �������������� ����
Time::Time(string t)
{
	hou = (t[0] - '0') * 10 + t[1] - '0';
	min = (t[3] - '0') * 10 + t[4] - '0';
	sec = (t[6] - '0') * 10 + t[7] - '0';
	(*this).perepol();
}


//�����������-�������������
Time::Time(int _hou, int _min, int _sec)
{
	hou = _hou;
	min = _min;
	sec = _sec;
	(*this).perepol();
}

//����������
Time::~Time()
{
	hou = 0;
	min = 0;
	sec = 0;
}

//����� ������������� ������ � ���� ������

string Time::TimeToString()
{
	string res("00:00:00");
	res[0] = hou / 10 + '0';
	res[1] = hou % 10 + '0';
	res[3] = min / 10 + '0';
	res[4] = min % 10 + '0';
	res[6] = sec / 10 + '0';
	res[7] = sec % 10 + '0';
	return res;
}

//���������� �������� ������������
Time& Time::operator=(const Time& c)
{
	hou = c.hou;
	min = c.min;
	sec = c.sec;
	return *this;
}

Time Time::perepol()
{
	min += sec / 60;
	sec %= 60;
	hou += min / 60;
	min %= 60;
	hou %= 24;
	return *this;
}
//���������� �������� ��������
Time Time::operator+(const Time& c)
{
	Time res;
	res.sec = sec + c.sec;
	res.min = min + c.min;
	res.hou = hou + c.hou;
	(res).perepol();
	return res;
}


//���������� �������� ���������
Time Time::operator-(const Time& c)
{
	Time res;
	if (sec < c.sec)
	{
		min--;
		res.sec = 60 + sec - c.sec;
	}
	else
		res.sec = sec - c.sec;

	if (min < c.min)
	{
		hou--;
		res.min = 60 + min - c.min;
	}
	else
		res.min = min - c.min;

	if (hou < c.hou)
	{
		res.hou = 24 + hou - c.hou;
	}
	else
		res.hou = hou - c.hou;
	return res;
}




//���������� �������� ��������� >
bool Time::operator>(const Time& c)
{

	if (hou > c.hou)
		return true;
	else
	{
		if (hou == c.hou)
			if (min > c.min)
				return true;
			else
				if (min == c.min)
					if (sec > c.sec)
						return true;
					else
						return false;

				else
					return false;
		else
			return false;
	}
}

//���������� �������� ��������� <
bool Time::operator<(const Time& c)
{
	if (hou < c.hou)
		return true;
	else
	{
		if (hou == c.hou)
			if (min < c.min)
				return true;
			else
				if (min == c.min)
					if (sec < c.sec)
						return true;
					else
						return false;

				else
					return false;
		else
			return false;
	}

}

//���������� �������� ��������� ==
bool Time::operator==(const Time& c)
{
	return hou == c.hou && min == c.min && sec == c.sec;
}

//���������� �������� ��������� >=
bool Time::operator>=(const Time& c)
{
	if (hou > c.hou)
		return true;
	else
	{
		if (hou == c.hou)
			if (min > c.min)
				return true;
			else
				if (min == c.min)
					if (sec >= c.sec)
						return true;
					else
						return false;

				else
					return false;
		else
			return false;
	}
}

//���������� �������� ��������� <=
bool Time::operator<=(const Time& c)
{
	if (hou < c.hou)
		return true;
	else
	{
		if (hou == c.hou)
			if (min < c.min)
				return true;
			else
				if (min == c.min)
					if (sec <= c.sec)
						return true;
					else
						return false;

				else
					return false;
		else
			return false;
	}
}

//���������� �������� ��������� !=
bool Time::operator!=(const Time& c)
{
	return hou != c.hou && min != c.min && sec != c.sec;
}
//���������� �������� ������ � �����
ostream& operator<<(ostream& stream, const Time& c)
{
	stream << c.hou << ':' << c.min << ':' << c.sec << endl;
	return stream;
}

//���������� �������� ����� � ���ok
istream& operator>>(istream& stream, Time& c)
{
	stream >> c.hou >> c.min >> c.sec;;
	return stream;
}

//output
void Time::ToutPut(const char* name)
{

	cout << name << ": hou = " << hou << ": min = " << min << ": sec = " << sec << endl;

}

//inPut
void Time::TinPut()
{
	cout << "������� ���� (�� 0 �� 24)" << endl;

	cin >> hou;

	cout << "������� ������ (�� 0 �� 60)" << endl;

	cin >> min;

	cout << "������� ������� (�� 0 �� 60)" << endl;

	cin >> sec;
	(*this).perepol();
}

int Time::getHour()
{
	return hou;
}
int Time::getMin()
{
	return min;
}
int Time::getSec()
{
	return sec;
}

void Time::setHour(int _hou)
{
	hou = _hou;
}
void Time::setMin(int _min)
{
	min = _min;
}
void Time::setSec(int _sec)
{
	sec = _sec;
}
void Time::setTime(int _hou, int _min, int _sec)
{
	hou = _hou;
	min = _min;
	sec = _sec;
}