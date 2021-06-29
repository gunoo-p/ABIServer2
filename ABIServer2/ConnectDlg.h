#pragma once


// ConnectDlg 대화 상자

class ConnectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ConnectDlg)

public:
	ConnectDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ConnectDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ConnectDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	
	CListCtrl m_lstConnectPOS, m_lstConnectMobile;

	void Create_LstConectPOS();
	void Create_LstConectMobile();

	afx_msg void OnPaint();
};
