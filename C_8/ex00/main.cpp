#include "easyfind.hpp"
#include <vector>
int main() {
    std::vector<int> a;
    a.push_back(12);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
  std::cout << *easyfind(a, 4);
}
