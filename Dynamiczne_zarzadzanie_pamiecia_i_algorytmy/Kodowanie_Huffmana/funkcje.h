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
extern char* zakodowany_tekst;
extern int dlugosc_kodu;

void stworz_glowe(char znak); //funkcja tworzy glowe listy znakow z pliku
char* czytaj_plik(const char* plik); // funkcja wczytuje zawartosc pliku
void dodanie_elementu_na_poczatek_oraz_zliczanie_powtorzen(char znak); //funkcja tworzy liste znakow z pliku
void sortowanie_listy(); // funkcja sortuje liste znakow z pliku
void stworz_drzewo_HF(); // funkcja tworzy strukture drzewiasta z listy znakow z pliku
void kodowanieHT(node* galaz, char* kodHT, int generacja, char w_ktora_strone); // funkcja tworzy kod huffmana z pozycji w drzewie
void wyswietl_powtorzenia(); // wyswietla ilosc powtorzen danego znaku
void wyswietl_kod(); // wyswietla kod przypisany danemu znakowi
void sortowanie_wpisow(); // sortuje liste pozycji z listy znakow do kodowania
char* przeszukaj_kod(char znak); // przekazuje pojedyncze kody do ich pozniejszego polaczenia
void zniszcz_liste(); // funkcja zwalnia pamiec listy
void usun_drzewo_HF(node* galaz); // funkcja zwalnia pamiec drzewa
void zloz_liste(int dlugosc, char *tekst); //funkcja pushuje w petli wszystkie znaki na poczatek listy
void sformatuj_tekst(char *tekst, size_t dlugosc); // funkcja wypisuje na stdout podany tekst, i dodaje do niego znaki ktore poprawiaja wyglad programu
void posprzataj(char *tekst, char *zakodowany_tekst); //funkcja zwalniajaca cala zaalokowana pamiec
void zbuduj_kod(char *zakodowany_tekst, char *tekst); // laczy pojedyncze kody w wynikowy ciag kodu calej zawartosci pliku
void stopien_kompresji(int dlugosc, int dlugosc_kodu); // wylicza stopien kompresji