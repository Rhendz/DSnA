#include "rvector.h"
#include <iostream>

namespace rz {

RVector::RVector(int capacity) : size_(0) {
  if (capacity < 1) {
    std::cout << "Can not make an RVector of that size!" << std::endl;
    exit(EXIT_FAILURE);
  }

  // Accommodate user capacity - makes sure internal capacity_ is correct.
  Resize(capacity);
  data_ = new int[capacity_];
}

RVector::~RVector() {
  delete data_;
}

int RVector::GetSize() const {
  return size_;
}

int RVector::GetCapacity() const {
  return capacity_;
}

bool RVector::IsEmpty() const {
  return size_ == 0;
}

int RVector::At(int index) const {
  if (!IsInBounds(index)) { exit(EXIT_FAILURE); }

  return data_[index];
}

void RVector::Push(int item) {
  Resize(size_ + 1);

  data_[size_] = item;
  size_++;
}

void RVector::Insert(int index, int item) {
  if (!IsInBounds(index)) { exit(EXIT_FAILURE); }

  Resize(size_ + 1);

  // Shift all elements to the right
  for (int i = size_; i > index; i--) {
    data_[i] = data_[i - 1];
  }

  data_[index] = item;
  size_++;
}

void RVector::Prepend(int item) { Insert(0, item); }

int RVector::Pop() {
  if (size_ == 0) {
    std::cout << "Nothing to pop!" << std::endl;
    exit(EXIT_FAILURE);
  }

  int val = data_[size_ - 1];

  size_--;

  Resize(size_);

  return val;
}

void RVector::Delete(int index) {
  if (!IsInBounds(index)) { exit(EXIT_FAILURE); }

  for (int i = index; i < size_ - 1; i++) {
    data_[i] = data_[i + 1];
  }

  size_--;

  Resize(size_);
}

void RVector::Remove(int item) {
  int index = Find(item);

  while (index != -1) {
    Delete(index);
    index = Find(item);
  }
}

int RVector::Find(int item) const {
  for (int i = 0; i < size_; i++) {
    if (data_[i] == item) return i;
  }

  return -1;
}

void RVector::Resize(int size) {
  if (size >= capacity_) {
    capacity_ *= kGrowthFactor;
    return;
  }

  if (size <= capacity_ / 4 && size > kMinCapacity) {
    capacity_ *= (1 / kGrowthFactor);
    return;
  }
}

bool RVector::IsInBounds(int index) const {
  return !(index < 0 || index >= size_);
}

}  // namespace rz
