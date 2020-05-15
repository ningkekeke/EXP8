
// 8.1Dlg.h : 头文件
//

#pragma once


// CMy81Dlg 对话框
class CMy81Dlg : public CDialogEx
{
// 构造
public:
	CMy81Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY81_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int a1;
	int a2;
	int a3;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	int b1;
	int b2;
	afx_msg void OnBnClickedButton6();
	int c1;
	CString S;
	afx_msg void OnBnClickedButton5();
};
