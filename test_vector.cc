#include <gtest/gtest.h>

#include <vector>

#include "s21_containers/s21_containers.h"

// ========================== SET 1 =================================

TEST(VectorTest, DefaultConstructor) {
  s21::vector<double> s21_vector;
  std::vector<double> std_vector;
  EXPECT_TRUE(s21_vector.empty());
  EXPECT_EQ(s21_vector.size(), 0);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorTest, SizeConstructor1) {
  s21::vector<double> s21_vector(10);
  std::vector<double> std_vector(10);
  EXPECT_EQ(s21_vector.size(), 10);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorTest, SizeConstructor2) {
  s21::vector<double> s21_vector(0);
  std::vector<double> std_vector(0);
  EXPECT_EQ(s21_vector.size(), 0);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorTest, InitializerListConstructor) {
  s21::vector<std::string> s21_vector = {"hello", "world"};
  std::vector<std::string> std_vector = {"hello", "world"};
  EXPECT_EQ(s21_vector.front(), "hello");
  EXPECT_EQ(s21_vector.back(), "world");
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorTest, CopyConstructor) {
  s21::vector<char> s21_vector = {'a', 'b', 'c'};
  std::vector<char> std_vector = {'a', 'b', 'c'};
  s21::vector<char> s21_copy(s21_vector);
  std::vector<char> std_copy(std_vector);
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
  EXPECT_EQ(s21_copy.size(), std_copy.size());
}

TEST(VectorTest, MoveConstructor) {
  s21::vector<int> s21_vector = {10, 20, 30};
  std::vector<int> std_vector = {10, 20, 30};
  s21::vector<int> s21_moved(std::move(s21_vector));
  std::vector<int> std_moved(std::move(std_vector));
  EXPECT_EQ(s21_moved.front(), std_moved.front());
  EXPECT_EQ(s21_moved.back(), std_moved.back());
  EXPECT_TRUE(s21_vector.empty());
  EXPECT_TRUE(std_vector.empty());
}

TEST(VectorTest, MoveAssignment) {
  s21::vector<int> s21_vector = {100, 200, 300};
  std::vector<int> std_vector = {100, 200, 300};
  s21::vector<int> s21_assigned;
  std::vector<int> std_assigned;
  s21_assigned = std::move(s21_vector);
  std_assigned = std::move(std_vector);
  EXPECT_EQ(s21_assigned.front(), std_assigned.front());
  EXPECT_EQ(s21_assigned.back(), std_assigned.back());
  EXPECT_TRUE(s21_vector.empty());
  EXPECT_TRUE(std_vector.empty());
}

TEST(VectorTest, AccessOperator1) {
  s21::vector<int> s21_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(s21_vector[2], std_vector[2]);
  EXPECT_EQ(s21_vector.at(4), std_vector.at(4));
}

TEST(VectorTest, AccessOperator2) {
  s21::vector<int> s21_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_THROW(s21_vector.at(6), std::out_of_range);
  EXPECT_THROW(std_vector.at(6), std::out_of_range);
}

TEST(VectorTest, PushBackPopBack) {
  s21::vector<float> s21_vector;
  std::vector<float> std_vector;
  s21_vector.push_back(1.5);
  std_vector.push_back(1.5);
  EXPECT_EQ(s21_vector.back(), std_vector.back());
  s21_vector.push_back(2.5);
  std_vector.push_back(2.5);
  EXPECT_EQ(s21_vector.back(), std_vector.back());
  s21_vector.pop_back();
  std_vector.pop_back();
  EXPECT_EQ(s21_vector.back(), std_vector.back());
}

TEST(VectorTest, Swap) {
  s21::vector<int> s21_vector1 = {10, 20, 30};
  s21::vector<int> s21_vector2 = {40, 50, 60};
  std::vector<int> std_vector1 = {10, 20, 30};
  std::vector<int> std_vector2 = {40, 50, 60};
  s21_vector1.swap(s21_vector2);
  std_vector1.swap(std_vector2);
  EXPECT_EQ(s21_vector1.front(), std_vector1.front());
  EXPECT_EQ(s21_vector2.back(), std_vector2.back());
  EXPECT_EQ(s21_vector1.size(), std_vector1.size());
  EXPECT_EQ(s21_vector2.size(), std_vector2.size());
}

