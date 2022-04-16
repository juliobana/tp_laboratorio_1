/*
 * pedirDatos.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Julio Baña
 */

#ifndef PEDIRDATOS_H_
#define PEDIRDATOS_H_

int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,int maximo, int minimo, int maximoDeReintentos);

int getCaracter(char * pResultado,char * mensaje,char * mensajeError, char maximo, char minimo, int maximoDeReintentos);

int getFloat(float * pNumeroIngresado,char * mensaje,char * mensajeError,int maximo, int minimo, int maximoDeReintentos);

#endif /* PEDIRDATOS_H_ */
