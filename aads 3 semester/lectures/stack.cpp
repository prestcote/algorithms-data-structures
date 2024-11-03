#include<iostream>
#include<stack>
#include <algorithm>

// https://informatics.msk.ru/mod/statements/view.php?chapterid=756#1

template<typename T>
class extended_stack {
private:
  std::stack<std::pair<T, T>> st;

public:

  T top() {
    return st.top().first;
  }

  T max() {
    return st.top().second;
  }

  T min() {
    return st.top().second;
  }

  void pop() {
    st.pop();
  }

  void push(T value) {
    if (st.empty()) {
      st.push({ value, value });
    }
    else {
      st.push({ value, std::min(value, st.top().second) });
   }
  }

  bool empty() {
    return st.empty();
  }

};

template<typename T>
class extended_queue {
private:
  extended_stack<T> left;
  extended_stack<T> right;

  void relocate() {
    while (!right.empty()) {
      left.push(right.top());
      right.pop();
    }
  }

public:

  void insert(T value) {
    right.push(value);
  }

  T first() {
    if (left.empty()) relocate();
    return left.top();
  }


  T max() {
    if (left.empty() || right.empty()) {
      relocate();
      return left.max();
    }
    else {
      return std::max(left.max(), right.max());
    }
  }


  bool empty() {
    return left.empty() && right.empty();
  }

};


int main() {
  int n = 0;
  int k = 0;
  int el = 0;
  std::cin >> n >> k;
  extended_stack<int> st;
  for (int i = 0; i < k; i++) {
    std::cin >> el;
    st.push(el);
  }
  for (int i = k; i < n; i++) {
    std::cout << st.min() << ' ';
    st.pop();
    std::cin >> el;
    st.push(el);
  }


  return 0;
}
