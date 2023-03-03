#include "Vector4.h"
namespace GritEngine
{
	Vector4 Vector4::operator+(Vector4& RHS)
	{
		return Vector4(w + RHS.w, x + RHS.x, y + RHS.y, z + RHS.z);
	}
	Vector4 Vector4::operator-(Vector4& RHS)
	{
		return Vector4(w - RHS.w, x - RHS.x, y - RHS.y, z - RHS.z);
	}
}