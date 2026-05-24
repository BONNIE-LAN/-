#include<iostream>
#include "operation.h"
#include <graphics.h>
#include <conio.h>
#include <vector>
#include <sstream>
#include <windows.h>
#include <algorithm>

#define WIDTH 1024
#define HEIGHT 768
#define BTN_WIDTH 150
#define BTN_HEIGHT 40
#define COLUMN 2

using namespace std;

struct Button {
    int id;
    RECT rect;
    const TCHAR* text;
    COLORREF color;
};

vector<Button> g_buttons;
HWND g_hWnd;
bool g_arrayInitialized = false;
bool showArray = false;  // 新增控制变量

const COLORREF BG_COLOR = RGB(240, 240, 240);
const COLORREF BTN_COLOR = RGB(79, 129, 189);
const COLORREF TEXT_COLOR = RGB(0, 0, 0);

void InitUI() {
    int startX = 50;
    int startY = 100;
    int spacing = 20;

    const TCHAR* btnTexts[] = {
        _T("1. 输入数组"),
        _T("2. 排序数组"),
        _T("3. 插入元素"),
        _T("4. 查找元素"),
        _T("5. 删除元素"),
        _T("6. 输出元素"),
        _T("7. 求和操作"),
        _T("8. 显示数组"),
        _T("9. 退出程序")
    };

    for (int i = 0; i < 9; ++i) {
        int col = i % COLUMN;
        int row = i / COLUMN;

        Button btn{
            i + 1,
            {
                startX + col * (BTN_WIDTH + spacing),
                startY + row * (BTN_HEIGHT + spacing),
                startX + col * (BTN_WIDTH + spacing) + BTN_WIDTH,
                startY + row * (BTN_HEIGHT + spacing) + BTN_HEIGHT
            },
            btnTexts[i],
            BTN_COLOR
        };
        g_buttons.push_back(btn);
    }
}

void DrawUI(const vector<int>& arr) {
    BeginBatchDraw();
    cleardevice();

    setbkcolor(BG_COLOR);
    cleardevice();

    settextcolor(RGB(46, 76, 114));
    settextstyle(36, 0, _T("微软雅黑"));
    RECT titleRect{ 0, 20, WIDTH, 80 };
    drawtext(_T("数组可视化操作平台"), &titleRect, DT_CENTER | DT_VCENTER);

    settextstyle(16, 0, _T("微软雅黑"));
    for (const auto& btn : g_buttons) {
        setfillcolor(btn.color);
        solidroundrect(btn.rect.left, btn.rect.top,
            btn.rect.right, btn.rect.bottom, 8, 8);

        settextcolor(TEXT_COLOR);
        drawtext(btn.text, (RECT*)&btn.rect, DT_CENTER | DT_VCENTER);
    }

    // 仅在showArray为true时绘制数组
    if (showArray) {
        settextstyle(18, 0, _T("Consolas"));
        int baseX = 500, baseY = 150;
        for (size_t i = 0; i < arr.size(); ++i) {
            setfillcolor(RGB(100 + i * 10 % 155, 150 + i * 20 % 105, 200));
            solidroundrect(baseX + i * 70, baseY, baseX + i * 70 + 60, baseY + 60, 10, 10);

            TCHAR numStr[10];
            _stprintf_s(numStr, _T("%d"), arr[i]);
            settextcolor(RGB(0, 0, 0));
            outtextxy(baseX + i * 70 + 25 - textwidth(numStr) / 2,
                baseY + 25 - textheight(numStr) / 2, numStr);

            TCHAR indexStr[5];
            _stprintf_s(indexStr, _T("[%d]"), (int)i);
            settextcolor(RGB(50, 50, 50));
            outtextxy(baseX + i * 70 + 30 - textwidth(indexStr) / 2, baseY + 70, indexStr);
        }
    }

    setfillcolor(RGB(220, 220, 220));
    solidrectangle(0, HEIGHT - 40, WIDTH, HEIGHT);
    settextcolor(RGB(80, 80, 80));
    settextstyle(14, 0, _T("微软雅黑"));
    outtextxy(20, HEIGHT - 30,
        g_arrayInitialized ? _T("就绪") : _T("提示：请先初始化数组（操作1）"));

    EndBatchDraw();
}

