#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <vector>
#include <limits>

using namespace std;
class vinyl 
{
	protected:			//private:
		char artist[50];
		char name[40];
		char edition[40];
		char distributor[40];
		float price;
		char condition[5];
		int year;
		int month;
		int day;
	public:
		vinyl();
		vinyl(char* art, char* nam, char *edt, char *dist, float pr, char *cond, int yr, int mon, int d);
		void  setArtist(char *art);
		void  setName(char *nam);
		void  setEdition(char *edt);
		void  setDistributor(char *dist);
		bool  setPrice(float pr);
		void  setCondition(char *cond);
		int   setDate(int yr, int mon, int d);
		void  clear();
		void  download(char* art, char* nam, char *edt, char *dist, float pr, char *cond);
		char* getArtist();
		char* getName();
		char* getEdition();
		char* getDistributor();
		float getPrice();
		char* getCondition();
		int   getYear();
		int   getMonth();
		int   getDay();
};

class baseVinyl 
{
	protected:
		int quantity;
		int quantityFound;
		int quantityTrash;
		int current; //indeks elementu aktualnego, dziedzina: liczby
		int currentFound; //wartość -1 oznacza brak elementu aktualnego
		int currentTrash;
		vector <vinyl> tab;
		vector <vinyl> found;
		vector <int>   indexes;
		vector <vinyl> trash;
	private:
		int i; //bardziej uniwersalnym rozwiązaniem jest deklarowanie lokalnego 'i' w metodach
	public:
		baseVinyl();
		int    addNew(char* art, char* nam, char *edt, char *dist, float pr, char *cond, int yr, int mon, int d);
		void   clearAll();
		vinyl  getVinyl(int i);
		vinyl& getTab();
		int    getQuantity();
		float  sum();
		void   saveFile();
		void   readFile();
		void   setCurrent(int index);
		void   next(); //zamiast void lepiej bool lub w int w 4 metodach
		void   previous();
		int    getCurrent();
		void   deleteCurrent(int i);
		void   sortName();
		void   sortPrice();
		void   sortDate();
		int    searchPrice(float min, float max);	//lepszy bylby int - kod błędu
		bool   searchName(char searchedName[]);	//j.w.
		int    searchArtist(char searchedArtist[]);
		void   changeArtist(char oldArt[], char newArt[]);
		int    changePricePercent(float percent, float min, float max);
		int	   changePricePercentExact(float percent, float oldPrice);
		int    changePriceNumber(float newPrice, float min, float max);
		int    changePriceNumberExact(float newPrice, float oldPrice);
//Znalezione
		int	   getQuantityFound();
		int	   getCurrentFound();
		vinyl  getVinylFound(int i);
		vinyl  getFound();
		void   nextFound();
		void   previousFound();
		int    getIndex();	
		void   deleteCurrentFound(int i);
		void   deleteAllFound();
//Kosz
		int    getQuantityTrash();
		int    getCurrentTrash();
		vinyl  getVinylTrash(int i);
		vinyl  getTrash();
		void   nextTrash();
		void   previousTrash();
		void   deleteCurrentTrash();
		void   deleteAllTrash();
		void   addBackTrash(int i);
};


//NAGŁÓWKI NIEZALEŻNYCH FUNKCJI:

void gotoxy(int x, int y);
void writeVinylXY(vinyl t, int x, int y); //lepiej 2 metody (etykiety i wartosci - oddzielnie)
void baner();
void hideCursor(); 


//metody towar:
vinyl::vinyl() 
{
	strcpy(name," ");
	strcpy(artist," ");
	strcpy(name," ");
	strcpy(edition," ");
	strcpy(distributor," ");
	price=0;
	strcpy(condition," ");
	year=0;
	month=0;
	day=0;
}


vinyl::vinyl(char* art, char* nam, char *edt, char *dist, float pr, char *cond, int yr, int mon, int d) 
{
	strcpy(artist, art);
	strcpy(name,nam);
	strcpy(edition, edt);
	strcpy(distributor, dist);
	price=pr;
	strcpy(condition, cond);
	year=yr;
	month=mon;
	day=d;
}


void vinyl::clear() 
{
	strcpy(name," ");
	strcpy(artist," ");
	strcpy(name," ");
	strcpy(edition," ");
	strcpy(distributor," ");
	price=0;
	strcpy(condition," ");
	year=0;
	month=0;
	day=0;
}


void vinyl::setName(char *nam) 
{
	strcpy(name, nam);			//w wiekszosc klas nalezy zrobic komplet set'erów
}


void vinyl::setArtist(char *art) 
{
	strcpy(artist, art);
}


void vinyl::setEdition(char *edt) 
{
	strcpy(edition, edt);
}


void vinyl::setDistributor(char *dist) 
{
	strcpy(distributor, dist);
}


bool vinyl::setPrice(float pr) 
{
	if (pr>0) 
	{
		price=pr;
		return 1;
	}
	else
		return 0;
}


void vinyl::setCondition(char *cond) 
{
	strcpy(condition, cond);
}


int vinyl::setDate(int yr, int mon, int d)
{
	if (yr>=1930 && yr<=2024) 
		year=yr;
	else
	{
		year=0;
		month=0;
		day=0;
		return 0;
	}
	
	if(mon>=1 && mon<=12)
		month=mon;
	else
	{
		month=0;
		day=0;
		return 1;
	}	
	
	if(mon==1 || mon==3 || mon==5 || mon==7 || mon==8 || mon==10 || mon==12)
	{
		if (d>=1 && d<=31)
			day=d;
		else
		{
			day=0;
			return 2;
		}
	}
	else if(mon==2)
	{
		if((yr%4==0 && yr%100!=0)|| yr%400==0)
		{
			if(d>=1 && d<=29)
				day=d;
			else
			{
				day=0;
				return 3;
			}
		}
		else
		{
			if(d>=1 && d<=28)
			
				day=d;
			else
			{	
				day=0;
				return 4;
			}
		}
	}
	else
	{
		if (d>=1 && d<=30)
			day=d;
		else
		{
			day=0;
			return 5;
		}	
	}	
		
	return 6;
}


void vinyl::download(char* art, char* nam, char *edt, char *dist, float pr, char *cond) 
{
	strcpy(artist,art);
	strcpy(name,nam);
	strcpy(edition,edt);
	strcpy(distributor,dist);
	price=pr;
	strcpy(condition,cond);	
}


