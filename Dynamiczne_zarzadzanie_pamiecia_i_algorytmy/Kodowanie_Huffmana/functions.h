typedef struct node
{
	char znak;
	int ilosc;
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
void usun_drzewo_HF();
void kodowanie_HF();