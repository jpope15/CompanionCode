#include <string>

// Copy and swap technique
void func(std::string &str) {
  auto tmp = std::string{str}; // copy
  tmp += f1();                 // Mutate copy, may throw
  tmp += f2();                 // Mutate copy, may throw
  std::swap(tmp, str);         // swap, never throws
}

// Using copy and swap to preserve state of object
class Number;
class Widget {
public:
  Widget(const Number &x, const Number &y) : x_{x}, y_{y} {
    assert(is_valid()); // check class invariant
  }

  void update(const Number &x, const Number &y) {
    assert(x != y && is_valid()); // precondition
    auto x_tmp = x;
    auto y_tmp = y;

    std::swap(x_tmp, x_);
    std::swap(y_tmp, y_);
    assert(is_valid()); // postcondition
  }

private:
  Number x_{};
  Number y_{};

  bool is_valid() const {
    return x_ != y_;
  } // class invariant, x_ and y_ must not be equal
};