TEST(VectorTest, ReserveCapacity) {
  s21::vector<int> s21_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  size_t newCapacity = s21_vector.capacity() + 5;
  s21_vector.reserve(newCapacity);
  std_vector.reserve(newCapacity);
  EXPECT_GE(s21_vector.capacity(), newCapacity);
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
}

TEST(VectorTest, ShrinkToFit1) {
  s21::vector<int> s21_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> std_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorTest, ShrinkToFit2) {
  s21::vector<int> s21_vector;
  s21_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.capacity(), 0U);
}

TEST(VectorTest, ShrinkToFit3) {
  s21::vector<int> s21_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_vector.pop_back();
  s21_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.capacity(), s21_vector.size());
  EXPECT_EQ(s21_vector.capacity(), 9U);
}

TEST(VectorTest, Insert1) {
  s21::vector<std::string> s21_vector = {"alpha", "beta", "gamma"};
  std::vector<std::string> std_vector = {"alpha", "beta", "gamma"};
  s21::vector<std::string>::iterator s21_it = s21_vector.begin() + 1;
  std::vector<std::string>::iterator std_it = std_vector.begin() + 1;
  s21_vector.insert(s21_it, "delta");
  std_vector.insert(std_it, "delta");
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector[1], std_vector[1]);
}

TEST(VectorTest, Insert2) {
  s21::vector<int> s21vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> stdvector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::vector<int>::iterator s21iter1 = s21vector.begin();
  std::vector<int>::iterator stditer1 = stdvector.begin();
  s21vector.insert(s21iter1, 4);
  stdvector.insert(stditer1, 4);
  s21::vector<int>::iterator s21iter2 = s21vector.end();
  std::vector<int>::iterator stditer2 = stdvector.end();
  s21vector.insert(s21iter2, 7);
  stdvector.insert(stditer2, 7);
  ASSERT_EQ(s21vector.size(), stdvector.size());
}

TEST(VectorTest, Erase) {
  s21::vector<std::string> s21_vector = {"one", "two", "three", "four"};
  std::vector<std::string> std_vector = {"one", "two", "three", "four"};
  s21::vector<std::string>::iterator s21_it = s21_vector.begin() + 2;
  std::vector<std::string>::iterator std_it = std_vector.begin() + 2;
  s21_vector.erase(s21_it);
  std_vector.erase(std_it);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector[2], std_vector[2]);
}

TEST(VectorTest, Maxsize) {
  s21::vector<int> s21_vector;
  EXPECT_GT(s21_vector.max_size(), 0U);
}

TEST(VectorTest, DataPointer) {
  s21::vector<int> s21_vector = {5, 10, 15};
  std::vector<int> std_vector = {5, 10, 15};
  int* s21_data = s21_vector.data();
  int* std_data = std_vector.data();
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_EQ(s21_data[i], std_data[i]);
  }
}

TEST(VectorTest, Clear) {
  s21::vector<int> s21_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  s21_vector.clear();
  std_vector.clear();
  EXPECT_TRUE(s21_vector.empty());
  EXPECT_TRUE(std_vector.empty());
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

// ========================== SET 2 =================================

// VECTOR
TEST(VectorTest, Constructor_default) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.data(), std_v.data());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(VectorTest, Constructor_n) {
  s21::vector<int> s21_v(5);
  std::vector<int> std_v(5);
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(VectorTest, Constructor_n_throw) {
  try {
    s21::vector<int> s21_v(-1);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(),
              std::string("cannot create s21::vector larger than max_size()"));
  }
}

TEST(VectorTest, Constructor_initializer_list_1) {
  s21::vector<int> s21_v{2, 3, 5, 7, 1};
  std::vector<int> std_v{2, 3, 5, 7, 1};
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
  EXPECT_EQ(s21_v.at(4), std_v.at(4));
}

