#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "BinaryTree.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Basic Tree<int> Operations: ") {

    BinaryTree<int> bt;

    CHECK_NOTHROW(bt.add_root(1));
    CHECK_NOTHROW(bt.add_left(1,2));
    CHECK_NOTHROW(bt.add_left(2,3));
    CHECK_NOTHROW(bt.add_left(3,4));
    CHECK_NOTHROW(bt.add_right(1,5));
    CHECK_NOTHROW(bt.add_right(5,6));
    CHECK_NOTHROW(bt.add_right(6,7));
    CHECK_NOTHROW(bt.add_left(5,8));
    CHECK_NOTHROW(bt.add_right(3,9));
    CHECK_THROWS(bt.add_right(50,9));
    CHECK_THROWS(bt.add_right(10,9));
    CHECK_THROWS(bt.add_right(30,9));

}


TEST_CASE("Basic Tree<string> Operations: ") {

    BinaryTree<string> bt;

    CHECK_NOTHROW(bt.add_root("1"));
    CHECK_NOTHROW(bt.add_left("1","2"));
    CHECK_NOTHROW(bt.add_left("2","3"));
    CHECK_NOTHROW(bt.add_left("3","4"));
    CHECK_NOTHROW(bt.add_right("1","5"));
    CHECK_NOTHROW(bt.add_right("5","6"));
    CHECK_NOTHROW(bt.add_right("6","7"));
    CHECK_NOTHROW(bt.add_left("5","8"));
    CHECK_NOTHROW(bt.add_right("3","9"));
    CHECK_THROWS(bt.add_right("50","9"));
    CHECK_THROWS(bt.add_right("10","9"));
    CHECK_THROWS(bt.add_right("30","9"));

}



TEST_CASE("Tree<int> Traversals Check"){

    BinaryTree<int> bt;

    CHECK_NOTHROW(bt.add_root(7));
    CHECK_NOTHROW(bt.add_left(7, 3));
    CHECK_NOTHROW(bt.add_right(7, 6));
    CHECK_NOTHROW(bt.add_left(3, 1));
    CHECK_NOTHROW(bt.add_right(3, 2));
    CHECK_NOTHROW(bt.add_left(6, 4));
    CHECK_NOTHROW(bt.add_right(6, 5));
    CHECK_THROWS(bt.add_right(10, 5));



    u_int i = 0;

    vector<int> preOrder = {7, 3, 1, 2, 6, 4, 5};
    for (auto it=bt.begin_preorder(); it!=bt.end_preorder(); ++it) {
                CHECK_EQ(*it, preOrder.at(i));
        i++;
    }

    i = 0;

    vector<int> inOrder = {1, 3, 2, 7, 4, 6, 5};
    for (auto it=bt.begin_inorder(); it!=bt.end_inorder(); ++it) {
                CHECK_EQ(*it, inOrder.at(i));
        i++;
    }

    i = 0;

    vector<int> postOrder = {1 ,2 ,3 ,4 ,5 ,6 ,7};
    for (auto it=bt.begin_postorder(); it!=bt.end_postorder(); ++it) {
                CHECK_EQ(*it, postOrder.at(i));
    }
}



