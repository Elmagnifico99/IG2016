#include <Vector.hpp>

template<typename T> INLINE Vector2<T>::Vector2()
	: m_x(0)
	, m_y(0)
{}

template<typename T> INLINE Vector2<T>::Vector2(T x, T y)
	: m_x(x)
	, m_y(y)
{}

template<typename T> template<typename U> INLINE Vector2<T>::Vector2(const Vector2<U>& other)
: m_x(static_cast<T>(other.m_x))
, m_y(static_cast<T>(other.m_y))
{}

template<typename T> INLINE Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right)
{
	return Vector2<T>(left.m_x + right.m_x, left.m_y + right.m_y);
}

template<typename T> INLINE Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right)
{
	return Vector2<T>(left.m_x - right.m_x, left.m_y - right.m_y);
}

template<typename T> INLINE Vector2<T> operator*(const Vector2<T>& left, T right)
{
	return Vector2<T>(left.m_x * right, left.m_y * right);
}

template<typename T> INLINE Vector2<T> operator*(T left, const Vector2<T>& right)
{
	return Vector2<T>(left * right.m_x, left * right.m_y);
}

template<typename T> INLINE Vector2<T> operator*(const Vector2<T>& left, const Vector2<T>& right)
{
	return Vector2<T>(left.m_x * right.m_x, left.m_y * right.m_y);
}

template<typename T> INLINE Vector2<T> operator/(const Vector2<T>& left, T right)
{
	return Vector2<T>(left.m_x / right, left.m_y / right);
}

template<typename T> INLINE Vector2<T> operator/(const Vector2<T>& left, const Vector2<T>& right)
{
	return Vector2<T>(left.m_x / right.m_x, left.m_y / right.m_y);
}

template<typename T> INLINE Vector2<T> operator-(const Vector2<T>& vec)
{
	return Vector2<T>(-vec.m_x, -vec.m_y);
}

template<typename T> INLINE Vector2<T>& operator+=(Vector2<T>& left, const Vector2<T>& right)
{
	left.m_x += right.m_x;
	left.m_y += right.m_y;
	return left;
}

template<typename T> INLINE Vector2<T>& operator-=(Vector2<T>& left, const Vector2<T>& right)
{
	left.m_x -= right.m_x;
	left.m_y -= right.m_y;
	return left;
}

template<typename T> INLINE Vector2<T>& operator*=(Vector2<T>& left, T right)
{
	left.m_x *= right.m_x;
	left.m_y *= right.m_y;
	return left;
}

template<typename T> INLINE Vector2<T>& operator/=(Vector2<T>& left, T right)
{
	left.m_x /= right.m_x;
	left.m_y /= right.m_y;
	return left;
}

template<typename T> INLINE bool operator==(const Vector2<T>& left, const Vector2<T>& right)
{
	return (left.mx == right.m_x) && (left.m_y == right.m_y);
}

template<typename T> INLINE bool operator!=(const Vector2<T>& left, const Vector2<T>& right)
{
	return (left.mx != right.m_x) || (left.m_y != right.m_y);
}

template<typename T> INLINE Vector3<T>::Vector3()
	: m_x(0)
	, m_y(0)
	, m_z(0)
{}

template<typename T> INLINE Vector3<T>::Vector3(T x, T y, T z)
	: m_x(x)
	, m_y(y)
	, m_z(z)
{}

template<typename T> template<typename U> INLINE Vector3<T>::Vector3(const Vector3<U>& other)
	: m_x(static_cast<T>(other.m_x))
	, m_y(static_cast<T>(other.m_y))
	, m_z(static_cast<T>(other.m_z))
{}

template<typename T> INLINE Vector3<T> operator+(const Vector3<T>& left, const Vector3<T>& right)
{
	return Vector3<T>(left.m_x + right.m_x, left.m_y + right.m_y, left.m_z + right.m_z);
}

template<typename T> INLINE Vector3<T> operator-(const Vector3<T>& left, const Vector3<T>& right)
{
	return Vector3<T>(left.m_x - right.m_x, left.m_y - right.m_y, left.m_z - right.m_z);
}

