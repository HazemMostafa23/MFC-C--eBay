// MyProducts.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "MyProducts.h"
#include "afxdialogex.h"
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <cstdio>
#include "Account.h"

CString cprice;
CString ccat;
CString ccondition;
CString cspecs;
CString cdesc;

using namespace std;
// MyProducts dialog

IMPLEMENT_DYNAMIC(MyProducts, CDialogEx)

BOOL MyProducts::OnInitDialog() {
	CDialog::OnInitDialog();
	cond.AddString(_T("New"));
	cond.AddString(_T("Used"));
	string logmail,test,subcat,cat,title,desc,specs,price,condition,mail,number;
	ifstream file1;
	ifstream file2;
	file1.open("log.txt");
	file2.open("selling.txt");
	int i = 0;
	while (3 > i) {
		getline(file1, logmail);
		i++;
	}

	while (!file2.eof()) {
		getline(file2, subcat), getline(file2, title), getline(file2, cat), getline(file2, desc), getline(file2, specs), getline(file2, price), getline(file2, condition), getline(file2, mail), getline(file2, number);
		if (mail == logmail) {
			CString ctitle(title.c_str());
			combo.AddString(ctitle);

		}



	}
	return TRUE;
}
MyProducts::MyProducts(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG14, pParent)
{

}

MyProducts::~MyProducts()
{
}

void MyProducts::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, combo);
	DDX_Control(pDX, IDC_COMBO1, cond);
}


BEGIN_MESSAGE_MAP(MyProducts, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &MyProducts::OnLbnSelchangeList1)
	ON_LBN_DBLCLK(IDC_LIST1, &MyProducts::OnLbnDblclkList1)
	ON_EN_CHANGE(IDC_EDIT4, &MyProducts::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON2, &MyProducts::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON11, &MyProducts::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON20, &MyProducts::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &MyProducts::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &MyProducts::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &MyProducts::OnBnClickedButton23)
	ON_EN_CHANGE(IDC_EDIT9, &MyProducts::OnEnChangeEdit9)
	ON_BN_CLICKED(IDC_BUTTON24, &MyProducts::OnBnClickedButton24)
END_MESSAGE_MAP()


// MyProducts message handlers


void MyProducts::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}


void MyProducts::OnLbnDblclkList1()
{
	string test,title, subcat, cat,desc, specs, price, condition, mail, number;;
	ifstream file1;
	CString ctitle;
	combo.GetText(combo.GetCurSel(), ctitle);
	CStringA ctitleA(ctitle);
	title = ctitleA.GetBuffer();
	file1.open("selling.txt");
	while (!file1.eof()) {
		getline(file1, test);
		if (test == title) {
			getline(file1, cat), getline(file1, desc), getline(file1, specs), getline(file1, price), getline(file1, condition), getline(file1, mail);

		}


	}
	cprice=(price.c_str());
	ccat=(cat.c_str());
	ccondition=(condition.c_str());
	cspecs = (specs.c_str());
	cdesc = (desc.c_str());
	SetDlgItemText(IDC_EDIT1, ctitle);
	SetDlgItemText(IDC_EDIT2, cprice);
	SetDlgItemText(IDC_EDIT7, cspecs);
	SetDlgItemText(IDC_EDIT4, ccondition);
	SetDlgItemText(IDC_EDIT11, cdesc);
}


void MyProducts::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void MyProducts::OnBnClickedButton2()
{
	ifstream file1;
	ofstream file2;
	string title, title2;
	file1.open("selling.txt");
	file2.open("tempselling.txt");
	CString ctitle;
	GetDlgItemText(IDC_EDIT1, ctitle);

	CStringA ctitleA(ctitle);
	title = ctitleA.GetBuffer();
	string test;
	CString ctitle2;
	GetDlgItemText(IDC_EDIT9, ctitle2);
	
	CStringA ctitle2A(ctitle2);
	title2 = ctitle2A.GetBuffer();
	if (title2.length() != 0) {
		while (!file1.eof()) {
			getline(file1, test);

			if (test == title) {
				
				
				file2 << title2 << endl;


			}
			else file2 << test << endl;
		}
		file1.close();
		file2.close();
		remove("selling.txt");
		rename("tempselling.txt", "selling.txt");
		MessageBox(_T("Modified"));
	}
	else MessageBox(_T("Empty field"));
}


