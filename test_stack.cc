#include <gtest/gtest.h>
#include "s21_containers/s21_containers.h"
#include <stack>

// ========================== SET 1 =================================
// stack
TEST(stack, Constructor1) {
    s21::stack<int> a;
    std::stack<int> b;
    EXPECT_EQ(a.empty(), b.empty());
}

TEST(stack, Constructor2) {
    s21::stack<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    b.push(6);
    b.push(7);
    b.push(8);
    b.push(9);
    b.push(10);
    EXPECT_EQ(a.top(), b.top());
}

TEST(stack, ConstructorCopy) {
    s21::stack<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    s21::stack<int> a_copy(a);
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    b.push(6);
    b.push(7);
    b.push(8);
    b.push(9);
    b.push(10);
    std::stack<int> b_copy(b);
    EXPECT_EQ(a_copy.top(), b_copy.top());
}

TEST(stack, ConstructorMove) {
    s21::stack<int> a = {1, 2, 3, 4, 5};
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    s21::stack<int> a_move(std::move(a));
    std::stack<int> b_move(std::move(b));
    ASSERT_EQ(a.empty(), b.empty());
    ASSERT_EQ(a_move.empty(), b_move.empty());
    ASSERT_EQ(a_move.size(), b_move.size());
    ASSERT_EQ(a_move.top(), b_move.top());
}

TEST(stack, OperatorMove) {
    s21::stack<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    b.push(6);
    b.push(7);
    b.push(8);
    b.push(9);
    b.push(10);
    s21::stack<int> a_empty;
    std::stack<int> b_empty;
    a_empty = std::move(a);
    b_empty = std::move(b);
    EXPECT_EQ(a_empty.top(), b_empty.top());
}

TEST(stack, Top) {
    s21::stack<int> a = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(a.top(), 6);
}

TEST(stack, Empty) {
    s21::stack<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    b.push(6);
    b.push(7);
    b.push(8);
    b.push(9);
    b.push(10);
    EXPECT_EQ(a.empty(), b.empty());
    s21::stack<int> a_empty;
    std::stack<int> b_empty;
    EXPECT_EQ(a_empty.empty(), b_empty.empty());
}

TEST(stack, Size) {
    s21::stack<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    b.push(6);
    b.push(7);
    b.push(8);
    b.push(9);
    b.push(10);
    EXPECT_EQ(a.size(), b.size());
    s21::stack<int> a_empty;
    std::stack<int> b_empty;
    EXPECT_EQ(a_empty.size(), b_empty.size());
}

TEST(stack, PushPop) {
    s21::stack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    a.push(7);
    a.push(8);
    a.push(9);
    a.push(10);
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    b.push(6);
    b.push(7);
    b.push(8);
    b.push(9);
    b.push(10);
    EXPECT_EQ(a.size(), b.size());
    a.pop();
    b.pop();
    EXPECT_EQ(a.size(), b.size());
    EXPECT_EQ(a.top(), b.top());
    a.pop();
    a.pop();
    b.pop();
    b.pop();
    EXPECT_EQ(a.size(), b.size());
    EXPECT_EQ(a.top(), b.top());
}

TEST(stack, Swap) {
    s21::stack<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);
    b.push(6);
    b.push(7);
    b.push(8);
    b.push(9);
    b.push(10);
    s21::stack<int> a_empty;
    std::stack<int> b_empty;
    a_empty.swap(a);
    b_empty.swap(b);
    EXPECT_EQ(a_empty.top(), b_empty.top());
    EXPECT_EQ(a.empty(), b.empty());
}



// ========================== SET 2 =================================
// STACK
TEST(StackTest, Constructor_default) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Constructor_initializer_list_1) {
  s21::stack<int> s21_stack{1, 2, 4};
  EXPECT_EQ(s21_stack.size(), 3);
  EXPECT_EQ(s21_stack.top(), 4);
}

TEST(StackTest, Constructor_initializer_list_2) {
  std::initializer_list<int> b;
  s21::stack<int> s21_stack{b};
  std::stack<int> std_stack{b};
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Constructor_copy_1) {
  std::initializer_list<int> il1 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_copy{s21_stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_copy{std_stack};
  EXPECT_EQ(s21_stack_copy.size(), std_stack_copy.size());
  EXPECT_EQ(s21_stack_copy.top(), std_stack_copy.top());
}

TEST(StackTest, Constructor_move_1) {
  std::initializer_list<int> il1 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{s21_stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{std_stack};
  EXPECT_EQ(s21_stack_move.size(), std_stack_move.size());
  EXPECT_EQ(s21_stack_move.top(), std_stack_move.top());
}

TEST(StackTest, Opertator_move_1) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Opertator_move_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Opertator_move_3) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Top_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};

  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Top_2_throw) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};

  EXPECT_THROW(s21_stack.top(), std::out_of_range);
}

TEST(StackTest, Empty_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackTest, Empty_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackTest, Size_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Size_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Push_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Push_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Pop_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Pop_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), 0);
}

TEST(StackTest, Swap_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, Swap_2) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, Swap_3) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2;

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_4) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_5) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2;

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_6) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}


