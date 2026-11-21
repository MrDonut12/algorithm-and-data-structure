// Source - https://stackoverflow.com/q/79753925
// Posted by crxyz
// Retrieved 2026-11-19, License - CC BY-SA 4.0

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >>n;

  vector<string> prev;
  string s;
  cin >> s;
  prev.push_back(s.substr(0, 1));
  for (int j=1; j<n; j++) { // first row
    prev.push_back(prev.back()+s[j]);
  }

  for (int i=1; i<n; i++) {
    string s;
    cin >> s;
    prev[0] += s[0];
    for (int j=1; j<n; j++) {
      prev[j] = min(prev[j-1], prev[j]) + s[j];
    }
  }

  cout << prev.back() << '\n';
}
