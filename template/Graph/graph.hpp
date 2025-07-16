#include <vector>

namespace graph {
struct Edge {
    int to, weight = 0;
};
class Graph {
  public:
    Graph() = delete;
    Graph(size_t n) : d_e(std::vector<std::vector<Edge>>(n + 1)), d_size(n) {}

    void add_directed_edge(int u, int v, int w = 1) { d_e.at(u).emplace_back(v, w); }
    void add_undirected_edge(int u, int v, int w = 1) {
        d_e.at(u).emplace_back(v, w);
        d_e.at(v).emplace_back(u, w);
    }
    const std::vector<Edge>& operator[](size_t index) { return d_e.at(index); }
    size_t size() { return d_size; }
    void reverse() {
        std::vector<std::vector<Edge>> tmp(d_size + 1);
        for (int x = 0; x <= d_size; ++x)
            for (const auto& [y, weight] : d_e[x])
                tmp.at(y).emplace_back(x, weight);
        d_e.swap(tmp);
    }

  private:
    std::vector<std::vector<Edge>> d_e;
    size_t d_size;
};
}  // namespace graph