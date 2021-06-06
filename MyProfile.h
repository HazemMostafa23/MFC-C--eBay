#pragma once
#include "image1.h"
#include "PictureCtrl.h"
#include "atlimage.h"



// MyProfile dialog

class MyProfile : public CDialogEx
{
	DECLARE_DYNAMIC(MyProfile)

public:
	MyProfile(CWnd* pParent = NULL);   // standard constructor
	virtual ~MyProfile();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG12 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg
	
	void OnBnClickedCancel();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit1();
	BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit2();
	CImage1 picture;
	CPictureCtrl photo;
	afx_msg void OnStnClickedStatic1();
	CImage pp;
	afx_msg void OnStnClickedStatic2();
	CImage1 imgs;
	afx_msg void OnStnClickedStatic6();
	CPictureCtrl imgur;
	CPictureCtrl pphoto;
	afx_msg void OnStnClickedStaticphoto();
	CPictureCtrl myphoto;
	afx_msg void OnStnClickedPhoto();
};
