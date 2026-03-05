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
	int n, k1, k2; cin >> n >> k1 >> k2;
	--k1, --k2;
	if (k1 > k2) swap(k1, k2);
	vi a(n, 0); for (int i = 0; i < n; i++) cin >> a[i];
	
	priority_queue<int, vector<int>> pq;
	for (int i = 0; i < n; i++) {
		pq.push(a[i]);
		while (pq.size() > k2) pq.pop();
	}
	// I am a genius
	int ans = 0;
	while (k1--) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans << endl;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