TEST_CASE("Tree<double> Traversals Check"){

    BinaryTree<double> bt;

    CHECK_NOTHROW(bt.add_root(7));
    CHECK_NOTHROW(bt.add_left(7, 3));
    CHECK_NOTHROW(bt.add_right(7, 6));
    CHECK_NOTHROW(bt.add_left(3, 1));
    CHECK_NOTHROW(bt.add_right(3, 2));
    CHECK_NOTHROW(bt.add_left(6, 4));
    CHECK_NOTHROW(bt.add_right(6, 5));
    CHECK_THROWS(bt.add_right(10, 5));
    CHECK_THROWS(bt.add_left(10, 5));


    u_int i = 0;

    vector<double> preOrder = {7.2, 3.2, 1.2, 2.2, 6.2, 4.2, 5.2};
    for (auto it=bt.begin_preorder(); it!=bt.end_preorder(); ++it) {
                CHECK_EQ(*it, preOrder.at(i));
        i++;
    }

    i = 0;

    vector<double> inOrder = {1.2, 3.2, 2.2, 7.2, 4.2, 6.2, 5.2};
    for (auto it=bt.begin_inorder(); it!=bt.end_inorder(); ++it) {
                CHECK_EQ(*it, inOrder.at(i));
        i++;
    }

    i = 0;

    vector<double> postOrder = {1.2 ,2.2 ,3.2 ,4.2 ,5.2 ,6.2 ,7.2};
    for (auto it=bt.begin_postorder(); it!=bt.end_postorder(); ++it) {
                CHECK_EQ(*it, postOrder.at(i));
        i++;
    }
}


TEST_CASE("Tree<string> Traversals Check"){

    BinaryTree<string> bt;

    CHECK_NOTHROW(bt.add_root("7"));
    CHECK_NOTHROW(bt.add_left("7", "3"));
    CHECK_NOTHROW(bt.add_right("7", "6"));
    CHECK_NOTHROW(bt.add_left("3", "1"));
    CHECK_NOTHROW(bt.add_right("3", "2"));
    CHECK_NOTHROW(bt.add_left("6", "4"));
    CHECK_NOTHROW(bt.add_right("6", "5"));
    CHECK_THROWS(bt.add_right("10", "5"));
    CHECK_THROWS(bt.add_left("10", "5"));


    u_int i = 0;

    vector<string> preOrder = {"7", "3", "1", "2", "6", "4", "5"};
    for (auto it=bt.begin_preorder(); it!=bt.end_preorder(); ++it) {
                CHECK_EQ(*it, preOrder.at(i));
        i++;
    }

    i = 0;

    vector<string> inOrder = {"1", "3", "2", "7", "4", "6", "5"};
    for (auto it=bt.begin_inorder(); it!=bt.end_inorder(); ++it) {
                CHECK_EQ(*it, inOrder.at(i));
        i++;
    }

    i = 0;

    vector<string> postOrder = {"1" ,"2" ,"3" ,"4" ,"5" ,"6" ,"7"};
    for (auto it=bt.begin_postorder(); it!=bt.end_postorder(); ++it) {
                CHECK_EQ(*it, postOrder.at(i));
        i++;
    }
}


TEST_CASE("Test for the tree of char"){

    BinaryTree<char> bt;

    CHECK_NOTHROW(bt.add_root('5'));
    CHECK_NOTHROW(bt.add_left('5', '3'));
    CHECK_NOTHROW(bt.add_right('5', '7'));
    CHECK_NOTHROW(bt.add_left('3', '2'));
    CHECK_NOTHROW(bt.add_right('3', '4'));
    CHECK_NOTHROW(bt.add_left('7', '6'));
    CHECK_NOTHROW(bt.add_right('7', '8'));
    CHECK_THROWS(bt.add_right('1', '8'));
    CHECK_THROWS(bt.add_left('1', '8'));



    u_int i = 0;

    vector<char> preOrder = {'5','3', '2', '4', '7', '6', '8'};
    for (auto it=bt.begin_preorder(); it!=bt.end_preorder(); ++it) {
                CHECK_EQ(*it, preOrder.at(i));
        i++;
    }

    i = 0;

    vector<char> inOrder = {'2', '3', '4', '5', '6', '7', '8'};
    for (auto it=bt.begin_inorder(); it!=bt.end_inorder(); ++it) {
                CHECK_EQ(*it, inOrder.at(i));
        i++;
    }

    i = 0;

    vector<char> postOrder = {'2' ,'4' ,'3' ,'6' ,'8' ,'7' ,'5'};
    for (auto it=bt.begin_postorder(); it!=bt.end_postorder(); ++it) {
                CHECK_EQ(*it, postOrder.at(i));
        i++;
    }
}
