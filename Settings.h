#pragma once


// Settings dialog

class Settings : public CDialogEx
{
	DECLARE_DYNAMIC(Settings)

public:
	Settings(CWnd* pParent = NULL);   // standard constructor
	virtual ~Settings();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton11();
};
