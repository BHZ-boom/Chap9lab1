
// Chap9lab1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Chap9lab1.h"
#include "Chap9lab1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CChap9lab1Dlg 对话框



CChap9lab1Dlg::CChap9lab1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHAP9LAB1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	str1 = L"";
	str2 = L"摄像头";
}

void CChap9lab1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_STATIC_CHOOSEN, m_show);
}

BEGIN_MESSAGE_MAP(CChap9lab1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO_512M, &CChap9lab1Dlg::OnBnClickedRadio512m)
	ON_BN_CLICKED(IDC_RADIO_1G, &CChap9lab1Dlg::OnBnClickedRadio1g)
	ON_BN_CLICKED(IDC_RADIO_2G, &CChap9lab1Dlg::OnBnClickedRadio2g)
	ON_BN_CLICKED(IDC_CHECK_CAMERA, &CChap9lab1Dlg::OnBnClickedCheckCamera)
	ON_BN_CLICKED(IDC_CHECK_WIRE, &CChap9lab1Dlg::OnBnClickedCheckWire)
	ON_BN_CLICKED(IDC_CHECK_EAR, &CChap9lab1Dlg::OnBnClickedCheckEar)
	ON_BN_CLICKED(IDC_CHECK_HANDLE, &CChap9lab1Dlg::OnBnClickedCheckHandle)
	ON_BN_CLICKED(IDC_BUTTON_RESELECT, &CChap9lab1Dlg::OnBnClickedButtonReselect)
	ON_BN_CLICKED(IDC_BUTTON_COMMIT, &CChap9lab1Dlg::OnBnClickedButtonCommit)
END_MESSAGE_MAP()


// CChap9lab1Dlg 消息处理程序

BOOL CChap9lab1Dlg::OnInitDialog()
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
	CButton* InitRadioButton = (CButton*)GetDlgItem(IDC_RADIO_1G);
	CButton* InitCheckBox = (CButton*)GetDlgItem(IDC_CHECK_CAMERA);
	InitRadioButton->SetCheck(BST_CHECKED);
	InitCheckBox->SetCheck(BST_CHECKED);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CChap9lab1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChap9lab1Dlg::OnPaint()
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
HCURSOR CChap9lab1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChap9lab1Dlg::OnBnClickedRadio512m()
{
	// TODO: 在此添加控件通知处理程序代码
	str1 = L"内存：512M";
	CStatic* pStaticText = (CStatic*)GetDlgItem(IDC_STATIC_CHOOSEN);
	pStaticText->SetWindowText(str1 + str2);
}


void CChap9lab1Dlg::OnBnClickedRadio1g()
{
	// TODO: 在此添加控件通知处理程序代码
	str1 = L"内存：1G";
	CStatic* pStaticText = (CStatic*)GetDlgItem(IDC_STATIC_CHOOSEN);
	pStaticText->SetWindowText(str1 + str2);
}


void CChap9lab1Dlg::OnBnClickedRadio2g()
{
	// TODO: 在此添加控件通知处理程序代码
	str1 = L"内存：2G";
	CStatic* pStaticText = (CStatic*)GetDlgItem(IDC_STATIC_CHOOSEN);
	pStaticText->SetWindowText(str1 + str2);
}


void CChap9lab1Dlg::HelpCheckBox() {
	str2 = L"";
	CButton* CheckBox[4];
	UINT nState[4];
	CheckBox[0] = (CButton*)GetDlgItem(IDC_CHECK_CAMERA);
	CheckBox[1] = (CButton*)GetDlgItem(IDC_CHECK_WIRE);
	CheckBox[2] = (CButton*)GetDlgItem(IDC_CHECK_EAR);
	CheckBox[3] = (CButton*)GetDlgItem(IDC_CHECK_HANDLE);
	for (int i = 0; i < 4; i++) {
		nState[i] = CheckBox[i]->GetCheck();
	}
	if (nState[0] == BST_CHECKED) {
		str2 += L"摄像头";
	}
	if (nState[1] == BST_CHECKED) {
		str2 += L"无线网卡";
	}
	if (nState[2] == BST_CHECKED) {
		str2 += L"蓝牙耳机";
	}
	if (nState[3] == BST_CHECKED) {
		str2 += L"游戏手柄";
	}
	CStatic* pStaticText = (CStatic*)GetDlgItem(IDC_STATIC_CHOOSEN);
	pStaticText->SetWindowText(str1 + str2);
}


void CChap9lab1Dlg::OnBnClickedCheckCamera()
{
	// TODO: 在此添加控件通知处理程序代码
	HelpCheckBox();
}




void CChap9lab1Dlg::OnBnClickedCheckWire()
{
	// TODO: 在此添加控件通知处理程序代码
	HelpCheckBox();
}




void CChap9lab1Dlg::OnBnClickedCheckEar()
{
	// TODO: 在此添加控件通知处理程序代码
	HelpCheckBox();
}




void CChap9lab1Dlg::OnBnClickedCheckHandle()
{
	// TODO: 在此添加控件通知处理程序代码
	HelpCheckBox();
}


void CChap9lab1Dlg::OnBnClickedButtonReselect()
{
	// TODO: 在此添加控件通知处理程序代码
	CButton* CheckBox[7];
	CheckBox[0] = (CButton*)GetDlgItem(IDC_CHECK_CAMERA);
	CheckBox[1] = (CButton*)GetDlgItem(IDC_CHECK_WIRE);
	CheckBox[2] = (CButton*)GetDlgItem(IDC_CHECK_EAR);
	CheckBox[3] = (CButton*)GetDlgItem(IDC_CHECK_HANDLE);
	CheckBox[4] = (CButton*)GetDlgItem(IDC_RADIO_512M);
	CheckBox[5] = (CButton*)GetDlgItem(IDC_RADIO_1G);
	CheckBox[6] = (CButton*)GetDlgItem(IDC_RADIO_2G);
	for (int i = 0; i < 7; i++) {
		CheckBox[i]->SetCheck(BST_UNCHECKED);
	}
	CheckBox[0]->SetCheck(BST_CHECKED);
	CheckBox[5]->SetCheck(BST_CHECKED);
	OnBnClickedRadio1g();
	HelpCheckBox();
}


void CChap9lab1Dlg::OnBnClickedButtonCommit()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(IDC_BUTTON_COMMIT);
}
