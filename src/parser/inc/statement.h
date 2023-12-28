#pragma once
#include <string>

class Statement{
public:
  virtual ~Statement() = default;
  virtual std::string format() const = 0;
};
