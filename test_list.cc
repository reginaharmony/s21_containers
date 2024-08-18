#include <gtest/gtest.h>

#include <list>

#include "s21_containers/s21_containers.h"

// TEST(VectorMethods, Reserve_IncreaseCapacity) {
//  s21::list<int> lst(1);
// lst.push_front(5);
//  EXPECT_EQ(lst.front(),5);
// }

// ========================== SET 1 =================================

TEST(ListTest_s1, DefaultConstructor_s1) {
  s21::list<int> our_list;
  std::list<int> std_list;
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(ListTest_s1, SizeConstructor_s1) {
  s21::list<int> our_list(5);
  std::list<int> std_list(5);
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(ListTest_s1, InitializerListConstructor_s1) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(our_list.size(), std_list.size());
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(ListTest_s1, ConstructorMove_s1) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy(std::move(our_list));
  std::list<int> std_copy(std::move(std_list));
  EXPECT_EQ(our_copy.size(), std_copy.size());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(ListTest_s1, Size_s1) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(ListTest_s1, PushFront_s1) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_front(1);
  std_list.push_front(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  our_list.push_front(2);
  std_list.push_front(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  our_list.push_front(3);
  std_list.push_front(3);
  EXPECT_EQ(our_list.front(), std_list.front());
}

TEST(ListTest_s1, PushBack_s1) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
}

TEST(ListTest_s1, PopFront_s1) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  our_list.pop_front();
  std_list.pop_front();
  EXPECT_EQ(our_list.front(), std_list.front());
}

TEST(ListTest_s1, PopBack_s1) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  our_list.pop_back();
  std_list.pop_back();
  EXPECT_EQ(our_list.front(), std_list.front());
}

TEST(ListTest_s1, Swap_s1) {
  s21::list<int> our_list_first = {1};
  s21::list<int> our_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  our_list_first.swap(our_list_second);
  std_list_first.swap(std_list_second);
  EXPECT_EQ(our_list_first.front(), std_list_first.front());
}

TEST(ListTest_s1, IteratorBegin_s1) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it(our_list.begin());
  std::list<int>::iterator std_it(std_list.begin());
  EXPECT_EQ(*our_it, *std_it);
}

TEST(ListTest_s1, IteratorBeginPlusAndMinus_s1) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  ++our_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  --our_it;
  --std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(ListTest_s1, IteratorEnd_Last_s1) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.end();
  std::list<int>::iterator std_it;
  std_it = std_list.end();
  --std_it;
  EXPECT_EQ(*our_it, *std_it);
}

// TEST(ListTest_s1, IteratorEquals_s1) {
//   s21::list<int> first_list = {1, 2, 3};
//   s21::list<int>::iterator our_it_first;
//   our_it_first = first_list.begin();
//   s21::list<int>::iterator our_it_second;
//   our_it_second = first_list.begin();
//   EXPECT_TRUE(our_it_first == our_it_second);
//   EXPECT_TRUE(our_it_first >= our_it_second);
//   EXPECT_TRUE(our_it_first <= our_it_second);
//   ++our_it_second;
//   EXPECT_TRUE(our_it_first != our_it_second);
//   EXPECT_TRUE(our_it_second > our_it_first);
//   EXPECT_TRUE(our_it_second >= our_it_first);
//   EXPECT_TRUE(our_it_first < our_it_second);
//   EXPECT_TRUE(our_it_first <= our_it_second);
// }

