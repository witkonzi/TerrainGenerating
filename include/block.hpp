#pragma once

#include "../include/math_lib.hpp"

class Block {
private:
  double edge_length;
  math_lib::Vector3D starting_point;

  math_lib::BlockPoints block_coordinates;

public:
  Block(const double new_edge_lenght, math_lib::Vector3D new_starting_point);

  [[nodiscard]] auto get_edge_length() const -> double;
  [[nodiscard]] auto get_starting_point() const -> math_lib::Vector3D;

  auto set_edge_length(const double new_edge_length) -> void;
  auto set_starting_point(const math_lib::Vector3D new_starting_point) -> void;

  auto apply_rotation_x(const double &theta) -> void;
  auto apply_rotation_y(const double &theta) -> void;
  auto apply_rotation_z(const double &theta) -> void;
  auto apply_all_rotations(const double &theta) -> void;
};