TEST(VectorTest, Constructor_initializer_list_2) {
  std::initializer_list<int> b;
  s21::vector<int> s21_v{b};
  std::vector<int> std_v{b};
  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(VectorTest, Constructor_copy_1) {
  s21::vector<int> s21_v{2, 3, 5, 7, 1};
  std::vector<int> std_v{2, 3, 5, 7, 1};
  s21::vector<int> s21_copy(s21_v);
  std::vector<int> std_copy(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());
  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
  EXPECT_EQ(s21_v.at(4), std_v.at(4));

  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
  EXPECT_EQ(s21_copy.at(0), std_copy.at(0));
  EXPECT_EQ(s21_copy.at(1), std_copy.at(1));
  EXPECT_EQ(s21_copy.at(2), std_copy.at(2));
  EXPECT_EQ(s21_copy.at(3), std_copy.at(3));
  EXPECT_EQ(s21_copy.at(4), std_copy.at(4));
}

TEST(VectorTest, Constructor_copy_2) {
  s21::vector<int> s21_v;
  s21::vector<int> s21_copy(s21_v);
  std::vector<int> std_v;
  std::vector<int> std_copy(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());

  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_EQ(s21_copy.capacity(), std_copy.capacity());
  EXPECT_EQ(s21_copy.empty(), std_copy.empty());
}

TEST(VectorTest, Constructor_move_1) {
  s21::vector<int> s21_v;
  s21::vector<int> s21_move(s21_v);
  std::vector<int> std_v;
  std::vector<int> std_move(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());

  EXPECT_EQ(s21_move.size(), std_move.size());
  EXPECT_EQ(s21_move.capacity(), std_move.capacity());
  EXPECT_EQ(s21_move.empty(), std_move.empty());
}

TEST(VectorTest, Constructor_move_2) {
  s21::vector<int> s21_v{1, 2, 3, 4, 5};
  s21::vector<int> s21_move(s21_v);
  std::vector<int> std_v{1, 2, 3, 4, 5};
  std::vector<int> std_move(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
  EXPECT_EQ(s21_v.empty(), std_v.empty());

  EXPECT_EQ(s21_move.size(), std_move.size());
  EXPECT_EQ(s21_move.capacity(), std_move.capacity());
  EXPECT_EQ(s21_move.empty(), std_move.empty());
}

TEST(VectorTest, Destructor) {
  s21::vector<int> s21_v{1, 2, 3, 4, 5};
  s21_v.~vector();

  EXPECT_EQ(0, s21_v.size());
  EXPECT_EQ(0, s21_v.capacity());
  EXPECT_EQ(0, s21_v.data());
}

TEST(VectorTest, Operator_move_1) {
  s21::vector<int> s21_v1{1, 2, 3};
  s21::vector<int> s21_v2;
  s21_v2 = std::move(s21_v1);
  EXPECT_EQ(s21_v2.size(), 3);
  EXPECT_EQ(s21_v2.at(0), 1);
  EXPECT_EQ(s21_v2.at(1), 2);
  EXPECT_EQ(s21_v2.at(2), 3);
}

TEST(VectorTest, Operator_move_2) {
  s21::vector<int> s21_v1{1, 2, 3};
  s21::vector<int> s21_v2{4, 5, 6};
  s21_v2 = std::move(s21_v1);
  EXPECT_EQ(s21_v2.size(), 3);
  EXPECT_EQ(s21_v2.at(0), 1);
  EXPECT_EQ(s21_v2.at(1), 2);
  EXPECT_EQ(s21_v2.at(2), 3);
}

TEST(VectorTest, Element_at) {
  s21::vector<int> s21_v{1, 2, 3, 4, 5};
  std::vector<int> std_v{1, 2, 3, 4, 5};

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
  EXPECT_EQ(s21_v.at(4), std_v.at(4));
}

TEST(VectorTest, Element_at_throw) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_ANY_THROW(s21_v.at(1));
  EXPECT_ANY_THROW(std_v.at(1));
}

TEST(VectorTest, Element_front) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(s21_v.front(), std_v.front());
}

TEST(VectorTest, Element_front_throw) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_ANY_THROW(s21_v.front());
}

TEST(VectorTest, Element_back) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(s21_v.back(), std_v.back());
}

TEST(VectorTest, Element_back_throw) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  EXPECT_ANY_THROW(s21_v.back());
}

