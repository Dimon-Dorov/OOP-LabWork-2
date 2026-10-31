#pragma once
#include <string>

class Time
{
private:
	int hours;
	int minuts;
	int seconds;
	bool isValid(int h, int m, int s) const;
public:
	bool Init(int h, int m, int s);
	bool Init(const std::string& timeStr);
	bool Init(long totSec);
	bool Init(const Time& other);

	void Read();
	void Display() const;
	std::string toStr() const;
	long diffSec(const Time& other) const;
	void addSec(long s);
	void subtrSec(long s);
	int compare(const Time& other) const;
	long toSec() const;
	long toMin() const;
};

