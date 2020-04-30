#ifndef HD2D7ED23_6286_417C_8CF2_ADA9F704CE08
#define HD2D7ED23_6286_417C_8CF2_ADA9F704CE08

#include <typeinfo>

struct PlaceHolder {
  virtual const std::type_info & type() const = 0;
  virtual PlaceHolder* clone() const = 0;
  virtual ~PlaceHolder() {}
};

#endif /* HD2D7ED23_6286_417C_8CF2_ADA9F704CE08 */


