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

  TEST("char") {
    Value a((char) 2);
    ASSERT_TRUE(value_castable<char>(a));
    ASSERT_EQ(2, value_cast<char>(a));
  }

  TEST("short") {
    Value a((short) 2);
    ASSERT_TRUE(value_castable<short>(a));
    ASSERT_EQ(2, value_cast<short>(a));
  }

  TEST("int") {
    Value a(2);
    ASSERT_TRUE(value_castable<int>(a));
    ASSERT_EQ(2, value_cast<int>(a));
  }

  TEST("long") {
    Value a((long) 2);
    ASSERT_TRUE(value_castable<long>(a));
    ASSERT_EQ(2, value_cast<long>(a));
  }

  TEST("uchar") {
    Value a((unsigned char) 2);
    ASSERT_TRUE(value_castable<unsigned char>(a));
    ASSERT_EQ(2, value_cast<unsigned char>(a));
  }

  TEST("ushort") {
    Value a((unsigned short) 2);
    ASSERT_TRUE(value_castable<unsigned short>(a));
    ASSERT_EQ(2, value_cast<unsigned short>(a));
  }

  TEST("uint") {
    Value a((unsigned int) 2);
    ASSERT_TRUE(value_castable<unsigned int>(a));
    ASSERT_EQ(2, value_cast<unsigned int>(a));
  }

  TEST("ulong") {
    Value a((unsigned long) 2);
    ASSERT_TRUE(value_castable<unsigned long>(a));
    ASSERT_EQ(2, value_cast<unsigned long>(a));
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
    Value a(65535);

    ASSERT_TRUE(value_castable<unsigned short>(a));
    ASSERT_EQ(65535, value_cast<unsigned short>(a));
  }

  TEST("int(max_ushort + 1) -> ushort: overflow") {
    Value a(65536);

    ASSERT_TRUE(!value_castable<unsigned short>(a));
  }

  TEST("ushort -> uint") {
    Value a((unsigned short) 15);

    //ASSERT_TRUE(value_castable<unsigned int>(a));
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

  // TEST("signed char -> ulong") {
  //   Value a((signed char) 2);

  //   ASSERT_TRUE(value_castable<unsigned long>(a));
  //   ASSERT_EQ(2, value_cast<unsigned long>(a));
  // }

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

  // TEST("signed char -> long") {
  //   ASSERT_TRUE(typeid(unsigned char) == typeid(char));
  //   ASSERT_TRUE(typeid(signed char) == typeid(char));


  //   Value a((signed char) 2);

  //   ASSERT_TRUE(value_castable<long>(a));
  //   ASSERT_EQ(2, value_cast<long>(a));
  // }

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
    ASSERT_EQ(32767, value_cast<short>(a));
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

