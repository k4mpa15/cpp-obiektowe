#include <iostream>
#include <string>

using namespace std;

class Notatka{
	friend class Folder;
	private:
		string tytul;
		string tresc;
	public:
		Notatka(string tytul, string tresc)
		{
			this->tytul = tytul;
			this->tresc = tresc;
		}
		
		~Notatka()
		{
			cout << "notatka usunieta" << endl;
		}
};

class Folder{
	friend class Uzytkownik;
	private:
		int iloscNotatek;
		Notatka* notatka[10];
		string nazwa;
	public:
		Folder(string nazwa)
		{
			this->iloscNotatek = 0;
			this->nazwa = nazwa;
		}
		
		~Folder()
		{
			cout << "usunieto folder" << endl;
			for (int i = 0; i < iloscNotatek; i++)
			{
				delete notatka[i];
			}
			iloscNotatek = 0;
		}
		
		void wyswietlNotatki()
		{	if (iloscNotatek > 0)
			{
				for (int i = 0; i < iloscNotatek; i++)
				{
					cout << "             " << notatka[i]->tytul << endl;
					cout << "             " << notatka[i]->tresc << endl;
				}
			}
			else cout << "           brak notatek!" << endl;
		}
		
		void utworzNotatke(string nazwa, string tresc)
		{
			notatka[iloscNotatek] = new Notatka(nazwa, tresc);
			iloscNotatek++;
		}
		
		void Edycja(string nazwaNot, string tresc)
		{
			for (int i = 0; i < iloscNotatek; i++)
			{
				if (notatka[i]->tytul == nazwaNot) notatka[i]->tresc = tresc;
				else cout << "brak takiej notatki" << endl;
			}
		}
		
		void Usuniecie(string tytulNot)
		{
			for (int i = 0; i < iloscNotatek; i++)
			{
				if (notatka[i]->tytul == tytulNot) delete notatka[i];
				else cout << "brak takiej notatki" << endl;
			}
			iloscNotatek--;
		}
};

class Uzytkownik{
	friend class MenagerUzytkownikow;
	private:
		bool czyZalogowany;
		string login;
		string haslo;
		Folder* folder[10];
		int iloscFolderow;
	public:
		Uzytkownik(string login, string haslo)
		{
			this->login = login;
			this->haslo = haslo;
			this->iloscFolderow = 0;
			czyZalogowany = false;
			for (int i = 0; i < 10; i++) folder[i] = NULL;
		}
		
		void utworzFolder(string nazwa)
		{
			if (czyZalogowany == true)
			{
				folder[iloscFolderow] = new Folder(nazwa);
				cout << "utworzono folder o nazwie: " << folder[iloscFolderow]->nazwa << " na koncie o loginie: " << this->login << endl;
				iloscFolderow++;
			}
			else cout << "nie jestes zalogowany" << endl;
		}
		
		void wyswietlFoldery()
		{
			if(czyZalogowany == true)
			{
				if (iloscFolderow > 0)
				{
					cout << "foldery i notatki uzytkownika o loginie: " << this->login << ":" << endl;
					for (int i = 0; i < iloscFolderow; i++)
					{
						cout << "    " << folder[i]->nazwa;
						cout <<endl;
						folder[i]->wyswietlNotatki();
					}
				}
				else cout << "brak folderow!" << endl;
			}
		}
		
		void wyswietlFoldery(string nazwaF)
		{
			if(czyZalogowany == true)
			{
				if (iloscFolderow > 0)
				{
					cout << "folder i notatki uzytkownika o loginie: " << this->login << ":" << endl;
					for (int i = 0; i < iloscFolderow; i++)
					{
						if (folder[i]->nazwa == nazwaF)
						{
							cout << "    " << folder[i]->nazwa;
							cout << endl;
							folder[i]->wyswietlNotatki();
						}
						
					}
				}
				else cout << "brak folderow!" << endl;
			}
		}
		
		~Uzytkownik()
		{
			cout << "usunieto uzytkownika" << endl;
			for (int i = 0; i < 10; i++)
			{
				delete folder[i];
			}
			iloscFolderow = 0;
		}
		
