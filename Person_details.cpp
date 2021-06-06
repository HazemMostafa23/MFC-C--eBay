// Person_details.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "Person_details.h"
#include "afxdialogex.h"
#include "Requests.h"


// Person_details dialog

IMPLEMENT_DYNAMIC(Person_details, CDialogEx)

Person_details::Person_details(CWnd* pParent /*=NULL*/)
	
{

}

Person_details::~Person_details()
{
}

void Person_details::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Person_details, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Person_details::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT3, &Person_details::OnEnChangeEdit3)
	ON_BN_CLICKED(IDOK, &Person_details::OnBnClickedOk)
END_MESSAGE_MAP()


// Person_details message handlers


void Person_details::OnBnClickedButton1()
{
	Requests request;
	ShowWindow(SW_HIDE);
	request.DoModal();
}


void Person_details::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void Person_details::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
