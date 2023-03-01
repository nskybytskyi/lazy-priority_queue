#include <functional>
#include <queue>
#include <tuple>
#include <vector>

template <class T, class Container = std::vector<T>,
          class Compare = std::less<typename Container::value_type>>
class lazy_priority_queue {
 public:
  using value_type = typename Container::value_type;
  using const_reference = typename Container::const_reference;

  lazy_priority_queue() : lazy_priority_queue(Compare()) {}
  lazy_priority_queue(const Compare& compare)
      : insert_(compare), remove_(compare) {}

  const_reference top() const {
    while (!remove_.empty() && remove_.top() == insert_.top()) {
      remove_.pop();
      insert_.pop();
    }
    return insert_.top();
  }

  bool empty() const { return size() == 0; }

  int size() const {
    return static_cast<int>(insert_.size()) - static_cast<int>(remove_.size());
  }

  void push(const value_type& value) { insert_.push(value); }

  template <class InputIt>
  void push(InputIt first, InputIt last) {
    for (auto it = first; it != last; ++it) {
      push(*it);
    }
  }

  void pop() {
    std::ignore = top();
    insert_.pop();
  }

  void erase(const value_type& value) { remove_.push(value); }

  template <class InputIt>
  void erase(InputIt first, InputIt last) {
    for (auto it = first; it != last; ++it) {
      erase(*it);
    }
  }

 private:
  mutable std::priority_queue<T, Container, Compare> insert_;
  mutable std::priority_queue<T, Container, Compare> remove_;
};