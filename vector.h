#ifndef VECTOR_H
#define VECTOR_H

#pragma once

//	C++17 constexpr support:
#if __cpp_constexpr >= 201907L
#	define CONSTEXPR constexpr
#else
#	define CONSTEXPR
#endif

//	C++20 concept support:
#ifndef __cpp_lib_concepts
#	include <concepts>
#endif

#ifdef __cpp_lib_concepts
#	if __cpp_lib_concepts >= 201907L
		template <typename T>
		concept ValidVecType = std::is_arithmetic<T>::value;
#	else
#		define ValidVecType typename
#	endif
#endif

template <ValidVecType T>
class vector_3d
{
public:
	/***	Construction
	**************************************************************/
	CONSTEXPR vector_3d() noexcept : x( 0.0 ), y( 0.0 ), z( 0.0 ) {}
	CONSTEXPR ~vector_3d() noexcept {}
	CONSTEXPR vector_3d( T X, T Y, T Z ) noexcept : x( X ), y( Y ), z( Z ) {}
	CONSTEXPR vector_3d( T* p ) noexcept { *this = p; };
	CONSTEXPR vector_3d( const vector_3d& in ) noexcept : x( in.x ), y( in.y ), z( in.z ) {}

	/***	Operator=
	**************************************************************/
	CONSTEXPR inline auto& operator=( const vector_3d& other ) noexcept
	{
		x = other.x;
		y = other.y;
		z = other.z;

		return *this;
	}

	CONSTEXPR inline auto& operator=( T* p ) noexcept
	{
		if (p)
		{
			x = p[0];
			y = p[1];
			z = p[2];
		} else
			x = y = z = 0.0;

		return *this;
	}

	CONSTEXPR inline auto& operator=( T f ) noexcept
	{
		x = y = z = f;

		return *this;
	}

	/***	Operator+=
	**************************************************************/
	CONSTEXPR inline auto& operator+=( const vector_3d& other ) noexcept
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	CONSTEXPR inline auto& operator+=( T* p ) noexcept
	{
		x += p[0];
		y += p[1];
		z += p[2];

		return *this;
	}

	CONSTEXPR inline auto& operator+=( T f ) noexcept
	{
		x += f;
		y += f;
		z += f;

		return *this;
	}

	/***	Operator-=
	**************************************************************/
	CONSTEXPR inline auto& operator-=( const vector_3d& other ) noexcept
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	CONSTEXPR inline auto& operator-=( T* p ) noexcept
	{
		x -= p[0];
		y -= p[1];
		z -= p[2];

		return *this;
	}

	CONSTEXPR inline auto& operator-=( T f ) noexcept
	{
		x -= f;
		y -= f;
		z -= f;

		return *this;
	}

	/***	Operator*=
	**************************************************************/
	CONSTEXPR inline auto& operator*=( const vector_3d& other ) noexcept
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	CONSTEXPR inline auto& operator*=( T* p ) noexcept
	{
		x *= p[0];
		y *= p[1];
		z *= p[2];

		return *this;
	}

	CONSTEXPR inline auto& operator*=( T f ) noexcept
	{
		x *= f;
		y *= f;
		z *= f;

		return *this;
	}

	/***	Operator/=
	**************************************************************/
	CONSTEXPR inline auto& operator/=( const vector_3d& other ) noexcept
	{
		if (other.x != 0.0 && other.y != 0.0 && other.z != 0.0)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
		}

