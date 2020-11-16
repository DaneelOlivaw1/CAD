// CAD1View.h : interface of the CCAD1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAD1VIEW_H__AB65D20B_DC28_444B_A65F_544AAB4E90F8__INCLUDED_)
#define AFX_CAD1VIEW_H__AB65D20B_DC28_444B_A65F_544AAB4E90F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCAD1View : public CView
{
protected: // create from serialization only
	CCAD1View();
	DECLARE_DYNCREATE(CCAD1View)

// Attributes
public:
	CCAD1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCAD1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCAD1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCAD1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CAD1View.cpp
inline CCAD1Doc* CCAD1View::GetDocument()
   { return (CCAD1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAD1VIEW_H__AB65D20B_DC28_444B_A65F_544AAB4E90F8__INCLUDED_)
