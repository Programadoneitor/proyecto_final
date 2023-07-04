#include<stdio.h>

int main() {
	float carga_vehiculo, peso_promedio, edad_bovinos, produccion_leche, venta_leche;
	int numerobovinos_brown, numerobovinos_holstein, numerobovinos_jersey, numerobovinos_llevar, raza_bovinos, totalpeso_bovinos;
	printf("Bienvenido al programa de recomendaciones y resultados de posibles produccion y venta de leche.\n");
	printf("Se solicitaran unos datos, tanto de la raza y edad de las vacas, la capacidad de carga del vehiculo, el numero de vacas que se encuentran en venta por favor tener estos datos.\n");
	do {
		printf("Ingrese la capacidad de carga de su camion en kilogramos\n");
		scanf("%f",&carga_vehiculo);
		if (carga_vehiculo<3500) {
			printf("La capacidad del vehiculo es muy baja, vuelva a ingresar.\n");
		}
	} while (carga_vehiculo<3500);
	do {
		printf("Elija la raza de los bovinos a comprar, las razas holstein y bronw swis suelen ser mas pesadas que la jersey, se reduce las opciones a solo tres ya que estas son las recomendadas para la produccion de leche.\n");
		printf("1.- Raza Holstein.\n");
		printf("2.- Raza Brown swiss.\n");
		printf("3.- Raza Jersey.\n");
		printf("4.- Terminar\n");
		scanf("%i",&raza_bovinos);
		switch (raza_bovinos) {
		case 1:
		// aqui se pide la informacion de los bovinos controlando que ingrese datos reales y que no sean negativos, lo mismo es en todas las opciones
			do {
				printf("Cuantas vacas de esta raza se encuentran disponibles para la compra.\n");
				scanf("%i",&numerobovinos_holstein);
				if (numerobovinos_holstein<=0) {
					printf("Dato ingresado no valido.\n");
				}
			} while (numerobovinos_holstein<=0);
			do {
				printf("En promedio cuantos litros de leche produce esta raza al dia?\n");
				scanf("%f",&produccion_leche);
				if (produccion_leche>30 || produccion_leche<18) {
					printf("Los valores estan saliendo de lo real o el bovino se encuentra con graves problemas de salud, se recomienda no comprar, en cualquier caso vuelva a ingresar un valor valido.\n");
				}
			} while (!(produccion_leche>=18 && produccion_leche<=30));
			produccion_leche = (produccion_leche*1.030);
			// se hace la transformacion de litros a kilogramos ya que la informacion y datos investigados proporcionan en kilogramos por lo que para las comprobaciones se haran en kilogramos, lo mismo pasa en todas las opciones.
			do {
				printf("Cual es el peso promedio en kilogramos de los bovinos.\n");
				scanf("%f",&peso_promedio);
				if (peso_promedio<410 || peso_promedio>680) {
					printf("Los valores se encuentran fuera de lo real para una vaca o se encuentran con problemas graves de salud, no comprar, en cualquier caso vuelva a ingresar un peso valido.\n");
				}
			} while (!(peso_promedio>=410 && peso_promedio<=680));
			do {
				printf("Cual es la edad en meses de los bovinos.\n");
				scanf("%f",&edad_bovinos);
				if (edad_bovinos<0 || edad_bovinos>120) {
					printf("Los datos ingresados son irreales o incorrectos, verifique.\n");
				}
			} while (!(edad_bovinos>0 && edad_bovinos<120));
			// se empieza hacer las comprobaciones tanto de, cuando se encuentra con pesos y producciones bajos como cuando salen de datos reales.
			if (edad_bovinos<18) {
				printf("Los bovinos son muy jovenes por lo tanto no han estado preniadas y no producira mucha leche, se recomienda no comprar.\n");
			} else {
				if (edad_bovinos>90) {
					printf("Los bovinos son muy viejos no tendra mucho tiempo de vida util, se recomienda no comprar.\n");
				} else {
					if (edad_bovinos>=18 && edad_bovinos<=20 && peso_promedio>400 && peso_promedio<=430) {
						printf("Los bovinos se encuentran bajo de peso, se recomienda no comprar.\n");
					} else {
						if (edad_bovinos>20 && edad_bovinos<=30 && peso_promedio>=430 && peso_promedio<500 && produccion_leche<19) {
							printf("Los bovinos se encuentran bajo de peso y/o baja produccion de leche, se recomienda no comprar.\n");
						} else {
							if (edad_bovinos>30 && edad_bovinos<=40 && peso_promedio>=500 && peso_promedio<550 && produccion_leche<20) {
								printf("Los bovinos se encuentran bajo de peso y/o baja produccion de leche, se recomienda no comprar.\n");
							} else {
								if (edad_bovinos>40 && edad_bovinos<=50 && peso_promedio>=550 && peso_promedio<610 && produccion_leche<21) {
									printf("Los bovinos se encuentran bajo de peso y/o baja produccion de leche, se recomienda no comprar.\n");
								} else {
									if (edad_bovinos>50 && edad_bovinos<=90 && peso_promedio>=610 && peso_promedio<670 && produccion_leche<22) {
										printf("Los bovinos se encuentran bajo de peso y/o baja produccion de leche, se recomienda no comprar.\n");
									} else {
										if (edad_bovinos>=18 && edad_bovinos<20 && (peso_promedio>=500 || peso_promedio<400)) {
											printf("Los datos estan saliendo de lo real o el bovino se encuentra con graves problemas de salud.\n");
										} else {
											if (edad_bovinos>=20 && edad_bovinos<30 && (peso_promedio<400 || peso_promedio>=610)) {
												printf("Los datos estan saliendo de lo real o el bovino se encuentra con graves problemas de salud.\n");
											} else {
												if (edad_bovinos>=30 && edad_bovinos<40 && (peso_promedio>=660 || peso_promedio<430)) {
													printf("Los datos estan saliendo de lo real o el bovino se encuentra con graves problemas de salud.\n");
												} else {
													if (edad_bovinos>=40 && edad_bovinos<50 && (peso_promedio>=670 || peso_promedio<460)) {
														printf("Los datos estan saliendo de lo real o el bovino se encuentra con graves problemas de salud.\n");
													} else {
														if (edad_bovinos>=50 && edad_bovinos<90 && (peso_promedio>=680 || peso_promedio<500)) {
															printf("Los datos estan saliendo de lo real o el bovino se encuentra con graves problemas de salud.\n");
														} else {
															printf("Todo se encuentra en orden los bovinos estan con buen peso y buena produccion de leche.\n");
															// se hacen los calculos para determinar cuantos bovinos pueden soportar el vehiculo de carga y la posible produccion de leche, volviendo a litros para imprimir de acuerdo a lo pedido al usuario. 
															totalpeso_bovinos = 0;
															numerobovinos_llevar = 0;
															while (totalpeso_bovinos<=carga_vehiculo) {
																totalpeso_bovinos = peso_promedio*numerobovinos_llevar;
																if (totalpeso_bovinos<=carga_vehiculo) {
																	numerobovinos_llevar = numerobovinos_llevar+1;
																} else {
																	numerobovinos_llevar = numerobovinos_llevar-1;
																	if (numerobovinos_llevar>numerobovinos_holstein) {
																		numerobovinos_llevar = numerobovinos_holstein;
																	}
																}
															}
															produccion_leche = (produccion_leche/1.030);
															venta_leche = numerobovinos_llevar*produccion_leche;
															printf("El camion puede transportar un total de %d vacas.\n",numerobovinos_llevar);
															printf("En base a los bovinos que se pueden llevar se puede producir y vender alrededor de %.2f litros de leche.\n",venta_leche);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			break;
		case 2:
			do {
				printf("Cuantas vacas de esta raza se encuentran disponibles para la compra.\n");
				scanf("%i",&numerobovinos_brown);
				if (numerobovinos_brown<=0) {
					printf("Dato ingresado no valido.\n");
				}
			} while (numerobovinos_brown<=0);
			do {
				printf("En promedio cuantos litros de leche produce esta raza al dia?\n");
				scanf("%f",&produccion_leche);
				if (produccion_leche>30 || produccion_leche<18) {
					printf("Los valores estan saliendo de lo real o el bovino se encuentra con graves problemas de salud, se recomienda no comprar, en cualquier caso vuelva a ingresar un valor valido.\n");
				}
			} while (!(produccion_leche>=18 && produccion_leche<=30));
			produccion_leche = (produccion_leche*1.030);
			do {
				printf("Cual es el peso promedio en kilogramos de los bovinos.\n");
				scanf("%f",&peso_promedio);
				if (peso_promedio<410 || peso_promedio>680) {
					printf("Los valores se encuentran fuera de lo real para una vaca o se encuentran con problemas graves de salud, no comprar, en cualquier caso vuelva a ingresar un peso valido.\n");
				}
			} while (!(peso_promedio>=410 && peso_promedio<=680));
			do {
				printf("Cual es la edad en meses de los bovinos.\n");
				scanf("%f",&edad_bovinos);
				if (edad_bovinos<0 || edad_bovinos>120) {
					printf("Los datos ingresados son irreales o incorrectos, verifique.\n");
				}
			} while (!(edad_bovinos>0 && edad_bovinos<120));
			if (edad_bovinos<18) {
				printf("Los bovinos son muy jovenes por lo tanto no han estado pre�adas y no producira mucha leche, se recomienda no comprar.\n");
			} else {
				if (edad_bovinos>90) {
					printf("Los bovinos son muy viejos no tendra mucho tiempo de vida util, se recomienda no comprar.\n");
				} else {
					if (edad_bovinos>=18 && edad_bovinos<=20 && peso_promedio>400 && peso_promedio<=430) {
						printf("Los bovinos se encuentran bajo de peso, se recomienda no comprar.\n");
					} else {
						if (edad_bovinos>20 && edad_bovinos<=30 && peso_promedio>=430 && peso_promedio<500 && produccion_leche<20) {
							printf("2Los bovinos se encuentran bajo de peso y/o baja produccion de leche, se recomienda no comprar.\n");
						} else {
							if (edad_bovinos>30 && edad_bovinos<=40 && peso_promedio>=500 && peso_promedio<550 && produccion_leche<21) {
								printf("3Los bovinos se encuentran bajo de peso y/o baja produccion de leche, se recomienda no comprar.\n");
							} else {
								if (edad_bovinos>40 && edad_bovinos<=50 && peso_promedio>=550 && peso_promedio<610 && produccion_leche<23) {
									printf("4Los bovinos se encuentran bajo de peso y/o baja produccion de leche, se recomienda no comprar.\n");
								} else {
									if (edad_bovinos>50 && edad_bovinos<=90 && peso_promedio>=610 && peso_promedio<640 && produccion_leche<24) {
										printf("5Los bovinos se encuentran bajo de peso y/o baja produccion de leche, se recomienda no comprar.\n");
									} else {
										if (edad_bovinos>=18 && edad_bovinos<20 && (peso_promedio>500 || peso_promedio<370)) {
											printf("Los datos estan saliendo de lo real o el bovino se encuentra con graves problemas de salud.\n");
										} else {
											if (edad_bovinos>=20 && edad_bovinos<30 && (peso_promedio<=400 || peso_promedio>580)) {
												printf("Los datos estan saliendo de lo real o el bovino se encuentra con graves problemas de salud.\n");
											} else {
												if (edad_bovinos>=30 && edad_bovinos<40 && (peso_promedio>690 || peso_promedio<420)) {
													printf("Los datos estan saliendo de lo real o el bovino se encuentra con graves problemas de salud.\n");
												} else {
													if (edad_bovinos>=40 && edad_bovinos<50 && (peso_promedio>720 || peso_promedio<490)) {
														printf("Los datos estan saliendo de lo real o el bovino se encuentra con graves problemas de salud.\n");
													} else {
														if (edad_bovinos>=50 && edad_bovinos<90 && (peso_promedio>770 || peso_promedio<510)) {
															printf("Los datos estan saliendo de lo real o el bovino se encuentra con graves problemas de salud.\n");
														} else {
															printf("Todo se encuentra en orden los bovinos estan con buen peso y buena produccion de leche.\n");
															totalpeso_bovinos = 0;
															numerobovinos_llevar = 0;
															while (totalpeso_bovinos<=carga_vehiculo) {
																totalpeso_bovinos = peso_promedio*numerobovinos_llevar;
																if (totalpeso_bovinos<=carga_vehiculo) {
																	numerobovinos_llevar = numerobovinos_llevar+1;
																} else {
																	numerobovinos_llevar = numerobovinos_llevar-1;
																	if (numerobovinos_llevar>numerobovinos_brown) {
																		numerobovinos_llevar = numerobovinos_brown;
																	}
																}
															}
															produccion_leche = (produccion_leche/1.030);
															venta_leche = numerobovinos_llevar*produccion_leche;
															printf("El camion puede transportar un total de %d vacas.\n",numerobovinos_llevar);
															printf("En base a los bovinos que se pueden llevar se puede producir y vender alrededor de %.2f litros de leche.\n",venta_leche);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			break;
		case 3:
			do {
				printf("Cuantas vacas de esta raza se encuentran disponibles para la compra. Tomar en cuenta que esta raza no tiende a tener grandes pesos. Es la raza mas liviana del mercado\n");
				scanf("%i",&numerobovinos_jersey);
				if (numerobovinos_jersey<=0) {
					printf("Dato ingresado no valido.\n");
				}
			} while (numerobovinos_jersey<=0);
			do {
				printf("En promedio cuantos litros de leche produce esta raza al dia?\n");
				scanf("%f",&produccion_leche);
				if (produccion_leche>28 || produccion_leche<15) {
					printf("Los valores estan saliendo de lo real o el bovino se encuentra con graves problemas de salud, se recomienda no comprar, en cualquier caso vuelva a ingresar un valor valido.\n");
				}
			} while (!(produccion_leche>=15 && produccion_leche<=28));
			produccion_leche = (produccion_leche*1.030);
			do {
				printf("Cual es el peso promedio en kilogramos de los bovinos.\n");
				scanf("%f",&peso_promedio);
				if (peso_promedio<190 || peso_promedio>490) {
					printf("Los valores se encuentran fuera de lo real para una vaca o se encuentran con problemas graves de salud, no comprar, en cualquier caso vuelva a ingresar un peso valido.\n");
				}
			} while (!(peso_promedio>=190 && peso_promedio<=490));
			do {
				printf("Cual es la edad en meses de los bovinos.\n");
				scanf("%f",&edad_bovinos);
				if (edad_bovinos<0 || edad_bovinos>120) {
					printf("Los datos ingresados son irreales o incorrectos, verifique.\n");
				}
			} while (!(edad_bovinos>0 && edad_bovinos<120));
			if (edad_bovinos<18) {
				printf("Los bovinos son muy jovenes por lo tanto no han estado preniadas y no producira mucha leche, se recomienda no comprar.\n");
			} else {
				if (edad_bovinos>90) {
					printf("Los bovinos son muy viejos no tendra mucho tiempo de vida util, se recomienda no comprar.\n");
				} else {
					if (edad_bovinos>=18 && edad_bovinos<=20 && peso_promedio>=195 && peso_promedio<210) {
						printf("Los bovinos se encuentran bajo de peso, se recomienda no comprar.\n");
					} else {
						if (edad_bovinos>20 && edad_bovinos<=30 && peso_promedio>=210 && peso_promedio<270 && produccion_leche<18) {
							printf("2Los bovinos se encuentran bajo de peso y/o baja produccion de leche, se recomienda no comprar.\n");
						} else {
							if (edad_bovinos>30 && edad_bovinos<=40 && peso_promedio>=270 && peso_promedio<350 && produccion_leche<19) {
								printf("3Los bovinos se encuentran bajo de peso y/o baja produccion de leche, se recomienda no comprar.\n");
							} else {
								if (edad_bovinos>40 && edad_bovinos<=50 && peso_promedio>=350 && peso_promedio<400 && produccion_leche<20) {
									printf("4Los bovinos se encuentran bajo de peso y/o baja produccion de leche, se recomienda no comprar.\n");
								} else {
									if (edad_bovinos>50 && edad_bovinos<=90 && peso_promedio>=400 && peso_promedio<430 && produccion_leche<21) {
										printf("5Los bovinos se encuentran bajo de peso y/o baja produccion de leche, se recomienda no comprar.\n");
									} else {
										if (edad_bovinos>=18 && edad_bovinos<20 && (peso_promedio>360 || peso_promedio<195)) {
											printf("Los datos estan saliendo de lo real o el bovino se encuentra con graves problemas de salud.\n");
										} else {
											if (edad_bovinos>=20 && edad_bovinos<30 && (peso_promedio<230 || peso_promedio>390)) {
												printf("Los datos estan saliendo de lo real o el bovino se encuentra con graves problemas de salud.\n");
											} else {
												if (edad_bovinos>=30 && edad_bovinos<40 && (peso_promedio>410 || peso_promedio<260)) {
													printf("Los datos estan saliendo de lo real o el bovino se encuentra con graves problemas de salud.\n");
												} else {
													if (edad_bovinos>=40 && edad_bovinos<50 && (peso_promedio>460 || peso_promedio<345)) {
														printf("Los datos estan saliendo de lo real o el bovino se encuentra con graves problemas de salud.\n");
													} else {
														if (edad_bovinos>=50 && edad_bovinos<90 && (peso_promedio>480 || peso_promedio<365)) {
															printf("Los datos estan saliendo de lo real o el bovino se encuentra con graves problemas de salud.\n");
														} else {
															printf("Todo se encuentra en orden los bovinos estan con buen peso y buena produccion de leche.\n");
															totalpeso_bovinos = 0;
															numerobovinos_llevar = 0;
															while (totalpeso_bovinos<=carga_vehiculo) {
																totalpeso_bovinos = peso_promedio*numerobovinos_llevar;
																if (totalpeso_bovinos<=carga_vehiculo) {
																	numerobovinos_llevar = numerobovinos_llevar+1;
																} else {
																	numerobovinos_llevar = numerobovinos_llevar-1;
																	if (numerobovinos_llevar>numerobovinos_jersey) {
																		numerobovinos_llevar = numerobovinos_jersey;
																	}
																}
															}
															produccion_leche = (produccion_leche/1.030);
															venta_leche = numerobovinos_llevar*produccion_leche;
															printf("El camion puede transportar un total de %d vacas.\n",numerobovinos_llevar);
															printf("En base a los bovinos que se pueden llevar se puede producir y vender alrededor de %.2f litros de leche.\n",venta_leche);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			break;
		case 4:
			printf ("Gracias por usar nuestro programa.\n");
			break;
		default:
			printf("Opcion incorecta, verifique.\n");
		}
	} while (raza_bovinos!=4);
	return 0;
}

