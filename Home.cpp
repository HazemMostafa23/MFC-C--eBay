// Home.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "Home.h"
#include "afxdialogex.h"
#include "Contact.h"
#include "AboutUs.h"
#include "Feedback.h"
#include "MFCApplication8Dlg.h"
#include "Requests.h"
#include "Selling.h"
#include "Settings.h"
#include "Account.h"
#include "Search.h"
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <afxwin.h>
#include <search.h>
#include <Winuser.h>
#include "ProductPage.h"
#include "RecievedRequests.h"
#include "MyProducts.h"






using namespace std;


// Home dialog

IMPLEMENT_DYNAMIC(Home, CDialogEx)

Home::Home(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Home::~Home()
{
}

void Home::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, combo);
	DDX_Control(pDX, IDC_LIST1, combobo);
	
}


BEGIN_MESSAGE_MAP(Home, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON13, &Home::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON12, &Home::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON10, &Home::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON15, &Home::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &Home::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON8, &Home::OnBnClickedButton8)
	ON_EN_CHANGE(IDC_EDIT1, &Home::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON14, &Home::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_RADIO1, &Home::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO3, &Home::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &Home::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &Home::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &Home::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_BUTTON2, &Home::OnBnClickedButton2)
	ON_BN_CLICKED(ID11, &Home::OnBnClicked11)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Home::OnCbnSelchangeCombo1)
	ON_LBN_DBLCLK(IDC_LIST1, &Home::OnLbnDblclkList1)
	ON_LBN_SELCHANGE(IDC_LIST1, &Home::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC, &Home::OnBnClickedC)

END_MESSAGE_MAP()


// Home message handlers

void Home::OnBnClickedButton13()
{
	Contact contact;
	ShowWindow(SW_HIDE);
	contact.DoModal();
	
}


void Home::OnBnClickedButton12()
{
	AboutUs about;

	ShowWindow(SW_HIDE);
	about.DoModal();
}

void Home::OnBnClickedButton10()
{
	Feedback feedback;
	ShowWindow(SW_HIDE);
	feedback.DoModal();
}


void Home::OnBnClickedButton15()
{
	CMFCApplication8Dlg login;
	ShowWindow(SW_HIDE);
	MessageBox(_T("Signed out successfully"));
	login.DoModal();
	
}


void Home::OnBnClickedButton16()
{
	Requests request;
	ShowWindow(SW_HIDE);
	request.DoModal();
}




void Home::OnBnClickedButton8()
{
	Selling selling;
	ShowWindow(SW_HIDE);
	selling.DoModal();

}


void Home::OnBnClickedButton17()
{
	Settings settings;
	ShowWindow(SW_HIDE);
	settings.DoModal();
	
	
}


void Home::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void Home::OnBnClickedButton14()
{
	Account account;
	ShowWindow(SW_HIDE);
	account.DoModal();
}


void Home::OnBnClickedRadio1()
{
	combo.ResetContent();
	combo.AddString(_T("Tvs"));
	combo.AddString(_T("Mobiles"));
	combo.AddString(_T("Cameras"));
	combo.AddString(_T("Laptops"));
	combo.AddString(_T("Headphones"));
}


void Home::OnBnClickedRadio3()
{

	combo.ResetContent();
	combo.AddString(_T("Refrigators"));
	combo.AddString(_T("Washers"));
	combo.AddString(_T("Ovens"));
	combo.AddString(_T("Air Conditioners"));
	combo.AddString(_T("Fans"));
}


void Home::OnBnClickedRadio4()
{
	combo.ResetContent();
	combo.AddString(_T("Tshirts"));
	combo.AddString(_T("Shorts"));
	combo.AddString(_T("Pants"));
	combo.AddString(_T("Jackets"));
	combo.AddString(_T("Shoes"));
}


void Home::OnBnClickedRadio5()
{

	combo.ResetContent();
	combo.AddString(_T("Watches"));
	combo.AddString(_T("Bracelets"));
	combo.AddString(_T("Necklaces"));
	combo.AddString(_T("Jewelleries"));
	combo.AddString(_T("Bags"));
}


void Home::OnBnClickedRadio6()
{
	combo.ResetContent();
	combo.AddString(_T("Cosmetics"));
	combo.AddString(_T("Skin care"));
	combo.AddString(_T("Perfumes"));
	combo.AddString(_T("Hair care"));
	combo.AddString(_T("Makeup"));
}


void Home::OnBnClickedButton2()
{
	string filter;
	CString cfilter;
	GetDlgItemText(IDC_COMBO1, cfilter);
	CStringA cfilterA(cfilter);
	filter = cfilterA.GetBuffer();
	ifstream file;
	string test;
	string name;
	
	file.open("selling.txt");
	
	combobo.ResetContent();
	while (!file.eof())
	{
		
		getline(file, test);
		if (test == filter) {
			
			getline(file, name);
			CString cname(name.c_str());
			combobo.AddString(cname);
			
			
		}



	}
	
}


void Home::OnBnClicked11()
{
	string filter;
	CString cfilter;
	GetDlgItemText(IDC_EDIT1, cfilter);
	CStringA cfilterA(cfilter);
	filter = cfilterA.GetBuffer();
	ifstream file;
	string test;
	string name;

	file.open("selling.txt");
	combobo.ResetContent();
	while (!file.eof())
	{

		getline(file, test);
		if (test.find(filter)<50) {

			CString cfilter(test.c_str());
			combobo.AddString(cfilter);


		}



	}
}


void Home::OnCbnSelchangeCombo1()
{
	string filter;
	CString cfilter;
	GetDlgItemText(IDC_COMBO1, cfilter);
	CStringA cfilterA(cfilter);
	filter = cfilterA.GetBuffer();

	

}


void Home::OnLbnDblclkList1()
{
	string test, category, subcategory, productdesc, username, id, mail, phoneno, productsp, price, condition;
    CString ctest;
	combobo.GetText(combobo.GetCurSel(), ctest);
	CStringA ctestA(ctest);
	test = ctestA.GetBuffer();
	ifstream file;
	ofstream file2;
	file.open("selling.txt");
	file2.open("tempproduct.txt",ios::trunc);
	string x;
	while (!file.eof()) {
		getline(file, x);
		if (x == test) {
			getline(file, category), getline(file, productdesc), getline(file, productsp), getline(file, price), getline(file, mail), getline(file, condition), getline(file, phoneno);
			file2 << test << endl << category << endl << productdesc << endl << productsp << endl << price << endl << mail << endl << condition << endl << phoneno << endl;
}
		
	}

	ProductPage product;
	ShowWindow(SW_HIDE);
	product.DoModal();
}


void Home::OnLbnSelchangeList1()
{
	
}





void Home::OnBnClickedC()
{
	RecievedRequests x;
	ShowWindow(SW_HIDE);
	x.DoModal();

	
}


void Home::OnBnClickedButton19()
{
	MyProducts x;
	ShowWindow(SW_HIDE);
	x.DoModal();

}
