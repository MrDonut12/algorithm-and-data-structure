#include <iostream>
#include <map>
using namespace std;

map<int, bool> sieve(int limit) {
    map<int, bool> is_prime;

    // Kh?i t?o t?t c? các s? t? 2 d?n `limit` là nguyên t?
    for (int i = 2; i <= limit; i++) {
        is_prime[i] = true;
    }

    // B?t d?u sàng Eratosthenes
    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false; // Ðánh d?u các b?i c?a i là không ph?i s? nguyên t?
            }
        }
    }
    
    return is_prime; // Tr? v? map ch?a các s? nguyên t?
}

int main() {
    int limit;
    cout << "Nh?p gi?i h?n: ";
    cin >> limit;

    map<int, bool> primes = sieve(limit);

    // In ra các s? nguyên t? trong map
    cout << "Các s? nguyên t? t? 2 d?n " << limit << " là: ";
    for (const auto& p : primes) {
        if (p.second) { // Ki?m tra n?u là nguyên t?
            cout << p.first << " ";
        }
    }
    cout << endl;

    return 0;
}