char* vinyl::getArtist() 
{
	return artist;
}


char* vinyl::getName() 
{
	return name;
}


char* vinyl::getEdition() 
{
	return edition;
}


char* vinyl::getDistributor() 
{
	return distributor;
}


float vinyl::getPrice() 
{
	return price;
}


char* vinyl::getCondition() 
{
	return condition;
}


int vinyl::getYear()
{
	return year;
}


int vinyl::getMonth()
{
	return month;
}


int vinyl::getDay()
{
	return day;
}


//metody bazatowar
baseVinyl::baseVinyl() 
{
	quantity=0;
	current=-1;
	quantityFound=0;
	currentFound=-1;
	quantityTrash=0;
	currentTrash=-1;
}

void baseVinyl::clearAll() 
{
	tab.erase( tab.begin(), tab.end() );
	quantity=0;
	current=-1;
}

int baseVinyl::addNew(char* art, char* nam, char *edt, char *dist, float pr, char *cond, int yr, int mon, int d) 
{
	vinyl v;
	int i;
	i=v.setDate(yr, mon, d);
	if(i!=6)
		return i;
	v.download(art, nam, edt, dist, pr, cond);
	tab.push_back(v);
	quantity++;
	current=quantity-1;
	return i; 
} 


float baseVinyl::sum() 
{
	float sum_all=0;
	for (i=0; i<quantity; i++) //rozmiar jak nie zadziala
		sum_all+=tab[i].getPrice();
	return sum_all;
}


int baseVinyl::getQuantity() 
{
	return quantity;
}


vinyl baseVinyl::getVinyl(int i) 
{
	return tab[i];
}


vinyl& baseVinyl::getTab() 
{
	return tab.at(current);
}


void baseVinyl::saveFile() 
{
	FILE *fp;		
	fp=fopen("vinyl.dat", "wb");
	quantity=tab.size();
	fwrite(&quantity, sizeof(quantity), 1, fp);
	for(i=0; i<tab.size(); i++)
		fwrite(&tab[i], sizeof(tab[i]), 1, fp); 
	fclose(fp);
}


void baseVinyl::readFile() 
{
	FILE *fp;
	tab.erase( tab.begin(), tab.end() );
	vinyl v;
	quantity=0;
	current=-1;
	fp=fopen("vinyl.dat", "rb");
	fread(&quantity, sizeof(quantity), 1, fp);
	for(i=0; i<quantity; i++)
	{
		fread(&v, sizeof(v), 1, fp); 
		tab.push_back(v);
	}
	fclose(fp);
	if (quantity>0)
		current = 0;
	else					//ustawianie biezacego elementu gdy go nie odczytuejmy z pliku
		current = -1;
}


void baseVinyl::setCurrent(int index) 
{
	if(index>=0 && index<quantity)
		current=index;
}


void baseVinyl::next() 
{
	if(current<quantity-1)
		current++;
}


void baseVinyl::previous() 
{
	if(current>0)
		current--;
}


int baseVinyl::getCurrent() 
{
	return current;
}

void baseVinyl::deleteCurrent(int i) 
{
	trash.push_back(tab[current]);
	quantityTrash++;
	if(currentTrash==-1)
		currentTrash=0;
	if(quantity>=1)
	{
		tab.erase(tab.begin() + current);
		if(current==quantity-1)
			current--;
		quantity--;
	}
}


void baseVinyl::sortPrice()
{
	vinyl pom;
	for(int nr=1; nr<quantity; nr++)
		for(int i=0; i<quantity-nr; i++)
			if(tab[i].getPrice()>tab[i+1].getPrice())
			{
				pom=tab[i];
				tab[i]=tab[i+1];
				tab[i+1]=pom;
			}
}


void baseVinyl::sortName()
{
	vinyl pom;
	for(int nr=1; nr<quantity; nr++)                 
  	{
	    for(int i=0; i<quantity-nr; i++)
	    {
	      if(strcmp(tab[i].getName(), tab[i+1].getName())>0)       
	      {
	        pom=tab[i];
	        tab[i]=tab[i+1];
	        tab[i+1]=pom;
	      }
	    }
  }	
}


 void baseVinyl::sortDate()
{
	vinyl pom;
	for(int nr=1; nr<quantity; nr++)
	{
		for(int i=0; i<quantity-nr; i++)
		{
			if(tab[i].getDay()>tab[i+1].getDay())
			{
				pom=tab[i];
				tab[i]=tab[i+1];
				tab[i+1]=pom;
			}
		}
	}
	
	for(int nr=1; nr<quantity; nr++)
	{
		for(int i=0; i<quantity-nr; i++)
		{
			if(tab[i].getMonth()>tab[i+1].getMonth())
			{
				pom=tab[i];
				tab[i]=tab[i+1];
				tab[i+1]=pom;
			}
		}
	}
	
	for(int nr=1; nr<quantity; nr++)
	{
		for(int i=0; i<quantity-nr; i++)
		{
			if(tab[i].getYear()>tab[i+1].getYear())
			{
				pom=tab[i];
				tab[i]=tab[i+1];
				tab[i+1]=pom;
			}
		}
	}		
}		


int baseVinyl::searchPrice(float min, float max)
{
	quantityFound=0;
	currentFound=-1;
	found.erase( found.begin(), found.end() );
	if(min<=0)
		return 2;
	else if(max>=2000000)
		return 3;
	else if(min>max)
		return 4;
	else if(max<min)
		return 5;
	else
	{
		for(int i=0; i<quantity; i++)
		{
			if(tab[i].getPrice()>=min && tab[i].getPrice()<=max)
			{
				found.push_back(tab[i]);
				indexes.push_back(i);
				quantityFound++;
			}
		}
		if (quantityFound>0)
		{
			currentFound=0;
			return 1;
		}
		else
			return 0;	
	}
}


bool baseVinyl::searchName(char searchedName[])
{
	quantityFound=0;
	currentFound=-1;
	found.erase( found.begin(), found.end() );
	for (int i=0; i<quantity; i++)
	{
		if ( strcmp( tab[i].getName(), searchedName )==0 )
		{
			found.push_back(tab[i]);
			indexes.push_back(i);
			quantityFound++;
		}
	}
	if (quantityFound>0)
	{
		currentFound=0;
		return 1;
	}
	else
		return 0;
}


