
// 8.2View.cpp : CMy82View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CMy82View ����/����

CMy82View::CMy82View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy82View::~CMy82View()
{
}

BOOL CMy82View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy82View ����

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
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy82View ��ӡ

BOOL CMy82View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy82View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy82View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy82View ���

#ifdef _DEBUG
void CMy82View::AssertValid() const
{
	CView::AssertValid();
}

void CMy82View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy82Doc* CMy82View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy82Doc)));
	return (CMy82Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy82View ��Ϣ�������


void CMy82View::Onq2()
{
	// TODO: �ڴ���������������
	flag = 2;
	Invalidate();
}


void CMy82View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 1) {
		IsReadyToMove = false;   // ��ʼ���һ�²����ƶ�
		if (Points[0].x <= point.x && point.x <= Points[2].x &&
			Points[0].y <= point.y && point.y <= Points[2].y)
		{
			p1 = point;
			IsReadyToMove = true; // ���һ�¿����ƶ���
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	if(flag==1){
	if (true == IsReadyToMove)
	{
		SetCursor(LoadCursor(NULL, IDC_SIZEALL)); // ���ù��Ϊ�˸�����   
												  // ���õ�ǰ���λ�úͳ�ʼ��¼��λ�����޸ľ��ε�ÿ�����㣬����ͼ����궯��Ч��
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 1) {

	
	if (true == IsReadyToMove)
	{
		p1 = NULL;      // ����ƶ���Ϣ
	}
	IsReadyToMove = false;   // ���һ�´�ʱ�������ƶ���
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