TEST(ListTest_s1, Insert_s1) {
  s21::list<int> our_list;
  std::list<int> std_list;
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  our_list.insert(our_it, 5);
  std_list.insert(std_it, 5);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.insert(our_it, 7);
  std_list.insert(std_it, 7);
  our_list.insert(our_it, 9);
  std_list.insert(std_it, 9);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

// // --------------------------------------------------------------------------
// Последнее изменение
// //  РУгается санитайз
// TEST(ListTest_s1, Erase) {
//   s21::list<int> our_list(5);
//   our_list[0]=1;
//   our_list[1]=2;
//   our_list[2]=3;
//   our_list[3]=4;
//   our_list[4]=5;
//   std::list<int> std_list = {1, 2, 3, 4, 5};
//   our_list.erase(our_list.begin());
//   std_list.erase(std_list.begin());
//   EXPECT_EQ(our_list.front(), std_list.front());
//   EXPECT_EQ(our_list.back(), std_list.back());
//   s21::list<int>::iterator our_it;
//   our_it = our_list.begin();
//   ++our_it;
//   std::list<int>::iterator std_it;
//   std_it = std_list.begin();
//   ++std_it;
//   EXPECT_EQ(our_list.front(), std_list.front());
//   EXPECT_EQ(our_list.back(), std_list.back());
// }

// TEST(ListTest, Splice) {
//   s21::list<int> our_list_first = {1};
//   s21::list<int> our_list_second = {2, 3, 4, 5};
//   std::list<int> std_list_first = {1};
//   std::list<int> std_list_second = {2, 3, 4, 5};
//   s21::list<int>::const_iterator our_it(our_list_first.cbegin());
//   std::list<int>::const_iterator std_it = std_list_first.begin();
//   our_list_first.splice(our_it, our_list_second);
//   std_list_first.splice(std_it, std_list_second);
//   EXPECT_EQ(our_list_first.front(), std_list_first.front());
//   EXPECT_EQ(our_list_first.back(), std_list_first.back());
// }

// TEST(ListTest, Merge) {
//   s21::list<int> our_list_first = {1};
//   s21::list<int> our_list_second = {2, 3, 4, 5};
//   std::list<int> std_list_first = {1};
//   std::list<int> std_list_second = {2, 3, 4, 5};
//   our_list_first.merge(our_list_second);
//   std_list_first.merge(std_list_second);
//   EXPECT_EQ(our_list_first.front(), std_list_first.front());
//   EXPECT_EQ(our_list_first.back(), std_list_first.back());
//   // EXPECT_EQ(our_list_second.empty(), std_list_second.empty());
// }
// //
// ------------------------------------------------------------------------------

// TEST(ListTest, Reverse) {
//   s21::list<int> our_list = {1, 2, 3, 4, 5};
//   std::list<int> std_list = {1, 2, 3, 4, 5};
//   our_list.reverse();
//   std_list.reverse();
//   EXPECT_EQ(our_list.front(), std_list.front());
//   EXPECT_EQ(our_list.back(), std_list.back());
// }

// TEST(ListTest, Unique) {
//   s21::list<int> our_list = {1, 2, 2, 3, 3};
//   std::list<int> std_list = {1, 2, 2, 3, 3};
//   s21::list<int>::iterator our_it;
//   std::list<int>::iterator std_it;
//   our_list.unique();
//   std_list.unique();
//   our_it = our_list.begin();
//   std_it = std_list.begin();
//   EXPECT_EQ(*our_it, *std_it);
//   ++our_it;
//   ++std_it;
//   EXPECT_EQ(*our_it, *std_it);
//   ++our_it;
//   ++std_it;
//   EXPECT_EQ(*our_it, *std_it);
// }

// TEST(ListTest, MaxSize) {
//     s21::list<int> my_list;
//     ASSERT_EQ(my_list.max_size(), 768614336404564650);
// }

// TEST(ListTest, Sort) {
//   s21::list<int> our_list = {2, 4, 1, 3, 5};
//   std::list<int> std_list = {2, 4, 1, 3, 5};
//   s21::list<int>::iterator our_it;
//   std::list<int>::iterator std_it;
//   our_list.sort();
//   std_list.sort();
//   our_it = our_list.begin();
//   std_it = std_list.begin();
//   EXPECT_EQ(*our_it, *std_it);
//   ++our_it;
//   ++std_it;
//   EXPECT_EQ(*our_it, *std_it);
//   ++our_it;
//   ++std_it;
//   EXPECT_EQ(*our_it, *std_it);
//   ++our_it;
//   ++std_it;
//   EXPECT_EQ(*our_it, *std_it);
//   ++our_it;
//   ++std_it;
//   EXPECT_EQ(*our_it, *std_it);
// }

// TEST(ListTest, Reverse_4) {
//   s21::list<int> our_list = {1, 2, 3, 4, 5};
//   std::list<int> std_list = {1, 2, 3, 4, 5};
//   our_list.reverse();
//   std_list.reverse();
//   EXPECT_EQ(our_list.front(), std_list.front());
//   EXPECT_EQ(our_list.back(), std_list.back());
// }

// TEST(ListTest, OperatorMove) {
//   s21::list<int> our_list = {1, 2, 3};
//   std::list<int> std_list = {1, 2, 3};
//   s21::list<int> our_copy;
//   our_copy = std::move(our_list);
//   std::list<int> std_copy;
//   std_copy = std::move(std_list);
//   EXPECT_EQ(our_copy.front(), std_copy.front());
//   EXPECT_EQ(our_copy.back(), std_copy.back());
// }

// TEST(ListTest_12, Insert_2) {
//     s21::list<int> our_list;
//     std::list<int> std_list;
//     s21::list<int>::iterator our_it = our_list.begin();
//     std::list<int>::iterator std_it = std_list.begin();
//     our_list.insert(our_it, 5);
//     std_list.insert(std_it, 5);
//     EXPECT_EQ(our_list.front(), std_list.front());
//     EXPECT_EQ(our_list.back(), std_list.back());
//     our_it = our_list.begin();
//     std_it = std_list.begin();
//     our_list.insert(our_it, 7);
//     std_list.insert(std_it, 7);
//     EXPECT_EQ(our_list.front(), std_list.front());
//     EXPECT_EQ(our_list.back(), std_list.back());

//     our_it = ++our_list.begin();
//     std_it = ++std_list.begin();
//     our_list.insert(our_it, 11);
//     std_list.insert(std_it, 11);
//     EXPECT_EQ(our_list.front(), std_list.front());
//     EXPECT_EQ(our_list.back(), std_list.back());
// }

// TEST(ListTest_4, Splice_4) {
//     {
//         s21::list<int> our_list_first = {1};
//         s21::list<int> our_list_second = {2, 3, 4, 5};
//         std::list<int> std_list_first = {1};
//         std::list<int> std_list_second = {2, 3, 4, 5};
//         s21::list<int>::const_iterator our_it = our_list_first.cbegin();
//         std::list<int>::const_iterator std_it = std_list_first.begin();
//         our_list_first.splice(our_it, our_list_second);
//         std_list_first.splice(std_it, std_list_second);
//         EXPECT_EQ(our_list_first.front(), std_list_first.front());
//         EXPECT_EQ(our_list_first.back(), std_list_first.back());
//     }
//     {
//         s21::list<int> our_list_first = {1};
//         s21::list<int> our_list_second = {2, 3, 4, 5};
//         std::list<int> std_list_first = {1};
//         std::list<int> std_list_second = {2, 3, 4, 5};
//         s21::list<int>::const_iterator our_it = our_list_first.cend();
//         std::list<int>::const_iterator std_it = std_list_first.end();
//         std_it--;
//         our_list_first.splice(our_it, our_list_second);
//         std_list_first.splice(std_it, std_list_second);
//         EXPECT_EQ(our_list_first.front(), std_list_first.front());
//         EXPECT_EQ(our_list_first.back(), std_list_first.back());
//     }
//     {
//         s21::list<int> our_list_first = {1, 6};
//         s21::list<int> our_list_second = {2, 3, 4, 5};
//         std::list<int> std_list_first = {1, 6};
//         std::list<int> std_list_second = {2, 3, 4, 5};
//         s21::list<int>::const_iterator our_it = ++our_list_first.cbegin();
//         std::list<int>::const_iterator std_it = ++std_list_first.begin();
//         our_list_first.splice(our_it, our_list_second);
//         std_list_first.splice(std_it, std_list_second);
//         EXPECT_EQ(our_list_first.front(), std_list_first.front());
//         EXPECT_EQ(our_list_first.back(), std_list_first.back());
//     }
// }

// ========================== SET 2 =================================
// LIST

template <typename value_type>
bool compare_lists(s21::list<value_type> my_list,
                   std::list<value_type> std_list) {
  bool result = true;
  if (my_list.size() == std_list.size()) {
    auto my_it = my_list.begin();
    auto std_it = std_list.begin();
    for (size_t i = 0; i != my_list.size(); ++i) {
      if (*my_it != *std_it) {
        result = false;
        break;
      }
      my_it++;
      std_it++;
    }
  } else {
    result = false;
  }
  return result;
}

TEST(ListTest, CompareLists) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  EXPECT_TRUE(compare_lists(my_list, std_list));
  std_list.push_back(6);
  EXPECT_FALSE(compare_lists(my_list, std_list));
  std_list.pop_back();
  my_list.push_front(0);
  std_list.push_front(0);
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, DefaultConstructor) {
  s21::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.size(), 0);
  EXPECT_TRUE(my_list.empty());

  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, SizeConstructor) {
  s21::list<int> my_list(10000);
  std::list<int> std_list(10000);
  EXPECT_EQ(my_list.size(), 10000);
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, SizeConstructorThrow) {
  try {
    s21::list<int> my_list(-1);
    FAIL() << "Expected std::out_of_range";
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("Size limit exception"));
  }
}

