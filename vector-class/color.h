//
// color.h -- simple color class
//

#ifndef COLOR_CLASS_H
#define COLOR_CLASS_H
#pragma once

#include <cmath>
#include <type_traits>

namespace detail
{

//
// type specification
//

template<typename T> concept ColorType = std::is_floating_point_v<T>;
template<typename T> concept ColorType255 = std::is_integral_v<T>;

//
// RGBA color container with [0.0, 1.0] ranged colors
//
template<ColorType T> requires(std::is_floating_point_v<T>)
class color
{
public:
	// 
	// Construction and destruction
	// 

	constexpr color() noexcept
	{
		set(0.0, 0.0, 0.0, 0.0);
	}
	constexpr color(T _r, T _g, T _b, T _a) noexcept
	{
		set(_r, _g, _b, _a);
	}

	// construct color from integral type
	template<typename U>
	inline static constexpr color construct_from_integral(U _r, U _g, U _b, U _a) noexcept
	{
		return
		{
			static_cast<T>(_r / 255.0),
			static_cast<T>(_g / 255.0),
			static_cast<T>(_b / 255.0),
			static_cast<T>(_a / 255.0),
		};
	}

	//
	// operators
	//

	inline bool operator==(const color& other) const noexcept
	{
		return (r == other.r && g == other.g && b == other.b && a == other.a);
	}

	inline bool operator!=(const color& other) const noexcept
	{
		return (r != other.r || g != other.g || b != other.b || a != other.a);
	}

	//
	// helpers
	//

	constexpr inline void set(T _r, T _g, T _b, T _a) noexcept
	{
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}

	constexpr inline uint32_t as_u32() const noexcept
	{
		uint32_t out;
		out = ((uint32_t)f32_to_int8_sat(r)) << 0;
		out |= ((uint32_t)f32_to_int8_sat(g)) << 8;
		out |= ((uint32_t)f32_to_int8_sat(b)) << 16;
		out |= ((uint32_t)f32_to_int8_sat(a)) << 24;
		return out;
	}

	constexpr inline bool is_nonzero() const
	{
		return r != 0.0 && g != 0.0 && b != 0.0 && a != 0.0;
	}

	constexpr inline bool is_nonzero_rgb() const
	{
		return r != 0.0 && g != 0.0 && b != 0.0;
	}

private:
	// Saturated, always output 0..255
	constexpr inline uint8_t f32_to_int8_sat(T clr) const
	{
		return ((int32_t)(saturate(clr) * 255.0 + 0.5));
	}

	constexpr inline T saturate(T f) const
	{
		return (f < 0.0) ? 0.0 : (f > 1.0) ? 1.0 : f;
	}

public:
	T r, g, b, a;
};

//
// RGBA color container with [0, 255] ranged colors
//
template<ColorType255 T> requires(std::is_integral_v<T>)
class color255
{
public:
	// 
	// Construction and destruction
	// 

	constexpr color255() noexcept
	{
		set(0, 0, 0, 0);
	}
	constexpr color255(T _r, T _g, T _b, T _a) noexcept
	{
		set(_r, _g, _b, _a);
	}

	// construct color from floating point type
	template<typename U>
	inline static constexpr color255 construct_from_floatingpoint(U _r, U _g, U _b, U _a) noexcept
	{
		return
		{
			static_cast<T>(_r * 255.0),
			static_cast<T>(_g * 255.0),
			static_cast<T>(_b * 255.0),
			static_cast<T>(_a * 255.0),
		};
	}

	//
	// operators
	//

	inline bool operator==(const color255& other) const noexcept
	{
		return (r == other.r && g == other.g && b == other.b && a == other.a);
	}

	inline bool operator!=(const color255& other) const noexcept
	{
		return (r != other.r || g != other.g || b != other.b || a != other.a);
	}

	//
	// helpers
	//

	constexpr inline void set(T _r, T _g, T _b, T _a) noexcept
	{
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}

	constexpr inline uint32_t as_u32() const noexcept
	{
		uint32_t out;
		out = r << 0;
		out |= g << 8;
		out |= b << 16;
		out |= a << 24;
		return out;
	}

	constexpr inline bool is_nonzero() const
	{
		return r != 0 && g != 0 && b != 0 && a != 0;
	}

	constexpr inline bool is_nonzero_rgb() const
	{
		return r != 0 && g != 0 && b != 0;
	}

public:
	T r, g, b, a;
};

} // namespace detail

//
// type declarations
//

using CColor = detail::color<float>;
using CColor255 = detail::color255<uint8_t>;

template<typename T> using CColorT = detail::color<T>;
template<typename T> using CColor255T = detail::color255<T>;

#endif // COLOR_CLASS_H