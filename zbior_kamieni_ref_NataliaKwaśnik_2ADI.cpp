#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>
#include <windows.h>

struct collection
{
	char name[20];
	float hardness;
	int quantity;
	float price;

};

using namespace std;

void randomData(collection gemstones[], int &n);
void generateSorted(collection gemstones[], int &n);
void generateReverseSorted(collection gemstones[], int &n);
bool addNew(collection gemstones[], collection &nowy, int &n, int &size);
void writeOut(collection gemstones[], int &n);
float sumAll(collection gemstones[], int &n);
float averagePrice(collection gemstones[], int &n);
void searchPrice(collection gemstones[], int &n, collection found[], int &n_found, float &min, float &max);//szukany przedział <min,max>
void minmax(collection gemstones[], int &n, float &min, float &max);
void discount(collection gemstones[], int &n, float &percent);
void selectionSort(collection gemstones[], int &n);
bool writeFile(collection gemstones[], collection found[], int &n, int &n_found);
bool readFile(collection gemstones[], collection found[], int &n, int &n_found);
bool searchByName(collection gemstones[], int &n, string &name);
void ReadMe(); 
void insertSort(collection gemstones[], int &n);
void bubbleSort(collection gemstones[], int &n);
void nameSort(collection gemstones[], int &n);
void changeElement(collection gemstones[], collection &change, int &element);
void deleteElement(collection gemstones[], int &element, int &n);
void writeOutFound(collection found[], int &n_found);