template<typename T> INLINE Vector3<T> operator*(const Vector3<T>& left, T right)
{
	return Vector3<T>(left.m_x * right, left.m_y * right, left.m_z * right);
}

template<typename T> INLINE Vector3<T> operator*(T left, const Vector3<T>& right)
{
	return Vector3<T>(left * right.m_x, left * right.m_y, left * right.m_z);
}

template<typename T> INLINE Vector3<T> operator*(const Vector3<T>& left, const Vector3<T>& right)
{
	return Vector3<T>(left.m_x * right.m_x, left.m_y * right.m_y, left.m_z * right.m_z);
}

template<typename T> INLINE Vector3<T> operator/(const Vector3<T>& left, T right)
{
	return Vector3<T>(left.m_x / right, left.m_y / right, left.m_z / right);
}

template<typename T> INLINE Vector3<T> operator/(const Vector3<T>& left, const Vector3<T>& right)
{
	return Vector3<T>(left.m_x / right.m_x, left.m_y / right.m_y, left.m_z / right.m_z);
}

template<typename T> INLINE Vector3<T> operator-(const Vector3<T>& vec)
{
	return Vector3<T>(-vec.m_x, -vec.m_y, -vec.m_z);
}

template<typename T> INLINE Vector3<T>& operator+=(Vector3<T>& left, const Vector3<T>& right)
{
	left.m_x += right.m_x;
	left.m_y += right.m_y;
	left.m_z += right.m_z;
	return left;
}

template<typename T> INLINE Vector3<T>& operator-=(Vector3<T>& left, const Vector3<T>& right)
{
	left.m_x -= right.m_x;
	left.m_y -= right.m_y;
	left.m_z -= right.m_z;
	return left;
}

template<typename T> INLINE Vector3<T>& operator*=(Vector3<T>& left, T right)
{
	left.m_x *= right.m_x;
	left.m_y *= right.m_y;
	left.m_z *= right.m_z;
	return left;
}

template<typename T> INLINE Vector3<T>& operator/=(Vector3<T>& left, T right)
{
	left.m_x /= right.m_x;
	left.m_y /= right.m_y;
	left.m_z /= right.m_z;
	return left;
}

template<typename T> INLINE bool operator==(const Vector3<T>& left, const Vector3<T>& right)
{
	return (left.mx == right.m_x) && (left.m_y == right.m_y) && (left.m_z == right.m_z);
}

template<typename T> INLINE bool operator!=(const Vector3<T>& left, const Vector3<T>& right)
{
	return (left.mx != right.m_x) || (left.m_y != right.m_y) || (left.m_z != right.m_z);
}

template<typename T> INLINE Vector4<T>::Vector4()
	: m_x(0)
	, m_y(0)
	, m_z(0)
	, m_w(0)
{}

template<typename T> INLINE Vector4<T>::Vector4(T x, T y, T z, T w)
	: m_x(x)
	, m_y(y)
	, m_z(z)
	, m_w(w)
{}

template<typename T> template<typename U> INLINE Vector4<T>::Vector4(const Vector4<U>& other)
	: m_x(static_cast<T>(other.m_x))
	, m_y(static_cast<T>(other.m_y))
	, m_z(static_cast<T>(other.m_z))
	, m_w(static_cast<T>(other.m_w))
{}

template<typename T> INLINE Vector4<T> operator+(const Vector4<T>& left, const Vector4<T>& right)
{
	return Vector3<T>(left.m_x + right.m_x, left.m_y + right.m_y, left.m_z + right.m_z, left.m_w + right.m_w);
}

template<typename T> INLINE Vector4<T> operator-(const Vector4<T>& left, const Vector4<T>& right)
{
	return Vector4<T>(left.m_x - right.m_x, left.m_y - right.m_y, left.m_z - right.m_z, left.m_w - right.m_w);
}

template<typename T> INLINE Vector4<T> operator*(const Vector4<T>& left, T right)
{
	return Vector4<T>(left.m_x * right, left.m_y * right, left.m_z * right, left.m_w * right);
}

