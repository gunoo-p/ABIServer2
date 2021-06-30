// WorkSheetDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ABIServer2.h"
#include "WorkSheetDlg.h"
#include "afxdialogex.h"
#include "ABIServer2Dlg.h"

// WorkSheetDlg 대화 상자

IMPLEMENT_DYNAMIC(WorkSheetDlg, CDialogEx)

WorkSheetDlg::WorkSheetDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WorkSheetDlg, pParent)
{

}

WorkSheetDlg::~WorkSheetDlg()
{
}

void WorkSheetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(WorkSheetDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// WorkSheetDlg 메시지 처리기


BOOL WorkSheetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void WorkSheetDlg::CreatePdtList()
{
	if (!m_pdtList) {
		m_pdtList.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS, CRect(0, 0, 800, 500), this, IDC_ProductList);
		m_pdtList.SetWindowPos(NULL, 30, 120, 1107, 580, SWP_SHOWWINDOW);

		m_pdtList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		m_pdtList.InsertColumn(0, L"제품코드", LVCFMT_LEFT, 100);
		m_pdtList.InsertColumn(1, L"메뉴", LVCFMT_LEFT, 100);
		m_pdtList.InsertColumn(2, L"제품 이름", LVCFMT_LEFT, 100);
		m_pdtList.InsertColumn(3, L"지점명", LVCFMT_LEFT, 100);
		m_pdtList.InsertColumn(4, L"분류", LVCFMT_LEFT, 100);
		m_pdtList.InsertColumn(5, L"가격", LVCFMT_LEFT, 100);
		m_pdtList.InsertColumn(6, L"상태", LVCFMT_LEFT, 100);
	}
	else
	{
		if(m_soldoutList)
		{ 
			m_soldoutList.DeleteAllItems();
		}
		else if(m_posLoginList)
		{
			m_posLoginList.DeleteAllItems();
		}
		else if (m_mobileLoginList)
		{
			m_mobileLoginList.DeleteAllItems();
		}
		else if (m_shopInfoList)
		{
			m_shopInfoList.DeleteAllItems();
		}
		else if (m_memberList)
		{
			m_memberList.DeleteAllItems();
		}
		return;
	}	
}


void WorkSheetDlg::CreateSoldOutList()
{
	if (!m_soldoutList) {
		m_soldoutList.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS, CRect(0, 0, 800, 500), this, IDC_SoldOutList);
		m_soldoutList.SetWindowPos(NULL, 30, 120, 1107, 580, SWP_SHOWWINDOW);

		m_soldoutList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		m_soldoutList.InsertColumn(0, L"No", LVCFMT_LEFT, 100);
		m_soldoutList.InsertColumn(1, L"메뉴", LVCFMT_LEFT, 100);
		m_soldoutList.InsertColumn(2, L"제품 이름", LVCFMT_LEFT, 100);
		m_soldoutList.InsertColumn(3, L"지점명", LVCFMT_LEFT, 100);
		m_soldoutList.InsertColumn(4, L"분류", LVCFMT_LEFT, 100);
		m_soldoutList.InsertColumn(5, L"가격", LVCFMT_LEFT, 100);
		m_soldoutList.InsertColumn(6, L"상태", LVCFMT_LEFT, 100);
	}
	else
	{
		if (m_pdtList)
		{
			m_pdtList.DeleteAllItems();
		}
		else if (m_posLoginList)
		{
			m_posLoginList.DeleteAllItems();
		}
		else if (m_mobileLoginList)
		{
			m_mobileLoginList.DeleteAllItems();
		}
		else if (m_shopInfoList)
		{
			m_shopInfoList.DeleteAllItems();
		}
		else if (m_memberList)
		{
			m_memberList.DeleteAllItems();
		}
		return;
	}
}


void WorkSheetDlg::CreatePosLoginList()
{
	if (!m_posLoginList) {
		m_posLoginList.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS, CRect(0, 0, 800, 500), this, IDC_POSLoginList);
		m_posLoginList.SetWindowPos(NULL, 30, 120, 1107, 580, SWP_SHOWWINDOW);

		m_posLoginList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		m_posLoginList.InsertColumn(0, L"No", LVCFMT_LEFT, 100);
		m_posLoginList.InsertColumn(1, L"로그인한 시간", LVCFMT_LEFT, 100);
		m_posLoginList.InsertColumn(2, L"로그아웃한 시간", LVCFMT_LEFT, 100);
		m_posLoginList.InsertColumn(3, L"지점명", LVCFMT_LEFT, 100);
	}
	else
	{
		if (m_pdtList)
		{
			m_pdtList.DeleteAllItems();
		}
		else if (m_soldoutList)
		{
			m_soldoutList.DeleteAllItems();
		}
		else if (m_mobileLoginList)
		{
			m_mobileLoginList.DeleteAllItems();
		}
		else if (m_shopInfoList)
		{
			m_shopInfoList.DeleteAllItems();
		}
		else if (m_memberList)
		{
			m_memberList.DeleteAllItems();
		}
		return;
	}
}


