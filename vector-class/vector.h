//
// vector.h -- simple vector class
//

#ifndef VECTOR_CLASS_H
#define VECTOR_CLASS_H
#pragma once

#include <cmath>
#include <type_traits>

namespace detail
{

//
// type specification
//

template<typename T>
concept VectorType = std::is_integral_v<T> || std::is_floating_point_v<T>;

//
// two dimensional vector class with helpers
//
template <VectorType T>
class vector_2d
{
public:
	// 
	// Construction and destruction
	// 

	constexpr vector_2d() noexcept :
		x(0.0),
		y(0.0)
	{
	}
	constexpr ~vector_2d() noexcept
	{
	}
	constexpr vector_2d(T X, T Y) noexcept :
		x(X),
		y(Y)
	{
	}

	// instantiation with a pointer
	constexpr vector_2d(T p[2]) noexcept
	{
		if (p)
		{
			x = p[0];
			y = p[1];
		}
		else
		{
			x = 0.0;
			y = 0.0;
		}
	};

	// instantiated with another vector
	constexpr vector_2d(const vector_2d& in) noexcept :
		x(in.x),
		y(in.y)
	{
	}

	// instantiated with another vector
	constexpr vector_2d(vector_2d& in) noexcept :
		x(in.x),
		y(in.y)
	{
	}

	// 
	// Conversion operators
	// 

	// Called when vec is asigned to T* or when passing as an argument
	// to a function which takes T*.
	constexpr inline operator T* () noexcept
	{
		return &x;
	}

	// Called when vec is asigned to const T* or when passing as an 
	// argument to a function which takes const T*.
	constexpr inline operator const T* () const noexcept
	{
		return &x;
	}

	// 
	// Operator=
	// 

	constexpr inline auto& operator=(const vector_2d& other) noexcept
	{
		x = other.x;
		y = other.y;

		return *this;
	}

	constexpr inline auto& operator=(T p[2]) noexcept
	{
		if (p)
		{
			x = p[0];
			y = p[1];
		}
		else
		{
			x = y = 0.0;
		}

		return *this;
	}

	constexpr inline auto& operator=(T f) noexcept
	{
		x = y = f;

		return *this;
	}

	// 
	// Operator+=
	// 

	constexpr inline auto& operator+=(const vector_2d& other) noexcept
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	constexpr inline auto& operator+=(T p[2]) noexcept
	{
		if (p)
		{
			x += p[0];
			y += p[1];
		}

		return *this;
	}

	constexpr inline auto& operator+=(T f) noexcept
	{
		x += f;
		y += f;

		return *this;
	}

	// 
	// Operator-=
	// 

	constexpr inline auto& operator-=(const vector_2d& other) noexcept
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}

	constexpr inline auto& operator-=(T p[2]) noexcept
	{
		if (p)
		{
			x -= p[0];
			y -= p[1];
		}

		return *this;
	}

	constexpr inline auto& operator-=(T f) noexcept
	{
		x -= f;
		y -= f;

		return *this;
	}

	// 
	// Operator*=
	// 

	constexpr inline auto& operator*=(const vector_2d& other) noexcept
	{
		x *= other.x;
		y *= other.y;

		return *this;
	}

	constexpr inline auto& operator*=(T p[2]) noexcept
	{
		if (p)
		{
			x *= p[0];
			y *= p[1];
		}

		return *this;
	}

	constexpr inline auto& operator*=(T f) noexcept
	{
		x *= f;
		y *= f;

		return *this;
	}

	// 
	// Operator/=
	// 

	constexpr inline auto& operator/=(const vector_2d& other) noexcept
	{
		if (other.x != 0.0 && other.y != 0.0)
		{
			x /= other.x;
			y /= other.y;
		}

		return *this;
	}

	constexpr inline auto& operator/=(T p[2]) noexcept
	{
		if (p)
		{
			if (p[0] != 0.0 && p[1] != 0.0)
			{
				x /= p[0];
				y /= p[1];
			}
		}

		return *this;
	}

	constexpr inline auto& operator/=(T f) noexcept
	{
		if (f != 0.0)
		{
			x /= f;
			y /= f;
		}

		return *this;
	}

	// 
	// Operator+
	// 

	constexpr inline auto operator+(const vector_2d& other) const noexcept
	{
		return vector_2d(x + other.x, y + other.y);
	}

	constexpr inline auto operator+(T p[2]) const noexcept
	{
		if (p)
			return vector_2d(x + p[0], y + p[1]);

		return *this;
	}

