
// Trigonometry Calculator01Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Trigonometry Calculator01.h"
#include "Trigonometry Calculator01Dlg.h"
#include "Trigonometric_Function.h"
#include "afxdialogex.h"
//#include "sinm.h"
#include <iomanip>
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

//#pragma comment (lib,"Sin_dll.lib")
//extern "C" _declspec(dllimport) long int factorialcpp(int n);
//extern "C" _declspec(dllimport) double sincpp(double x);

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTrigonometryCalculator01Dlg 对话框



CTrigonometryCalculator01Dlg::CTrigonometryCalculator01Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TRIGONOMETRYCALCULATOR01_DIALOG, pParent)
	, m_editNUM(0)
	, m_editResult(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrigonometryCalculator01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NUM_EDIT, m_editNUM);
	DDX_Text(pDX, IDC_CAL_EDIT, m_editResult);
	DDX_Control(pDX, IDC_TEST_EDIT, show_test);
}

BEGIN_MESSAGE_MAP(CTrigonometryCalculator01Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SIN_BUTTON, &CTrigonometryCalculator01Dlg::OnBnClickedSinButton)
	ON_BN_CLICKED(IDC_COS_BUTTON, &CTrigonometryCalculator01Dlg::OnBnClickedCosButton)
	ON_BN_CLICKED(IDC_TAN_BUTTON, &CTrigonometryCalculator01Dlg::OnBnClickedTanButton)
	ON_BN_CLICKED(IDC_COT_BUTTON, &CTrigonometryCalculator01Dlg::OnBnClickedCotButton)
	ON_BN_CLICKED(IDC_QUIT_BUTTON, &CTrigonometryCalculator01Dlg::OnBnClickedQuitButton)
	ON_BN_CLICKED(IDC_CLC_BUTTON, &CTrigonometryCalculator01Dlg::OnBnClickedClcButton)
	ON_BN_CLICKED(IDC_TEST_BUTTON, &CTrigonometryCalculator01Dlg::OnBnClickedTestButton)
END_MESSAGE_MAP()


// CTrigonometryCalculator01Dlg 消息处理程序

BOOL CTrigonometryCalculator01Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTrigonometryCalculator01Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTrigonometryCalculator01Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTrigonometryCalculator01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTrigonometryCalculator01Dlg::OnBnClickedSinButton()  //点击按钮sin，进入该函数
{
	// TODO: 计算sin函数	 
	//UpdateData(TRUE);                 // 将各控件中的数据保存到相应的变量  	
	//m_editResult = f_sin(m_editNUM);  // 计算sin的值		
	//UpdateData(FALSE);                // 根据各变量的值更新相应的控件，让输出结果编辑框显示m_editResult的值 

	UpdateData(TRUE);  // 将各控件中的数据保存到相应的变量
	typedef double(*lpSinFun)(double); //宏定义函数指针类型
	HINSTANCE hDll;   //DLL句柄 
	lpSinFun sinFun;  //函数指针
	hDll = LoadLibrary(_T("sincpp.dll"));  //动态获取dll文件路径
	m_editResult = 0; //初始化输出为零
	if (hDll != NULL)
	{
		sinFun = (lpSinFun)GetProcAddress(hDll, "sincpp");  //用sinFun取代dll库中的sincpp函数
		if (sinFun != NULL)
		{			
			m_editResult = sinFun(m_editNUM);
			UpdateData(FALSE);
		}
		FreeLibrary(hDll);  //释放dll
	}	      	
}


void CTrigonometryCalculator01Dlg::OnBnClickedCosButton()
{
	// TODO: 计算cos函数
	/*UpdateData(TRUE);                 	
	m_editResult = f_cos(m_editNUM);  			  
	UpdateData(FALSE);*/

	UpdateData(TRUE);
	typedef double(*lpCosFun)(double); //宏定义函数指针类型
	HINSTANCE hDll;   //DLL句柄 
	lpCosFun cosFun;  //函数指针
	hDll = LoadLibrary(_T("coscpp.dll"));  //动态获取dll文件路径
	m_editResult = 0; //初始化输出为零
	CString str;
	if (hDll != NULL)
	{
		cosFun = (lpCosFun)GetProcAddress(hDll, "coscpp");  
		if (cosFun != NULL)
		{
			m_editResult = cosFun(m_editNUM);
			UpdateData(FALSE);
		}
		FreeLibrary(hDll);
	}
}


void CTrigonometryCalculator01Dlg::OnBnClickedTanButton()
{
	// TODO: 计算tan函数
	/*UpdateData(TRUE);
	m_editResult = f_tan(m_editNUM);
	UpdateData(FALSE);*/

	UpdateData(TRUE);
	typedef double(*lpTanFun)(double); //宏定义函数指针类型
	HINSTANCE hDll;   //DLL句柄 
	lpTanFun tanFun;  //函数指针
	hDll = LoadLibrary(_T("tancpp.dll"));  //动态获取dll文件路径
	m_editResult = 0; //初始化输出为零
	if (hDll != NULL)
	{
		tanFun = (lpTanFun)GetProcAddress(hDll, "f_tan"); 
		if (tanFun != NULL)
		{
			m_editResult = tanFun(m_editNUM);
			UpdateData(FALSE);
		}
		FreeLibrary(hDll);  //释放dll
	}
}


