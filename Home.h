#pragma once
#include "afxwin.h"


// Home dialog

class Home : public CDialogEx
{
	DECLARE_DYNAMIC(Home)

public:
	Home(CWnd* pParent = NULL);   // standard constructor
	virtual ~Home();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		
	void OnBnClickedButton13();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton14();
	CComboBox combo;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClicked11();
	afx_msg void OnCbnSelchangeCombo1();
	CListBox combobo;
	afx_msg void OnLbnDblclkList1();
	afx_msg void OnLbnSelchangeList1();

	
	
	afx_msg void OnBnClickedC();
	afx_msg void OnBnClickedButton19();
};