TEST(ListTest, InitializerListConstructor) {
  s21::list<int> my_list{1, 2, 3, 7, 9};
  std::list<int> std_list{1, 2, 3, 7, 9};
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, InitializerListConstructor_2) {
  std::initializer_list<int> b;
  s21::list<int> my_list{b};
  std::list<int> std_list{b};
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, CopyConstructor) {
  s21::list<int> my_list{1, 2, 3};
  s21::list<int> my_list_copy(my_list);
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list_copy(std_list);
  EXPECT_TRUE(compare_lists(my_list_copy, std_list_copy));
}

TEST(ListTest, CopyConstructorEmpty) {
  s21::list<int> my_list;
  s21::list<int> my_list_copy(my_list);
  std::list<int> std_list;
  std::list<int> std_list_copy(std_list);
  EXPECT_TRUE(compare_lists(my_list_copy, std_list_copy));
}

TEST(ListTest, MoveConstructor) {
  s21::list<int> my_list{1, 2, 3};
  s21::list<int> my_list_copy(my_list);
  s21::list<int> my_list_move(std::move(my_list));
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move(std::move(std_list));
  EXPECT_TRUE(compare_lists(my_list_copy, std_list_copy));
}

TEST(ListTest, MoveConstructorEmpty) {
  s21::list<int> my_list;
  s21::list<int> my_list_copy(my_list);
  s21::list<int> my_list_move(std::move(my_list));
  std::list<int> std_list;
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move(std::move(std_list));
  EXPECT_TRUE(compare_lists(my_list_copy, std_list_copy));
}

TEST(ListTest, MoveAssignmentOperator) {
  s21::list<int> my_list{1, 2, 3};
  s21::list<int> my_list_copy(my_list);
  s21::list<int> my_list_move = std::move(my_list);
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move = std::move(std_list);
  EXPECT_TRUE(compare_lists(my_list_move, std_list_move));
}

TEST(ListTest, MoveAssignmentOperatorEmpty) {
  s21::list<int> my_list;
  s21::list<int> my_list_copy(my_list);
  s21::list<int> my_list_move = std::move(my_list);
  std::list<int> std_list;
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move = std::move(std_list);
  EXPECT_TRUE(compare_lists(my_list_move, std_list_move));
}

TEST(ListTest, Front) {
  s21::list<int> my_list{99, 2, 3, 4, 5};
  std::list<int> std_list{99, 2, 3, 4, 5};
  EXPECT_EQ(my_list.front(), std_list.front());
}

TEST(ListTest, Back) {
  s21::list<int> my_list{1, 2, 3, 4, 99};
  std::list<int> std_list{1, 2, 3, 4, 99};
  EXPECT_EQ(my_list.back(), std_list.back());
}

TEST(ListTest, Empty) {
  s21::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.empty(), std_list.empty());
  my_list.push_back(10);
  std_list.push_back(10);
  EXPECT_EQ(my_list.empty(), std_list.empty());
}

