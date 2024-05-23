class DiffBIT {
private:
  vector<int> tree;
  int n;

  void add(int x, int delta) {
    while (x <= n) {
      tree[x] += delta;
      x += x & -x;
    }
  }

public:
  DiffBIT(int n) : n(n), tree(n + 1, 0) {}

  void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
  }

  int query(int x) {
    int ret = 0;
    while (x > 0) {
      ret += tree[x];
      x -= x & -x;
    }
    return ret;
  }
};