TEST(VectorTest, Element_operator_square_brackets) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_EQ(s21_v[0], std_v[0]);
  EXPECT_EQ(s21_v[1], std_v[1]);
  EXPECT_EQ(s21_v[2], std_v[2]);
}

TEST(VectorTest, Element_operator_square_brackets_throw_1) {
  s21::vector<int> s21_v{1, 2, 3};
  EXPECT_ANY_THROW(s21_v[5]);
}

TEST(VectorTest, Element_operator_square_brackets_throw_2) {
  s21::vector<int> s21_v{1, 2, 3};
  EXPECT_ANY_THROW(s21_v[-1]);
}

TEST(VectorTest, Element_data) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(*s21_v.data(), *std_v.data());
}

TEST(VectorTest, Capacity_empty_1) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(VectorTest, Capacity_empty_2) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;

  EXPECT_EQ(s21_v.empty(), std_v.empty());
}

TEST(VectorTest, Capacity_size_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;

  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(VectorTest, Capacity_size_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(VectorTest, Capacity_capacity_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;

  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_capacity_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};

  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_reserve_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  s21_v.reserve(2);
  std_v.reserve(2);
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_reserve_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.reserve(2);
  std_v.reserve(2);
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_reserve_3) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.reserve(10);
  std_v.reserve(10);
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_reserve_4_throw) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  EXPECT_ANY_THROW(s21_v.reserve(-2));
  EXPECT_ANY_THROW(std_v.reserve(-2));
}

