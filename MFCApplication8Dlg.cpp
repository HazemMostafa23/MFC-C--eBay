
// MFCApplication8Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "MFCApplication8Dlg.h"
#include "afxdialogex.h"
#include "Home.h"
#include "Register.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication8Dlg dialog



CMFCApplication8Dlg::CMFCApplication8Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION8_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication8Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication8Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(ID2, &CMFCApplication8Dlg::OnBnClicked2)
	ON_BN_CLICKED(ID3, &CMFCApplication8Dlg::OnBnClicked3)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication8Dlg::OnEnChangeEdit3)
END_MESSAGE_MAP()


// CMFCApplication8Dlg message handlers

BOOL CMFCApplication8Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication8Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication8Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication8Dlg::OnBnClickedButton1()
{
	Home homepage;
	ShowWindow(SW_HIDE);
	homepage.DoModal();

}


void CMFCApplication8Dlg::OnBnClicked2()
{
	ifstream file;
	ifstream file2;
	ofstream logged;
	ofstream pass;
	file.open("register.txt",ios::app);
	file2.open("database.txt", ios::app);
	logged.open("log.txt", ios::trunc);
	pass.open("pass.txt", ios::trunc);
	string id, password,aid,apassword,username,email,mobileno;
	CString cid, cpassword;
	GetDlgItemText(IDC_EDIT3, cid);
	GetDlgItemText(IDC_EDIT4, cpassword);
    CStringA cidA(cid);
	CStringA cpasswordA(cpassword);
	aid = cidA.GetBuffer();
	apassword = cpasswordA.GetBuffer();
	bool condition = false;
	while (!file.eof()) {
		file >> id >> password;
		getline(file2, username), getline(file2, id), getline(file2, email), getline(file2, mobileno);
		if (id == aid&&password == apassword) {
			condition = true;
			file.close();
			file2.close();
			logged << username << endl << id << endl << email << endl << mobileno << endl;
			pass << password;
			logged.close();
			pass.close();
			
			Home homepage;
			MessageBox(_T("Logged in successfully"));
			ShowWindow(SW_HIDE);
            homepage.DoModal();
			break;
			

}
		
		
	}
	if (condition == false) {
		MessageBox(_T("Wrong username/ID"));
	}
	 
	
	
	
}


void CMFCApplication8Dlg::OnBnClicked3()
{
	Register regist;
	ShowWindow(SW_HIDE);
	regist.DoModal();
}


void CMFCApplication8Dlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
