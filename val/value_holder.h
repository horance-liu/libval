#ifndef H6CC30793_5307_45F9_B46E_C973F4D5A0D0
#define H6CC30793_5307_45F9_B46E_C973F4D5A0D0

#include "val/holder.h"

template<typename ValueType>
struct ValueHolder : Holder<ValueType> {
  ValueHolder(const ValueType &value) : held(value) {
  }

private:
  PlaceHolder* clone() const override {
    return new ValueHolder(held);
  }

  const ValueType& getValue() const override {
    return held;
  }

private:
  ValueType held;
};

///////////////////////////////////////////////
template<typename ValueType>
struct UnsignedLongHolder: Holder<ValueType> {
protected:
  union Held {
    unsigned long ul;
    unsigned int ui;
    unsigned short us;
    unsigned char uc;
    Held(const unsigned long value)  : ul(value) {}
    Held(const unsigned int value)   : ui(value) {}
    Held(const unsigned short value) : us(value) {}
    Held(const unsigned char value)  : uc(value) {}
  } held;
  UnsignedLongHolder(const ValueType &value) : held(value) {}
};

///////////////////////////////////////////////
template<>
struct ValueHolder<unsigned long> : UnsignedLongHolder<unsigned long> {
  ValueHolder(unsigned long value) : UnsignedLongHolder<unsigned long>(value) {
  }

private:
  const unsigned long& getValue() const override {
    return held.ul;
  }

  PlaceHolder* clone() const override {
    return new ValueHolder(held.ul);
  }
};

///////////////////////////////////////////////
template<>
struct ValueHolder<unsigned int> : UnsignedLongHolder<unsigned int> {
  ValueHolder(unsigned int value) : UnsignedLongHolder<unsigned int>(value) {
  }

private:
  const unsigned int& getValue() const override {
    return held.ui;
  }

  PlaceHolder* clone() const override {
    return new ValueHolder(held.ui);
  }
};

///////////////////////////////////////////////
template<>
struct ValueHolder<unsigned short> : UnsignedLongHolder<unsigned short> {
  ValueHolder(unsigned short value) : UnsignedLongHolder<unsigned short>(value) {
  }

private:
  const unsigned short& getValue() const override {
    return held.us;
  }

  PlaceHolder* clone() const override {
    return new ValueHolder(held.us);
  }
};

///////////////////////////////////////////////
template<>
struct ValueHolder<unsigned char> : UnsignedLongHolder<unsigned char> {
  ValueHolder(unsigned char value) : UnsignedLongHolder<unsigned char>(value) {
  }

private:
  const unsigned char& getValue() const override {
    return held.uc;
  }

  PlaceHolder* clone() const override {
    return new ValueHolder(held.uc);
  }
};

///////////////////////////////////////////////
template<typename ValueType>
struct SignedLongHolder: Holder<ValueType> {
protected:
  union Held {
    long sl;
    int si;
    short ss;
    char sc;
    Held(const long value)  : sl(value) {}
    Held(const int value)   : si(value) {}
    Held(const short value) : ss(value) {}
    Held(const char value)  : sc(value) {}
  } held;

  SignedLongHolder(const ValueType &value) : held(value) {
  }
};

///////////////////////////////////////////////
template<>
struct ValueHolder<long> : SignedLongHolder<long> {
  ValueHolder(const long &value) : SignedLongHolder<long>(value) {
  }

private:
  const long& getValue() const override {
    return held.sl;
  }

  PlaceHolder* clone() const override {
    return new ValueHolder(held.sl);
  }
};

///////////////////////////////////////////////
template<>
struct ValueHolder<int> : SignedLongHolder<int> {
  ValueHolder(const int &value) : SignedLongHolder<int>(value) {
  }

private:
  const int& getValue() const override{
    return held.si;
  }

  PlaceHolder* clone() const override {
    return new ValueHolder(held.si);
  }
};

///////////////////////////////////////////////
template<>
struct ValueHolder<short> : SignedLongHolder<short> {
  ValueHolder(const short &value) : SignedLongHolder<short>(value) {
  }

private:
  const short& getValue() const override {
    return held.ss;
  }

  PlaceHolder* clone() const override {
    return new ValueHolder(held.ss);
  }
};

///////////////////////////////////////////////
template<>
struct ValueHolder<char> : SignedLongHolder<char> {
  ValueHolder(const char &value) : SignedLongHolder<char>(value) {
  }

private:
  const char& getValue() const override {
    return held.sc;
  }

  PlaceHolder* clone() const override {
    return new ValueHolder(held.sc);
  }
};

#endif /* H6CC30793_5307_45F9_B46E_C973F4D5A0D0 */

