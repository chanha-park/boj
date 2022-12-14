#include <cstdio>
#include <map>
#include <vector>

namespace myStd {

class map : public std::map<int, int> {
 public:
  void insert(std::pair<int, int> n) {
    std::map<int, int>::iterator it = this->find(n.first);
    if (it == this->end())
      this->std::map<int, int>::insert(std::make_pair(n.first, n.second));
    else
      it->second += 1;
  }
};

struct Pair {
  int p;
  int order;
  int remainder;

  Pair(void) : p(0), order(0), remainder(0) {}
  Pair(int p, int order, int remainder)
      : p(p), order(order), remainder(remainder) {}
};

int pow(int base, int exp) {
  int ret = 1;

  while (exp > 0) {
    ret *= base;
    exp--;
  }
  return (ret);
}

}  // namespace myStd

myStd::map factor;
std::vector<Pair> crt;

// int is_prime(int n) {
//   if (factor.find(n) != factor.end())
//     return (1);
//   if (n == 1)
//     return (0);
//   if (n <= 3)
//     return (1);
//   if (n % 2) {
//     for (int i = 3; i <= n / i; i += 2) {
//       if (n % i == 0)
//         return (0);
//     }
//     return (1);
//   }
//   return (0);
// }

// int totient(int n) {
//   int count = n;

//   for (int i = 2; i <= count; i++) {
//     if (is_prime(i) && count % i == 0) {
//       count -= count / i;
//     }
//   }
//   return (count);
// }

// int f_(int a, int b, int c) {
//   int tot = totient(c);
//   int ret = 1;

//   b %= tot;
//   a %= c;
//   while (b--) {
//     ret *= a;
//     ret %= c;
//   }
//   return (ret);
// }

void factorize(int n) {
  int p, order;

  if (n == 1)
    return;

  order = 0;
  while ((n & 1) == 0) {
    n >>= 1;
    order++;
  }
  if (order)
    factor.insert(std::make_pair(2, order));

  for (p = 3; p <= n / p; p += 2) {
    while (n % p == 0) {
      order = 0;
      n /= p;
      order++;
      factor.insert(std::make_pair(p, order));
    }
  }
  factor.insert(std::make_pair(n, 1));
}

void get_crt(int a, int b, int p, int order) {
  if (a % p == 0) {
    if (b >= order)
      crt.push_back(Pair(p, order, 0));
    else
      crt.push_back(Pair(p, order, myStd::pow(p, )));
  }
  else {
	  int	k = myStd::pow(p, order);
	  int	tot = (p - 1) * (k / p);
	  b %= tot;
	  a %= k;
	  crt.push_back(Pair(p, order, myStd::pow(a, b) % k));
  }
}

int main(void) {
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);

  printf("c: %d\n", c);
  factorize(c);

  a %= c;

  for (std::map<int, int>::iterator it = factor.begin(); it != factor.end();
       ++it) {
    get_crt(a, b, it->first, it->second);
  }

  // for (std::map<int, int>::iterator it = factor.begin(); it != factor.end();
  //      ++it) {
  //   printf("p: %d, order: %d\n", it->first, it->second);
  // }
  // printf("%d\n", f_(a, b, c));
  return (0);
}
