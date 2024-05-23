vector<vector<int>> path;
vector<int> deg;
bool vis[N];

vector<int> tree_centor() {
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 1) q.push(i);
  }
  int num = n;
  while (num > 2) {
    int siz = q.size();
    num -= siz;
    for (int i = 1; i <= siz; ++i) {
      int u = q.front();
      q.pop();
      --deg[u];
      for (auto v : path[u]) {
        if (--deg[v] == 1) { q.push(v); }
      }
    }
  }
  vector<int> ans;
  while (!q.empty()) {
    ans.push_back(q.front());
    q.pop();
  }
  return ans;
}
