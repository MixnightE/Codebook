const int N = 1000;
bool sieve[N];

void linear_sieve(vector<int> &prime) {
  for (int i = 2; i < N; i++) {
    if (!sieve[i]) prime.push_back(i);
    for (int p : prime) {
      if (i * p >= N) break;
      sieve[i * p] = true;
      if (i % p == 0) break;
    }
  }
  for (auto &it : prime) cout << it << " ";
}
