#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

int getValidInt(char* msg,char* msgError, int lowLimit, int hiLimit);
float getValidFloat(char* msg, char* msgError, int lowLimit, int hiLimit);

int getStringAlpha(char* pResultado, char* msg, char* msgError, int reintentos);
int getStringNumeros(char* pResultado,char* msg,char* msgError, int reintentos);
int getStringNumerosFlotantes(char* pResultado,char* msg,char* msgError, int reintentos);
int getStringLetras(char* pResultado, char* msg, char* msgError,int reintentos);

int isValidDate(int day, int month, int year);
//----------------------------------------------
#endif // VALIDACIONES_H_INCLUDED
