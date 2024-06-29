#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

void test01();//用绿色实心矩形填充三角形
void test02();//画矩形
void test03();
void test04();
void test05();
void test06();
void test07();
void button(int x, int y, int w, int h, const char* text);
void test08();
void test09();

int main()
{
	test09();
	system("pause");
	return 0;
}

void test01()
{
	initgraph(640, 480);
	IMAGE img(10, 8);
	SetWorkingImage(&img);
	setbkcolor(BLACK);
	cleardevice();
	setfillcolor(WHITE);
	solidrectangle(1, 1, 8, 5);
	SetWorkingImage(NULL);

	setfillstyle(BS_PATTERN, NULL, &img);
	settextcolor(GREEN);

	POINT pts[] = { {50,50},{50,200},{300,50} };
	solidpolygon(pts, 3);
	int ch=_getch();
	closegraph();

}

void test02()
{
	initgraph(640, 480);
	setbkcolor(RGB(255, 128, 192));
	cleardevice();

	setlinestyle(PS_SOLID, 3);
	setlinecolor(RED);
	setfillcolor(BLUE);

	circle(50, 50, 50);
	fillcircle(50, 150, 50);
	solidcircle(50, 250, 50);

	setbkcolor(GREEN);
	clearcircle(150, 50, 50);
	setbkcolor(GREEN);
	clearcircle(150, 150, 50);
	int ch	=_getch();
	closegraph();
}

void test03()
{
	initgraph(640, 480);
	setbkcolor(RGB(255, 128, 192));
	cleardevice();

	setfillstyle(BS_HATCHED, HS_DIAGCROSS);
	setfillcolor(YELLOW);

	setlinecolor(BLUE);
	setlinestyle(PS_SOLID, 3);

	ellipse(20, 20, 120, 70);
	fillellipse(20, 90, 120, 140);
	solidellipse(20, 160, 120, 210);

	setbkcolor(YELLOW);
	clearellipse(20, 230, 120, 280);
	char a=getchar();
	closegraph();
}


void test04()
{
	initgraph(640, 480);
	/*setbkcolor(WHITE);
	cleardevice();*/

	/*settextstyle(16, 0, _T("Consolas"));
	outtextxy(0, 0, _T("测试"));
	wchar_t s[] = L"hello！";
	outtextxy(0, 50, s);*/
	/*system("pause");*/
	settextstyle(48, 0, _T("Consolas"));
	outtextxy(0, 0, _T("抗锯齿效果"));
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	_tcscpy_s(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	outtextxy(0, 100, _T("抗锯齿效果"));
	system("pause");
}

void test05()
{
	initgraph(640, 480);

	/*loadimage(NULL, _T("X:\\Code\\C_Primary\\easyx\\a\\b.png"));*/
	//IMAGE img;
	//loadimage(&img, _T("IMAGE"), _T("Player"));
	//putimage(100, 100, &img);	// 在另一个位置再次显示背景

	/*loadimage(NULL, _T("X:\\Code\\C_Primary\\easyx\\a\\b.png"));
	IMAGE img;
	getimage(&img, 0, 0, 100, 100);
	putimage(200, 200, &img);*/
	system("pause");
}

void test06()
{
	initgraph(1024, 1024);
	setbkcolor(YELLOW);
	cleardevice();

	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 2);
	setfillcolor(WHITE);
	setfillstyle(BS_SOLID);
	settextstyle(25, 0, "楷体");
	setbkmode(TRANSPARENT);
	settextcolor(BLUE);

	fillroundrect(100, 100, 400, 300, 50, 50);
	TCHAR s[] = _T("我是一只小青蛙！");
	int arr_x = (300 - textwidth(s)) / 2;
	int arr_y = (200 - textheight(s)) / 2;
	outtextxy(arr_x + 100, arr_y + 100, s);
	_getch();
}

void test07()
{
	initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();

	IMAGE img;
	loadimage(&img, ".//a//b.png");
	putimage(0, 0, &img);
	_getch();
}

void button(int x, int y, int w, int h, const char* text)
{
	initgraph(640,480);
	setbkcolor(WHITE);
	cleardevice();

	setfillcolor(RED);
	setlinecolor(BLACK);
	settextstyle(25, 0, "黑体");
	settextcolor(BLUE);
	fillroundrect(x, y, x+w, y+h, 10, 10);
	
	char text_[50] = { 0 };
	strcpy_s(text_, text);
	int arr_x = (w - textwidth(text_)) / 2;
	int arr_y = (h - textheight(text_)) / 2;
	outtextxy(x + arr_x, y + arr_y, text_);
}

void test08()
{
	button(50, 50, 100, 100, "按钮");

	ExMessage msg;
	bool flag = true;
	while (1)
	{
		if (peekmessage(&msg, EM_MOUSE|EM_KEY))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 50 && msg.x <= 150 && msg.y >= 50 && msg.y <= 150)
				{
					cout << "左键点击按钮" << endl;
				}
				break;
			case WM_RBUTTONDOWN:
				if (msg.x >= 50 && msg.x <= 150 && msg.y >= 50 && msg.y <= 150)
				{
					cout << "右键点击按钮" << endl;
				}
			case WM_KEYDOWN:
				if (msg.vkcode == 27)
				{
					cout << "退出！" << endl;
					flag = false;
					break;
				}
			default:
				break;
			}
		}
		if (!flag)
		{
			break;
		}
	}
}

void test09()
{
	initgraph(1024, 1024);
	setbkcolor(WHITE);
	cleardevice();

	int x = 0;
	int y = 0;
	int num = 0;
	bool flag = true;
	while (flag)
	{
		setfillcolor(RED);
		setlinecolor(BLACK);
		fillcircle(x, y, 20);

		int key = _getch();
		
		switch (key)
		{
		case 87:
			y -= 15;
			cout << "上" << " ";
			break;
		case 83:
			y += 15;
			cout << "下" << " ";
			break;
		case 65:
			x -= 15;
			cout << "左" << " ";
			break;
		case 68:
			x += 15;
			cout << "右" << " ";
			break;
		case 27:
			flag = false;
			cout << "退出" << endl;
			break;
		}
		num++;
		if (num % 10 == 0)
		{
			cout << endl;
		}
	}
}