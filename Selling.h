#pragma once
#include "afxwin.h"
#include "PictureCtrl.h"


// Selling dialog

class Selling : public CDialogEx
{
	DECLARE_DYNAMIC(Selling)

public:
	Selling(CWnd* pParent = NULL);   // standard constructor
	virtual ~Selling();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		BOOL OnInitDialog();
	void OnBnClickedCancel();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox combobo;
	CComboBox combobo3;
	CComboBox combobo2;
	afx_msg void OnCbnEditchangeCombo3();
	afx_msg void OnCbnEditchangeCombo1();
	afx_msg void OnCbnDropdownCombo1();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnBnClickedButton2();
	CPictureCtrl photo;
};
