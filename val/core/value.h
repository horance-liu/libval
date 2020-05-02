#ifndef HE1D05BB9_6E41_48E3_92EE_63CA1173D650
#define HE1D05BB9_6E41_48E3_92EE_63CA1173D650

#include "val/core/value_holder.h"
#include <type_traits>
#include <typeinfo>

struct Value {
  Value(Holder* holder = nullptr);
  ~Value();

  Value(const Value&);
  Value& operator=(const Value&);

  Value(Value&&) noexcept;
  Value& operator=(Value&& rhs) noexcept;

  Value& swap(Value&);

  bool empty() const;
  const std::type_info& type() const;

  template <typename T, typename D = typename std::decay<T>::type>
  Value(const T& t)
    : holder(new ValueHolder<T, std::is_enum<D>::value>(t))
  {}

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
  Holder* holder;
};

#endif /* HE1D05BB9_6E41_48E3_92EE_63CA1173D650 */

