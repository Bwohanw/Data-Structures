#include "List.h"


template <typename T>
List<T>::ListNode::ListNode(): data(T()), next(NULL), prev(NULL) {
}

template <typename T>
List<T>::ListNode::ListNode(const T& data) : data(data), next(NULL), prev(NULL) {
}

