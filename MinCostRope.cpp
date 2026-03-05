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

void solve(void){
	int n; cin >> n;
	vi a(n, 0); for (int i = 0; i < n; i++) cin >> a[i];
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for (auto& x : a) pq.push(x);
	int cost = 0;
	while (pq.size() > 1) {
		int fst = pq.top(); pq.pop();
		int scnd = pq.top(); pq.pop();
		cost += fst + scnd;
		pq.push(fst + scnd);
	}
	cout << cost << endl;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
