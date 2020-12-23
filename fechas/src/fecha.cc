/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado de Ingeniería Informática
 * Informática Básica
 * @file fecha.cc
 * @author Iván Texenery Díaz García
 * @date 12/12/2020
 * @brief Código de la clase Fecha
 */
#include <iostream>
#include <string>
#include <vector>
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

Fecha::Fecha(std::string fecha_str) {
  int fecha = stoi(fecha_str);
  anyo_ = fecha % 10000;
  fecha /= 10000;
  mes_ = fecha % 100;
  fecha /= 100;
  dia_ = fecha;
}

void Fecha::Imprimir() {
  std::cout << dia_ << "/" << mes_ << "/" << anyo_ << std::endl;
}
std::string Fecha::ObtenerFecha(std::string cadena) {
  std::string fecha{};
  for (auto elemento : cadena) {
    if (elemento != '/') {
      fecha += (elemento);
    }
  }
  return fecha;
}

bool Fecha::DeterminarBisiesto(int anyo) {
  if (anyo % 4 == 0) {
    if (anyo % 100 == 0) {
      if (anyo_ % 400 == 0) {
        return true;
      } else {
        return false;
      }
    } else {
      return true;
    }
  } else {
    return false;
  }
}

int Fecha::GetDia() { return dia_; }

int Fecha::GetMes() { return mes_; }

int Fecha::GetAnyo() { return anyo_; }

std::string Fecha::FechasPosteriores(int dia, int mes, int anyo, int n_fechas) {
  std::string fechas{""};
  for (int i = 0; i <= n_fechas; ++i) {
    ++dia;
    if (mes == 2 && Fecha::DeterminarBisiesto(anyo) == true && dia > 29) {
      dia -= 29;
      ++mes;
    }
    if (mes == 2 && Fecha::DeterminarBisiesto(anyo) == false && dia > 28) {
      dia -= 28;
      ++mes;
    }
    if ((mes == 4 && dia > 30) || (mes == 6 && dia > 30) ||
        (mes == 9 && dia > 30) || (mes == 11 && dia > 30)) {
      dia -= 30;
      ++mes;
    }
    if ((mes == 1 && dia > 31) || (mes == 3 && dia > 31) ||
        (mes == 5 && dia > 31) || (mes == 7 && dia > 31) ||
        (mes == 8 && dia > 31) || (mes == 10 && dia > 31) ||
        (mes == 12 && dia > 31)) {
      dia -= 31;
      if (mes == 12) {
        ++anyo;
        mes = 1;
      } else {
        ++mes;
      }
    }
    std::string fecha_posterior{""};
    fecha_posterior.append(std::to_string(dia));
    fecha_posterior.append("/");
    fecha_posterior.append(std::to_string(mes));
    fecha_posterior.append("/");
    fecha_posterior.append(std::to_string(anyo));
    fechas.append(fecha_posterior);
    fechas.append("\n");
  }
  return fechas;
}