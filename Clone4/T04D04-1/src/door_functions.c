#include <math.h>
#include <stdio.h>
#define PI 3.14159265358979323846

double Bernoulli(double);
double Agnesi(double);
double Hfunperbola(double);

int main() {

  double x = -3.14159265358979323846;
  double fun1 = Agnesi(x);
  double fun2 = Bernoulli(x);
  double fun3 = Hfunperbola(x);
  double step = PI * 2.0 / 41.0;

  for (double i = -PI; i <= PI; i += step) {
    x += 0.01556606;
    fun1 = Agnesi(x);
    fun2 = Bernoulli(x);
    fun3 = Hfunperbola(x);
    if (fun2 != 100) {
      char fun22 = '-';
      printf("%.7lf | %.7lf | %c | %.7lf\n", x, fun1, fun22, fun3);
    } else {
      printf("%.7lf | %.7lf | %.7lf | %.7lf\n", x, fun1, fun2, fun3);
    }
  }
  return 0;
}

double Agnesi(double x) {

  double fun = ((pow(1, 3)) / (pow(1, 2) + pow(x, 2)));
  return fun;
}

double Bernoulli(double x) {

  double fun =
      sqrt(sqrt(pow(1, 4) + 4 * pow(x, 2) * pow(1, 2)) - pow(x, 2) - pow(1, 2));
  return fun;
}

double Hfunperbola(double x) {

  double fun = (1 / pow(x, 2));
  return fun;
}
