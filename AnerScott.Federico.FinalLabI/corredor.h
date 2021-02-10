#include "LinkedList.h"



#ifndef CORREDOR_H_INCLUDED
#define CORREDOR_H_INCLUDED

 typedef  struct{

int id_corredor;
char apellido[20];
char tipo[20];
float promedio;
float tiempo;


}eCorredor;


#endif // CORREDOR_H_INCLUDED

eCorredor* corredor_new();
eCorredor* corredor_newParametros(char* idStr,char* apellidoStr,char* tipoStr,char* promedioStr,char* tiempoStr);
int corredorSetId( eCorredor* corredor, int id);
int corredorGetId( eCorredor* corredor, int* id);
int corredorSetApellido( eCorredor* corredor, char* apellido);
int corredorGetApellido( eCorredor* corredor, char* apellido);
int corredorSetTipo(eCorredor* corredor, char* tipo);
int corredorGetTipo(eCorredor* corredor, char* tipo );
int corredorSetPromedio(eCorredor* corredor, float promedio);
int corredorGetPromedio(eCorredor* corredor, float* promedio);
int corredorSetTiempo(eCorredor* corredor, float tiempo);
int corredorGetTiempo(eCorredor* corredor, float* tiempo);
void mostrarCorredor (LinkedList* lista, int index);
int mostrarCorredores(LinkedList* pArraylist);
void* asignarTiempo(void* corredor);
int OrdenarPosiciones(void* a, void* b);