	constexpr inline auto operator+(T f) const noexcept
	{
		return vector_2d(x + f, y + f);
	}

	// 
	// Operator-
	// 

	constexpr inline auto operator-(const vector_2d& other) const noexcept
	{
		return vector_2d(x - other.x, y - other.y);
	}

	constexpr inline auto operator-(T p[2]) const noexcept
	{
		if (p)
			return vector_2d(x - p[0], y - p[1]);

		return *this;
	}

	constexpr inline auto operator-(T f) const noexcept
	{
		return vector_2d(x - f, y - f);
	}

	// 
	// Operator- (negation)
	// 

	constexpr inline auto operator-() const noexcept
	{
		return vector_2d(-x, -y);
	}

	// 
	// Operator*
	// 

	constexpr inline auto operator*(const vector_2d& other) const noexcept
	{
		return vector_2d(x * other.x, y * other.y);
	}

	constexpr inline auto operator*(T p[2]) const noexcept
	{
		if (p)
			return vector_2d(x * p[0], y * p[1]);

		return *this;
	}

	constexpr inline auto operator*(T f) const noexcept
	{
		return vector_2d(x * f, y * f);
	}

	// 
	// Operator/
	// 

	constexpr inline auto operator/(const vector_2d& other) const noexcept
	{
		if (other.x != 0.0 && other.y != 0.0)
			return vector_2d(x / other.x, y / other.y);

		return *this;
	}

	constexpr inline auto operator/(T p[2]) const noexcept
	{
		if (p)
		{
			if (p[0] != 0.0 && p[1] != 0.0)
				return vector_2d(x / p[0], y / p[1]);
		}

		return *this;
	}

	constexpr inline auto operator/(T f) const noexcept
	{
		if (f != 0.0)
			return vector_2d(x / f, y / f);

		return *this;
	}

	// 
	// Operator[]
	// 

	constexpr inline auto& operator[](int i) const noexcept
	{
		if (i >= 0 && i < 3)
			return ((T*)this)[i];

		return ((T*)this)[0];
	}

	// 
	// Boolean operators
	// 

	constexpr inline bool operator!() const noexcept
	{
		return x == 0.0 && y == 0.0;
	}

	constexpr inline bool operator==(const vector_2d& other) const noexcept
	{
		return x == other.x && y == other.y;
	}

	constexpr inline bool operator!=(const vector_2d& other) const noexcept
	{
		return x != other.x || y != other.y;
	}

	constexpr inline bool operator<(const vector_2d& other) const noexcept
	{
		return x < other.x && y < other.y;
	}

	constexpr inline bool operator>(const vector_2d& other) const noexcept
	{
		return x > other.x && y > other.y;
	}

	// 
	// Constexpr helpers
	// 

	// true if all of the members are zero
	constexpr inline bool IsZero() const noexcept
	{
		return x == 0.0 && y == 0.0;
	}

	// returns pointer to the first element
	constexpr inline auto Base() noexcept
	{
		return &x;
	}

	// returns const pointer to the first element
	constexpr inline auto Base() const noexcept
	{
		return &x;
	}

	// resets vector
	constexpr inline auto& Clear() noexcept
	{
		x = y = 0.0;

		return *this;
	}

	// inverts vector
	constexpr inline auto& Negate() noexcept
	{
		x = -x;
		y = -y;

		return *this;
	}

	// dot product of vector
	constexpr inline auto Dot(const vector_2d& other) const noexcept
	{
		return x * other.x + y * other.y;
	}

	// returns length without using sqrt
	constexpr inline auto LengthSqr() const noexcept
	{
		return x * x + y * y;
	}

	// cross product of vector
	constexpr inline auto& CrossProduct(const vector_2d& a, const vector_2d& b) noexcept
	{
		x = (a.y * b.z) - (a.z * b.y);
		y = (a.z * b.x) - (a.x * b.z);

		return *this;
	}

	// https://en.wikipedia.org/wiki/Linear_interpolation
	constexpr inline void Lerp(const vector_2d& a, const vector_2d& b, float t)
	{
		x = a.x + (b.x - a.x) * t;
		y = a.y + (b.y - a.y) * t;
	}

	// identical to VectorMA
	constexpr inline void MulAdd(const vector_2d& a, const vector_2d& b, float scalar)
	{
		x = a.x + b.x * scalar;
		y = a.y + b.y * scalar;
	}

