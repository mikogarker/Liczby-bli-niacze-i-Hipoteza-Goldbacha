#include <iostream>
#include <vector>

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<int> findPrimePair(int evenNumber) {
    std::vector<int> primePair;

    for (int i = 2; i <= evenNumber / 2; ++i) {
        if (isPrime(i) && isPrime(evenNumber - i)) {
            primePair.push_back(i);
            primePair.push_back(evenNumber - i);
            break;
        }
    }

    return primePair;
}

int main() {
    int evenNumber;
    std::cin >> evenNumber;

    if (evenNumber % 2 == 0) {
        std::vector<int> result = findPrimePair(evenNumber);

        if (!result.empty()) {
            std::cout << evenNumber << "= " << result[0] << " + " << result[1] << std::endl;
        }
        else {
            std::cout << "nie znaleziono" << std::endl;
        }
    }
    else {
        std::cout << "to nie jest parzysta liczba" << std::endl;
    }

    return 0;
}
