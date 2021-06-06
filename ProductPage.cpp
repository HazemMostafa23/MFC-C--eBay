// ProductPage.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "ProductPage.h"
#include "afxdialogex.h"
#include "Transaction.h"
#include "Search.h"
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include "Home.h"
using namespace std;



// ProductPage dialog

IMPLEMENT_DYNAMIC(ProductPage, CDialogEx)

BOOL ProductPage::OnInitDialog() {
	ifstream file;
	file.open("tempproduct.txt");
	string title, price, category, specs, mobileno, mail, condition,subcategory,desc,rating;
	/*getline(file, subcategory),*/ getline(file, title), getline(file, category), getline(file, desc), getline(file, specs), getline(file, price), getline(file, condition), getline(file, mail), getline(file, mobileno);
	CString ctitle(title.c_str());
	CString ccategory(category.c_str());
	CString cdesc(desc.c_str());
	CString cspecs(specs.c_str());
	CString cprice(price.c_str());
	CString cconditon(condition.c_str());
	CString cmail(mail.c_str());
	CString cmobileno(mobileno.c_str());
	CString crating(rating.c_str());

	SetDlgItemText(1002, ctitle);
	SetDlgItemText(1003, cprice);
	SetDlgItemText(1004, ccategory);
	SetDlgItemText(IDC_EDIT5, cspecs);
	SetDlgItemText(IDC_EDIT7, cmobileno);
	SetDlgItemText(IDC_EDIT8, cmail);
	SetDlgItemText(IDC_EDIT6, crating);
	SetDlgItemText(IDC_EDIT18, cconditon);
	SetDlgItemText(IDC_EDIT1, cdesc);
	return TRUE;



}
ProductPage::ProductPage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION5_DIALOG, pParent)
{

}

ProductPage::~ProductPage()
{
}

void ProductPage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ProductPage, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &ProductPage::OnBnClickedButton4)
	
	ON_BN_CLICKED(IDDDDDD, &ProductPage::OnBnClickedDdddd)
END_MESSAGE_MAP()


// ProductPage message handlers


void ProductPage::OnBnClickedButton4()
{
	Transaction transaction;
	ShowWindow(SW_HIDE);
	transaction.DoModal();
	
}




void ProductPage::OnBnClickedDdddd()
{
	Home home;
	ShowWindow(SW_HIDE);
	home.DoModal();
}
