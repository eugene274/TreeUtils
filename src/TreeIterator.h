//
// Created by eugene on 11/5/18.
//

#ifndef TREE_ITERATOR_TREEITERATOR_H
#define TREE_ITERATOR_TREEITERATOR_H

#include "TreeUtils.h"

namespace tree_utils {

namespace iterator {

template<class T>
class TreeIterator {
 public:
  explicit TreeIterator(IterableTree<T> *_root);

  TreeIterator(const TreeIterator &other) = default;

  bool has_next();

  IterableTree<T> *next();

  TreeIterator operator++();

  IterableTree<T> *operator*();

 private:
  typedef std::vector<tree_utils::IterableTree<T> *> TreeStack;
  typedef typename TreeStack::iterator TreeStackIterator;

  void append_children();

  tree_utils::IterableTree<T> *_root = nullptr;
  TreeStack _stack;
  TreeStackIterator _stackCurrentIterator;
  TreeStackIterator _stackParentIterator;

};


template<class T>
bool tree_utils::iterator::TreeIterator<T>::has_next() {
  if (_stackCurrentIterator != _stack.end()) {
    return true;
  } else if (_stackParentIterator != _stack.end()) {
    append_children();
    return has_next();
  } else {
    return false;
  }
}

template<class T>
tree_utils::IterableTree<T> *tree_utils::iterator::TreeIterator<T>::next() {
  if (_stackCurrentIterator != _stack.end()) {
    return *_stackCurrentIterator++;
  } else if (_stackParentIterator != _stack.end()) {
    append_children();
    return next();
  } else {
    return nullptr;
  }
}

template<class T>
void tree_utils::iterator::TreeIterator<T>::append_children() {
  auto next_children = (*_stackParentIterator)->get_children();

  long cur_position = std::distance(_stack.begin(), _stackCurrentIterator);
  long parent_position = std::distance(_stack.begin(), _stackParentIterator);
  std::copy(next_children.begin(), next_children.end(), std::back_inserter(_stack));

  _stackCurrentIterator = _stack.begin() + cur_position;
  _stackParentIterator = _stack.begin() + parent_position;
  _stackParentIterator++;
}

template<class T>
tree_utils::iterator::TreeIterator<T>::TreeIterator(tree_utils::IterableTree<T> *_root) : _root(_root) {
  _stack.push_back(_root);
  _stackCurrentIterator = _stack.begin();
  _stackParentIterator = _stack.begin();
}

template<class T>
tree_utils::iterator::TreeIterator<T> tree_utils::iterator::TreeIterator<T>::operator++() {
  if (_stackCurrentIterator + 1 != _stack.end()) {
    ++_stackCurrentIterator;
  } else if (_stackParentIterator != _stack.end()) {
    append_children();
    operator++();
  } else {
    ++_stackCurrentIterator;
  }

  return *this;
}

template<class T>
tree_utils::IterableTree<T> *tree_utils::iterator::TreeIterator<T>::operator*() {
  return *_stackCurrentIterator;
}
} // iterator
} // tree_utils

#endif //TREE_ITERATOR_TREEITERATOR_H
