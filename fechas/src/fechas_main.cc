/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado de Ingeniería Informática
 * Informática Básica
 * @file fechas.cc
 * @author Iván Texenery Díaz García
 * @date 12/12/2020
 * @brief Desarrolle en C++ un programa cripto.cc cuya finalidad será
 * encriptar y/o desencriptar ficheros de texto.
 */
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "fecha.h"
#include "funciones_fecha.h"

int main(int argc, char* argv[]) {
  Parametros(argc, argv);

  std::string cadena{argv[1]};
  std::string n_fechas_str{argv[2]};
  int n_fechas{stoi(n_fechas_str)};
  std::ofstream archivo_salida(argv[3], std::ofstream::out);

  Fecha date(date.ObtenerFecha(cadena));

  date.Imprimir();
  date.DeterminarBisiesto(date.GetAnyo());
  archivo_salida << date.FechasPosteriores(date.GetDia(), date.GetMes(),
                                           date.GetAnyo(), n_fechas);
  archivo_salida.close();
  return 0;
}