
typedef struct ListaOrdenada ListaOrdenada;

ListaOrdenada* create(int n);

int add(ListaOrdenada* lo, int e);

int remover(ListaOrdenada* lo, int valor);

int size(ListaOrdenada* lo);

int linearSearch(ListaOrdenada* lo, int e);

int bynarySearch(ListaOrdenada* lo, int e);

void printAll(ListaOrdenada* lo);

int isFull(ListaOrdenada* lo);

int isEmpty(ListaOrdenada* lo);

void clear(ListaOrdenada* lo);


