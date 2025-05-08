#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
#include <set>
#include <queue>

class Trie {
private:
  struct Node {
    std::vector<int> terminalIndex;
    std::unordered_map<char, Node*> next;
    Node* suffixLink = nullptr;
    Node* terminalLink = nullptr;
    std::unordered_map<char, Node*> autLink;
  } root;

  int count = 0;
  std::set<char> alphabet = {};
public:
  void add(const std::string& s) {
    Node* node = &root;
    for (char c : s) {
      alphabet.insert(c);
      if (!node->next.count(c)) {
        node->next[c] = new Node();
      }
      node = node->next[c];
    }
    node->terminalIndex.push_back(count++);
  }

  void build() {
    std::queue<Node*> q;
    root.suffixLink = &root;
    q.push(&root);

    for (char c = 'a'; c <= 'z'; ++c) {
      if (!root.next.count(c)) {
        root.autLink[c] = &root;
      }
      else {
        root.autLink[c] = root.next[c];
      }
    }

    while (!q.empty()) {
      Node* node = q.front();
      q.pop();
      for (auto& pair : node->next) {
        char c = pair.first;
        Node* to = pair.second;
        to->suffixLink = (node == &root ? &root : node->suffixLink->autLink[c]);
        q.push(to);
      }
      for (char c : alphabet) {
        if (node->next.count(c)) {
          node->autLink[c] = node->next[c];
        }
        else {
          node->autLink[c] = (node == &root ? &root : node->suffixLink->autLink[c]);
        }
      }
      if (!node->suffixLink->terminalIndex.empty()) {
        node->terminalLink = node->suffixLink;
      }
      else {
        node->terminalLink = node->suffixLink->terminalLink;
      }
    }
  }

  std::vector<std::vector<int>> check(const std::string& s) {
    std::vector<std::vector<int>> res(count);
    Node* node = &root;
    for (int i = 0; i < s.size(); ++i) {
      if (!node->autLink.count(s[i])) {
        node->autLink[s[i]] = &root;
      }
      node = node->autLink[s[i]];
      if (!node->terminalIndex.empty() || node->terminalLink) {
        Node* t = (!node->terminalIndex.empty() ? node : node->terminalLink);
        for (; t != nullptr; t = t->terminalLink) {
          for (int index : t->terminalIndex) {
            res[index].push_back(i);
          }
        }
      }
    }
    return res;
  }
};

int main() {
  std::string check;
  std::cin >> check;
  int n;
  std::cin >> n;
  Trie trie;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    trie.add(s);
  }
  trie.build();
  std::vector<std::vector<int>> matches = trie.check(check);
  for (int i = 1; i <= n; ++i) {
    if (!matches[i - 1].empty()) {
      std::cout << "Yes\n";
    }
    else {
      std::cout << "No\n";
    }
    /*
    std::cout << i << ": ";
    for (int m : matches[i-1]) {
        std::cout << m << ' ';
    }
    std::cout << '\n';
    */
  }
  return 0;
}
