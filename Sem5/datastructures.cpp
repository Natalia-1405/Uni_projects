#include "datastructures.h"
#include <string.h>

using namespace std;

void Students::loadStudents()
{
    data.clear();
	FILE *fp;
	fp = fopen("students.dat", "rb");
	if(fp)
	{
		int count;
		fread(&count, sizeof(int), 1, fp);

		for(int i=0; i<count; i++)
		{
			Student s;
			fread(&s, sizeof(Student), 1, fp);
			data.push_back(s);
		}
		fclose(fp);
    }
}

void Students::saveStudents()
{
	FILE *fp;
	fp=fopen("students.dat", "wb");
	if(fp)
	{
		int count = data.size();
		fwrite(&count, sizeof(int), 1, fp);

		for(int i=0; i<data.size(); i++)
		{
			fwrite(&data[i], sizeof(Student), 1, fp);
		}
		fclose(fp);
	}
}

void Students::addNew(Student s)
{
	data.push_back(s);
}

void Students::remove(int i)
{
	if (i>=0 && i<data.size())
	{
		data.erase(data.begin() + i);
	}
}

void Students::update(int i, Student s)
{
	if(i>=0 && i<data.size())
	{
        data[i]=s;
    }
}

Student Students::get(int i)
{
	if(i>=0 && i<data.size())
	{
		return data[i];
	}
	return Student();
}

int Students::size()
{
	return data.size();
}

Student::Student()
{
	strcpy(firstName, "");
	strcpy(lastName, "");
    strcpy(className, "");
	strcpy(notes, "");
}

char* Student::getFirstName()
{
	return firstName;
}

char* Student::getLastName()
{
	return lastName;
}

char* Student::getClassName()
{
	return className;
}

char* Student::getNotes()
{
	return notes;
}

void Student::setFirstName(char* fn)
{
	strcpy(firstName, fn);
}

void Student::setLastName(char* ln)
{
	strcpy(lastName, ln);
}

void Student::setClassName(char* cn)
{
	strcpy(className, cn);
}

void Student::setNotes(char* note)
{
	strcpy(notes, note);
}

void Visits::loadVisits()
{
	data.clear();

	FILE *fp;
	fp=fopen("visits.dat", "rb");
	if(fp)
	{
		int count;
		fread(&count, sizeof(int), 1, fp);

		for(int i=0; i<count; i++)
		{
			Visit v;
			fread(&v, sizeof(Visit), 1, fp);
			data.push_back(v);
		}
		fclose(fp);
	}

    archive.clear();
	fp=fopen("visits_archive.dat", "rb");
	if(fp)
	{
		int count;
		fread(&count, sizeof(int), 1, fp);

		for(int i=0; i<count; i++)
		{
			Visit v;
			fread(&v, sizeof(Visit), 1, fp);
			archive.push_back(v);
		}
		fclose(fp);
    }
}

void Visits::saveVisits()
{
	FILE *fp;
	fp=fopen("visits.dat", "wb");
	if(fp)
	{
		int count=data.size();
		fwrite(&count, sizeof(int), 1, fp);

		for(int i=0; i<data.size(); i++)
		{
			fwrite(&data[i], sizeof(Visit), 1, fp);
		}
		fclose(fp);
	}

	fp=fopen("visits_archive.dat", "wb");
	if(fp)
	{
		int count=archive.size();
		fwrite(&count, sizeof(int), 1, fp);

		for(int i=0; i<archive.size(); i++)
		{
			fwrite(&archive[i], sizeof(Visit), 1, fp);
		}
		fclose(fp);
	}
}

void Visits::addNew(Visit v)
{
	data.push_back(v);
	sortDate();

}

void Visits::remove(int i)
{
	if (i>=0 && i<data.size())
	{
		data.erase(data.begin()+i);
	}
}

void Visits::update(int i, Visit v)
{
	if(i>=0 && i<data.size())
	{
		data[i]=v;
    }
}

