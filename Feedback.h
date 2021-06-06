#pragma once


// Feedback dialog

class Feedback : public CDialogEx
{
	DECLARE_DYNAMIC(Feedback)

public:
	Feedback(CWnd* pParent = NULL);   // standard constructor
	virtual ~Feedback();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRadio2();
};
