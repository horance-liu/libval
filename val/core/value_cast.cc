#include "val/core/value_cast.h"
#include <limits>

///////////////////////////////////////////////////////
template <typename ValueType>
ValueType* type_value_cast(Value* op) {
  return 0;
}

///////////////////////////////////////////////////////
template <typename Unsigned, typename Signed, typename BaseType>
Unsigned* unsigned_type_value_cast(Value* op) {
  Unsigned *p = 0;
  if ((p = safe_value_cast<Unsigned>(op)) ||
      (p = (Unsigned*) type_value_cast<BaseType>(op))) {
    return p;
  }

  Signed* ps = 0;
  if ((ps = safe_value_cast<Signed>(op)) && (*ps) > 0) {
    return (Unsigned*) ps;
  }

  return 0;
}

///////////////////////////////////////////////////////
template <typename Signed, typename BaseType>
Signed* signed_type_value_cast(Value* op) {
  Signed *p = 0;

  (p = safe_value_cast<Signed>(op)) ||
  (p = (Signed*) type_value_cast<BaseType>(op));

  return p;
}

///////////////////////////////////////////////////////
template <>
char* type_value_cast<char>(Value* op) {
  return signed_type_value_cast<char, void>(op);
}

///////////////////////////////////////////////////////
template <>
short* type_value_cast<short>(Value* op) {
  return signed_type_value_cast<short, char>(op);
}

///////////////////////////////////////////////////////
template <>
int* type_value_cast<int>(Value* op) {
  return signed_type_value_cast<int, short>(op);
}

///////////////////////////////////////////////////////
template <>
long* type_value_cast<long>(Value* op) {
  return signed_type_value_cast<long, int>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned char* type_value_cast<unsigned char>(Value* op) {
  return unsigned_type_value_cast<unsigned char, char, void>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned short* type_value_cast<unsigned short>(Value* op) {
  return unsigned_type_value_cast<unsigned short, short, unsigned char>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned int* type_value_cast<unsigned int>(Value* op) {
  return unsigned_type_value_cast<unsigned int, int, unsigned short>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned long* type_value_cast<unsigned long>(Value* op) {
  return unsigned_type_value_cast<unsigned long, long, unsigned int>(op);
}

///////////////////////////////////////////////////////
template <typename T>
T* scoped_value_cast(Value* op) {
  if (auto v = type_value_cast<T>(op)) {
    return v;
  }

  if (auto v = type_value_cast<unsigned long>(op)) {
    if (*v <= (unsigned long) std::numeric_limits<T>::max()) {
      return (T*) v;
    }
  }

  if (auto v = type_value_cast<long>(op)) {
    if (*v <= (long) std::numeric_limits<T>::max() &&
        *v >= (long) std::numeric_limits<T>::min()) {
      return (T*) v;
    }
  }

  return nullptr;
}

///////////////////////////////////////////////////////
template <>
char* value_cast<char>(Value* op) {
  return scoped_value_cast<char>(op);
}

///////////////////////////////////////////////////////
template <>
short* value_cast<short>(Value* op) {
  return scoped_value_cast<short>(op);
}

///////////////////////////////////////////////////////
template <>
int* value_cast<int>(Value* op) {
  return scoped_value_cast<int>(op);
}

///////////////////////////////////////////////////////
template <>
long* value_cast<long>(Value* op) {
  return scoped_value_cast<long>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned char* value_cast<unsigned char>(Value* op) {
  return scoped_value_cast<unsigned char>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned short* value_cast<unsigned short>(Value* op) {
  return scoped_value_cast<unsigned short>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned int* value_cast<unsigned int>(Value* op) {
  return scoped_value_cast<unsigned int>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned long* value_cast<unsigned long>(Value* op) {
  return scoped_value_cast<unsigned long>(op);
}
