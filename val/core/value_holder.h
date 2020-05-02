#ifndef H6CC30793_5307_45F9_B46E_C973F4D5A0D0
#define H6CC30793_5307_45F9_B46E_C973F4D5A0D0

#include "val/core/base_holder.h"

template<typename T>
struct ValueHolder : BaseHolder<T> {
  ValueHolder(const T& value) : held(value) {
  }

private:
  Holder* clone() const override {
    return new ValueHolder(held);
  }

  const T& getValue() const override {
    return held;
  }

private:
  T held;
};

///////////////////////////////////////////////
#define DECL_INTEGER_HOLDER(sign)       \
template<typename T>                   \
struct sign##_holder : BaseHolder<T> {  \
  sign##_holder(T value) {               \
    held.sign##_long = value;            \
  }                                      \
protected:                              \
  union Held {                          \
    sign long  sign##_long;             \
    sign int   sign##_int;              \
    sign short sign##_short;            \
    sign char  sign##_char;             \
  } held;                                \
};

#define DEF_INTEGER_HOLDER(sign, type)                      \
template<>                                                  \
struct ValueHolder<sign type> : sign##_holder<sign type> {  \
  using sign##_holder<sign type>::sign##_holder;            \
private:                                                    \
  BaseHolder* clone() const override {                      \
    return new ValueHolder(held.sign##_##type);             \
  }                                                          \
  const sign type& getValue() const override {              \
    return held.sign##_##type;                              \
  }                                                          \
};

DECL_INTEGER_HOLDER(signed)
DEF_INTEGER_HOLDER(signed, long)
DEF_INTEGER_HOLDER(signed, int)
DEF_INTEGER_HOLDER(signed, short)
DEF_INTEGER_HOLDER(signed, char)

DECL_INTEGER_HOLDER(unsigned)
DEF_INTEGER_HOLDER(unsigned, long)
DEF_INTEGER_HOLDER(unsigned, int)
DEF_INTEGER_HOLDER(unsigned, short)
DEF_INTEGER_HOLDER(unsigned, char)

#endif /* H6CC30793_5307_45F9_B46E_C973F4D5A0D0 */

