#ifndef HD2D7ED23_6286_417C_8CF2_ADA9F704CE08
#define HD2D7ED23_6286_417C_8CF2_ADA9F704CE08

#include "val/core/holder.h"

template <typename T>
struct BaseHolder : Holder {
  virtual const T& getValue() const = 0;

private:
  const std::type_info& type() const override {
    return typeid(T);
  }
};

#endif /* HD2D7ED23_6286_417C_8CF2_ADA9F704CE08 */


