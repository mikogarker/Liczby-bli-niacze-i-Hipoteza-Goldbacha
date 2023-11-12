#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

std::vector<bool> eratosthenes(size_t n) {
    std::vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;

    for (size_t p = 2; p * p <= n; ++p) {
        if (primes[p]) {
            for (size_t i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }

    return primes;
}

size_t twin_primes(size_t a, size_t b) {
    size_t c = 0;
    std::vector<bool> primes = eratosthenes(b);

    for (size_t i = a; i <= b - 2; ++i) {
        if (primes[i] && primes[i + 2]) {
            c += 1;
        }
    }

    return c;
}

int main() {
    int a, b;
    cin >> a >> b;
    size_t result = twin_primes(a, b);
    cout << result;

    return 0;
}