void CTrigonometryCalculator01Dlg::OnBnClickedCotButton()
{
	// TODO: 计算cot函数
	/*UpdateData(TRUE);
	m_editResult = f_cot(m_editNUM);
	UpdateData(FALSE);*/

	UpdateData(TRUE);
	typedef double(*lpCotFun)(double); //宏定义函数指针类型
	HINSTANCE hDll;   //DLL句柄 
	lpCotFun cotFun;  //函数指针
	hDll = LoadLibrary(_T("cotcpp.dll"));  //动态获取dll文件路径
	m_editResult = 0; //初始化输出为零
	if (hDll != NULL)
	{
		cotFun = (lpCotFun)GetProcAddress(hDll, "f_cot");  
		if (cotFun != NULL)
		{
			m_editResult = cotFun(m_editNUM);
			UpdateData(FALSE);
		}
		FreeLibrary(hDll);  //释放dll
	}
}


void CTrigonometryCalculator01Dlg::OnBnClickedQuitButton()
{
	// TODO: 退出窗口
	DestroyWindow();
}


void CTrigonometryCalculator01Dlg::OnBnClickedClcButton()
{
	// TODO: 清零结果框
	m_editResult = 0;
	UpdateData(FALSE);

}


void CTrigonometryCalculator01Dlg::OnBnClickedTestButton()
{
	// TODO: 启动自检，并显示自检结果
	double sin_wrong_rate = 0;
	double cos_wrong_rate = 0;
	double tan_wrong_rate = 0;
	double cot_wrong_rate = 0;

	typedef int(*lpSinTest)(); //宏定义函数指针类型
	typedef int(*lpCosTest)();
	typedef int(*lpTanTest)(void);
	typedef int(*lpCotTest)();
	HINSTANCE hDl_sin;   //DLL句柄 
	HINSTANCE hDl_cos;
	HINSTANCE hDl_tan;
	HINSTANCE hDl_cot;
	lpSinTest sintest;  //函数指针
	lpCosTest costest;
	lpTanTest tantest;
	lpCotTest cottest;
	hDl_sin = LoadLibrary(_T("sin_test.dll"));  //动态获取dll文件路径
	hDl_cos = LoadLibrary(_T("cos_test.dll"));
	hDl_tan = LoadLibrary(_T("tan_test.dll"));
	hDl_cot = LoadLibrary(_T("cot_test.dll"));

	if (hDl_sin != NULL)
	{
		sintest = (lpSinTest)GetProcAddress(hDl_sin, "sin_test");
		if (sintest != NULL)
		{
			int sin_wrong_cnt = sintest();  //调用测试函数
			sin_wrong_rate = sin_wrong_cnt / 10.0;
		}
		FreeLibrary(hDl_sin);
	}
	if (hDl_cos != NULL)
	{
		costest = (lpCosTest)GetProcAddress(hDl_cos, "cos_test");
		if (costest != NULL)
		{
			int cos_wrong_cnt = costest();  //调用测试函数
			cos_wrong_rate = cos_wrong_cnt / 10.0;
		}
		FreeLibrary(hDl_cos);
	}
	if (hDl_tan != NULL)
	{
		tantest = (lpTanTest)GetProcAddress(hDl_tan, "tan_test");
		if (tantest != NULL)
		{
			int tan_wrong_cnt = tantest();  //调用测试函数
			tan_wrong_rate = tan_wrong_cnt / 10.0;
		}
		FreeLibrary(hDl_tan);
	}
	if (hDl_cot != NULL)
	{
		cottest = (lpCotTest)GetProcAddress(hDl_cot, "cot_test");
		if (cottest != NULL)
		{
			int cot_wrong_cnt = cottest();  //调用测试函数
			cot_wrong_rate = cot_wrong_cnt / 10.0;
		}
		FreeLibrary(hDl_cot);
	}

	string www;
	CString str(www.c_str());

	char char_sin_wrong[10];
	char char_cos_wrong[10];
	char char_tan_wrong[10];
	char char_cot_wrong[10];  

	sprintf_s(char_sin_wrong, "%.1f", sin_wrong_rate);
	sprintf_s(char_cos_wrong, "%.1f", cos_wrong_rate);
	sprintf_s(char_tan_wrong, "%.1f", tan_wrong_rate);
	sprintf_s(char_cot_wrong, "%.1f", cot_wrong_rate);  //将浮点数转换为数组

	char temp1[] = { "sin函数已完成自检！错误率：" };
	char temp2[] = { "%\r\ncos函数已完成自检！错误率：" };
	char temp3[] = { "%\r\ntan函数已完成自检！错误率：" };
	char temp4[] = { "%\r\ncot函数已完成自检！错误率：" };
	char temp5[] = { "%" };
 
	show_test.SetWindowText(str + temp1 + char_sin_wrong + temp2 + char_cos_wrong + 
	                        temp3 + char_tan_wrong + temp4 + char_cot_wrong + temp5);
}
