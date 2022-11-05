#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int n, q;
int arr[101010];
const int sz = 1800;
vector<int> node[60];

void _update(int x, int a, int b){
	if(a){
		for(int i=0; i<node[x].size(); i++){
			if(node[x][i] == a){
				node[x].erase(node[x].begin() + i);
				break;
			}
		}
	}
	for(int i=0; i<=node[x].size(); i++){
		if(i == node[x].size() || node[x][i] >= b){
			node[x].insert(node[x].begin() + i, b);
			break;
		}
	}
}

void update(int x, int v){
	_update(x/sz, arr[x], v);
	arr[x] = v;
}

int query(int s, int e, int k){
	if(s/sz == e/sz){
		int ret = 0;
		for(; s<=e; s++) ret += (arr[s] > k);
		return ret;
	}
	int si = s/sz, ei = e/sz;
	int ret = 0;
	for(; s<si*sz+sz; s++) ret += arr[s] > k;
	for(; e>=ei*sz; e--) ret += arr[e] > k;
	for(int i=si+1; i<ei; i++) ret += node[i].end() - upper_bound(node[i].begin(), node[i].end(), k);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1; i<n/sz; i++) node[i].reserve(sz + 1);
	for(int i=1; i<=n; i++){
		int t; cin >> t;
		update(i, t);
	}
	cin >> q;
	while(q--){
		int op; cin >> op;
		if(op == 2){
			int a, b, c; cin >> a >> b >> c;
			cout << query(a, b, c) << "\n";
		}else{
			int a, b; cin >> a >> b;
			update(a, b);
		}
	}
}
