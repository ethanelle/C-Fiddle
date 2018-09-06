/*  Challenge #367
    Subfactorials
    Ethan Elliott
    Sept. 5, 2018
*/
#include <iostream>
using namespace std;

long subfactorial(int num) {
  if(num == 0)
    return 1;
  if(num == 1)
    return 0;
  return (num - 1) * (subfactorial(num - 1) + subfactorial(num - 2));
}

int main() {
  cout << subfactorial(6) << endl;
  cout << subfactorial(9) << endl;
  cout << subfactorial(14) << endl;
}
