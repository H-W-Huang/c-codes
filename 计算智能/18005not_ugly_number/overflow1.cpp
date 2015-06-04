#include <iostream>
#include <set>      // could also use an unordered_set, except that it turns
                    // out to be a pessimization

void generate_uglies(unsigned n, std::set<unsigned> &num, unsigned threshold) {
  // Abort recursion if we break the upper limit or find a number
  // that was already tested
  if(n <= threshold && num.find(n) == num.end()) {
    // Remember this ugly number
    num.insert(n);

    // Since n is an ugly number, these three are also ugly numbers.
    generate_uglies(n * 2, num, threshold);
    generate_uglies(n * 3, num, threshold);
    generate_uglies(n * 5, num, threshold);
  }
}

int main() {
  std::set<unsigned> num;

  generate_uglies(1, num, 100000000);

  std::cout << num.size() << std::endl;
}