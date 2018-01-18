#define LEWA_GALAZ 0
#define PRAWA_GALAZ 1

typedef struct node
{
	char znak;
	int ilosc;
	int valid;
	char *kod;
	struct node *lewa;
	struct node *prawa;
} node;

typedef struct lista
{
	struct node *lisc;
	struct lista *next; 
} lista;

typedef struct entry
{
	char znak;
	int ilosc;
	char *kod;
	struct entry *lewa;
} entry;

extern node *wezel;
extern lista *glowa;
extern entry* glowa_listy;
extern char *tekst_zakodowany;
extern int dlugosc_kodu;

char *czytaj_plik(const char *plik);
void stworz_glowe(char znak);
void dodanie_elementu_na_poczatek_oraz_zliczanie_powtorzen(char znak);
void wyswietl_powtorzenia();
void zloz_liste(int dlugosc, char *tekst);
void sortowanie_listy();
void stworz_drzewo_HF();
void kodowanieHT(node* pom_kontener, char* kodHT, int generacja, int w_ktora_strone);
void usun_drzewo_HF();
void sformatuj_tekst(char *tekst, size_t dlugosc);
void zniszcz_liste();
char *przeszukaj_kod(char fragment);