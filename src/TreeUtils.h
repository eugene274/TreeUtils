//
// Created by eugene on 11/5/18.
//

#ifndef TREE_ITERATOR_TREETOOLS_H
#define TREE_ITERATOR_TREETOOLS_H

#include <vector>
#include "IterableTree.h"

namespace tree_utils {


typedef std::vector <tree_utils::IterableTree *> TreeStack;
typedef TreeStack::iterator TreeStackIterator;

class IterableTree;

namespace iterator {
 class TreeIterator;
}


}

#endif //TREE_ITERATOR_TREETOOLS_H