main()
{       
	collection  *gemstones, *found, nowy, change;
	float sum, average, minimum, maximum, percent;
	int size=0, n=0, n_found=0, element=0;
	bool x, c, read, write, search;
	string byName;
	char znak;
	cout<<"Oblsuga magazynu ver.1"<<endl<<endl;
	srand(time(NULL));
	do
	{
		fflush(stdin);
		cout<<endl<<endl<<"Nacisnij ENTER"<<endl;
		getchar();
		system("CLS");
		cout<<"0. Dynamiczne tworzenie magazynu"<<endl;
		cout<<"1. Losowanie calego magazynu"<<endl;
		cout<<"2. Generowanie calego magazynu posortowanego"<<endl;
		cout<<"3. Generowanie calego magazynu odwrotnie posortowanego"<<endl;
		cout<<"4. Dopisanie towaru do magazynu"<<endl;
		cout<<"5. Wypisanie elementow tablicy"<<endl;
		cout<<"6. Suma wartosci w calym magazynie"<<endl;
		cout<<"7. Srednia cena towaru"<<endl;
		cout<<"8. Maksymalna i minimalna cena"<<endl;
		cout<<"9. Zmiana ceny o dany procent"<<endl;
		cout<<"a. Wyszukiwanie wedlug przedzialu cen"<<endl;
		cout<<"b. Sortowanie rosnace wedlug cen- proste wybieranie"<<endl;
		cout<<"c. Zapisz plik"<<endl;
		cout<<"d. Odczytaj plik"<<endl;
		cout<<"e. Szukanie wedlug nazwy"<<endl;
		cout<<"f. Insert sort wedlug cen"<<endl;
		cout<<"g. Bubble sort wedlug cen"<<endl;
		cout<<"h. Namesort"<<endl;
		cout<<"i. Podmien element"<<endl;
		cout<<"j. Usuwanie elementu"<<endl;
		cout<<"k. Wypisanie znalezionych"<<endl;
		cout<<"l. ReadMe"<<endl;
		cout<<"ESC. ---Koniec pracy---"<<endl;
		
		znak=getch();
		switch(znak)
		{
			case '0':	cout<<"Jaki rozmiar magazynu? (Miedzy 5, a 300): ";
						cin>>size;
						while(size<5 || size>300)
						{
							cout<<"Bledna liczba. Podaj nowa: ";
							cin>>size;
						}		
						gemstones=new collection[size+1];     //Powiekszony o 1 - patrz gorny komentarz
						found=new collection[size+1];
						n=0;
						n_found=0;
						break;
						
			case '1':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						cout<<"Ile danych losowac? ";
						cin>>n;
						while(n<size || n>size)
						{
							if(n>size)
							{
								cout<<"Bledna liczba. Podales wieksza liczbe niz zakres tablicy. Podaj nowa: ";
								cin>>n;
							}
							else
							{
								cout<<"Podales za mala liczbe. Podaj nowa: ";
								cin>>n;	
							}
						}
						randomData(gemstones, n);
						break;
						
			case '2':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						cout<<"Ile danych generowac? ";
						cin>>n;
						while(n<size || n>size)
						{
							if(n>size)
							{
								cout<<"Bledna liczba. Podales wieksza liczbe niz zakres tablicy. Podaj nowa: ";
								cin>>n;
							}
							else
							{
								cout<<"Bledna liczba. Podaj nowa: ";
								cin>>n;	
							}
						}
						generateSorted(gemstones, n);
						cout<<endl<<"Wygenerowano"<<endl;
						break;
						
			case '3':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						cout<<"Ile danych generowac? ";
						cin>>n;
						while(n<size || n>size)
						{
							if(n>size)
							{
								cout<<"Bledna liczba. Podales wieksza liczbe niz zakres tablicy. Podaj nowa: ";
								cin>>n;
							}
							else
							{
								cout<<"Podales za mala liczbe. Podaj nowa: ";
								cin>>n;	
							}
						}
						generateReverseSorted(gemstones, n);
						cout<<endl<<"Wygenerowano"<<endl;
						break;
						
			case '4':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						cout<<"Nazwa: ";
						fflush(stdin);
						gets(nowy.name);
						cout<<"Twardosc: ";
						cin>>nowy.hardness;
						while(nowy.hardness<=0 || nowy.hardness>10)
						{
							cout<<"Bledna liczba. Zakres od 1 do 10. Podaj nowa: ";
							cin>>nowy.hardness;
						}
						cout<<"Sztuki: ";
						cin>>nowy.quantity;
						while(nowy.quantity<=0 || nowy.quantity>5)
						{
							cout<<"Bledna liczba. Zakres od 1 do 5. Podaj nowa: ";
							cin>>nowy.quantity;
						}
						cout<<"Cena: ";
						cin>>nowy.price;
						while(nowy.price<=0 || nowy.price>=500000)
						{
							cout<<"Bledna liczba. Zakres jest od 1 do 500000. Podaj nowa: ";
							cin>>nowy.price;
						}
						cin.ignore();
						x=addNew(gemstones, nowy, n, size); 
						if(x==true)
							cout<<"Dodano";
						if(x==false)
							cout<<"Nie dodano";
						break;
						
			case '5':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						if(n==0)
						{
							cout<<"Nie ma nic do wypisania.";
							break;
						}
						writeOut(gemstones, n);
						cout<<endl;
						break;
						
			case '6':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						if(n==0)
						{
							cout<<"Nie ma danych. Wprowadz najpierw dane.";
							break;
						}
						cout<<endl<<"Suma wartosci magazynu= "<<sumAll(gemstones, n)<<endl<<endl;
						break;
						
			case '7':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						if(n==0)
						{
							cout<<"Nie ma danych. Wprowadz najpierw dane.";
							break;
						}
						cout<<endl<<"Srednia cena= "<<averagePrice(gemstones, n)<<endl<<endl;
						break;
						
			case '8':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						if(n==0)
						{
							cout<<"Nie ma nic do przeceny. Wprowadz najpierw dane.";
							break;
						}
						minmax(gemstones, n, minimum, maximum);
						cout<<"Cena minimalna="<<minimum<<". Cena maksymalna="<<maximum<<endl;
						break;
						
			case '9':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						if(n==0)
						{
							cout<<"Nie ma nic do przeceny. Wprowadz najpierw dane.";
							break;
						}
						cout<<"O jaki procent przeceniasz? (ujemny obniza) ";
						cin>>percent;
						while(percent<-99.99 || percent>200)
						{
							cout<<"Bledna liczba. Zakres zaczyna sie od -99 i konczy na 200. Podaj nowa: ";
							cin>>percent;
						}
						discount(gemstones, n, percent);
						cout<<"Przecenione."<<endl;
						break;
			
			case 'a':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						if(n==0)
						{
							cout<<"Nie ma danych. Wprowadz najpierw dane.";
							break;
						}
						do
						{
						cout<<"Podaj przedzial szukany."<<endl<<"od wartosci: ";
						cin>>minimum; 												
						cout<<"do wartosci: ";
						cin>>maximum;
							if(minimum<=0)
							{
								cout<<"Podales za malo. Podaj nowe liczby";
							}
							else if(maximum>500000)
							{
								cout<<"Podales za duzo. Podaj nowe liczby";
							}
							else if(maximum<minimum)
							{
								cout<<"Maksimum jest mniejsze niż minimum. Podaj nowe liczby.";
							}
						}while(minimum<=0 || maximum>500000 || maximum<minimum || minimum>maximum);
						getchar();
						searchPrice(gemstones, n, found, n_found, minimum, maximum);
						writeOut(found, n_found);
						cout<<endl;
						break;
						
			case 'b':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						selectionSort(gemstones, n);
						cout<<"Posortowano"<<endl;
						break;
						
			case 'c':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						write=writeFile(gemstones, found, n, n_found);
						if(write==false)
						{
							cout<<"Niezapisano";	
						}
						else
						{
							cout<<"Zapisano";
						}
						break;
						
			case 'd':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						read=readFile(gemstones, found, n, n_found);
						if(read==false)
						{
							cout<<"Nieodczytano";
						}
						else
						{
							cout<<"Odczytano";
						}
						break;		
						
			case 'e':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						cout<<"Podaj nazwe, ktorej szukasz: ";
						cin>>byName;
						search=searchByName(gemstones, n, byName);
						if(search==false)
						{
							cout<<"Brak takiego elementu."<<endl;
						}
						break;
			
			case 'f':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						insertSort(gemstones, n);
						cout<<"Posortowano."<<endl;
						break;
			
			case 'g':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						bubbleSort(gemstones, n);
						cout<<"Posortowano."<<endl;
						break;
			
			case 'h':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						nameSort(gemstones, n);
						cout<<"Posortowano."<<endl;
						break;
						
			case 'i':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						cout<<"Ktory element chcesz zmienic? (podaj nr indeksu)";
						do
						{
							cin>>element;
							if(element<=0 || element>n)
							{
								cout<<"Podano zly numer indeksu.";
							}
						}while(element<=0 || element>n);
						
						cout<<"Nazwa: ";
						fflush(stdin);
						gets(change.name);
						cout<<"Twardosc: ";
						cin>>change.hardness;
						while(change.hardness<=0 || change.hardness>10)
						{
							cout<<"Bledna liczba. Zakres od 1 do 10. Podaj nowa: ";
							cin>>change.hardness;
						}
						cout<<"Sztuki: ";
						cin>>change.quantity;
						while(change.quantity<=0 || change.quantity>5)
						{
							cout<<"Bledna liczba. Zakres od 1 do 5. Podaj nowa: ";
							cin>>change.quantity;
						}
						cout<<"Cena: ";
						cin>>change.price;
						while(change.price<=0 || change.price>=500000)
						{
							cout<<"Bledna liczba. Zakres jest od 1 do 500000. Podaj nowa: ";
							cin>>change.price;
						}
						cin.ignore();
						changeElement(gemstones, change, element);
						cout<<"Podmieniono.";
						break;
						
			case 'j':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						cout<<"Ktory element chcesz usunac? (podaj nr indeksu)";
						do
						{
							cin>>element;
							if(element<=0 || element>n)
							{
								cout<<"Podano zly numer indeksu.";
							}
						}while(element<=0 || element>n);
						deleteElement(gemstones, element, n);
						n--;
						cout<<"Usunieto.";
						break;
			
			case 'k':	if(size==0)
						{
							cout<<"Wybierz najpierw 0, aby utworzyc tablice";
							break;
						}
						if(n_found==0)
						{
							cout<<"Brak rzeczy do wypisania."<<endl;
							break;
						}
						writeOutFound(found, n_found);
						break;
									
			case 'l':	ReadMe();
						break;
						
			case 27:	cout<<"Koniec programu"<<endl;
						return 0;
						break;
						
						
			default: 	cout<<"Zly wybor!"<<endl;
		}
		getchar();	
	}while(znak!=27);	

cout<<endl<<"Nacisnij klawisz by zakonczyc"<<endl;
delete [] gemstones;
delete [] found;
system("pause");
return 0;
}




	
void randomData(collection  gemstones[], int &n)
{
	char naz[20], numer[13];
	for(int i=1; i<=n; i++)
	{
		strcpy(naz,"Kamyk"); 
		itoa(i, numer, 10);
		strcat(naz, numer);
		strcpy(gemstones[i].name, naz);
		gemstones[i].price=(rand()%500000) /100;
		gemstones[i].quantity=(rand()%10) + 5;
		gemstones[i].hardness=(rand()%10);
	}
}


