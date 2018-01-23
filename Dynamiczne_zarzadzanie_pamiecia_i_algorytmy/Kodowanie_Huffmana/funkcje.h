#define LEWA_GALAZ '0'
#define PRAWA_GALAZ '1'

typedef struct node
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

extern lista* glowa;
extern node* wezel;
extern node* glowa_listy;
extern char* zakodowany_tekst;
extern int dlugosc_kodu;

void stworz_glowe(char znak);
char* czytaj_plik(const char* plik);
void dodanie_elementu_na_poczatek_oraz_zliczanie_powtorzen(char znak);
void sortowanie_listy();
void stworz_drzewo_HF();
void kodowanieHT(node* galaz, char* kodHT, int generacja, char w_ktora_strone);
void wyswietl_powtorzenia();
void wyswietl_kod();
void sortowanie_wpisow();
char* przeszukaj_kod(char znak);
void zniszcz_liste();
void usun_drzewo_HF(node* galaz);
void zloz_liste(int dlugosc, char *tekst);
void sformatuj_tekst(char *tekst, size_t dlugosc);
void posprzataj(char *tekst, char *zakodowany_tekst);
void zbuduj_kod(char *zakodowany_tekst, char *tekst);