		return *this;
	}

	CONSTEXPR inline auto& operator/=( T* p ) noexcept
	{
		if (p[0] != 0.0 && p[1] != 0.0 && p[2] != 0.0)
		{
			x /= p[0];
			y /= p[1];
			z /= p[2];
		}

		return *this;
	}

	CONSTEXPR inline auto& operator/=( T f ) noexcept
	{
		if (f != 0.0)
		{
			x /= f;
			y /= f;
			z /= f;
		}

		return *this;
	}

	/***	Operator+
	**************************************************************/
	CONSTEXPR inline auto operator+( const vector_3d& other ) const noexcept
	{
		return vector_3d( x + other.x, y + other.y, z + other.z );
	}

	CONSTEXPR inline auto operator+( T* p ) const noexcept
	{
		return vector_3d( x + p[0], y + p[1], z + p[2] );
	}

	CONSTEXPR inline auto operator+( T f ) const noexcept
	{
		return vector_3d( x + f, y + f, z + f );
	}

	/***	Operator-
	**************************************************************/
	CONSTEXPR inline auto operator-( const vector_3d& other ) const noexcept
	{
		return vector_3d( x - other.x, y - other.y, z - other.z );
	}

	CONSTEXPR inline auto operator-( T* p ) const noexcept
	{
		return vector_3d( x - p[0], y - p[1], z - p[2] );
	}

	CONSTEXPR inline auto operator-( T f ) const noexcept
	{
		return vector_3d( x - f, y - f, z - f );
	}

	CONSTEXPR inline auto operator-() const noexcept
	{
		return vector_3d( -x, -y, -z );
	}

	/***	Operator*
	**************************************************************/
	CONSTEXPR inline auto operator*( const vector_3d& other ) const noexcept
	{
		return vector_3d( x * other.x, y * other.y, z * other.z );
	}

	CONSTEXPR inline auto operator*( T* p ) const noexcept
	{
		return vector_3d( x * p[0], y * p[1], z * p[2] );
	}

	CONSTEXPR inline auto operator*( T f ) const noexcept
	{
		return vector_3d( x * f, y * f, z * f );
	}

	/***	Operator/
	**************************************************************/
	CONSTEXPR inline auto operator/( const vector_3d& other ) const noexcept
	{
		if (other.x != 0.0 && other.y != 0.0 && other.z != 0.0)
			return vector_3d( x / other.x, y / other.y, z / other.z );

		return *this;
	}

	CONSTEXPR inline auto operator/( T* p ) const noexcept
	{
		if (p[0] != 0.0 && p[1] != 0.0 && p[2] != 0.0)
			return vector_3d( x / p[0], y / p[1], z / p[2] );

		return *this;
	}

	CONSTEXPR inline auto operator/( T f ) const noexcept
	{
		if (f != 0.0)
			return vector_3d( x / f, y / f, z / f );

		return *this;
	}

	/***	Operator[]
	**************************************************************/
	CONSTEXPR inline auto& operator[]( uint32_t i ) const noexcept
	{
		if (i >= 0 && i < 3)
			return ((T*)this)[i];

		return ((T*)this)[0];
	}

	/***	Boolean operators
	**************************************************************/
	CONSTEXPR inline bool operator!() const noexcept
	{
		return IsZero();
	}

	CONSTEXPR inline bool operator==( const vector_3d& other ) const noexcept
	{
		return x == other.x && y == other.y && z == other.z;
	}

	CONSTEXPR inline bool operator!=( const vector_3d& other ) const noexcept
	{
		return x != other.x || y != other.y || z != other.z;
	}

	/***	Other operators
	**************************************************************/
	CONSTEXPR inline operator auto() noexcept
	{
		return &x;
	}
	CONSTEXPR inline operator const auto() const noexcept
	{
		return &x;
	}

	/***	Helper constexpr functions
	**************************************************************/
	CONSTEXPR inline bool IsZero() const noexcept
	{
		return x == 0.0 && y == 0.0 && z == 0.0;
	}

	CONSTEXPR inline bool IsZero2D() const noexcept
	{
		return x == 0.0 && y == 0.0;
	}

	CONSTEXPR inline auto& Clear() noexcept
	{
		x = y = z = 0.0;

		return *this;
	}

	CONSTEXPR inline auto& Negate() noexcept
	{
		x = -x;
		y = -y;
		z = -z;

		return *this;
	}

	CONSTEXPR inline auto Dot( const vector_3d& other ) const noexcept
	{
		return x * other.x + y * other.y + z * other.z;
	}

	CONSTEXPR inline auto Dot2D( const vector_3d& other ) const noexcept
	{
		return x * other.x + y * other.y;
	}

	CONSTEXPR inline auto LengthSqr() const noexcept
	{
		return x * x + y * y + z * z;
	}

	CONSTEXPR inline auto LengthSqr2D() const noexcept
	{
		return x * x + y * y;
	}

	CONSTEXPR inline auto& CrossProduct( const vector_3d& a, const vector_3d& b ) noexcept
	{
		x = (a.y * b.z) - (a.z * b.y);
		y = (a.z * b.x) - (a.x * b.z);
		z = (a.x * b.y) - (a.y * b.x);

		return *this;
	}

	/***	Helper runtime functions
	**************************************************************/
	inline bool IsValid() const noexcept
	{
		return isfinite( x ) && isfinite( y ) && isfinite( z );
	}

	inline auto Length() const noexcept
	{
		return (T)std::sqrt( LengthSqr() );
	}

	inline auto Length2D() const noexcept
	{
		return (T)std::sqrt( LengthSqr2D() );
	}

	inline auto Distance( const vector_3d& ToVector ) const noexcept
	{
		return (ToVector - *this).Length();
	}

	inline auto Distance2D( vector_3d& ToVector ) const noexcept
	{
		return (ToVector - *this).Length2D();
	}

	inline auto Normalized() const noexcept
	{
		T flLen = Length();

		if (flLen == 0.0)
			return vector_3d( 0.0, 0.0, 1.0 );

		flLen = 1.0 / flLen;
		return vector_3d( x * flLen, y * flLen, z * flLen );
	}

	inline auto Normalize() noexcept
	{
		T RecipLength, VectorLength;

		VectorLength = Length();

		if (VectorLength != 0.0)
		{
			RecipLength = 1.0 / VectorLength;

			x *= RecipLength;
			y *= RecipLength;
			z *= RecipLength;
		}

		return VectorLength;
	}

	inline auto Normalize2D() noexcept
	{
		T Length = LengthSqr2D();
		T RecipLength;

		if (Length != 0.0)
		{
			RecipLength = 1.0 / Length;

			x *= RecipLength;
			y *= RecipLength;
		}

		return Length;
	}

	inline auto AngleBetween( vector_3d& other ) const noexcept
	{
		other.Normalize();
		Normalize();

		return (T)std::acos( Dot( other ) ) * static_cast<T>(180.0 / 3.14159265358979323846);
	}

	inline void VectorVectors( vector_3d& Right, vector_3d& Up ) const noexcept
	{
		if (IsZero2D())
		{
			Right = { 1.0 };
			Right = { -z, 0.0, 0.0 };
		} else
		{
			vector_3d tmp = {};
			CrossProduct( tmp, Right );

			Right.Normalize();

			Right.CrossProduct( *this, Up );

			Up.Normalize();
		}
	}

