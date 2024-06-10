#include <iostream>
#include <vector>
using namespace std;

void primeFactors(int n) {
    vector<int> factors;

    // Print the number of 2s that divide n
    while (n % 2 == 0) {
        factors.push_back(2);
        n = n / 2;
    }

    // n must be odd at this point
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }

    // This condition is to check if n is a prime number
    // greater than 2
    if (n > 2)
        factors.push_back(n);

    cout << "Prime factors are: ";
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    primeFactors(n);
    return 0;
}

