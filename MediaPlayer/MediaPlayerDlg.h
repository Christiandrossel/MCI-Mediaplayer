
// MediaPlayerDlg.h: Headerdatei
//

#pragma once
//CMCIObject mci; // Membervariable der Dialogklasse

// CMediaPlayerDlg-Dialogfeld
class CMediaPlayerDlg : public CDialogEx
{
// Konstruktion
public:
	CMediaPlayerDlg(CWnd* pParent = nullptr);	// Standardkonstruktor
	//CMCIObject mci; // Membervariable der Dialogklasse
// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEDIAPLAYER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	//CMCIObject mci; // Membervariable der Dialogklasse

// Implementierung
protected:
	HICON m_hIcon;
	//CMCIObject mci; // Membervariable der Dialogklasse
	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void OnTimer(UINT nIDEvent);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton8();
	//CMCIObject mci; // Membervariable der Dialogklasse
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();

	afx_msg void OnLbnSelchangeListbox();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
