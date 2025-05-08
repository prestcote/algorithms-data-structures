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

    for (char c = ' '; c <= '~'; ++c) {
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

  bool check(const std::string& s) {
    std::vector<std::vector<int>> res(count);
    Node* node = &root;
    for (int i = 0; i < s.size(); ++i) {
      if (!node->autLink.count(s[i])) {
        node->autLink[s[i]] = &root;
      }
      node = node->autLink[s[i]];
      if (!node->terminalIndex.empty() || node->terminalLink) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  int n;
  std::cin >> n;
  std::cin.ignore();
  Trie trie;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::getline(std::cin, s);
    trie.add(s);
  }
  trie.build();
  std::string check;
  while (std::getline(std::cin, check)) {
    if (trie.check(check)) {
      std::cout << check << '\n';
    }
  }
  return 0;
}
