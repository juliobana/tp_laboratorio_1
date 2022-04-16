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
		int flagMenuAerolineas=-1;
		int flagMenuLatam=-1;
		int opcionNumero;
		int menuAerolinea;
		float precioVueloAerolineas=0;
		float precioVueloLatam=0;
		int retornoKilometros=-1;
		float retornoMenu=-1;
		int kilometrosIngresados;
		float porcentajeDescuento;
		float porcentajeRecargo;
		float porcentajeRecargoDescuento;
		float bitCoin= 4606954.55;

		float precioTarjetaDebitoAerolineas;
		float precioTarjetaCreditoAerolineas;
		float precioBitcoinAerolineas;
		float precioUnitarioAerolineas;

		float precioTarjetaDebitoLatam;
		float precioTarjetaCreditoLatam;
		float precioBitcoinLatam;
		float precioUnitarioLatam;
		float calculos=-1;


		float precioTotalPorKilometros;
		float precioSinDescuentoAerolineas;
		float precioSinDescuentoLatam;
		float diferenciaDePrecios;


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
						printf("Precios actuales Aerolíneas : $ %0.2f  Latam : $ %0.2f \n",precioVueloAerolineas, precioVueloLatam);
						getInt(&menuAerolinea, "\n    ##### Ingrese empresa aérea  1) Aerolíneas  2) Latam  3) Salir de Menu precios  #####", "Error al selecione opcion correcta... \n\n", 3,1,2 );

						if(menuAerolinea == 1 ){
							do{
								retornoMenu = getFloat(&precioVueloAerolineas,"Ingrese precio del vuelo \n","Error, el valor debe ser mayor a $0 \n",1000000, 0, 2);
								if(retornoMenu ==0){
									flagMenuAerolineas=0;
									}
							}while(retornoMenu==-1);
						}

						if(menuAerolinea == 2 ){
							do{
								retornoMenu = getFloat(&precioVueloLatam,"Ingrese precio del vuelo \n","Error, el valor debe ser mayor a $0 \n",1000000, 0, 2);
								if(retornoMenu ==0){
									flagMenuLatam=0;
									}
							}while(retornoMenu==-1);
						}

					}while(menuAerolinea!=3);

					break;

				case 3:

					if(flagMenuAerolineas ==0){

						precioTotalPorKilometros= precioVueloAerolineas * (float)kilometrosIngresados;
						precioSinDescuentoAerolineas= precioTotalPorKilometros;

						precioTarjetaDebitoAerolineas = precioTotalPorKilometros;
						precioTarjetaCreditoAerolineas = precioTotalPorKilometros;
						precioBitcoinAerolineas = precioTotalPorKilometros;
						precioUnitarioAerolineas = precioTotalPorKilometros;

						// a) Tarjeta de débito (descuento 10%)
						porcentajeRecargoDescuento=0.10;
						calculoPorcentaje(precioTarjetaDebitoAerolineas, porcentajeRecargoDescuento,&porcentajeDescuento);
						precioTarjetaDebitoAerolineas = precioTarjetaDebitoAerolineas - porcentajeDescuento;


						//b) Tarjeta de crédito (interés 25%)
						porcentajeRecargoDescuento=0.25;
						calculoPorcentaje(precioTarjetaCreditoAerolineas, porcentajeRecargoDescuento,&porcentajeRecargo);
						precioTarjetaCreditoAerolineas = precioTarjetaCreditoAerolineas + porcentajeRecargo;


						//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)

						precioBitcoinAerolineas= precioBitcoinAerolineas/bitCoin;

						calculos= 0;
					}

					if(flagMenuLatam==0){

						precioTotalPorKilometros= precioVueloLatam * (float)kilometrosIngresados;
						precioSinDescuentoLatam = precioTotalPorKilometros;

						precioTarjetaDebitoLatam = precioTotalPorKilometros;
						precioTarjetaCreditoLatam = precioTotalPorKilometros;
						precioBitcoinLatam = precioTotalPorKilometros;
						precioUnitarioLatam = precioTotalPorKilometros;

						// a) Tarjeta de débito (descuento 10%)
						porcentajeRecargoDescuento=0.10;
						calculoPorcentaje(precioTarjetaDebitoLatam, porcentajeRecargoDescuento,&porcentajeDescuento);
						precioTarjetaDebitoLatam = precioTarjetaDebitoLatam - porcentajeDescuento;

						//b) Tarjeta de crédito (interés 25%)
						porcentajeRecargoDescuento=0.25;
						calculoPorcentaje(precioTarjetaCreditoLatam, porcentajeRecargoDescuento,&porcentajeRecargo);
						precioTarjetaCreditoLatam = precioTarjetaCreditoLatam + porcentajeRecargo;

						//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)

						precioBitcoinLatam= precioBitcoinLatam/bitCoin;

						//e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
						calculoDiferenciaEntreDosNumeros(precioSinDescuentoAerolineas, precioSinDescuentoLatam,  &diferenciaDePrecios);

						calculos= 0;

					}

					if (flagMenuAerolineas==-1 || flagMenuLatam==-1){

							printf("##### ¡ATENCION! Para operar debe ingresar primero los precios y Kilometros de las aérolineas ##### ");
					}
					break;
				case 4:

					if (flagMenuAerolineas==-1 || flagMenuLatam==-1){

												printf("##### ¡ATENCION! Para operar debe ingresar primero los precios y Kilometros de las aérolineas ##### ");
					}

					if(flagMenuAerolineas ==0 && calculos ==0){

						printf("Precio Aerolineas $ %0.2f \n", precioSinDescuentoAerolineas );
						printf("a)Precio con tarjeta debito: $ %0.2f \n", precioTarjetaDebitoAerolineas );
						printf("b)Precio con tarjeta credito: $ %0.2f \n", precioTarjetaCreditoAerolineas );
						printf("c)Precio pagando con Bitcoin: %0.2f BTC \n", precioBitcoinAerolineas );
						printf("d)Mostrar precio unitario: $ %0.2f \n\n", precioUnitarioAerolineas);
					}

					if(flagMenuAerolineas ==0 && calculos ==0){

						printf("Precio Latam $ %0.2f \n", precioSinDescuentoLatam );
						printf("a)Precio con tarjeta debito: $ %0.2f \n", precioTarjetaDebitoLatam );
						printf("b)Precio con tarjeta credito: $ %0.2f \n", precioTarjetaCreditoLatam );
						printf("c)Precio pagando con Bitcoin: %0.2f BTC \n", precioBitcoinLatam );
						printf("d)Mostrar precio unitario: $ %0.2f \n\n", precioUnitarioLatam);
						printf("La diferencia de precio es: $ %0.2f", diferenciaDePrecios);
					}

						break;

				case 5:

						/*
						 KM: 7090
						 Aerolineas Argentinas: $162965
						 Latam: $159339
						 */
						kilometrosIngresados=7090;
						precioVueloAerolineas=162965;
						precioVueloLatam=159339;

						precioTotalPorKilometros= precioVueloAerolineas * (float)kilometrosIngresados;
						precioSinDescuentoAerolineas= precioTotalPorKilometros;

						precioTarjetaDebitoAerolineas = precioTotalPorKilometros;
						precioTarjetaCreditoAerolineas = precioTotalPorKilometros;
						precioBitcoinAerolineas = precioTotalPorKilometros;
						precioUnitarioAerolineas = precioTotalPorKilometros;

						// a) Tarjeta de débito (descuento 10%)
						porcentajeRecargoDescuento=0.10;
						calculoPorcentaje(precioTarjetaDebitoAerolineas, porcentajeRecargoDescuento,&porcentajeDescuento);
						precioTarjetaDebitoAerolineas = precioTarjetaDebitoAerolineas - porcentajeDescuento;


						//b) Tarjeta de crédito (interés 25%)
						porcentajeRecargoDescuento=0.25;
						calculoPorcentaje(precioTarjetaCreditoAerolineas, porcentajeRecargoDescuento,&porcentajeRecargo);
						precioTarjetaCreditoAerolineas = precioTarjetaCreditoAerolineas + porcentajeRecargo;


						//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)

						precioBitcoinAerolineas= precioBitcoinAerolineas/bitCoin;

						printf("Precio Aerolineas $ %0.2f \n", precioSinDescuentoAerolineas );
						printf("a)Precio con tarjeta debito: $ %0.2f \n", precioTarjetaDebitoAerolineas );
						printf("b)Precio con tarjeta credito: $ %0.2f \n", precioTarjetaCreditoAerolineas );
						printf("c)Precio pagando con Bitcoin: %0.2f BTC \n", precioBitcoinAerolineas );
						printf("d)Mostrar precio unitario: $ %0.2f \n\n", precioUnitarioAerolineas);


						// LATAM

						precioTotalPorKilometros= precioVueloLatam * (float)kilometrosIngresados;
						precioSinDescuentoLatam = precioTotalPorKilometros;

						precioTarjetaDebitoLatam = precioTotalPorKilometros;
						precioTarjetaCreditoLatam = precioTotalPorKilometros;
						precioBitcoinLatam = precioTotalPorKilometros;
						precioUnitarioLatam = precioTotalPorKilometros;

						// a) Tarjeta de débito (descuento 10%)
						porcentajeRecargoDescuento=0.10;
						calculoPorcentaje(precioTarjetaDebitoLatam, porcentajeRecargoDescuento,&porcentajeDescuento);
						precioTarjetaDebitoLatam = precioTarjetaDebitoLatam - porcentajeDescuento;

						//b) Tarjeta de crédito (interés 25%)
						porcentajeRecargoDescuento=0.25;
						calculoPorcentaje(precioTarjetaCreditoLatam, porcentajeRecargoDescuento,&porcentajeRecargo);
						precioTarjetaCreditoLatam = precioTarjetaCreditoLatam + porcentajeRecargo;

						//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)

						precioBitcoinLatam= precioBitcoinLatam/bitCoin;

						//e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
						calculoDiferenciaEntreDosNumeros(precioSinDescuentoAerolineas, precioSinDescuentoLatam,  &diferenciaDePrecios);

						printf("Precio Latam $ %0.2f \n", precioSinDescuentoLatam );
						printf("a)Precio con tarjeta debito: $ %0.2f \n", precioTarjetaDebitoLatam );
						printf("b)Precio con tarjeta credito: $ %0.2f \n", precioTarjetaCreditoLatam );
						printf("c)Precio pagando con Bitcoin: %0.2f BTC \n", precioBitcoinLatam );
						printf("d)Mostrar precio unitario: $ %0.2f \n\n", precioUnitarioLatam);
						printf("La diferencia de precio es: $ %0.2f", diferenciaDePrecios);

						break;
			}

		}while(opcionNumero != 6);

		printf("Ah salido del Sistema");

		}