void generateSorted(collection  gemstones[], int &n)
{
	char naz[20], numer[13];
	for(int i=1; i<=n; i++)	
	{
		strcpy(naz,"Kamyk");
		itoa(i, numer, 10);
		strcat(naz, numer);
		strcpy(gemstones[i].name, naz);
		gemstones[i].price=i*10.11;
		gemstones[i].quantity=i;
		gemstones[i].hardness=i;	
	}

}


void generateReverseSorted(collection  gemstones[], int &n)
{
	char naz[20], numer[13];
	for(int i=1; i<=n; i++)	
	{
		strcpy(naz,"Kamyk");
		itoa(i, numer, 10);			//nazwy numeruję j.w, czyli rosnąco
		strcat(naz, numer);
		strcpy(gemstones[i].name, naz);
		gemstones[i].price=n*20 - i*10.11;
		gemstones[i].quantity=i;
		gemstones[i].hardness=i;
	}
}


bool addNew(collection  gemstones[], collection  &nowy, int &n, int &size)
{
	if (n>=size)
		return false;
	(n)++;
	gemstones[n]=nowy;
	return true;
}


void writeOut(collection  all[], int &n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		cout<<i<<". "<<all[i].name<<" | cena: "<<all[i].price<<" | ilosc:  "<<all[i].quantity<<" | twardosc: "<<all[i].hardness<<endl;
	}
}


