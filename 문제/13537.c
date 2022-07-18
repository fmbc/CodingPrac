#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100001;

int n, m;
vector<int> tree[MAXN * 4];

void update(int index, int target, int value, int start, int end) {
	if (target < start || target > end)
		return;
	tree[index].push_back(value);
	if (start != end) {
		int mid = (start + end) / 2;
		update(index * 2, target, value, start, mid);
		update(index * 2 + 1, target, value, mid + 1, end);
	}
}

int query(int index, int value, int left, int right, int start, int end) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[index].end() - upper_bound(tree[index].begin(), tree[index].end(), value);
	else {
		int mid = (start + end) / 2;
		return query(index * 2, value, left, right, start, mid) +
			query(index * 2 + 1, value, left, right, mid + 1, end);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int val;
	for (int i = 1; i <= n; ++i) {
		cin >> val;
		update(1, i, val, 1, n);
	}
	int range = MAXN * 4;
	for (int i = 1; i < range; ++i)
		sort(tree[i].begin(), tree[i].end());
	cin >> m;
	int i, j, k;
	while (m--) {
		cin >> i >> j >> k;
		cout << query(1, k, i, j, 1, n) << '\n';
	}
	return 0;
}
