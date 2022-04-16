/*
 ============================================================================
 Name        : TP_1.c
 Author      : Julio Baña
 División    : 1 E
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "pedirDatos.h"
#include "realizarCalculos.h"
#define BITCOIN 4606954.55

int main(void) {

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


		printf("                [----BIENVENIDO A SARLANGA VIAJES----] \n\n");

		do{
			getInt(&opcionNumero, "\n             ##### Ingrese una opción para operar ##### \n\n 1) Ingresar Kilómetros \n 2) Ingresar Precio de Vuelos \n 3) Calcular todos los costos \n 4) Informar Resultados \n 5) Carga forzada de datos \n 6) Salir \n", "El numero ingresado es Erroneo \n\n", 6,1,2 );
			switch (opcionNumero){
				case 1:
					while(retornoKilometros ==-1){
					retornoKilometros = getInt(&kilometrosIngresados,"Ingrese los Kilometros del vuelo: \n","los Kilometros deben ser mayores a 100 \n",1000000, 100, 5);
					}
					printf("La cantidad de kilometros ingresados son : Km %d ",kilometrosIngresados );
					break;
				case 2:
					do{
						printf(" Precios actuales \n Aerolíneas : $ %0.2f  \n Latam      : $ %0.2f \n",precioVueloAerolineas, precioVueloLatam);
						getInt(&menuAerolinea, "\n    ##### Ingrese opción deseada :  1) Aerolíneas  2) Latam  3) Salir de Menu precios  #####", "¡ERROR! selecione opcion correcta... \n\n", 3,1,2 );

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

						precioBitcoinAerolineas= precioBitcoinAerolineas/BITCOIN;
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

						precioBitcoinLatam= precioBitcoinLatam/BITCOIN;

						//e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
						calculoDiferenciaEntreDosNumeros(precioSinDescuentoAerolineas, precioSinDescuentoLatam,  &diferenciaDePrecios);

						calculos= 0;
						printf("     ##### Calculo de costos realizados ¡exitosamente! ##### \n\n");

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
						printf("c)Precio pagando con bitcoin: %0.2f BTC \n", precioBitcoinAerolineas );
						printf("d)Mostrar precio unitario: $ %0.2f \n\n", precioUnitarioAerolineas);
					}

					if(flagMenuAerolineas ==0 && calculos ==0){

						printf("Precio Latam $ %0.2f \n", precioSinDescuentoLatam );
						printf("a)Precio con tarjeta debito: $ %0.2f \n", precioTarjetaDebitoLatam );
						printf("b)Precio con tarjeta credito: $ %0.2f \n", precioTarjetaCreditoLatam );
						printf("c)Precio pagando con bitcoin: %0.2f BTC \n", precioBitcoinLatam );
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

						precioBitcoinAerolineas= precioBitcoinAerolineas/BITCOIN;

						printf("Precio Aerolineas $ %0.2f \n", precioSinDescuentoAerolineas );
						printf("a)Precio con tarjeta debito: $ %0.2f \n", precioTarjetaDebitoAerolineas );
						printf("b)Precio con tarjeta credito: $ %0.2f \n", precioTarjetaCreditoAerolineas );
						printf("c)Precio pagando con bitcoin: %0.2f BTC \n", precioBitcoinAerolineas );
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

						precioBitcoinLatam= precioBitcoinLatam/BITCOIN;

						//e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)

						calculoDiferenciaEntreDosNumeros(precioSinDescuentoAerolineas, precioSinDescuentoLatam,  &diferenciaDePrecios);

						printf("Precio Latam $ %0.2f \n", precioSinDescuentoLatam );
						printf("a)Precio con tarjeta debito: $ %0.2f \n", precioTarjetaDebitoLatam );
						printf("b)Precio con tarjeta credito: $ %0.2f \n", precioTarjetaCreditoLatam );
						printf("c)Precio pagando con bitcoin: %0.2f BTC \n", precioBitcoinLatam );
						printf("d)Mostrar precio unitario: $ %0.2f \n\n", precioUnitarioLatam);
						printf("La diferencia de precio es: $ %0.2f \n", diferenciaDePrecios);

						break;
			}

		}while(opcionNumero != 6);

		printf("##### Ah salido del Sistema... #####");

	}





