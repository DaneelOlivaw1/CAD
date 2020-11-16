// CAD1Doc.cpp : implementation of the CCAD1Doc class
//

#include "stdafx.h"
#include "CAD1.h"

#include "CAD1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCAD1Doc

IMPLEMENT_DYNCREATE(CCAD1Doc, CDocument)

BEGIN_MESSAGE_MAP(CCAD1Doc, CDocument)
	//{{AFX_MSG_MAP(CCAD1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCAD1Doc construction/destruction

CCAD1Doc::CCAD1Doc()
{
	// TODO: add one-time construction code here

}

CCAD1Doc::~CCAD1Doc()
{
}

BOOL CCAD1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCAD1Doc serialization

void CCAD1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCAD1Doc diagnostics

#ifdef _DEBUG
void CCAD1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCAD1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCAD1Doc commands
