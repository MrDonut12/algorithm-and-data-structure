#include <bits/stdc++.h>

#define fto(i, a, b) for (int i = (int)a; i <= (int)b; ++i)
#define fdto(i, a, b) for (int i = (int)a; i >= (int)b; --i)

#define TEST int TEST; cin >> TEST; while(TEST--)
#define FAST ios::sync_with_stdio(false), cin.tie(nullptr);
#define TIME cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << " secs \n"

#define el endl
#define yes cout << "YES\n"
#define no cout << "NO\n"

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define sz(a) (int)a.size()
#define all(a) (a).begin(), (a).end()
#define rall(a) reverse(all(a))

#define vt vector
#define ii pair<int, int>
#define pll pair<ll, ll> 

#define db double
#define ll long long
#define ull unsigned long long
#define int128 __int128
//#define int ll

#define maxm (int)()
#define maxn (int)(1e2+5)

using namespace std;

int n, k;
int vis[maxn][maxn];

int di[] = {0, 0, 1, -1};
int dj[] = {-1, 1, 0, 0};

int check(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= n);
}

int main(){
  
    FAST;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; i += 5){
        for (int j = 1; j <= n; j += 5){
            int u = i;
            int v = j;
            while(check(u, v)){
                if (vis[u][v] == 1) {
                    ++u;
                    ++v;
                    continue;
                }
                vis[u][v] = 1;
                cout << u << " " << v << el;
                cout.flush();
                string s;
                cin >> s;
                if (s == "sunk") ++cnt;
                if (cnt == k) return 0; 
                if (s == "hit"){
                    fto(_, 0, 3){
                        int x = u;
                        int y = v;
                        fto(sl, 1, 4){
                            x += di[_];  
                            y += dj[_];
                            if (check(x, y)){
                                if (vis[x][y] == 1) continue;
                                vis[x][y] = 1;
                                cout << x << " " << y << el;
                                cout.flush();
                                cin >> s;
                                if (s == "miss") break;
                                if (s == "sunk") ++cnt;
                                if (cnt == k) return 0; 
                            } 
                        }
                    }
                }
                ++u;
                ++v;
            }
        }
    }  
    //TIME;
    return 0;
}

// Duy Khanh
