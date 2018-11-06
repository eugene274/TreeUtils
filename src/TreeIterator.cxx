//
// Created by eugene on 11/5/18.
//

#include "TreeIterator.h"


bool tree_utils::iterator::TreeIterator::has_next() {
  if (_stackCurrentIterator != _stack.end()) {
    return true;
  } else if (_stackParentIterator != _stack.end()) {
    append_children();
    return has_next();
  } else {
    return false;
  }
}

tree_utils::IterableTree *tree_utils::iterator::TreeIterator::next() {
  if (_stackCurrentIterator != _stack.end()) {
    return *_stackCurrentIterator++;
  } else if (_stackParentIterator != _stack.end()) {
    append_children();
    return next();
  } else {
    return nullptr;
  }
}

void tree_utils::iterator::TreeIterator::append_children() {
  auto next_children = (*_stackParentIterator)->get_children();

  long cur_position = std::distance(_stack.begin(), _stackCurrentIterator);
  long parent_position = std::distance(_stack.begin(), _stackParentIterator);
  std::copy(next_children.begin(), next_children.end(), std::back_inserter(_stack));

  _stackCurrentIterator = _stack.begin() + cur_position;
  _stackParentIterator = _stack.begin() + parent_position;
  _stackParentIterator++;
}

tree_utils::iterator::TreeIterator::TreeIterator(tree_utils::IterableTree *_root) : _root(_root) {
  _stack.push_back(_root);
  _stackCurrentIterator = _stack.begin();
  _stackParentIterator = _stack.begin();
}

tree_utils::iterator::TreeIterator tree_utils::iterator::TreeIterator::operator++() {
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

tree_utils::IterableTree *tree_utils::iterator::TreeIterator::operator*() {
  return *_stackCurrentIterator;
}
