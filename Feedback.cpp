// Feedback.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "Feedback.h"
#include "afxdialogex.h"
#include "Home.h"



// Feedback dialog

IMPLEMENT_DYNAMIC(Feedback, CDialogEx)

Feedback::Feedback(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

Feedback::~Feedback()
{
}

void Feedback::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Feedback, CDialogEx)
	ON_BN_CLICKED(IDOK, &Feedback::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO2, &Feedback::OnBnClickedRadio2)
END_MESSAGE_MAP()


// Feedback message handlers


void Feedback::OnBnClickedOk()
{
	Home homepage;
	MessageBox(_T("Submitted successfully"));
    ShowWindow(SW_HIDE);
	homepage.DoModal();
	
}


void Feedback::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
}
