#include "../include/block.hpp"

Block::Block(const double new_edge_lenght,
             math_lib::Vector3D new_starting_point)
    : edge_length{new_edge_lenght}, starting_point(new_starting_point) {
  block_coordinates =
      math_lib::get_block_3d_matrix(this->edge_length, this->starting_point);
}

[[nodiscard]] auto Block::get_edge_length() const -> double {
  return edge_length;
}
[[nodiscard]] auto Block::get_starting_point() const -> math_lib::Vector3D {
  return starting_point;
}

auto Block::set_edge_length(const double new_edge_length) -> void {
  edge_length = new_edge_length;
}
auto Block::set_starting_point(const math_lib::Vector3D new_starting_point)
    -> void {
  starting_point = new_starting_point;
}

auto Block::apply_rotation_x(const double &theta) -> void {
  auto rotation_matrix_x = math_lib::get_rotation_matrix_3d_x(theta);
  for (int i = 0; i < 8; i++) {
    this->block_coordinates[i] =
        math_lib::rotate_point(rotation_matrix_x, block_coordinates[i]);
  }
}
auto Block::apply_rotation_y(const double &theta) -> void {
  auto rotation_matrix_y = math_lib::get_rotation_matrix_3d_y(theta);
  for (int i = 0; i < 8; i++) {
    this->block_coordinates[i] =
        math_lib::rotate_point(rotation_matrix_y, block_coordinates[i]);
  }
}
auto Block::apply_rotation_z(const double &theta) -> void {
  auto rotation_matrix_z = math_lib::get_rotation_matrix_3d_z(theta);
  for (int i = 0; i < 8; i++) {
    this->block_coordinates[i] =
        math_lib::rotate_point(rotation_matrix_z, block_coordinates[i]);
  }
}
auto Block::apply_all_rotations(const double &theta) -> void {
  apply_rotation_x(theta);
  apply_rotation_y(theta);
  apply_rotation_z(theta);
}
