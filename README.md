# Descriere tema:
## Etapa 1:
### Pentru etapa 1 am facut o aplicatie de tip Youtube in care poti sa vizitezi(si sa te abonezi/dezabonezi) diverse canale si sa dai like sau dislike la videoclipurile acestora. De asemnea poti sa iti creezi propriul tau canal si sa postezi videoclipuri. Pentru citire si afisarea a n obiecte am implementat optiunea de a descarca videoclipuri.
## Etapa 2:
### Pentru etapa 2 am derivat clasa de baza Video care facea parte si din prima etapa a proiectului, in doua clase copil numite SponsoredVideo si Livestream, care acestea la rand lor sunt mostenite in diamant de catre SponsoredLivestream. Clasa abstracta este Content si este mostenita de catre Video. 
### Branch-ul cu derivata Shorts:
### Am facut un obiect de tip shorts si l-am adaugat folosind downcasting in videoclipurile canalului 1. De asemenea am adaugat optiunea in meniu sa creezi un short de la tastatura si imediat dupa programul sa il afiseze ca sa arat ca toate functiile clasei adaugate Shorts merg cum trebuie
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
- folosirea a funcționalităților limbajului fără sens
- folosirea a funcționlităților limbajului cu scopul de a încălca "legal" o altă regulă
    - folosirea excesivă a claselor friend
    - folosirea excesviă a elementelor statice  

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
     - [x] existența unui pull request către branch-ul în care lucrați ce include adăugarea unei noi derivate ce evidențiază că modificările aduse sunt minimale (0.5p)
- derivata nu poate fi una ștearsă și rescrisă
- derivata va avea date membre noi + o modificare de comportament pe una dintre funcțiile virtuale

### Tema 3

#### Cerințe
 - Clase template (3p)
   - [ ] crearea unei ierarhii de clase template cu minim 2 clase
   - [ ] ilustrarea RTTI pe clase template
   - [ ] instanțieri cu logică a claselor create
 - STL (2p)
   - [ ] utilizarea a două structuri (containere) din (fără <vector>)
   - [ ] utilizarea a unui algoritm cu funcție lambda (de exemplu, sort, transform)
 - Design Patterns (2p)
   - [ ] utilizarea a două șabloane de proiectare
 - Prezentare (3p)
   - [ ] răspunsuri la întrebări din cod / generale C++
   - [ ] explicarea a unei alte structuri sau a altui algoritm neutilizat (STL)
   - [ ] explicarea a altor două șabloane de proiectare


## Recomandare Tema

* rezolvați tema 1 cu niște itemi generali ca să puteți extinde tema cu ușurință la următoarele teme.
  - coș de cumpărături + produse
  - sistem de validare a documentelor + documente de identitate
  - sistem de gestionare a biletelor + bilet 
* funcționalitatea creată să folosească metode ale obiectului generic 
* ar fi bine ca relația de agregare să fie făcută cu un obiect general în stilul celor de mai sus ^
* branch-uri + commit-uri punctuale
