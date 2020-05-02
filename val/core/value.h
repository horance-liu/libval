#ifndef HE1D05BB9_6E41_48E3_92EE_63CA1173D650
#define HE1D05BB9_6E41_48E3_92EE_63CA1173D650

#include "val/core/value_holder.h"

struct Value {
  Value() = default;
  ~Value();

  Value(const Value&);
  Value& operator=(const Value&);

  Value& swap(Value&);

  bool empty() const;
  const std::type_info& type() const;

  template <typename T>
  Value(const T& t) : holder(new ValueHolder<T>(t)) {
  }

  template <typename T>
  Value& operator=(const T& t) {
    Value(t).swap(*this);
    return *this;
  }

  template<typename T>
  T* cast() {
    if (type() != typeid(T)) {
      return nullptr;
    }

    auto p = dynamic_cast<BaseHolder<T>*>(holder);
    return p ? &const_cast<T&>(p->getValue()) : nullptr;
  }

private:
  Holder* holder = nullptr;
};

#endif /* HE1D05BB9_6E41_48E3_92EE_63CA1173D650 */

