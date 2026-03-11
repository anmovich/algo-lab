#include <iostream>
using namespace std;

long long extended_gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) { // если b равно 0, то gcd = a, и x = 1, y = 0
    x = 1;
    y = 0;
    return a;
  }
  // Рекурсивно вызываем для пары (b, a % b)
  long long x1, y1;
  long long g = extended_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}

int main() {
  cout << "Серёгин Михаил Всеволодович Рпиб-о25" << endl;
  long long a, n;
  cin >> a >> n;
  long long x, y;
  long long g = extended_gcd(a, n, x, y);

  if (g != 1) { // если НОД не равен 1 то обратного элемента не существует
    cout << 0 << endl;
  } else {
    // Приводим x к положительному значению в диапазоне [0, n-1]
    long long result = x % n;
    if (result < 0)
      result += n;
    cout << result << endl;
  }

  return 0;
}
