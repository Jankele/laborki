#define LEWA_GALAZ 0
#define PRAWA 1

typedef struct node
{
	char znak;
	int ilosc, valid;
	char *kod;
	struct node *lewa;
	struct node *prawa;
} node;

typedef struct lista
{
	struct node *lisc;
	struct lista *next; 
} lista;

extern node *wezel;
extern lista *glowa;
extern node* glowa_listy;
extern char *tekst_zakodowany;
extern int dlugosc_kodu;

char *czytaj_plik(const char *plik);
void stworz_glowe(char znak);
void dodanie_elementu_na_poczatek_oraz_zliczanie_powtorzen(char znak);
void wyswietl_powtorzenia();
void zloz_liste(int dlugosc, char *tekst);
void sortowanie_listy();
void stworz_drzewo_HF();
void gen_huff_kod(node* pom_kontener, char* kodHT, int generacja, int w_ktora_strone);
void usun_drzewo_HF();
void sformatuj_tekst(char *tekst, size_t dlugosc);
void zniszcz_liste();