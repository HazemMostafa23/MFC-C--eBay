// MyProfile.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "MyProfile.h"
#include "afxdialogex.h"
#include "Account.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Register.h"
#include <afxctl.h>
#include "PictureCtrl.h"
#include <algorithm>
#include "resource.h"


using namespace std;


// MyProfile dialog

IMPLEMENT_DYNAMIC(MyProfile, CDialogEx)

MyProfile::MyProfile(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG12, pParent)
{

}

MyProfile::~MyProfile()
{
}

void MyProfile::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IMAGE1, picture);
	DDX_Control(pDX, IDC_STATIC_1, photo);


	DDX_Control(pDX, IDC_STATIC_6, imgur);
	
}


BEGIN_MESSAGE_MAP(MyProfile, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &MyProfile::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT4, &MyProfile::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT1, &MyProfile::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &MyProfile::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT2, &MyProfile::OnEnChangeEdit2)
	ON_STN_CLICKED(IDC_STATIC_1, &MyProfile::OnStnClickedStatic1)

	ON_STN_CLICKED(IDC_STATIC_6, &MyProfile::OnStnClickedStatic6)
	
END_MESSAGE_MAP()


// MyProfile message handlers





void MyProfile::OnBnClickedCancel()
{
	Account account;
		ShowWindow(SW_HIDE);
	account.DoModal();
}


void MyProfile::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void MyProfile::OnEnChangeEdit1()
{
}
BOOL MyProfile::OnInitDialog() {
	ifstream file;
	file.open("log.txt");
	string username, id, email, mobileno;

	getline(file, username), getline(file, id), getline(file, email), getline(file, mobileno);
	CString cusername(username.c_str());
	CString cid(id.c_str());
	CString cemail(email.c_str());
	CString cmobileno(mobileno.c_str());
	SetDlgItemText(IDC_EDIT1, cusername);
	SetDlgItemText(IDC_EDIT3, cid);
	SetDlgItemText(IDC_EDIT2, cemail);
	SetDlgItemText(IDC_EDIT4, cmobileno);
	
	
	
	///*CString personalphotopath = cpath1;*/
	//

	return TRUE;
}

void MyProfile::OnBnClickedButton2()
{

}


void MyProfile::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void MyProfile::OnStnClickedStatic1()
{
	// TODO: Add your control notification handler code here
}


void MyProfile::OnStnClickedStatic2()
{
	// TODO: Add your control notification handler code here
}


void MyProfile::OnStnClickedStatic6()
{
	// TODO: Add your control notification handler code here
}


void MyProfile::OnStnClickedStaticphoto()
{
	// TODO: Add your control notification handler code here
}


void MyProfile::OnStnClickedPhoto()
{
	// TODO: Add your control notification handler code here
}
