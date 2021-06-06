#pragma once
#include "afxwin.h"


// MyProducts dialog

class MyProducts : public CDialogEx
{
	DECLARE_DYNAMIC(MyProducts)

public:
	BOOL OnInitDialog();
	MyProducts(CWnd* pParent = NULL);   // standard constructor
	virtual ~MyProducts();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG14 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	CListBox combo;
	afx_msg void OnLbnDblclkList1();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedButton2();
	CComboBox cat;
	CComboBox cond;
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnEnChangeEdit9();
	afx_msg void OnBnClickedButton24();
};
