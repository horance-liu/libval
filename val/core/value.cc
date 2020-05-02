#include "val/core/value.h"
#include <utility>

Value::Value(Holder* holder) : holder(holder) {
}

Value::~Value() {
  if (holder) {
    delete holder;
  }
}

Value::Value(Value&& rhs) noexcept : holder(rhs.holder) {
  rhs.holder = nullptr;
}

Value& Value::operator=(Value&& rhs) noexcept {
  Value(std::move(rhs)).swap(*this);
  return *this;
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
