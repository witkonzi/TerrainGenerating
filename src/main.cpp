#include "../include/math_lib.hpp"
#include <iostream>

int main() {
  auto jp = math_lib::get_block_3d_matrix(5, {1, 2, 0});
  for (auto &row : jp) {
    for (const auto &elem : row) {
      std::cout << elem << ' ';
    }
    std::cout << std::endl;
  }

  return 0;
}