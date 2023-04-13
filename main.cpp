#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

vi list{};
void solve(int n, int m, const vi& v, int b) {
	if (m == list.size()) {
		for (const auto& x : list) {
			cout << x << ' ';
		}

		cout << '\n';

		return;
	}

	for (auto i = b; i < n; ++i) {
		list.push_back(v[i]);
		solve(n, m, v, i);
		list.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	auto v = vi(n);
	for (auto i = 0; i < n; ++i) {
		cin >> v[i];
	}

	list.reserve(n);

	sort(v.begin(), v.end());
	solve(n, m, v, 0);

	return 0;
}