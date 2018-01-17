typedef struct node
{
	char znak;
	int ilosc;
	char *kod;
	struct node *lewa;
	struct node *prawa;
} node;

typedef struct lista
{
	struct node *lisc;
	struct lista *next; 
} lista;

char *czytaj_plik(const char *plik);
void stworz_glowe(char znak, lista **glowa);
void dodanie_elementu_na_poczatek_oraz_zliczanie_powtorzen(char znak, lista **glowa);
void wyswietl_powtorzenia(lista *glowa);
void sortowanie_listy(lista **glowa);
void stworz_drzewo_HF();
void usun_drzewo_HF(node **wezel);
void kodowanie_HF();
void zloz_liste(int dlugosc, lista **glowa, char *tekst);
void sformatuj_tekst(char *tekst, size_t dlugosc);
void zniszcz_liste(lista **glowa);