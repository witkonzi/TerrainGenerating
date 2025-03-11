#include "../include/math_lib.hpp"
#include <cmath>

namespace math_lib {

auto get_rotation_matrix_2d(const double &theta) -> Matrix2D {
  auto first_vector = Vector2D{cos(theta), sin(theta)};
  auto second_vector = Vector2D{-sin(theta), cos(theta)};
  auto rot_matrix = Matrix2D{first_vector, second_vector};

  return rot_matrix;
}

auto get_rotation_matrix_3d_x(const double &theta) -> Matrix3D {
  auto first_vector = Vector3D{1, 0, 0};
  auto second_vector = Vector3D{0, cos(theta), sin(theta)};
  auto third_vector = Vector3D{0, -sin(theta), cos(theta)};
  auto rot_matrix = Matrix3D{first_vector, second_vector, third_vector};

  return rot_matrix;
}

auto get_rotation_matrix_3d_y(const double &theta) -> Matrix3D {
  auto first_vector = Vector3D{cos(theta), 0, -sin(theta)};
  auto second_vector = Vector3D{0, cos(theta), sin(theta)};
  auto third_vector = Vector3D{sin(theta), 0, cos(theta)};
  auto rot_matrix = Matrix3D{first_vector, second_vector, third_vector};

  return rot_matrix;
}

auto get_rotation_matrix_3d_z(const double &theta) -> Matrix3D {
  auto first_vector = Vector3D{cos(theta), sin(theta), 0};
  auto second_vector = Vector3D{-sin(theta), cos(theta), 0};
  auto third_vector = Vector3D{0, 0, 1};
  auto rot_matrix = Matrix3D{first_vector, second_vector, third_vector};

  return rot_matrix;
}

auto multiply_matrixes(const Matrix3D &matrix_1, const Matrix3D &matrix_2)
    -> Matrix3D {
  Matrix3D result_matrix;

  /*Initializing result matrix with zeros*/
  for (auto &row : result_matrix) {
    for (auto &elem : row) {
      elem = 0.0;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        result_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
      }
    }
  }
  return result_matrix;
}

auto rotate_point(const Matrix3D &matrix, const Vector3D &point) -> Vector3D {
  /*Initizaling rotated_point with zeros*/
  Vector3D rotated_point = {0.0, 0.0, 0.0};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      rotated_point[i] += matrix[j][i] * point[j];
    }
  }
  return rotated_point;
}

auto get_block_3d_matrix(const double &edge_length,
                         const Vector3D &starting_point) -> BlockPoints {
  BlockPoints result;

  /*Initializing result matrix with zeros*/
  for (auto &row : result) {
    for (auto &elem : row) {
      elem = 0.0;
    }
  }

  for (int i = 0; i < 3; i++) {
    Vector3D helper = {0.0, 0.0, 0.0};
    helper[i] = 1;
    result[i] = helper;

    Vector3D not_helper;
    for (int j = 0; j < 3; j++) {
      not_helper[j] = !(helper[j]);
    }
    result[i + 4] = not_helper;
  }
  result[3] = {0.0, 0.0, 0.0};
  result[7] = {1.0, 1.0, 1.0};

  for (int k = 0; k < 8; k++) {
    for (int l = 0; l < 3; l++) {
      if (result[k][l] == 0) {
        result[k][l] = starting_point[l];
      } else {
        result[k][l] = starting_point[l] + edge_length;
      }
    }
  }
  return result;
}

} // namespace math_lib