void MyProducts::OnBnClickedButton11()
{
	ifstream file1;
	ofstream file2;
	string title, title2;
	file1.open("selling.txt");
	file2.open("tempselling.txt");
	CString ctitle;
	GetDlgItemText(IDC_EDIT2, ctitle);

	CStringA ctitleA(ctitle);
	title = ctitleA.GetBuffer();
	string test;
	CString ctitle2;
	GetDlgItemText(IDC_EDIT9, ctitle2);

	CStringA ctitle2A(ctitle2);
	title2 = ctitle2A.GetBuffer();
	if (title2.length() != 0) {
		while (!file1.eof()) {
			getline(file1, test);

			if (test == title) {
				
				
				file2 << title2 << endl;


			}
			else file2 << test << endl;
		}
		file1.close();
		file2.close();
		remove("selling.txt");
		rename("tempselling.txt", "selling.txt");
		MessageBox(_T("Modified"));
	}
	else MessageBox(_T("Empty field."));
}


void MyProducts::OnBnClickedButton20()
{
	ifstream file1;
	ofstream file2;
	string title, title2;
	file1.open("selling.txt");
	file2.open("tempselling.txt");
	CString ctitle;
	GetDlgItemText(IDC_EDIT4, ctitle);

	CStringA ctitleA(ctitle);
	title = ctitleA.GetBuffer();
	string test;
	CString ctitle2;
	GetDlgItemText(IDC_EDIT9, ctitle2);

	CStringA ctitle2A(ctitle2);
	title2 = ctitle2A.GetBuffer();
	if (title2.length() != 0) {
		while (!file1.eof()) {
			getline(file1, test);

			if (test == title) {
				
				
				file2 << title2 << endl;


			}
			else file2 << test << endl;
		}
		file1.close();
		file2.close();
		remove("selling.txt");
		rename("tempselling.txt", "selling.txt");
		MessageBox(_T("Modified"));
	}
	else MessageBox(_T("Empty field."));
}

void MyProducts::OnBnClickedButton21()
{
	ifstream file1;
	ofstream file2;
	string title, title2;
	file1.open("selling.txt");
	file2.open("tempselling.txt");
	CString ctitle;
	GetDlgItemText(IDC_EDIT7, ctitle);

	CStringA ctitleA(ctitle);
	title = ctitleA.GetBuffer();
	string test;
	CString ctitle2;
	GetDlgItemText(IDC_EDIT9, ctitle2);

	CStringA ctitle2A(ctitle2);
	title2 = ctitle2A.GetBuffer();
	if (title2.length()!=0) {
		while (!file1.eof()) {
			getline(file1, test);

			if (test == title) {
				
				
				file2 << title2 << endl;


			}
			else file2 << test << endl;
		}
		file1.close();
		file2.close();
		remove("selling.txt");
		rename("tempselling.txt", "selling.txt");
		MessageBox(_T("Modified"));
	}
	else MessageBox(_T("Empty field"));
}
void MyProducts::OnBnClickedButton22()
{
	Account x;
	ShowWindow(SW_HIDE);
	x.DoModal();

}


void MyProducts::OnBnClickedButton23()
{
	ifstream file1;
	ofstream file2;
	string title, title2;
	file1.open("selling.txt");
	file2.open("tempselling.txt");
	CString ctitle;
	GetDlgItemText(IDC_EDIT11, ctitle);

	CStringA ctitleA(ctitle);
	title = ctitleA.GetBuffer();
	string test;
	CString ctitle2;
	GetDlgItemText(IDC_EDIT9, ctitle2);

	CStringA ctitle2A(ctitle2);
	title2 = ctitle2A.GetBuffer();
	if (title2.length()!=0) {
		while (!file1.eof()) {
			getline(file1, test);

			if (test == title) {
				
				
				file2 << title2 << endl;


			}
			else file2 << test << endl;
		}
		file1.close();
		file2.close();
		remove("selling.txt");
		rename("tempselling.txt", "selling.txt");
		MessageBox(_T("Modified"));
	}
	else MessageBox(_T("Empty Field."));
}

void MyProducts::OnEnChangeEdit9()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void MyProducts::OnBnClickedButton24()
{
	ifstream file;
	ofstream file2;
	file.open("selling.txt");
	file2.open("tempselling.txt");
	CString ctitle;
	string title, test,test_next;
	combo.GetText(combo.GetCurSel(), ctitle);
	CStringA ctitleA(ctitle);
	title = ctitleA.GetBuffer();
	int count;
	while (!file.eof()) {
		
		getline(file, test);
		getline(file, test_next);
		if (test_next != title && !file.eof()) {
			file2 << test << endl;
			file2 << test_next << endl;

		}
		else for (count = 0; count < 7; count++) {
			getline(file, test);
		}
			


	}
	file.close();
	file2.close();
	remove("selling.txt");
	rename("tempselling.txt", "selling.txt");
	MessageBox(_T("Product deleted"));
}
