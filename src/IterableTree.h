//
// Created by eugene on 11/5/18.
//

#ifndef TREE_ITERATOR_ITERABLE_H
#define TREE_ITERATOR_ITERABLE_H

#include <vector>
#include "TreeUtils.h"
#include "TreeIterator.h"

namespace tree_utils {

template<class T>
class IterableTree {

 public:
  typedef it::TreeIterator<T> iterator;

  tree_utils::it::TreeIterator<T> begin() {
    return iterator(this);
  }

  std::vector<IterableTree *> get_children() {
    return children;
  }

  void add_child(IterableTree<T> *child) {
    children.push_back(child);
  }

 protected:

 private:
  typename iterator::TreeStack children;

};

}

#endif //TREE_ITERATOR_ITERABLE_H