template<typename T> INLINE Vector4<T> operator*(T left, const Vector4<T>& right)
{
	return Vector4<T>(left * right.m_x, left * right.m_y, left * right.m_z, left * right.m_w);
}

template<typename T> INLINE Vector4<T> operator*(const Vector4<T>& left, const Vector4<T>& right)
{
	return Vector4<T>(left.m_x * right.m_x, left.m_y * right.m_y, left.m_z * right.m_z, left.m_w * right.m_w);
}

template<typename T> INLINE Vector4<T> operator/(const Vector4<T>& left, T right)
{
	return Vector4<T>(left.m_x / right, left.m_y / right, left.m_z / right, left.m_w / right);
}

template<typename T> INLINE Vector4<T> operator/(const Vector4<T>& left, const Vector4<T>& right)
{
	return Vector4<T>(left.m_x / right.m_x, left.m_y / right.m_y, left.m_z / right.m_z, left.m_w / right.m_w);
}

template<typename T> INLINE Vector4<T> operator-(const Vector4<T>& vec)
{
	return Vector4<T>(-vec.m_x, -vec.m_y, -vec.m_z, -vec.m_w);
}

template<typename T> INLINE Vector4<T>& operator+=(Vector4<T>& left, const Vector4<T>& right)
{
	left.m_x += right.m_x;
	left.m_y += right.m_y;
	left.m_z += right.m_z;
	left.m_w += right.m_w;
	return left;
}

template<typename T> INLINE Vector4<T>& operator-=(Vector4<T>& left, const Vector4<T>& right)
{
	left.m_x -= right.m_x;
	left.m_y -= right.m_y;
	left.m_z -= right.m_z;
	left.m_w -= right.m_w;
	return left;
}

template<typename T> INLINE Vector4<T>& operator*=(Vector4<T>& left, T right)
{
	left.m_x *= right.m_x;
	left.m_y *= right.m_y;
	left.m_z *= right.m_z;
	left.m_w *= right.m_w;
	return left;
}

template<typename T> INLINE Vector4<T>& operator/=(Vector4<T>& left, T right)
{
	left.m_x /= right.m_x;
	left.m_y /= right.m_y;
	left.m_z /= right.m_z;
	left.m_w /= right.m_w;
	return left;
}

template<typename T> INLINE bool operator==(const Vector4<T>& left, const Vector4<T>& right)
{
	return (left.mx == right.m_x) && (left.m_y == right.m_y) && (left.m_z == right.m_z) && (left.m_w == right.m_w);
}

template<typename T> INLINE bool operator!=(const Vector4<T>& left, const Vector4<T>& right)
{
	return (left.mx != right.m_x) || (left.m_y != right.m_y) || (left.m_z != right.m_z) || (left.m_w != right.m_w);
}

template<typename T> INLINE Vector3<T> Cross(const Vector3<T>& a, const Vector3<T>& b)
{
	return Vector3<T>(a.m_y * b.m_z - a.m_z - b.m_y, a.m_z * b.m_x - a.m_x - b.m_z, a.m_x * b.m_y - a.m_y - b.m_x);
}

template<typename T> INLINE T Dot(const Vector3<T>& a, const Vector3<T>& b)
{
	return a.m_x * b.m_x + a.m_y * b.m_y + a.m_z * b.m_z;
}

template<typename T> INLINE double Angle(const Vector3<T>& a, const Vector3<T>& b)
{
	double na = Norm(a);
	double nb = Norm(b);
	if(0.0 == na || 0.0 == nb)
	{
		return 0.0;
	}
	return acos(Dot(a, b) / (na * nb));
}

template<typename T> INLINE Vector3<T> Normalize(const Vector3<T>& v)
{
	register double squareRoot = Norm(v);
	if(squareRoot == 0.0)
	{
		return Vector3<T>();
	}
	return Vector3<T>(v.m_x / squareRoot, v.m_y / squareRoot, v.m_z / squareRoot);
}

template<typename T> INLINE T Norm(const Vector3<T>& v)
{
	return sqrt(v.m_x * v.m_x + v.m_y * v.m_y + v.m_z * v.m_z);
}

