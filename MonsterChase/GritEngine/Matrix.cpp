#include "Matrix.h"
namespace GritEngine
{
	float Matrix::MultiplyRowColumn(float r_1, float r_2, float r_3, float r_4, float c_1, float c_2, float c_3, float c_4) const
	{
		float Answer;
		Answer = r_1 * c_1 + r_2 * c_2 + r_3 * c_3 + r_4 * c_4;
		return (float)Answer;
	}
	void Matrix::MatrixFloatMultiply(float number)
	{
		m11 = m11 * number;
		m12 = m12 * number;
		m13 = m13 * number;
		m14 = m14 * number;
		m21 = m21 * number;
		m22 = m22 * number;
		m23 = m23 * number;
		m24 = m24 * number;
		m31 = m31 * number;
		m32 = m32 * number;
		m33 = m33 * number;
		m34 = m34 * number;
		m41 = m41 * number;
		m42 = m42 * number;
		m43 = m43 * number;
		m44 = m44 * number;
	}
	void Matrix::InverseCalculations(Matrix& Temp) const
	{
		Temp.m11 = m22 * m33 * m44 -
			m22 * m34 * m43 -
			m32 * m23 * m44 +
			m32 * m24 * m43 +
			m42 * m23 * m34 -
			m42 * m24 * m33;

		Temp.m21 = -m21 * m33 * m44 +
			m21 * m34 * m43 +
			m31 * m23 * m44 -
			m31 * m24 * m43 -
			m41 * m23 * m34 +
			m41 * m24 * m33;

		Temp.m31 = m21 * m32 * m44 -
			m21 * m34 * m42 -
			m31 * m22 * m44 +
			m31 * m24 * m42 +
			m41 * m22 * m34 -
			m41 * m24 * m32;

		Temp.m41 = -m21 * m32 * m43 +
			m21 * m33 * m42 +
			m31 * m22 * m43 -
			m31 * m23 * m42 -
			m41 * m22 * m33 +
			m41 * m23 * m32;

		Temp.m21 = -m12 * m33 * m44 +
			m12 * m34 * m43 +
			m32 * m13 * m44 -
			m32 * m14 * m43 -
			m42 * m13 * m34 +
			m42 * m14 * m33;

		Temp.m22 = m11 * m33 * m44 -
			m11 * m34 * m43 -
			m31 * m13 * m44 +
			m31 * m14 * m43 +
			m41 * m13 * m34 -
			m41 * m14 * m33;

		Temp.m32 = -m11 * m32 * m44 +
			m11 * m34 * m42 +
			m31 * m12 * m44 -
			m31 * m14 * m42 -
			m41 * m12 * m34 +
			m41 * m14 * m32;

		Temp.m42 = m11 * m32 * m43 -
			m11 * m33 * m42 -
			m31 * m12 * m43 +
			m31 * m13 * m42 +
			m41 * m12 * m33 -
			m41 * m13 * m32;

		Temp.m13 = m12 * m23 * m44 -
			m12 * m24 * m43 -
			m22 * m13 * m44 +
			m22 * m14 * m43 +
			m42 * m13 * m24 -
			m42 * m14 * m23;

		Temp.m23 = -m11 * m23 * m44 +
			m11 * m24 * m43 +
			m21 * m13 * m44 -
			m21 * m14 * m43 -
			m41 * m13 * m24 +
			m41 * m14 * m23;

		Temp.m33 = m11 * m22 * m44 -
			m11 * m24 * m42 -
			m21 * m12 * m44 +
			m21 * m14 * m42 +
			m41 * m12 * m24 -
			m41 * m14 * m22;

		Temp.m43 = -m11 * m22 * m43 +
			m11 * m23 * m42 +
			m21 * m12 * m43 -
			m21 * m13 * m42 -
			m41 * m12 * m23 +
			m41 * m13 * m22;

		Temp.m14 = -m12 * m23 * m34 +
			m12 * m24 * m33 +
			m22 * m13 * m34 -
			m22 * m14 * m33 -
			m32 * m13 * m24 +
			m32 * m14 * m23;

		Temp.m24 = m11 * m23 * m34 -
			m11 * m24 * m33 -
			m21 * m13 * m34 +
			m21 * m14 * m33 +
			m31 * m13 * m24 -
			m31 * m14 * m23;

		Temp.m34 = -m11 * m22 * m34 +
			m11 * m24 * m32 +
			m21 * m12 * m34 -
			m21 * m14 * m32 -
			m31 * m12 * m24 +
			m31 * m14 * m22;

		Temp.m44 = m11 * m22 * m33 -
			m11 * m23 * m32 -
			m21 * m12 * m33 +
			m21 * m13 * m32 +
			m31 * m12 * m23 -
			m31 * m13 * m22;
	}