void WorkSheetDlg::CreateMobileLoginList()
{
	if (!m_mobileLoginList) {
		m_mobileLoginList.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS, CRect(0, 0, 800, 500), this, IDC_MobileLoginList);
		m_mobileLoginList.SetWindowPos(NULL, 30, 120, 1107, 580, SWP_SHOWWINDOW);

		m_mobileLoginList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		m_mobileLoginList.InsertColumn(0, L"No", LVCFMT_LEFT, 100);
		m_mobileLoginList.InsertColumn(1, L"로그인한 시간", LVCFMT_LEFT, 100);
		m_mobileLoginList.InsertColumn(2, L"로그아웃한 시간", LVCFMT_LEFT, 100);
		m_mobileLoginList.InsertColumn(3, L"이름", LVCFMT_LEFT, 100);
	}
	else
	{
		if (m_pdtList)
		{
			m_pdtList.DeleteAllItems();
		}
		else if (m_soldoutList)
		{
			m_soldoutList.DeleteAllItems();
		}
		else if (m_posLoginList)
		{
			m_posLoginList.DeleteAllItems();
		}
		else if (m_shopInfoList)
		{
			m_shopInfoList.DeleteAllItems();
		}
		else if (m_memberList)
		{
			m_memberList.DeleteAllItems();
		}
		return;
	}
}


void WorkSheetDlg::CreateShopInfoList()
{
	if (!m_shopInfoList) {
		m_shopInfoList.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS, CRect(0, 0, 800, 500), this, IDC_ShopInfoList);
		m_shopInfoList.SetWindowPos(NULL, 30, 120, 1107, 580, SWP_SHOWWINDOW);

		m_shopInfoList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		m_shopInfoList.InsertColumn(0, L"No", LVCFMT_LEFT, 100);
		m_shopInfoList.InsertColumn(1, L"지점명", LVCFMT_LEFT, 100);
		m_shopInfoList.InsertColumn(2, L"주소", LVCFMT_LEFT, 100);
		m_shopInfoList.InsertColumn(3, L"상세주소", LVCFMT_LEFT, 100);
		m_shopInfoList.InsertColumn(4, L"우편번호", LVCFMT_LEFT, 100);
		m_shopInfoList.InsertColumn(5, L"IP", LVCFMT_LEFT, 100);
		m_shopInfoList.InsertColumn(6, L"PORT", LVCFMT_LEFT, 100);
		m_shopInfoList.InsertColumn(7, L"오픈여부", LVCFMT_LEFT, 100);
		m_shopInfoList.InsertColumn(8, L"예약여부", LVCFMT_LEFT, 100);
	}
	else
	{
		if (m_pdtList)
		{
			m_pdtList.DeleteAllItems();
		}
		else if (m_soldoutList)
		{
			m_soldoutList.DeleteAllItems();
		}
		else if (m_posLoginList)
		{
			m_posLoginList.DeleteAllItems();
		}
		else if (m_mobileLoginList)
		{
			m_mobileLoginList.DeleteAllItems();
		}
		else if (m_memberList)
		{
			m_memberList.DeleteAllItems();
		}
		return;
	}
}


void WorkSheetDlg::CreateMemberList()
{
	if (!m_memberList) {
		m_memberList.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS, CRect(0, 0, 800, 500), this, IDC_MemberList);
		m_memberList.SetWindowPos(NULL, 30, 120, 1107, 580, SWP_SHOWWINDOW);

		m_memberList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		m_memberList.InsertColumn(0, L"No", LVCFMT_LEFT, 100);
		m_memberList.InsertColumn(1, L"로그인한 시간", LVCFMT_LEFT, 100);
		m_memberList.InsertColumn(2, L"로그아웃한 시간", LVCFMT_LEFT, 100);
		m_memberList.InsertColumn(3, L"이름", LVCFMT_LEFT, 100);
	}
	else
	{
		if (m_pdtList)
		{
			m_pdtList.DeleteAllItems();
		}
		else if (m_soldoutList)
		{
			m_soldoutList.DeleteAllItems();
		}
		else if (m_posLoginList)
		{
			m_posLoginList.DeleteAllItems();
		}
		else if (m_mobileLoginList)
		{
			m_mobileLoginList.DeleteAllItems();
		}
		else if (m_shopInfoList)
		{
			m_shopInfoList.DeleteAllItems();
		}
		return;
	}
}

void WorkSheetDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	CFont font;
	font.CreatePointFont(300, L"굴림"); // 글씨크기, 폰트
	dc.SelectObject(&font); // 폰트를 dc에 적용

	dc.SetBkMode(TRANSPARENT); // 배경을 투명색
	dc.DrawText(CString("제품리스트"), CRect(30, 10, 300, 100), 0); 
}