int baseVinyl::searchArtist(char searchedArtist[])
{
	quantityFound=0;
	currentFound=-1;
	found.erase( found.begin(), found.end() );
	for (int i=0; i<quantity; i++)
	{
		if ( strcmp( tab[i].getArtist(), searchedArtist )==0 )
		{
			found.push_back(tab[i]);
			indexes.push_back(i);
			quantityFound++;
		}
	}
	if (quantityFound>0)
	{
		currentFound=0;
		return 1;
	}
	else
		return 0;
}

void baseVinyl::changeArtist(char oldArt[], char newArt[])
{
	for(int i=0; i<quantity; i++)
	{
		if ( strcmp( tab[i].getArtist(), oldArt )==0 )
			tab[i].setArtist(newArt);
	}
}


int baseVinyl::changePricePercent(float percent, float min, float max)
{
	int j;
	
	if(min<=0)
		return 1;
	else if(max>=2000000)
		return 2;
	else if(min>max)
		return 3;
	else if(percent<-100)
		return 4;
	else if(percent>200)
		return 5;
	for(int i=0; i<quantity; i++)
	{
		if(tab[i].getPrice()>=min && tab[i].getPrice()<=max)
		{
			tab[i].setPrice(tab[i].getPrice()+(tab[i].getPrice() * percent/100));
			j++;
		}
	}
	if(j==0)
		return 6;
	return 7;
}

int baseVinyl::changePricePercentExact(float percent, float oldPrice)
{
	int j;
	
	for(int i=0; i<quantity; i++)
	{
		if(tab[i].getPrice()==oldPrice)
		{
			tab[i].setPrice(tab[i].getPrice()+(tab[i].getPrice() * percent/100));
			j++;
		}
	}
	if(j==0)
		return 0;
	return 1;
	
}
		
	
int baseVinyl::changePriceNumber(float newPrice, float min, float max)
{
	int j;
	
	if(min<=0)
		return 1;
	else if(max>=2000000)
		return 2;
	else if(min>max)
		return 3;
	else if(newPrice<0)
		return 4;
	else if(newPrice>2000000)
		return 5;
	for(int i=0; i<quantity; i++)
	{
		if(tab[i].getPrice()>=min && tab[i].getPrice()<=max)
		{
			tab[i].setPrice(newPrice);
			j++;
		}
	}
	if(j==0)
		return 6;
	return 7;
}


int baseVinyl::changePriceNumberExact(float newPrice, float oldPrice)
{	
	int j;
	for(int i=0; i<quantity; i++)
	{
		if(tab[i].getPrice()==oldPrice)
		{
			tab[i].setPrice(newPrice);
			j++;
		}
	}
	if(j==0)
		return 0;
	return 1;	
}



vinyl baseVinyl::getVinylFound(int i)
{
	return found[i];
}


vinyl baseVinyl::getFound()
{
	return found.at(currentFound);
}


int baseVinyl::getCurrentFound()
{
	return currentFound;
}


int baseVinyl::getQuantityFound()
{
	return quantityFound;
}


void baseVinyl::nextFound()
{
	if(currentFound<quantityFound-1)
		currentFound++;
}


void baseVinyl::previousFound()
{
	if(currentFound>0)
		currentFound--;
}


void baseVinyl::deleteCurrentFound(int i)
{
	trash.push_back(found[currentFound]);
	quantityTrash++;
	if(currentTrash==-1)
		currentTrash=0;
	tab.erase(tab.begin() + indexes[currentFound]);
	indexes.erase(indexes.begin() + currentFound);
	if(current==quantity-1)
		current--;
	quantity--;
	if(quantityFound>=1)
	{
		found.erase(found.begin() + currentFound);
		if(currentFound==quantityFound-1)
			currentFound--;
		quantityFound--;
	}
	int q=quantityFound;
	if(currentFound<quantityFound-1)
	{
		for(i=0;i<q;i++)
		{
			indexes[i]=indexes[i]-1;
		}
	}
}

void baseVinyl::deleteAllFound()
{
	currentFound=quantityFound-1;
	int q=quantityFound;	
	for(i=q; i>0; i--)
	{
		trash.push_back(found[currentFound]);
		quantityTrash++;
		if(currentTrash==-1)
			currentTrash=0;
		tab.erase(tab.begin() + indexes[currentFound]);
		indexes.erase(indexes.begin() + currentFound);
		if(current==quantity-1)
			current--;
		quantity--;
		found.erase(found.begin() + currentFound);
		if(currentFound==quantityFound-1)
			currentFound--;
		quantityFound--;
	}
}


int baseVinyl::getQuantityTrash()
{
	return quantityTrash;
}


int baseVinyl::getCurrentTrash()
{
	return currentTrash;
}


vinyl baseVinyl::getVinylTrash(int i)
{
	return trash[i];	
}


vinyl baseVinyl::getTrash()
{
	return trash.at(currentFound);
}


void baseVinyl::nextTrash()
{
	if(currentTrash<quantityTrash-1)
		currentTrash++;
}


void baseVinyl::previousTrash()
{
	if(currentTrash>0)
		currentTrash--;
}


void baseVinyl::deleteCurrentTrash()
{
	trash.erase(trash.begin() + currentTrash);
	if(currentTrash==quantityTrash-1)
		currentTrash--;
	quantityTrash--;
}
		

void baseVinyl::deleteAllTrash()
{
	currentTrash=quantityTrash-1;
	int q=quantityTrash;	
	for(i=q; i>0; i--)
	{
		trash.erase(trash.begin() + currentTrash);
		currentTrash--;
		quantityTrash--;
	}
										

}
void baseVinyl::addBackTrash(int i)
{
	tab.push_back(trash[i]);
	quantity++;
	if(current==-1)
		current=0;
	trash.erase(trash.begin() + currentTrash);
	if(currentTrash==quantityTrash-1)
		currentTrash--;
	quantityTrash--;
}


void gotoxy(int x, int y) 
{
	COORD c;
	c.X = x-1;
	c.Y = y-1;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}


void hideCursor() 
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo); // Get current cursor settings
    cursorInfo.bVisible = FALSE;                     // Set cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo); // Apply the changes
}

