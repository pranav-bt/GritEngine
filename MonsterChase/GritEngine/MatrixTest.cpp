//#include "Matrix.h"
//
//#include <assert.h>
//namespace GritEngine
//{
//	float r()
//	{
//		return rand() % 100;
//	}
//	void MatrixTest(int testcases)
//	{
//		for (int count = 0; count < testcases; count++)
//		{
//			Eigen::MatrixXd EigenMatrix(4, 4);
//			float a = r();
//			float b = r();
//			float c = r();
//			float d = r();
//			float e = r();
//			float f = r();
//			float g = r();
//			float h = r();
//			float i = r();
//			float j = r();
//			float k = r();
//			float l = r();
//			float m = r();
//			float n = r();
//			float o = r();
//			float p = r();
//			EigenMatrix << a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
//			Matrix GritEngineMatrix(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);
//			//Make Sure Matrices are equal before the test
//			bool eq = GritEngineMatrix == EigenMatrix;
//			assert(eq);
//
//			//inverse test on matrices
//			bool invtest = GritEngineMatrix.GetNewInvertMatrix() == EigenMatrix.inverse();
//			assert(invtest);
//
//			//transpose test matrices
//			bool transposetest = GritEngineMatrix.GetNewTransposeMatrix() == EigenMatrix.transpose();
//			assert(transposetest);
//
//			//scaling test
//			auto scale3d = Eigen::Scaling<double>(1, 2, 3).toDenseMatrix();
//			Eigen::Matrix4d Scale;
//			Scale.setIdentity();
//			Scale.block<3, 3>(0, 0) = scale3d;
//			EigenMatrix = EigenMatrix * Scale;
//			GritEngineMatrix = GritEngineMatrix * Matrix::CreateScale(1, 2, 3);
//			bool scalingtest = GritEngineMatrix == EigenMatrix;
//			assert(scalingtest);
//
//			//Translation test
//			Eigen::Vector3d T;
//			T << 2, 2, 2;
//			Eigen::Matrix4d Trans; // Eigen Transformation Matrix
//			Trans.setIdentity();
//			Trans.block<3, 1>(0, 3) = T;
//			EigenMatrix = EigenMatrix * Trans;
//			GritEngineMatrix = GritEngineMatrix * Matrix::CreateTranslation(2, 2, 2);
//			bool translationtest = GritEngineMatrix == EigenMatrix;
//			assert(translationtest);
//
//			//Vector Right multiply test
//			Eigen::Vector4d ver(2, 3, 4, 1);
//			Eigen::Vector4d vectoreigen = EigenMatrix * ver;
//			Vector4 vpr(2, 3, 4, 1);
//			Vector4 vectorpranavr = GritEngineMatrix.VectorRightMulitply(vpr);
//			bool vectorrightmultest = vectorpranavr == vectoreigen;
//			assert(vectorrightmultest);
//
//			//Vector Left multiply test
//			Eigen::Matrix<double, 1, 4> vel(2, 3, 4, 1);
//			auto vectoreigenl = vel * (Eigen::Matrix4d)EigenMatrix;
//			Vector4 vpl(2, 3, 4, 1);
//			Vector4 vectorpranavl = GritEngineMatrix.VectorLeftMulitply(vpl);
//			bool vectorleftmultest = vectorpranavl == vectoreigenl;
//			assert(vectorleftmultest);
//
//			//Rotation Test
//			Eigen::Matrix3d RotationMatrix;
//			Eigen::AngleAxisd xangle(0.25 * 22 / 7, Eigen::Vector3d::UnitX());
//			Eigen::AngleAxisd yangle(0.25 * 22 / 7, Eigen::Vector3d::UnitY());
//			Eigen::AngleAxisd zangle(0.25 * 22 / 7, Eigen::Vector3d::UnitZ());
//			Eigen::Quaternion<double> Q = zangle * yangle * xangle;
//			RotationMatrix = Q.matrix();
//			Eigen::Matrix4d TransRot; // Eigen Transformation Matrix
//			TransRot.setIdentity();
//			TransRot.block<3, 3>(0, 0) = RotationMatrix;
//			EigenMatrix = EigenMatrix * TransRot;
//			auto MatrixPranavRotation = Matrix::CreateRotationZ(0.25 * 22 / 7) * Matrix::CreateRotationY(0.25 * 22 / 7) * Matrix::CreateRotationX(0.25 * 22 / 7);
//			GritEngineMatrix = GritEngineMatrix * MatrixPranavRotation;
//			bool rotationtest = GritEngineMatrix == EigenMatrix;
//			assert(rotationtest);
//		}
//	}
//}