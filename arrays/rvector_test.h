#ifndef DSNA_ARRAYS_RVECTOR_TEST_H
#define DSNA_ARRAYS_RVECTOR_TEST_H

namespace rz {

class RVectorTest {
 public:
  void RunTests() const;
  void TestGetSize() const;
  void TestGetCapacity() const;
  void TestIsEmpty() const;
  void TestAt() const;
  void TestPush() const;
  void TestInsert() const;
  void TestPrepend() const;
  void TestPop() const;
  void TestDelete() const;
  void TestRemove() const;
  void TestFind() const;
};

}  // namespace rz

#endif  // DSNA_ARRAYS_RVECTOR_TEST_H
