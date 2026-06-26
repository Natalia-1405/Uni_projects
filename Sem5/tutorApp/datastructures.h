#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <string.h>
#include <vector>

using namespace std;

class Student
{
	private:
		char firstName[30];
		char lastName[50];
		char className[20];
		char notes[500];
	public:
		Student();
		char* getFirstName();
		char* getLastName();
		char* getClassName();
		char* getNotes();
		void  setFirstName(char* fn);
		void  setLastName(char* ln);
		void  setClassName(char* cn);
		void  setNotes(char* note);
};

class Students
{
	private:
		vector<Student>data;
	public:
		void loadStudents();
		void saveStudents();
		void addNew(Student s);
		void remove(int i);
		void update(int i, Student s);
		Student get(int i);
		int size();
};

class Visit
{
	private:
		int year;
		int month;
		int day;
		int hour;
		int minutes;
		int duration;
		char firstName[30];
		char lastName[50];
		char notes[200];
	public:
		Visit();
		int getYear();
		int getMonth();
		int getDay();
		int getHour();
		int getMinutes();
		int getDuration();
		char* getFirstName();
		char* getLastName();
		char* getNotes();
		void setYear(int y);
		void setMonth(int m);
		void setDay(int d);
		void setHour(int h);
		void setMinutes(int m);
		void setDuration(int dur);
		void setFirstName(char* fn);
		void setLastName(char* ln);
        void setNotes(char* n);
};

class Visits
{
	private:
		vector<Visit>data;
		vector<Visit>archive;
	public:
		void loadVisits();
		void saveVisits();
		void addNew(Visit v);
		void remove(int i);
		void update(int i, Visit v);
		Visit get(int i);
		Visit getArchive(int i);
		int size();
		int sizeArchive();
		void moveToArchive(int i);
		int getMonthly(int y, int m);
		int getTotal(int y);
		void sortDate();
        void sortDateArchive();
};

class Income
{
	private:
		float amount;
		int year;
		int month;
	public:
		Income();
		float getAmount();
		int getYear();
		int getMonth();
		void setAmount(float a);
		void setYear(int y);
        void setMonth(int m);
};

class Incomes
{
	private:
		vector<Income>data;
	public:
		void loadIncome();
		void saveIncome();
		void addNew(Income in);
		Income get(int i);
		int size();
		float getQuarterTotal(int y, int q);
        float getTotal(int y);
};

class UserSettings
{
	private:
		float hourlyRate;
		char userName[30];
	public:
		UserSettings();
		void  setHourlyRate(float rate);
		void  setUserName(char *name);
		char* getUserName();
		float getHourlyRate();
		void  saveSettings();
        void  loadSettings();
};

#endif