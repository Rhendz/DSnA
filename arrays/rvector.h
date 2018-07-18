#ifndef DSNA_ARRAYS_RVECTOR_H
#define DSNA_ARRAYS_RVECTOR_H

namespace rhendz {

static const int kMinCapacity = 16;
static const int kGrowthFactor = 2;
static const int kShrinkFactor = 4;

class RVector {
 public:
  RVector(int capacity);
  ~RVector();
  // Returns the current number of items in the RVector.
  int GetSize() const;
  // Returns the current number of items that can fit in the RVector.
  int GetCapacity() const;
  // Returns whether or not the RVector is empty.
  bool IsEmpty() const;
  // Returns an item at the given index; otherwise, an error is thrown.
  int At(int index) const;
  // An item is pushed onto the end of the RVector.
  void Push(int item);
  // An item is inserted at the given index and all items are shifted
  // accordingly.
  void Insert(int index, int item);
  // An item is inserted at the front of the RVector.
  void Prepend(int item);
  // The item at the end of the RVector is removed and returned.
  int Pop();
  // The item at the given index is deleted and all trailing elements
  // are shifted towards the left.
  void Delete(int index);
  // All occurrences of item are removed from the RVector and the RVector
  // is shifted accordingly.
  void Remove(int item);
  // Looks for item and returns the index at which the first occurrence is
  // found; otherwise, -1 is returned.
  int Find(int item) const;

 protected:
  // The capacity that can be held in the RVector before a resize is required.
  int capacity_{kMinCapacity};
  // The current amount of items in the RVector.
  int size_{0};
  // The storage array
  int *data_;
  // Checks to see if resizing is required using the following conditions:
  // (1) If capacity is reached, the new capacity is doubled.
  // (2) If size is a 1/4 the capacity, the new capacity is halved.
  void Resize(int size);
};

}  // namespace rhendz

#endif  // DSNA_ARRAYS_RVECTOR_H
