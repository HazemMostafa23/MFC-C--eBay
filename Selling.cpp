// Selling.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "Selling.h"
#include "afxdialogex.h"
#include "Home.h"
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;


// Selling dialog

IMPLEMENT_DYNAMIC(Selling, CDialogEx)

Selling::Selling(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG8, pParent)
{

}

Selling::~Selling()
{
}

void Selling::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, combobo);
	DDX_Control(pDX, IDC_COMBO3, combobo3);
	DDX_Control(pDX, IDC_COMBO2, combobo2);
	DDX_Control(pDX, IDC_STATIC_1, photo);
}


BEGIN_MESSAGE_MAP(Selling, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &Selling::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_COMBO2, &Selling::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDOK, &Selling::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Selling::OnCbnSelchangeCombo1)
	
	ON_BN_CLICKED(IDC_BUTTON2, &Selling::OnBnClickedButton2)
END_MESSAGE_MAP()


// Selling message handlers
BOOL Selling::OnInitDialog() {

	CDialogEx::OnInitDialog();
	combobo.AddString(_T("Electronics"));
	combobo.AddString(_T("Appliances"));
	combobo.AddString(_T("Fashion"));
	combobo.AddString(_T("Accessoires"));
	combobo.AddString(_T("Health&Beauty"));
	combobo2.AddString(_T("New"));
	combobo2.AddString(_T("Used"));


	return TRUE;
}

void Selling::OnBnClickedCancel()
{
	Home homepage;
	ShowWindow(SW_HIDE);
	homepage.DoModal();
	
}


void Selling::OnCbnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
}


void Selling::OnBnClickedOk()
{
	string title,category,subcategory,productdesc,username,id,mail,phoneno;
	CString ctitle,ccategory,csubcategory,cproductdesc;
	string productsp, price, condition;
	CString cproductsp, cprice, ccondition;
	GetDlgItemText(IDC_EDIT1, ctitle);
	GetDlgItemText(IDC_COMBO1, ccategory);
	GetDlgItemText(IDC_COMBO3, csubcategory);
	GetDlgItemText(IDC_EDIT3, cproductdesc);
	GetDlgItemText(IDC_EDIT4, cproductsp);
	GetDlgItemText(IDC_EDIT2, cprice);
	GetDlgItemText(IDC_COMBO2, ccondition);
	CStringA ctitleA(ctitle);
	CStringA ccategoryA(ccategory);
	CStringA csubcategoryA(csubcategory);
	CStringA cproductdescA(cproductdesc);
	CStringA cproductspA(cproductsp);
	CStringA cpriceA(cprice);
	CStringA cconditionA(ccondition);
    title = ctitleA.GetBuffer();
	category = ccategoryA.GetBuffer();
	subcategory = csubcategoryA.GetBuffer();
	productdesc = cproductdescA.GetBuffer();
	productsp = cproductspA.GetBuffer();
	price = cpriceA.GetBuffer();
	condition = cconditionA.GetBuffer();
	bool conditionID = true;
	for (int i = 0; i < price.length(); i++) {
		if (!(price[i] >= '0' && price[i] <= '9')) {
			conditionID = false;
			break;
		}
	}
	if (title.length() != 0 && category.length() != 0 && subcategory.length() != 0 && productdesc.length() != 0&&productsp.length()!=0&&price.length()!=0&&condition.length()!=0) {
		if (title.length() < 60) {
			if (conditionID == true) {
				ifstream file2;
				file2.open("log.txt");
				getline(file2, username), getline(file2, id), getline(file2, mail), getline(file2, phoneno);
				ofstream file;
				file.open("selling.txt", ios::app);
				file << subcategory << endl << title << endl << category << endl << productdesc << endl << productsp << endl << price << endl << condition << endl<<mail<<endl<<phoneno<<endl;
				file.close();
				
				Home homepage;
				MessageBox(_T("Your product has been listed"));
				ShowWindow(SW_HIDE);
				homepage.DoModal();
				
			
			}
			else MessageBox(_T("Price should only be numbers"));
		}
		else MessageBox(_T("Product title shoudn't be more than 50 charactar"));
	}
	else MessageBox(_T("Fill all the missing fields"));
	
}



void Selling::OnCbnSelchangeCombo1()
{

	CString cBox1;
	string Box1;
	combobo.GetLBText(combobo.GetCurSel(), cBox1);
	CStringA cBox1A(cBox1);
	Box1 = cBox1A.GetBuffer();

	if (Box1 == "Electronics") {
		combobo3.ResetContent();
		combobo3.AddString(_T("Tvs"));
		combobo3.AddString(_T("Mobiles"));
		combobo3.AddString(_T("Cameras"));
		combobo3.AddString(_T("Laptops"));
		combobo3.AddString(_T("Headphones"));

	}
	else if (Box1 == "Appliances") {
		combobo3.ResetContent();
		combobo3.AddString(_T("Refrigators"));
		combobo3.AddString(_T("Washers"));
		combobo3.AddString(_T("Ovens"));
		combobo3.AddString(_T("Air Conditioners"));
		combobo3.AddString(_T("Fans"));
	}
	else if (Box1 == "Fashion") {

		combobo3.ResetContent();
		combobo3.AddString(_T("Tshirts"));
		combobo3.AddString(_T("Shorts"));
		combobo3.AddString(_T("Pants"));
		combobo3.AddString(_T("Jackets"));
		combobo3.AddString(_T("Shoes"));
	}
	else if (Box1 == "Accessoires") {
		combobo3.ResetContent();
		combobo3.AddString(_T("Watches"));
		combobo3.AddString(_T("Bracelets"));
		combobo3.AddString(_T("Necklaces"));
		combobo3.AddString(_T("Jewelleries"));
		combobo3.AddString(_T("Bags"));

	}
	else if (Box1 == "Health&Beauty") {
		combobo3.ResetContent();
		combobo3.AddString(_T("Cosmetics"));
		combobo3.AddString(_T("Skin care"));
		combobo3.AddString(_T("Perfumes"));
		combobo3.AddString(_T("Hair care"));
		combobo3.AddString(_T("Makeup"));

	}
}



void Selling::OnBnClickedButton2()
{

	TCHAR strFilters[] = { _T("PNG Files(.png)|.png|JPG Files(.jpg)|.jpg|BMP Files(.bmp)|.bmp||") };
	CFileDialog x(TRUE, _T("png"), _T(""),
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, strFilters, NULL);
	x.DoModal();
	CString cbrowse;
	cbrowse = x.GetPathName();
	photo.Load(cbrowse);

}