	// copy contents of our vector to an allocated array
	constexpr inline void CopyToArray(float* rgfl) const
	{
		rgfl[0] = x;
		rgfl[1] = y;
	}

	// 
	// Runtime helpers
	// 

	// checks if the vector contents is valid
	inline bool IsValid() const noexcept
	{
		return isfinite(x) && isfinite(y);
	}

	// returns length of the vector using sqrt
	inline auto Length() const noexcept
	{
		return static_cast<T>(sqrt(LengthSqr()));
	}

	// returns distance to the other vector
	inline auto Distance(const vector_2d& ToVector) const noexcept
	{
		return (ToVector - *this).Length();
	}

	// returns normalized vector, however does not modify it's members
	inline auto Normalize() const noexcept
	{
		T flLen = Length();

		if (flLen == 0.0)
			return vector_2d(0.0, 0.0);

		flLen = 1.0 / flLen;
		return vector_2d(x * flLen, y * flLen);
	}

public:
	T x, y;
};

// for vec * float
// NOTE: has to be outside
template <VectorType T>
constexpr inline vector_2d<T> operator*(float p, const vector_2d<T>& v)
{
	return v * p;
};

//
// three dimensional vector class with helpers
//
template <VectorType T>
class vector_3d
{
public:
	// 
	// Construction and destruction
	// 

	constexpr vector_3d() noexcept :
		x(0.0),
		y(0.0),
		z(0.0)
	{
	}

	constexpr ~vector_3d() noexcept
	{
	}

	constexpr vector_3d(T X, T Y, T Z) noexcept :
		x(X),
		y(Y),
		z(Z)
	{}

	// instantiated with a pointer
	constexpr vector_3d(T p[3]) noexcept
	{
		if (p)
		{
			x = p[0];
			y = p[1];
			z = p[2];
		}
		else
		{
			x = 0.0;
			y = 0.0;
			z = 0.0;
		}
	};

	// instantiated with another vector
	constexpr vector_3d(const vector_3d& in) noexcept :
		x(in.x),
		y(in.y),
		z(in.z)
	{
	}

	// instantiated with another vector
	constexpr vector_3d(vector_3d& in) noexcept :
		x(in.x),
		y(in.y),
		z(in.z)
	{
	}

	// 
	// Conversion operators
	// 

	// called when Vector is asigned to T* or when passing as an argument
	// to a function which takes T*.
	constexpr inline operator T* () noexcept
	{
		return &x;
	}

	// called when Vector is asigned to const T* or when passing as an 
	// argument to a function which takes const T*.
	constexpr inline operator const T* () const noexcept
	{
		return &x;
	}

	// 
	// Operator=
	// 

	constexpr inline auto& operator=(const vector_3d& other) noexcept
	{
		x = other.x;
		y = other.y;
		z = other.z;

		return *this;
	}

	constexpr inline auto& operator=(T p[3]) noexcept
	{
		if (p)
		{
			x = p[0];
			y = p[1];
			z = p[2];
		}
		else
		{
			x = y = z = 0.0;
		}

		return *this;
	}

	constexpr inline auto& operator=(T f) noexcept
	{
		x = y = z = f;

		return *this;
	}

	// 
	// Operator+=
	// 

	constexpr inline auto& operator+=(const vector_3d& other) noexcept
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	constexpr inline auto& operator+=(T p[3]) noexcept
	{
		if (p)
		{
			x += p[0];
			y += p[1];
			z += p[2];
		}

		return *this;
	}

	constexpr inline auto& operator+=(T f) noexcept
	{
		x += f;
		y += f;
		z += f;

		return *this;
	}

	// 
	// Operator-=
	// 

	constexpr inline auto& operator-=(const vector_3d& other) noexcept
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	constexpr inline auto& operator-=(T p[3]) noexcept
	{
		if (p)
		{
			x -= p[0];
			y -= p[1];
			z -= p[2];
		}

		return *this;
	}

	constexpr inline auto& operator-=(T f) noexcept
	{
		x -= f;
		y -= f;
		z -= f;

		return *this;
	}

	// 
	// Operator*=
	// 

	constexpr inline auto& operator*=(const vector_3d& other) noexcept
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	constexpr inline auto& operator*=(T p[3]) noexcept
	{
		if (p)
		{
			x *= p[0];
			y *= p[1];
			z *= p[2];
		}

		return *this;
	}

	constexpr inline auto& operator*=(T f) noexcept
	{
		x *= f;
		y *= f;
		z *= f;

		return *this;
	}

