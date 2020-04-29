
// Trigonometry Calculator01Dlg.h: 头文件
//

#pragma once


// CTrigonometryCalculator01Dlg 对话框
class CTrigonometryCalculator01Dlg : public CDialogEx
{
// 构造
public:
	CTrigonometryCalculator01Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRIGONOMETRYCALCULATOR01_DIALOG };
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
	double m_editNUM;
	double m_editResult;
	afx_msg void OnBnClickedSinButton();
	afx_msg void OnBnClickedCosButton();
	afx_msg void OnBnClickedTanButton();
	afx_msg void OnBnClickedCotButton();
	afx_msg void OnBnClickedQuitButton();
	afx_msg void OnBnClickedClcButton();
	CEdit show_test;
	afx_msg void OnBnClickedTestButton();
};
