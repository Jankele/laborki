#include <stdio.h>
int main (int argc, char **argv)
{
    printf("Uruchomiono%s\n", argv[0]);
    if(argc>1)
    {
        printf("z argumentami:\n");
        for (int i=1;i<argc;i++)
        printf("%d %s\n",i,argv[i]);
    }
    printf("zmiana\n");
    return 0;
}
