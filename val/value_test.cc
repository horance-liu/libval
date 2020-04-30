#include <limits>
#include "cctest/cctest.h"

#include "val/is_ref.h"
#include "val/value.h"
#include "val/value_cast.h"

using namespace cctest;

FIXTURE(TestAny) {
  TEST("empty") {
    Value i;

    ASSERT_TRUE(i.empty());
  }

  TEST("not empty") {
    Value i(0);

    ASSERT_TRUE(!i.empty());
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

    //ASSERT_TRUE(value_castable<unsigned short>(a));
    ASSERT_EQ(65535, value_cast<unsigned short>(a));
  }

//  TEST("ShouldNotCastUnsignedIntExceedingTheLimitationToUnsignedShort") {
//    Value a(65536);
//
//    ASSERT_TRUE(!value_castable<unsigned short>(a));
//  }
//
//
//  TEST("ShouldBeAbleCastUnsignedShortToUnsignedInt") {
//    Value a((unsigned short) 15);
//
//    ASSERT_TRUE(value_castable<unsigned int>(a));
//    ASSERT_EQ(15, value_cast<unsigned int>(a));
//  }
//
//
//  TEST("ShouldBeAbleCastUnsignedCharToUnsignedInt") {
//    Value a((unsigned char) 12);
//
//    ASSERT_TRUE(value_castable<unsigned int>(a));
//    ASSERT_EQ(12, value_cast<unsigned int>(a));
//  }
//
//
//  TEST("ShouldBeAbleCastNonnegtiveIntToUnsignedInt") {
//    Value a(1);
//
//    ASSERT_TRUE(value_castable<unsigned int>(a));
//    ASSERT_EQ(1, value_cast<unsigned int>(a));
//  }
//
//
//  TEST("ShouldBeAbleCastNonnegtiveShortToUnsignedInt") {
//    Value a((short) 5);
//
//    ASSERT_TRUE(value_castable<unsigned int>(a));
//    ASSERT_EQ(5, value_cast<unsigned int>(a));
//  }
//
//
//  TEST("ShouldBeAbleCastNonnegtiveCharToUnsignedInt") {
//    Value a((char) 2);
//
//    ASSERT_TRUE(value_castable<unsigned int>(a));
//    ASSERT_EQ(2, value_cast<unsigned int>(a));
//  }
//
//
//  TEST("ShouldBeAbleCastNonnegtiveIntToUnsignedLong") {
//    Value a(1);
//
//    ASSERT_TRUE(value_castable<unsigned long>(a));
//    ASSERT_EQ(1, value_cast<unsigned long>(a));
//  }
//
//
//  TEST("ShouldBeAbleToCastNonnegtiveShortToUnsignedLong") {
//    Value a((short) 5);
//
//    ASSERT_TRUE(value_castable<unsigned long>(a));
//    ASSERT_EQ(5, value_cast<unsigned long>(a));
//  }
//
//
//  TEST("ShouldBeAbleToCastNonnegtiveCharToUnsignedLong") {
//    Value a((char) 2);
//
//    ASSERT_TRUE(value_castable<unsigned long>(a));
//    ASSERT_EQ(2, value_cast<unsigned long>(a));
//  }
//
//
//  TEST("ShouldBeAbleToCastNonnegtiveIntToUnsignedLong") {
//    Value a((int) 5);
//
//    ASSERT_TRUE(value_castable<unsigned long>(a));
//    ASSERT_EQ(5, value_cast<unsigned long>(a));
//  }
//
//
//  TEST("ShouldBeAbleToCastInScopeUnsignedCharToChar") {
//    Value a((unsigned char) std::numeric_limits<char>::max());
//
//    ASSERT_TRUE(value_castable<char>(a));
//    ASSERT_EQ(std::numeric_limits<char>::max(), value_cast<char>(a));
//  }
//
//
//  TEST("ShouldNotCastInScopeUnsignedCharToChar") {
//    Value a((unsigned char) std::numeric_limits<char>::max() + 1);
//
//    ASSERT_TRUE(!value_castable<char>(a));
//  }
//
//
//  TEST("ShouldBeAbleToCastInScopeUnsignedShortToShort") {
//    Value a((unsigned short) 32767);
//
//    ASSERT_TRUE(value_castable<short>(a));
//    ASSERT_EQ(32767, value_cast<short>(a));
//  }
//
//
//  TEST("ShouldNotCastInScopeUnsignedShortToShort") {
//    Value a((unsigned short) 32768);
//
//    ASSERT_TRUE(!value_castable<short>(a));
//  }
//
//
//  TEST("ShouldBeAbleToCastInScopeUnsignedIntToInt") {
//    Value a((unsigned int) std::numeric_limits<int>::max());
//
//    ASSERT_TRUE(value_castable<int>(a));
//    ASSERT_EQ(std::numeric_limits<int>::max(), value_cast<int>(a));
//  }
//
//
//  TEST("ShouldNotCastInScopeUnsignedIntToInt") {
//    Value a((unsigned int) std::numeric_limits<int>::max() + 1);
//
//    ASSERT_TRUE(!value_castable<int>(a));
//  }
//
//
//  TEST("ShouldBeAbleToCastInScopeUnsignedLongToLong") {
//    Value a((unsigned long) std::numeric_limits<long>::max());
//
//    ASSERT_TRUE(value_castable<long>(a));
//    ASSERT_EQ(std::numeric_limits<long>::max(), value_cast<long>(a));
//  }
//
//
//  TEST("ShouldNotCastInScopeUnsignedLongToLong") {
//    Value a((unsigned long) std::numeric_limits<long>::max() + 1);
//
//    ASSERT_TRUE(!value_castable<long>(a));
//  }
//
//
//  TEST("ShouldBeAbleToAnyCastReferenceCorrectly") {
//    const std::string &str = std::string("abcdef");
//    Value i(str);
//    Value &ref = i;
//
//    const std::string &result = value_cast<const std::string&>(ref);
//    ASSERT_EQ(std::string("abcdef"), result);
//  }
//
//  enum Enum {
//    Enum10 = 10
//  };
//
//
//  TEST("ShouldBeAbleToEnumToSameEnum") {
//    Value e(Enum10);
//
//    ASSERT_EQ(Enum10, value_cast<Enum>(e));
//  }
//
//
//  TEST("ShouldBeAbleToCastLongToEnum") {
//    Value l((long) 10);
//
//    ASSERT_EQ(Enum10, value_cast<Enum>(l));
//  }
//
//
//  TEST("ShouldBeAbleToCastIntToEnum") {
//    Value i((int) 10);
//
//    ASSERT_EQ(Enum10, value_cast<Enum>(i));
//  }
//
//
//  TEST("ShouldBeAbleToCastShortToEnum") {
//    Value s((short) 10);
//
//    ASSERT_EQ(Enum10, value_cast<Enum>(s));
//  }
//
//
//  TEST("ShouldBeAbleToCastCharToEnum") {
//    Value c((char) 10);
//
//    ASSERT_EQ(Enum10, value_cast<Enum>(c));
//  }
//
//
//  TEST("shouldBeAbleToCastUnsignedLongToEnum") {
//    Value l((unsigned long) 10);
//
//    ASSERT_EQ(Enum10, value_cast<Enum>(l));
//  }
//
//
//  TEST("ShouldBeAbleToCastUnsignedIntToEnum") {
//    Value i((unsigned int) 10);
//
//    ASSERT_EQ(Enum10, value_cast<Enum>(i));
//  }
//
//
//  TEST("ShouldBeAbleToCastUnsignedShortToEnum") {
//    Value s((unsigned short) 10);
//
//    ASSERT_EQ(Enum10, value_cast<Enum>(s));
//  }
//
//
//  TEST("ShouldBeAbleToCastUnsignedCharToEnum") {
//    Value c((unsigned char) 10);
//
//    ASSERT_EQ(Enum10, value_cast<Enum>(c));
//  }
//
//  TEST("castable_unsigned_int") {
//    Value ui((unsigned int) 2);
//    ASSERT_TRUE(value_castable<unsigned int>(ui));
//  }
//
//  TEST("define Any array") {
//    Value objects[] = { 1, (const char*) "string", 1.2 };
//
//    ASSERT_EQ(1, value_cast<int>(objects[0]));
//    ASSERT_EQ(1, value_cast<unsigned int>(objects[0]));
//
//    ASSERT_EQ((const char* )"string", value_cast<const char*>(objects[1]));
//    ASSERT_EQ(1.2, value_cast<double>(objects[2]));
//  }
};

