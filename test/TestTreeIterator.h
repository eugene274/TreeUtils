//
// Created by eugene on 11/5/18.
//

#ifndef TREE_ITERATOR_TESTTREEITERATOR_H
#define TREE_ITERATOR_TESTTREEITERATOR_H

#include <gtest/gtest.h>
#include "../src/IterableTree.h"
#include "../src/TreeIterator.h"

namespace {

class BinaryTree : public tree_utils::IterableTree<BinaryTree> {

 public:
  int payload = 0;

  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  std::vector<IterableTree *> get_children() override {
    std::vector<IterableTree *> children;
    if (left != nullptr) children.push_back(left);
    if (right != nullptr) children.push_back(right);
    return children;
  }
};

TEST(TestTreeIterator, HasNext) {
  auto *tree_root = new BinaryTree;
  tree_root->payload = 0;
  auto tree_1 = new BinaryTree;
  tree_1->payload = 1;
  auto tree_1_1 = new BinaryTree;
  tree_1_1->payload = 3;
  auto *tree_2 = new BinaryTree;
  tree_2->payload = 2;

  tree_root->left = tree_1;
  tree_root->right = tree_2;

  tree_1->left = tree_1_1;

  ASSERT_EQ(tree_root->get_children().size(), 2);

  {
    auto tree_iterator = tree_root->begin();
    ASSERT_EQ(tree_iterator.next(), tree_root);
    ASSERT_EQ(tree_iterator.next(), tree_1);
    ASSERT_EQ(tree_iterator.next(), tree_2);
    ASSERT_EQ(tree_iterator.next(), tree_1_1);
    ASSERT_FALSE(tree_iterator.has_next());
  }

  {
    auto tree_iterator = tree_root->begin();
    ASSERT_EQ(*tree_iterator, tree_root);
    ++tree_iterator;
    ASSERT_EQ(*tree_iterator, tree_1);
    ++tree_iterator;
    ASSERT_EQ(*tree_iterator, tree_2);
    ++tree_iterator;
    ASSERT_EQ(*tree_iterator, tree_1_1);
    ++tree_iterator;
    ASSERT_FALSE(tree_iterator.has_next());
  }

  delete tree_1_1;
  delete tree_1;
  delete tree_2;
  delete tree_root;

}

}

#endif //TREE_ITERATOR_TESTTREEITERATOR_H
