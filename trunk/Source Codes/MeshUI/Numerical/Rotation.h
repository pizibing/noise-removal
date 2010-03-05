/*_____________________________________________________
 |
 |	Intra3D Layer1 :  Algebra �������֮һ
 |                                          
 |  �ļ���Rotation.h
 |
 |  ���ܣ���Ԫ����ת����
 |
 |  ���������� ��1999/01/10
 |
 |	Դ������ԣ������˵������ٲ���
 |_____________________________________________________*/

/*_____________________________________________________
 |  
 |	���� OpenGL �Ľ���ʽ��άͼ�������������
 |
 |	**   Intra3D 2.0 for Windows 9X/NT  **
 |
 |	          ����Ȩ�ˣ����� 
 |	
 |	�㽭��ѧ CAD&CG �����ص�ʵ���� (310027)
 |_____________________________________________________*/


#if !defined(ROTATION_H)
#define		 ROTATION_H

#include "..\MeshLib\BasicElement.h"

/*______________________ ROTATION ͨ�� QUATERNION ʵ�� _____________________*/


// ������ת ROTATION �任, ROTATION ��һ����ָ axis ��һ��
// �� ROTATION �ṹ��ʾ��תʱ��(axis, angle) �� -(axis, angle) �ȼ�

class ROTATION
{
public:
	Coord axis ;	// Unit Vector  
	double  angle;	// 0 - 360 degree
	// �����һ���� ROTATION 
	ROTATION(Coord Axis, double fAngle=0.0f)
	{ axis=Axis; angle=fAngle; axis.normalize(); }
	// �����һ���� ROTATION 
	ROTATION(double fX=0.0f, double fY=0.0f, double fZ=1.0f, double fAngle=0.0f)
	{ axis[0]=fX; axis[1]=fY; axis[2]=fZ; angle=fAngle; axis.normalize(); }

	
};

// ROTATION ��ˣ�����ֵ = R1 * R2  (��ִ�� R1 ��ת����ִ�� R2 ��ת)
// Ҫ�� R1 R2 �ȹ�һ��
ROTATION RotationMultiply( ROTATION R1,  ROTATION R2);

ROTATION operator *      ( ROTATION R1,  ROTATION R2);

// V ���� R �任��Ϊ V', �������� V'
// Ҫ�� R �ȹ�һ��

Coord VectorTransform(const Coord V, const ROTATION R);

// �� ROTATION �ṹ��ʾ�� Matrix
// Ҫ�� R �ȹ�һ��
void RotationToMatrix(double M[16], const ROTATION R);


/*_______________ �����˽���Ԫ��ϸ�ڵĳ���Ա�������¿� _____________________*/



// ������Ԫ�� QUATERNION
// �� QUATERNION �ṹ��ʾ��תʱ��(x,y,z,w) �� -(x,y,z,w) �ȼ�

class QUATERNION
{
public:
	double x, y, z, w;
	QUATERNION(double fX=0.0f, double fY=0.0f, double fZ=0.0f, double fW=1.0f)
	{ x=fX; y=fY; z=fZ; w=fW; }
};


// ��Ԫ����ģ������ֵ = |A|
double QuaternionMagnitude(const QUATERNION A);

// ��Ԫ���һ��
// ��� |A|=0�����ֵ = A�����ֵ = A/(|A|)
void QuaternionNormalize(QUATERNION *A);

// ��Ԫ������
// ��� |A|=0�����ֵ = A���������ֵ = A ����
void QuaternionInverse(QUATERNION *A);

// ��Ԫ�鹲�����ֵ = A �Ĺ���
void QuaternionConjugate(QUATERNION *A);

// ��Ԫ����ӣ�����ֵ = A + B
QUATERNION QuaternionAdd(const QUATERNION A, const QUATERNION B);

QUATERNION operator +   (const QUATERNION A, const QUATERNION B);

// ��Ԫ�����������ֵ = A - B
QUATERNION QuaternionSub(const QUATERNION A, const QUATERNION B);

QUATERNION operator -   (const QUATERNION A, const QUATERNION B);

// ��Ԫ�����ţ�����ֵ = s * A 
QUATERNION QuaternionScale(const QUATERNION A, const double s);

QUATERNION operator *     (const QUATERNION A, const double s);

QUATERNION QuaternionScale(const double s, const QUATERNION A);

QUATERNION operator *     (const double s, const QUATERNION A);

// ��Ԫ����ˣ�����ֵ = A * B
QUATERNION QuaternionMultiply(const QUATERNION A, const QUATERNION B);

QUATERNION operator *        (const QUATERNION A, const QUATERNION B);  

// Spherical Linear Interpolation Between two Quaternions, 0 < t < 1
QUATERNION QuaternionSlerp(const QUATERNION from, const QUATERNION to, double t);

/*_____________________________________________________
 |                                                     
 |   Ϊ��߼������ܣ����±任�������ٶ�
 |
 |   ������� R Q V �Ѿ������� Normalize ����    
 |_____________________________________________________*/


/*------------------------------------------------------------------*/
/*----------------------  QUATERNION �� ROTATION  ------------------*/

// �� ROTATION �ṹ��ʾ�� QUATERNION
QUATERNION RotationToQuaternion(const ROTATION R);

// �� QUATERNION �ṹ��ʾ�� ROTATION
ROTATION QuaternionToRotation(const QUATERNION Q);

/*------------------------------------------------------------------*/
/*----------------------  QUATERNION �� Matrix  --------------------*/

// �� QUATERNION �ṹ��ʾ�� Matrix
void QuaternionToMatrix(double M[16], const QUATERNION Q);
void QuaternionToMatrix(double R[3][3], const QUATERNION quat);

// �� Matrix �ṹ��ʾ�� QUATERNION
// Ҫ�� Matrix ��һ����ת����,�����ܵõ���ȷ���
void MatrixToQuaternion(QUATERNION *Q, const double M[16]);
void MatrixToQuaternion(QUATERNION *quat, const double R[3][3]);
void MatrixToQuaternion2(QUATERNION& quat, const double R[3][3]);
/*------------------------------------------------------------------*/
/*-----------------------  QUATERNION �� Coord  -------------------*/


// ��ʸ��������ά�ռ��һ�㣩��ʾ����Ԫ��
QUATERNION VectorToQuaternion(const Coord V);

// ����Ԫ����鲿��ʸ����ʾ
Coord QuaternionToVector(const QUATERNION Q);

// V ���� Q �任��Ϊ V', �������� V'
Coord VectorTransform(const Coord V, const QUATERNION Q);
Coord VectorTransform(const Coord V, const ROTATION Q);

#endif