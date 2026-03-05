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
	int k;
	int n; cin >> n >> k;
	vi a(n, 0); for (int i = 0; i < n; i++) cin >> a[i];
	
	// O(K)
	priority_queue<int, vector<int>, greater<int>> pq(a.begin(), a.begin() + k + 1);
	// O (N log K)
	for (int i = 0; i < n - k - 1; i++) {
		a[i] = pq.top();
		pq.pop();
		pq.push(a[i + k + 1]);
	}
	for (int i = n - k - 1; i < n; i++) {
		a[i] = pq.top();
		pq.pop();
	}
	for (auto& x : a) cout << x << sp;
	cout << endl;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
