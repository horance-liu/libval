# libval: type-safe container for single value of any type.

## Build 

### CMake 

```bash
$ mkdir build && cd build
$ cmake ..
$ make && make test
```

libval use xunit cctest:

```bash
$ git clone https://github.com/ccup/cctest.git
$ cd cctest && mkdir build && cd build
$ cmake ..
$ make && sudo make install 
```

### Bazel

```bash
$ bazel test //val/...
```

Bazel will download xunit cctest.

## Usage

libval's Value object will contains one single value of any type, and then you can cast to the value for the original type. 

```bash
TEST("uint -> uint") {
  Value a((unsigned int) 2);
  ASSERT_TRUE(value_castable<unsigned int>(a));
  ASSERT_EQ(2, value_cast<unsigned int>(a));
}
```

libval supports type conversions, and allows all of rules for type conversion in C/C++ programming langugae.

```cpp
TEST("char -> ushort") {
  Value a((char) 2);

  ASSERT_TRUE(value_castable<unsigned short>(a));
  ASSERT_EQ(2, value_cast<unsigned short>(a));
}
```

libval will not castable if value is overflow or underflow.

```cpp
TEST("int(max_ushort + 1) -> ushort: overflow") {
  Value a(std::numeric_limits<unsigned short>::max() + 1);

  ASSERT_TRUE(!value_castable<unsigned short>(a));
}
```

libval supports the conversions between enum constants and integers.

```cpp
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

TEST("enum -> long") {
  Value l(Enum10);

  ASSERT_TRUE(value_castable<long>(l));
  ASSERT_EQ(10, value_cast<long>(l));
}
```

## TODO

### universal constructor.

```cpp
Value(Value&&) noexcept;

template <class T>
Value(T&&);

template <class T, class... Args>
explicit Value(std::in_place_type_t<T>, Args&&... args);
```

### universal operator= 

```cpp
Value& operator=(Value&&) noexcept;

template<typename T>
Value& operator=(T&&);
```

### make_value factory

```cpp
template <class T, class... Args>
Value make_value(Args&&... args);
```
