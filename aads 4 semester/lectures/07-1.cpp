#include <iostream>
#include <string>
#include <map>
#include <functional>

class Trie {
private:
  struct Node {
    int isTerminal = 0;
    std::map<char, Node> next;
  } root;
public:
  void add(const std::string& s) {
    Node* node = &root;
    for (char c : s) {
      node = &node->next[c];
    }
    node->isTerminal += 1;
  }

  void print() {
    std::string res;
    std::function<void(Node&)> dfs = [&](Node& node) {
      for (auto& [ c, n ] : node.next) {
        res.push_back(c);
        if (n.isTerminal) {
          std::cout << res << '\n';
        }
        dfs(n);
        res.pop_back();
      }
      };
    dfs(root);
  }
};

int main() {
  int n;
  std::cin >> n;
  Trie trie;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    trie.add(s);
  }
  trie.print();
}
