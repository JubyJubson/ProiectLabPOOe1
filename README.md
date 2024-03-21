# Aplicatie de tip Youtube.

### Descriere:
### In acesta prima etapa poti sa te uiti la canalele deja creeate din aplicatia Youtube, poti sa interactionezi cu aceestea dand like si dislike la videoclipurile acestora si sa te abonezi la ele. De asemnea poti sa iti creezi propriul tau canal de Youtube si sa postezi videoclipuri. Acesta canal o sa apara in lista de canale din aplicatia YouTube, de asemenea acesta poate fi modificat de utilizator(Nume canal, nume proprietar, descriere noua). In plus, poti sa descarci n-videoclipuri (citirea si afisarea a n obiecte).

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
