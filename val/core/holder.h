#ifndef H33901192_ADC0_4E89_8710_6C20BBD15C81
#define H33901192_ADC0_4E89_8710_6C20BBD15C81

#include <typeinfo>

struct Holder {
  virtual const std::type_info& type() const = 0;
  virtual Holder* clone() const = 0;
  virtual ~Holder() {}
};

#endif