public:
	T x, y, z;
};

template <ValidVecType T> CONSTEXPR inline vector_3d<T> operator*( T fl, const vector_3d<T>& v )
{
	return v * fl;
};

template <ValidVecType T>
class vector_2d
{
public:
	/***	Construction
	**************************************************************/
	CONSTEXPR vector_2d() noexcept : x(0.0), y(0.0) {}
	CONSTEXPR ~vector_2d() noexcept {}
	CONSTEXPR vector_2d(T X, T Y) noexcept : x(X), y(Y) {}
	CONSTEXPR vector_2d(T* p) noexcept { *this = p; };
	CONSTEXPR vector_2d(const vector_2d& in) noexcept : x(in.x), y(in.y) {}

	/***	Operator=
	**************************************************************/
	CONSTEXPR inline auto& operator=(const vector_2d& other) noexcept
	{
		x = other.x;
		y = other.y;

		return *this;
	}

	CONSTEXPR inline auto& operator=(T* p) noexcept
	{
		if (p)
		{
			x = p[0];
			y = p[1];
		} 		else
			x = y = 0.0;

		return *this;
	}

	CONSTEXPR inline auto& operator=(T f) noexcept
	{
		x = y = f;

		return *this;
	}

	/***	Operator+=
	**************************************************************/
	CONSTEXPR inline auto& operator+=(const vector_2d& other) noexcept
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	CONSTEXPR inline auto& operator+=(T* p) noexcept
	{
		x += p[0];
		y += p[1];

		return *this;
	}

	CONSTEXPR inline auto& operator+=(T f) noexcept
	{
		x += f;
		y += f;

		return *this;
	}

