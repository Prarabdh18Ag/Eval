#include <iostream>
#include <vector>

using namespace std;

void findPrimes(int n) {
    if (n < 2) {
        cout << "No primes less than 2." << endl;
        return;
    }

    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    cout << "Prime numbers up to " << n << " are: ";
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    findPrimes(num);

    return 0;
}