void writeVinylXY(vinyl t, int x, int y) 
{
	gotoxy(x, y);
	cout<<"\033[32m------------------------------------------------------------------------------";
	gotoxy(x, y+1);
	cout<<"|\033[0mArtist:";
	gotoxy(x+77, y+1);
	cout<<"\033[32m|";
	gotoxy(x, y+2);
	cout<<"|\033[0mName:";
	gotoxy(x+77, y+2);
	cout<<"\033[32m|";
	gotoxy(x, y+3);
	cout<<"|\033[0mEdition:";
	gotoxy(x+77, y+3);
	cout<<"\033[32m|";
	gotoxy(x, y+4);
	cout<<"|\033[0mDistributor:";
	gotoxy(x+77, y+4);
	cout<<"\033[32m|";
	gotoxy(x, y+5);
	cout<<"|\033[0mPrice:";
	gotoxy(x+77, y+5);
	cout<<"\033[32m|";
	gotoxy(x, y+6);
	cout<<"|\033[0mCondition:";
	gotoxy(x+77, y+6);
	cout<<"\033[32m|";
	gotoxy(x, y+7);
	cout<<"|\033[0mData wydania:";
	gotoxy(x+77, y+7);
	cout<<"\033[32m|";
	gotoxy(x, y+8);
	cout<<"------------------------------------------------------------------------------\033[0m";
	gotoxy(x+25, y+1);
	cout<<t.getArtist();
	gotoxy(x+25, y+2);
	cout<<t.getName();
	gotoxy(x+25, y+3);
	cout<<t.getEdition();
	gotoxy(x+25, y+4);
	cout<<t.getDistributor();
	gotoxy(x+25, y+5);
	cout<<t.getPrice()<<" euro";
	gotoxy(x+25, y+6);
	cout<<t.getCondition();
	gotoxy(x+25, y+7);
	cout<<t.getDay()<<"."<<t.getMonth()<<"."<<t.getYear()<<endl;
}

void baner()
{
	cout<<"\033[35m       __      __  _                   _ ";  
	cout<<"             _____         _   _                 _     _"<<endl;
    cout<<"       \\ \\    / / (_)                 | |";
	cout<<"            / ____|       | | | |               | |   (_)"<<endl;
    cout<<"        \\ \\  / /   _   _ __    _   _  | |";
    cout<<"           | |       ___  | | | |    _     ___  | |_   _    ___    _ __"<<endl;
    cout<<"         \\ \\/ /   | | | '_ \\  | | | | | |";
	cout<<"           | |      / _ \\ | | | |  / _ \\  / __/ | __| | |  / _ \\  | '_ \\ "<<endl;
    cout<<"          \\  /    | | | | | | | |_| | | |";
	cout<<"           | |____ | (_) || | | | |  __/ / (__  | |_  | | | (_) | | | | |"<<endl;
    cout<<"           \\/     |_| |_| |_|  \\__, | |_|";
	cout<<"            \\_____| \\___/ |_| |_|  \\___|  \\___\\  \\__| |_|  \\___/  |_| |_|"<<endl;
    cout<<"                                __/ |"<<endl;
    cout<<"                               |___/\033[0m"<<endl;	
}



