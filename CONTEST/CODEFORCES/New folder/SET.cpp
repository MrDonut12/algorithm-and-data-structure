#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        vector<int> results(n);
        
        // Xét các giá tr? k t? 1 d?n n
        for (int k = 1; k <= n; ++k) {
            // T?o m?t b?n sao c?a m?ng a d? luu các k?t qu? OR
            vector<int> or_results = a;
            
            // Th?c hi?n phép OR trong các nhóm v?i kho?ng cách >= k
            for (int start = 0; start < k; ++start) {
                int current_or = 0;
                
                // Th?c hi?n phép OR trên các ph?n t? trong m?i nhóm
                for (int i = start; i < n; i += k) {
                    current_or |= or_results[i];
                }
                
                // Gán l?i giá tr? OR cho t?t c? các ph?n t? trong nhóm
                for (int i = start; i < n; i += k) {
                    or_results[i] = current_or;
                }
            }
            
            // Tính giá tr? AND c?a m?ng sau khi OR
            int max_and = or_results[0];
            for (int i = 1; i < n; ++i) {
                max_and &= or_results[i];
            }
            
            results[k - 1] = max_and;
        }
        
        // In k?t qu? cho t?ng giá tr? k
        for (int i = 0; i < n; ++i) {
            cout << results[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

