#include "rvector_test.h"
#include "assert.h"
#include "rvector.h"
#include <iostream>

namespace rz {

void RVectorTest::RunTests() const {
  TestGetSize();
  std::cout << "GetSize passed." << std::endl;
  TestGetCapacity();
  std::cout << "GetCapacity passed." << std::endl;
  TestIsEmpty();
  std::cout << "IsEmpty passed." << std::endl;
  TestAt();
  std::cout << "At passed." << std::endl;
  TestPush();
  std::cout << "Push passed." << std::endl;
  TestInsert();
  std::cout << "Insert passed." << std::endl;
  TestPrepend();
  std::cout << "Prepend passed." << std::endl;
  TestPop();
  std::cout << "Pop passed." << std::endl;
  TestDelete();
  std::cout << "Delete passed." << std::endl;
  TestRemove();
  std::cout << "Remove passed." << std::endl;
  TestFind();
  std::cout << "Find passed." << std::endl;
}

void RVectorTest::TestGetSize() const {
  rz::RVector test(5);
  assert(test.GetSize() == 0);

  int add_items = 10;
  for (int i = 0; i < add_items; i++) {
    test.Push(i);
  }

  assert(test.GetSize() == add_items);
}

void RVectorTest::TestGetCapacity() const {
  rz::RVector test(5);
  assert(test.GetCapacity() == rz::kMinCapacity);

  rz::RVector test_2(25);
  assert(test_2.GetCapacity() == rz::kMinCapacity * 2);

  for (int i = 0; i < 32; i++) {
    test_2.Push(i);
  }

  assert(test_2.GetCapacity() == rz::kMinCapacity * 4);
}

void RVectorTest::TestIsEmpty() const {
  rz::RVector test(5);
  assert(test.IsEmpty() == true);

  test.Push(1);
  assert(test.IsEmpty() == false);
}

void RVectorTest::TestAt() const {
  rz::RVector test(5);
  test.Push(1);
  test.Push(5);

  assert(test.At(0) == 1);
  assert(test.At(1) == 5);
}

void RVectorTest::TestPush() const {
  // Since the tests rely on Push() if all the tests pass
  // Push() does as well.
}

void RVectorTest::TestInsert() const {
  rz::RVector test(5);
  test.Push(1);
  test.Push(2);
  test.Push(3);
  test.Insert(1, 4);

  assert(test.At(1) == 4);
  assert(test.At(2) == 2);
  assert(test.At(3) == 3);
}

void RVectorTest::TestPrepend() const {
  rz::RVector test(5);
  test.Push(2);
  test.Prepend(1);

  assert(test.At(0) == 1);
  assert(test.At(1) == 2);
}

void RVectorTest::TestPop() const {
  rz::RVector test(5);
  test.Push(1);
  test.Push(2);

  int pop = test.Pop();
  assert(pop == 2);
}

void RVectorTest::TestDelete() const {
  rz::RVector test(5);
  test.Push(1);
  test.Push(2);
  test.Push(3);

  test.Delete(0);

  assert(test.At(0) == 2);
  assert(test.At(1) == 3);
}

void RVectorTest::TestRemove() const {
  rz::RVector test(5);
  test.Push(1);
  test.Push(2);
  test.Push(1);
  test.Push(1);
  test.Push(3);

  test.Remove(1);
  assert(test.GetSize() == 2);
  assert(test.At(0) == 2);
  assert(test.At(1) == 3);
}

void RVectorTest::TestFind() const {
  rz::RVector test(5);
  test.Push(1);
  test.Push(2);
  test.Push(1);
  test.Push(1);
  test.Push(3);

  int index = test.Find(1);
  assert(index == 0);

  test.Delete(0);
  index = test.Find(1);
  assert(index == 1);
}

}  // namespace rz
