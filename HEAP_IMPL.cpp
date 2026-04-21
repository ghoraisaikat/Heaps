#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define eb(...) emplace_back(__VA_ARGS__)
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
	int heap_size = n;

	function<int(int)> LEFT = [&](int root){
		return (root << 1) + 1;
	};
	function<int(int)> RIGHT = [&](int root){
		return (root << 1) + 2;
	};
	function<void(int)> MAX_HEAPIFY = [&](int root){
		int l = LEFT(root);
		int r = RIGHT(root);
		int largest = root;

		if (l < heap_size && a[l] > a[largest])
			largest = l;
		if (r < heap_size && a[r] > a[largest])
			largest = r;
		if (largest != root) {
			swap(a[root], a[largest]);
			MAX_HEAPIFY(largest);
		}
	};

	function<void(int)> MAX_HEAPIFY_ITER = [&](int root){
		while (true){
			int l = LEFT(root);
			int r = RIGHT(root);
			int largest = root;

			if (l < heap_size && a[l] > a[largest])
				largest = l;
			if (r < heap_size && a[r] > a[largest])
				largest = r;
			if (largest != root) {
				swap(a[root], a[largest]);
				root = largest;
			} else return;
				
		}
	};

	function<void(void)> BUILD_MAX_HEAP = [&](void){
		heap_size = n;
		for (int i = n / 2 - 1; i >= 0; i--)
			MAX_HEAPIFY(i);
	};

	function<void(void)> HEAPSORT = [&](void) {
		BUILD_MAX_HEAP();
		for (int i = n - 1; i >= 1; i--) {
			swap(a[0], a[i]);
			--heap_size;
			MAX_HEAPIFY_ITER(0);
		}
	};
	

	for (auto& x : a) cout << x << sp;
	cout << endl;
	HEAPSORT();
	for (auto& x : a) cout << x << sp;
	cout << endl;
}

int main(void){
    int t = 1;
    while (t--) solve();
    return 0;
}
