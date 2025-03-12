#include <iostream>
#include <vector>
#include <algorithm>

const long long MAXN = 1e10;
const long long INF = MAXN;
std::vector <std::vector<long long>> t(4 * MAXN);

void build(int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = std::vector<long long>(1, a[tl]);
	else {
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		std::merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(),
			back_inserter(t[v]));
	}
}

int query(int v, int tl, int tr, int l, int r, int x) {
	if (l > r)
		return INF;
	if (l == tl && tr == r) {
		std::vector<long long>::iterator pos = std::lower_bound(t[v].begin(), t[v].end(), x);
		if (pos != t[v].end())
			return *pos;
		return INF;
	}
	int tm = (tl + tr) / 2;
	return std::min(
		query(v * 2, tl, tm, l, std::min(r, tm), x),
		query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, x)
	);
}

void update(int v, int tl, int tr, int pos, int new_val) {
	t[v].erase(t[v].find(a[pos]));
	t[v].insert(new_val);
	if (tl != tr) {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos, new_val);
		else
			update(v * 2 + 1, tm + 1, tr, pos, new_val);
	}
	else
		a[pos] = new_val;
}