main() 
{
	hideCursor();
	char art[50], nam[40], edt[40], dist[40], cond[10], oldart[50], zn, search[50];
	float pr, percent, oldpr;
	bool check;
	int i, j, yr, mon, d, min, max;
	baseVinyl base;

	do 
	{
		system("CLS");
		baner();
		gotoxy(48, 10);
		cout<<"1. Clear all"<<endl;
		gotoxy(48, 11);
		cout<<"2. Add new"<<endl;
		gotoxy(48, 12);
		cout<<"3. Records list"<<endl;
		gotoxy(48, 13);
		cout<<"4. Sum of all"<<endl;
		gotoxy(48, 14);
		cout<<"5. Save to File"<<endl;
		gotoxy(48, 15);
		cout<<"6. Read to File"<<endl;
		gotoxy(48, 16);
		cout<<"a. Browse through the records."<<endl;
		gotoxy(48, 17);
		cout<<"b. Set Current"<<endl;
		gotoxy(48, 18);
		cout<<"c. Sorting"<<endl;
		gotoxy(48, 19);
		cout<<"d. Searching"<<endl;
		gotoxy(48, 20);
		cout<<"e. Browse through found records."<<endl;
		gotoxy(48, 21);
		cout<<"g. Search and change."<<endl;
		gotoxy(48, 22);
		cout<<"p. Trashbin"<<endl;
		gotoxy(48, 23);
		cout<<"f. Finish"<<endl;

		zn=getch();

		system("cls");

		switch(zn) 
		{
			case '1':
				gotoxy(25, 15);
				cout<<"Are you sure you want to clear the whole table and lose everything?"<<endl;
				gotoxy(45, 16);
				cout<<"y - yes           n - no"<<endl;
				zn=getch();
				switch(zn)
				{
					case 'y':
						base.clearAll();
						break;
					case 'n':
						break;
				}
				break;
			
			case '2':
				fflush(stdin);
				gotoxy(48, 10);
				cout<<"Artist: ";
				gets(art);
				gotoxy(48, 11);
				cout<<"Name: ";
				gets(nam);
				gotoxy(48, 12);
				cout<<"Edition: ";
				gets(edt);
				gotoxy(48, 13);
				cout<<"Distributor: ";
				gets(dist);
				do
				{
					gotoxy(48, 14);
					cout<<"Price: ";
					cin>>pr;
					if(cin.fail())
					{
						cin.clear();
						gotoxy(48, 15);
						cout<<"Invalid. You can only input a number."<<endl;
						check=false;
						cin.ignore();
						fflush(stdin);
						gotoxy(48, 14);
						cout<<"                        ";         
					}
					else
					{
						check=true;
						gotoxy(48, 15);
						cout<<"                                      "<<endl;
					}
						fflush(stdin);
				}while(check==false);
				gotoxy(48, 15);
				cout<<"Condition: ";
				gets(cond);
				do
				{
					gotoxy(48, 16);
					cout<<"Date(dd-mm-yyyy): "<<endl;
					gotoxy(48, 17);
					cout<<"            ";
					gotoxy(48, 18);
					cout<<"               ";
					gotoxy(48, 19);
					cout<<"              ";
					gotoxy(48, 17);
					cout<<"Day: ";
					cin>>d;
					cin.ignore();
					gotoxy(48, 18);
					cout<<"Month: ";
					cin>>mon;
					cin.ignore();
					gotoxy(48, 19);
					cout<<"Year: ";
					cin>>yr;
					cin.ignore();
					i=base.addNew(art, nam, edt, dist, pr, cond, yr, mon, d);
					if(i==0)
					{
						gotoxy(48, 20);
						cout<<"Incorrect year. Try again.";
					}
					if(i==1)
					{
						gotoxy(48, 20);
						cout<<"Incorrect month. Try again.";
					}
					if(i==2)
					{
						gotoxy(48, 20);
						cout<<"Incorrect day (only between 1-31). Try again.";
					}
					if(i==3)
					{
						gotoxy(48, 20);
						cout<<"Incorrect day (only between 1-29). Try again.";
					}
					if(i==4)
					{
						gotoxy(48, 20);
						cout<<"Incorrect day (only between 1-28). Try again.";
					}
					if(i==5)
					{
						gotoxy(48, 20);
						cout<<"Incorrect day (only between 1-30). Try again.";
					}
				}while(i!=6);
				gotoxy(48, 20);
				cout<<"                                              ";
				gotoxy(48, 20);
				cout<<"Added! Click ENTER to proceed.";
				getchar();
				break;
				
			case '3':
				cout<<"                                  Collection"<<endl;
				cout<<"------------------------------------------------------------------------------"<<endl<<endl;
				for(i=0; i<base.getQuantity(); i++) 
				{
					cout<<"|Artist: \033[35m"<<base.getVinyl(i).getArtist()<<"\033[0m"<<endl;
					cout<<"|Name: \033[35m"<<base.getVinyl(i).getName()<<"\033[0m"<<endl;
					cout<<"|Edition: \033[35m"<<base.getVinyl(i).getEdition()<<"\033[0m"<<endl;
					cout<<"|Distributor: \033[35m"<<base.getVinyl(i).getDistributor()<<"\033[0m"<<endl;
					cout<<"|Price: \033[35m"<<base.getVinyl(i).getPrice()<<" EURO\033[0m"<<endl;
					cout<<"|Condition: \033[35m"<<base.getVinyl(i).getCondition()<<"\033[0m"<<endl;
					cout<<"|Date: \033[35m"<<base.getVinyl(i).getDay()<<"."<<base.getVinyl(i).getMonth()<<"."<<base.getVinyl(i).getYear()<<"\033[0m"<<endl<<endl;
				}
				cout<<"------------------------------------------------------------------------------"<<endl;
				cout<<"Click ENTER to proceed.";
				getchar();
				break;
				
			case '4':
				gotoxy(48, 15);
				cout<<"Sum of all: "<<base.sum()<<endl;
				gotoxy(48, 16);
				cout<<"Click ENTER to proceed.";
				getchar();
				break;
				
			case '5':
				gotoxy(36, 15);
				cout<<"Are you sure you want to upwrite the file?";
				gotoxy(45, 16);
				cout<<"y - yes           n - no"<<endl;
				zn=getch();
				switch(zn)
				{
					case 'y':
						base.saveFile();
						gotoxy(36, 17);
						cout<<"Saved. Click ENTER to proceed.";
						getchar();
						break;
					case 'n':
						break;
				}
				break;
				
			case '6':
				gotoxy(36, 15);
				cout<<"Are you sure you want to lose your work and open a file?";
				gotoxy(45, 16);
				cout<<"y - yes           n - no"<<endl;
				zn=getch();
				switch(zn)
				{
					case 'y':
						base.readFile();
						gotoxy(36, 17);
						cout<<"Opened. Click ENTER to proceed.";
						getchar();
						break;
					case 'n':
						break;
				}
				break;
				
			case 'a':
				i=base.getCurrent();
				if (i==-1)
				{
					cout<<"No elements. Click ENTER to proceed."<<endl;
					getchar();
				}
				else
				{
					do
					{
						system("cls");
						if (base.getCurrent()==-1)
						{
							cout<<"No elements. Click ENTER to proceed."<<endl;
							getchar();
							break;
						}
						writeVinylXY(base.getVinyl(i), 25, 10);
						gotoxy(25, 19);
						cout<<"    a - previous   b - next   c - change index    d - delete    l - leave";
						zn=getch();
						switch(zn)
						{
							case 'a':
								base.previous();
								i=base.getCurrent();
								break;
							case 'b':
								base.next();
								i=base.getCurrent();
								break;	
							case 'c':
								system("cls");
								gotoxy(26, 15);
								cout<<"Do you want to change the whole index or one of the categories?"<<endl;
								gotoxy(10, 16);
								cout<<"1 - all  2 - artist 3 - name 4 - edition  5 - distributor  6 - price  7 - condition  8 - date  9 - leave";
								zn=getch();
								system("cls");
								switch(zn)
								{
									case '1':
										gotoxy(48, 10);
										cout<<"Artist: ";
										gets(art);
										base.getTab().setArtist(art);
										gotoxy(48, 11);
										cout<<"Name: ";
										gets(nam);
										base.getTab().setName(nam);
										gotoxy(48, 12);
										cout<<"Edition: ";
										gets(edt);
										base.getTab().setEdition(edt);
										gotoxy(48, 13);
										cout<<"Distributor: ";
										gets(dist);
										base.getTab().setDistributor(dist);
										do
										{
											gotoxy(48, 14);
											cout<<"Price: ";
											cin>>pr;
											if(cin.fail())
											{
												cin.clear();
												gotoxy(48, 15);
												cout<<"Invalid. You can only input a number."<<endl;
												check=false;
												cin.ignore();
												fflush(stdin);
												gotoxy(48, 14);
												cout<<"                        ";         
											}
											else
											{
												check=true;
												gotoxy(48, 15);
												cout<<"                                      "<<endl;
												base.getTab().setPrice(pr);
											}
												fflush(stdin);
										}while(check==false);
										gotoxy(48, 15);
										cout<<"Condition: ";
										gets(cond);
										base.getTab().setCondition(cond);
										do
										{
											gotoxy(48, 16);
											cout<<"Date(dd-mm-yyyy): "<<endl;
											gotoxy(48, 17);
											cout<<"            ";
											gotoxy(48, 18);
											cout<<"               ";
											gotoxy(48, 19);
											cout<<"              ";
											gotoxy(48, 17);
											cout<<"Day: ";
											cin>>d;
											cin.ignore();
											gotoxy(48, 18);
											cout<<"Month: ";
											cin>>mon;
											cin.ignore();
											gotoxy(48, 19);
											cout<<"Year: ";
											cin>>yr;
											cin.ignore();
											i=base.getTab().setDate(yr, mon, d);
											if(i==0)
											{
												gotoxy(48, 20);
												cout<<"Incorrect year. Try again.";
											}
											if(i==1)
											{
												gotoxy(48, 20);
												cout<<"Incorrect month. Try again.";
											}
											if(i==2)
											{
												gotoxy(48, 20);
												cout<<"Incorrect day (only between 1-31). Try again.";
											}
											if(i==3)
											{
												gotoxy(48, 20);
												cout<<"Incorrect day (only between 1-29). Try again.";
											}
											if(i==4)
											{
												gotoxy(48, 20);
												cout<<"Incorrect day (only between 1-28). Try again.";
											}
											if(i==5)
											{
												gotoxy(48, 20);
												cout<<"Incorrect day (only between 1-30). Try again.";
											}
										}while(i!=6);
										gotoxy(48, 20);
										cout<<"                                              ";
										gotoxy(48, 20);
										cout<<"Added! Click ENTER to proceed.";
										getchar();
										break;
									case '2':
										gotoxy(48, 15);
										cout<<"Artist: ";
										gets(art);
										base.getTab().setArtist(art);
										gotoxy(48, 16);
										cout<<"Changed! Press ENTER to continue";
										getchar();
										break;
									case '3':
										gotoxy(48, 15);
										cout<<"Name: ";
										gets(nam);
										base.getTab().setName(nam);
										gotoxy(48, 16);
										cout<<"Changed! Press ENTER to continue";
										getchar();
										break;
									case '4':
										gotoxy(48, 15);
										cout<<"Edition: ";
										gets(edt);
										base.getTab().setEdition(edt);
										gotoxy(48, 16);
										cout<<"Changed! Press ENTER to continue";
										getchar();
										break;
									case '5':
										gotoxy(48, 15);
										cout<<"Distributor: ";
										gets(dist);
										base.getTab().setDistributor(dist);
										gotoxy(48, 16);
										cout<<"Changed! Press ENTER to continue";
										getchar();
										break;
									case '6':
										gotoxy(48, 15);
										cout<<"Price: ";
										cin>>pr;
										base.getTab().setPrice(pr);
										gotoxy(48, 16);
										cout<<"Changed! Press ENTER to continue";
										getchar();
										break;
									case '7':
										gotoxy(48, 15);
										cout<<"Condition: ";
										gets(cond);
										base.getTab().setCondition(cond);
										gotoxy(48, 16);
										cout<<"Changed! Press ENTER to continue";
										getchar();
										break;
									case '8':
										do
										{
											gotoxy(48, 15);
											cout<<"Date(dd-mm-yyyy): "<<endl;
											gotoxy(48, 16);
											cout<<"            ";
											gotoxy(48, 17);
											cout<<"               ";
											gotoxy(48, 18);
											cout<<"              ";
											gotoxy(48, 16);
											cout<<"Day: ";
											cin>>d;
											cin.ignore();
											gotoxy(48, 17);
											cout<<"Month: ";
											cin>>mon;
											cin.ignore();
											gotoxy(48, 18);
											cout<<"Year: ";
											cin>>yr;
											cin.ignore();
											i=base.getTab().setDate(yr, mon, d);
											if(i==0)
											{
												gotoxy(48, 19);
												cout<<"Incorrect year. Try again.";
											}
											if(i==1)
											{
												gotoxy(48, 19);
												cout<<"Incorrect month. Try again.";
											}
											if(i==2)
											{
												gotoxy(48, 19);
												cout<<"Incorrect day (only between 1-31). Try again.";
											}
											if(i==3)
											{
												gotoxy(48, 19);
												cout<<"Incorrect day (only between 1-29). Try again.";
											}
											if(i==4)
											{
												gotoxy(48, 19);
												cout<<"Incorrect day (only between 1-28). Try again.";
											}
											if(i==5)
											{
												gotoxy(48, 19);
												cout<<"Incorrect day (only between 1-30). Try again.";
											}
										}while(i!=6);
										gotoxy(48, 19);
										cout<<"                                              ";
										gotoxy(48, 19);
										cout<<"Added! Click ENTER to proceed.";
										getchar();
										break;
									case '9':
										break;
								}
								break;
							case 'd':
								gotoxy(35, 21);
								cout<<"Are you sure you want to delete current index?";
								gotoxy(45, 22);
								cout<<"y - yes           n - no"<<endl;
								zn=getch();
								switch(zn)
								{
									case 'y':
										gotoxy(35, 21);
										cout<<"                                                   ";
										gotoxy(45, 22);
										cout<<"                         ";
										i=base.getCurrent();
										base.deleteCurrent(i);
										gotoxy(44, 21);
										cout<<"Deleted. Click ENTER to continue.";
										i=base.getCurrent();
										getchar();
										break;
									case 'n':
										break;
								}
								break;
						}
					}while(zn!='l');
				}
				break;
				
			case 'b':
				cout<<"Index of the element: ";
				cin>>i;
				base.setCurrent(i);
				if (i==-1)
				{
					cout<<"No elements. Click ENTER to proceed."<<endl;
					getchar();
					getchar();
				}
				else if(i>=base.getQuantity() )
				{
					cout<<"Index is too high! Click ENTER and try again."<<endl;
					getchar();
					getchar();
				}
				else
				{
					writeVinylXY(base.getVinyl(i), 5, 10);
					cout<<endl<<"Click ENTER to leave.";
					getchar();
					getchar();
				}
				break;
				
			case 'f':
				gotoxy(30, 15);
				cout<<"Are you sure you want to leave? (Remember to save your work!)."<<endl<<endl;
				gotoxy(40, 16);
				cout<<"n - NO			ESC - leave";
				zn=getch();
				switch(zn)
				{
					case 27:
						system("cls");
						gotoxy(55, 15);
						cout<<"Period.";
						getchar();
						break;
					case 'n':
						break;
				}
				break;
				
			case 'c': 
				system("cls");
				gotoxy(45, 12);
				cout<<"By which category you want to sort?"<<endl;
				gotoxy(45, 13);
				cout<<"1 - Sort by name"<<endl;
				gotoxy(45, 14);
				cout<<"2 - Sort by price"<<endl;
				gotoxy(45, 15);
				cout<<"3 - Sort by date"<<endl;
				gotoxy(45, 16);
				cout<<"l - leave"<<endl;
				zn=getch();
				switch(zn)
				{
					case '1':
						system("cls");
						base.sortPrice();
						gotoxy(45, 15);
						cout<<"Sorted. Click ENTER to proceed.";
						getchar();
						break;
					case '2':
						system("cls");
						base.sortName();
						gotoxy(45, 15);
						cout<<"Sorted. Click ENTER to proceed.";
						getchar();
						break;
					case '3':
						system("cls");
						base.sortDate();
						gotoxy(45, 15);
						cout<<"Sorted. Click ENTER to proceed.";
						getchar();
						break;
					case 'l':
						break;
				}
				break;	
					
			case 'd': 
				system("cls");
				gotoxy(45, 12);
				cout<<"What do you want to search for?";
				gotoxy(45, 13);
				cout<<"1 - Search for an artist";
				gotoxy(45, 14);
				cout<<"2 - Search for a name";
				gotoxy(45, 15);
				cout<<"3 - Search for a price range";
				gotoxy(45, 16);
				cout<<"l - leave";
				zn=getch();
				switch(zn)
				{
					case '1':
						system("cls");
						gotoxy(50, 15);
						cout<<"Artist: ";
						fflush(stdin);
						gets(search);
						i=base.searchArtist(search);
						if(i==0)
						{
							gotoxy(50, 16);
							cout<<"Not found.";
						}
						else
						{
							gotoxy(45, 16);
							cout<<"Found. Click ENTER to proceed.";
						}
						getchar();
						break;
					case '2':
						system("cls");
						gotoxy(50, 15);
						cout<<"Name: ";
						fflush(stdin);
						gets(search);
						i=base.searchName(search);
						if(i==0)
						{
							gotoxy(50, 16);
							cout<<"Not found.";
						}
						else
						{
							gotoxy(45, 16);
							cout<<"Found. Click ENTER to proceed.";
						}
						getchar();
						break;
					case '3':
						system("cls");
						gotoxy(50, 15);
						cout<<"Min: ";
						cin>>min;
						gotoxy(50, 16);
						cout<<"Max: ";
						cin>>max;
						i=base.searchPrice(min,max);
						if(i==1)
						{
							gotoxy(50, 17);
							cout<<"Found. Click ENTER to proceed.";
							getchar();
						}
						else if(i==2)
						{
							gotoxy(50, 17);
							cout<<"Minimum too low! Click ENTER to proceed and try again.";
							getchar();
						}
						else if(i==3)
						{
							gotoxy(50, 17);
							cout<<"Maximum too high! Click ENTER to proceed and try again.";
							getchar();
						}
						else if(i==4)
						{
							gotoxy(50, 17);
							cout<<"Maximum is lower than minimum! Click ENTER to proceed and try again.";
							getchar();
						}	
						else
						{
							gotoxy(50, 17);
							cout<<"Nothing found. Click ENTER to proceed.";
							getchar();
						}
						getchar();
						break;
					case 'l':
						break;
				}
				break;	
				
			case 'e':	
			i=base.getCurrentFound();
				if (i==-1)
				{
					gotoxy(43, 15);
					cout<<"No elements. Click ENTER to proceed."<<endl;
					getchar();
				}
				else
				{
					do
					{
						system("cls");
						if(base.getCurrentFound()==-1)
						{
							gotoxy(43, 15);
							cout<<"No elements. Click ENTER to leave.";
							getch();
							break;
						}
						writeVinylXY(base.getVinylFound(i), 20, 10);
						gotoxy(12, 19);
						cout<<"    a - previous     b - next       d - delete index      t - delete all indexes    l - leave"<<endl;
						zn=getch();
						switch(zn)
						{
							case 'a':
								base.previousFound();
								i=base.getCurrentFound();
								break;
							case 'b':
								base.nextFound();
								i=base.getCurrentFound();
								break;	
							case 'd':
								gotoxy(35, 21);
								cout<<"Are you sure you want to delete current index?";
								gotoxy(45, 22);
								cout<<"y - yes           n - no";
								zn=getch();
								switch(zn)
								{
									case 'y':
										gotoxy(35, 21);
										cout<<"                                                   ";
										gotoxy(45, 22);
										cout<<"                         ";
										base.deleteCurrentFound(i);
										gotoxy(45, 21);
										cout<<"Deleted. Click ENTER to continue.";
										i=base.getCurrentFound();
										getchar();
										break;
									case 'n':
										break;
								}
								break;
							case 't':
								gotoxy(35, 21);
								cout<<"Are you sure you want to delete all found data?";
								gotoxy(45, 22);
								cout<<"y - yes           n - no";
								zn=getch();
								switch(zn)
								{
									case 'y':
										
										base.deleteAllFound();
										gotoxy(35, 21);
										cout<<"                                                   ";
										gotoxy(45, 22);
										cout<<"                         ";
										gotoxy(45, 21);
										cout<<"Deleted. Click ENTER to proceed.";
										getchar();
										break;
									case 'n':
										break;
								}
								break;
						}
					}while(zn!='l');
				}
				break;
			
			case 'g':
			system("cls");
			gotoxy(45, 12);
			cout<<"What do you want to change?"<<endl;
			gotoxy(45, 13);
			cout<<"1 - Artist";
			gotoxy(45, 14);
			cout<<"2 - Price by percent (price range)";
			gotoxy(45, 15);
			cout<<"3 - Price by percent (exact price)";
			gotoxy(45, 16);
			cout<<"4 - Price by number (price range)";
			gotoxy(45, 17);
			cout<<"5 - Price by number (exact price)";
			zn=getch();
			switch(zn)
			{
				case '1':
					system("cls");
					gotoxy(45, 15);
					cout<<"Enter old artist: ";
					gets(oldart);
					gotoxy(45, 16);
					cout<<"Enter new artist: ";
					gets(art);
					base.changeArtist(oldart, art);
					gotoxy(45, 17);
					cout<<"Changed. Click ENTER to proceed.";
					getchar();
					break;
				case '2':
					system("cls");
					gotoxy(45, 15);
					cout<<"Enter price range you seek for:";
					gotoxy(45, 16);
					cout<<"Minimum: ";
					cin>>min;
					gotoxy(45, 17);
					cout<<"Maximum: ";
					cin>>max;
					gotoxy(45, 18);
					cout<<"Enter percent ('-' will be treated as a discount): ";		
					cin>>percent;
					i=base.changePricePercent(percent, min, max);
					if(i==1)
					{
						gotoxy(45, 19);
						cout<<"Minimum too low! Click ENTER to proceed and try again.";
						getchar();
					}
					else if(i==2)
					{
						gotoxy(45, 19);
						cout<<"Maximum too high! Click ENTER to proceed and try again.";
						getchar();
					}
					else if(i==3)
					{
						gotoxy(45, 19);
						cout<<"Maximum is lower than minimum! Click ENTER to proceed and try again.";
						getchar();
					}
					else if(i==4)
					{
						gotoxy(45, 19);
						cout<<"Percent too small. Can't be below -100. Click ENTER to proceed and try again.";
						getchar();
					}
					else if(i==5)
					{
						gotoxy(45, 19);
						cout<<"Percent too high. Can't be above 200. Click ENTER to proceed and try again.";
						getchar();
					}
					else if(i==6)
					{
						gotoxy(45, 19);
						cout<<"None found. Click ENTER to proceed.";
						getchar(); 
					}	
					else
					{
						gotoxy(45, 19);
						cout<<"Changed. Click ENTER to proceed.";
						getchar();
					}
					getchar();
					break;
				case '3':
					system("cls");
					gotoxy(45, 15);
					cout<<"Enter the price you seek for:";
					cin>>oldpr;
					gotoxy(45,16);
					cout<<"Enter percent ('-' will be treated as a discount): ";		
					cin>>percent;
					i=base.changePricePercentExact(percent, oldpr);
					if(i==1)
					{
						gotoxy(45,17);
						cout<<"Changed. Click ENTER to proceed.";
						getchar();
					}
					else
					{
						gotoxy(45,17);
						cout<<"None found. Click ENTER to proceed.";
						getchar();
					}
					getchar();
					break;
				case '4':
					system("cls");
					gotoxy(45, 15);
					cout<<"Enter price range you seek for:";
					gotoxy(45, 16);
					cout<<"Minimum: ";
					cin>>min;
					gotoxy(45, 17);
					cout<<"Maximum: ";
					cin>>max;
					gotoxy(45, 18);
					cout<<"Enter new price: ";
					cin>>pr;
					i=base.changePriceNumber(pr, min, max);
					if(i==1)
					{
						gotoxy(45, 19);
						cout<<"Minimum too low! Click ENTER to proceed and try again.";
						getchar();
					}
					else if(i==2)
					{
						gotoxy(45, 19);
						cout<<"Maximum too high! Click ENTER to proceed and try again.";
						getchar();
					}
					else if(i==3)
					{
						gotoxy(45, 19);
						cout<<"Maximum is lower than minimum! Click ENTER to proceed and try again.";
						getchar();
					}
					else if(i==4)
					{
						gotoxy(45, 19);
						cout<<"Price can't be below 0. Click ENTER to proceed and try again.";
						getchar(); 
					}
					else if (i==5)
					{
						gotoxy(45, 19);
						cout<<"Price can't be more than 2000000. Click ENTER to proceed and try again.";
						getchar(); 
					}
					else if(i==6)
					{
						gotoxy(45, 19);
						cout<<"None found. Click ENTER to proceed.";
						getchar(); 
					}
					else
					{
						gotoxy(45, 19);
						cout<<"Changed. Click ENTER to proceed.";
						getchar();
					}
					getchar();
					break;
				case '5':
					system("cls");
					gotoxy(45, 15);
					cout<<"Enter the price you seek for:";
					cin>>oldpr;
					gotoxy(45, 16);
					cout<<"Enter new price: ";
					cin>>pr;
					i=base.changePriceNumberExact(pr, oldpr);
					if(i==1)
					{
						gotoxy(45,17);
						cout<<"Changed. Click ENTER to proceed.";
						getchar();
					}
					else
					{
						gotoxy(45,17);
						cout<<"None found. Click ENTER to proceed.";
						getchar();
					}
					getchar();
					break;	
			}
			break;
			
			case 'p':
			i=base.getCurrentTrash();
			if (i==-1)
			{
				gotoxy(43, 15);
				cout<<"No elements. Click ENTER to proceed."<<endl;
				getchar();
			}
			else
			{
				do
				{
					system("cls");
					if(base.getCurrentTrash()==-1)
					{
						gotoxy(43, 15);
						cout<<"No elements. Click ENTER to leave.";
						getch();
						break;
					}
					writeVinylXY(base.getVinylTrash(i), 20, 10);
					gotoxy(5, 19);
					cout<<"    a - previous          b - next        d - delete index      t - delete all indexes   j - add back   l - leave";
					zn=getch();
					switch(zn)
					{
						case 'a':
							base.previousTrash();
							i=base.getCurrentTrash();
							break;
						case 'b':
							base.nextTrash();
							i=base.getCurrentTrash();
							break;	
						case 'd':
							gotoxy(35, 21);
							cout<<"Are you sure you want to delete current index?";
							gotoxy(45, 22);
							cout<<"y - yes           n - no";
							zn=getch();
							switch(zn)
							{
								case 'y':
									gotoxy(35, 21);
									cout<<"                                                   ";
									gotoxy(45, 22);
									cout<<"                         ";
									gotoxy(54, 21);
									base.deleteCurrentTrash();
									cout<<"Deleted. Click ENTER to proceed.";
									i=base.getCurrentTrash();
									getchar();
									break;
								case 'n':
									break;
							}
							break;
						case 't':
							gotoxy(35, 21);
							cout<<"Are you sure you want to delete all found data?";
							gotoxy(45, 22);
							cout<<"y - yes           n - no";
							zn=getch();
							switch(zn)
							{
								case 'y':	
									gotoxy(35, 21);
									cout<<"                                                   ";
									gotoxy(45, 22);
									cout<<"                         ";
									gotoxy(44, 21);																
									base.deleteAllTrash();
									cout<<"Deleted. Click ENTER to proceed.";
									getchar();
									break;
								case 'n':
									break;
							}
							break;
						case 'j':
							base.addBackTrash(i);
							gotoxy(44, 21);
							cout<<"Added back. Click ENTER to proceed.";
							getchar();
							break;
					}
				}while(zn!='l');
			}
			break;	
		}
		
	} while(zn!=27);
}
