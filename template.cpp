#include "bits/stdc++.h"

using pii = std::pair<int, int>;
constexpr uint32_t mod = 998244353;

namespace util {
constexpr int lg(uint64_t x) { return std::bit_width(x) - 1; }  // -1 if 0

class Random {
  public:
    Random() : engine(static_cast<std::mt19937_64::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())) {}
    uint64_t randint(uint64_t low, uint64_t high) { return std::uniform_int_distribution<uint64_t>(low, high)(engine); }
    double randreal(double low, double high) { return std::uniform_real_distribution<double>(low, high)(engine); }

  private:
    std::mt19937_64 engine;
};

template <typename T, typename... Sizes>
constexpr auto make_nd_vector(size_t first, Sizes... sizes) {
    if constexpr (sizeof...(sizes) == 0)
        return std::vector<T>(first);
    else
        return std::vector<decltype(make_nd_vector<T>(sizes...))>(first, make_nd_vector<T>(sizes...));
}

constexpr uint64_t qpow(uint64_t a, int64_t b) {
    uint64_t ans = 1;
    a = b < 0 ? qpow(a, mod - 2) : a % mod;
    for (b = abs(b); b; b >>= 1, (a *= a) %= mod)
        if (b & 1)
            (ans *= a) %= mod;
    return ans;
}
}  // namespace util

void solve() {
}

int main() {
    uint32_t t = 1;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}
