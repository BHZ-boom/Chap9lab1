
// Chap9lab1Dlg.h: 头文件
//

#pragma once


// CChap9lab1Dlg 对话框
class CChap9lab1Dlg : public CDialogEx
{
// 构造
public:
	CChap9lab1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAP9LAB1_DIALOG };
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
	CString str1, str2;
	afx_msg void OnBnClickedRadio512m();
	afx_msg void OnBnClickedRadio1g();
	afx_msg void OnBnClickedRadio2g();
	afx_msg void OnBnClickedCheckCamera();
	afx_msg void OnBnClickedCheckWire();
	afx_msg void OnBnClickedCheckEar();
	afx_msg void OnBnClickedCheckHandle();
	void HelpCheckBox();
	afx_msg void OnBnClickedButtonReselect();
	afx_msg void OnBnClickedButtonCommit();
};
