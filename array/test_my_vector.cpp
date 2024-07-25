#include<cassert>
#include<iostream>
#include "test_my_vector.h"
#include "my_vector.h"
namespace MyVector {
    void TestMyVector::RunTest() const{
      TestSize();
      TestCapacity();
      TestIsEmpty();
      TestGetValueAt();
      TestInsert();
      TestPop();
      // TestPrepend();
      // TestRemove();
      // TestFind();
    };
    void TestMyVector::TestSize() const{
      TungVector<int> testVector(3);
      assert(testVector.getSize() == 3);
    };
    void TestMyVector::TestCapacity() const{
      TungVector<int> testVector(3);
      TungVector<int> testVector1(24);
      TungVector<int> testVector2(48);
      assert(testVector.getCapacity() == 16);
      assert(testVector1.getCapacity() == 32);
      assert(testVector2.getCapacity() == 64);
    };
    void TestMyVector::TestIsEmpty() const{
      TungVector<int> testVector(4);
      for (int i = 3; i >= 0; i--){
        testVector.remove(i);
      }
      assert(testVector.isEmpty());
    };
    void TestMyVector::TestGetValueAt() const{
      TungVector<int> testMyVector(10);
      for(int i = 0; i < 10; i++){
        testMyVector.push(i);
      }
      assert(testMyVector.getValueAt(9) == 0);
      assert(testMyVector.getValueAt(10) == 0);
      assert(testMyVector.getValueAt(11) == 1);
      assert(testMyVector.getValueAt(17) == 7);
    };
    void TestMyVector::TestInsert() const{
      TungVector<int> testVector(0);
      for(int i = 0; i < 16; i++){
        testVector.push(i);
      }
      testVector.insert(0, 55);
      testVector.insert(1, 20);
      testVector.insert(15, 24);
      testVector.insert(16, 22);
      assert(testVector.getValueAt(0) == 55);
      assert(testVector.getValueAt(1) == 20);
      assert(testVector.getValueAt(14) == 12);
      assert(testVector.getValueAt(15) == 24);
      assert(testVector.getValueAt(16) == 22);
      assert(testVector.getValueAt(17) == 13);
    };
    void TestMyVector::TestPop() const {
      TungVector<int> testVector(20);
      int x = testVector.pop();
      assert(x == 0);
      assert(testVector.getSize() == 19);
      testVector.insert(19, 25);
      x = testVector.pop();
      int y = testVector.pop();
      assert(x == 0);
      assert(y == 25);
      assert(testVector.getSize() == 18);
    };
    // void TestMyVector::TestRemove() const;
    // void TestMyVector::TestFind() const;
}