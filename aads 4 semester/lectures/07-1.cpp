#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <functional>

class Trie {
private:
  struct Node {
    long long isTerminal = 0;
    long long count = 0;
    std::map<char, Node> next;
  } root;
public:
  void add(const std::string& s) {
    Node* node = &root;
    for (char c : s) {
      node->count += 1;
      node = &node->next[c];
    }
    node->isTerminal += 1;
  }

  void print() {
    std::string res;
    std::function<void(Node&)> dfs = [&](Node& node) {
      for (auto& [c, n] : node.next) {
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

  std::string find_kth(int& k) {
    std::string result;
    Node* node = &root;
    while (k > 0) {
      for (auto& [c, n] : node->next) {
        if (n.count >= k) {
          result.push_back(c);
          if (n.isTerminal) {
            k -= 1;;
            if (k == 0) {
              return result;
            }
          }
          break;

        }
        else {
          k -= n.count;

        }

      }

    }
    return result;
  }
};

int main() {
  long long n;
  std::cin >> n;
  Trie trie;
  std::vector<int> commands;
  for (size_t i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    if (s[0] >= '0' && s[0] <= '9') {
      long long number = std::stoi(s);
      commands.push_back(number);
    }
    else {
      trie.add(s);
    }
  }
  std::unordered_map<long long, std::string> m = trie.print();
  for (auto& i : commands) {
    std::cout << m[i] << '\n';
  }
}

