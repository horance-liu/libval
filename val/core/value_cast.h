#ifndef H3BB67895_C9E2_416C_9BAC_B6AEB95D8DDB
#define H3BB67895_C9E2_416C_9BAC_B6AEB95D8DDB

#include "val/core/value.h"
#include <type_traits>

template<typename T>
T* safe_value_cast(Value* v) {
  return v != 0 ? v->cast<T>() : nullptr;
}

//////////////////////////////////////////////// /////////////////
template<typename T, bool IsEnum>
struct ValueCast {
  static T* cast(Value* v) {
    return safe_value_cast<T>(v);
  }
};

/////////////////////////////////////////////////////////////////
template<typename T>
struct ValueCast<T, true> {
  static T* cast(Value* v) {
    T *p = nullptr;
    (p = safe_value_cast<T>(v)) ||
    (p = (T*) safe_value_cast<unsigned long>(v))  ||
    (p = (T*) safe_value_cast<unsigned int>(v))   ||
    (p = (T*) safe_value_cast<unsigned short>(v)) ||
    (p = (T*) safe_value_cast<unsigned char>(v))  ||
    (p = (T*) safe_value_cast<long>(v))  ||
    (p = (T*) safe_value_cast<int>(v))   ||
    (p = (T*) safe_value_cast<short>(v)) ||
    (p = (T*) safe_value_cast<char>(v));
    return p;
  }
};

/////////////////////////////////////////////////////////////////
template<typename T>
T* value_cast(Value* v) {
  return ValueCast<T, std::is_enum<T>::value>::cast(v);
}

/////////////////////////////////////////////////////////////////
template<>
char* value_cast<char>(Value* op);

/////////////////////////////////////////////////////////////////
template<>
short* value_cast<short>(Value* op);

/////////////////////////////////////////////////////////////////
template<>
int* value_cast<int>(Value* op);

/////////////////////////////////////////////////////////////////
template<>
long* value_cast<long>(Value* op);

/////////////////////////////////////////////////////////////////
template<>
unsigned char* value_cast<unsigned char>(Value* op);

/////////////////////////////////////////////////////////////////
template<>
unsigned short* value_cast<unsigned short>(Value* op);

/////////////////////////////////////////////////////////////////
template<>
unsigned int* value_cast<unsigned int>(Value* op);

/////////////////////////////////////////////////////////////////
template<>
unsigned long* value_cast<unsigned long>(Value* op);

/////////////////////////////////////////////////////////////////
template<typename T>
const T* value_cast(const Value* v) {
  return value_cast<T>(const_cast<Value*>(v));
}

/////////////////////////////////////////////////////////////////
template<typename T>
T value_cast(const Value& v) {
  return value_cast<T>(const_cast<Value&>(v));
}

/////////////////////////////////////////////////////////////////
template<typename T>
T value_cast(Value& v) {
  auto result = value_cast<typename std::decay<T>::type>(&v);
  return *result;
}

/////////////////////////////////////////////////////////////////
template<typename T>
bool value_castable(const Value& v) {
  return !v.empty() && value_cast<typename std::decay<T>::type>(&v) != nullptr;
}

#endif /* H3BB67895_C9E2_416C_9BAC_B6AEB95D8DDB */

