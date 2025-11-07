#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define vpi vector<pii>
#define vi vector<int>
#define vvi vector<vi>
#define fastIO  ios::sync_with_stdio(false); cin.tie(nullptr);


int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct ii {
    int r, c, d;
};

bool valid(int x, int n) { return x >= 0 && x < n; }

void dfs(int i, int j, int id, const vector<string> &grid,
         vector<vector<bool>> &vis, vvi &comp_id, vpi &component, int n) {
    stack<pii> st;
    st.push({i, j});
    vis[i][j] = true;
    comp_id[i][j] = id;
    component.pb({i, j});

    while (!st.empty()) {
        auto [x, y] = st.top();
        st.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dr[d];
            int ny = y + dc[d];
            if (valid(nx, n) && valid(ny, n) && grid[nx][ny] == '#' &&
                !vis[nx][ny]) {
                vis[nx][ny] = true;
                comp_id[nx][ny] = id;
                component.pb({nx, ny});
                st.push({nx, ny});
            }
        }
    }
}

bool has_three(const vector<string> &grid, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j + 2 < n; j++)
            if (grid[i][j] == '#' && grid[i][j + 1] == '#' &&
                grid[i][j + 2] == '#')
                return true;
    for (int j = 0; j < n; j++)
        for (int i = 0; i + 2 < n; i++)
            if (grid[i][j] == '#' && grid[i + 1][j] == '#' &&
                grid[i + 2][j] == '#')
                return true;
    return false;
}

bool is_safe(int x, int y, const vector<vector<bool>> &is_black, int n) {
    for (int s = max(0, y - 2); s <= y; s++) {
        if (s + 2 >= n) continue;
        bool a = (s == y ? true : is_black[x][s]);
        bool b = (s + 1 == y ? true : is_black[x][s + 1]);
        bool c = (s + 2 == y ? true : is_black[x][s + 2]);
        if (a && b && c) return false;
    }
    for (int s = max(0, x - 2); s <= x; s++) {
        if (s + 2 >= n) continue;
        bool a = (s == x ? true : is_black[s][y]);
        bool b = (s + 1 == x ? true : is_black[s + 1][y]);
        bool c = (s + 2 == x ? true : is_black[s + 2][y]);
        if (a && b && c) return false;
    }
    return true;
}

bool is_target(int r, int c, const vvi &comp_id, const vector<bool> &merged,
               const vector<string> &grid, int n) {
    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (valid(nr, n) && valid(nc, n) && grid[nr][nc] == '#' &&
            !merged[comp_id[nr][nc]])
            return true;
    }
    return false;
}

bool try_grow(int root, const vector<vpi> &comps, const vvi &comp_id,
              const vector<string> &grid, int n) {
    int k = comps.size();
    vector<bool> merged(k, false);
    merged[root] = true;
    int num_merged = 1;
    vector<vector<bool>> grown(n, vector<bool>(n, false));
    for (auto p : comps[root]) grown[p.fi][p.se] = true;

    vector<vector<bool>> is_black(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == '#') is_black[i][j] = true;

    bool possible = true;

    while (num_merged < k && possible) {
        bool visited[100][100][4] = {};
        queue<ii> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grown[i][j])
                    for (int d = 0; d < 4; d++) {
                        int nr = i + dr[d];
                        int nc = j + dc[d];
                        if (!valid(nr, n) || !valid(nc, n)) continue;
                        if (grid[nr][nc] != '.') continue;
                        if (is_black[nr][nc]) continue;
                        if (!is_safe(nr, nc, is_black, n)) continue;
                        if (visited[nr][nc][d]) continue;
                        visited[nr][nc][d] = true;
                        q.push({nr, nc, d});
                    }
        bool good_path = false;

        while (!q.empty() && !good_path) {
            ii curr = q.front();
            q.pop();
            int cr = curr.r;
            int cc = curr.c;

            if (is_target(cr, cc, comp_id, merged, grid, n)) {
                is_black[cr][cc] = true;
                grown[cr][cc] = true;
                merged[comp_id[cr][cc]] = true;
                num_merged++;
                good_path = true;
            }
        }
        if (!good_path) possible = false;
    }

    return possible && num_merged == k;
}

int main() {
	fastIO;
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        if (has_three(grid, n)) {
            cout << "NO\n";
            continue;
        }

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vvi comp_id(n, vector<int>(n, -1));
        vector<vpi> comps;
        int id = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '#' && !vis[i][j]) {
                    vpi component;
                    dfs(i, j, id, grid, vis, comp_id, component, n);
                    comps.pb(component);
                    id++;
                }

        int k = comps.size();
        if (k <= 1) {
            cout << "YES\n";
            continue;
        }

        bool can = false;
        for (int root = 0; root < k; root++)
            if (try_grow(root, comps, comp_id, grid, n)) {
                can = true;
                break;
            }

        cout << (can ? "YES\n" : "NO\n");
    }
    return 0;
}
