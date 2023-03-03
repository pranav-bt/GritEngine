#pragma once
#include <array>
#include "Vector4.h"
#include <math.h>
#include <cmath>
namespace GritEngine
{
	// A Matrix4 class that is mainly used for transforms and collision
	class Matrix 
	{
	private:
		float m11, m12, m13, m14,
			  m21, m22, m23, m24,
			  m31, m32, m33, m34,
			  m41, m42, m43, m44;
		Matrix();
		float MultiplyRowColumn(float r_1, float r_2, float r_3, float r_4, float c_1, float c_2, float c_3, float c_4) const;
		void MatrixFloatMultiply(float number);
		void InverseCalculations(Matrix& Temp) const;

	public:
		Matrix(float i11, float i12, float i13, float i14,
			float i21, float i22, float i23, float i24,
			float i31, float i32, float i33, float i34,
			float i41, float i42, float i43, float i44) :
			m11(i11), m12(i12), m13(i13), m14(i14),
			m21(i21), m22(i22), m23(i23), m24(i24),
			m31(i31), m32(i32), m33(i33), m34(i34),
			m41(i41), m42(i42), m43(i43), m44(i44)
			{};

		Matrix(const Matrix& other)
		{
			m11 = other.m11; 
			m12 = other.m12; 
			m13 = other.m13; 
			m14 = other.m14; 
			m21 = other.m21; 
			m22 = other.m22; 
			m23 = other.m23; 
			m24 = other.m24; 
			m31 = other.m31; 
			m32 = other.m32; 
			m33 = other.m33; 
			m34 = other.m34; 
			m41 = other.m41; 
			m42 = other.m42; 
			m43 = other.m43; 
			m44 = other.m44; 
		}
		
		Matrix& operator=(const Matrix & other);
		Matrix operator*(const Matrix& other);
		static Matrix CreateRotationX(float RadiansInX);
		static Matrix CreateRotationY(float RadiansInY);
		static Matrix CreateRotationZ(float RadiansInZ);
		static Matrix CreateTranslation(float x, float y, float z);
		static Matrix CreateScale(float scaleX, float scaleY, float scaleZ);
		static Matrix IdentityMatrix();
		void InvertMatrix();
		Matrix GetNewInvertMatrix() const;
		void TransposeMatrix();
		Matrix GetNewTransposeMatrix() const;
		Vector4 VectorLeftMulitply(const Vector4& other) const;
		Vector4 VectorRightMulitply(const Vector4& other) const;
	};


}