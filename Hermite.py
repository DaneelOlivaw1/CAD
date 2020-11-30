import turtle as tu
import math
import numpy as np
scr = tu.getscreen()
tu.ht()
height = 1000
width = 600
scr.setup(height,width)
scr.delay(0)
tu.tracer(False)


num = 0
l = []
f = 0 # 标记现在是否有线
ff = -1
def cursor_x_y(x, y):
    global num, l, f, ff
    if f != 0:
        if ff == -1:
            p = Point(x,y)
            esp = 10
            for i in range(len(l)):
                if abs(l[i].x - p.x) < esp and abs(l[i].y - p.y) < esp:
                    # print(i)
                    ff = i
                    l[ff].showCir()
        else :
            l[ff].x = x
            l[ff].y = y
            ff = -1
            Hermite()
            
    else :
        num = num + 1
        p = Point(x,y)
        l.append(p)
        
        s = "鼠标坐标为:" + str(p.m[0]) + "," + str(p.m[1])
        print(s)
        if num % 2 == 0:
            Line = V(l[-1], l[-2])
            Line.show()
        if num == 4:
            num = 0
            Hermite()
            f = 1



def Hermite():

    clearScreen()
    global l
    
    Line = V(l[0], l[1])
    Line.show()
    Line = V(l[2], l[3])
    Line.show()
    if (len(l) == 4):
        l.append(Point(0,0))
    p0 = V(l[4], l[0])
    dp0 = V(l[0], l[1])
    p1 = V(l[4], l[2])
    dp1 = V(l[2], l[3])
    mx = [p0.x, p1.x, dp0.x, dp1.x]
    my = [p0.y, p1.y, dp0.y, dp1.y]
    t = 0
    ts = []
    # print(mx, my)
    while (t <= 1):
        t=t+0.001
        T = [1-3*t**2+2*t**3, 3*t**3-2*t**3, t-2*t**2+t**3, -t**2+t**3]
        px = 0;
        py = 0;
        
        for i in range(0,4):
            px = px + T[i] * mx[i];
            py = py + T[i] * my[i];
        tp = Point(px, py)
        ts.append(tp)
    
    for i in ts:
        i.show()
    # print("===============")

def clearScreen():
    pen = tu.Turtle()
    pen.penup()
    pen.goto(-500, 500)
    pen.pendown()
    pen.pencolor('white')
    pen.begin_fill()
    pen.fillcolor('white')
    for i in range(1, 5):
        if i % 2 == 1:
            n = 1000
        elif i % 2 == 0:
            n = 1000
        pen.forward(n)
        pen.right(90)
    
    pen.end_fill()
    pen.penup()

class Point:
    def __init__(self, x:int, y:int):
        self.x = x
        self.y = y
        self.m = np.array([x, y], np.int32)
        # print(self.m)
    def show(self):
        pen = tu.Turtle()
        pen.speed(0)
        pen.ht()
        pen.pen(pencolor='red', pensize='2', fillcolor='yellow')
        pen.penup()
        pen.goto(self.x, self.y)
        pen.pendown()
        pen.goto(self.x, self.y)
        pen.penup()
    def showCir(self):
        pen = tu.Turtle()
        pen.speed(0)
        pen.ht()
        pen.pen(pencolor='orange', pensize='2', fillcolor='white')
        pen.penup()
        pen.goto(self.x, self.y - 5)
        pen.pendown()
        pen.circle(10)
        pen.penup()

class V:
    def __init__(self, a: Point, b: Point):
        self.p0 = a
        self.p1 = b
        self.x = b.x - a.x
        self.y = b.y - a.y
        self.m = np.array([self.x, self.y], np.int32)
        # print(self.x, self.y)
    def show(self):
        pen = tu.Turtle()
        pen.speed(0)
        pen.ht()
        pen.pen(pencolor='green', pensize='2', fillcolor='yellow')
        pen.penup()
        pen.goto(self.p0.x, self.p0.y)
        pen.pendown()
        pen.goto(self.p1.x, self.p1.y)
        pen.penup()

        
scr.onclick(cursor_x_y)

tu.mainloop()