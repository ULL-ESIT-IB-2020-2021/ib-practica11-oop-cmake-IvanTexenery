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
class Fecha {
 public:
  Fecha(std::string fecha_str);
  void Imprimir();
  std::string ObtenerFecha(std::string cadena);
  bool DeterminarBisiesto(int anyo);
  int GetDia();
  int GetMes();
  int GetAnyo();
  std::string FechasPosteriores(int dia, int mes, int anyo, int n_fechas);

 private:
  int dia_;
  int mes_;
  int anyo_;
};
