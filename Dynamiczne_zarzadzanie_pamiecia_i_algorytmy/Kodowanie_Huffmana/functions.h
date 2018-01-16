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
void push_front_and_count(char znak, lista **glowa);
void stworz_drzewo_HF();
void usun_drzewo_HF();
void wyswietl_powtorzenia(lista **glowa);
void kodowanie_HF();