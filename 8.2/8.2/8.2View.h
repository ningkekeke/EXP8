
// 8.2View.h : CMy82View 类的接口
//

#pragma once

#include "Dlg.h"
#include "Dlg2.h"
class CMy82View : public CView
{
protected: // 仅从序列化创建
	CMy82View();
	DECLARE_DYNCREATE(CMy82View)

// 特性
public:
	CMy82Doc* GetDocument() const;

// 操作
public:
	int s1 = 255;
	int s2 = 255;
	int s3 = 255;
	int flag = 0;
	int X, Y, a, b;
	CRect cr;
	CPoint Points[4];
	bool IsReadyToMove; // 是否可以开始移动
	CPoint p1; // 移动矩形的时候会用到
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy82View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // 8.2View.cpp 中的调试版本
inline CMy82Doc* CMy82View::GetDocument() const
   { return reinterpret_cast<CMy82Doc*>(m_pDocument); }
#endif

