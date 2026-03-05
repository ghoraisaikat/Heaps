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
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){
		return p1.second > p2.second;
	}
};

struct cmp1{
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){
		return p1.second < p2.second;
	}
};
void solve(void){
	int n, k, x; cin >> n >> k >> x;
	vi a(n, 0); for (int i = 0; i < n; i++) cin >> a[i];

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	for (int i = 0; i < n; i++) {
		pq.push(make_pair(a[i], abs(a[i] - x)));
	}
	for (int i = 0; i < k; i++) {
		cout << pq.top().first << sp;
		pq.pop();
	}
	// Space optimization
	// Heap never grows larger than K
	// O (K log K)
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> pqm;
	for (int i = 0; i < n; i++) {
		int dist = abs(a[i] - x);
		if (pqm.empty() || pqm.size() < k) {
			pqm.push(make_pair(a[i], dist));
			continue;
		}
		// If there are already K numbers
		// Check for a better alternative
		if (dist < pqm.top().second) {
			pqm.pop();
			pqm.push(make_pair(a[i], dist));
		}
	}
	cout << endl;
	while (!pqm.empty()) {
		cout << pqm.top().first << sp;
		pqm.pop();
	}

	cout << endl;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
