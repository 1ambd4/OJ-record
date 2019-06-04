#include <iostream>
#include <cstring>
using namespace std;

const int MAX= 100000 + 10;
int prime[MAX];
bool not_prime[MAX * 10];
int prime2[MAX * 10];

void _get_prime() {
  memset(prime, 0, sizeof(prime));

  for (int i = 2; i <= MAX; ++i) {
    if (!prime[i]) prime[++prime[0]] = i;
    int tmp = MAX / i;
    for (int j = 1; j <= prime[0] && prime[j] <= tmp; j++) {
      prime[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}

void get_prime(int L, int R) {
  memset(not_prime, 0, sizeof(not_prime));
  if (L < 2) L = 2;
  for (int i = 1; i <= prime[0] && (long long)prime[i] * prime[i] <= R; ++i) {
    int s = L / prime[i] + (L % prime[i] > 0);
    if (s == 1) s = 2;
    for (int j = s; (long long)j * prime[i] <= R; ++j) {
      if ((long long)j * prime[i] >= L) {
        not_prime[j * prime[i] - L] = true;
      }
    }
  }

  prime2[0] = 0;
  for (int i = 0; i <= R-L; ++i) {
    if (!not_prime[i]) {
      prime2[++prime2[0]] = i + L;
    }
  }
}

int main(void) {
  _get_prime();
  int L, U;
  while (cin >> L >> U) {
    get_prime(L, U);
    if (prime2[0] < 2) cout << "There are no adjacent primes." << endl;
    else {
      int x1 = 0, x2 = 100000000, y1 = 0, y2 = 0;
      for (int i = 1; i < prime2[0]; ++i) {
        if (prime2[i+1] - prime2[i] < x2 - x1) {
          x1 = prime2[i];
          x2 = prime2[i+1];
        }
        if (prime2[i+1] - prime2[i] > y2 - y1) {
          y1 = prime2[i];
          y2 = prime2[i+1];
        }
      }
      cout << x1 << "," << x2 << " are closest, " << y1 << "," << y2 << " are most distant." << endl;
    }
  }
  return 0;
}
