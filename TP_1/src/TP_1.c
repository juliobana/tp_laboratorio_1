/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "pedirDatos.h"

int main(void) {


	/*
	1. Ingresar Kilómetros: ( km=x)

	2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
	- Precio vuelo Aerolíneas:
	- Precio vuelo Latam:

	3. Calcular todos los costos:
	 a) Tarjeta de débito (descuento 10%)
	 b) Tarjeta de crédito (interés 25%)
	 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
	 d) Mostrar precio por km (precio unitario)
	 e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
	4. Informar Resultados
	“Latam:
	 a) Precio con tarjeta de débito: r
	 b) Precio con tarjeta de crédito: r
	 c) Precio pagando con bitcoin : r
	 d) Precio unitario: r
	 Aerolíneas:
	 a) Precio con tarjeta de débito: r
	 b) Precio con tarjeta de crédito: r
	 c) Precio pagando con bitcoin : r
	 d) Precio unitario: r
	 La diferencia de precio es : r “
	5. Carga forzada de datos
	6. Salir

*/


	setbuf(stdout,NULL);
		int opcionNumero;
		int kiliometrosIngresados;
		int precioDelVuelo;
		int menuAerolinea;
		int saldoParcial=0;
		int aux= -1;
		int precioVueloAerolineas=0;
		int precioVueloLatam=0;
		//int precioVueloLatam;
		int flag;

		int dineroIngresado;
		//int flagMenuAerolineas=0;
		//int flagMenuLatam=0;
		int dineroRetirado=0;
		char deseaContinuar;
		int retornoKilometros=-1;
		int retornoMenuAerolineas=-1;
		int retornoMenuPrecios;
		int kilometrosIngresados;

		int catidadDeDineroparaRetirar;
		printf("                [----BIENVENIDO SARLANGA VIAJES----] \n\n");


		do{
			getInt(&opcionNumero, "\n             ##### Ingrese un numero para operar ##### \n\n 1) Ingresar Kilómetros \n 2) Ingresar Precio de Vuelos \n 3) Calcular todos los costos \n 4) Informar Resultados \n 5) Carga forzada de datos \n 6) Salir \n", "El numero ingresado es Erroneo \n\n", 4,1,2 );
			switch (opcionNumero){
				case 1:
					while(retornoKilometros ==-1){
					retornoKilometros = getInt(&kilometrosIngresados,"Ingrese los Kilometros del vuelo: \n","los Kilometros deben ser mayores a 100 \n",1000000, 100, 5);
					}
					printf("Los kilometros ingresados es : %d ",kilometrosIngresados );
					break;
				case 2:
					do{
						printf("Precios actuales Aerolíneas : $ %d  Latam : $ %d \n",precioVueloAerolineas, precioVueloLatam);
						retornoMenuPrecios= getInt(&menuAerolinea, "\n    ##### Ingrese empresa aerea - 1) Aerolíneas  2) Latam  3) Salir de Menu precios  #####", "Error al selecione opcion correcta... \n\n", 3,1,2 );

						if(menuAerolinea == 1 ){
							do{
								retornoMenuAerolineas = getInt(&precioVueloAerolineas,"Ingrese precio del vuelo \n","Error, el valor debe ser mayor a $0 \n",1000000, 0, 2);
								if(retornoMenuAerolineas ==0){
									//flagMenuAerolineas=1;
									}
							}while(retornoMenuAerolineas==-1);
						}

						if(menuAerolinea == 2 ){
							do{
								retornoMenuAerolineas = getInt(&precioVueloLatam,"Ingrese precio del vuelo \n","Error, el valor debe ser mayor a $0 \n",1000000, 0, 2);
								if(retornoMenuAerolineas ==0){
									//flagMenuAerolineas=1;
									}
							}while(retornoMenuAerolineas==-1);
						}

					}while(menuAerolinea!=3);

					break;

				case 3:

					if(flag== 1 ){
						getInt(&dineroIngresado, "\n    ##### Ingrese a la cuenta el monto dinero deseado ##### \n", "La cantidades permitidas es de $100 a $10000 \n\n", 10000,100,2 );
						}
					saldoParcial = kiliometrosIngresados + dineroIngresado;
					printf("\n  dinero  a ingresado:  $ %d", dineroIngresado);
					break;

				case 4:

						break;

				case 5:

						break;




			}
		}while(deseaContinuar != 's');

		printf("Ah salido del Sistema");

		}





