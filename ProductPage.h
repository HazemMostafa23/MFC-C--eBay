#pragma once


// ProductPage dialog

class ProductPage : public CDialogEx
{
	DECLARE_DYNAMIC(ProductPage)

public:
	BOOL OnInitDialog();
	ProductPage(CWnd* pParent = NULL);   // standard constructor
	virtual ~ProductPage();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION5_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedDdddd();
};
