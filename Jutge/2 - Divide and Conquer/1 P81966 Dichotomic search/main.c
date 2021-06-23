#include <stdio.h>

int position(double x, double v[], int esq, int dre);

int main() {
	int n, t;
	while (scanf("%d", &n) > 0) {
    double v[n];
    for (int i = 0; i < n; ++i) scanf("%lf", &v[i]);
    scanf("%d", &t);
    while (t) {
      --t;
      double x;
      int esq, dre;
      scanf("%lf %d %d", &x, &esq, &dre);
      printf("%d\n", position(x, v, esq, dre));
    }
	}
	return 0;
}
