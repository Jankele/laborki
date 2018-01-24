#define LEWA_GALAZ '0' //znak podstawiany podczas kodowania przy przejsciu na lewa galaz
#define PRAWA_GALAZ '1' //znak podstawiany podczas kodowania przy przejsciu na prawa galaz
typedef struct node // struktura reprezentujaca lisc
{
    char znak;
    int ilosc;
    int gotowy;
    char *kod;
    struct node *lewa;
    struct node *prawa;
} node;

typedef struct lista
{
    struct node *lisc;
    struct lista *next; 
} lista;

extern lista* glowa; //glowa listy znakow z pliku
extern node* wezel;
extern node* glowa_listy; //glowa listy pozycji z listy znakow do kodowania

char* czytaj_plik(const char* plik); // funkcja wczytuje zawartosc pliku
void stworz_glowe(char znak); //funkcja tworzy glowe listy znakow z pliku
void stworz_liste_powtorzen(int dlugosc, char* tekst); //funkcja tworzy liste znakow z pliku
void sortowanie_listy(char a); // '0' = funkcja sortuje liste znakow z pliku, else = sortuje liste pozycji z listy znakow do kodowania w celu wyswietlenia na ekranie pozycji posortowanych wg ilosci wystapien
void stworz_drzewo_HF(); // funkcja tworzy strukture drzewiasta z listy znakow z pliku
void kodowanieHT(node* galaz, char* kodHT, int generacja, char w_ktora_strone, int *dlugosc_kodu); // funkcja tworzy kod huffmana z pozycji w drzewie
void zbuduj_kod(char *zakodowany_tekst, char *tekst); // laczy pojedyncze kody w wynikowy ciag kodu calej zawartosci pliku
void sformatuj_tekst(char *tekst, size_t dlugosc); // funkcja wypisuje na stdout podany tekst, i dodaje do niego znaki ktore poprawiaja wyglad programu
void stopien_kompresji(int dlugosc, int dlugosc_kodu); // wylicza stopien kompresji - ratio KOMPRESJA : 1
void wyswietl(char a); // '0' = wyswietla ilosc powtorzen danego znaku, else = wyswietla kod przypisany danemu znakowi
void usun_drzewo_HF(node* galaz); // funkcja zwalnia pamiec drzewa
void posprzataj(char *tekst, char *zakodowany_tekst); //funkcja zwalniajaca cala zaalokowana pamiec

