#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <chrono>

using namespace std;

bool isPrime(int num) {
	if (num <= 1) return false;
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int temp;
	
	const int maxSize = 100;
	int data[maxSize];

	std::ifstream inputFile("liczby_przyklad.txt");

	if (!inputFile.is_open()) {
		std::cerr << "Error opening file 'liczby'" << std::endl;
		return 1;
	}

	int index = 0;
	while (index < maxSize && inputFile >> data[index]) {
		index++;
	}

	temp = 0;
	for (int i = 0; i < 100; i++) {
		if (isPrime(data[i]-1) == 1) {
			temp++;
		}
	}
	cout << temp;
}