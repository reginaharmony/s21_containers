#ifndef VECTOR_H
#define VECTOR_H

#include <utility>

namespace s21 {

template <typename T>
class vector {
 public:
  // Vector Member type
  using value_type = T;
  using reference = T &;
  using iterator = T *;
  using const_reference = const T &;
  using const_iterator = const T *;
  using size_type = std::size_t;

 public:
  // Vector Member functions
  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();
  vector &operator=(vector &&v);

  // Vector Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data();

  // Vector Modifiers
  void clear();
  iterator insert(T *pos, const T &value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other) noexcept;

  // Vector Iterators
  iterator begin() { return iterator(container_); }
  iterator end() { return iterator(container_ + size_); }
  const_iterator begin() const { return const_iterator(container_); };
  const_iterator end() const { return const_iterator(container_ + size_); };

  // Vector Capacity
  bool empty() const { return size_ == 0; };
  size_type size() const { return size_; };
  size_type max_size() const { return PTRDIFF_MAX / sizeof(value_type); }
  size_type capacity() const { return capacity_; };
  void reserve(size_type size) { reallocate(size, true); };
  void shrink_to_fit() { reallocate(size_, false); };

  // Bonus part
  template <typename... Args>
  iterator emplace(const_iterator pos, Args &&...args);
  template <typename... Args>
  void emplace_back(Args... args);

 private:
  size_type size_;
  size_type capacity_;
  value_type *container_;

  // Supplementary
  void reset();
  void reallocate(size_type size_new, bool expand);
  void check_range(iterator pos);
};

}  // namespace s21
#endif  // VECTOR_H

// return static_cast<size_type>(SIZE_MAX) / sizeof(T) - 1;