// ========================== SET 3 =================================
// >>>>>>>>> STACK <<<<<<<<<<<<<<
TEST(Stack, simple_test) {
  s21::stack<int> my_stack;
  std::stack<int> orig_stack;
  my_stack.push(1);
  my_stack.push(2);
  my_stack.push(2555);
  my_stack.push(365434);
  orig_stack.push(1);
  orig_stack.push(2);
  orig_stack.push(2555);
  orig_stack.push(365434);
  while (!orig_stack.empty() && !my_stack.empty()) {
    ASSERT_EQ(orig_stack.top(), my_stack.top());
    orig_stack.pop();
    my_stack.pop();
  }
  ASSERT_EQ(orig_stack.empty(), my_stack.empty());
}
TEST(Stack, swap_test) {
  std::stack<double> orig_stack1;
  orig_stack1.push(2.55);
  orig_stack1.push(3.55);
  orig_stack1.push(222.55);
  orig_stack1.push(984.55);
  orig_stack1.push(123.55);
  orig_stack1.push(0.55);
  orig_stack1.push(-34.55);
  std::stack<double> orig_stack2;
  orig_stack2.push(342.22);
  orig_stack2.push(355.01);
  orig_stack2.push(123.99);
  orig_stack2.push(888.34);
  orig_stack2.push(-23.11);
  orig_stack2.push(1002.88);
  orig_stack2.push(1.55);
  s21::stack<double> my_stack1;
  my_stack1.push(2.55);
  my_stack1.push(3.55);
  my_stack1.push(222.55);
  my_stack1.push(984.55);
  my_stack1.push(123.55);
  my_stack1.push(0.55);
  my_stack1.push(-34.55);
  s21::stack<double> my_stack2;
  my_stack2.push(342.22);
  my_stack2.push(355.01);
  my_stack2.push(123.99);
  my_stack2.push(888.34);
  my_stack2.push(-23.11);
  my_stack2.push(1002.88);
  my_stack2.push(1.55);
  orig_stack1.swap(orig_stack2);
  my_stack1.swap(my_stack2);
  while (!orig_stack1.empty() && !my_stack1.empty()) {
    ASSERT_DOUBLE_EQ(orig_stack1.top(), my_stack1.top());
    orig_stack1.pop();
    my_stack1.pop();
  }
  while (!orig_stack2.empty() && !my_stack2.empty()) {
    ASSERT_DOUBLE_EQ(orig_stack2.top(), my_stack2.top());
    orig_stack2.pop();
    my_stack2.pop();
  }
  ASSERT_EQ(orig_stack2.empty(), my_stack2.empty());
}

TEST(Stack, copy_constructor_test) {
  std::stack<int> orig_stack1;
  orig_stack1.push(55);
  orig_stack1.push(555);
  orig_stack1.push(5555);
  orig_stack1.push(55555);
  std::stack<int> orig_stack2(orig_stack1);
  s21::stack<int> my_stack1;
  my_stack1.push(55);
  my_stack1.push(555);
  my_stack1.push(5555);
  my_stack1.push(55555);
  s21::stack<int> my_stack2(my_stack1);
  while (!orig_stack2.empty() && !my_stack2.empty()) {
    ASSERT_EQ(orig_stack2.top(), my_stack2.top());
    orig_stack2.pop();
    my_stack2.pop();
  }
  s21::stack<int> my_stack3;
  std::stack<int> orig_stack3;
  s21::stack<int> my_stack4(my_stack3);
  std::stack<int> orig_stack4(orig_stack3);
  ASSERT_EQ(orig_stack4.empty(), my_stack4.empty());
}

TEST(Stack, move_constructor_test) {
  std::stack<int> orig_stack1;
  orig_stack1.push(55);
  orig_stack1.push(555);
  orig_stack1.push(5555);
  orig_stack1.push(55555);
  std::stack<int> orig_stack2(std::move(orig_stack1));
  s21::stack<int> copy_stack1;
  copy_stack1.push(55);
  copy_stack1.push(555);
  copy_stack1.push(5555);
  copy_stack1.push(55555);
  s21::stack<int> copy_stack2(std::move(copy_stack1));
  while (!orig_stack2.empty() && !copy_stack2.empty()) {
    ASSERT_EQ(orig_stack2.top(), copy_stack2.top());
    orig_stack2.pop();
    copy_stack2.pop();
  }
  ASSERT_EQ(orig_stack1.size(), copy_stack1.size());
}

TEST(Stack, move_operator_test) {
  std::stack<int> orig_stack1;
  orig_stack1.push(55);
  orig_stack1.push(555);
  orig_stack1.push(5555);
  orig_stack1.push(55555);
  std::stack<int> orig_stack2;
  orig_stack2.push(1);
  orig_stack2.push(2);
  orig_stack2 = std::move(orig_stack1);
  s21::stack<int> copy_stack1;
  copy_stack1.push(55);
  copy_stack1.push(555);
  copy_stack1.push(5555);
  copy_stack1.push(55555);
  s21::stack<int> copy_stack2{1, 2};
  copy_stack2 = std::move(copy_stack1);
  while (!orig_stack2.empty() && !copy_stack2.empty()) {
    ASSERT_EQ(orig_stack2.top(), copy_stack2.top());
    orig_stack2.pop();
    copy_stack2.pop();
  }
  ASSERT_EQ(orig_stack1.size(), copy_stack1.size());
}

TEST(Stack, emplace_test) {
  std::stack<int> orig_stack1;
  orig_stack1.push(55);
  orig_stack1.push(555);
  orig_stack1.push(5555);
  orig_stack1.push(55555);
  orig_stack1.emplace(345);
  orig_stack1.emplace(234);
  orig_stack1.emplace(889);
  s21::stack<int> copy_stack1;
  copy_stack1.push(55);
  copy_stack1.push(555);
  copy_stack1.push(5555);
  copy_stack1.push(55555);
  copy_stack1.emplace_front(345);
  copy_stack1.emplace_front(234);
  copy_stack1.emplace_front(889);
  while (!orig_stack1.empty() && !copy_stack1.empty()) {
    ASSERT_EQ(orig_stack1.top(), copy_stack1.top());
    orig_stack1.pop();
    copy_stack1.pop();
  }
  ASSERT_EQ(orig_stack1.size(), copy_stack1.size());
}