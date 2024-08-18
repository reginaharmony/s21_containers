#ifndef S21_LIST_H
#define S21_LIST_H

#include <utility>

namespace s21 {

template <typename T>
class list {
 public:
  //  List Member type
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;

 private:
  struct Node {
    T value_;
    Node* prev_;
    Node* next_;
    Node(const T& value) : value_(value), prev_(nullptr), next_(nullptr) {}
  };

  Node* head_;
  Node* tail_;
  Node* end_;
  size_type size_;

  // ================================================================
  // ================================================================
  //  List Iterator Internal Class
  template <typename value_type>
  class ListIterator {
   public:
    ListIterator() { ptr_ = nullptr; }
    ListIterator(Node* ptr) : ptr_(ptr){};
    ListIterator operator++(int) { return ptr_ = ptr_->next_, *this; }
    ListIterator operator--(int) { return ptr_ = ptr_->prev_, *this; }
    ListIterator& operator++() { return ptr_ = ptr_->next_, *this; }
    ListIterator& operator--() { return ptr_ = ptr_->prev_, *this; }
    ListIterator operator+(const size_type val) { return move(val, true); }
    ListIterator operator-(const size_type val) { return move(val, false); }
    bool operator==(ListIterator other) { return ptr_ == other.ptr_; }
    bool operator!=(ListIterator other) { return ptr_ != other.ptr_; }
    reference operator*() {
      if (!ptr_) throw std::invalid_argument("Value is nullptr");
      return ptr_->value_;
    }

   private:
    Node* ptr_ = nullptr;
    friend class list<T>;

    ListIterator move(size_type val, bool fwd = true) {
      Node* tmp = ptr_;
      for (size_type i = 0; i < val; ++i) tmp = (fwd ? tmp->next_ : tmp->prev_);
      return ListIterator(tmp);
    }
  };

  // ================================================================
  //  List Const Iterator Internal Class
  template <typename value_type>
  class ListConstIterator : public ListIterator<T> {
   public:
    ListConstIterator(ListIterator<T> other) : ListIterator<T>(other) {}
    // const T& operator*() { return ListIterator<T>::operator*(); }
  };
  // ================================================================
  // ================================================================

 public:
  // List Member Functions
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  ~list();
  list& operator=(list&& l);

  //  List Member type (iterators)
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using it = iterator;
  using c_it = const_iterator;

  // List Iterators
  it begin() { return !head_ ? it(end_) : it(head_); }
  it end() { return it(end_); }
  c_it begin() const { return !head_ ? c_it(end_) : c_it(head_); }
  c_it end() const { return c_it(end_); }

  // List Element access
  const_reference front() { return !head_ ? end_->value_ : head_->value_; }
  const_reference back() { return !tail_ ? end_->value_ : tail_->value_; }

  // List Capacity
  bool empty() { return size_ == 0; }
  size_type size() { return size_; }
  size_type max_size() { return (PTRDIFF_MAX / sizeof(Node)); }

  // List Modifiers
  void clear();
  void pop_front();
  void pop_back();
  void push_front(const_reference value);
  void push_back(const_reference value);
  void swap(list& other);
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void merge(list& other);
  void reverse();
  void unique();
  void sort();
  void splice(const_iterator pos, list& other);

 private:
  // Supplementary
  void reset();
  void update();
  void copy(const list& l);
  void pop(Node*& node);
  void push(const_reference value, bool front);
  void sort_nodes(iterator left, iterator right);
};
}  // namespace s21
#endif  // S21_LIST_H
