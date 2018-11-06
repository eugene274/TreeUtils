//
// Created by eugene on 11/5/18.
//

#ifndef TREE_ITERATOR_TREEITERATOR_H
#define TREE_ITERATOR_TREEITERATOR_H

#include "IterableTree.h"
#include "TreeUtils.h"

namespace tree_utils {

namespace iterator {

class TreeIterator {
 public:
  explicit TreeIterator(IterableTree *_root);

  TreeIterator(const TreeIterator &other) = default;

  bool has_next();

  IterableTree *next();

  TreeIterator operator++();

  IterableTree *operator* ();

 private:

  void append_children();

  tree_utils::IterableTree *_root = nullptr;
  TreeStack _stack;
  TreeStackIterator _stackCurrentIterator;
  TreeStackIterator _stackParentIterator;

};

} // iterator
} // tree_utils

#endif //TREE_ITERATOR_TREEITERATOR_H