Visit Visits::get(int i)
{
	if(i>=0 && i<data.size())
	{
		return data[i];
	}
	return Visit();
}

int Visits::size()
{
    return data.size();
}

Visit Visits::getArchive(int i)
{
	if(i>=0 && i<archive.size())
	{
		return archive[i];
	}
	return Visit();
}

int Visits::sizeArchive()
{
	return archive.size();
}

void Visits::moveToArchive(int i)
{
	if(i>=0 && i<data.size())
	{
		archive.push_back(data[i]);
		data.erase(data.begin() + i);
        sortDateArchive();
	}
}

int Visits::getMonthly(int y, int m)
{
	int total=0;
	for(int i=0; i<archive.size(); i++)
	{
		if(archive[i].getYear() == y && archive[i].getMonth()==m)
		{
			total+=1;
		}
	}
	return total;
}

int Visits::getTotal(int y)
{
	int total=0;
    for(int i=0; i<archive.size(); i++)
	{
		if(archive[i].getYear() == y)
		{
			total+=1;
		}
	}
	return total;
}

void Visits::sortDate()
{
	Visit pom;
	for(int nr=1; nr<data.size(); nr++)
	{
	   for(int i=0; i<data.size()-nr; i++)
	   {
		   if(data[i].getYear()>data[i+1].getYear() ||
		   (data[i].getYear()==data[i+1].getYear() && data[i].getMonth()>data[i+1].getMonth()) ||
		   (data[i].getYear()==data[i+1].getYear() && data[i].getMonth()==data[i+1].getMonth() && data[i].getDay()>data[i+1].getDay()) ||
		   (data[i].getYear()==data[i+1].getYear() && data[i].getMonth()==data[i+1].getMonth() && data[i].getDay()==data[i+1].getDay() && data[i].getHour()>data[i+1].getHour()) ||
		   (data[i].getYear()==data[i+1].getYear() && data[i].getMonth()==data[i+1].getMonth() && data[i].getDay()==data[i+1].getDay() && data[i].getHour()==data[i+1].getHour() && data[i].getMinutes()>data[i+1].getMinutes()))
		   {
				pom=data[i];
				data[i]=data[i+1];
				data[i+1]=pom;
		   }
	   }
	}
}

void Visits::sortDateArchive()
{
	Visit pom;
		for(int nr=1; nr<archive.size(); nr++)
		{
		   for(int i=0; i<archive.size()-nr; i++)
		   {
			   if(archive[i].getYear()>archive[i+1].getYear() ||
			   (archive[i].getYear()==archive[i+1].getYear() && archive[i].getMonth()>archive[i+1].getMonth()) ||
			   (archive[i].getYear()==archive[i+1].getYear() && archive[i].getMonth()==archive[i+1].getMonth() && archive[i].getDay()>archive[i+1].getDay()) ||
			   (archive[i].getYear()==archive[i+1].getYear() && archive[i].getMonth()==archive[i+1].getMonth() && archive[i].getDay()==archive[i+1].getDay() && archive[i].getHour()>archive[i+1].getHour()) ||
			   (archive[i].getYear()==archive[i+1].getYear() && archive[i].getMonth()==archive[i+1].getMonth() && archive[i].getDay()==archive[i+1].getDay() && archive[i].getHour()==archive[i+1].getHour() && archive[i].getMinutes()>archive[i+1].getMinutes()))
			   {
					pom=archive[i];
					archive[i]=archive[i+1];
					archive[i+1]=pom;
			   }
		   }
		}
}

Visit::Visit()
{
	year=0;
	month=0;
	day=0;
	hour=0;
	minutes=0;
	duration=0;
	strcpy(firstName, "");
	strcpy(lastName, "");
	strcpy(notes, "");
}

int Visit::getYear()
{
	return year;
}

int Visit::getMonth()
{
	return month;
}

int Visit::getDay()
{
	return day;
}

int Visit::getHour()
{
	return hour;
}

int Visit::getMinutes()
{
	return minutes;
}

int Visit::getDuration()
{
	return duration;
}

