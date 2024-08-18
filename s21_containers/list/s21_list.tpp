#include "s21_list.h"
namespace s21 {

//  List Member Functions
// =================================================================
template <class T>
list<T>::list() {
  reset();
}

template <class T>
list<T>::list(size_type n) {
  if (n >= max_size()) throw std::out_of_range("Size limit exception");
  reset();
  for (size_type i = 0; i < n; ++i) push_back(T());
}

template <class T>
list<T>::list(std::initializer_list<T> const& items) {
  reset();
  for (const auto& item : items) push_back(item);
}

template <class T>
list<T>::list(const list& l) {
  reset(), copy(l);
}
template <class T>
list<T>::list(list&& l) {
  reset(), swap(l);
}

template <class T>
list<T>::~list() {
  clear(), delete end_;
}

template <class T>
typename list<T>::list& list<T>::operator=(list&& l) {
  if (this != &l) clear(), swap(l);
  return *this;
}

// List Modifiers
// =================================================================
template <class T>
void list<T>::clear() {
  while (!empty()) pop_back();
}

template <class T>
void list<T>::pop_front() {
  pop(head_);
}

template <class T>
void list<T>::pop_back() {
  pop(tail_);
}

template <class T>
void list<T>::push_front(const_reference value) {
  push(value, true);
}

template <class T>
void list<T>::push_back(const_reference value) {
  push(value, false);
}

template <class T>
void list<T>::swap(list& other) {
  using std::swap;
  swap(this->head_, other.head_);
  swap(this->tail_, other.tail_);
  swap(this->end_, other.end_);
  swap(this->size_, other.size_);
}

template <class T>
typename list<T>::it list<T>::insert(it pos, const_reference value) {
  Node* new_node = new Node(value);
  if (empty())
    new_node->next_ = new_node->prev_ = end_, head_ = tail_ = new_node;
  else {
    if (pos.ptr_ == head_) head_ = new_node;
    if (pos.ptr_ == end_) tail_ = new_node;
    new_node->next_ = pos.ptr_;
    new_node->prev_ = pos.ptr_->prev_;
    pos.ptr_->prev_->next_ = new_node;
    pos.ptr_->prev_ = new_node;
  }
  return size_++, update(), iterator(new_node);
}

template <class T>
void list<T>::erase(iterator pos) {
  if (pos == end_ || !size_) throw std::invalid_argument("Invalid argument");
  if (pos.ptr_ == head_) head_ = pos.ptr_->next_;
  if (pos.ptr_ == tail_) tail_ = pos.ptr_->prev_;
  if (pos.ptr_->prev_) pos.ptr_->prev_->next_ = pos.ptr_->next_;
  if (pos.ptr_->next_) pos.ptr_->next_->prev_ = pos.ptr_->prev_;
  delete pos.ptr_, size_--, update();
}

template <class T>
void list<T>::merge(list<T>& other) {
  if (this->empty() && other.empty()) return;
  iterator it_this = this->begin();
  iterator it_other = other.begin();
  while (it_this != this->end() && it_other != other.end()) {
      if (it_this.ptr_->value_ <= it_other.ptr_->value_)  it_this++; 
      else this->insert(it_this, it_other.ptr_->value_), it_other++; 
  }
  while (it_other != other.end()) {
      this->insert(this->end(), it_other.ptr_->value_), it_other++;
  }
  other.clear();
}


template <class T>
void list<T>::reverse() {
  if (this->empty()) return;
  size_type step = 0;
  for (iterator it = this->begin(); step <= this->size(); ++it)
    step++, std::swap(it.ptr_->prev_, it.ptr_->next_);
  std::swap(head_, tail_);
}

template <class T>
void list<T>::unique() {
  if (this->empty()) return;
  for (iterator it = this->begin(); it != this->end(); it++)
    if (it.ptr_->value_ == it.ptr_->prev_->value_) this->erase(it - 1);
}

template <class T>
void list<T>::splice(const_iterator pos, list& other) {
  if (other.empty()) return;
  for (iterator it = other.begin(); it != other.end(); it++) insert(pos, *it);
  other.clear();
}

template <class T>
void list<T>::sort() {
  if (size_ > 1) sort_nodes(begin(), --end());
}

// Supplementary
// =================================================================

template <class T>
void list<T>::reset() {
  size_ = 0, head_ = tail_ = nullptr, end_ = new Node(size_);
}

template <class T>
void list<T>::update() {
  if (!end_) return;
  end_->next_ = head_;
  end_->prev_ = tail_;
  end_->value_ = size_;
  if (head_) head_->prev_ = end_;
  if (tail_) tail_->next_ = end_;
}

template <class T>
void list<T>::copy(const list& l) {
  Node* current = l.head_;
  for (size_type i = 0; i != l.size_; i++)
    push_back(current->value_), current = current->next_;
}

template <class T>
void list<T>::pop(Node*& node) {
  if (empty()) throw std::out_of_range("list is empty");
  if (node == head_) {
    Node* first = node;
    if (size_ == 1) head_ = tail_ = nullptr;
    head_ = first->next_, head_->prev_ = nullptr;
    delete first;
  } else {
    Node* last = node;
    if (size_ == 1) head_ = tail_ = nullptr;
    tail_ = last->prev_, tail_->next_ = nullptr;
    delete last;
  }
  size_--, update();
}

template <class T>
void list<T>::push(const_reference value, bool front) {
  Node* new_node = new Node(value);
  if (empty()) head_ = tail_ = new_node;
  if (front) {
    new_node->next_ = head_;
    head_->prev_ = new_node;
    head_ = new_node;
  } else {
    new_node->prev_ = tail_;
    tail_->next_ = new_node;
    tail_ = new_node;
  }
  size_++, update();
}

template <class T>
void list<T>::sort_nodes(iterator first, iterator last) {
  if (first == last || first == end_ || last == end_ || first == tail_) return;
  T pivot_value = last.ptr_->value_;
  iterator pivot = first;
  for (iterator j = first; j != last; ++j)
    if (j.ptr_->value_ <= pivot_value)
      std::swap(pivot.ptr_->value_, j.ptr_->value_), pivot++;
  std::swap(pivot.ptr_->value_, last.ptr_->value_);

  sort_nodes(first, --pivot);
  sort_nodes(++pivot, last);
}

}  // namespace s21