#ifndef VECTOR_H
#define VECTOR_H

#pragma once

template <typename T>
class vector_3d
{
public:
	/*
	*	constructor / destructor
	**/
	constexpr vector_3d() : x(0.0), y(0.0), z(0.0) {}
	constexpr ~vector_3d() {}
	constexpr vector_3d(T X, T Y, T Z) : x(X), y(Y), z(Z) {}
	constexpr vector_3d(T* p) { *this = p; };
	constexpr vector_3d(const vector_3d& in) : x(in.x), y(in.x), z(in.x) {}

	/*
	*	operator =
	**/
	constexpr inline auto& operator=(const vector_3d& in)
	{
		x = in.x;
		y = in.y;
		z = in.z;

		return *this;
	}

	constexpr inline auto& operator=(T* p)
	{
		if (p)
		{
			x = p[0];
			y = p[1];
			z = p[2];
		} 		else
			x = y = z = 0.0;

		return *this;
	}

	constexpr inline auto& operator=(T f)
	{
		x = y = z = f;

		return *this;
	}

	/*
	 *	operator +=
	**/
	constexpr inline auto& operator+=(const vector_3d& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	constexpr inline auto& operator+=(T* p)
	{
		x += p[0];
		y += p[1];
		z += p[2];

		return *this;
	}

	constexpr inline auto& operator+=(T f)
	{
		x += f;
		y += f;
		z += f;

		return *this;
	}

	/*
	 *	operator -=
	**/
	constexpr inline auto& operator-=(const vector_3d& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	constexpr inline auto& operator-=(T* p)
	{
		x -= p[0];
		y -= p[1];
		z -= p[2];

		return *this;
	}

	constexpr inline auto& operator-=(T f)
	{
		x -= f;
		y -= f;
		z -= f;

		return *this;
	}

	/*
	 *	operator *=
	**/
	constexpr inline auto& operator*=(const vector_3d& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	constexpr inline auto& operator*=(T* p)
	{
		x *= p[0];
		y *= p[1];
		z *= p[2];

		return *this;
	}

	constexpr inline auto& operator*=(T f)
	{
		x *= f;
		y *= f;
		z *= f;

		return *this;
	}

	/*
	 *	operator /=
	**/
	constexpr inline auto& operator/=(const vector_3d& other)
	{
		if (other.x != 0.0 && other.y != 0.0 && other.z != 0.0)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
		}

		return *this;
	}

	constexpr inline auto& operator/=(T* p)
	{
		if (p[0] != 0.0 && p[1] != 0.0 && p[2] != 0.0)
		{
			x /= p[0];
			y /= p[1];
			z /= p[2];
		}

		return *this;
	}

	constexpr inline auto& operator/=(T f)
	{
		if (f != 0.0)
		{
			x /= f;
			y /= f;
			z /= f;
		}

		return *this;
	}

	/*
	 *	operator +=
	**/
	constexpr inline auto operator+(const vector_3d& other) const
	{
		return vector_3d(x + other.x, y + other.y, z + other.z);
	}

	constexpr inline auto operator+(T* p) const
	{
		return vector_3d(x + p[0], y + p[1], z + p[2]);
	}

	constexpr inline auto operator+(T f) const
	{
		return vector_3d(x + f, y + f, z + f);
	}

	/*
	 *	operator -
	**/
	constexpr inline auto operator-(const vector_3d& other) const
	{
		return vector_3d(x - other.x, y - other.y, z - other.z);
	}

	constexpr inline auto operator-(T* p) const
	{
		return vector_3d(x - p[0], y - p[1], z - p[2]);
	}

	constexpr inline auto operator-(T f) const
	{
		return vector_3d(x - f, y - f, z - f);
	}

	constexpr inline auto operator-() const
	{
		return vector_3d(-x, -y, -z);
	}

	/*
	 *	operator *
	**/
	constexpr inline auto operator*(const vector_3d& other) const
	{
		return vector_3d(x * other.x, y * other.y, z * other.z);
	}

	constexpr inline auto operator*(T* p) const
	{
		return vector_3d(x * p[0], y * p[1], z * p[2]);
	}

	constexpr inline auto operator*(T f) const
	{
		return vector_3d(x * f, y * f, z * f);
	}

	/*
	 *	operator /
	**/
	constexpr inline auto operator/(const vector_3d& other) const
	{
		if (other.x != 0.0 && other.y != 0.0 && other.z != 0.0)
			return vector_3d(x / other.x, y / other.y, z / other.z);

		return *this;
	}

	constexpr inline auto operator/(T* p) const
	{
		if (p[0] != 0.0 && p[1] != 0.0 && p[2] != 0.0)
			return vector_3d(x / p[0], y / p[1], z / p[2]);

		return *this;
	}

	constexpr inline auto operator/(T f) const
	{
		if (f != 0.0)
			return vector_3d(x / f, y / f, z / f);

		return *this;
	}

	/*
	*	array access
	**/
	constexpr inline auto& operator[](uint32_t i) const
	{
		if (i >= 0 && i < 3)
			return ((T*)this)[i];

		return ((T*)this)[0];
	}

	/*
	*	boolean operators
	**/
	constexpr inline bool operator!() const
	{
		return IsZero();
	}

	constexpr inline bool operator==(const vector_3d& other) const
	{
		return x == other.x && y == other.y && z == other.z;
	}

	constexpr inline bool operator!=(const vector_3d& other) const
	{
		return x != other.x || y != other.y || z != other.z;
	}

	/*
	 *	return itself
	**/
	constexpr inline operator auto()
	{
		return &x;
	}
	constexpr inline operator const auto() const
	{
		return &x;
	}

	/*
	 *	Constexpr helper members
	**/
	constexpr inline bool IsZero() const
	{
		return x == 0.0 && y == 0.0 && z == 0.0;
	}

	constexpr inline bool IsZero2D() const
	{
		return x == 0.0 && y == 0.0;
	}

	inline bool IsValid() const
	{
		return isfinite(x) && isfinite(y) && isfinite(z);
	}

	constexpr inline auto& Clear()
	{
		x = y = z = 0.0;

		return *this;
	}

	constexpr inline auto& Negate()
	{
		x = -x;
		y = -y;
		z = -z;

		return *this;
	}

	constexpr inline auto Dot(const vector_3d& other) const noexcept
	{
		return x * other.x + y * other.y + z * other.z;
	}

	constexpr inline auto Dot2D(const vector_3d& other) const noexcept
	{
		return x * other.x + y * other.y;
	}

	constexpr inline auto LengthSqr() const noexcept
	{
		return x * x + y * y + z * z;
	}

	constexpr inline auto LengthSqr2D() const noexcept
	{
		return x * x + y * y;
	}

	inline constexpr auto& CrossProduct(const vector_3d& a, const vector_3d& b)
	{
		x = (a.y * b.z) - (a.z * b.y);
		y = (a.z * b.x) - (a.x * b.z);
		z = (a.x * b.y) - (a.y * b.x);

		return *this;
	}

	/*
	 *	Non-constexpr helper members
	**/
	inline auto Length() const noexcept
	{
		return (T)std::sqrt(LengthSqr());
	}

	inline auto Length2D() const noexcept
	{
		return (T)std::sqrt(LengthSqr2D());
	}

	inline auto Distance(const vector_3d& ToVector) const noexcept
	{
		return (ToVector - *this).Length();
	}

	inline auto Distance2D(vector_3d& ToVector) const noexcept
	{
		return (ToVector - *this).Length2D();
	}

	inline auto Normalized() const noexcept
	{
		T flLen = Length();

		if (flLen == 0.0)
			return vector_3d(0.0, 0.0, 1.0);

		flLen = 1.0 / flLen;
		return vector_3d(x * flLen, y * flLen, z * flLen);
	}

	inline auto Normalize()
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

	inline auto Normalize2D()
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

	inline auto AngleBetween(vector_3d& other) const noexcept
	{
		other.Normalize();
		Normalize();

		return (T)std::acos(Dot(other)) * static_cast<T>(180.0 / 3.14159265358979323846);
	}

	inline void VectorVectors(vector_3d& Right, vector_3d& Up) const
	{
		if (IsZero2D())
		{
			Right = { 1.0 };
			Right = { -z, 0.0, 0.0 };
		} 		else
		{
			vector_3d tmp = {};
			CrossProduct(tmp, Right);

			Right.Normalize();

			Right.CrossProduct(*this, Up);

			Up.Normalize();
		}
	}

public:
	T x, y, z;
};

template <typename T> constexpr inline vector_3d<T> operator*(T fl, const vector_3d<T>& v) 
{ 
	return v * fl; 
};

template <typename T>
class vector_2d
{
public:
	/*
	*	constructor / destructor
	**/
	constexpr vector_2d() : x(0.0), y(0.0) {}
	constexpr ~vector_2d() {}
	constexpr vector_2d(T X, T Y) : x(X), y(Y) {}
	constexpr vector_2d(T* p) { *this = p; };
	constexpr vector_2d(const vector_2d& in) : x(in.x), y(in.x) {}

	/*
	*	operator =
	**/
	constexpr inline auto& operator=(const vector_2d& in)
	{
		x = in.x;
		y = in.y;

		return *this;
	}

	constexpr inline auto& operator=(T* p)
	{
		if (p)
		{
			x = p[0];
			y = p[1];
		} 		else
			x = y = 0.0;

		return *this;
	}

	constexpr inline auto& operator=(T f)
	{
		x = y = f;

		return *this;
	}

	/*
	 *	operator +=
	**/
	constexpr inline auto& operator+=(const vector_2d& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	constexpr inline auto& operator+=(T* p)
	{
		x += p[0];
		y += p[1];

		return *this;
	}

	constexpr inline auto& operator+=(T f)
	{
		x += f;
		y += f;

		return *this;
	}

	/*
	 *	operator -=
	**/
	constexpr inline auto& operator-=(const vector_2d& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}

	constexpr inline auto& operator-=(T* p)
	{
		x -= p[0];
		y -= p[1];

		return *this;
	}

	constexpr inline auto& operator-=(T f)
	{
		x -= f;
		y -= f;

		return *this;
	}

	/*
	 *	operator *=
	**/
	constexpr inline auto& operator*=(const vector_2d& other)
	{
		x *= other.x;
		y *= other.y;

		return *this;
	}

	constexpr inline auto& operator*=(T* p)
	{
		x *= p[0];
		y *= p[1];

		return *this;
	}

	constexpr inline auto& operator*=(T f)
	{
		x *= f;
		y *= f;

		return *this;
	}

	/*
	 *	operator /=
	**/
	constexpr inline auto& operator/=(const vector_2d& other)
	{
		if (other.x != 0.0 && other.y != 0.0)
		{
			x /= other.x;
			y /= other.y;
		}

		return *this;
	}

	constexpr inline auto& operator/=(T* p)
	{
		if (p[0] != 0.0 && p[1] != 0.0)
		{
			x /= p[0];
			y /= p[1];
		}

		return *this;
	}

	constexpr inline auto& operator/=(T f)
	{
		if (f != 0.0)
		{
			x /= f;
			y /= f;
		}

		return *this;
	}

	/*
	 *	operator +=
	**/
	constexpr inline auto operator+(const vector_2d& other) const
	{
		return vector_2d(x + other.x, y + other.y);
	}

	constexpr inline auto operator+(T* p) const
	{
		return vector_2d(x + p[0], y + p[1]);
	}

	constexpr inline auto operator+(T f) const
	{
		return vector_2d(x + f, y + f);
	}

	/*
	 *	operator -
	**/
	constexpr inline auto operator-(const vector_2d& other) const
	{
		return vector_2d(x - other.x, y - other.y);
	}

	constexpr inline auto operator-(T* p) const
	{
		return vector_2d(x - p[0], y - p[1]);
	}

	constexpr inline auto operator-(T f) const
	{
		return vector_2d(x - f, y - f);
	}

	constexpr inline auto operator-() const
	{
		return vector_2d(-x, -y);
	}

	/*
	 *	operator *
	**/
	constexpr inline auto operator*(const vector_2d& other) const
	{
		return vector_2d(x * other.x, y * other.y);
	}

	constexpr inline auto operator*(T* p) const
	{
		return vector_2d(x * p[0], y * p[1]);
	}

	constexpr inline auto operator*(T f) const
	{
		return vector_2d(x * f, y * f);
	}

	/*
	 *	operator /
	**/
	constexpr inline auto operator/(const vector_2d& other) const
	{
		if (other.x != 0.0 && other.y != 0.0)
			return vector_2d(x / other.x, y / other.y);

		return *this;
	}

	constexpr inline auto operator/(T* p) const
	{
		if (p[0] != 0.0 && p[1] != 0.0)
			return vector_2d(x / p[0], y / p[1]);

		return *this;
	}

	constexpr inline auto operator/(T f) const
	{
		if (f != 0.0)
			return vector_2d(x / f, y / f);

		return *this;
	}

	/*
*	array access
**/
	constexpr inline auto& operator[](uint32_t i) const
	{
		if (i >= 0 && i < 2)
			return ((T*)this)[i];

		return ((T*)this)[0];
	}

	/*
	*	boolean operators
	**/
	constexpr inline bool operator!() const
	{
		return IsZero();
	}

	constexpr inline bool operator==(const vector_2d& other) const
	{
		return x == other.x && y == other.y;
	}

	constexpr inline bool operator!=(const vector_2d& other) const
	{
		return x != other.x || y != other.y;
	}

	/*
	 *	return itself
	**/
	constexpr inline operator auto()
	{
		return &x;
	}
	constexpr inline operator const auto() const
	{
		return &x;
	}

	/*
	 *	Constexpr helper members
	**/
	constexpr inline bool IsZero() const
	{
		return x == 0.0 && y == 0.0;
	}

	inline bool IsValid() const
	{
		return isfinite(x) && isfinite(y);
	}

	constexpr inline auto& Clear()
	{
		x = y = 0.0;

		return *this;
	}

	constexpr inline auto& Negate()
	{
		x = -x;
		y = -y;

		return *this;
	}

	constexpr inline auto Dot(const vector_2d& other) const noexcept
	{
		return x * other.x + y * other.y;
	}

	constexpr inline auto LengthSqr() const noexcept
	{
		return x * x + y * y;
	}

	/*
	 *	Non-constexpr helper members
	**/
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

	inline auto Normalize()
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

template <typename T> constexpr inline vector_2d<T> operator*(T fl, const vector_2d<T>& v)
{
	return v * fl;
};

#define vec3_t vector_3d<float>

using Vector = vector_3d<float>;
using Vector2D = vector_2d<float>;

#endif