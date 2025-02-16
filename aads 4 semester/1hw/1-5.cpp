#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SegmentTree {
  struct Node {
    int minVal, maxVal;
  };

  vector<Node> tree;
  int n;

  SegmentTree(const vector<int>& arr) {
    n = arr.size();
    tree.resize(4 * n);
    build(arr, 0, 0, n - 1);
  }

  void build(const vector<int>& arr, int node, int start, int end) {
    if (start == end) {
      tree[node] = { arr[start], arr[start] };
    }
    else {
      int mid = (start + end) / 2;
      build(arr, 2 * node + 1, start, mid);
      build(arr, 2 * node + 2, mid + 1, end);
      tree[node].minVal = min(tree[2 * node + 1].minVal, tree[2 * node + 2].minVal);
      tree[node].maxVal = max(tree[2 * node + 1].maxVal, tree[2 * node + 2].maxVal);
    }
  }

  void update(int node, int start, int end, int idx, int value) {
    if (start == end) {
      tree[node] = { value, value };
    }
    else {
      int mid = (start + end) / 2;
      if (idx <= mid)
        update(2 * node + 1, start, mid, idx, value);
      else
        update(2 * node + 2, mid + 1, end, idx, value);

      tree[node].minVal = min(tree[2 * node + 1].minVal, tree[2 * node + 2].minVal);
      tree[node].maxVal = max(tree[2 * node + 1].maxVal, tree[2 * node + 2].maxVal);
    }
  }

  Node query(int node, int start, int end, int l, int r) {
    if (r < start || l > end) return { INT_MAX, INT_MIN }; // Вне диапазона
    if (l <= start && end <= r) return tree[node]; // Полностью в диапазоне

    int mid = (start + end) / 2;
    Node leftResult = query(2 * node + 1, start, mid, l, r);
    Node rightResult = query(2 * node + 2, mid + 1, end, l, r);
    return { min(leftResult.minVal, rightResult.minVal), max(leftResult.maxVal, rightResult.maxVal) };
  }

  void update(int idx, int value) {
    update(0, 0, n - 1, idx, value);
  }

  int getDifference(int l, int r) {
    Node result = query(0, 0, n - 1, l, r);
    std::cout << '\n' << result.maxVal << ' ' << result.minVal << '\n';
    return result.maxVal - result.minVal;
  }
};

vector<int> generateArray(int size) {
  vector<int> arr(size);
  for (int i = 1; i <= size; i++) {
    arr[i - 1] = (i * i % 12345) + (i * i * i % 23456);
  }
  return arr;
}

int main() {
  int n = 100001; // Размер массива
  vector<int> arr = generateArray(n);

  SegmentTree segTree(arr);

  // Примеры запросов:
  cout <<  segTree.getDifference(1, 2) << endl;

  segTree.update(2, -100); // Меняем a[20] на 50000

  cout << segTree.getDifference(2, 3) << endl;

  return 0;
}
