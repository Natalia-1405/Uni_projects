#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <vector>

using namespace std;
class vinyl 
{
	protected:			//private:
		char artist[50];
		char name[20];
		char edition[30];
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
		bool  setDate(int yr, int mon, int d);
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
		float worth();
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
		void   addNew(char* art, char* nam, char *edt, char *dist, float pr, char *cond, int yr, int mon, int d);
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
//Znalezione
		int	   getQuantityFound();
		int	   getCurrentFound();
		vinyl  getVinylFound(int i);
		vinyl  getFound();
		void   nextFound();
		void   previousFound();
		int    getIndex();	
		void   deleteCurrentFound();
//Kosz
		int    getQuantityTrash();
		int    getCurrentTrash();
		vinyl  getVinylTrash(int i);
		vinyl  getTrash();
		void   nextTrash();
		void   previousTrash();
		void   deleteCurrentTrash();
		void   addBackTrash(int i);
};


//NAGŁÓWKI NIEZALEŻNYCH FUNKCJI:

void gotoxy(int x, int y);
void writeVinylXY(vinyl t, int x, int y); //lepiej 2 metody (etykiety i wartosci - oddzielnie)


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


bool vinyl::setDate(int yr, int mon, int d)
{
	if (yr>=1930 && yr<=2024) 
		year=yr;
	else
		return 0;
	
	if(mon>=1 && mon<=12)
		month=mon;
	else
		return 0;	
	
	if(mon==1 || mon==3 || mon==5 || mon==7 || mon==8 || mon==10 || mon==12)
	{
		if (d>=1 && d<=31)
			day=d;
		else
			return 0;
	}
	else if(mon==2)
	{
		if((yr%4==0 && yr%100!=0)|| yr%400==0)
		{
			if(d>=1 && d<=29)
				day=d;
			else
				return 0;
		}
		else
		{
			if(d>=1 && d<=28)
				day=d;
			else
				return 0;
		}
	}
	else
	{
		if (d>=1 && d<=30)
			day=d;
		else
			return 0;	
	}		
	return 1;
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


float vinyl::worth()
{
	return price;
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

void baseVinyl::addNew(char* art, char* nam, char *edt, char *dist, float pr, char *cond, int yr, int mon, int d) //moze lepiej bool albo int mordo
{
	vinyl v;
	v.setDate(yr, mon, d);
	v.download(art, nam, edt, dist, pr, cond);
	tab.push_back(v);
	quantity++;
	current=quantity-1; 
} 


float baseVinyl::sum() 
{
	float sum_all=0;
	for (i=0; i<quantity; i++) //rozmiar jak nie zadziala
		sum_all+=tab[i].worth();
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
	trash.push_back(tab[i]);
	quantityTrash++;
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


void baseVinyl::deleteCurrentFound()
{
	trash.push_back(found[i]);
	quantityTrash++;
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
		

void baseVinyl::addBackTrash(int i)
{
	tab.push_back(trash[i]);
	quantity++;
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


void writeVinylXY(vinyl t, int x, int y) 
{
	gotoxy(x, y);
	cout<<"------------------------------------------------------------------------------";
	gotoxy(x, y+1);
	cout<<"|Artist:						                         |";
	gotoxy(x, y+2);
	cout<<"|Name:				    				         |";
	gotoxy(x, y+3);
	cout<<"|Edition:								         |";
	gotoxy(x, y+4);
	cout<<"|Distributor:							         |";
	gotoxy(x, y+5);
	cout<<"|Price:						    		         |";
	gotoxy(x, y+6);
	cout<<"|Condition:								         |";
	gotoxy(x, y+7);
	cout<<"|Data wydania:							         |";
	gotoxy(x, y+8);
	cout<<"------------------------------------------------------------------------------";
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

main() 
{
	char art[50], nam[20], edt[30], dist[40], cond[10], zn, search[50];
	float pr;
	int i, yr, mon, d, min, max;
	
	baseVinyl base;

	do 
	{
		system("CLS");
		cout<<endl<<"1. Clear all"<<endl;
		cout<<"2. Add new"<<endl;
		cout<<"3. Show the whole table"<<endl;
		cout<<"4. Sum of all"<<endl;
		cout<<"5. Save to File"<<endl;
		cout<<"6. Read to File"<<endl;
		cout<<"a. Browse through the table."<<endl;
		cout<<"b. Set Current"<<endl;
		cout<<"c. Sorting"<<endl;
		cout<<"d. Searching"<<endl;
		cout<<"e. Browse through found elements."<<endl;
		cout<<"f. Finish"<<endl;

		zn=getch();

		system("cls");

		switch(zn) 
		{
			case '1':
				cout<<"Are you sure you want to clear the whole table and lose everything?"<<endl;
				cout<<"y - yes           n - no";
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
				cout<<"Artist: ";
				gets(art);
				cout<<"Name: ";
				gets(nam);
				cout<<"Edition: ";
				gets(edt);
				cout<<"Distributor: ";
				gets(dist);
				cout<<"Price: ";
				cin>>pr;
				cin.ignore();
				cout<<"Condition: ";
				gets(cond);
				cout<<"Date(dd-mm-yyyy): "<<endl;
				cout<<"Day: ";
				cin>>d;
				cin.ignore();
				cout<<"Month: ";
				cin>>mon;
				cin.ignore();
				cout<<"Year: ";
				cin>>yr;
				cin.ignore();
				base.addNew(art, nam, edt, dist, pr, cond, yr, mon, d);
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
				cout<<"Sum of all: "<<base.sum()<<endl;
				cout<<"Click ENTER to proceed.";
				getchar();
				break;
				
			case '5':
				cout<<"Are you sure you want to upwrite the file?"<<endl<<"y - yes           n - no"<<endl;
				zn=getch();
				switch(zn)
				{
					case 'y':
						base.saveFile();
						cout<<"Saved. Click ENTER to proceed.";
						getchar();
						break;
					case 'n':
						break;
				}
				break;
				
			case '6':
				cout<<"Are you sure you want to lose your work and open a file?"<<endl<<"y - yes           n - no"<<endl;
				zn=getch();
				switch(zn)
				{
					case 'y':
						base.readFile();
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
						writeVinylXY(base.getVinyl(i), 5, 10);
						cout<<endl<<"    a - previous   b - next   c - change index    d - delete    l - leave";
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
								cout<<"Do you want to change the whole index or one of the categories?"<<endl;
								cout<<"1 - all  2 - artist 3 - name 4 - edition  5 - distributor  6 - price  7 - condition  8 - date  9 - leave";
								zn=getch();
								system("cls");
								switch(zn)
								{
									case '1':
										cout<<"Artist: ";
										gets(art);
										base.getTab().setArtist(art);
										cout<<"Name: ";
										gets(nam);
										base.getTab().setName(nam);
										cout<<"Edition: ";
										gets(edt);
										base.getTab().setEdition(edt);
										cout<<"Distributor: ";
										gets(dist);
										base.getTab().setDistributor(dist);
										cout<<"Price: ";
										cin>>pr;
										base.getTab().setPrice(pr);
										cin.ignore();
										cout<<"Condition: ";
										gets(cond);
										base.getTab().setCondition(cond);
										cout<<"Date(dd-mm-yyy): ";
										cin>>d;
										cin.ignore();
										cin>>mon;
										cin.ignore();
										cin>>yr;
										cin.ignore();
										base.getTab().setDate(yr,mon,d);
										cout<<endl<<"Changed! Press ENTER to continue";
										getchar();
										break;
									case '2':
										cin.ignore();
										cout<<"Artist: ";
										gets(art);
										base.getTab().setArtist(art);
										cout<<endl<<"Changed! Press ENTER to continue";
										getchar();
										break;
									case '3':
										cout<<"Name: ";
										gets(nam);
										base.getTab().setName(nam);
										cout<<endl<<"Changed! Press ENTER to continue";
										getchar();
										break;
									case '4':
										cout<<"Edition: ";
										gets(edt);
										base.getTab().setEdition(edt);
										cout<<endl<<"Changed! Press ENTER to continue";
										getchar();
										break;
									case '5':
										cout<<"Distributor: ";
										gets(dist);
										base.getTab().setDistributor(dist);
										cout<<endl<<"Changed! Press ENTER to continue";
										getchar();
										break;
									case '6':
										cout<<"Price: ";
										cin>>pr;
										base.getTab().setPrice(pr);
										cout<<endl<<"Changed! Press ENTER to continue";
										getchar();
										break;
									case '7':
										cout<<"Condition: ";
										gets(cond);
										base.getTab().setCondition(cond);
										cout<<endl<<"Changed! Press ENTER to continue";
										getchar();
										break;
									case '8':
										cout<<"Date(dd-mm-yyy): ";
										cin>>d;
										cin.ignore();
										cin>>mon;
										cin.ignore();
										cin>>yr;
										cin.ignore();
										base.getTab().setDate(yr,mon,d);
										cout<<endl<<"Changed! Press ENTER to continue";
										getchar();
										break;
									case '9':
										break;
								}
								break;
							case 'd':
								cout<<endl<<endl<<"        Are you sure you want to delete current index?"<<endl<<"y - yes           n - no"<<endl;
								zn=getch();
								switch(zn)
								{
									case 'y':
										i=base.getCurrent();
										base.deleteCurrent(i);
										cout<<"Deleted.";
										i=base.getCurrent();
										break;
									case 'n':
										break;
								}
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
				cout<<"Are you sure you want to leave? (Remember to save your work!)."<<endl<<endl;
				cout<<"n - NO			ESC - leave";
				zn=getch();
				switch(zn)
				{
					case 27:
						system("cls");
						cout<<"Period.";
						getchar();
						break;
					case 'n':
						break;
				}
				break;
				
			case 'c': 
				system("cls");
				cout<<"By which category you want to sort?"<<endl;
				cout<<"1 - Sort by name"<<endl;
				cout<<"2 - Sort by price"<<endl;
				cout<<"3 - Sort by date"<<endl;
				cout<<"l - leave"<<endl;
				zn=getch();
				switch(zn)
				{
					case '1':
						system("cls");
						base.sortPrice();
						cout<<"Sorted. Click ENTER to proceed.";
						getchar();
						break;
					case '2':
						system("cls");
						base.sortName();
						cout<<"Sorted. Click ENTER to proceed.";
						getchar();
						break;
					case '3':
						system("cls");
						base.sortDate();
						cout<<"Sorted. Click ENTER to proceed.";
						getchar();
						break;
					case 'l':
						break;
				}
				break;	
					
			case 'd': 
				system("cls");
				cout<<"What do you want to search for?"<<endl;
				cout<<"1 - Search for an artist"<<endl;
				cout<<"2 - Search for a name"<<endl;
				cout<<"3 - Search for a price range"<<endl;
				cout<<"l - leave"<<endl;
				zn=getch();
				switch(zn)
				{
					case '1':
						system("cls");
						cout<<"Artist: ";
						fflush(stdin);
						gets(search);
						i=base.searchArtist(search);
						if(i==0)
							cout<<"Not found.";
						else
							cout<<"Found. Click ENTER to proceed.";
						getchar();
						break;
					case '2':
						system("cls");
						cout<<"Name: ";
						fflush(stdin);
						gets(search);
						i=base.searchName(search);
						if(i==0)
							cout<<"Not found.";
						else
							cout<<"Found. Click ENTER to proceed.";
						getchar();
						break;
					case '3':
						system("cls");
						cout<<"Min: ";
						cin>>min;
						cout<<"Max: ";
						cin>>max;
						i=base.searchPrice(min,max);
						if(i==1)
						{
							cout<<"Found. Click ENTER to proceed.";
							getchar();
						}
						else if(i==2)
						{
							cout<<"Minimum too low! Click ENTER to proceed and try again.";
							getchar();
						}
						else if(i==3)
						{
							cout<<"Maximum too high! Click ENTER to proceed and try again.";
							getchar();
						}
						else if(i==4)
						{
							cout<<"Maximum is lower than minimum! Click ENTER to proceed and try again.";
							getchar();
						}	
						else
						{
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
							cout<<"No elements. Click ENTER to leave.";
							getch();
							break;
						}
						writeVinylXY(base.getVinylFound(i), 5, 10);
						cout<<endl<<"    a - previous                    b - next          d - delete index      t - delete all indexes    l - leave";
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
								cout<<endl<<"Are you sure you want to delete current index?"<<endl<<"y - yes           n - no"<<endl;
								zn=getch();
								switch(zn)
								{
									case 'y':
										base.deleteCurrentFound();
										cout<<"Deleted.";
										i=base.getCurrentFound();
										break;
									case 'n':
										break;
								}
							case 't':
								cout<<endl<<"Are you sure you want to delete all found data?"<<endl<<"y - yes           n - no"<<endl;
								zn=getch();
								switch(zn)
								{
									case 'y':
										for(i=0;i<=base.getQuantityFound();i++)
										{
											base.deleteCurrentFound();
										}
										cout<<"Deleted. Click ENTER to proceed.";
										break;
									case 'n':
										break;
								}
						}
					}while(zn!='l');
				}
				break;
			
			case 'p':
			i=base.getCurrentTrash();
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
					if(base.getCurrentTrash()==-1)
					{
						cout<<"No elements. Click ENTER to leave.";
						getch();
						break;
					}
					writeVinylXY(base.getVinylTrash(i), 5, 10);
					cout<<endl<<"    a - previous          b - next        d - delete index      t - delete all indexes   j - add back   l - leave";
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
							cout<<endl<<"Are you sure you want to delete current index?"<<endl<<"y - yes           n - no"<<endl;
							zn=getch();
							switch(zn)
							{
								case 'y':
									base.deleteCurrentTrash();
									cout<<"Deleted.";
									i=base.getCurrentTrash();
									break;
								case 'n':
									break;
							}
						case 't':
							cout<<endl<<"Are you sure you want to delete all found data?"<<endl<<"y - yes           n - no"<<endl;
							zn=getch();
							switch(zn)
							{
								case 'y':
									for(i=0;i<=base.getQuantityTrash();i++)
									{
										base.deleteCurrentTrash();
									}
									cout<<"Deleted. Click ENTER to proceed.";
									break;
								case 'n':
									break;
							}
						case 'j':
							base.addBackTrash(i);
							cout<<endl<<"Added back. Click ENTER to proceed.";
							getchar();
							break;
					}
				}while(zn!='l');
			}
			break;	
		}
		
	} while(zn!=27);
}
