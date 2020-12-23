/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado de Ingeniería Informática
 * Informática Básica
 * @file funciones_fecha.cc
 * @author Iván Texenery Díaz García
 * @date 12/12/2020
 * @brief Funciones del programa principal
 */
#include "funciones_fecha.h"

#include <iostream>
#include <string>

/**
 * Controla que los parámetros que se le pasan a la funcion main sean correctos.
 * @param Cantidad de parámetros introducidos, array de caracteres con los
 * argumentos introducidos.
 */
void Parametros(int argc, char *argv[]) {
  const std::string kTextoAyuda =
      "  Introduzca ./fechas junto con la fecha \n\
  a la que desea calcular las n fechas posteriores a ella con una separación de \n\
  un día entre fechas sucesivas, además de el archivo de salida donde desea escribir la salida,\n\
  de la forma: ./fechas dd/mm/aa N fichero_salida.txt ";

  if (argc != 4) {
    std::cout << argv[0]
              << " Modo de uso: ./fechas dd/mm/aa N fichero_salida.txt"
              << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información"
              << std::endl;
    exit(EXIT_SUCCESS);
  }

  std::string parametro{argv[1]};
  if (parametro == "--help") {
    std::cout << kTextoAyuda << std::endl;
    exit(EXIT_SUCCESS);
  }
}