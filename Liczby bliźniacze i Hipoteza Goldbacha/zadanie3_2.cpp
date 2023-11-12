#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void findDecompositions(int number, std::unordered_map<int, int>& decompositions) {
    for (int i = 2; i <= number / 2; ++i) {
        if (isPrime(i) && isPrime(number - i)) {
            decompositions[i]++;
        }
    }
}

int main() {
    const int maxSize = 100;
    int numbers[maxSize];

    std::ifstream inputFile("liczby.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file 'liczby.txt'" << std::endl;
        return 1;
    }

    for (int i = 0; i < maxSize && inputFile >> numbers[i]; ++i) {}

    inputFile.close();


    int maxDecompositions = -1, minDecompositions = std::numeric_limits<int>::max();
    int numberWithMaxDecompositions, numberWithMinDecompositions;

    for (int i = 0; i < maxSize; ++i) {
        std::unordered_map<int, int> decompositions;
        findDecompositions(numbers[i], decompositions);

        int count = decompositions.size();

        if (count > maxDecompositions) {
            maxDecompositions = count;
            numberWithMaxDecompositions = numbers[i];
        }

        if (count < minDecompositions) {
            minDecompositions = count;
            numberWithMinDecompositions = numbers[i];
        }
    }

    std::cout << "najwięcej : " << numberWithMaxDecompositions
        << " (ilosc rozwiazan: " << maxDecompositions << ")\n";

    std::cout << "najmniej: " << numberWithMinDecompositions
        << " (ilosc rozwiazan: " << minDecompositions << ")\n";

    return 0;
}
