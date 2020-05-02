#include "val/core/value.h"

Value::~Value() {
  delete holder;
}

bool Value::empty() const {
  return !holder;
}

const std::type_info& Value::type() const {
  return holder ? holder->type() : typeid(void);
}

Value& Value::swap(Value& rhs) {
  auto temp = holder;
  holder = rhs.holder;
  rhs.holder = temp;
  return *this;
}

Value::Value(const Value & other)
    : Value(other.holder ? other.holder->clone() : nullptr) {
}

Value& Value::operator=(const Value & rhs) {
  Value(rhs).swap(*this);
  return *this;
}
