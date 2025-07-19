#include <vector>
using int64 = long long;
namespace segment_tree {
template <typename Info>
class SegmentTree {
  public:
    SegmentTree() = delete;
    SegmentTree(size_t n) : d_size(n),
                            d_tree(std::vector<Node>((n << 2))) { build(0, n - 1); }
    SegmentTree(const std::vector<Info>& info) : d_size(info.size()),
                                                 d_tree(std::vector<Node>((info.size() << 2))) {
        build(0, info.size() - 1, info);
    }

    void change(const int& l, const int& r, const int64& x, const int& p = 1) {
        auto& nodep = node(p);
        if (nodep.is_inner(l, r)) {
            nodep.apply(x);
            return;
        }
        node(p << 1).apply(nodep.tag());
        node(p << 1 | 1).apply(nodep.tag());
        nodep.clear_tag();
        int mid = nodep.mid();
        if (l <= mid) change(l, r, x, p << 1);
        if (r > mid) change(l, r, x, p << 1 | 1);
        nodep.merge(node(p << 1), node(p << 1 | 1));
    }
    void change(const int& index, const int64& x) { return change(index, index, x); }

    Info ask(const int& l, const int& r, const int& p = 1) {
        auto& nodep = node(p);
        if (nodep.is_inner(l, r)) return nodep.get_info();
        node(p << 1).apply(nodep.tag());
        node(p << 1 | 1).apply(nodep.tag());
        nodep.clear_tag();
        int mid = nodep.mid();
        if (l > mid) return ask(l, r, p << 1 | 1);
        if (r <= mid) return ask(l, r, p << 1);
        Info result;
        result.merge(ask(l, r, p << 1), ask(l, r, p << 1 | 1));
        return result;
    }
    Info ask(const int& index) { return ask(index, index); }
    size_t size() { return d_size; }

  private:
    class Node {
      public:
        Node() { d_info.clear_tag(d_tag); }
        void init(int _l, int _r) { l = _l, r = _r, d_info.clear_tag(d_tag); }
        bool is_leaf() { return l == r; }
        void set_info(const Info& info) { d_info = info; }
        const Info& get_info() { return d_info; }
        const int64& tag() { return d_tag; }
        void clear_tag() { d_info.clear_tag(d_tag); }
        void apply(const int64& x) { d_info.apply(x, l, r, d_tag); }
        void merge(const Node& x, const Node& y) { d_info.merge(x.d_info, y.d_info); }
        bool is_inner(const int& _l, const int& _r) { return _l <= l && _r >= r; }
        int mid() { return l + ((r - l) >> 1); }

      protected:
        int l, r;
        int64 d_tag;
        Info d_info;
    };
    Node& node(size_t index) { return d_tree.at(index); }
    void build(const int& l, const int& r, const std::vector<Info>& info = {}, const int& p = 1) {
        node(p).init(l, r);
        if (l == r) {
            if (!info.empty()) {
                node(p).set_info(info.at(l));
                node(p).init(l, r);
            }
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(l, mid, info, p << 1);
        build(mid + 1, r, info, p << 1 | 1);
        node(p).merge(node(p << 1), node(p << 1 | 1));
    }
    size_t d_size;
    std::vector<Node> d_tree;
};

struct Info {
    Info() {
    }  // init
    void merge(const Info& lhs, const Info& rhs) {
    }  // pushup
    void apply(const int64& x, const int& l, const int& r, int64& tag) {
    }  // apply x to this info
    void clear_tag(int64& tag) {
    }  // clear tag after pushdown
};
}  // namespace segment_tree