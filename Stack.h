#pragma once
#include <cassert>

template <class T>
class Stack {
 public:
  Stack() {
    size = 20;
    topIndex = 0;
    stack = new T[size];
  }

  ~Stack() { delete[] stack; }

  void push(T element) {
    if (topIndex + 1 == size) {
      int new_size = size * 2;
      T* new_stack;
      new_stack = new T[new_size];
      for (int i = 0; i < size; ++i) {
        new_stack[i] = stack[i];
      }
      delete[] stack;
      stack = new_stack;
      size = new_size;
    }
    stack[topIndex++] = element;
  }

  T top() { return stack[topIndex - 1]; }

  T pop() {
    if (topIndex <= 0) {
      throw std::out_of_range("stack is empty");
    } else {
      --topIndex;
    }
  }

  bool empty() { return topIndex == 0 ? true : false; }

  int Size() const { return topIndex; }

  T& operator[](int index) {
    assert((index >= 0 && index < topIndex) && "out of range");
    return stack[index];
  }

  friend bool operator==(Stack<T>& a, Stack<T>& b) {
    if (a.Size() != b.Size()) {
      return false;
    }
    for (int i = 0; i < a.Size(); ++i) {
      if (a[i] != b[i]){
        return false;
	  }
	}
    return true;
  }

  friend bool operator!=(Stack<T>& a, Stack<T>& b) {
    return !(a == b);
  }

   private:
    T* stack;
    int size;
    int topIndex;
  };
