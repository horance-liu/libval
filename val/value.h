#ifndef HE1D05BB9_6E41_48E3_92EE_63CA1173D650
#define HE1D05BB9_6E41_48E3_92EE_63CA1173D650

#include "val/value_base.h"
#include "val/value_holder.h"

struct Value : ValueBase {
  Value() = default;

  template<typename T>
  Value(const T& t) : ValueBase(new ValueHolder<T>(t)) {
  }

  Value(const Value &other);

  template<typename T>
  Value& operator=(const T& t) {
    Value(t).swap(*this);
    return *this;
  }

  Value& operator=(const Value &rhs);
};

#endif /* HE1D05BB9_6E41_48E3_92EE_63CA1173D650 */

