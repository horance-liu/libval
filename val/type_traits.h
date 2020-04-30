#ifndef H81FC8E66_9FAB_45DE_9AB2_406B393BC7D0
#define H81FC8E66_9FAB_45DE_9AB2_406B393BC7D0

/*
 * For non-reference type
 */
template<typename T>
struct TypeTraits {
  typedef T Raw;
  typedef T &RefRaw;

  typedef T Type;
  typedef T &Ref;
};

/*
 * For non-reference type
 */
template<typename T>
struct TypeTraits<const T> {
  typedef T Raw;
  typedef T &RefRaw;

  typedef T Type;
  typedef const T &Ref;
};

/*
 * For non-reference type
 */
template<typename T>
struct TypeTraits<const T*> {
  typedef T *Raw;
  typedef T *&RefRaw;

  typedef const T *Type;
  typedef const T *&Ref;
};

/*
 * For reference type
 */
template<typename T>
struct TypeTraits<T&> {
  typedef T Raw;
  typedef T &RefRawx;

  typedef T Type;
  typedef T &Ref;
};

/*
 * For reference type
 */
template<typename T>
struct TypeTraits<const T&> {
  typedef T Raw;
  typedef T &RefRaw;

  typedef T Type;
  typedef const T &Ref;
};

/*
 * For non-reference type
 */
template<>
struct TypeTraits<void> {
  typedef void Raw;
  typedef void RefRaw;

  typedef void Type;
  typedef void Ref;
};

#endif /* H81FC8E66_9FAB_45DE_9AB2_406B393BC7D0 */

