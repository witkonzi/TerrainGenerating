#include "../include/grid.hpp"

Grid::Grid(const unsigned int new_width, const unsigned int new_length)
    : width{new_width}, length{new_length} {}

auto Grid::get_width() const -> unsigned int { return width; }
auto Grid::get_length() const -> unsigned int { return length; }

auto Grid::set_width(const double &new_width) -> void { width = new_width; }
auto Grid::set_length(const double &new_length) -> void { length = new_length; }