int InputDialog(const TCHAR* title, const TCHAR* prompt) {
    static TCHAR buffer[256] = { 0 };
    InputBox(buffer, 256, title, prompt);
    return _ttoi(buffer);
}

void ShowMessage(const TCHAR* message) {
    MessageBox(g_hWnd, message, _T("系统提示"), MB_OK | MB_ICONINFORMATION);
}

int main() {
    initgraph(WIDTH, HEIGHT, SHOWCONSOLE);
    g_hWnd = GetHWnd();
    SetWindowText(g_hWnd, _T("数组操作库 - 图形版"));

    InitUI();
    vector<int> arr;

    while (true) {
        DrawUI(arr);

        ExMessage msg;
        if (peekmessage(&msg, EM_MOUSE | EM_KEY)) {
            if (msg.message == WM_CLOSE) break;

            if (msg.message == WM_LBUTTONDOWN) {
                for (const auto& btn : g_buttons) {
                    if (PtInRect(&btn.rect, { msg.x, msg.y })) {
                        if (btn.id != 1 && btn.id != 9 && !g_arrayInitialized) {
                            ShowMessage(_T("请先使用操作1初始化数组！"));
                            continue;
                        }

                        switch (btn.id) {
                        case 1: {
                            int n = InputDialog(_T("输入元素个数"), _T("请输入数组元素数量："));
                            if (n <= 0) {
                                ShowMessage(_T("无效的数组长度！"));
                                break;
                            }
                            arr.resize(n);
                            for (int i = 0; i < n; ++i) {
                                TCHAR prompt[50];
                                _stprintf_s(prompt, _T("请输入第%d个元素："), i + 1);
                                arr[i] = InputDialog(_T("输入数组元素"), prompt);
                                DrawUI(arr);
                            }
                            g_arrayInitialized = true;
                            break;
                        }
                        case 2:
                            sort(arr.begin(), arr.end());
                            DrawUI(arr);
                            ShowMessage(_T("数组排序完成！"));
                            break;
                        case 3: {
                            int index = InputDialog(_T("插入位置"), _T("请输入插入索引："));
                            int element = InputDialog(_T("插入元素"), _T("请输入要插入的值："));
                            insert_element(arr, index, element);
                            break;
                        }
                        case 4: {
                            int element = InputDialog(_T("查找元素"), _T("请输入要查找的值："));
                            find_element(arr, element);
                            break;
                        }
                        case 5: {
                            int element = InputDialog(_T("删除元素"), _T("请输入要删除的值："));
                            delete_element(arr, element);
                            break;
                        }
                        case 6: {  // 修改输出逻辑
                            int index = InputDialog(_T("元素索引"), _T("请输入要显示的索引："));
                            if (index >= 0 && index < arr.size()) {
                                TCHAR result[50];
                                _stprintf_s(result, _T("索引[%d]的值为：%d"), index, arr[index]);
                                ShowMessage(result);
                            }
                            else {
                                ShowMessage(_T("索引无效！"));
                            }
                            break;
                        }
                        case 7: {
                            vector<int> indices;
                            int num = InputDialog(_T("求和操作"), _T("请输入要相加的索引数量："));
                            for (int i = 0; i < num; ++i) {
                                TCHAR prompt[30];
                                _stprintf_s(prompt, _T("请输入第%d个索引："), i + 1);
                                indices.push_back(InputDialog(_T("输入索引"), prompt));
                            }
                            int sum = sum_array(indices, arr);
                            TCHAR result[50];
                            _stprintf_s(result, _T("求和结果：%d"), sum);
                            ShowMessage(result);
                            break;
                        } 
                        case 8:  // 新增显示控制
                            showArray = true;
                            DrawUI(arr);
                            break;
                        case 9:
                            closegraph();
                            return 0;
                        }
                    }
                }
            }
        }
        Sleep(10);
    }

    closegraph();
    return 0;
}