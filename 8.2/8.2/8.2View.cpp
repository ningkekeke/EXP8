
// 8.2View.cpp : CMy82View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "8.2.h"
#endif

#include "8.2Doc.h"
#include "8.2View.h"
#include "Dlg.h"
#include "Dlg2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy82View

IMPLEMENT_DYNCREATE(CMy82View, CView)

BEGIN_MESSAGE_MAP(CMy82View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(q2, &CMy82View::Onq2)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(q1, &CMy82View::Onq1)
	ON_COMMAND(q3, &CMy82View::Onq3)
END_MESSAGE_MAP()

// CMy82View 构造/析构

CMy82View::CMy82View()
{
	// TODO: 在此处添加构造代码

}

CMy82View::~CMy82View()
{
}

BOOL CMy82View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy82View 绘制

void CMy82View::OnDraw(CDC* pDC)
{
	CMy82Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag == 1) {
		CRect rect = CRect(Points[0], Points[2]);
		pDC->Ellipse(rect);
	}
	if (flag == 2)
	{
		Dlg d;
		int r = d.DoModal();
		if (r == IDOK)
		{
			X = d.x;
			Y = d.y;
			a = d.a;
			b = d.b;
		}
		cr = CRect(X - a, Y - b, X + a, Y + b);
		pDC->Ellipse(cr);
	}
	if (flag == 4) 
	{
		CBrush bru(RGB(s1, s2, s3));
		CBrush *oldbrush;
		oldbrush = pDC->SelectObject(&bru);
		pDC->Ellipse(cr);
		s1 = s2 = s3 = 255;
		if (flag == 44) {
			CPen pen;
			pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
			pDC->SelectObject(&pen);
			pDC->MoveTo(cr.left, cr.top);
			pDC->LineTo(cr.right, cr.top);
			pDC->MoveTo(cr.right, cr.top);
			pDC->LineTo(cr.right, cr.bottom);
			pDC->MoveTo(cr.right, cr.bottom);
			pDC->LineTo(cr.left, cr.bottom);
			pDC->MoveTo(cr.left, cr.bottom);
			pDC->LineTo(cr.left, cr.top);
			flag = 0;
		}
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy82View 打印

BOOL CMy82View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy82View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy82View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy82View 诊断

#ifdef _DEBUG
void CMy82View::AssertValid() const
{
	CView::AssertValid();
}

void CMy82View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy82Doc* CMy82View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy82Doc)));
	return (CMy82Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy82View 消息处理程序


void CMy82View::Onq2()
{
	// TODO: 在此添加命令处理程序代码
	flag = 2;
	Invalidate();
}


void CMy82View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1) {
		IsReadyToMove = false;   // 初始标记一下不能移动
		if (Points[0].x <= point.x && point.x <= Points[2].x &&
			Points[0].y <= point.y && point.y <= Points[2].y)
		{
			p1 = point;
			IsReadyToMove = true; // 标记一下可以移动了
		}
		Invalidate(FALSE);
	}
	if (flag == 4) {
		if (point.x > cr.left &&point.x < cr.right &&point.y > cr.top &&point.y < cr.bottom)
			flag = 44;
		Invalidate();
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy82View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	if(flag==1){
	if (true == IsReadyToMove)
	{
		SetCursor(LoadCursor(NULL, IDC_SIZEALL)); // 设置光标为八个方向   
												  // 利用当前鼠标位置和初始记录的位置来修改矩形的每个顶点，做到图随鼠标动的效果
		for (int i = 0; i < 4; i++)
		{
			Points[i] += point - p1;
		}
		p1 = point;
	}
	dc.SetROP2(R2_NOT);
	this->Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CMy82View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1) {

	
	if (true == IsReadyToMove)
	{
		p1 = NULL;      // 清空移动信息
	}
	IsReadyToMove = false;   // 标记一下此时不可以移动了
	Invalidate(FALSE);}
	if (flag == 4) {
		cr.left = point.x - 100;
		cr.top = point.y - 70;
		cr.right = point.x + 100;
		cr.bottom = point.y + 70;
		Invalidate();
	}
	CView::OnLButtonUp(nFlags, point);
}


void CMy82View::Onq1()
{
	// TODO: 在此添加命令处理程序代码
	flag = 1;
	Invalidate();
	IsReadyToMove = false;
	p1 = 0;
	Points[0] = CPoint(121, 100);
	Points[1] = CPoint(367, 100);
	Points[2] = CPoint(367, 245);
	Points[3] = CPoint(121, 245);
}


void CMy82View::Onq3()
{
	// TODO: 在此添加命令处理程序代码
	flag = 4;
	Dlg2 dia;
	int r = dia.DoModal();
	if (r == IDOK)
	{
		s1 = dia.r;
		s2 = dia.g;
		s3 = dia.b;
	}
	Invalidate();
}
