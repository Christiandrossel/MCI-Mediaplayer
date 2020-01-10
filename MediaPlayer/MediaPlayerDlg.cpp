/**
	OnTimer() Funktioniert noch nicht
*/



// MediaPlayerDlg.cpp: Implementierungsdatei
//

#include "pch.h"
#include "framework.h"
#include "MediaPlayer.h"
#include "MediaPlayerDlg.h"
#include "afxdialogex.h"
#include "CMCIObject.h"

#include <iostream>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CMCIObject mci; // Membervariable der Dialogklasse
BYTE tracks;
// CMediaPlayerDlg-Dialogfeld

using namespace std;


CMediaPlayerDlg::CMediaPlayerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MEDIAPLAYER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMediaPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMediaPlayerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMediaPlayerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON8, &CMediaPlayerDlg::OnBnClickedButton8)

	ON_BN_CLICKED(IDC_BUTTON4, &CMediaPlayerDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CMediaPlayerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMediaPlayerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMediaPlayerDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMediaPlayerDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMediaPlayerDlg::OnBnClickedButton7)

	ON_LBN_SELCHANGE(IDC_LISTBOX, &CMediaPlayerDlg::OnLbnSelchangeListbox)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMediaPlayerDlg-Meldungshandler
//Diese Funktion wird am Ende aufgerufen
BOOL CMediaPlayerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Symbol für dieses Dialogfeld festlegen.  Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zusätzliche Initialisierung einfügen
	//OnTimer(1);
	
	
	SetTimer(1, 200, NULL);
	
	
	
	//OnTimer(SetTimer(1, 200, NULL));
	



	return TRUE;  // TRUE zurückgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}

// Wenn Sie dem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen.  Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgeführt.

void CMediaPlayerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext zum Zeichnen

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, während der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CMediaPlayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




//Open Video
void CMediaPlayerDlg::OnBnClickedButton1()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
	mci.OpenFile(L"test.mpg");
	mci.SetAviPosition(GetSafeHwnd(), CRect(30, 60, 210, 140));
	mci.Play();
}

//CLOSE Button
void CMediaPlayerDlg::OnBnClickedButton8()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
	mci.Close();
}

//Changed ListFunction
void CMediaPlayerDlg::OnLbnSelchangeList1()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.

	/* mci.Pause(); */

}



//Open CD
void CMediaPlayerDlg::OnBnClickedButton4()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
	((CListBox*)GetDlgItem(IDC_LISTBOX))->ResetContent();
	mci.OpenAudioCD(0, tracks); // sucht und öffnet eine AudioCD
	// ein spezielles Laufwerk: mci.OpenAudioCD(L"e:",t);
	BYTE min, sek, frame;
	for (int i = 1; i <= tracks; i++) {
		mci.GetTrackLength(i, min, sek, frame);
		CString temp; // z.B.Eintrag in eine ListBox : -)
		temp.Format(L"[%02d] %02d:%02d", i, min, sek);
		((CListBox*)GetDlgItem(IDC_LISTBOX))->AddString(temp);
	}
	
	mci.Play();
}


//Open Sound
void CMediaPlayerDlg::OnBnClickedButton2()
{
	((CListBox*)GetDlgItem(IDC_LISTBOX))->ResetContent();
	mci.OpenFile(L"maus_schokolade_mono.mp3");
	
	mci.Play();

	BYTE min, sek, frame;
	mci.GetTrackLength(1, min, sek, frame);
	CString temp; // z.B.Eintrag in eine ListBox : -)
	temp.Format(L"[%02d] %02d:%02d", 1, min, sek);
	((CListBox*)GetDlgItem(IDC_LISTBOX))->AddString(temp);


	//TODO clear listbox or reset listbox

}

//Open MDI
void CMediaPlayerDlg::OnBnClickedButton3()
{
	((CListBox*)GetDlgItem(IDC_LISTBOX))->ResetContent();
	mci.OpenFile(L"canyon.mid");
	mci.Play();
	BYTE min, sek, frame;
	mci.GetTrackLength(1, min, sek, frame);
	CString temp; // z.B.Eintrag in eine ListBox : -)
	temp.Format(L"[%02d] %02d:%02d", 1, min, sek);
	((CListBox*)GetDlgItem(IDC_LISTBOX))->AddString(temp);
}

//EXIT
void CMediaPlayerDlg::OnBnClickedButton5()
{
	exit(0);
	
}

//Play Button
void CMediaPlayerDlg::OnBnClickedButton6()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
	mci.Play();
}

//STOP Button
void CMediaPlayerDlg::OnBnClickedButton7()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
	mci.Stop();
}

void setText() {
	//Text übergeben
	CString s;
	s.Format(L"%d", 123);
	//IDC_Time ist die ID des Textfeld
  //GetDlgItem(IDC_TIME)->SetWindowText(s);
}


void CMediaPlayerDlg::OnLbnSelchangeListbox()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.

	mci.TMSFSeek(((CListBox*)GetDlgItem(IDC_LISTBOX))->GetCurSel() + 1, 0, 0, 0);
	mci.Play();
}




void CMediaPlayerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Fügen Sie hier Ihren Meldungshandlercode ein, und/oder benutzen Sie den Standard.
	CString str;
	unsigned char t, m, s, f, m2, s2, f2;
	mci.GetTMSFPosition(t, m, s, f);
	mci.GetTrackLength(1, m2, s2, f2);
	float secAktTrack = m*60 + s;
	float secTotaleTrack = m2 * 60 + s2;
	//float p sec;
	float p = secAktTrack *100 / secTotaleTrack;
	str.Format(L"[%02d] %02d:%02d \n  %.2f %%", t, m, s, p); //secAktTrack*100 / secTotaleTrack
	SetDlgItemText(IDC_TIME, str);
	
	CDialog::OnTimer(nIDEvent);

	CDialogEx::OnTimer(nIDEvent);
}
