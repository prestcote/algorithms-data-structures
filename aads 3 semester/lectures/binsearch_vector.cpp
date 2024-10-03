#include <iostream>
#include <vector>

template<class T>
int bin_first(const std::vector<T>& a, const T& key) {
  int left = -1;
  int right = a.size();
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    if (a[mid] < key) {
      left = mid;
    }
    else {
      right = mid;
    }
  }
  if (right != a.size() && a[right] == key) {
    return right;
  }
  else {
    return -1 - right;
  }
}

template <class T>
int bin_last(const std::vector<T>&, const T& key) {
  int left = -1;
  int right = a.size();
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    if (a[mid] <= key) {
      left = mid;
    }
    else {
      right = mid;
    }
  }
  if (left != -1 && a[left] == key) {
    return right;
  }
  else {
    return -left;
  }
}

int main() {
  return 0;
}
