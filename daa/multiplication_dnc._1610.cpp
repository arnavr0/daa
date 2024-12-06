#include <bits/stdc++.h>
using namespace std;
long power(int x, unsigned n)
{
    
    long long pow = 1;
    for (int i = 0; i < n; i++) {
        pow = pow * x;
    }
 
    return pow;
}

int makeequal(long long &num1, long long &num2, int a, int b) {
  int flag = 1;
  if ( a == b) {
    return 1;
  }
  if (a > b) {
    
    for (int i = 0; i < a - b; i++) {
      num2 = num2 * 10;
      flag = flag * 10;
      
    }
  
  } else {
    for (int i = 0; i < b - a; i++) {
      num1 = num1 * 10;
      flag = flag * 10;
    }
    
  }
  return flag;
}
long long karatsuba(long long x, long long y) {

  if (x < 10 || y < 10) {
    return x * y;
  }

  int a = to_string(x).length();
  int b = to_string(y).length();

  int flag = makeequal(x, y, a, b);
  int n = max(a, b);
  int m = n / 2;
  long long xh = x / power(10, m);
  long long yh = y / power(10, m);
  long long xl = x % (power(10, m));
  long long yl = y % (power(10, m));
  long long xhyh = karatsuba(xh, yh);
  long long xlyl = karatsuba(xl, yl);
  long long xhyl = karatsuba(xh , yl);
    long long xlyh = karatsuba(xl , yh);

  return (xhyh * (pow(10, 2 * m)) + (xhyl+xlyh) * (pow(10, m)) + xlyl) / flag;
}
int main() {
  long long x = 1214;
  long long y = 1456;
  long long p = karatsuba(x, y);
  cout << p << endl;
}