#include <iostream>
using namespace std;

int main()
{
	int wybor= 0; 								/// zmienna dla pierwszego switcha
	char filler='1'; 							/// zmienna, która wype³ni tablicê wyborów
	string plansza[3][3]; 						/// plansza do gry
	string pozycje[3][3];						/// plansza, oznaczaj¹ca wolne pola
	string kolo_czy_krzyzyk[2];					/// tablica przechowuj¹ca "X" i "O"
	for(int i=0; i<3; i++)						/// wype³nienie obu tablic
	{
		for(int j=0; j<3; j++)
		{
			plansza[i][j] = ".";
			pozycje[i][j]= filler;
			filler++;
		}
	}
	cout<<"Witaj w grze kolko i krzyzyk"<<endl<<"1. Graj"<<endl<<"2. Wyjdz"<<endl;
	cin>>wybor;									/// rozpoczêcie gry, lub brak rozpoczêcia
	switch(wybor)
	{
		case 2:
			cout<<"Na razie"<<endl;
			exit(0);
			break;
		case 1:
			cout<<"To grajmy"<<endl;
			break;
	}
	int tura_gracza=0, tura_przeciwnika = 0;	/// zmienne do liczenia tur, zmienna okreœlaj¹ca czy ktoœ wygra³, zmienna przechowuj¹ca "X" lub "O" w zale¿noœci od gracza oraz zmienna do drugiego switcha
	int wygrana = 0;
	string znak="";
	int wybor2 = 0;
	cout<<"Graczu nr 1, co wybierasz? Kolko czy krzyzyk?"<<endl<<"1. Kolko"<<endl<<"2. Krzyzyk"<<endl;
	cin>>wybor2; 								/// wybór przez gracza pierwszego "X" lub "O"
	switch(wybor2)
	{
		case 1:
			kolo_czy_krzyzyk[0]="O";
			kolo_czy_krzyzyk[1]="X";
			break;
		case 2:
			kolo_czy_krzyzyk[0]="X";
			kolo_czy_krzyzyk[1]="O";
			break;
			
	}
	while (wygrana == 0)
	{
		if(wygrana == 0 && tura_gracza + tura_przeciwnika == 9){
				cout<<"Remis"<<endl; 			/// w przypadku gdy nikt nie wygra³, mamy remis
				break;
			}
		if (tura_gracza == tura_przeciwnika)
		{
			tura_gracza++;						/// zmiana tury na gracza nr 1
			cout<<"Tura gracza nr 1"<<endl;
			znak = kolo_czy_krzyzyk[0];
		}
		else
		{
			tura_przeciwnika++;					/// zmiana tury na gracza nr 2
			cout<<"Tura gracza nr 2"<<endl;
			znak = kolo_czy_krzyzyk[1];
		}
		int filler2=0;							/// zmienna, która okreœla numer pola(dla tablicy pozycje)
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				cout<<plansza[i][j];			/// wypisanie obecnego stanu planszy 
			}
			cout<<endl;
		}
		cout<<endl;
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				cout<<pozycje[i][j];			/// wypisanie obecnego stanu wolnych pozycji
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"Wybierz pole, na ktorym umiescisz "<<znak<<endl;
		cin>>filler2;
		while(filler2 < 1 || filler2>9)
		{
			cin>>filler2;						/// obs³uga b³êdnego wybrania pola(liczba z poza zakresu od 1 do 9)
		}
		int d1, d2 = 0;							/// interpretacja wpisanego numeru pola na pozycjê w tablicy
		d1 = filler2 / 3;
		if (filler2 % 3 == 0)
		{
			d1--;
		}
		int test = filler2 % 3;
		if (test == 1)
		{
			d2 = 0;
		}
		if (test == 2)
		{
			d2 = 1;
		}
		if (test == 0)
		{
			d2 = 2;
		}
		if(	pozycje[d1][d2] == ".")				/// w przypadku gdy pole zosta³o ju¿ wykorzystane(jest na nim .), to gracz musi wybraæ inne pole
		{
			cout<<"To pole jest zajete, wybierz inne"<<endl;
			if (tura_gracza > tura_przeciwnika)
			{
				tura_gracza--;
			}
			else
			{
				tura_przeciwnika--;
			}
			
		}
		else
		{
			pozycje[d1][d2] = ".";				/// jeœli pole jest poprawne, na planszy zostanie umieszczony znak ("X" lub "O"), a na tablicy pozycji cyfra zostanie zast¹piona kropk¹
			plansza[d1][d2] = znak;
		}
		if (tura_gracza > 2 && tura_przeciwnika > 1 && (tura_gracza + tura_przeciwnika) < 10) ///kiedy minie przynajmniej 5 tur
		{
			int numer_gracza = 0;				/// gracz nr 1 rozpoczyna³, a przeciwnikiem by³ gracz nr 2
			if ((tura_gracza + tura_przeciwnika)% 2 == 0)
			{
				numer_gracza = 2;
			}
			else
			{
				numer_gracza = 1;
			}
			if (plansza[0][2] == znak)			/// opisanie wszystkich mo¿liwych kombinacji wygrywaj¹cych i wybór zwyciêzcy(w przypadku braku takiej kombinacji po wykonaniu 9 ruchów nast¹pi remis)
			{
				if(plansza[0][2] == plansza[1][2] && plansza[1][2] == plansza[2][2] )
				{
					cout<<"Gracz nr "<<numer_gracza<<" wygral uzywajac "<<znak<<endl;
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							cout<<plansza[i][j];
						}
						cout<<endl;
					}
					cout<<endl;
					wygrana++;
				}
				if(plansza[0][2] == plansza[1][1] && plansza[2][0] == plansza[1][1] )
				{
					cout<<"Gracz nr "<<numer_gracza<<" wygral uzywajac "<<znak<<endl;
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							cout<<plansza[i][j];
						}
						cout<<endl;
					}
					cout<<endl;
					wygrana++;
				}
				if(plansza[0][2] == plansza[0][1] && plansza[0][0] == plansza[0][1] )
				{
					cout<<"Gracz nr "<<numer_gracza<<" wygral uzywajac "<<znak<<endl;
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							cout<<plansza[i][j];
						}
						cout<<endl;
					}
					cout<<endl;
					wygrana++;
				}
				
			}
			if(plansza[0][1] == znak)
			{
				if(plansza[0][1] == plansza[1][1] && plansza[1][1] == plansza[2][1] )
				{
					cout<<"Gracz nr "<<numer_gracza<<" wygral uzywajac "<<znak<<endl;
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							cout<<plansza[i][j];
						}
						cout<<endl;
					}
					cout<<endl;
					wygrana++;
				}
			}
			if (plansza[0][0] == znak)
			{
				if(plansza[0][0] == plansza[1][1] && plansza[1][1] == plansza[2][2] )
				{
					cout<<"Gracz nr "<<numer_gracza<<" wygral uzywajac "<<znak<<endl;
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							cout<<plansza[i][j];
						}
						cout<<endl;
					}
					cout<<endl;
					wygrana++;
				}
				if(plansza[0][0] == plansza[1][0] && plansza[2][0] == plansza[1][0] )
				{
					cout<<"Gracz nr "<<numer_gracza<<" wygral uzywajac "<<znak<<endl;
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							cout<<plansza[i][j];
						}
						cout<<endl;
					}
					cout<<endl;
					wygrana++;
				}
			}
			if(plansza[1][0] == znak)
			{
				if(plansza[1][0] == plansza[1][1] && plansza[1][1] == plansza[1][2] )
				{
					cout<<"Gracz nr "<<numer_gracza<<" wygral uzywajac "<<znak<<endl;
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							cout<<plansza[i][j];
						}
						cout<<endl;
					}
					cout<<endl;
					wygrana++;
				}
			}
			if(plansza[2][0] == znak)
			{
				if(plansza[2][0] == plansza[2][1] && plansza[2][1] == plansza[2][2] )
				{
					cout<<"Gracz nr "<<numer_gracza<<" wygral uzywajac "<<znak<<endl;
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							cout<<plansza[i][j];
						}
						cout<<endl;
					}
					cout<<endl;
					wygrana++;
				}
			}
			
			
			
			
		}
		
			
		
		
		

		
		
		
	}
	
	
}
