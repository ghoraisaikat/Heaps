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
	int n; cin >> n;
	vi a(n, 0); for (int i = 0; i < n; i++) cin >> a[i];
	priority_queue<int, vi> pq(all(a));
	
	while (pq.size() > 1) {
		int tp = pq.top(); pq.pop();
		int scnd = pq.top(); pq.pop();
		if (tp != scnd) pq.push(tp - scnd);
	}
	if (pq.empty()) cout << 0 << endl;
	else cout << pq.top() << endl;

}

int main(void){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