	/***	Operator-=
	**************************************************************/
	CONSTEXPR inline auto& operator-=(const vector_2d& other) noexcept
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}

	CONSTEXPR inline auto& operator-=(T* p) noexcept
	{
		x -= p[0];
		y -= p[1];

		return *this;
	}

	CONSTEXPR inline auto& operator-=(T f) noexcept
	{
		x -= f;
		y -= f;

		return *this;
	}

	/***	Operator*=
	**************************************************************/
	CONSTEXPR inline auto& operator*=(const vector_2d& other) noexcept
	{
		x *= other.x;
		y *= other.y;

		return *this;
	}

	CONSTEXPR inline auto& operator*=(T* p) noexcept
	{
		x *= p[0];
		y *= p[1];

		return *this;
	}

	CONSTEXPR inline auto& operator*=(T f) noexcept
	{
		x *= f;
		y *= f;

		return *this;
	}

	/***	Operator/=
	**************************************************************/
	CONSTEXPR inline auto& operator/=(const vector_2d& other) noexcept
	{
		if (other.x != 0.0 && other.y != 0.0)
		{
			x /= other.x;
			y /= other.y;
		}

		return *this;
	}

	CONSTEXPR inline auto& operator/=(T* p) noexcept
	{
		if (p[0] != 0.0 && p[1] != 0.0)
		{
			x /= p[0];
			y /= p[1];
		}

		return *this;
	}

	CONSTEXPR inline auto& operator/=(T f) noexcept
	{
		if (f != 0.0)
		{
			x /= f;
			y /= f;
		}

		return *this;
	}

	/***	Operator+
	**************************************************************/
	CONSTEXPR inline auto operator+(const vector_2d& other) const noexcept
	{
		return vector_2d(x + other.x, y + other.y);
	}

	CONSTEXPR inline auto operator+(T* p) const noexcept
	{
		return vector_2d(x + p[0], y + p[1]);
	}

	CONSTEXPR inline auto operator+(T f) const noexcept
	{
		return vector_2d(x + f, y + f);
	}

	/***	Operator-
	**************************************************************/
	CONSTEXPR inline auto operator-(const vector_2d& other) const noexcept
	{
		return vector_2d(x - other.x, y - other.y);
	}

	CONSTEXPR inline auto operator-(T* p) const noexcept
	{
		return vector_2d(x - p[0], y - p[1]);
	}

	CONSTEXPR inline auto operator-(T f) const noexcept
	{
		return vector_2d(x - f, y - f);
	}

	CONSTEXPR inline auto operator-() const noexcept
	{
		return vector_2d(-x, -y);
	}

	/***	Operator*
	**************************************************************/
	CONSTEXPR inline auto operator*(const vector_2d& other) const noexcept
	{
		return vector_2d(x * other.x, y * other.y);
	}

	CONSTEXPR inline auto operator*(T* p) const noexcept
	{
		return vector_2d(x * p[0], y * p[1]);
	}

	CONSTEXPR inline auto operator*(T f) const noexcept
	{
		return vector_2d(x * f, y * f);
	}

	/***	Operator/
	**************************************************************/
	CONSTEXPR inline auto operator/(const vector_2d& other) const noexcept
	{
		if (other.x != 0.0 && other.y != 0.0)
			return vector_2d(x / other.x, y / other.y);

		return *this;
	}

	CONSTEXPR inline auto operator/(T* p) const noexcept
	{
		if (p[0] != 0.0 && p[1] != 0.0)
			return vector_2d(x / p[0], y / p[1]);

		return *this;
	}

	CONSTEXPR inline auto operator/(T f) const noexcept
	{
		if (f != 0.0)
			return vector_2d(x / f, y / f);

		return *this;
	}

	/***	Operator[]
	**************************************************************/
	CONSTEXPR inline auto& operator[](uint32_t i) const noexcept
	{
		if (i >= 0 && i < 2)
			return ((T*)this)[i];

		return ((T*)this)[0];
	}

	/***	Boolean operators
	**************************************************************/
	CONSTEXPR inline bool operator!() const noexcept
	{
		return IsZero();
	}

	CONSTEXPR inline bool operator==(const vector_2d& other) const noexcept
	{
		return x == other.x && y == other.y;
	}

	CONSTEXPR inline bool operator!=(const vector_2d& other) const noexcept
	{
		return x != other.x || y != other.y;
	}

	/***	Other operators
	**************************************************************/
	CONSTEXPR inline operator auto() noexcept
	{
		return &x;
	}
	CONSTEXPR inline operator const auto() const noexcept
	{
		return &x;
	}

	/***	Helper constexpr functions
	**************************************************************/
	CONSTEXPR inline bool IsZero() const noexcept
	{
		return x == 0.0 && y == 0.0;
	}

	CONSTEXPR inline auto& Clear() noexcept
	{
		x = y = 0.0;

		return *this;
	}

	CONSTEXPR inline auto& Negate() noexcept
	{
		x = -x;
		y = -y;

		return *this;
	}

	CONSTEXPR inline auto Dot(const vector_2d& other) const noexcept
	{
		return x * other.x + y * other.y;
	}

	CONSTEXPR inline auto LengthSqr() const noexcept
	{
		return x * x + y * y;
	}

	/***	Helper non-constexpr functions
	**************************************************************/
	inline bool IsValid() const noexcept
	{
		return isfinite(x) && isfinite(y);
	}

	inline auto Length() const noexcept
	{
		return (T)std::sqrt(LengthSqr());
	}

	inline auto Distance(const vector_2d& ToVector) const noexcept
	{
		return (ToVector - *this).Length();
	}

	inline auto Normalized() const noexcept
	{
		T flLen = Length();

		if (flLen == 0.0)
			return vector_2d(0.0, 0.0);

		flLen = 1.0 / flLen;
		return vector_2d(x * flLen, y * flLen);
	}

	inline auto Normalize() noexcept
	{
		T Length = LengthSqr();
		T RecipLength;

		if (Length != 0.0)
		{
			RecipLength = 1.0 / Length;

			x *= RecipLength;
			y *= RecipLength;
		}

		return Length;
	}

	inline auto AngleBetween(vector_2d& other) const noexcept
	{
		other.Normalize();
		Normalize();

		return (T)std::acos(Dot(other)) * static_cast<T>(180.0 / 3.14159265358979323846);
	}

public:
	T x, y;
};

template <ValidVecType T> CONSTEXPR inline vector_2d<T> operator*(T fl, const vector_2d<T>& v)
{
	return v * fl;
};

using Vector = vector_3d<float>;
using Vector2D = vector_2d<float>;

#endif