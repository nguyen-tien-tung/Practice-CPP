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
      // TestPop();
      // TestPrepend();
      // TestRemove();
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
    void TestMyVector::TestIsEmpty() const{
      TungVector<int> testVector(4);
      for (int i = 4; i <= 0; i--){
        testVector.remove(i);
      }
      assert(testVector.isEmpty());
    };
    void TestMyVector::TestGetValueAt() const{
      TungVector<int> testMyVector(10);
      for(int i = 0; i < 10; i++){
        testMyVector.push(i);
      }
      assert(testMyVector.getValueAt(9) == 9);
      assert(testMyVector.getValueAt(7) == 7);
    };
    void TestMyVector::TestInsert() const{
      TungVector<int> testVector(16);
      for(int i = 0; i < 16; i++){
        testVector.push(i);
      }
      testVector.insert(1, 20);
      testVector.insert(15, 24);
      testVector.insert(16, 22);
      assert(testVector.getValueAt(1) == 20);
      assert(testVector.getValueAt(14) == 13);
      assert(testVector.getValueAt(15) == 24);
      assert(testVector.getValueAt(16) == 22);
      assert(testVector.getValueAt(17) == 14);
      // std::cout << "hihihaha" << std::endl;
      // for (int i = 0; i < 32; i++){
      //   std::cout << testVector.getValueAt(i) << std::endl;
      // }
    };
    // void TestMyVector::TestPop() const;
    // void TestMyVector::TestPrepend() const;
    // void TestMyVector::TestRemove() const;
    // void TestMyVector::TestFind() const;
}