TEST(ListTest, Size) {
  s21::list<int> my_list{1, 2, 3, 4, 5, 6, 7, 8};
  std::list<int> std_list{1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(my_list.size(), std_list.size());
}

TEST(ListTest, SizeEmpty) {
  s21::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.size(), std_list.size());
}

TEST(ListTest, MaxSize) {
  s21::list<size_t> my_list_empty;
  std::list<size_t> std_list_empty;
  EXPECT_EQ(my_list_empty.max_size(), std_list_empty.max_size());
}

TEST(ListTest, Clear) {
  s21::list<int> my_list{1, 2, 3, 4};
  my_list.clear();
  std::list<int> std_list{1, 2, 5, 4, 3};
  std_list.clear();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, ClearEmpty) {
  s21::list<int> my_list;
  my_list.clear();
  std::list<int> std_list;
  std_list.clear();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PushBack) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.push_back(6);
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.push_back(6);
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PopBack) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.pop_back();
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.pop_back();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PushFront) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.push_front(0);
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.push_front(0);
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PopFront) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.pop_front();
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.pop_front();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Swap) {
  s21::list<int> my_list1{1, 2, 3, 4, 5};
  s21::list<int> my_list2{6, 7, 8, 9, 10, 11};
  my_list1.swap(my_list2);

  std::list<int> std_list1{1, 2, 3, 4, 5};
  std::list<int> std_list2{6, 7, 8, 9, 10, 11};
  std_list1.swap(std_list2);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
  EXPECT_TRUE(compare_lists(my_list2, std_list2));
}

TEST(ListTest, Swap_2) {
  s21::list<int> my_list1{1, 5, 8, 100};
  s21::list<int> my_list2;
  my_list1.swap(my_list2);

  std::list<int> std_list1{1, 5, 8, 100};
  std::list<int> std_list2;
  std_list1.swap(std_list2);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
  EXPECT_TRUE(compare_lists(my_list2, std_list2));
}

TEST(ListTest, begin_1) {
  s21::list<int> my_list1{500, 1500, 3000};

  std::list<int> std_list2{500, 1500, 3000};
  EXPECT_EQ(*my_list1.begin(), *std_list2.begin());
}

TEST(ListTest, begin_2) {
  s21::list<int> my_list1(4);

  std::list<int> std_list2(4);
  EXPECT_EQ(*my_list1.begin(), *std_list2.begin());
}

TEST(ListTest, begin_3_throw) {
  s21::list<int> my_list1;
  std::list<int> std_list2;

  EXPECT_EQ(*my_list1.begin(), 0);
}

TEST(ListTest, end_1) {
  s21::list<int> my_list1{500, 1500, 3000};

  std::list<int> std_list2{500, 1500, 3000};
  EXPECT_EQ(*my_list1.begin(), *std_list2.begin());
}

TEST(ListTest, end_2) {
  s21::list<int> my_list1(4);

  std::list<int> std_list2(4);
  EXPECT_EQ(*my_list1.end(), *std_list2.end());
}

TEST(ListTest, end_3) {
  s21::list<int> my_list1;

  std::list<int> std_list2;
  EXPECT_EQ(*my_list1.end(), *std_list2.end());
}

