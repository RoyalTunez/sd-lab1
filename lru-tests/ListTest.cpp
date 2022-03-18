#include "gtest/gtest.h"
#include "DoublyLinkedList.h"
#include <utility>

TEST(List, AddSingleElement) {
    DoublyLinkedList<std::pair<int, int>> list;

    auto ins = std::pair<int, int>(1, 1);

    list.addFirst(std::make_pair(1, 1));

    ASSERT_EQ(list.size(), 1);
    
    auto firstElement = list.peekFirst();

    ASSERT_EQ(firstElement->getValue(), ins);
}

TEST(List, AddManyElements) {
    DoublyLinkedList<std::pair<int, int>> list;

    const int TEST_SIZE = 100;

    for (int test = 0; test < TEST_SIZE; test++) {
        auto ins = std::make_pair(test, test);

        list.addFirst(ins);

        ASSERT_EQ(list.size(), test + 1);

        ASSERT_EQ(list.peekFirst()->getValue(), ins);
    }
}

TEST(List, Remove) {
    DoublyLinkedList<int> list;

    auto node1 = list.addFirst(1);
    auto node2 = list.addFirst(2);
    auto node3 = list.addFirst(3);

    node2->remove();
    ASSERT_EQ(list.size(), 2);

    node1->remove();
    ASSERT_EQ(list.size(), 1);

    node3->remove();
    ASSERT_EQ(list.size(), 0);
}

TEST(List, RemoveLast) {
    DoublyLinkedList<int> list;

    const int TEST_SIZE = 100;

    for (int test = 0; test < TEST_SIZE; test++) {
        list.addFirst(test);
    }

    for (int test = 0; test < TEST_SIZE; test++) {
        list.removeLast();

        ASSERT_EQ(list.size(), TEST_SIZE - test - 1);
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}