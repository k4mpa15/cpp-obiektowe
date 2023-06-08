# cpp-obiektowe
programy w c++ 
Programowanie obiektowe | Laboratorium nr 7-8 | WCY21KY1S1 

Przedstaw na diagramie klas UML klasy oraz zależnościU między nimi spełniające następujące założenia dla budowanego systemu prowadzenia i organizacji notatek: 

 

Występują klasy: Uzytkownik, ManagerUzytkownikow, Notatka, Folder. 

Użytkownik ma przypisany login,  hasło oraz foldery, w których przechowuje swoje notatki. Można założyć odgórny limit tych folderów. 

Użytkownik może utworzyć nową notatkę dopiero po poprawnym zalogowaniu. Logowanie odbywa się poprzez podanie loginu i hasła. O poprawności logowania decyduje ManagerUzytkownikow i po poprawnym uwierzytelnieniu zwraca adres na obiekt zalogowanego użytkownika. ManagerUzytkownikow posiada listę użytkowników, którym zapewnia również wylogowanie, ponadto może obsłużyć maksymalnie 100 użytkowników.  

Jeden użytkownik może mieć wiele notatek, ale system nakłada odgórną granicę 10 notatek na folder. Notatka zawiera tytuł oraz treść. 

Notatki są organizowane w folderach i tu system także nakłada odgórną granicę 10 folderów na użytkownika. Folder identyfikowany jest według nazwy. 

Użytkownik tworząc notatkę podaje również nazwę folderu, w której ma się znaleźć, jeżeli podana zostanie nazwa folderu, którego nie ma utworzonego, to następuje utworzenie tego folderu, chyba, że przekroczony zostanie odgórny limit folderów na użytkownika. Jeśli wskazany dla notatki folder został już zapełniony, to użytkownik jest o tym informowany i oczekiwane jest podanie innej nazwy folderu. 

Każdą istniejącą notatkę można edytować (nadpisując nową treścią) bądź usunąć. 

Użytkownik może wyświetlić wszystkie posiadane foldery oraz notatki we wskazanym folderze. 

Usuniecie ManageraUzytkownikow, skutkuje usunięciem użytkowników, w następstwie czego usuwane są wszystkie przypisane do nich foldery wraz z zawartymi w nich notatkami. 

 

 Zaimplementuj zaproponowany diagram klas w języku C++ i napisz program testujący. 

 
