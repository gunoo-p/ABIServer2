
// ABIServer2Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ABIServer2.h"
#include "ABIServer2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CABIServer2Dlg 대화 상자
CABIServer2App* m_App = (CABIServer2App*)AfxGetApp();;


CABIServer2Dlg::CABIServer2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ABISERVER2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	wsDlg = NULL;
	pdtRoot = 0;
	loginRoot = 0;
	clientRoot = 0;
	saleRoot = 0;
	saleShop = 0;
	saleShop_m = 0;
}

void CABIServer2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TreeMenu, m_TreeMenu);
	DDX_Control(pDX, IDC_DescriptionList, m_lstDescription);
}

BEGIN_MESSAGE_MAP(CABIServer2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_DBLCLK, IDC_TreeMenu, &CABIServer2Dlg::OnDblclkTreemenu)
END_MESSAGE_MAP()


// CABIServer2Dlg 메시지 처리기

BOOL CABIServer2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	SetWindowPos(NULL, 0, 0, 1920, 1070, SWP_SHOWWINDOW);
	m_TreeMenu.SetWindowPos(NULL, 15, 20, 220, 720, SWP_SHOWWINDOW);
	m_lstDescription.SetWindowPos(NULL, 15, 750, 1880, 300, SWP_SHOWWINDOW);

	Init_WorkSheet();
	Init_ConnectList();

	CreateTreeMenu();

	ShowWindow(SW_SHOWMAXIMIZED); 
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CABIServer2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CABIServer2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CABIServer2Dlg::Init_WorkSheet()
{
	/*if (!wsDlg)
	{
		wsDlg = new WorkSheetDlg;
		wsDlg->Create(IDD_WorkSheetDlg);
		wsDlg->SetWindowPos(NULL, 250, 21, 1170, 720, SWP_SHOWWINDOW);
		wsDlg->ShowWindow(true);
	}
	else 
	{
		wsDlg->ShowWindow(true);
	}*/
}

void CABIServer2Dlg::Init_ConnectList()
{
	if (!connectDlg)
	{
		connectDlg = new ConnectDlg;
		connectDlg->Create(IDD_ConnectDlg);
		connectDlg->SetWindowPos(NULL, 1440, 21, 455, 720, SWP_SHOWWINDOW);
		connectDlg->ShowWindow(true);
	}
	else
	{
		connectDlg->ShowWindow(true);
	}
}

/* 
	p : POS       d : Day
	k : Kiosk     m : Month
	m : Mobile    y : Year
	s : Shop
*/
void CABIServer2Dlg::CreateTreeMenu()
{
	CFont font;
	LOGFONT logFont;

	GetDlgItem(IDC_TreeMenu)->GetFont()->GetLogFont(&logFont);

	logFont.lfHeight = 139;
	//logFont.lfWeight = FW_BOLD;

	font.CreatePointFontIndirect(&logFont);
	GetDlgItem(IDC_TreeMenu)->SetFont(&font);

	// 제품정보
	pdtRoot = m_TreeMenu.InsertItem(L"제품정보", 0, 0, TVI_ROOT, TVI_LAST);
	m_TreeMenu.InsertItem(L"제품리스트", 0, 0, pdtRoot, TVI_LAST);
	m_TreeMenu.InsertItem(L"품절리스트", 0, 0, pdtRoot, TVI_LAST);

	//로그인정보
	loginRoot = m_TreeMenu.InsertItem(L"로그인 정보", 0, 0, TVI_ROOT, TVI_LAST);
	m_TreeMenu.InsertItem(L"POS 로그인", 0, 0, loginRoot, TVI_LAST);
	m_TreeMenu.InsertItem(L"Mobile 로그인", 0, 0, loginRoot, TVI_LAST);
	
	//고객 정보
	clientRoot = m_TreeMenu.InsertItem(L"고객 정보", 0, 0, TVI_ROOT, TVI_LAST);
	m_TreeMenu.InsertItem(L"지점 정보", 0, 0, clientRoot, TVI_LAST);
	m_TreeMenu.InsertItem(L"Mobile 회원 정보", 0, 0, clientRoot, TVI_LAST);
	
	// 결제 정보
	saleRoot = m_TreeMenu.InsertItem(L"결제 정보", 0, 0, TVI_ROOT, TVI_LAST);

		// 지점별 결제
		saleShop = m_TreeMenu.InsertItem(L"지점별 결제", 0, 0, saleRoot, TVI_LAST);
			m_TreeMenu.InsertItem(L"POS 결제", 0, 0, saleShop, TVI_LAST);
			m_TreeMenu.InsertItem(L"Kiosk 결제", 0, 0, saleShop, TVI_LAST);
			saleShop_m = m_TreeMenu.InsertItem(L"Mobile 결제", 0, 0, saleShop, TVI_LAST);
				m_TreeMenu.InsertItem(L"예약 결제", 0, 0, saleShop_m, TVI_LAST);
				m_TreeMenu.InsertItem(L"실시간 결제", 0, 0, saleShop_m, TVI_LAST);

		// 통합 Kiosk 주문
		saleAll_K = m_TreeMenu.InsertItem(L"통합 Kiosk 주문", 0, 0, saleRoot, TVI_LAST);

		// 통합 Mobile 주문
		saleAll_M = m_TreeMenu.InsertItem(L"통합 Mobile 주문", 0, 0, saleRoot, TVI_LAST);
			m_TreeMenu.InsertItem(L"예약 결제", 0, 0, saleAll_M, TVI_LAST);
			m_TreeMenu.InsertItem(L"실시간 결제", 0, 0, saleAll_M, TVI_LAST);

		// 모바일 내역 보고서
		saleReport_M = m_TreeMenu.InsertItem(L"모바일 내역 보고서", 0, 0, saleRoot, TVI_LAST);
			m_TreeMenu.InsertItem(L"일별 조회", 0, 0, saleReport_M, TVI_LAST);
			m_TreeMenu.InsertItem(L"월별 조회", 0, 0, saleReport_M, TVI_LAST);
			m_TreeMenu.InsertItem(L"년도별 조회", 0, 0, saleReport_M, TVI_LAST);

		// 지점별 내역 보고서
		saleReport_S = m_TreeMenu.InsertItem(L"지점별 내역 보고서", 0, 0, saleRoot, TVI_LAST);
			m_TreeMenu.InsertItem(L"일별 조회", 0, 0, saleReport_S, TVI_LAST);
			m_TreeMenu.InsertItem(L"월별 조회", 0, 0, saleReport_S, TVI_LAST);
			m_TreeMenu.InsertItem(L"년도별 조회", 0, 0, saleReport_S, TVI_LAST);

}

void CABIServer2Dlg::OnDblclkTreemenu(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	HTREEITEM SelectTreeMenu = m_TreeMenu.GetSelectedItem();
	if (m_TreeMenu.GetChildItem(SelectTreeMenu) == NULL)
	{
		//::MessageBox(NULL, L"D", m_TreeMenu.GetItemText(hItem), MB_OK);
		if (m_TreeMenu.GetItemText(SelectTreeMenu) == L"제품리스트") {
			m_App->wsFlag = 1;
		}
	}
}
