
// ABIServer2Dlg.h: 헤더 파일
//

#pragma once
#include "WorkSheetDlg.h"
#include "ConnectDlg.h"


// CABIServer2Dlg 대화 상자
class CABIServer2Dlg : public CDialogEx
{
	// 생성입니다.
public:
	CABIServer2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	WorkSheetDlg* wsDlg;
	ConnectDlg* connectDlg;

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABISERVER2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void Init_WorkSheet();
	void Init_ConnectList();

	CTreeCtrl m_TreeMenu;
	CListBox m_lstDescription;

	void CreateTreeMenu();
	HTREEITEM pdtRoot, loginRoot, clientRoot, saleRoot;
	HTREEITEM pdtProduct, pdtSoldout, loginShop, loginMobile, clientShop, clientMobile;
	HTREEITEM saleShop, saleAll_K, saleAll_M, saleReport_M, saleReport_S;
	HTREEITEM saleShop_p, saleShop_k, saleShop_m, saleAll_M_reserve, saleAll_M_realtime, saleReport_M_d, saleReport_M_m, saleReport_M_y, saleReport_S_d, saleReport_S_m, saleReport_S_y;
	HTREEITEM saleShop_m_reserve, saleShop_m_realtime;

	HTREEITEM hTreeItem;
	CString SelectTreeMenu;

	afx_msg void OnDblclkTreemenu(NMHDR* pNMHDR, LRESULT* pResult);
};
