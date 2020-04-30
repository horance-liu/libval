#include "val/value.h"

Value::Value(const Value & other)
   : ValueBase(other.getContent() ? other.getContent()->clone() : 0)
{
}

Value& Value::operator=(const Value & rhs)
{
   Value(rhs).swap(*this);
   return *this;
}
