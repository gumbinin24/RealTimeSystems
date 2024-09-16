#include <iostream>
#include <time.h>

int main() {
	int N = 10000000;
	int n = 10;
	clock_t start = clock();
	for (int i = 0; i < N; i++) 
	{
		int res = 1;
		for (int j = 1; j <= n; j++) 
		{
			res = res * j;
		}
	}
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
}