		void utworzNotatke()
		{
			if(czyZalogowany == true)
			{
				cout << "podaj nazwe notatki jaka chcesz utworzyc" << endl;
				string nazwa;
				cin >> nazwa;
				cout << "podaj tresc notatki" << endl;
				string tresc;
				cin >> tresc;
				cout << "podaj nazwe folderu do jakiego chcesz zapisac notatke" << endl;
				string nazwaF;
				cin >> nazwaF;
				for (int i = 0; i < iloscFolderow; i++)
				{
					if (folder[i]->nazwa == nazwaF) folder[i]->utworzNotatke(nazwa, tresc);
					else 
					{
						if (iloscFolderow < 10) 
						{
							cout << "tworzenie nowego folderu" << endl;
							folder[iloscFolderow] = new Folder(nazwaF);
							folder[iloscFolderow]->utworzNotatke(nazwa, tresc);
							iloscFolderow++;
						}
						else 
						{
							cout << "brak miejsca na nowy folder!" << endl;
							cout << "podaj inna nazwe folderu";
							cin >> nazwaF;
							if (folder[i]->nazwa == nazwaF) folder[i]->utworzNotatke(nazwa, tresc);
						}
					}
				}
			}
			else cout << "nie jestes poprawnie zalogowany" << endl;
		}
		
		void edytujNotatke(string nazwa)
		{
			cout << "podaj nazwe notatki do zmiany " << endl;
			string nazwaNot;
			cin >> nazwaNot;
			string tresc;
			cout << "podaj tresc na jaka chcesz zmienic notatke: " << endl;
			cin >> tresc;
			for (int i = 0; i < iloscFolderow; i++)
			{
				if (folder[i]->nazwa == nazwa) folder[i]->Edycja(nazwaNot, tresc);
				else cout << "nie ma takiego folderu!" << endl;	
			}
		}
		
		void usunNotatke(string nazwa)
		{
			cout << "podaj nazwe notatki do usuniecia " << endl;
			string nazwaNot;
			cin >> nazwaNot;
			for (int i = 0; i < iloscFolderow; i++)
			{
				if (folder[i]->nazwa == nazwa) folder[i]->Usuniecie(nazwaNot);
				else cout << "nie ma takiego folderu!" << endl;
			}
		}
};

class MenagerUzytkownikow{
	friend class Uzytkownik;
	private:
		int iloscUzytkownikow;
		Uzytkownik* Uzytkownicy[100];
	public:
		Uzytkownik* logowanie(string login, string haslo, Uzytkownik* u)
		{
			if (u->login == login && u->haslo == haslo)
			{
				if(iloscUzytkownikow < 100)
				{
					u->czyZalogowany = true;
					Uzytkownicy[iloscUzytkownikow] = u;
					iloscUzytkownikow++;
					cout << "zalogowano" << endl;
					return u;
				}
				else cout << "za duzo uzytkownikow!" << endl;
			
			}
			else cout <<"niepoprawne haslo i/lub login" << endl;
		}
		
		MenagerUzytkownikow()
		{
			iloscUzytkownikow = 0;
			for (int i = 0; i < 100; i++) Uzytkownicy[i] = NULL;
		}
		
		void wylogowanie(Uzytkownik *u)
		{
			u->czyZalogowany = false;
		}
		
		~MenagerUzytkownikow()
		{
			for (int i = 0; i < iloscUzytkownikow; i++)
			{
				Uzytkownicy[i]->czyZalogowany = false;
				delete Uzytkownicy[i];
				
			}
			iloscUzytkownikow = 0;
		}
};

int main()
{
	MenagerUzytkownikow* m1 = new MenagerUzytkownikow;
	
	Uzytkownik* u1 = new Uzytkownik("Ala", "haslo123");
	m1->logowanie("Ala", "haslo123", u1);
	Uzytkownik* u2 = new Uzytkownik("Ola", "haslo123");
	m1->logowanie("Ola", "haslo1234", u2);
	Uzytkownik* u3 = new Uzytkownik("Ela", "haslo123");
	m1->logowanie("Ela", "haslo123", u3);
	
	delete m1;
	
	cout << endl;
	
	MenagerUzytkownikow* m2 = new MenagerUzytkownikow;
	
	Uzytkownik* u4 = new Uzytkownik("Ania", "haslo123");
	m2->logowanie("Ania", "haslo123", u4);
	Uzytkownik* u5 = new Uzytkownik("Asia", "haslo123");
	m2->logowanie("Asia", "haslo123", u5);
	
	u4->utworzFolder("folder1");
	u5->utworzFolder("folder1");
	
	cout << endl;
	
	u4->wyswietlFoldery();
	
	cout << endl;
	
	u4->utworzNotatke();
	u4->utworzNotatke();
	
	cout << endl;
	
	string folder;
	
	u4->wyswietlFoldery();
	
	cout << "jaki folder chcesz wyswietlic?" << endl;
	cin >> folder;
	
	u4->wyswietlFoldery(folder);
	
	cout << "w jakim folderze chcesz edytowac notatke?" << endl;
	cin >> folder;
	u4->edytujNotatke(folder);
	
	cout << "w jakim folderze chcesz usunac notatke?" << endl;
	cin >> folder;
	u4->usunNotatke(folder);

	u4->wyswietlFoldery();
	
	delete m2;
	
	return 0;
}

