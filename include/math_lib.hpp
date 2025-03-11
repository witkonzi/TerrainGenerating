#pragma once

#include <array>

namespace math_lib {
using Vector2D = std::array<double, 2>;
using Vector3D = std::array<double, 3>;

using Matrix2D = std::array<std::array<double, 2>, 2>;
using Matrix3D = std::array<std::array<double, 3>, 3>;

using BlockPoints = std::array<std::array<double, 3>, 8>;

auto get_rotation_matrix_2d(const double &theta) -> Matrix2D;

auto get_rotation_matrix_3d_x(const double &theta) -> Matrix3D;
auto get_rotation_matrix_3d_y(const double &theta) -> Matrix3D;
auto get_rotation_matrix_3d_z(const double &theta) -> Matrix3D;

auto multiply_matrixes(const Matrix3D &matrix_1, const Matrix3D &matrix_2)
    -> Matrix3D;
auto rotate_point(const Matrix3D &matrix, const Vector3D &point) -> Vector3D;

auto get_block_3d_matrix(const double &edge_length,
                         const Vector3D &starting_point) -> BlockPoints;
} // namespace math_lib
