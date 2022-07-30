#ifdef __modelagem__
void ler_entrada(int n, int demanda[], int afluencia[], float hidro[], float termo[]);
void print_entrada(int n, int demanda[], int afluencia[], float hidro[], float termo[]);
void print_func_obj(int entrada);
void print_hidro(int entrada, float ca, float termo);
void print_restricoes(int entrada, float termo[], float hidro[], float hidroV, int demanda[]);
void print_volume(int entrada, int afluencia[]);
void print_lp(int entrada, float ca, int afluencia[], float termo[], float hidro[], float termoV, float hidroV, int demanda[]);
#endif