#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const double pi = acos(-1);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
int a[maxn], mx[maxn << 2];

void pushup(int rt) {
    mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
    if (l == r) {
        mx[rt] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    pushup(rt);
}

void update(int pos, int num, int l, int r, int rt) {
    if (l == r) {
        mx[rt] += num;
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m) update(pos, num, l, m, rt << 1);
    if (m < pos) update(pos, num, m + 1, r, rt << 1 | 1);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return mx[rt];
    int m = (l + r) >> 1;
    int res = 0;
    if (L <= m) res = max(res, query(L, R, l, m, rt << 1));
    if (m < R) res = max(res, query(L, R, m + 1, r, rt << 1 | 1));
    return res;
}

void solve() {
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    build(1, n, 1);
    scanf("%d", &m);
    while (m--) {
        int op, al, br;
        scanf("%d %d %d", &op, &al, &br);
        if (op == 2) printf("%d\n", query(al, br, 1, n, 1));
        else update(al, br, 1, n, 1);
    }
}

int main() {
    solve();
    return 0;
}
