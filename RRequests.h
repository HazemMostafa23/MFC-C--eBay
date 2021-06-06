#pragma once


// RRequests dialog

class RRequests : public CDialogEx
{
	DECLARE_DYNAMIC(RRequests)

public:
	RRequests(CWnd* pParent = NULL);   // standard constructor
	virtual ~RRequests();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG13 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCommand1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton2();
};
