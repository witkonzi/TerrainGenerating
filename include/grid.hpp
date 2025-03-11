#pragma once

#include "block.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

using BlockGroup = std::vector<Block>;

class Grid {
private:
  unsigned int width;
  unsigned int length;

  BlockGroup block_group;

public:
  Grid(const unsigned int new_width, const unsigned int new_length);

  [[nodiscard]] auto get_width() const -> unsigned int;
  [[nodiscard]] auto get_length() const -> unsigned int;

  auto set_width(const double &new_x) -> void;
  auto set_length(const double &new_y) -> void;
};
