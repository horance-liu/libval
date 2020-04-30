#ifndef H9D4787A0_2534_4257_A657_418E6743D0F2
#define H9D4787A0_2534_4257_A657_418E6743D0F2

#include "val/place_holder.h"

template<typename T>
struct Holder : PlaceHolder {
  typedef T Type;
  virtual const T& getValue() const = 0;

private:
  const std::type_info& type() const override {
    return typeid(T);
  }
};

#endif /* H9D4787A0_2534_4257_A657_418E6743D0F2 */
