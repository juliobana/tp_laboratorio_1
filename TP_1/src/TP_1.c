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
#include "realizarCalculos.h"

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
		int menuAerolinea;
		float precioVueloAerolineas=0;
		float precioVueloLatam=0;
		int retornoKilometros=-1;
		float retornoMenuAerolineas=-1;
		int kilometrosIngresados;
		float porcentajeDescuento;
		float porcentajeRecargo;
		float porcentajeRecargoDescuento;
		float bitCoin= 4606954.55;
		float precioTarjetaCredito;
		float precioTarjetaDebito;
		float precioBitcoin;
		float precioUnitario;


		printf("                [----BIENVENIDO SARLANGA VIAJES----] \n\n");


		do{
			getInt(&opcionNumero, "\n             ##### Ingrese un numero para operar ##### \n\n 1) Ingresar Kilómetros \n 2) Ingresar Precio de Vuelos \n 3) Calcular todos los costos \n 4) Informar Resultados \n 5) Carga forzada de datos \n 6) Salir \n", "El numero ingresado es Erroneo \n\n", 6,1,2 );
			switch (opcionNumero){
				case 1:
					while(retornoKilometros ==-1){
					retornoKilometros = getInt(&kilometrosIngresados,"Ingrese los Kilometros del vuelo: \n","los Kilometros deben ser mayores a 100 \n",1000000, 100, 5);
					}
					printf("Los kilometros ingresados es : %d ",kilometrosIngresados );
					break;
				case 2:
					do{
						printf("Precios actuales Aerolíneas : $ %f  Latam : $ %f \n",precioVueloAerolineas, precioVueloLatam);
						getInt(&menuAerolinea, "\n    ##### Ingrese empresa aérea  1) Aerolíneas  2) Latam  3) Salir de Menu precios  #####", "Error al selecione opcion correcta... \n\n", 3,1,2 );

						if(menuAerolinea == 1 ){
							do{
								retornoMenuAerolineas = getFloat(&precioVueloAerolineas,"Ingrese precio del vuelo \n","Error, el valor debe ser mayor a $0 \n",1000000, 0, 2);
								if(retornoMenuAerolineas ==0){
									//flagMenuAerolineas=1;
									}
							}while(retornoMenuAerolineas==-1);
						}

						if(menuAerolinea == 2 ){
							do{
								retornoMenuAerolineas = getFloat(&precioVueloLatam,"Ingrese precio del vuelo \n","Error, el valor debe ser mayor a $0 \n",1000000, 0, 2);
								if(retornoMenuAerolineas ==0){
									//flagMenuAerolineas=1;
									}
							}while(retornoMenuAerolineas==-1);
						}

					}while(menuAerolinea!=3);

					break;

				case 3:
					precioTarjetaCredito = precioVueloAerolineas;
					precioTarjetaDebito = precioVueloAerolineas;
					precioBitcoin = precioVueloAerolineas;
					precioUnitario = precioVueloAerolineas;

					printf("Linea aérea Aerolineas \n");
					// a) Tarjeta de débito (descuento 10%)
					porcentajeRecargoDescuento=0.10;
					calculoPorcentaje(precioTarjetaCredito, porcentajeRecargoDescuento,&porcentajeDescuento);
					precioTarjetaCredito = precioTarjetaCredito - porcentajeDescuento;
					printf("a)Precio con tarjeta debito: $ %0.2f \n",precioTarjetaCredito);

					//b) Tarjeta de crédito (interés 25%)
					porcentajeRecargoDescuento=0.25;
					calculoPorcentaje(precioTarjetaDebito, porcentajeRecargoDescuento,&porcentajeRecargo);
					precioTarjetaDebito = precioTarjetaDebito + porcentajeRecargo;
					printf("b)Precio con tarjeta credito: $ %0.2f \n",precioTarjetaDebito);

					//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)

					precioBitcoin= precioBitcoin/bitCoin;
					printf("c)Precio pagando con Bitcoin: %0.2f BTC \n",precioBitcoin);

					//d) Mostrar precio por km (precio unitario)

					printf("d)Mostrar precio unitario: $ %0.2f \n",precioUnitario);

					printf("Linea aérea Latam \n");
					//e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)

					break;
				case 4:

						break;

				case 5:

						break;

			}
		}while(opcionNumero != 6);

		printf("Ah salido del Sistema");

		}





