#include "s21_vector.h"
namespace s21 {
// Vector Member functions
// =================================================================

template <class T>
vector<T>::vector() {
  this->reset();
}

template <class T>
vector<T>::vector(size_type n) {
  if (this->max_size() < n)
    throw std::out_of_range("cannot create s21::vector larger than max_size()");
  this->size_ = this->capacity_ = n, this->container_ = new T[n];
}

template <class T>
vector<T>::vector(std::initializer_list<T> const& items) {
  this->size_ = this->capacity_ = items.size();
  if (!this->size_) this->reset();
  this->container_ = new T[this->size_],
  std::copy(items.begin(), items.end(), this->container_);
}

template <class T>
vector<T>::vector(const vector& v) {
  this->size_ = v.size_, this->capacity_ = v.capacity_;
  this->container_ = new T[this->size_];
  std::copy(v.container_, v.container_ + this->size_, this->container_);
}

template <class T>
vector<T>::vector(vector&& v)
    : size_(v.size_), capacity_(v.capacity_), container_(v.container_) {
  v.reset();
}

template <class T>
vector<T>::~vector() {
  if (this->container_) delete[] this->container_;
  this->reset();
}

template <class T>
class s21::vector<T>& vector<T>::operator=(vector&& v) {
  if (this == &v) return *this;
  return this->swap(v), *this;
}

// Vector Element access
// =================================================================

template <class T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) throw std::out_of_range("Index out of range");
  return container_[pos];
}

template <class T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  if (pos >= size()) throw std::out_of_range("Index out of range");
  return container_[pos];
}

template <class T>
typename vector<T>::const_reference vector<T>::front() {
  if (empty()) throw std::out_of_range("Out of range");
  return *container_;
}

template <class T>
typename vector<T>::const_reference vector<T>::back() {
  if (empty()) throw std::out_of_range("Out of range");
  return *(container_ + size_ - 1);
}

template <class T>
typename vector<T>::iterator vector<T>::data() {
  return container_;
}

// Vector Modifiers
// =================================================================

template <class T>
void vector<T>::clear() {
  this->size_ = 0;
}

template <class T>
typename vector<T>::iterator vector<T>::insert(T* pos, const T& value) {
  check_range(pos);
  size_type index = pos - container_;
  if (size_ + 1 >= capacity_) reallocate(capacity_ * 2, true);
  std::move_backward(container_ + index, container_ + size_,
                     container_ + size_ + 1);
  container_[index] = value, size_++;
  return &(container_[index]);
}

template <class T>
void vector<T>::erase(iterator pos) {
  check_range(pos);
  std::move(pos + 1, container_ + size_, pos);
  size_--;
}

template <class value_type>
void vector<value_type>::push_back(const_reference value) {
  if (size_ >= capacity_) reserve(2 * (capacity_ > 0 ? capacity_ : 1));
  container_[size_++] = value;
}

template <class T>
void vector<T>::pop_back() {
  size_ > 0 ? size_-- : 0;
}

template <class T>
void vector<T>::swap(vector& other) noexcept {
  std::swap(other.size_, size_);
  std::swap(other.capacity_, capacity_);
  std::swap(other.container_, container_);
}

template <class T>
template <class... Args>
typename vector<T>::iterator vector<T>::emplace(const T* pos, Args&&... args) {
  std::initializer_list<T> items = {args...};
  std::ptrdiff_t offset = pos - container_;
  iterator it = const_cast<iterator>(pos);
  for (const_reference item : items) {
    it = insert(it, item);
    it++;
  }

  return container_ + offset;
}

template <class T>
template <class... Args>
void vector<T>::emplace_back(Args... args) {
  std::initializer_list<T> items = {args...};
  for (const_reference item : items) {
    push_back(item);
  }
}

// Supplementary
// =================================================================

template <class T>
void vector<T>::reset() {
  size_ = capacity_ = 0, container_ = nullptr;
}

template <class T>
void vector<T>::reallocate(size_type size, bool expand) {
  if ((expand && size > capacity_) || (!expand && size < capacity_)) {
    T* temp = new T[size]();
    for (size_type i = 0; i < size_; i++) temp[i] = container_[i];
    delete[] container_, container_ = temp, capacity_ = size;
  }
}

template <class T>
void vector<T>::check_range(typename vector<T>::iterator pos) {
  size_type zero = 0;
  size_type index = pos - container_;
  if (zero > index || index > size_)
    throw std::out_of_range("Index out ot range");
}

}  // namespace s21

// template <class T>
// typename vector<T>::iterator vector<T>::insert(T* pos, const T& value) {
//   size_type index = pos - container_;
//   check_range(pos);
//   reserve(size_ + 1);
//   std::move_backward(container_ + index, container_ + size_,
//                      container_ + size_ + 1);
//   container_[index] = value, size_++;
//   return &(container_[index]);
// }

// template <class T>
// typename vector<T>::iterator vector<T>::insert(T* pos, const T& value) {
//   size_type index = pos - container_;
//   check_range(pos);
//   if (size_ + 1 >= capacity_) reallocate(capacity_ * 2, true);
//   T replace = container_[index];
//   size_++;
//   container_[index] = value;
//   for (size_type i = index + 1; i < size_; ++i) {
//     T next = container_[i];
//     container_[i] = replace;
//     replace = next;
//   }
//   return container_ + index;
// }

// template <class value_type>
// void vector<value_type>::expand(size_type size, bool flag) {
//     // Determine the new capacity
//     size_type newCapacity = flag ? size : (2 * (capacity_ > 0 ? capacity_ :
//     2)); iterator tmp = container_; container_ = new value_type[newCapacity];
//     for (size_t i = 0; i < size_; ++i) {
//         container_[i] = tmp[i];
//     }

//     delete[] tmp;
//     capacity_ = newCapacity;
// }
