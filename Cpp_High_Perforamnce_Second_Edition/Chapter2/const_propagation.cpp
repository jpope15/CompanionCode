#include <experimental/propagate_const>

class Foo {
public:
  Foo(int *ptr) : ptr_{ptr} {}

  auto set_ptr(int *p) const {
    ptr_ = p; // will not compile
  }

  auto set_val(int v) const {
    val_ = v; // will nto compile
  }

  auto set_ptr_val(int v) const {
    *ptr_ = v; // will not compile, const is propagated. If this was a normal
               // pointer, it would compile.
  }

private:
  std::experimental::propagate_const<int *> ptr_ = nullptr;
  int val_{};
};
