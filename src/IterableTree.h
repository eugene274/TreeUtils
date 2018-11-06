//
// Created by eugene on 11/5/18.
//

#ifndef TREE_ITERATOR_ITERABLE_H
#define TREE_ITERATOR_ITERABLE_H

#include <vector>

namespace tree_utils {

class IterableTree {

 public:
  virtual std::vector <tree_utils::IterableTree *> get_children() = 0;
};

}

#endif //TREE_ITERATOR_ITERABLE_H
