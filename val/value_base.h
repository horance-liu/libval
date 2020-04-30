#ifndef H5E822A0E_01ED_467D_8BD7_1EF32B9ACFB6
#define H5E822A0E_01ED_467D_8BD7_1EF32B9ACFB6

#include "val/holder.h"

struct ValueBase {
  bool empty() const;
  const std::type_info& type() const;

protected:
  ValueBase(PlaceHolder* holder = nullptr);
  ~ValueBase();

  ValueBase& swap(ValueBase &rhs);
  PlaceHolder* getContent() const;

private:
  PlaceHolder* holder;

  template<typename ValueType>
  friend ValueType* __type_value_cast(ValueBase*);
};

#endif /* H5E822A0E_01ED_467D_8BD7_1EF32B9ACFB6 */

