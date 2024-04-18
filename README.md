# Aplicatie de tip Youtube.

### Descriere:

### Tema 1:
### In acesta prima etapa poti sa te uiti la canalele deja creeate din aplicatia Youtube, poti sa interactionezi cu aceestea dand like si dislike la videoclipurile acestora si sa te abonezi la ele. De asemnea poti sa iti creezi propriul tau canal de Youtube si sa postezi videoclipuri. Acesta canal o sa apara in lista de canale din aplicatia YouTube, de asemenea acesta poate fi modificat de utilizator(Nume canal, nume proprietar, descriere noua). In plus, poti sa descarci n-videoclipuri (citirea si afisarea a n obiecte).

### Tema 2:
### Pentru a doua etapa am extins clasa Video cu doua clase derivate numite SponsoredVideo si Livestream, iar din acesta doua am facut o mostenire in diamant pentru clasa SponsoredLivestream care mosteneste SponsoredVideo si Livestream. Am facut o clasa abstracta numita Content pe care o mosteneste clasa Video, iar functia pur virtuala este show care afiseaza mai multe detalii despre videoclip, livestream, etc...
## Cerințe obligatorii 

Nerespectarea duce la nepunctarea proiectului

- programul va fi scris în C++
- programul va avea un meniu interactiv (doar pentru ilustrarea funcționalității)
- programul nu are erori de compilare
- programul nu are warning-uri (folosind -Wall)
- existența a minim un punct din fiecare cerință
- fară variabile globale
- datele membre private
- fara headere specifice unui sistem de operare (<windows.h>)
- teste unitare pentru cerințele implementate (unde se poate, dacă nu apar probleme cu setup-ul de teste 😅)

## Tema 1

#### Cerințe
- [x] definirea a minim **2-3 clase** care sa interactioneze in cadrul temei alese (fie prin compunere, agregare sau doar sa apeleze metodele celeilalte intr-un mod logic) (5p)
  - pentru o clasă:
    - [x] constructori de inițializare
    - [x] constructor supraîncărcat
    - [x] constructori de copiere
    - [x] `operator=` de copiere
    - [x] destructor
    - [x] `operator<<` pentru afișare (std::ostream)
    - [x] `operator>>` pentru citire (std::istream)
    - [x] alt operator supraîncărcat ca funcție membră
    - [x] alt operator supraîncărcat ca funcție non-membră
  - pentru celelalte clase se va definii doar ce e nevoie
- [x] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe (3p)
- nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector 
- [x] scenariu de utilizare a claselor definite (1p):
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [x] opțiune pentru citirea și afișarea a n obiecte (1p)

## Recomandare Tema

* rezolvați tema 1 cu niște itemi generali ca să puteți extinde tema cu ușurință la următoarele teme.
  - coș de cumpărături + produse
  - sistem de validare a documentelor + documente de identitate
  - sistem de gestionare a biletelor + bilet 
* funcționalitatea creată să folosească metode ale obiectului generic 
* ar fi bine ca relația de agregare să fie făcută cu un obiect general în stilul celor de mai sus ^
* branch-uri + commit-uri punctuale

### Tema 2

#### Cerințe
- [x] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp` [(0.25p)](https://github.com/Ionnier/poo/tree/main/proiect/P01#separarea-implement%C4%83rii-metodelor-din-clase)
- [x] cât mai multe `const` [(0.25p)](https://github.com/Ionnier/poo/tree/main/labs/L04#reminder-const-everywhere)
- [x] moșteniri [(5p)](https://github.com/Ionnier/poo/tree/main/labs/L04#exemplu):
- [x] minim o clasă de bază și **2 clase derivate**
- [x] încercați să derivați o clasă creată anterior
- dacă nu reușiți
     - creați o altă clasă care poate fi integrată cu clasele anterioare
     - menționați de ce nu ați reușit și ce ați încercat
- [x] ilustrați [upcast](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding)-ul și [downcast](https://github.com/Ionnier/poo/tree/main/labs/L04#smarter-downcast-dynamic-cast)-ul folosind funcții virtuale și pointeri la clasa de bază
- aceasta va fi făcută prin **2-3** metode specifice temei alese
- funcțiile pentru citire / afișare sau destructorul nu sunt incluse deși o să trebuiască să le implementați
- [x] apelarea constructorului din clasa de bază din [constructori din derivate](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-la-derivare)
- [x] suprascris [cc](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-de-copiere-la-derivare)/op= pentru copieri/atribuiri corecte
- [x] destructor [virtual](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding)
- [x] funcții și atribute `static` (în clase) [(1p)](https://github.com/Ionnier/poo/tree/main/labs/L04#static)
- [x] excepții [(1p)](https://github.com/Ionnier/poo/tree/main/labs/L04#exception-handling)
  - porniți de la `std::exception`
  - ilustrați propagarea excepțiilor
  - ilustrati upcasting-ul în blocurile catch
  - minim folosit într-un loc în care tratarea erorilor în modurile clasice este mai dificilă
- [x] folosirea unei clase abstracte (fie la exceptii, fie la moșteniri) [(0.5p)](https://github.com/Ionnier/poo/tree/main/labs/L04#clase-abstracte)
- [x] actualizarea meniului & scenariului de utilizare [(0.5p)](https://github.com/Ionnier/oop-template-t1/blob/main/main.cpp#L16)
- [x] citirea și afișarea a n obiecte [(0.5p)](https://github.com/Ionnier/oop-template-t1/blob/main/main.cpp#L13)
  - poate fi combinat cu demonstrarea upcasting-ului & downcast-ului printr-un vector către o clasă de bază
  - poate fi făcut oriunde (dacă aveți deja o clasă cu un vector, de exemplu o clasă Coș cu un vector<Produs>)
- [ ] existența unui pull request către branch-ul în care lucrați ce include adăugarea unei noi derivate ce evidențiază că modificările aduse sunt minimale (0.5p)
  - derivata nu poate fi una ștearsă și rescrisă
  - derivata va avea date membre noi + o modificare de comportament pe una dintre funcțiile virtuale

## Recomandare Tema

* rezolvați tema 1 cu niște itemi generali ca să puteți extinde tema cu ușurință la următoarele teme.
