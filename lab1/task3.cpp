#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <time.h>


void Func(std::string name) {
	int N = 10000000;
	int n = 10;

	for (int i = 0; i < N; i++) 
	{
		int res = 1;
		for (int j = 1; j <= n; j++) 
		{
			res = res * j;
		}
	}

	std::cout << name << " - successfully completed" << std::endl;
}

int main() {
	clock_t start = clock();

	std::thread thread1(Func, "t1");
	std::thread thread2(Func, "t2");

	thread1.join();
	thread2.join();

	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	std::cout << "parallel: " << seconds << std::endl << std::endl;

	clock_t start1 = clock();

	Func("s1");
	Func("s2");

	clock_t end1 = clock();
	double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
	std::cout << "standard: " << seconds1 << std::endl;

	std::cout << std::endl << "difference is " << seconds1 - seconds << " seconds" << std::endl;

	system("pause");
}
