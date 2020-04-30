#ifndef H3BB67895_C9E2_416C_9BAC_B6AEB95D8DDB
#define H3BB67895_C9E2_416C_9BAC_B6AEB95D8DDB

#include <assert.h>
#include "val/type_traits.h"
#include "val/value_base.h"

template<typename ValueType>
ValueType* __type_value_cast(ValueBase *operand) {
  typedef typename TypeTraits<ValueType>::Type nonref;
  typedef Holder<nonref> holder;

  if (operand->type() != typeid(ValueType)) {
    return nullptr;
  }

  auto p = dynamic_cast<holder*>(operand->getContent());
  return p ? &const_cast<ValueType&>(p->getValue()) : nullptr;
}

template<typename ValueType>
ValueType* __value_cast(ValueBase *operand) {
  return operand != 0 ? __type_value_cast<ValueType>(operand) : nullptr;
}

//////////////////////////////////////////////// /////////////////
template<typename ValueType, bool IsEnum>
struct ValueCast {
  static ValueType* cast(ValueBase *operand) {
    return __value_cast<ValueType>(operand);
  }
};

/////////////////////////////////////////////////////////////////
template<typename ValueType>
struct ValueCast<ValueType, true> {
  static ValueType* cast(ValueBase *operand) {
    ValueType *p = 0;
    (p = __value_cast<ValueType>(operand))
        || (p = (ValueType*) __value_cast<unsigned long>(operand)) || (p =
            (ValueType*) __value_cast<unsigned int>(operand)) || (p =
            (ValueType*) __value_cast<unsigned short>(operand)) || (p =
            (ValueType*) __value_cast<unsigned char>(operand)) || (p =
            (ValueType*) __value_cast<long>(operand)) || (p =
            (ValueType*) __value_cast<int>(operand)) || (p =
            (ValueType*) __value_cast<short>(operand)) || (p =
            (ValueType*) __value_cast<char>(operand));
    return p;
  }
};

/////////////////////////////////////////////////////////////////
template<typename ValueType>
ValueType* value_cast(ValueBase *operand) {
  return ValueCast<ValueType, std::is_enum<ValueType>::value>::cast(operand);
}

/////////////////////////////////////////////////////////////////
template<>
char* value_cast<char>(ValueBase *op);

/////////////////////////////////////////////////////////////////
template<>
short* value_cast<short>(ValueBase *op);

/////////////////////////////////////////////////////////////////
template<>
int* value_cast<int>(ValueBase *op);

/////////////////////////////////////////////////////////////////
template<>
long* value_cast<long>(ValueBase *op);

/////////////////////////////////////////////////////////////////
template<>
unsigned char* value_cast<unsigned char>(ValueBase *op);

/////////////////////////////////////////////////////////////////
template<>
unsigned short* value_cast<unsigned short>(ValueBase *op);

/////////////////////////////////////////////////////////////////
template<>
unsigned int* value_cast<unsigned int>(ValueBase *op);

/////////////////////////////////////////////////////////////////
template<>
unsigned long* value_cast<unsigned long>(ValueBase *op);

/////////////////////////////////////////////////////////////////
template<typename ValueType>
const ValueType* value_cast(const ValueBase *operand) {
  return value_cast<ValueType>(const_cast<ValueBase*>(operand));
}

/////////////////////////////////////////////////////////////////
template<typename ValueType>
ValueType value_cast(const ValueBase &operand) {
  typedef typename TypeTraits<ValueType>::Type nonref;

  const nonref *result = value_cast<nonref>(&operand);
  assert(result != 0);

  return *const_cast<nonref*>(result);
}

/////////////////////////////////////////////////////////////////
template<typename ValueType>
ValueType value_cast(ValueBase &operand) {
  typedef typename TypeTraits<ValueType>::Type nonref;

  nonref *result = value_cast<nonref>(&operand);
  assert(result != 0);

  return *result;
}

/////////////////////////////////////////////////////////////////
template<typename ValueType>
bool value_castable(const ValueBase &val) {
  typedef typename TypeTraits<ValueType>::Type nonref;

  return (!val.empty()) && (value_cast<nonref>(&val) != 0);
}

#endif /* H3BB67895_C9E2_416C_9BAC_B6AEB95D8DDB */