	Matrix& Matrix::operator=(const Matrix& other)
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
		return *this;
		
	}
	
	Matrix Matrix::operator*(const Matrix& other)
	{
		Matrix Multiplied = IdentityMatrix();
		Multiplied.m11 = MultiplyRowColumn(m11, m12, m13, m14, other.m11, other.m21, other.m31, other.m41);
		Multiplied.m12 = MultiplyRowColumn(m11, m12, m13, m14, other.m12, other.m22, other.m32, other.m42);
		Multiplied.m13 = MultiplyRowColumn(m11, m12, m13, m14, other.m13, other.m23, other.m33, other.m43);
		Multiplied.m14 = MultiplyRowColumn(m11, m12, m13, m14, other.m14, other.m24, other.m34, other.m44);
		Multiplied.m21 = MultiplyRowColumn(m21, m22, m23, m24, other.m11, other.m21, other.m31, other.m41);
		Multiplied.m22 = MultiplyRowColumn(m21, m22, m23, m24, other.m12, other.m22, other.m32, other.m42);
		Multiplied.m23 = MultiplyRowColumn(m21, m22, m23, m24, other.m13, other.m23, other.m33, other.m43);
		Multiplied.m24 = MultiplyRowColumn(m21, m22, m23, m24, other.m14, other.m24, other.m34, other.m44);
		Multiplied.m31 = MultiplyRowColumn(m31, m32, m33, m34, other.m11, other.m21, other.m31, other.m41);
		Multiplied.m32 = MultiplyRowColumn(m31, m32, m33, m34, other.m12, other.m22, other.m32, other.m42);
		Multiplied.m33 = MultiplyRowColumn(m31, m32, m33, m34, other.m13, other.m23, other.m33, other.m43);
		Multiplied.m34 = MultiplyRowColumn(m31, m32, m33, m34, other.m14, other.m24, other.m34, other.m44);
		Multiplied.m41 = MultiplyRowColumn(m41, m42, m43, m44, other.m11, other.m21, other.m31, other.m41);
		Multiplied.m42 = MultiplyRowColumn(m41, m42, m43, m44, other.m12, other.m22, other.m32, other.m42);
		Multiplied.m43 = MultiplyRowColumn(m41, m42, m43, m44, other.m13, other.m23, other.m33, other.m43);
		Multiplied.m44 = MultiplyRowColumn(m41, m42, m43, m44, other.m14, other.m24, other.m34, other.m44);
		return Multiplied;
	}
	Matrix Matrix::CreateRotationX(float RadiansInX)
	{
		Matrix RotX = IdentityMatrix();
		RotX.m22 = std::cos(RadiansInX);
		RotX.m23 = -(std::sin(RadiansInX));
		RotX.m32 = std::sin(RadiansInX);
		RotX.m33 = std::cos(RadiansInX);
		return RotX;
	}
	Matrix Matrix::CreateRotationY(float RadiansInY)
	{
		Matrix RotY = IdentityMatrix();
		RotY.m11 = std::cos(RadiansInY);
		RotY.m13 = std::sin(RadiansInY);
		RotY.m31 = -std::sin(RadiansInY);
		RotY.m33 = std::cos(RadiansInY);
		return RotY;
	}
	Matrix Matrix::CreateRotationZ(float RadiansInZ)
	{
		Matrix RotZ = IdentityMatrix();
		RotZ.m11 = std::cos(RadiansInZ);
		RotZ.m12 = -(std::sin(RadiansInZ));
		RotZ.m21 = std::sin(RadiansInZ);
		RotZ.m22 = std::cos(RadiansInZ);
		return RotZ;
	}
	Matrix Matrix::CreateTranslation(float x, float y, float z)
	{
		Matrix Translation = IdentityMatrix();
		Translation.m14 = x;
		Translation.m24 = y;
		Translation.m34 = z;
		return Translation;
	}
	Matrix Matrix::CreateScale(float scaleX, float scaleY, float scaleZ)
	{
		Matrix Scale = IdentityMatrix();
		Scale.m11 = scaleX;
		Scale.m22 = scaleY;
		Scale.m33 = scaleZ;
		return Scale;
	}
	Matrix Matrix::IdentityMatrix()
	{
		Matrix Identity = Matrix(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		return Identity;
	}
	void Matrix::InvertMatrix()
	{
		Matrix Temp = IdentityMatrix();
		this->InverseCalculations(Temp);

		float det = m11 * Temp.m11 + m12 * Temp.m21 + m13 * Temp.m31 + m14 * Temp.m41;

		if (det == 0)
			return;

		det = 1.0 / det;

		Temp.MatrixFloatMultiply(det);

		*this = Temp;
		//return true;
	}
	Matrix Matrix::GetNewInvertMatrix() const
	{
		Matrix Temp = IdentityMatrix();
		this->InverseCalculations(Temp);
		
		float det = m11 * Temp.m11 + m12 * Temp.m21 + m13 * Temp.m31 + m14 * Temp.m41;

		if (det == 0)
			return IdentityMatrix();

		det = 1.0 / det;

		Temp.MatrixFloatMultiply(det);
		return Temp;
	}
	void Matrix::TransposeMatrix()
	{
		std::swap(m12, m21);
		std::swap(m13, m31);
		std::swap(m14, m41);
		std::swap(m23, m32);
		std::swap(m24, m42);
		std::swap(m34, m43);
	}
	Matrix Matrix::GetNewTransposeMatrix() const
	{
		Matrix NewTranspose = *this;
		NewTranspose.TransposeMatrix();
		return NewTranspose;
	}
	Vector4 Matrix::VectorLeftMulitply(const Vector4& other) const
	{
		float i_w = other.GetW();
		float i_x = other.GetX();
		float i_y = other.GetY();
		float i_z = other.GetZ();
		float w = MultiplyRowColumn(i_w, i_x, i_y, i_z, m11, m21, m31, m41);
		float x = MultiplyRowColumn(i_w, i_x, i_y, i_z, m12, m22, m32, m42);
		float y = MultiplyRowColumn(i_w, i_x, i_y, i_z, m13, m23, m33, m43);
		float z = MultiplyRowColumn(i_w, i_x, i_y, i_z, m14, m24, m34, m44);
		Vector4 NewVector = Vector4(w, x, y, z);
		return NewVector;
	}
	Vector4 Matrix::VectorRightMulitply(const Vector4& other) const
	{
		float i_w = other.GetW();
		float i_x = other.GetX();
		float i_y = other.GetY();
		float i_z = other.GetZ();
		float w = MultiplyRowColumn(m11, m12, m13, m14, i_w, i_x, i_y, i_z);
		float x = MultiplyRowColumn(m21, m22, m23, m24, i_w, i_x, i_y, i_z);
		float y = MultiplyRowColumn(m31, m32, m33, m34, i_w, i_x, i_y, i_z);
		float z = MultiplyRowColumn(m41, m42, m43, m44, i_w, i_x, i_y, i_z);
		Vector4 NewVector = Vector4(w, x, y, z);
		return NewVector;
	}
}