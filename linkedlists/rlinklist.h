#ifndef DSNA_LINKEDLISTS_RLINKLIST_H
#define DSNA_LINKEDLISTS_RLINKLIST_H

namespace rz {

struct Node {
  int val;
  Node* next;  // Pointer to the next node in the list
};

class RLinkList {
 public:
  RLinkList();
  ~RLinkList();
  // Returns the size of the RLinkList.
  int GetSize() const;
  // Returns true if RLinkList is empty.
  bool IsEmpty() const;
  // Returns the value at the give index.
  int At(int index) const;
  // Adds a node to the front of the list.
  void PushFront(int value);
  // Adds a node to the back of the list.
  void PushBack(int value);
  // Removes the item at the back and returns that item.
  int PopBack();
  // Get value of front node.
  int GetFront() const;
  // Get value of back node.
  int GetBack() const;
  // Inserts node at index.
  void Insert(int index, int value);
  // Removes node atgiven index.
  void Erase(int index);
  // Returns value of node at the nth position from the end.
  int AtEnd(int index) const;
  // Reverses thje list.
  void Reverse();
  // Removes the first item in the list with given value.
  void Remove(int value);
 protected:
  // The head pointer of the list.
  Node *head_;
};

}  // namespace rz

#endif // DSNA_LINKEDLISTS_RLINKLIST_H
