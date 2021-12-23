
// mfc.21.12.23.v1.shutdownDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "mfc.21.12.23.v1.shutdown.h"
#include "mfc.21.12.23.v1.shutdownDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// Cmfc211223v1shutdownDlg 对话框



Cmfc211223v1shutdownDlg::Cmfc211223v1shutdownDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC211223V1SHUTDOWN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmfc211223v1shutdownDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cmfc211223v1shutdownDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &Cmfc211223v1shutdownDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &Cmfc211223v1shutdownDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmfc211223v1shutdownDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cmfc211223v1shutdownDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// Cmfc211223v1shutdownDlg 消息处理程序

BOOL Cmfc211223v1shutdownDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	/*HICON m_hIcon;
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);*/
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	//m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	



	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cmfc211223v1shutdownDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cmfc211223v1shutdownDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cmfc211223v1shutdownDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cmfc211223v1shutdownDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cmfc211223v1shutdownDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cmdup("/c shutdown -s -t ");
	CEdit* pedit = (CEdit*)GetDlgItem(IDC_EDIT1);
	CString edit_text;
	int num;
	pedit->GetWindowText(edit_text);
	num = _ttoi(edit_text);
	num = num * 60;
	edit_text.Format(_T("%d"), num);
	CString cmd = cmdup + edit_text;


	HINSTANCE res = ShellExecute(NULL, "open", "cmd.exe", cmd, NULL, SW_SHOW);
	if ((DWORD)res <= 32 )
	{
		CStatic* ptext = (CStatic*)GetDlgItem(IDC_STATIC3);
		CString sc("当前状态：设定失败");
		ptext->SetWindowTextA(sc);
	}
	else
	{
		CStatic* ptext = (CStatic*)GetDlgItem(IDC_STATIC3);
		CString sc("当前状态：设定成功");
		ptext->SetWindowTextA(sc);
	}
	
	//MessageBox(cmd, _T("程序"));

}


void Cmfc211223v1shutdownDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cmdup("/c shutdown -r -t ");
	CEdit* pedit = (CEdit*)GetDlgItem(IDC_EDIT1);
	CString edit_text;
	int num;
	pedit->GetWindowText(edit_text);
	num = _ttoi(edit_text);
	num = num * 60;
	edit_text.Format(_T("%d"), num);
	CString cmd = cmdup + edit_text;
	HINSTANCE res = ShellExecute(NULL, "open", "cmd.exe", cmd, NULL, SW_SHOW);
	if ((DWORD)res <= 32)
	{
		CStatic* ptext = (CStatic*)GetDlgItem(IDC_STATIC3);
		CString sc("当前状态：设定失败");
		ptext->SetWindowTextA(sc);
	}
	else
	{
		CStatic* ptext = (CStatic*)GetDlgItem(IDC_STATIC3);
		CString sc("当前状态：设定成功");
		ptext->SetWindowTextA(sc);
	}
}


void Cmfc211223v1shutdownDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cmd("/c shutdown -a ");
	HINSTANCE res = ShellExecute(NULL, "open", "cmd.exe", cmd, NULL, SW_SHOW);
	if ((DWORD)res <= 32)
	{
		CStatic* ptext = (CStatic*)GetDlgItem(IDC_STATIC3);
		CString sc("当前状态：取消失败");
		ptext->SetWindowTextA(sc);
	}
	else
	{
		CStatic* ptext = (CStatic*)GetDlgItem(IDC_STATIC3);
		CString sc("当前状态：取消成功");
		ptext->SetWindowTextA(sc);
	}
}
