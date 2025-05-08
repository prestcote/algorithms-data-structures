#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <functional>
#include <vector>

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
    node->count += 1;
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

  std::string print(long long number) {
    std::string ans;
    Node* node = &root;
    while (number > 0) {
      for (auto& [c, n] : node->next) {
        if (n.count >= number) {
          ans.push_back(c);
          node = &n;
          if (node->isTerminal) {
            number -= 1;
            if (number == 0) {
              return ans;
            }
          }
          break;
        }
        else {
          number -= n.count;
        }
      }
    }
    return ans;
  }
};

int main() {
  long long n;
  std::cin >> n;
  Trie trie;
  for (size_t i = 0; i < n; ++i) {
    //std::cout << i << "come onn";
    std::string s;
    std::cin >> s;
    if (s[0] >= '0' && s[0] <= '9') {
      long long number = std::stoi(s);
      std::cout << trie.print(number) << '\n';
    }
    else {
      trie.add(s);
    }
  }
  return 0;
}

