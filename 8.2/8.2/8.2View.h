
// 8.2View.h : CMy82View ��Ľӿ�
//

#pragma once

#include "Dlg.h"
#include "Dlg2.h"
class CMy82View : public CView
{
protected: // �������л�����
	CMy82View();
	DECLARE_DYNCREATE(CMy82View)

// ����
public:
	CMy82Doc* GetDocument() const;

// ����
public:
	int s1 = 255;
	int s2 = 255;
	int s3 = 255;
	int flag = 0;
	int X, Y, a, b;
	CRect cr;
	CPoint Points[4];
	bool IsReadyToMove; // �Ƿ���Կ�ʼ�ƶ�
	CPoint p1; // �ƶ����ε�ʱ����õ�
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy82View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onq2();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void Onq1();
	afx_msg void Onq3();
};

#ifndef _DEBUG  // 8.2View.cpp �еĵ��԰汾
inline CMy82Doc* CMy82View::GetDocument() const
   { return reinterpret_cast<CMy82Doc*>(m_pDocument); }
#endif

