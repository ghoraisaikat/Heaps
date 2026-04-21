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
#define ff first
#define ss second
#define sp " "

void solve(void){
	int n, k; cin >> n >> k;
	vi a(n, 0); for (int i = 0; i < n; i++) cin >> a[i];
	priority_queue<int, vi> pq;

	for (auto& x : a) pq.push(x);
	while (k--) {
		int tp = pq.top();
		pq.pop();
		pq.push((tp + 1)/ 2);
	}
	int s = 0;
	while (!pq.empty()) {
		s += pq.top();
		pq.pop();
	}
	cout << s << endl;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
