/*_____________________________________________________
 |
 |  �ļ���Trackball.h
 |
 |_____________________________________________________*/




#if !defined(TRACKBALL_H)
#define		 TRACKBALL_H

#include "..\MeshLib\BasicElement.h"

class Trackball
{
public:
	Trackball(void);
   ~Trackball(void);

public:
	// �����������Ϊ���ڵ�����
	void SetTrackWindow(int iWidth, int iHeight);

	// �����������Ϊ��������(centerX, centerY) 
	void SetTrackWindow(int iWidth, int iHeight, int iCenterX, int iCenterY);

	// ����հ������ʱ������ (mouseX, mouseY)
	void Start(int iMouseX, int iMouseY);

	// ����ƶ� (dx,dy), ������ת�� axis ��Ƕ� angle 
	void Tracking(int iDx, int iDy, Coord *axis, float *fAngle);

protected:

	// �����(mouseX, mouseY)ͶӰ������һ�� P
	// ����ֵ��Ϊ���ĵ�P��ʸ��
	Coord MouseToCoord(int iMouseX, int iMouseY);

	int    m_iWidth,   m_iHeight;	// ���ڵĿ��
	int    m_iCenterX, m_iCenterY;	// ����������
	int    m_iRadius;				// ������뾶
	int    m_iMouseX,  m_iMouseY;	// ���λ��

	Coord m_start;	// �հ���ʱ�����ͶӰʸ��
	Coord m_stop;	// �ƶ�(dx,dy)ʱ�����ͶӰʸ��
};

#endif // TRACKBALL_H
