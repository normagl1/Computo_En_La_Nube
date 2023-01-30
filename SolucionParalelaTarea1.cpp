

#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float* d);

int main()
{
	std::cout << "Sumando Arreglos en Paralelo\n";
	float A[N], B[N], R[N];
	int i;

	for (i = 0; i < N; i++)
	{
		A[i] = 1 + i;
		B[i] = 11 + i;
	}
	int pedazos = chunk;

#pragma omp parallel for \
    shared(A, B, R, pedazos) private(i) \
    schedule(static, pedazos)

	for (i = 0; i < N; i++)
		R[i] = A[i] + B[i];

	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo A" << std::endl;
	imprimeArreglo(A);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo B" << std::endl;
	imprimeArreglo(B);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo R" << std::endl;
	imprimeArreglo(R);
#ifdef _OPENMP
	std::cout << "OMP disponible y funcionando\n";
#endif
}

void imprimeArreglo(float* d) {
	for (int x = 0; x < mostrar; x++)
		std::cout << d[x] << " - ";
	std::cout << std::endl;
}