TEST(ListTest, Merge_1) {
  s21::list<int> my_list1{1, 999, 2000};
  s21::list<int> my_list2{500, 1500, 3000};
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 999, 2000};
  std::list<int> std_list2{500, 1500, 3000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_2) {
  s21::list<int> my_list1{1, 999, 2000};
  s21::list<int> my_list2{1500, 3000};
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 999, 2000};
  std::list<int> std_list2{1500, 3000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_3) {
  s21::list<int> my_list1{1, 2000, 666};
  s21::list<int> my_list2{1500, 154, 124, 3000};
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 2000, 666};
  std::list<int> std_list2{1500, 154, 124, 3000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_4) {
  s21::list<int> my_list1;
  s21::list<int> my_list2{1500, 154, 124, 3000};
  my_list1.merge(my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2{1500, 154, 124, 3000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_5) {
  s21::list<int> my_list1{1, 2000, 666};
  s21::list<int> my_list2;
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 2000, 666};
  std::list<int> std_list2;
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_6) {
  s21::list<int> my_list1;
  s21::list<int> my_list2;
  my_list1.merge(my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2;
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Reverse_1) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  my_list.reverse();
  std_list.reverse();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Reverse_2) {
  s21::list<int> my_list(4);
  std::list<int> std_list(4);
  my_list.reverse();
  std_list.reverse();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Reverse_3) {
  s21::list<int> my_list;
  std::list<int> std_list;
  my_list.reverse();
  std_list.reverse();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Unique_1) {
  s21::list<int> my_list{90, 10, 3, 40, 30, 20, 10, 10, 90, 90, 90};
  std::list<int> std_list{90, 10, 3, 40, 30, 20, 10, 10, 90, 90, 90};
  my_list.unique();
  std_list.unique();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Unique_2) {
  s21::list<int> my_list(3);
  std::list<int> std_list(3);
  my_list.unique();
  std_list.unique();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Unique_3) {
  s21::list<int> my_list;
  std::list<int> std_list;
  my_list.unique();
  std_list.unique();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

// TEST(ListTest, Splice_1) {
//   s21::list<int> my_list1{1, 999, 2000};
//   s21::list<int> my_list2{500, 1500, 3000};
//   my_list1.splice(my_list1.begin(), my_list2);

//   std::list<int> std_list1{1, 999, 2000};
//   std::list<int> std_list2{500, 1500, 3000};
//   std_list1.splice(std_list1.begin(), std_list2);
//   EXPECT_TRUE(compare_lists(my_list1, std_list1));
// }

TEST(ListTest, Splice_2) {
  s21::list<int> my_list1;
  s21::list<int> my_list2{500, 1500, 3000};
  my_list1.splice(my_list1.begin(), my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2{500, 1500, 3000};
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Splice_3) {
  s21::list<int> my_list1{1, 999, 2000};
  s21::list<int> my_list2;
  my_list1.splice(my_list1.begin(), my_list2);

  std::list<int> std_list1{1, 999, 2000};
  std::list<int> std_list2;
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Splice_4) {
  s21::list<int> my_list1;
  s21::list<int> my_list2;
  my_list1.splice(my_list1.begin(), my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2;
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_1) {
  s21::list<int> my_list1{1, 999, 2000};
  my_list1.insert(my_list1.begin(), 5);

  std::list<int> std_list1{1, 999, 2000};
  std_list1.insert(std_list1.begin(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_2) {
  s21::list<int> my_list1{1, 999, 2000};
  my_list1.insert(my_list1.end(), 5);

  std::list<int> std_list1{1, 999, 2000};
  std_list1.insert(std_list1.end(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_3) {
  s21::list<int> my_list1;
  my_list1.insert(my_list1.begin(), 5);

  std::list<int> std_list1;
  std_list1.insert(std_list1.begin(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_4) {
  s21::list<int> my_list1;
  my_list1.insert(my_list1.end(), 5);

  std::list<int> std_list1;
  std_list1.insert(std_list1.end(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_5) {
  s21::list<int> my_list1(4);
  my_list1.insert(my_list1.begin(), 5);

  std::list<int> std_list1(4);
  std_list1.insert(std_list1.begin(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_6) {
  s21::list<int> my_list1(4);
  my_list1.insert(my_list1.end(), 5);

  std::list<int> std_list1(4);
  std_list1.insert(std_list1.end(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Erase_1) {
  s21::list<int> my_list1{1, 999, 2000};
  my_list1.erase(my_list1.begin());

  std::list<int> std_list1{1, 999, 2000};
  std_list1.erase(std_list1.begin());

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Erase_2_throw) {
  s21::list<int> my_list1{1, 999, 2000};

  EXPECT_THROW(my_list1.erase(my_list1.end()), std::invalid_argument);
}

TEST(ListTest, Erase_3) {
  s21::list<int> my_list1{1, 999, 2000};
  my_list1.erase(--my_list1.end());

  std::list<int> std_list1{1, 999, 2000};
  std_list1.erase(std_list1.end().operator--());

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Erase_4_throw) {
  s21::list<int> my_list1;

  EXPECT_THROW(my_list1.erase(my_list1.end()--), std::invalid_argument);
}

TEST(ListTest, Erase_5) {
  s21::list<int> my_list1(5);
  my_list1.erase(--my_list1.end());

  std::list<int> std_list1(5);
  std_list1.erase(std_list1.end().operator--());

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

// ========================== SET 3 =================================

// List Testing
class TestList {
 public:
  s21::list<int> s21_list_empty;
  s21::list<int> s21_list_three{1, 2, 3};
  s21::list<int> s21_lesser{534789,   2479056, 987654, 110101024,
                            62348710, 1,       35674};
  s21::list<char> s21_char_list{'L', 'I', 'S', 'T'};
  s21::list<int> s21_list_ten{1, 2, 3, 5, 9, 10};
  s21::list<int> s21_list_unique{111, 111, 111, 3, 4, 5, 6, 666, 666};

  std::list<int> std_list_empty;
  std::list<int> std_list_three{1, 2, 3};
  std::list<int> std_lesser{534789,   2479056, 987654, 110101024,
                            62348710, 1,       35674};
  std::list<char> std_char_list{'L', 'I', 'S', 'T'};
  std::list<int> std_list_ten{1, 2, 3, 5, 9, 10};
  std::list<int> std_list_unique{111, 111, 111, 3, 4, 5, 6, 666, 666};
};

TEST(List, default_constructor) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_empty.size(), tester.std_list_empty.size());
  EXPECT_EQ(tester.s21_list_empty.empty(), tester.std_list_empty.empty());
}

TEST(List, init_constructor) {
  TestList tester;
  s21::list<int> a(3);
  std::list<int> b(3);
  s21::list<int>::iterator s21_it = a.begin();
  std::list<int>::iterator std_it = b.begin();
  while (s21_it != a.end()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(List, initializer_constructor) {
  TestList tester;
  s21::list<int>::iterator s21_iter = tester.s21_list_three.begin();
  std::list<int>::iterator std_iter = tester.std_list_three.begin();
  while (s21_iter != tester.s21_list_three.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

TEST(List, copy_constructor) {
  TestList tester;
  s21::list<int> s21_list_copy(tester.s21_list_three);
  std::list<int> std_list_copy(tester.std_list_three);
  s21::list<int>::iterator s21_iter = s21_list_copy.begin();
  std::list<int>::iterator std_iter = std_list_copy.begin();
  while (s21_iter != s21_list_copy.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(s21_list_copy.size(), std_list_copy.size());
  EXPECT_EQ(s21_list_copy.empty(), std_list_copy.empty());
}

TEST(List, move_constructor) {
  TestList tester;
  s21::list<int> s21_list_move(std::move(tester.s21_list_three));
  std::list<int> std_list_move(std::move(tester.std_list_three));
  s21::list<int>::iterator s21_iter = s21_list_move.begin();
  std::list<int>::iterator std_iter = std_list_move.begin();
  while (s21_iter != s21_list_move.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(s21_list_move.size(), std_list_move.size());
  EXPECT_EQ(s21_list_move.empty(), std_list_move.empty());
  s21_iter = tester.s21_list_three.begin();
  std_iter = tester.std_list_three.begin();
  while (s21_iter != tester.s21_list_three.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

// TEST(List, copy_assigment_lesser) {
//   TestList tester;
//   s21::list<int> s21_list_copy{1, 2};
//   std::list<int> std_list_copy{1, 2};
//   s21_list_copy = tester.s21_lesser;
//   std_list_copy = tester.std_lesser;
//   s21::list<int>::iterator s21_iter = s21_list_copy.begin();
//   std::list<int>::iterator std_iter = std_list_copy.begin();
//   while (s21_iter != s21_list_copy.end()) {
//     EXPECT_EQ(*s21_iter, *std_iter);
//     ++s21_iter;
//     ++std_iter;
//   }
//   EXPECT_EQ(s21_list_copy.size(), std_list_copy.size());
//   EXPECT_EQ(s21_list_copy.empty(), std_list_copy.empty());
// }

TEST(List, move_assigment) {
  TestList tester;
  s21::list<int> s21_list_move{1, 2};
  std::list<int> std_list_move{1, 2};
  s21_list_move = std::move(tester.s21_lesser);
  std_list_move = std::move(tester.std_lesser);
  s21::list<int>::iterator s21_iter = s21_list_move.begin();
  std::list<int>::iterator std_iter = std_list_move.begin();
  while (s21_iter != s21_list_move.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
  EXPECT_EQ(s21_list_move.size(), std_list_move.size());
  EXPECT_EQ(s21_list_move.empty(), std_list_move.empty());
}

TEST(List, function_front) {
  TestList tester;
  EXPECT_EQ(tester.s21_char_list.front(), tester.std_char_list.front());
}
TEST(List, function_front_empty) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_empty.front(), tester.std_list_empty.front());
}

TEST(List, function_back) {
  TestList tester;
  EXPECT_EQ(tester.s21_char_list.back(), tester.std_char_list.back());
}
TEST(List, function_back_empty) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_empty.back(), tester.std_list_empty.back());
}

TEST(List, iterator_access_first) {
  TestList tester;
  s21::list<char>::iterator s21_iter = tester.s21_char_list.begin();
  std::list<char>::iterator std_iter = tester.std_char_list.begin();
  while (s21_iter != tester.s21_char_list.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }
}

TEST(List, function_empty) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_empty.empty(), tester.std_list_empty.empty());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

TEST(List, function_size) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_empty.size(), tester.std_list_empty.size());
}

TEST(List, function_max_size) {
  TestList tester;
  EXPECT_EQ(tester.s21_list_empty.max_size(), tester.std_list_empty.max_size());
}

TEST(List, function_clear) {
  TestList tester;
  tester.s21_list_three.clear();
  tester.std_list_three.clear();
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
}

TEST(List, function_insert_begin) {
  TestList tester;
  s21::list<int>::iterator s21_it = tester.s21_list_empty.begin();
  std::list<int>::iterator std_it = tester.std_list_empty.begin();
  s21_it = tester.s21_list_empty.insert(s21_it, 666);
  std_it = tester.std_list_empty.insert(std_it, 666);
  ASSERT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_empty.begin();
  std_it = tester.std_list_empty.begin();
  while (s21_it != tester.s21_list_empty.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_empty.size(), tester.std_list_empty.size());
  EXPECT_EQ(tester.s21_list_empty.empty(), tester.std_list_empty.empty());
}

TEST(List, function_insert_mid) {
  TestList tester;
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = tester.s21_list_ten.insert(s21_it, 666);
  std_it = tester.std_list_ten.insert(std_it, 666);
  ASSERT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_insert_end) {
  TestList tester;
  s21::list<int>::iterator s21_it = tester.s21_list_ten.end();
  std::list<int>::iterator std_it = tester.std_list_ten.end();
  s21_it = tester.s21_list_ten.insert(s21_it, 666);
  std_it = tester.std_list_ten.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_insert_multi) {
  TestList tester;
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  s21_it = tester.s21_list_ten.insert(s21_it, 666);
  std_it = tester.std_list_ten.insert(std_it, 666);
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  s21_it = tester.s21_list_ten.insert(s21_it, 666);
  std_it = tester.std_list_ten.insert(std_it, 666);
  EXPECT_EQ(*s21_it, *std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_erase_begin) {
  TestList tester;
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  tester.s21_list_ten.erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_erase_mid) {
  TestList tester;
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  tester.s21_list_ten.erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

// TEST(List, function_erase_end) {
//   TestList tester;
//   s21::list<int>::iterator s21_it = tester.s21_list_ten.rbegin();
//   std::list<int>::iterator std_it = --tester.std_list_ten.end();
//   tester.s21_list_ten.erase(s21_it);
//   tester.std_list_ten.erase(std_it);
//   s21_it = tester.s21_list_ten.begin();
//   std_it = tester.std_list_ten.begin();
//   while (s21_it != tester.s21_list_ten.end()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
// }

TEST(List, function_erase_multi) {
  TestList tester;
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  ++s21_it;
  ++std_it;
  tester.s21_list_ten.erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  tester.s21_list_ten.erase(s21_it);
  tester.std_list_ten.erase(std_it);
  s21_it = tester.s21_list_ten.begin();
  std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}
TEST(List, function_push_back) {
  TestList tester;
  tester.s21_list_three.push_back(666);
  tester.std_list_three.push_back(666);
  tester.s21_list_three.push_back(123);
  tester.std_list_three.push_back(123);
  s21::list<int>::iterator s21_it = tester.s21_list_three.begin();
  std::list<int>::iterator std_it = tester.std_list_three.begin();
  while (s21_it != tester.s21_list_three.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
  EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
}

TEST(List, function_pop_back) {
  TestList tester;
  tester.s21_list_ten.pop_back();
  tester.std_list_ten.pop_back();
  tester.s21_list_ten.pop_back();
  tester.std_list_ten.pop_back();
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_push_front) {
  TestList tester;
  tester.s21_list_ten.push_front(666);
  tester.std_list_ten.push_front(666);
  tester.s21_list_ten.push_front(123);
  tester.std_list_ten.push_front(123);
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_pop_front) {
  TestList tester;
  tester.s21_list_ten.pop_front();
  tester.std_list_ten.pop_front();
  tester.s21_list_ten.pop_front();
  tester.std_list_ten.pop_front();
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_swap) {
  TestList tester;
  s21::list<int> s21_list_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<int> std_list_swap{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  tester.s21_lesser.swap(s21_list_swap);
  tester.std_lesser.swap(std_list_swap);
  s21::list<int>::iterator s21_it = s21_list_swap.begin();
  std::list<int>::iterator std_it = std_list_swap.begin();
  while (s21_it != s21_list_swap.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(s21_list_swap.size(), std_list_swap.size());
  EXPECT_EQ(s21_list_swap.empty(), std_list_swap.empty());
  s21_it = tester.s21_lesser.begin();
  std_it = tester.std_lesser.begin();
  while (s21_it != tester.s21_lesser.end()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.empty(), tester.std_lesser.empty());
}
TEST(List, function_merge_nonsorted) {
  TestList tester;
  s21::list<int> s21_list_merge{77, 125890, 430235, -236, 32858, 7457};
  std::list<int> std_list_merge{77, 125890, 430235, -236, 32858, 7457};
  tester.s21_lesser.merge(s21_list_merge);
  tester.std_lesser.merge(std_list_merge);
  s21::list<int>::iterator s21_it = s21_list_merge.begin();
  std::list<int>::iterator std_it = std_list_merge.begin();
  while (s21_it != s21_list_merge.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(s21_list_merge.size(), std_list_merge.size());
  EXPECT_EQ(s21_list_merge.empty(), std_list_merge.empty());
  s21_it = tester.s21_lesser.begin();
  std_it = tester.std_lesser.begin();
  while (s21_it != tester.s21_lesser.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.empty(), tester.std_lesser.empty());
}

TEST(List, function_merge_sorted) {
  TestList tester;
  s21::list<int> s21_list_merge{77, 125890, 430235, -236, 32858, 7457};
  std::list<int> std_list_merge{77, 125890, 430235, -236, 32858, 7457};
  tester.s21_lesser.sort();
  tester.std_lesser.sort();
  tester.s21_lesser.merge(s21_list_merge);
  tester.std_lesser.merge(std_list_merge);
  s21::list<int>::iterator s21_it = s21_list_merge.begin();
  std::list<int>::iterator std_it = std_list_merge.begin();
  while (s21_it != s21_list_merge.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(s21_list_merge.size(), std_list_merge.size());
  EXPECT_EQ(s21_list_merge.empty(), std_list_merge.empty());
  s21_it = tester.s21_lesser.begin();
  std_it = tester.std_lesser.begin();
  while (s21_it != tester.s21_lesser.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.empty(), tester.std_lesser.empty());
}

// TEST(List, function_splice) {
//   TestList tester;
//   s21::list<int> s21_list_splice{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   std::list<int> std_list_splice{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   s21::list<int>::const_iterator s21_it = tester.s21_lesser.cbegin();
//   std::list<int>::const_iterator std_it = tester.std_lesser.cbegin();
//   ++s21_it;
//   ++std_it;
//   tester.s21_lesser.splice(s21_it, s21_list_splice);
//   tester.std_lesser.splice(std_it, std_list_splice);
//   s21_it = s21_list_splice.cbegin();
//   std_it = std_list_splice.cbegin();
//   while (s21_it != s21_list_splice.end()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(s21_list_splice.size(), std_list_splice.size());
//   EXPECT_EQ(s21_list_splice.empty(), std_list_splice.empty());
//   s21_it = tester.s21_lesser.cbegin();
//   std_it = tester.std_lesser.cbegin();
//   while (s21_it != tester.s21_lesser.end()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_lesser.size(), tester.std_lesser.size());
//   EXPECT_EQ(tester.s21_lesser.empty(), tester.std_lesser.empty());
// }

TEST(List, function_reverse) {
  TestList tester;
  tester.s21_list_ten.reverse();
  tester.std_list_ten.reverse();
  s21::list<int>::iterator s21_it = tester.s21_list_ten.begin();
  std::list<int>::iterator std_it = tester.std_list_ten.begin();
  while (s21_it != tester.s21_list_ten.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
  EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
}

TEST(List, function_unique) {
  TestList tester;
  tester.s21_list_unique.unique();
  tester.std_list_unique.unique();
  s21::list<int>::iterator s21_it = tester.s21_list_unique.begin();
  std::list<int>::iterator std_it = tester.std_list_unique.begin();
  while (s21_it != tester.s21_list_unique.end()) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_list_unique.size(), tester.std_list_unique.size());
  EXPECT_EQ(tester.s21_list_unique.empty(), tester.std_list_unique.empty());
}

TEST(List, function_sort) {
  TestList tester;
  tester.s21_lesser.sort();
  tester.std_lesser.sort();
  s21::list<int>::iterator s21_it = tester.s21_lesser.begin();
  std::list<int>::iterator std_it = tester.std_lesser.begin();
  while (s21_it != tester.s21_lesser.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
  EXPECT_EQ(tester.s21_lesser.size(), tester.std_lesser.size());
  EXPECT_EQ(tester.s21_lesser.empty(), tester.std_lesser.empty());
}

// TEST(List, function_emplace_begin) {
//   TestList tester;
//   s21::list<int>::const_iterator s21_it = tester.s21_list_ten.cbegin();
//   std::list<int>::const_iterator std_it = tester.std_list_ten.cbegin();
//   auto s21_iter = tester.s21_list_ten.emplace(s21_it, 666);
//   auto std_iter = tester.std_list_ten.emplace(std_it, 666);
//   ASSERT_EQ(*s21_iter, *std_iter);
//   s21_it = tester.s21_list_ten.cbegin();
//   std_it = tester.std_list_ten.cbegin();
//   while (s21_it != tester.s21_list_ten.end()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_emplace_mid) {
//   TestList tester;
//   s21::list<int>::const_iterator s21_it = tester.s21_list_ten.cbegin();
//   std::list<int>::const_iterator std_it = tester.std_list_ten.cbegin();
//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   auto s21_iter = tester.s21_list_ten.emplace(s21_it, 666);
//   auto std_iter = tester.std_list_ten.emplace(std_it, 666);
//   ASSERT_EQ(*s21_iter, *std_iter);
//   s21_it = tester.s21_list_ten.cbegin();
//   std_it = tester.std_list_ten.cbegin();
//   while (s21_it != tester.s21_list_ten.end()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_emplace_end) {
//   TestList tester;
//   s21::list<int>::const_iterator s21_it = tester.s21_list_ten.cend();
//   std::list<int>::const_iterator std_it = tester.std_list_ten.cend();
//   auto s21_iter = tester.s21_list_ten.emplace(s21_it, 666);
//   auto std_iter = tester.std_list_ten.emplace(std_it, 666);
//   EXPECT_EQ(*s21_iter, *std_iter);
//   while (s21_it != tester.s21_list_ten.cend()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_emplace_multi) {
//   TestList tester;
//   s21::list<int>::const_iterator s21_it = tester.s21_list_ten.cbegin();
//   std::list<int>::const_iterator std_it = tester.std_list_ten.cbegin();
//   s21::list<int>::iterator s21_iter = tester.s21_list_ten.emplace(s21_it,
//   666); std::list<int>::iterator std_iter =
//   tester.std_list_ten.emplace(std_it, 666);

//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   ++s21_it;
//   ++std_it;
//   s21_iter = tester.s21_list_ten.emplace(s21_it, 666);
//   std_iter = tester.std_list_ten.emplace(std_it, 666);

//   ASSERT_EQ(*s21_it, *std_it);

//   auto s21_iterator = tester.s21_list_ten.begin();
//   auto std_iterator = tester.std_list_ten.begin();

//   while (s21_iterator != tester.s21_list_ten.end()) {
//     ASSERT_EQ(*s21_iterator, *std_iterator);
//     ++s21_iterator;
//     ++std_iterator;
//   }

//   EXPECT_EQ(tester.s21_list_ten.size(), tester.std_list_ten.size());
//   EXPECT_EQ(tester.s21_list_ten.empty(), tester.std_list_ten.empty());
// }

// TEST(List, function_emplace_back) {
//   TestList tester;
//   tester.s21_list_three.emplace_back(666);
//   tester.std_list_three.emplace_back(666);
//   tester.s21_list_three.emplace_back(123);
//   tester.std_list_three.emplace_back(123);
//   s21::list<int>::iterator s21_it = tester.s21_list_three.begin();
//   std::list<int>::iterator std_it = tester.std_list_three.begin();
//   while (s21_it != tester.s21_list_three.end()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
//   EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
// }

// TEST(List, function_emplace_front) {
//   TestList tester;
//   tester.s21_list_three.emplace_front(666);
//   tester.std_list_three.emplace_front(666);
//   tester.s21_list_three.emplace_front(123);
//   tester.std_list_three.emplace_front(123);
//   s21::list<int>::iterator s21_it = tester.s21_list_three.begin();
//   std::list<int>::iterator std_it = tester.std_list_three.begin();
//   while (s21_it != tester.s21_list_three.end()) {
//     EXPECT_EQ(*s21_it, *std_it);
//     ++s21_it;
//     ++std_it;
//   }
//   EXPECT_EQ(tester.s21_list_three.size(), tester.std_list_three.size());
//   EXPECT_EQ(tester.s21_list_three.empty(), tester.std_list_three.empty());
// }