#include<cassert>
#include "test_my_vector.h"
#include "my_vector.h"
namespace MyVector {
    void TestMyVector::RunTest() const{
      TestSize();
      TestCapacity();
      // TestPush();
      // TestPop();
      // TestPrepend();
      // TestInsert();
      // TestRemove();
      // TestGetValueAt();
      // TestFind();
    };
    void TestMyVector::TestSize() const{
      TungVector<int> testVector(3);
      assert(testVector.getSize() == 0);
    };
    void TestMyVector::TestCapacity() const{
      TungVector<int> testVector(3);
      assert(testVector.getCapacity() == 16);
    };
    // void TestMyVector::TestPush() const;
    // void TestMyVector::TestPop() const;
    // void TestMyVector::TestPrepend() const;
    // void TestMyVector::TestInsert() const;
    // void TestMyVector::TestRemove() const;
    // void TestMyVector::TestGetValueAt() const;
    // void TestMyVector::TestFind() const;
}