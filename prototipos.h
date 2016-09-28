#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

#include <QMainWindow>
#include <QtCore>
#include <QObject>
#include <QMutex>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

//Estructuras
struct AlmacenPrima;
struct NodoPeticion;
struct CarritoEntrega;
struct MezcladoraMasa;
struct MezcladoraChocolate;
struct Banda;
struct NodoContenido;
struct Ensambladora;
struct Horno;
struct Bandeja;
struct BandaInspectores;
struct Inspector;
struct Empacadora;
struct ListaGalletas;
struct CarritoSalida;
struct NodoEmpaque;
struct Planificador;
struct CarritoSalida;
struct MonticulosEmpaques;
struct NodoMonticulo;
struct AlmacenTerminal;
struct ListaRangos;
struct NodoRango;

//Clases de Interfaz
class VentanaPrincipal;

//Hilos
struct Simulacion;
class HiloCarritoEntrega;
class HiloMezcladoraMasa;
class HiloMezcladoraChocolate;
class HiloBanda;
class HiloInterfaz;
#endif // PROTOTIPOS_H
