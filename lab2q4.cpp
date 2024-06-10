#include <iostream>
using namespace std;

// Function to find gcd
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find modular inverse of a under modulo m
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to solve linear congruence equation a*x = b (mod m)
void solveLinearCongruence(int a, int b, int m) {
    int g = gcd(a, m);

    if (b % g != 0) {
        cout << "No solution exists." << endl;
        return;
    }

    // Reduce a, b and m by g
    a /= g;
    b /= g;
    m /= g;

    int x0 = (b * modInverse(a, m)) % m;

    for (int i = 0; i < g; i++)
        cout << "x = " << x0 + i * m << " (mod " << m * g << ")" << endl;
}

int main() {
    int a, b, m;
    cout << "Enter values for a, b, and m in the equation a*x = b (mod m): ";
    cin >> a >> b >> m;
    solveLinearCongruence(a, b, m);
    return 0;
}

