#ifndef S21_STACK_H
#define S21_STACK_H
#include "../vector/s21_vector.tpp"

namespace s21 {
template <class T, class Container = s21::vector<T>>
class stack {
 public:
  //  Stack Member type
  using value_type = typename Container::value_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;
  using size_type = typename Container::size_type;

 public:
  //  Stack Member functions
  stack() = default;
  stack(std::initializer_list<value_type> const &items) : cont(items) {}
  stack(const stack &s) = default;
  stack(stack &&s) = default;
  ~stack() {}
  stack &operator=(stack &&s) = default;

  // Stack Element access
  const_reference top() { return cont.back(); }

  // Stack Capacity
  bool empty() { return cont.empty(); }
  size_type size() { return cont.size(); }

  // Stack Modifiers
  void push(const_reference value) { cont.push_back(value); }
  void pop() { cont.pop_back(); }
  void swap(stack &s) { cont.swap(s.cont); }

  // Bonus part
  template <typename... Args>
  void emplace_front(Args &&...args) {
    cont.emplace_back(std::forward<Args>(args)...);
  }

 private:
  Container cont;
};

}  //  namespace s21

#endif  // S21_STACK_H