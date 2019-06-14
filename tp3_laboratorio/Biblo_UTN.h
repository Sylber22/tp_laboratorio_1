#ifndef BIBLO_UTN_H_INCLUDED
#define BIBLO_UTN_H_INCLUDED
int getInt(int* pResultado, char* msg, char* msgError);
int getFloat(float* pResultado, char* msg, char* msgError);
int getChar(char* pResultado,char* msg, char* msgError);
char getNumeroAleatorio(int desde , int hasta, int iniciar);
//--------------------------------
int esSoloLetras(char* str);
int esNumerico(char *str);
int esTelefono(char* str);
int esAlfaNumerico(char *str);
int esNumericoFlotante(char* str);
//--------------------------------
int getString(char *pResultado, char* msg);
int getStringLetras(char* pResultado, char* msg, char* msgError,int reintentos);
int getTelefono(char* pResultado, char* msg, char* msgError,int reintentos);
//--------------------------------
void cleanStdin(void);
int menu();
//--------------------------------

#endif // BIBLO_UTN_H_INCLUDED
