#include <iostream>
#include <vector>
#include <map>
#include "decimalToBinary.h"
#include "HexaToBinary.h"

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

map<int, int> primeFactorization(int n) {
    map<int, int> factors;
    for (int i = 2; i * i <= n; i++) {
        int count = 0;
        while (n % i == 0) {
            ++count;
            n /= i;
        }
        if (count > 0) factors.emplace(i, count);
    }
    if (n > 1) factors.emplace(n, 1);
    return factors;
}
vector<int> phiEuler(int n){
    vector<int> euler;
    for(int i=1;i<n;i++){
        if(gcd(n,i)==1) euler.push_back(i);
    }
    return euler;
}
void extendedEuclidean(int a, int b, int &x, int &y, int &gcd) {
    if (b == 0) {
        x = 1;
        y = 0;
        gcd = a;
        return;
    }
    int x1, y1;
    extendedEuclidean(b, a % b, x1, y1, gcd);
    x = y1;
    y = x1 - (a / b) * y1;
}
int main() {
int a = 131364, b = 17;
    int x, y, gcd;
    int abc;
    extendedEuclidean(a, b, x, y, gcd);
    cout << "UCLN của " << a << " và " << b << " là " << gcd << endl;
    cout << "x = " << x << ", y = " << y << endl;    
    return 0;
}
