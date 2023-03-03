#pragma once
namespace GritEngine
{
	class Vector4
	{
	private:
		
	public:
		float x, y, z, w;
		Vector4(float i_x, float i_y, float i_z, float i_w) { w = i_w; x = i_x; y = i_y; z = i_z; };
		Vector4 operator+(Vector4& RHS);
		Vector4 operator-(Vector4& RHS);
		//getters
		float GetW() const
		{
			return w;
		}
		float GetX() const
		{
			return x;
		}
		float GetY() const 
		{
			return y;
		}
		float GetZ() const 
		{
			return z;
		}
	};
}