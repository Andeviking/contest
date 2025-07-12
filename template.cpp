#include <bit>
#include <cstddef>
#include <cstdint>

#include "bits/stdc++.h"
using pii = std::pair<int, int>;
constexpr uint32_t mod = 998244353;

namespace util {
template <typename T, typename... Sizes>
constexpr auto make_nd_vector(size_t first, Sizes... sizes)
{
    if constexpr (sizeof...(sizes) == 0)
        return std::vector<T>(first);
    else
        return std::vector<decltype(make_nd_vector<T>(sizes...))>(first, make_nd_vector<T>(sizes...));
}

constexpr uint64_t qpow(uint64_t a, int64_t b)
{
    uint64_t ans = 1;
    a = b < 0 ? qpow(a, mod - 2) : a % mod;
    for (b = abs(b); b; b >>= 1, (a *= a) %= mod)
        if (b & 1)
            (ans *= a) %= mod;
    return ans % mod;
}

constexpr int lg(uint64_t x)  // -1 if 0
{
    return std::bit_width(x) - 1;
}
}  // namespace util

void solve()
{
}

int main()
{
    uint32_t t = 1;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}
