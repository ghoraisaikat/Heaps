#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define endl "\n"
#define YES "YES\n"
#define NO "NO\n"
#define ull unsigned long long
#define ll long long
#define debug() cout << "I reached here!" << endl

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define ff first
#define ss second
#define sp " "
#define vpii vector<pii>
#define vpll vector<pll>

const int MOD = 1e9 + 7;

struct cmp{
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second > p2.second;
	}
};

void solve(void){
	int n; int k; cin >> n >> k;
	vi a(n, 0); for (int i = 0; i < n; i++) cin >> a[i];
	unordered_map<int, int> f;
	for (int i = 0; i < n; i++) f[a[i]]++;
	// Space optimization
	priority_queue<pii, vector<pii>, cmp> pq;

	for (auto& x : f) {
		pq.push(x);
		// The least will keep getting eliminated
		while (pq.size() > k) pq.pop();
	}
	while (!pq.empty()) {
		cout << pq.top().first << sp << pq.top().second << endl;
		pq.pop();
	}
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