	// 
	// Operator/=
	// 

	constexpr inline auto& operator/=(const vector_3d& other) noexcept
	{
		if (other.x != 0.0 && other.y != 0.0 && other.z != 0.0)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
		}

		return *this;
	}

	constexpr inline auto& operator/=(T p[3]) noexcept
	{
		if (p)
		{
			if (p[0] != 0.0 && p[1] != 0.0 && p[2] != 0.0)
			{
				x /= p[0];
				y /= p[1];
				z /= p[2];
			}
		}

		return *this;
	}

	constexpr inline auto& operator/=(T f) noexcept
	{
		if (f != 0.0)
		{
			x /= f;
			y /= f;
			z /= f;
		}

		return *this;
	}

	// 
	// Operator+
	// 

	constexpr inline auto operator+(const vector_3d& other) const noexcept
	{
		return vector_3d(x + other.x, y + other.y, z + other.z);
	}

	constexpr inline auto operator+(T p[3]) const noexcept
	{
		if (p)
			return vector_3d(x + p[0], y + p[1], z + p[2]);

		return *this;
	}

	constexpr inline auto operator+(T f) const noexcept
	{
		return vector_3d(x + f, y + f, z + f);
	}

	// 
	// Operator-
	// 

	constexpr inline auto operator-(const vector_3d& other) const noexcept
	{
		return vector_3d(x - other.x, y - other.y, z - other.z);
	}

	constexpr inline auto operator-(T p[3]) const noexcept
	{
		if (p)
			return vector_3d(x - p[0], y - p[1], z - p[2]);

		return *this;
	}

	constexpr inline auto operator-(T f) const noexcept
	{
		return vector_3d(x - f, y - f, z - f);
	}

	// 
	// Operator- (negation)
	// 

	constexpr inline auto operator-() const noexcept
	{
		return vector_3d(-x, -y, -z);
	}

	// 
	// Operator*
	// 

	constexpr inline auto operator*(const vector_3d& other) const noexcept
	{
		return vector_3d(x * other.x, y * other.y, z * other.z);
	}

	constexpr inline auto operator*(T p[3]) const noexcept
	{
		if (p)
			return vector_3d(x * p[0], y * p[1], z * p[2]);

		return *this;
	}

	constexpr inline auto operator*(T f) const noexcept
	{
		return vector_3d(x * f, y * f, z * f);
	}

	// 
	// Operator/
	// 

	constexpr inline auto operator/(const vector_3d& other) const noexcept
	{
		if (other.x != 0.0 && other.y != 0.0 && other.z != 0.0)
			return vector_3d(x / other.x, y / other.y, z / other.z);

		return *this;
	}

	constexpr inline auto operator/(T p[3]) const noexcept
	{
		if (p)
		{
			if (p[0] != 0.0 && p[1] != 0.0 && p[2] != 0.0)
				return vector_3d(x / p[0], y / p[1], z / p[2]);
		}

		return *this;
	}

	constexpr inline auto operator/(T f) const noexcept
	{
		if (f != 0.0)
			return vector_3d(x / f, y / f, z / f);

		return *this;
	}

	// 
	// Operator[]
	// 

	constexpr inline auto& operator[](int i) const noexcept
	{
		if (i >= 0 && i < 3)
			return ((T*)this)[i];

		return ((T*)this)[0];
	}

	// 
	// Boolean operators
	// 

	constexpr inline bool operator!() const noexcept
	{
		return x == 0.0 && y == 0.0 && z == 0.0;
	}

	constexpr inline bool operator==(const vector_3d& other) const noexcept
	{
		return x == other.x && y == other.y && z == other.z;
	}

	constexpr inline bool operator!=(const vector_3d& other) const noexcept
	{
		return x != other.x || y != other.y || z != other.z;
	}

	constexpr inline bool operator<(const vector_3d& other) const noexcept
	{
		return x < other.x && y < other.y && z < other.z;
	}

	constexpr inline bool operator>(const vector_3d& other) const noexcept
	{
		return x > other.x && y > other.y && z > other.z;
	}

	// 
	// Constexpr helpers
	// 

	// returns true if all of the members are zero
	constexpr inline bool IsZero() const noexcept
	{
		return x == 0.0 && y == 0.0 && z == 0.0;
	}

	// returns true if all two-dimensional members are zero
	constexpr inline bool IsZero2D() const noexcept
	{
		return x == 0.0 && y == 0.0;
	}

	// returns pointer to the first element
	constexpr inline auto Base() noexcept
	{
		return &x;
	}

	// returns const pointer to the first element
	constexpr inline auto Base() const noexcept
	{
		return &x;
	}

	// resets vector
	constexpr inline auto& Clear() noexcept
	{
		x = y = z = 0.0;

		return *this;
	}

	// inverts vector
	constexpr inline auto& Negate() noexcept
	{
		x = -x;
		y = -y;
		z = -z;

		return *this;
	}

	// dot product of vector
	constexpr inline auto Dot(const vector_3d& other) const noexcept
	{
		return x * other.x + y * other.y + z * other.z;
	}

	// dot product of 2D vector
	constexpr inline auto Dot2D(const vector_3d& other) const noexcept
	{
		return x * other.x + y * other.y;
	}

	// returns length without using sqrt
	constexpr inline auto LengthSqr() const noexcept
	{
		return x * x + y * y + z * z;
	}

	// returns 2D length without using sqrt
	constexpr inline auto LengthSqr2D() const noexcept
	{
		return x * x + y * y;
	}

	// cross product of vector
	constexpr inline auto& CrossProduct(const vector_3d& a, const vector_3d& b) noexcept
	{
		x = (a.y * b.z) - (a.z * b.y);
		y = (a.z * b.x) - (a.x * b.z);
		z = (a.x * b.y) - (a.y * b.x);

		return *this;
	}

	// https://en.wikipedia.org/wiki/Linear_interpolation
	constexpr inline void Lerp(const vector_3d& a, const vector_3d& b, float t)
	{
		x = a.x + (b.x - a.x) * t;
		y = a.y + (b.y - a.y) * t;
		z = a.z + (b.z - a.z) * t;
	}

	// identical to VectorMA
	constexpr inline void MulAdd(const vector_3d& a, const vector_3d& b, float scalar)
	{
		x = a.x + b.x * scalar;
		y = a.y + b.y * scalar;
		z = a.z + b.z * scalar;
	}

	// returns new instance of Vector2D
	constexpr inline vector_2d<T> AsVector2D() const
	{
		return { x, y };
	}

	// copy contents of our vector to an allocated array
	constexpr inline void CopyToArray(float* rgfl) const
	{
		rgfl[0] = x;
		rgfl[1] = y;
		rgfl[2] = z;
	}

	// 
	// Runtime helpers
	// 

	// checks if the vector contents is valid
	inline bool IsValid() const noexcept
	{
		return isfinite(x) && isfinite(y) && isfinite(z);
	}

	// returns length of the vector using sqrt
	inline auto Length() const noexcept
	{
		return static_cast<T>(sqrt(LengthSqr()));
	}

	// returns length of the 2D vector using sqrt
	inline auto Length2D() const noexcept
	{
		return static_cast<T>(sqrt(LengthSqr2D()));
	}

	// returns distance to the other vector
	inline auto Distance(const vector_3d& ToVector) const noexcept
	{
		return (ToVector - *this).Length();
	}

	// returns 2D distance to the other vector
	inline auto Distance2D(vector_3d& ToVector) const noexcept
	{
		return (ToVector - *this).Length2D();
	}

	// returns normalized vector, however does not modify it's members
	inline auto Normalize() const noexcept
	{
		T flLen = Length();

		if (flLen == 0.0)
			return vector_3d(0.0, 0.0, 1.0);

		flLen = 1.0 / flLen;
		return vector_3d(x * flLen, y * flLen, z * flLen);
	}

	inline auto NormalizeInPlace() noexcept
	{
		T flLen = Length();

		if (flLen == 0)
		{
			x = y = 0;
			z = 1;
			return flLen;
		}

		const T flInvertedLen = 1 / flLen;

		x *= flInvertedLen;
		y *= flInvertedLen;
		z *= flInvertedLen;

		return flLen;
	}

public:
	T x, y, z;
};

// for vec * float
// NOTE: has to be outside
template <VectorType T>
constexpr inline vector_3d<T> operator*(float p, const vector_3d<T>& v)
{
	return v * p;
};

} // namespace detail

//
// type declarations
//

using Vector2D = detail::vector_2d<float>;
using Vector = detail::vector_3d<float>;

template<typename T> using Vector2DT = detail::vector_2d<T>;
template<typename T> using VectorT = detail::vector_3d<T>;

#endif // VECTOR_CLASS_H