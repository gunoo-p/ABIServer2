// ConnectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ABIServer2.h"
#include "ConnectDlg.h"
#include "afxdialogex.h"


// ConnectDlg 대화 상자

IMPLEMENT_DYNAMIC(ConnectDlg, CDialogEx)

ConnectDlg::ConnectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ConnectDlg, pParent)
{

}

ConnectDlg::~ConnectDlg()
{
}

void ConnectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ConnectDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// ConnectDlg 메시지 처리기


BOOL ConnectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	Create_LstConectPOS();
	Create_LstConectMobile();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void ConnectDlg::Create_LstConectPOS()
{
	m_lstConnectPOS.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS, CRect(0, 0, 800, 500), this, IDC_ConnectPosList);

	m_lstConnectPOS.SetWindowPos(NULL, 25, 40, 400, 300, SWP_SHOWWINDOW);

	m_lstConnectPOS.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_lstConnectPOS.InsertColumn(0, L"No", LVCFMT_CENTER, 50);
	m_lstConnectPOS.InsertColumn(1, L"날짜", LVCFMT_CENTER, 100);
	m_lstConnectPOS.InsertColumn(2, L"시간", LVCFMT_CENTER, 80);
	m_lstConnectPOS.InsertColumn(3, L"접속 IP", LVCFMT_CENTER, 110);
	m_lstConnectPOS.InsertColumn(4, L"지점명", LVCFMT_CENTER, 60);
}

void ConnectDlg::Create_LstConectMobile()
{
	m_lstConnectMobile.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS, CRect(0, 0, 800, 500), this, IDC_ConnectMobileList);

	m_lstConnectMobile.SetWindowPos(NULL, 25, 400, 400, 300, SWP_SHOWWINDOW);

	m_lstConnectMobile.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_lstConnectMobile.InsertColumn(0, L"No", LVCFMT_CENTER, 50);
	m_lstConnectMobile.InsertColumn(1, L"날짜", LVCFMT_CENTER, 100);
	m_lstConnectMobile.InsertColumn(2, L"시간", LVCFMT_CENTER, 80);
	m_lstConnectMobile.InsertColumn(3, L"접속 IP", LVCFMT_CENTER, 170);
}


void ConnectDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	CFont font;
	font.CreatePointFont(100, L"굴림"); // 글씨크기, 폰트
	dc.SelectObject(&font); // 폰트를 dc에 적용

	dc.SetBkMode(TRANSPARENT); // 배경을 투명색
	dc.DrawText(CString("POS 접속 리스트"), CRect(30, 20, 300, 100), 0);
	dc.DrawText(CString("Mobile 접속 리스트"), CRect(30, 380, 300, 400), 0);
}
