#include "val/value_base.h"
#include "val/holder.h"

ValueBase::ValueBase(PlaceHolder* holder) : holder(holder) {
}

ValueBase::~ValueBase() {
  delete holder;
}

bool ValueBase::empty() const {
  return !holder;
}

const std::type_info& ValueBase::type() const {
  return holder ? holder->type() : typeid(void);
}

ValueBase& ValueBase::swap(ValueBase &rhs) {
  auto temp = holder;
  holder = rhs.holder;
  rhs.holder = temp;
  return *this;
}

PlaceHolder* ValueBase::getContent() const {
  return holder;
}