float sumAll(collection  gemstones[], int &n)
{
	int i;
	float sum;
	for(i=1; i<=n; i++)
		sum+=gemstones[i].price;
	return sum;	
}


float averagePrice(collection  gemstones[], int &n)
{
	int i;
	float sum;
	float average;
	for(i=1; i<=n; i++)
		sum+=gemstones[i].price;
	average=sum/ n;
	return average;
}


void searchPrice(collection  gemstones[], int &n, collection found[], int &n_found, float &min, float &max)
{
	int i;
	n_found=0;
	for(i=0; i<n; i++)
	{
		if(gemstones[i].price>=min && gemstones[i].price<=max)
		{
			(n_found)++;	
			found[n_found]=gemstones[i];
		}
	}
}


void minmax(collection gemstones[], int &n, float &min, float &max)
{
	int i;
	min=gemstones[1].price;
	max=gemstones[1].price;
	for(i=2; i<=n; i++)
	{
		if(gemstones[i].price>max)
			max=gemstones[i].price;
			
		else
		if(gemstones[i].price<min)
			min=gemstones[i].price;
	}
}


void discount(collection  gemstones[], int &n, float &percent) //przecena wszystkiego
{
	for(int i=1; i<=n; i++)
		gemstones[i].price+=gemstones[i].price * percent/100;
}


void selectionSort(collection  gemstones[], int &n)
{
	collection  min;
	int index, i, nr;
	for(nr=1; nr<n; nr++)
	{
		min=gemstones[nr];
		index=nr;
		for(i=nr+1; i<=n; i++)
		
			if(gemstones[i].price < min.price)
			{
				min=gemstones[i];
				index=i;
			}
		gemstones[index]=gemstones[nr];
		gemstones[nr]=min;
	}
}


