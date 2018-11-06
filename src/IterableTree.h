//
// Created by eugene on 11/5/18.
//

#ifndef TREE_ITERATOR_ITERABLE_H
#define TREE_ITERATOR_ITERABLE_H

#include <vector>
#include "TreeUtils.h"

namespace tree_utils {

template<class T>
class IterableTree {

 public:
  virtual std::vector<IterableTree *> get_children() = 0;

  tree_utils::iterator::TreeIterator<T> begin() {
    return tree_utils::iterator::TreeIterator<T>(this);
  }

};

}

#endif //TREE_ITERATOR_ITERABLE_H
