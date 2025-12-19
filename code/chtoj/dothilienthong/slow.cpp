#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define pb push_back
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';
#define shouko 1
#define orz shouko
#define task "SLOW"

using namespace std;
const int N = 1e6 + 9;
const int inf = 1e18;
const int mod = 2e9 + 11;
const int base = 311;

inline int add(int a, int b, int mod) {
	return (a + b) % mod;
}
inline int sub(int a, int b, int mod) {
	return ((a - b) % mod + mod) % mod;
}
inline int mul(int a, int b, int mod) {
	return (1LL * a * b) % mod;
}
int n, q, ti;
int a[N];
int in[N], out[N];
vector<int> adj[N];
int st[4 * N];

void DFS(int u, int par) {
	in[u] = out[u] = ++ti;
	for (auto v : adj[u]) {
		if (v != par) {
			DFS(v, u);
			out[u] = max(out[u], out[v]);
		}
	}
}

void update(int id, int l, int r, int u, int v, int val) {
	if (u > r || v < l) {
		return;
	}
	if (l >= u && r <= v) {
		st[id] += val;
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2, l, mid, u, v, val);
	update(id * 2 + 1, mid + 1, r, u, v, val);
}

int get(int id, int l, int r, int pos) {
	if (l > pos || r < pos) {
		return 0;
	}
	if (l == r) {
		return st[id];
	}
	int mid = (l + r) / 2;
	return st[id] + get(id * 2, l, mid, pos) + get(id * 2 + 1, mid + 1, r, pos);
}


void solve() {
	cin >> n;
	for (int i = 1; i <= n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	DFS(1, -1);


	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		cout << get(1, 1, n, in[x]) << '\n';
		update(1, 1, n, in[x], out[x], 1);

	}

}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(task ".inp", "r")) {
		freopen(task ".inp", "r", stdin);
		freopen(task ".out", "w", stdout);
	}

	solve();

	// execute;
	return 0;
}
