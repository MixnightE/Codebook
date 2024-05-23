vector<vector<int>> path;
int cost[N];
bool vis[N];

int dfs(int u, int pre) {
  int sum = 1, ans = 0;
  for (auto v : path[u]) {
    if (v != pre) {
      ans = dfs(v, u);
      sum += ans;
      cost[u] = max(cost[u], ans);
    }
  }
  cost[u] = max(cost[u], n - sum);
  return sum;
}

void solve() {
  cin >> n;
  memset(vis, false, sizeof(vis));
  memset(cost, 0, sizeof(cost));
  path.assign(n + 1, vector<int>());
  for (int i = 1; i < n; ++i) {
    cin >> x >> y;
    path[x].push_back(y);
    path[y].push_back(x);
  }
  dfs(1, 0);
  int mn = 0x7fffffff;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (cost[i] < mn) {
      mn = cost[i];
      ans = i;
    }
  }
  queue<pii> q;
  q.emplace(ans, 1);
  int mx = 0;
  vis[ans] = 1;
  while (!q.empty()) {
    auto [u, len] = q.front();
    mx = max(mx, len);
    q.pop();
    for (auto v : path[u]) {
      if (!vis[v]) {
        vis[v] = 1;
        q.emplace(v, len + 1);
      }
    }
  }
  cout << mx << endl;
  for (int i = 0; i < mx; i++) {
    cout << ans << ' ' << i << endl;
  }
}
