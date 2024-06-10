#include <iostream>
#include <vector>
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

// Function to find the smallest x such that:
// x % num[i] = rem[i] for all i
int chineseRemainderTheorem(const vector<int> &num, const vector<int> &rem) {
    int prod = 1;
    for (int n : num)
        prod *= n;

    int result = 0;
    for (int i = 0; i < num.size(); i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % prod;
}

int main() {
    int k;
    cout << "Enter number of equations: ";
    cin >> k;

    vector<int> num(k), rem(k);
    cout << "Enter the values for num and rem arrays:" << endl;
    for (int i = 0; i < k; i++) {
        cout << "num[" << i << "] = ";
        cin >> num[i];
        cout << "rem[" << i << "] = ";
        cin >> rem[i];
    }

    int result = chineseRemainderTheorem(num, rem);
    cout << "x is " << result << endl;

    return 0;
}

