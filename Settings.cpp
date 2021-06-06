// Settings.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "Settings.h"
#include "afxdialogex.h"
#include "Home.h"
#include "Account.h"
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdio>
using namespace std;


// Settings dialog

IMPLEMENT_DYNAMIC(Settings, CDialogEx)

Settings::Settings(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG9, pParent)
{

}

Settings::~Settings()
{
}

void Settings::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Settings, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &Settings::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &Settings::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON9, &Settings::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON11, &Settings::OnBnClickedButton11)
END_MESSAGE_MAP()


// Settings message handlers


void Settings::OnBnClickedButton3()
{
	Account account;
	ShowWindow(SW_HIDE);
	account.DoModal();
	
}


void Settings::OnBnClickedButton1()
{
	string password, opassword,npassword,confirm,tpassword,tid;
	CString copassword,cnpassword,cconfirm;
	GetDlgItemText(IDC_EDIT1, copassword);
	GetDlgItemText(IDC_EDIT2, cnpassword);
	GetDlgItemText(IDC_EDIT3, cconfirm);
	CStringA copasswordA(copassword);
	CStringA cnpasswordA(cnpassword);
	CStringA cconfirmA(cconfirm);
	opassword = copasswordA.GetBuffer();
	npassword = cnpasswordA.GetBuffer();
	confirm = cconfirmA.GetBuffer();
	ifstream file;
	ifstream file3;
	ofstream temp;
	
	file.open("pass.txt");
	getline(file, password);
	file3.open("register.txt");
	temp.open("temp.txt");
	
	string x;
	if (opassword.length() != 0 && npassword.length() != 0 && confirm.length() != 0) {
		if (password == opassword) {
			if (npassword == confirm) {
				while (!file3.eof()) {
					getline(file3, x);
					if (x == opassword) {
						temp << npassword << endl;

					}
					else temp << x << endl;

				}
				temp.close();
				file.close();
				file3.close();
				remove("register.txt");
				rename("temp.txt", "register.txt");
				MessageBox(_T("Password changed successfully"));
			}
			else MessageBox(_T("password&confirmation dont match"));
		}
		else MessageBox(_T("old password is wrong"));
	}
	else MessageBox(_T("Fill the empty fields"));
}


void Settings::OnBnClickedButton9()
{
	MessageBox(_T("Email changed successfully"));
}


void Settings::OnBnClickedButton11()
{
	/*CString cmobileno;
	string amobileno,mail,id,name,mobileno;
	GetDlgItemText(IDC_EDIT3, cmobileno);
	CStringA cmobilenoA(cmobileno);
	mobileno = cmobilenoA.GetBuffer();
	ifstream file;
	ofstream file2;
	ifstream file3;
	file.open("database.txt");
	file2.open("temp2.txt");
	file3.open("log.txt");
	getline(file3, name), getline(file3, id), getline(file3, mail), getline(file, amobileno);
	string x;
	while (!file.eof()) {
		getline(file, x);
		if (x == amobileno) {
			file2 << mobileno << endl;

		}
		else file2 << x << endl;
	}
	file.close();
	file2.close();
	file3.close();
	remove("database.txt");
	rename("temp2.txt", "database.txt");

		*/
	MessageBox(_T("Mobile number changed successfully"));

	}
	
	