TEST(VectorTest, Capacity_shrink_to_fit_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  s21_v.reserve(10);
  std_v.reserve(10);
  s21_v.shrink_to_fit();
  std_v.shrink_to_fit();
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_shrink_to_fit_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.reserve(10);
  std_v.reserve(10);
  s21_v.shrink_to_fit();
  std_v.shrink_to_fit();
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST(VectorTest, Modifiers_clear_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  s21_v.clear();
  std_v.clear();

  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(VectorTest, Modifiers_clear_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.clear();
  std_v.clear();

  EXPECT_EQ(s21_v.size(), std_v.size());
}

TEST(VectorTest, Modifiers_insert_1) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.insert(s21_v.begin() + 1, 5);
  std_v.insert(std_v.begin() + 1, 5);

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
}

TEST(VectorTest, Modifiers_insert_2) {
  s21::vector<int> s21_v{50, 10, 40, 20, 30};
  std::vector<int> std_v{50, 10, 40, 20, 30};
  s21_v.insert(s21_v.begin() + s21_v.size(), 100);
  std_v.insert(std_v.begin() + std_v.size(), 100);

  EXPECT_EQ(s21_v.at(5), std_v.at(5));
}

TEST(VectorTest, Modifiers_insert_3) {
  try {
    s21::vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.insert(s21_v.begin() + 10, 100);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(VectorTest, Modifiers_insert_4) {
  try {
    s21::vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.insert(s21_v.begin() - 4, 100);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(VectorTest, Modifiers_erase_1) {
  s21::vector<int> s21_v{1, 2, 3, 4};
  std::vector<int> std_v{1, 2, 3, 4};

  s21_v.erase(s21_v.begin() + 1);
  std_v.erase(std_v.begin() + 1);

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
}

TEST(VectorTest, Modifiers_erase_2) {
  s21::vector<int> s21_v{50, 10, 40, 20, 30};
  std::vector<int> std_v{50, 10, 40, 20, 30};
  s21_v.erase(s21_v.begin());
  std_v.erase(std_v.begin());

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
}

TEST(VectorTest, Modifiers_erase_3) {
  s21::vector<int> s21_v{50, 10, 40, 20, 30};
  std::vector<int> std_v{50, 10, 40, 20, 30};
  s21_v.erase(s21_v.end() - 1);
  std_v.erase(std_v.end() - 1);

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
}

TEST(VectorTest, Modifiers_erase_4) {
  try {
    s21::vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.erase(s21_v.begin() - 1);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(VectorTest, Modifiers_erase_5) {
  try {
    s21::vector<int> s21_v{50, 10, 40, 20, 30};
    s21_v.erase(s21_v.end() + 1);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Index out ot range"));
  }
}

TEST(VectorTest, Modifiers_push_back_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;

  s21_v.push_back(2);
  s21_v.push_back(3);
  s21_v.push_back(4);
  s21_v.push_back(5);

  std_v.push_back(2);
  std_v.push_back(3);
  std_v.push_back(4);
  std_v.push_back(5);

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
}

TEST(VectorTest, Modifiers_push_back_2) {
  s21::vector<int> s21_v{1, 2};
  std::vector<int> std_v{1, 2};

  s21_v.push_back(2);
  s21_v.push_back(3);
  s21_v.push_back(4);
  s21_v.push_back(5);

  std_v.push_back(2);
  std_v.push_back(3);
  std_v.push_back(4);
  std_v.push_back(5);

  EXPECT_EQ(s21_v.at(0), std_v.at(0));
  EXPECT_EQ(s21_v.at(1), std_v.at(1));
  EXPECT_EQ(s21_v.at(2), std_v.at(2));
  EXPECT_EQ(s21_v.at(3), std_v.at(3));
  EXPECT_EQ(s21_v.at(4), std_v.at(4));
  EXPECT_EQ(s21_v.at(5), std_v.at(5));
}

TEST(VectorTest, Modifiers_pop_back_1) {
  s21::vector<int> s21_v{1, 2};

  s21_v.pop_back();
  s21_v.pop_back();
  s21_v.pop_back();
  s21_v.pop_back();

  EXPECT_EQ(s21_v.size(), 0);
  EXPECT_EQ(s21_v.capacity(), 2);
}

TEST(VectorTest, Modifiers_pop_back_2) {
  s21::vector<int> s21_v;

  s21_v.pop_back();
  s21_v.pop_back();
  s21_v.pop_back();
  s21_v.pop_back();

  EXPECT_EQ(s21_v.size(), 0);
  EXPECT_EQ(s21_v.capacity(), 0);
}

TEST(VectorTest, Modifiers_swap_1) {
  s21::vector<int> s21_v;
  s21::vector<int> s21_v_copy;

  std::vector<int> std_v;
  std::vector<int> std_v_copy;

  s21_v_copy.swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Modifiers_swap_2) {
  s21::vector<int> s21_v{1, 2, 3, 4};
  s21::vector<int> s21_v_copy;

  std::vector<int> std_v{1, 2, 3, 4};
  std::vector<int> std_v_copy;

  s21_v_copy.swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Modifiers_swap_3) {
  s21::vector<int> s21_v{1, 2, 3, 4};
  s21::vector<int> s21_v_copy{1, 2};

  std::vector<int> std_v{1, 2, 3, 4};
  std::vector<int> std_v_copy{1, 2};

  s21_v_copy.swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Modifiers_swap_4) {
  s21::vector<int> s21_v{1, 2, 3, 4};
  s21::vector<int> s21_v_copy{1, 2, 3, 4, 5, 6};

  std::vector<int> std_v{1, 2, 3, 4};
  std::vector<int> std_v_copy{1, 2, 3, 4, 5, 6};

  s21_v_copy.swap(s21_v);
  std_v_copy.swap(std_v);

  EXPECT_EQ(s21_v.size(), std_v.size());
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());

  EXPECT_EQ(s21_v_copy.size(), std_v_copy.size());
  EXPECT_EQ(s21_v_copy.capacity(), std_v_copy.capacity());
}

TEST(VectorTest, Helpers_add_memotysize_1) {
  int n = 1000;
  s21::vector<int> s21_v(n);
  s21_v.push_back(1);
  EXPECT_EQ(s21_v.size(), n + 1);
}

TEST(VectorTest, Helpers_add_memotysize_2) {
  int n = 10000;
  s21::vector<int> s21_v(n);
  s21_v.push_back(1);

  EXPECT_EQ(s21_v.size(), n + 1);
}

TEST(VectorTest, Helpers_add_memotysize_3) {
  int n = 100000;
  s21::vector<int> s21_v(n);
  s21_v.push_back(1);
  s21_v.push_back(1);
  s21_v.push_back(1);

  EXPECT_EQ(s21_v.size(), n + 3);
}