bool searchByName(collection gemstones[], int &n, string &name)
{
	int j;
	for(int i=1; i<=n; i++)
	{
		if(name==gemstones[i].name)
		{
			cout<<i<<". "<<gemstones[i].name<<" | cena: "<<gemstones[i].price<<" | ilosc:  "<<gemstones[i].quantity<<" | twardosc: "<<gemstones[i].hardness<<endl;
			j++;
		}
	}
	
	if(j==0)
		return false;
	else
		return true;		
}	


bool writeFile(collection gemstones[], collection found[], int &n, int &n_found)
{
	FILE *tb;
	FILE *tbf;
	tb=fopen("gemstones.dat", "wb");
	if(tb==NULL)
	{
		return false;
	}	
	fwrite(&n, sizeof(n), 1, tb);
	for(int i=1; i<=n; i++)
		fwrite(&gemstones[i], sizeof(gemstones[i]), 1, tb);
	fclose(tb);
	
	tbf=fopen("gsfound.dat", "wb");
	if(tbf==NULL)
	{
		return false;
	}
	fwrite(&n_found, sizeof(n_found), 1, tbf);
	for(int i=1; i<=n_found; i++)
		fwrite(&found[i], sizeof(found[i]), 1, tbf);
	fclose(tbf);
	return true;
}


bool readFile(collection  gemstones[], collection found[], int &n, int &n_found)
{
	FILE *tb;
	FILE *tbf;
	tb=fopen("gemstones.dat", "rb");
	if(tb==NULL)
	{
		return false;
	}
	fread(&n, sizeof(n), 1, tb);
	for(int i=1; i<=n; i++)
		fread(&gemstones[i], sizeof(gemstones[i]), 1, tb);
	fclose(tb);
	
	tbf=fopen("gsfound.dat", "rb");
	if(tbf==NULL)
	{
		return false;
	}
	fread(&n_found, sizeof(n_found), 1, tbf);
	for(int i=1; i<=n_found; i++)
		fread(&found[i], sizeof(found[i]), 1, tbf);
	fclose(tbf);
	return true;
}
		
void ReadMe()
{

	FILE *fp;
	char c;
	fp=fopen("ReadMe.txt","r");
	do
	{
		c=getc(fp);
		
		Sleep(45);
		if (c!=EOF)
			cout<<c;
	}
	while(c!=EOF);
	fclose(fp);
} 


void insertSort(collection gemstones[], int &n)
{
	int i;
	for(int nr=2, i; nr<=n; nr++)
	{
		gemstones[0]=gemstones[nr];
		i=nr-1;
		while(gemstones[i].price>gemstones[0].price)
		{
			gemstones[i+1]=gemstones[i];
			i--;
		}
		gemstones[i+1]=gemstones[0];
	}
}


void bubbleSort(collection gemstones[], int &n)
{
	collection pom;
	for(int nr=1; nr<=n; nr++)
		for(int i=1; i<=n-nr; i++)
			if(gemstones[i].price>gemstones[i+1].price)
			{
				pom=gemstones[i];
				gemstones[i]=gemstones[i+1];
				gemstones[i+1]=pom;
			}
}	

void nameSort(collection gemstones[], int &n)
{
	collection pom;
	for(int nr=1; nr<=n; nr++)                 
  {
    for(int i=1; i<=n-nr; i++)
    {
      if(strcmp(gemstones[i].name, gemstones[i+1].name)>0)       
      {
        pom=gemstones[i];
        gemstones[i]=gemstones[i+1];
        gemstones[i+1]=pom;
      }
    }
  }	
}


void changeElement(collection gemstones[], collection &change, int &element)
{
	gemstones[element]=change;				
}


void deleteElement(collection gemstones[], int &element, int &n)
{
	for(int i=element; i<n; i++)
	{
		gemstones[i]=gemstones[i+1];
	}
}

void writeOutFound(collection found[], int &n_found)
{
	int i;
	for(i=1;i<=n_found;i++)
	{
		cout<<i<<". "<<found[i].name<<" | cena: "<<found[i].price<<" | ilosc:  "<<found[i].quantity<<" | twardosc: "<<found[i].hardness<<endl;
	}

}