char* Visit::getFirstName()
{
	return firstName;
}

char* Visit::getLastName()
{
	return lastName;
}

char* Visit::getNotes()
{
	return notes;
}

void Visit::setYear(int y)
{
	year=y;
}

void Visit::setMonth(int m)
{
	month=m;
}

void Visit::setDay(int d)
{
	day=d;
}

void Visit::setHour(int h)
{
	hour=h;
}

void Visit::setMinutes(int m)
{
	minutes=m;
}

void Visit::setDuration(int dur)
{
	duration=dur;
}

void Visit::setFirstName(char* fn)
{
	strcpy(firstName, fn);
}

void Visit::setLastName(char* ln)
{
	strcpy(lastName, ln);
}

void Visit::setNotes(char* n)
{
    strcpy(notes, n);
}

Income::Income()
{
	amount=0;
	year=0;
	month=0;
}

float Income::getAmount()
{
	return amount;
}

int Income::getYear()
{
	return year;
}

int Income::getMonth()
{
    return month;
}

void Income::setAmount(float a)
{
	amount=a;
}

void Income::setYear(int y)
{
	year=y;
}

void Income::setMonth(int m)
{
	month=m;
}

void Incomes::loadIncome()
{
	data.clear();

	FILE *fp;
	fp=fopen("income.dat", "rb");
	if(fp)
	{
		int count;
		fread(&count, sizeof(int), 1, fp);

		for(int i=0; i<count; i++)
		{
			Income in;
			fread(&in, sizeof(Income), 1, fp);
			data.push_back(in);
		}
		fclose(fp);
	}
}

void Incomes::saveIncome()
{
	FILE *fp;
	fp=fopen("income.dat", "wb");
	if(fp)
	{
		int count=data.size();
		fwrite(&count, sizeof(int), 1, fp);

		for(int i=0; i<data.size(); i++)
		{
			fwrite(&data[i], sizeof(Income), 1, fp);
		}
		fclose(fp);
    }
}

void Incomes::addNew(Income in)
{
	data.push_back(in);
}

Income Incomes::get(int i)
{
	if(i>=0 && i<data.size())
	{
		return data[i];
	}
	return Income();
}

int Incomes::size()
{
	return data.size();
}

float Incomes::getQuarterTotal(int y, int q)
{
	float total=0;
	int start=0;
    int end=0;
	if(q==1)
	{
		start=1;
		end=3;
	}
	else if(q==2)
	{
		start=4;
		end=6;
	}
	else if(q==3)
	{
		start=7;
		end=9;
	}
	else if(q==4)
	{
		start=10;
		end=12;
	}

	for(int i=0; i<data.size(); i++)
	{
		if(data[i].getYear() == y && data[i].getMonth()>=start && data[i].getMonth()<=end)
		{
			total+=data[i].getAmount();
		}
	}
	return total;
}

float Incomes::getTotal(int y)
{
	int total=0;
	for(int i=0; i<data.size(); i++)
	{
		if(data[i].getYear() == y)
		{
			total+=data[i].getAmount();
		}
	}
	return total;
}

UserSettings::UserSettings()
{
	strcpy(userName, "");
	hourlyRate=0;
}

void UserSettings::setHourlyRate(float rate)
{
	hourlyRate=rate;
}

void UserSettings::setUserName(char *name)
{
   strcpy(userName, name);
}

char* UserSettings::getUserName()
{
	return userName;
}

float UserSettings::getHourlyRate()
{
	return hourlyRate;
}

void  UserSettings::saveSettings()
{
	FILE *fp;
	fp=fopen("settings.dat", "wb");
	if(fp)
	{
		fwrite(this, sizeof(UserSettings), 1, fp);
		fclose(fp);
	}
}

void  UserSettings::loadSettings()
{
	FILE *fp;
	fp=fopen("settings.dat", "rb");
	if(fp)
	{
		fread(this, sizeof(UserSettings), 1, fp);
		fclose(fp);
	}
}