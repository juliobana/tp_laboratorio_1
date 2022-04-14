/*
 * pedirDatos.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Julio
 */


#include <stdio.h>
#include <stdlib.h>
#include "pedirDatos.h"

/// @brief Funcion pide numero entero y valida el mismo
/// @param pNumeroIngresado
/// @param mensaje
/// @param mensajeError
/// @param maximo
/// @param minimo
/// @param maximoDeReintentos
/// @return 0 si esta OK. -1 si algo no salio bien
	int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
			int maximo, int minimo, int maximoDeReintentos){

		int auxNumeroIngresado;
		int retorno;
		retorno = -1;

		if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
			do{
				printf("%s", mensaje);
				scanf("%d", &auxNumeroIngresado);
				maximoDeReintentos--;

				if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
							*pNumeroIngresado = auxNumeroIngresado;
							retorno = 0;
							break;
				}else{
					printf("%s", mensajeError);
				}

			}while(maximoDeReintentos > 0);
		}

		return retorno;
}



	/// @brief Funcion pide caracter y valida el mismo
	/// @param pResultado
	/// @param mensaje
	/// @param mensajeError
	/// @param maximo
	/// @param minimo
	/// @param maximoDeReintentos
	/// @return 0 si esta OK. -1 si algo no salio bien

	int getCaracter(char * pResultado,char * mensaje,char * mensajeError, char maximo, char minimo, int maximoDeReintentos){

			int auxCharacterIngresado;
			int retorno;
			retorno = -1;

			if(pResultado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
				do{
					printf("%s", mensaje);
					scanf("%c", &auxCharacterIngresado);
					maximoDeReintentos--;

					if(auxCharacterIngresado >= minimo && auxCharacterIngresado <= maximo){
								*pResultado = auxCharacterIngresado;
								retorno = 0;
								break;
					}else{
						printf("%s", mensajeError);
					}

				}while(maximoDeReintentos >= 0);
			}

			return retorno;
	}
