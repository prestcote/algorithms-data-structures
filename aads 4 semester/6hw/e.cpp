#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>

class Trie {
private:
  struct Node {
    std::unordered_map<char, Node*> next;
    std::unordered_map<char, Node*> autLink;
    Node* suffixLink = nullptr;
    Node* terminalLink = nullptr;
    int id = 0;
    std::vector<int> terminalIndex;
  } root;
  int count = 0;
  std::vector<Node*> nodes;
  std::vector<int> terminalCounts;

public:

  Trie() {
    nodes.push_back(&root);
  }

  void add(const std::string& s) {
    Node* node = &root;
    for (char c : s) {
      if (!node->next.count(c)) {
        node->next[c] = new Node();
        node->next[c]->id = nodes.size();
        nodes.push_back(node->next[c]);
      }
      node = node->next[c];
    }
    node->terminalIndex.push_back(count++);
  }
  void build() {
    std::queue<Node*> q;
    root.suffixLink = &root;
    for (char c = 'a'; c <= 'z'; ++c) {
      if (root.next.count(c)) {
        root.autLink[c] = root.next[c];
        root.next[c]->suffixLink = &root;
        q.push(root.next[c]);
      }
      else {
        root.autLink[c] = &root;
      }
    }
    while (!q.empty()) {
      Node* node = q.front();
      q.pop();
      for (auto& [c, child] : node->next) {
        Node* f = node->suffixLink;
        while (!f->autLink.count(c)) {
          f = f->suffixLink;
        }
        child->suffixLink = f->autLink[c];
        q.push(child);
      }
      for (char c = 'a'; c <= 'z'; ++c) {
        if (node->next.count(c)) {
          node->autLink[c] = node->next[c];
        }
        else {
          node->autLink[c] = node->suffixLink->autLink[c];
        }
      }
      if (!node->suffixLink->terminalIndex.empty()) {
        node->terminalLink = node->suffixLink;
      }
      else {
        node->terminalLink = node->suffixLink->terminalLink;
      }
    }
    terminalCounts.resize(nodes.size(), 0);
    terminal();
  }

  void terminal() {
    std::queue<Node*> q;
    q.push(&root);
    while (!q.empty()) {
      Node* node = q.front();
      q.pop();
      terminalCounts[node->id] = node->terminalIndex.size();
      if (node->terminalLink) {
        terminalCounts[node->id] += terminalCounts[node->terminalLink->id];
      }
      for (auto& [_, child] : node->next) {
        q.push(child);
      }
    }
  }

  long long dfs(int v, Node* s, const std::vector<std::map<char, int>>& tree) {
    long long result = terminalCounts[s->id];
    for (const auto& [ch, to] : tree[v]) {
      Node* ns = s->autLink[ch];
      result += dfs(to, ns, tree);
    }
    return result;
  }

  long long check(const std::vector<std::map<char, int>>& tree) {
    return dfs(0, &root, tree);
  }
};

int main() {
  int n;
  std::cin >> n;
  std::vector<std::map<char, int>> tree(n);
  int k = 0;
  int a = 0;
  char b;
  for (int i = 0; i < n; ++i) {
    std::cin >> k;
    for (int j = 0; j < k; ++j) {
      std::cin >> a >> b;
      a--;
      tree[i][b] = a;
    }
  }
  int m = 0;
  std::cin >> m;
  std::string s;
  Trie trie;
  for (int i = 0; i < m; ++i) {
    std::cin >> s;
    trie.add(s);
  }
  trie.build();
  std::cout << trie.check(tree);
  return 0;
}
