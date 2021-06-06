#pragma once


// Person_details dialog

class Person_details : public CDialogEx
{
	DECLARE_DYNAMIC(Person_details)

public:
	Person_details(CWnd* pParent = NULL);   // standard constructor
	virtual ~Person_details();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeMfceditbrowse1();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedOk();
};
