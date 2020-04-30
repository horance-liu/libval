#include "val/value_cast.h"
#include <limits>
#include <type_traits>

///////////////////////////////////////////////////////
template <typename ValueType>
ValueType* type_value_cast(ValueBase* op)
{
   return 0;
}

///////////////////////////////////////////////////////
template <typename Unsigned, typename Signed, typename BaseType>
Unsigned* unsigned_type_value_cast(ValueBase* op)
{
   Unsigned *p = 0;
   if((p = __value_cast<Unsigned>(op)) ||
      (p = (Unsigned*)type_value_cast<BaseType>(op))
   )
   {
      return p;
   }

   Signed* ps = 0;
   if((ps = __value_cast<Signed>(op)) && (*ps) > 0)
   {
      return (Unsigned*)ps;
   }

   return 0;
}

///////////////////////////////////////////////////////
template <typename Signed, typename BaseType >
Signed* signed_type_value_cast(ValueBase* op)
{
   Signed *p = 0;

   (p = __value_cast<Signed>(op)) ||
   (p = (Signed*)type_value_cast<BaseType>(op));

   return p;
}

///////////////////////////////////////////////////////
template <>
char* type_value_cast<char>(ValueBase* op)
{
   return signed_type_value_cast<char, void>(op);
}

///////////////////////////////////////////////////////
template <>
short* type_value_cast<short>(ValueBase* op)
{
   return signed_type_value_cast<short, char>(op);
}

///////////////////////////////////////////////////////
template <>
int* type_value_cast<int>(ValueBase* op)
{
   return signed_type_value_cast<int, short>(op);
}

///////////////////////////////////////////////////////
template <>
long* type_value_cast<long>(ValueBase* op)
{
   return signed_type_value_cast<long, int>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned char* type_value_cast<unsigned char>(ValueBase* op)
{
   return unsigned_type_value_cast<unsigned char, char, void>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned short* type_value_cast<unsigned short>(ValueBase* op)
{
   return unsigned_type_value_cast<unsigned short, short, unsigned char>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned int* type_value_cast<unsigned int>(ValueBase* op)
{
   return unsigned_type_value_cast<unsigned int, int, unsigned short>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned long* type_value_cast<unsigned long>(ValueBase* op)
{
   return unsigned_type_value_cast<unsigned long, long, unsigned int>(op);
}

///////////////////////////////////////////////////////
template <typename ValueType>
ValueType* scope_check_value_cast(ValueBase* op)
{
   ValueType* v = type_value_cast<ValueType>(op);
   if(v != 0)
   {
      return v;
   }

   unsigned long* ul = type_value_cast<unsigned long>(op);
   if(ul  && ((*ul) <= (unsigned long)std::numeric_limits<ValueType>::max()))
   {
      return (ValueType*)ul;
   }

   long* l = type_value_cast<long>(op);
   if(l  && (((*l) <= (long)std::numeric_limits<ValueType>::max()) && 
              (*l) >= (long)std::numeric_limits<ValueType>::min()))
   {
      return (ValueType*)l;
   }

   return 0;
}

///////////////////////////////////////////////////////
template <>
char* value_cast<char>(ValueBase* op)
{
   return scope_check_value_cast<char>(op);
}

///////////////////////////////////////////////////////
template <>
short* value_cast<short>(ValueBase* op)
{
   return scope_check_value_cast<short>(op);
}

///////////////////////////////////////////////////////
template <>
int* value_cast<int>(ValueBase* op)
{
   return scope_check_value_cast<int>(op);
}

///////////////////////////////////////////////////////
template <>
long* value_cast<long>(ValueBase* op)
{
   return scope_check_value_cast<long>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned char* value_cast<unsigned char>(ValueBase* op)
{
   return scope_check_value_cast<unsigned char>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned short* value_cast<unsigned short>(ValueBase* op)
{
   return scope_check_value_cast<unsigned short>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned int* value_cast<unsigned int>(ValueBase* op)
{
   return scope_check_value_cast<unsigned int>(op);
}

///////////////////////////////////////////////////////
template <>
unsigned long* value_cast<unsigned long>(ValueBase* op)
{
   return scope_check_value_cast<unsigned long>(op);
}
