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

template <typename T>
struct SignedHolder : BaseHolder<T> {
  SignedHolder(T value) {
    held.sl = value;
  } 

protected:    
  union Held {
    long  sl;
    int   si;
    short ss;
    char  ch;
  } held;
};

template<>
struct ValueHolder<long> : SignedHolder<long> {
  using SignedHolder<long>::SignedHolder;
private:
  BaseHolder* clone() const override {
    return new ValueHolder(held.sl);
  }
  const long& getValue() const override {
    return held.sl;
  }
};

template<>
struct ValueHolder<int> : SignedHolder<int> {
  using SignedHolder<int>::SignedHolder;
private:
  BaseHolder* clone() const override {
    return new ValueHolder(held.si);
  }
  const int& getValue() const override {
    return held.si;
  }
};

template<>
struct ValueHolder<short> : SignedHolder<short> {
  using SignedHolder<short>::SignedHolder;
private:
  BaseHolder* clone() const override {
    return new ValueHolder(held.ss);
  }
  const short& getValue() const override {
    return held.ss;
  }
};

template<>
struct ValueHolder<char> : SignedHolder<char> {
  using SignedHolder<char>::SignedHolder;
private:
  BaseHolder* clone() const override {
    return new ValueHolder(held.ch);
  }
  const char& getValue() const override {
    return held.ch;
  }
};

template <typename T>
struct UnsignedHolder : BaseHolder<T> {
  UnsignedHolder(T value) {
    held.ul = value;
  } 

protected:    
  union Held {
    unsigned long  ul;
    unsigned int   ui;
    unsigned short us;
    unsigned char  uc;
  } held;
};

template<>
struct ValueHolder<unsigned long> : UnsignedHolder<unsigned long> {
  using UnsignedHolder<unsigned long>::UnsignedHolder;
private:
  BaseHolder* clone() const override {
    return new ValueHolder(held.ul);
  }
  const unsigned long& getValue() const override {
    return held.ul;
  }
};

template<>
struct ValueHolder<unsigned int> : UnsignedHolder<unsigned int> {
  using UnsignedHolder<unsigned int>::UnsignedHolder;
private:
  BaseHolder* clone() const override {
    return new ValueHolder(held.ui);
  }
  const unsigned int& getValue() const override {
    return held.ui;
  }
};

template<>
struct ValueHolder<unsigned short> : UnsignedHolder<unsigned short> {
  using UnsignedHolder<unsigned short>::UnsignedHolder;
private:
  BaseHolder* clone() const override {
    return new ValueHolder(held.us);
  }
  const unsigned short& getValue() const override {
    return held.us;
  }
};

template<>
struct ValueHolder<unsigned char> : UnsignedHolder<unsigned char> {
  using UnsignedHolder<unsigned char>::UnsignedHolder;
private:
  BaseHolder* clone() const override {
    return new ValueHolder(held.uc);
  }
  const unsigned char& getValue() const override {
    return held.uc;
  }
};

#endif /* H6CC30793_5307_45F9_B46E_C973F4D5A0D0 */

