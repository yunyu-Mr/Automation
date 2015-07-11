// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Automation.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg dialog

IMPLEMENT_DYNAMIC(CLoginDlg, CDialog)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
	, m_Passwd(_T(""))
	, m_Username(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PASSWD_EDIT, m_Passwd);
	DDX_Text(pDX, IDC_USERNAME_EDIT, m_Username);
	DDX_Control(pDX, IDC_USERNAME_EDIT, m_EditUsername);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CLoginDlg message handlers


void CLoginDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	bool validLogin = false;

	if( m_Username == "" ){
		AfxMessageBox(L"请输入用户名^_^");
		return;
	}
	if( m_Passwd == "" ){
		AfxMessageBox(L"请输入密码^_^");
		return;
	}
	//Connect DB to check password
	if (m_Username == "auto" && m_Passwd == "123" ) {
		validLogin = true;
	} else {
		validLogin = false;
	}

	if (validLogin) {
		CDialog::OnOK();
	} else {
		AfxMessageBox(L"您输入的密码不对哦！请检查用户名和密码是否输入正确亲~");
		this->m_EditUsername.SetFocus();
	}
	UpdateData(FALSE);
}
