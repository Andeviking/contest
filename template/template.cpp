#include "bits/stdc++.h"

namespace datatype {
using uint64 = unsigned long long;
using int64 = long long;
using int128 = __int128;
using uint128 = unsigned __int128;
using uint32 = unsigned int;
using pii = std::pair<int, int>;

template <typename T>
    requires(std::same_as<T, __int128> || std::same_as<T, unsigned __int128>)
std::ostream& operator<<(std::ostream& os, T x) {
    if (x < 0) os.put('-'), x = -x;
    if (x > 9) operator<<(os, x / 10);
    os.put('0' + x % 10);
    return os;
}
template <typename T>
    requires(std::same_as<T, __int128> || std::same_as<T, unsigned __int128>)
std::istream& operator>>(std::istream& is, T& x) {
    x = 0;
    int flag = 1;
    char c = 0;
    while (is.get(c) && !std::isdigit(c))
        if (c == '-') flag = -1;
    while (std::isdigit(c)) {
        x = (x << 3) + (x << 1) + (c ^ 48);
        if (!is.get(c)) break;
    }
    x *= flag;
    return is;
}
}  // namespace datatype
using namespace datatype;

namespace util {
constexpr int lg(uint64 x) { return std::bit_width(x) - 1; }  // -1 if 0
void set_precision(int n) { std::cout << std::fixed << std::setprecision(n); }

template <typename T = int, typename... Sizes>
constexpr auto make_nd_vector(size_t first, Sizes... sizes) {
    if constexpr (sizeof...(sizes) == 0)
        return std::vector<T>(first);
    else
        return std::vector(first, make_nd_vector<T>(sizes...));
}
template <typename T = int>
constexpr auto make_filled_vector(size_t size) {
    std::vector<T> result(size);
    for (auto& c : result)
        std::cin >> c;
    return result;
}
template <typename T, typename U, typename Compare = std::less<>>
void sort_bind(std::vector<T>& a, std::vector<U>& b, Compare cmp = {}) {
    const size_t n = a.size();
    std::vector<size_t> idx(n);
    std::iota(idx.begin(), idx.end(), size_t{0});
    std::sort(idx.begin(), idx.end(), [&](size_t i, size_t j) { return cmp(a[i], a[j]); });

    std::vector<T> a_sorted(n);
    std::vector<U> b_sorted(n);
    for (size_t i = 0; i < n; ++i) {
        a_sorted[i] = a[idx[i]];
        b_sorted[i] = b[idx[i]];
    }
    a.swap(a_sorted);
    b.swap(b_sorted);
}

static constexpr uint32 mod = 998244353;
template <uint32 mod = mod>
constexpr uint64 qpow(uint64 a, int64 b) {
    uint64 ans = 1;
    a = b < 0 ? qpow<mod>(a, mod - 2) : a % mod;
    for (b = b < 0 ? -b : b; b; b >>= 1, (a *= a) %= mod)
        if (b & 1)
            (ans *= a) %= mod;
    return ans;
}
}  // namespace util

using namespace std;

void solve();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    uint32 t = 1;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}
constexpr uint32 mod = util::mod;

void solve() {
}