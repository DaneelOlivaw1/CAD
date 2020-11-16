// CAD1View.cpp : implementation of the CCAD1View class
//

#include "stdafx.h"
#include "CAD1.h"
#include <cmath>
#include "CAD1Doc.h"
#include "CAD1View.h"
#include <ctime>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCAD1View

IMPLEMENT_DYNCREATE(CCAD1View, CView)

BEGIN_MESSAGE_MAP(CCAD1View, CView)
	//{{AFX_MSG_MAP(CCAD1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCAD1View construction/destruction

CCAD1View::CCAD1View()
{
	// TODO: add construction code here

}

CCAD1View::~CCAD1View()
{
}

BOOL CCAD1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCAD1View drawing


void CCAD1View::OnDraw(CDC* pDC)
{
	CCAD1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width()/2, rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2, -rect.Height()/2);
	// CRect clear(CPoint(rect.Width(), rect.Width()), CPoint(-rect.Height(),-rect.Height()))
	pDC->FillSolidRect(&rect, RGB(255,255,255));  // Clear Screen

	
	double t = sqrt(3);
	int a = 50;
	int x[] = {0,t * a, -1 * t * a};
	int y[] = {2 * a,-1 * a,-1 * a};
	int T[40][3];
	// 三角形的矩阵
	for (int i = 0; i < 3; i++){
		T[i][0] = x[i];
		T[i][1] = y[i];
		T[i][2] = 1;
	}
	// 画三角形
	for (i = 0 ; i < 3; i++){
		int j = (i + 1) % 3;
		CPoint p0(T[i][0], T[i][1]), p1(T[j][0], T[j][1]);
		pDC->MoveTo(p0);pDC->LineTo(p1);
	}
	// 每次旋转角度
	double s = 3.1415926 * 2 / 45;
	int cnt;
	// xy速度
	int vx = 10, vy = 10;
	// xy坐标
	int px = 0, py = 0;
	// 主循环
	for (cnt = 1; cnt < 5000; cnt ++){
		px += vx; py += vy;
		// 碰撞检测 碰到了就对应方向的速度变反向
		if (px < rect.Width()/2*-1 + 2 * a|| px > rect.Width()/2 - 2 * a){
			vx *= -1;
		}
		if (py < rect.Height()/2*-1 + 2 * a|| py > rect.Height()/2 - 2 * a){
			vy *= -1;
		}
		// 每次清屏
		pDC->FillSolidRect(&rect, RGB(255,255,255));  // Clear Screen
		double t[3][3]; // 旋转矩阵
		double t2[3][3]; // 平移矩阵
		// 两个矩阵初始化
		for (i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				t[i][j] = 0;
				t2[i][j] = 0;
			}
		}
		t[0][0] = cos(s*cnt);t[0][1] = -1 * sin(s*cnt);
		t[1][0] = sin(s*cnt);t[1][1] = cos(s*cnt);
		t[2][2] = 1;
		t2[0][0] = 1;t2[1][1] = 1;t2[2][2] = 1;
		t2[2][0] = px;t2[2][1] = py;
		// TT是旋转后的三角形
		// TTT是平移后的三角形
		// 第一步 先旋转 第二步 再平移
		int TT[40][3],TTT[40][3];

		// 旋转
		for (int l = 0; l < 40; l++){
			for (int i = 0; i < 3; i ++){
				TT[l][i] = 0;
				for (int j = 0; j < 3; j++){
					TT[l][i] += T[l][j] * t[j][i];
				}
			}
		}
		// 平移
		for (l = 0; l < 40; l++){
			for (int i = 0; i < 3; i ++){
				TTT[l][i] = 0;
				for (int j = 0; j < 3; j++){
					TTT[l][i] += TT[l][j] * t2[j][i];
				}
			}
		}
		// 画图
		for (i = 0 ; i < 3; i++){
			int j = (i + 1) % 3;
			CPoint p0(TTT[i][0], TTT[i][1]), p1(TTT[j][0], TTT[j][1]);
			pDC->MoveTo(p0);pDC->LineTo(p1);
		}
		Sleep(50);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCAD1View printing

BOOL CCAD1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCAD1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCAD1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCAD1View diagnostics

#ifdef _DEBUG
void CCAD1View::AssertValid() const
{
	CView::AssertValid();
}

void CCAD1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCAD1Doc* CCAD1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCAD1Doc)));
	return (CCAD1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCAD1View message handlers
