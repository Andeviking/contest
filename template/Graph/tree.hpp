
#include <cstddef>
#include <vector>
namespace tree {
class Tree {
  public:
    Tree() = delete;
    Tree(size_t n) : d_size(n), d_tree(std::vector<std::vector<int>>(n + 1)), d_fa(std::vector<int>(n + 1)) {}
    void add_edge(size_t u, size_t v) {
        d_tree.at(u).emplace_back(v);
        d_fa.at(v) = u;
    }
    const std::vector<int>& operator[](const size_t& index) { return d_tree.at(index); }
    size_t size() { return d_size; }

  private:
    std::vector<std::vector<int>> d_tree;
    std::vector<int> d_fa;
    size_t d_size;
};
}  // namespace tree