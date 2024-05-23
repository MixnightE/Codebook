// return {f(n), f(n + 1)}
pair<int, int> fib(int n) {
  if (n == 0) return {0, 1};
  auto p = fib(n >> 1);
  int c = p.first * (2 * p.second - p.first);
  int d = p.first * p.first + p.second * p.second;
  // c %= mod, d %= mod; // if u need mod
  if (n & 1) return {d, c + d};
  else return {c, d};
}

// 在我們對Fib() % m 時，每隔 get_pisano(m) 時就會重複
int get_pisano(int m) {
  int a = 0, b = 1, c;
  for (int i = 0; i < m * m; i++) {
    c = (a + b) % m;
    a = b;
    b = c;
    if (a == 0 && b == 1) return i + 1;
  }
}
