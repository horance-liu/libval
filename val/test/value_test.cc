#include "cctest/cctest.h"
#include "val/val.h"
#include <limits>

using namespace cctest;

FIXTURE(ValueTest) {
  TEST("empty") {
    Value i;

    ASSERT_TRUE(i.empty());
  }

  TEST("not empty") {
    Value i(0);

    ASSERT_TRUE(!i.empty());
  }

  TEST("char -> char") {
    Value a((char) 2);
    ASSERT_TRUE(value_castable<char>(a));
    ASSERT_EQ(2, value_cast<char>(a));
  }

  TEST("schar -> schar") {
    Value a((signed char) 2);
    ASSERT_TRUE(value_castable<signed char>(a));
    ASSERT_EQ(2, value_cast<signed char>(a));
  }

  TEST("uchar -> uchar") {
    Value a((unsigned char) 2);
    ASSERT_TRUE(value_castable<unsigned char>(a));
    ASSERT_EQ(2, value_cast<unsigned char>(a));
  }

  TEST("short -> short") {
    Value a((short) 2);
    ASSERT_TRUE(value_castable<short>(a));
    ASSERT_EQ(2, value_cast<short>(a));
  }

  TEST("int -> int") {
    Value a(2);
    ASSERT_TRUE(value_castable<int>(a));
    ASSERT_EQ(2, value_cast<int>(a));
  }

  TEST("long -> long") {
    Value a((long) 2);
    ASSERT_TRUE(value_castable<long>(a));
    ASSERT_EQ(2, value_cast<long>(a));
  }

  TEST("long literal -> long") {
    Value a(2L);
    ASSERT_TRUE(value_castable<long>(a));
    ASSERT_EQ(2, value_cast<long>(a));
  }

  TEST("uchar -> uchar") {
    Value a((unsigned char) 2);
    ASSERT_TRUE(value_castable<unsigned char>(a));
    ASSERT_EQ(2, value_cast<unsigned char>(a));
  }

  TEST("ushort -> ushort") {
    Value a((unsigned short) 2);
    ASSERT_TRUE(value_castable<unsigned short>(a));
    ASSERT_EQ(2, value_cast<unsigned short>(a));
  }

  TEST("uint -> uint") {
    Value a((unsigned int) 2);
    ASSERT_TRUE(value_castable<unsigned int>(a));
    ASSERT_EQ(2, value_cast<unsigned int>(a));
  }

  TEST("uint -> int") {
    Value a((unsigned int) 2);
    ASSERT_TRUE(value_castable<int>(a));
    ASSERT_EQ(2, value_cast<int>(a));
  }

  TEST("uint -> short") {
    Value a((unsigned int) 2);
    ASSERT_TRUE(value_castable<short>(a));
    ASSERT_EQ(2, value_cast<short>(a));
  }

  TEST("uint -> char") {
    Value a((unsigned int) 2);
    ASSERT_TRUE(value_castable<char>(a));
    ASSERT_EQ(2, value_cast<char>(a));
  }

  TEST("uint -> signed char") {
    Value a((unsigned int) 2);
    ASSERT_TRUE(value_castable<signed char>(a));
    ASSERT_EQ(2, value_cast<signed char>(a));
  }

  TEST("ulong -> ulong") {
    Value a((unsigned long) 2);
    ASSERT_TRUE(value_castable<unsigned long>(a));
    ASSERT_EQ(2, value_cast<unsigned long>(a));
  }

  TEST("ulong literal -> ulong") {
    Value a(2UL);
    ASSERT_TRUE(value_castable<unsigned long>(a));
    ASSERT_EQ(2, value_cast<unsigned long>(a));
  }

  TEST("ulong -> long") {
    Value a((unsigned long) 2);
    ASSERT_TRUE(value_castable<long>(a));
    ASSERT_EQ(2, value_cast<long>(a));
  }

  TEST("ulong -> int") {
    Value a((unsigned long) 2);
    ASSERT_TRUE(value_castable<int>(a));
    ASSERT_EQ(2, value_cast<int>(a));
  }

  TEST("ulong -> short") {
    Value a((unsigned long) 2);
    ASSERT_TRUE(value_castable<short>(a));
    ASSERT_EQ(2, value_cast<short>(a));
  }

  TEST("ulong -> char") {
    Value a((unsigned long) 2);
    ASSERT_TRUE(value_castable<char>(a));
    ASSERT_EQ(2, value_cast<char>(a));
  }

  TEST("ulong -> signed char") {
    Value a((unsigned long) 2);
    //ASSERT_TRUE(value_castable<signed char>(a));
    ASSERT_EQ(2, value_cast<signed char>(a));
  }

  TEST("uchar -> ushort") {
    Value a((unsigned char) 12);

    ASSERT_TRUE(value_castable<unsigned short>(a));
    ASSERT_EQ(12, value_cast<unsigned short>(a));
  }

  TEST("short -> ushort") {
    Value a((short) 5);

    ASSERT_TRUE(value_castable<unsigned short>(a));
    ASSERT_EQ(5, value_cast<unsigned short>(a));
  }

  TEST("char -> ushort") {
    Value a((char) 2);

    ASSERT_TRUE(value_castable<unsigned short>(a));
    ASSERT_EQ(2, value_cast<unsigned short>(a));
  }

  TEST("int(max_ushort) -> ushort") {
    Value a(std::numeric_limits<unsigned short>::max());

    ASSERT_TRUE(value_castable<unsigned short>(a));
    ASSERT_EQ(std::numeric_limits<unsigned short>::max(), value_cast<unsigned short>(a));
  }

  TEST("int(max_ushort + 1) -> ushort: overflow") {
    Value a(std::numeric_limits<unsigned short>::max() + 1);

    ASSERT_TRUE(!value_castable<unsigned short>(a));
  }

  TEST("ushort -> uint") {
    Value a((unsigned short) 15);

    ASSERT_TRUE(value_castable<unsigned int>(a));
    ASSERT_EQ(15, value_cast<unsigned int>(a));
  }

  TEST("uchar -> uint") {
    Value a((unsigned char) 12);

    ASSERT_TRUE(value_castable<unsigned int>(a));
    ASSERT_EQ(12, value_cast<unsigned int>(a));
  }

  TEST("int -> uint") {
    Value a(1);

    ASSERT_TRUE(value_castable<unsigned int>(a));
    ASSERT_EQ(1, value_cast<unsigned int>(a));
  }

  TEST("short -> uint") {
    Value a((short) 5);

    ASSERT_TRUE(value_castable<unsigned int>(a));
    ASSERT_EQ(5, value_cast<unsigned int>(a));
  }

  TEST("char -> uint") {
    Value a((char) 2);

    ASSERT_TRUE(value_castable<unsigned int>(a));
    ASSERT_EQ(2, value_cast<unsigned int>(a));
  }

  TEST("int -> ulong") {
    Value a(1);

    ASSERT_TRUE(value_castable<unsigned long>(a));
    ASSERT_EQ(1, value_cast<unsigned long>(a));
  }

  TEST("short -> ulong") {
    Value a((short) 5);

    ASSERT_TRUE(value_castable<unsigned long>(a));
    ASSERT_EQ(5, value_cast<unsigned long>(a));
  }

  TEST("char -> ulong") {
    Value a((char) 2);

    ASSERT_TRUE(value_castable<unsigned long>(a));
    ASSERT_EQ(2, value_cast<unsigned long>(a));
  }

   TEST("signed char -> ulong") {
     Value a((signed char) 2);

     ASSERT_TRUE(value_castable<unsigned long>(a));
     ASSERT_EQ(2, value_cast<unsigned long>(a));
   }

  TEST("unsigned char -> ulong") {
    Value a((unsigned char) 2);

    ASSERT_TRUE(value_castable<unsigned long>(a));
    ASSERT_EQ(2, value_cast<unsigned long>(a));
  }

  TEST("char -> long") {
    Value a((char) 2);

    ASSERT_TRUE(value_castable<long>(a));
    ASSERT_EQ(2, value_cast<long>(a));
  }

   TEST("signed char -> long") {
     Value a((signed char) 2);

     ASSERT_TRUE(value_castable<long>(a));
     ASSERT_EQ(2, value_cast<long>(a));
   }

  TEST("unsigned char -> long") {
    Value a((unsigned char) 2);

    ASSERT_TRUE(value_castable<long>(a));
    ASSERT_EQ(2, value_cast<long>(a));
  }

  TEST("uchar -> char") {
    Value a((unsigned char) 2);

    ASSERT_TRUE(value_castable<char>(a));
    ASSERT_EQ(2, value_cast<char>(a));
  }

  TEST("int -> ulong") {
    Value a((int) 5);

    ASSERT_TRUE(value_castable<unsigned long>(a));
    ASSERT_EQ(5, value_cast<unsigned long>(a));
  }

  TEST("uchar(max_char) -> char") {
    Value a((unsigned char) std::numeric_limits<char>::max());

    ASSERT_TRUE(value_castable<char>(a));
    ASSERT_EQ(std::numeric_limits<char>::max(), value_cast<char>(a));
  }

  TEST("uchar(max_char + 1) -> char: overflow") {
    Value a((unsigned char) std::numeric_limits<char>::max() + 1);

    ASSERT_TRUE(!value_castable<char>(a));
  }

  TEST("ushort(max_short) -> short") {
    Value a((unsigned short) std::numeric_limits<short>::max());

    ASSERT_TRUE(value_castable<short>(a));
    ASSERT_EQ(std::numeric_limits<short>::max(), value_cast<short>(a));
  }

  TEST("ushort(max_short + 1) -> short: overflow") {
    Value a((unsigned short) std::numeric_limits<short>::max() + 1);

    ASSERT_TRUE(!value_castable<short>(a));
  }

  TEST("uint(int_max) -> int") {
    Value a((unsigned int) std::numeric_limits<int>::max());

    ASSERT_TRUE(value_castable<int>(a));
    ASSERT_EQ(std::numeric_limits<int>::max(), value_cast<int>(a));
  }

  TEST("uint(int_max + 1) -> int") {
    Value a((unsigned int) std::numeric_limits<int>::max() + 1);

    ASSERT_TRUE(!value_castable<int>(a));
  }

  TEST("ulong(long_max) -> long") {
    Value a((unsigned long) std::numeric_limits<long>::max());

    ASSERT_TRUE(value_castable<long>(a));
    ASSERT_EQ(std::numeric_limits<long>::max(), value_cast<long>(a));
  }

  TEST("ulong(long_max + 1) -> long") {
    Value a((unsigned long) std::numeric_limits<long>::max() + 1);

    ASSERT_TRUE(!value_castable<long>(a));
  }

  TEST("ref") {
    const std::string &str = std::string("abcdef");
    Value i(str);
    Value &ref = i;

    const std::string &result = value_cast<const std::string&>(ref);
    ASSERT_EQ(std::string("abcdef"), result);
  }

  enum Enum {
    Enum10 = 10
  };

  TEST("enum") {
    Value e(Enum10);

    ASSERT_EQ(Enum10, value_cast<Enum>(e));
  }

  TEST("long -> enum") {
    Value l((long) 10);

    ASSERT_EQ(Enum10, value_cast<Enum>(l));
  }

  TEST("enum -> long") {
    Value l(Enum10);

    ASSERT_TRUE(value_castable<long>(l));
    ASSERT_EQ(10, value_cast<long>(l));
  }

  TEST("enum -> int") {
    Value l(Enum10);

    ASSERT_TRUE(value_castable<int>(l));
    ASSERT_EQ(10, value_cast<int>(l));
  }

  TEST("enum -> short") {
    Value l(Enum10);

    ASSERT_TRUE(value_castable<short>(l));
    ASSERT_EQ(10, value_cast<short>(l));
  }

  TEST("enum -> char") {
    Value l(Enum10);

    ASSERT_TRUE(value_castable<char>(l));
    ASSERT_EQ(10, value_cast<char>(l));
  }

  TEST("enum -> signed char") {
    Value l(Enum10);

    ASSERT_TRUE(value_castable<signed char>(l));
    ASSERT_EQ(10, value_cast<signed char>(l));
  }

  TEST("enum -> ulong") {
    Value l(Enum10);

    ASSERT_TRUE(value_castable<unsigned long>(l));
    ASSERT_EQ(10, value_cast<unsigned long>(l));
  }

  TEST("enum -> uint") {
    Value l(Enum10);

    ASSERT_TRUE(value_castable<unsigned int>(l));
    ASSERT_EQ(10, value_cast<unsigned int>(l));
  }

  TEST("enum -> ushort") {
    Value l(Enum10);

    ASSERT_TRUE(value_castable<unsigned short>(l));
    ASSERT_EQ(10, value_cast<unsigned short>(l));
  }

  TEST("enum -> uchar") {
    Value l(Enum10);

    ASSERT_TRUE(value_castable<unsigned char>(l));
    ASSERT_EQ(10, value_cast<unsigned char>(l));
  }

  TEST("int -> enum") {
    Value i((int) 10);

    ASSERT_EQ(Enum10, value_cast<Enum>(i));
  }

  TEST("short -> enum") {
    Value s((short) 10);

    ASSERT_EQ(Enum10, value_cast<Enum>(s));
  }

  TEST("char -> enum") {
    Value c((char) 10);

    ASSERT_EQ(Enum10, value_cast<Enum>(c));
  }

  TEST("signed char -> enum") {
    Value c((signed char) 10);

    ASSERT_EQ(Enum10, value_cast<Enum>(c));
  }

  TEST("ulong -> enum") {
    Value l((unsigned long) 10);

    ASSERT_EQ(Enum10, value_cast<Enum>(l));
  }

  TEST("uint -> enum") {
    Value i((unsigned int) 10);

    ASSERT_EQ(Enum10, value_cast<Enum>(i));
  }

  TEST("ushort -> enum") {
    Value s((unsigned short) 10);

    ASSERT_EQ(Enum10, value_cast<Enum>(s));
  }

  TEST("uchar -> enum") {
    Value c((unsigned char) 10);

    ASSERT_EQ(Enum10, value_cast<Enum>(c));
  }

  TEST("value array") {
    Value objects[] = { 1, (const char*) "string", 1.2 };

    ASSERT_EQ(1, value_cast<int>(objects[0]));
    ASSERT_EQ(1, value_cast<unsigned int>(objects[0]));

    ASSERT_EQ((const char* )"string", value_cast<const char*>(objects[1]));
    ASSERT_EQ(1.2, value_cast<double>(objects[2]));
  }
};

