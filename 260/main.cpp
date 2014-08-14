#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = (int) 1e5 + 7;
int n, q, a[N], BLOCK_SIZE, nblocks;

struct block {
	int *cnt;
	deque<int> elem;
	block() {
		cnt = (int *) malloc(sizeof(int) * N);
		memset(cnt, 0, sizeof(int) * N);
		elem.clear();
	}
};

vector<block> lsts;

pair<int, int> get(int l) {
	int idx = l / BLOCK_SIZE;
	int startPos = l % BLOCK_SIZE;
	return make_pair(idx, startPos);	
}

int half_query(int idx, int l, int r, int k) {
	int ans = 0;
	for (int i = l; i <= r; i++) {
		if (lsts[idx].elem[i] == k) {
			ans++;
		}
	}
	return ans;
}

int query(int l, int r, int k) {
	pair<int, int> p1 = get(l);
	pair<int, int> p2 = get(r);
	int ans = 0;
	if (p1.first == p2.first) {
		ans = half_query(p1.first, p1.second, p2.second, k);
	} else {
		ans += half_query(p1.first, p1.second, (int) lsts[p1.first].elem.size() - 1, k);
		ans += half_query(p2.first, 0, p2.second, k);
		
		for (int i = p1.first + 1; i < p2.first; i++) {
			ans += lsts[i].cnt[k];
		}
	}
	return ans;
}

vector<int> unupdated_deque;
int margin;

void complete_update(int idx) {
	int prev = unupdated_deque[idx - 1 - margin];
	lsts[idx].cnt[prev] ++;
	lsts[idx].elem.push_front(prev);
	
	//
	int toRemove = unupdated_deque[idx - margin];
	lsts[idx].elem.pop_back();
	lsts[idx].cnt[toRemove]--;
}

void update(int l, int r) {
	pair<int, int> p1 = get(l);
	pair<int, int> p2 = get(r);
	if (p1.first == p2.first) {
		// update first part
		{
			int idx = p1.first;
			int last = lsts[idx].elem[p2.second];
			// no change in cnt
			for (int i = p1.second; i <= p2.second; i++) {
				int new_last = lsts[idx].elem[i];
				lsts[idx].elem[i] = last;
				last = new_last;
			}
		}
	} else {
		unupdated_deque.clear();
		for (int i = p1.first; i <= p2.first; i++) {
			unupdated_deque.push_back(lsts[i].elem.back());
		}
		margin = p1.first;
		// update first part
		{
			int idx = p1.first;
			int last = lsts[p2.first].elem[p2.second];
			int toRemove = lsts[idx].elem.back();
			lsts[idx].cnt[toRemove]--;
			int toAdd = last;
			lsts[idx].cnt[toAdd]++;
			for (int i = p1.second; i < lsts[idx].elem.size(); i++) {
				int new_last = lsts[idx].elem[i];
				lsts[idx].elem[i] = last;
				last = new_last;
			}
		}
		// update second part
		{
			int idx = p2.first;
			assert (idx > 0);
			int last = unupdated_deque[idx - 1 - margin];
			int toAdd = last;
			lsts[idx].cnt[toAdd]++;
			int toRemove = lsts[p2.first].elem[p2.second];	
			lsts[idx].cnt[toRemove]--;
			for (int i = 0; i <= p2.second; i++) {
				int new_last = lsts[idx].elem[i];
				lsts[idx].elem[i] = last;
				last = new_last;
			}
		}
		// complete update
		for (int i = p1.first + 1; i < p2.first; i++) {
			complete_update(i);
		}
	}

}

void insert(vector<int> v) {
	block my_block;
	for (int i = 0; i < v.size(); i++) {
		my_block.cnt[v[i]]++;
		my_block.elem.push_back(v[i]);
	}
	lsts.push_back(my_block);
}

int main() {
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	BLOCK_SIZE = sqrt(n) + 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		if (i > 0 && i % BLOCK_SIZE == 0) {
			insert(temp);
			temp.clear();
			temp.push_back(a[i]);
		} else {
			temp.push_back(a[i]);
		}
	}
	if (temp.size()) {
		insert(temp);
	}
	
	cin >> q;
	int lastans = 0;
	int ct = 0;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int l1, r1;
			cin >> l1 >> r1;
			int l = (l1 + lastans - 1) % n + 1;
			int r = (r1 + lastans - 1) % n + 1;
			if (l > r) swap(l, r);
			update(l - 1, r - 1);
		} else {
			int l1, r1, k1;
			cin >> l1 >> r1 >> k1;
			int l = (l1 + lastans - 1) % n + 1;
			int r = (r1 + lastans - 1) % n + 1;
			int k = (k1 + lastans - 1) % n + 1;
			l --, r --;
			if (l > r) swap(l, r);
			int ans = query(l, r, k);
			lastans = ans;
			cout << ans << endl;
		}
	}

	return 0;
}
