#include <iostream>

#include <unordered_map>

// #include "units/distance.hpp"

struct Data
{
  int counter;

  explicit Data(const int counter = 0) : counter(counter) {}

  // Data(const Data &) = delete;

  Data &operator=(const Data &) = delete;
};

int main(int argc, const char **argv)
{
  // toolbox::units::Distance<int> a(1);
  // std::cout << a.Get() << std::endl;

  std::unordered_map<void *, Data> m;

  void *address = reinterpret_cast<void *>(1ul);

  auto result = m.emplace(address, 13);
  auto data = &(result.first->second);

  ++m[address].counter;

  m.insert(std::make_pair(address, 42));

  return 0;
}