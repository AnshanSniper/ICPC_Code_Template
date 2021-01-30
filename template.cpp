#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
const double pi = acos(-1);
const double eps = 1e-8;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;

//快读
int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

//快速幂
ll qp(ll a, ll b, ll mod) {
    ll ans = 1 % mod;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}

//快速加
ll qa(ll base, ll cnt, ll mod) {
    ll res = 0;
    while (cnt) {
        if (cnt & 1) res = (res + base) % mod;
        base = (base + base) % mod;
        cnt >>= 1;
    }
    return res;
}

//乘法逆元
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

//欧拉函数
ll eular(ll n) {
    ll ans = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

//最长上升子序列
int lis() {
    for (int i = 1; i <= n; ++i) {
        f[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) res = max(res, f[i]);
    return res;
}

//树状数组
int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += v;
}

int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

//扩展中国剩余定理
ll excrt() {
    ll x, y;
    ll m = p[0], res = a[0];
    for (int i = 1; i < n; ++i) {
        ll d = exgcd(m, p[i], x, y), c = (a[i] - res % p[i] + p[i]) % p[i];
        if (c % d) return -1;
        x = qa(x, c / d, p[i] / d);
        res += x * m;
        m *= p[i] / d;
        res = (res % m + m) % m;
    }
    if (!res) return m;
    return res;
}

//进制转换
ll convert_10(ll m, string a) {
    ll sum = 0, n = a.length();
    for (int i = 0; i < n; i++) {
        if (a[i] >= '0' && a[i] <= '9') sum = sum * m + a[i] - '0';
        else sum = sum * m + a[i] - 'A' + 10;
    }
    return sum;
}

void convert_m(ll num, ll m) {
    int a[100], x = 0;
    while (num) {
        a[x++] = num % m;
        num /= m;
    }
    for (int i = x - 1; i >= 0; i--) {
        if (a[i] >= 0 && a[i] <= 9) cout << a[i];
        else cout << char(a[i] - 10 + 'A');
    }
    cout << endl;
}

//因子个数
int cfn(int n) {
    int s = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int a = 0;
            while (n % i == 0) {
                n /= i;
                a++;
            }
            s *= a + 1;
        }
    }
    if (n > 1) s *= 2;
    return s;
}

void solve() {

}

int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
