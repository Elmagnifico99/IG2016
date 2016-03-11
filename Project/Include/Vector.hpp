#ifndef __VECTOR_HPP
#define __VECTOR_HPP

#define TEMPLATE(t) template<typename T>

template<typename T>
class Vector2
{
public:

	explicit Vector2(void);
	explicit Vector2(T x, T y);
	template<typename U> explicit Vector2(const Vector2<U>& other);
	virtual ~Vector2(void){}

	T m_x;
	T m_y;

};

template<typename T> Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right);

template<typename T> Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right);

template<typename T> Vector2<T> operator*(const Vector2<T>& left, T right);

template<typename T> Vector2<T> operator*(T left, const Vector2<T>& right);

template<typename T> Vector2<T> operator*(const Vector2<T>& left, const Vector2<T>& right);

template<typename T> Vector2<T> operator/(const Vector2<T>& left, T right);

template<typename T> Vector2<T> operator/(const Vector2<T>& left, const Vector2<T>& right);

template<typename T> Vector2<T> operator-(const Vector2<T>& vec);

template<typename T> Vector2<T>& operator+=(Vector2<T>& left, const Vector2<T>& right);

template<typename T> Vector2<T>& operator-=(Vector2<T>& left, const Vector2<T>& right);

template<typename T> Vector2<T>& operator*=(Vector2<T>& left, T right);

template<typename T> Vector2<T>& operator/=(Vector2<T>& left, T right);

bool operator==(const Vector2<float>& left, const Vector2<float>& right);

bool operator!=(const Vector2<float>& left, const Vector2<float>& right);

typedef Vector2<unsigned int> 	Vector2u;
typedef Vector2<int>			Vector2i;
typedef Vector2<float>			Vector2f;
typedef Vector2<double>			Vector2d;

template<typename T>
class Vector3
{
public:

	explicit Vector3(void);
	explicit Vector3(T x, T y, T z);
	template<typename U> explicit Vector3(const Vector3<U>& other);
	virtual ~Vector3(void){}

	T m_x;
	T m_y;
	T m_z;

};

template<typename T> Vector3<T> operator+(const Vector3<T>& left, const Vector3<T>& right);

template<typename T> Vector3<T> operator-(const Vector3<T>& left, const Vector3<T>& right);

template<typename T> Vector3<T> operator*(const Vector3<T>& left, T right);

template<typename T> Vector3<T> operator*(T left, const Vector3<T>& right);

template<typename T> Vector3<T> operator*(const Vector3<T>& left, const Vector3<T>& right);

template<typename T> Vector3<T> operator/(const Vector3<T>& left, T right);

template<typename T> Vector3<T> operator/(const Vector3<T>& left, const Vector3<T>& right);

template<typename T> Vector3<T> operator-(const Vector3<T>& vec);

template<typename T> Vector3<T>& operator+=(Vector3<T>& left, const Vector3<T>& right);

template<typename T> Vector3<T>& operator-=(Vector3<T>& left, const Vector3<T>& right);

template<typename T> Vector3<T>& operator*=(Vector3<T>& left, T right);

template<typename T> Vector3<T>& operator/=(Vector3<T>& left, T right);

bool operator==(const Vector3<float>& left, const Vector3<float>& right);

bool operator!=(const Vector3<float>& left, const Vector3<float>& right);

typedef Vector3<unsigned int> 	Vector3u;
typedef Vector3<int>			Vector3i;
typedef Vector3<float>			Vector3f;
typedef Vector3<double>			Vector3d;

template<typename T>
class Vector4
{
public:

	explicit Vector4(void);
	explicit Vector4(T x, T y, T z, T w);
	template<typename U> explicit Vector4(const Vector4<U>& other);
	virtual ~Vector4(void){}

	T m_x;
	T m_y;
	T m_z;
	T m_w;

};

template<typename T> Vector4<T> operator+(const Vector4<T>& left, const Vector4<T>& right);

template<typename T> Vector4<T> operator-(const Vector4<T>& left, const Vector4<T>& right);

template<typename T> Vector4<T> operator*(const Vector4<T>& left, T right);

template<typename T> Vector4<T> operator*(T left, const Vector4<T>& right);

template<typename T> Vector4<T> operator*(const Vector4<T>& left, const Vector4<T>& right);

template<typename T> Vector4<T> operator/(const Vector4<T>& left, T right);

template<typename T> Vector4<T> operator/(const Vector4<T>& left, const Vector4<T>& right);

template<typename T> Vector4<T> operator-(const Vector4<T>& vec);

template<typename T> Vector4<T>& operator+=(Vector4<T>& left, const Vector4<T>& right);

template<typename T> Vector4<T>& operator-=(Vector4<T>& left, const Vector4<T>& right);

template<typename T> Vector4<T>& operator*=(Vector4<T>& left, T right);

template<typename T> Vector4<T>& operator/=(Vector4<T>& left, T right);

bool operator==(const Vector4<float>& left, const Vector4<float>& right);

bool operator!=(const Vector4<float>& left, const Vector4<float>& right);

typedef Vector4<unsigned int> 	Vector4u;
typedef Vector4<int>			Vector4i;
typedef Vector4<float>			Vector4f;
typedef Vector4<double>			Vector4d;

// Utils

template<typename T> Vector3<T> Cross(const Vector3<T>& a, const Vector3<T>& b);
template<typename T> T Dot(const Vector3<T>& a, const Vector3<T>& b);
template<typename T> double Angle(const Vector3<T>& a, const Vector3<T>& b);
template<typename T> Vector3<T> Normalize(const Vector3<T>& v);
template<typename T> T Norm(const Vector3<T>& v);

#include "Vector.inl"

#endif // __VECTOR_HPP