import turtle as tu
import math
f = 0
class Point:
    def __init__(self, x:int, y:int):
        self.x = x;
        self.y = y;

class Line:
    def __init__(self, p0:Point, p1:Point):
        self.p0 = p0
        self.p1 = p1
        self.a = p0.y - p1.y
        self.b = p1.x - p0.x
        self.c = p0.x * p1.y - p1.x * p0.y
    
    def show(self):
        # print(self.p0.x, self.p0.y, self.p1.x, self.p1.y)
        pen = tu.Turtle()
        pen.speed(0)
        pen.ht()
        pen.pen(pencolor='red', pensize='2', fillcolor='yellow')
        pen.penup()
        pen.goto(self.p0.x, self.p0.y)
        pen.pendown()
        pen.goto(self.p1.x, self.p1.y)

def getPoint(l0:Line, l1:Line):
    d = l0.a * l1.b - l1.a * l0.b
    x = 0
    y = 0
    if (d==0):
        x = l0.p1.x
        y = l0.p1.y
    else:
        x = (l0.b * l1.c - l1.b * l0.c) / d
        y = (l1.a * l0.c - l0.a * l1.c) / d
    tp = Point(x, y);
    l1.p0 = tp
    l0.p1 = tp
    # l0.show()
    # l1.show()
    return l0, l1


scr = tu.getscreen()
tu.ht()
height = 1000
width = 600
scr.setup(height,width)
scr.delay(0)

pen2 = tu.Turtle()
pen2.speed(0)
pen2.ht()
pen2.pen(pencolor='red', pensize='2', fillcolor='yellow')

p = 0
l = []

def getl(l:Line):
    d = 30
    tc = math.sqrt(l.a * l.a + l.b * l.b)
    p0 = Point(l.p0.x + d * l.a / tc, l.p0.y + d * l.b / tc)
    p1 = Point(l.p1.x + d * l.a / tc, l.p1.y + d * l.b / tc)
    l1 = Line(p0, p1)
    p0 = Point(l.p0.x - d * l.a / tc, l.p0.y - d * l.b / tc)
    p1 = Point(l.p1.x - d * l.a / tc, l.p1.y - d * l.b / tc)
    l2 = Line(p0, p1)
    # l1.show()
    # l2.show()
    return l1, l2

def cursor_x_y(x, y):
    if (f != 0):
        return 
    # x = x - height / 2
    # y = width / 2 - y
    global p
    s = "鼠标坐标为:" + str(x) + "," + str(y)
    t = Point(x, y)
    l.append(t) 
    if p == 0:
        pen2.penup()
        pen2.goto(x, y)
        pen2.pendown()
        p = p + 1 
    else:
        pen2.goto(x, y)
    print(s)
l1 = []
l2 = []
def drawline(x, y):
    global f
    if (f != 0):
        return
    for i in range(len(l) - 1):
        p0 = Point(l[i].x, l[i].y)
        p1 = Point(l[i+1].x, l[i+1].y)
        tl = Line(p0, p1)
        tl1, tl2 = getl(tl)
        l1.append(tl1)
        l2.append(tl2)

    for i in range(len(l1) - 1):
        l1[i], l1[i+1] = getPoint(l1[i], l1[i+1])
        l2[i], l2[i+1] = getPoint(l2[i], l2[i+1])
    for i in range(len(l1)):
        pen2.begin_fill()
        pen2.penup()
        pen2.goto(l1[i].p0.x, l1[i].p0.y)
        pen2.pendown()
        pen2.goto(l1[i].p1.x, l1[i].p1.y)
        pen2.goto(l2[i].p1.x, l2[i].p1.y)
        pen2.goto(l2[i].p0.x, l2[i].p0.y)
        pen2.goto(l1[i].p0.x, l1[i].p0.y)
        pen2.end_fill()
        pen2.fillcolor()
    f += 1
        

scr.onclick(cursor_x_y)
# scr.cv.bind("<Motion>",cursor_x_y)    # 第二种绑定鼠标事件的方法：鼠标移动。
scr.onclick(drawline, btn=2)
tu.mainloop()