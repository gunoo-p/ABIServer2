// WorkSheetDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ABIServer2.h"
#include "WorkSheetDlg.h"
#include "afxdialogex.h"

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
	//DDX_Control(pDX, IDC_ProductList, m_pdtList);
}


BEGIN_MESSAGE_MAP(WorkSheetDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// WorkSheetDlg 메시지 처리기


BOOL WorkSheetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CreateList();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void WorkSheetDlg::CreateList()
{

	if(m_App->wsFlag == 1)
	{
		m_pdtList.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS, CRect(0, 0, 800, 500), this, IDC_ProductList);

		m_pdtList.SetWindowPos(NULL, 30, 120, 1107, 580, SWP_SHOWWINDOW);

		m_pdtList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		m_pdtList.InsertColumn(0, L"컬럼 1", LVCFMT_LEFT, 100);
		m_pdtList.InsertColumn(1, L"컬럼 1", LVCFMT_LEFT, 100);
		m_pdtList.InsertColumn(2, L"컬럼 1", LVCFMT_LEFT, 100);
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
