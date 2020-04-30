#ifndef HDE71C4B3_8353_4752_AADD_B9ADED598A7D
#define HDE71C4B3_8353_4752_AADD_B9ADED598A7D

//////////////////////////////////////////
template<typename T>
struct IsRef {
  static const bool isTrue = false;
  static const bool outBoundable = false;
};

//////////////////////////////////////////
template<typename T>
struct IsRef<T&> {
  static const bool isTrue = true;
  static const bool outBoundable = true;
};

//////////////////////////////////////////
template<typename T>
struct IsRef<const T&> {
  static const bool isTrue = true;
  static const bool outBoundable = false;
};

#endif /* HDE71C4B3_8353_4752_AADD_B9ADED598A7D */
