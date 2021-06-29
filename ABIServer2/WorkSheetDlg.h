#pragma once

// WorkSheetDlg 대화 상자

class WorkSheetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(WorkSheetDlg)

public:
	WorkSheetDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~WorkSheetDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WorkSheetDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	CListCtrl m_pdtList;
	void CreateList();

	CFont font;
	CStatic m_TitleText;
	afx_msg void OnPaint();
};
