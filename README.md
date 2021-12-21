# vector-class
A simple class which takes care of simple 3D&2D Vector math. 

# Features
- Operators overloaded: `=`, `+=`, `-=`, `*=`, `/=`, `+`, `-`, `*`, `/`, `[]`, `!`, `==`, `!=`, `()`
- Helper functions such as: 
  - `IsZero`, `IsValid`
  - `Clear`, `Negate`
  - `Dot`, `CrossProduct`, `Normalize`
  - `Length`, `Distance`
  - etc...
- All members possible all `constexpr`.
- `c++20 concepts` are used for type safety.

# How to use
- There are two predefined types: 
  - `Vector` being vector_3d< float >
  - `Vector2D` being vector_2d< float >

# Example
```c++
Vector v3d(0.0f, 0.0f, 0.0f);
Vector2D v2d(0.0f, 0.0f);
```
