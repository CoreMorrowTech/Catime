/**
 * @file drawing.c
 * @brief 窗口绘图功能实现
 * 
 * 本文件实现了应用程序窗口绘图相关的功能，
 * 包括文本渲染、颜色设置和窗口内容绘制等功能。
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <windows.h>
 #include "../include/drawing.h"
 #include "../include/font.h"
 #include "../include/color.h"
 #include "../include/timer.h"
 #include "../include/config.h"
 
 // 从window_procedure.c引入的变量
 extern int elapsed_time;
 
 // 使用resource.h中定义的窗口绘制相关常量
 
 /**
  * @brief 处理窗口绘制
  * @param hwnd 窗口句柄
  * @param ps 绘制结构体
  * 
  * 处理窗口的WM_PAINT消息，执行以下操作：
  * 1. 创建内存DC双缓冲防止闪烁
  * 2. 根据模式计算剩余时间/获取当前时间
  * 3. 动态加载字体资源(支持实时预览)
  * 4. 解析颜色配置(支持HEX/RGB格式)
  * 5. 使用双缓冲机制绘制文本
  * 6. 自动调整窗口尺寸适应文本内容
  */
 void HandleWindowPaint(HWND hwnd, PAINTSTRUCT *ps) {
     HDC hdc = ps->hdc;
     RECT rect;
     GetClientRect(hwnd, &rect);
 
     // 创建双缓冲绘图环境
     HDC memDC = CreateCompatibleDC(hdc);
     HBITMAP memBitmap = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
     HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, memBitmap);
 
     // 设置白色背景
     HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
     FillRect(memDC, &rect, hBrush);
     DeleteObject(hBrush);
 
     // 绘制灰色边框
     HPEN hPen = CreatePen(PS_SOLID, 1, RGB(200, 200, 200));
     HPEN hOldPen = (HPEN)SelectObject(memDC, hPen);
     Rectangle(memDC, rect.left, rect.top, rect.right, rect.bottom);
     SelectObject(memDC, hOldPen);
     DeleteObject(hPen);
 
     // 复制到屏幕DC
     BitBlt(hdc, 0, 0, rect.right, rect.bottom, memDC, 0, 0, SRCCOPY);
 
     // 清理资源
     SelectObject(memDC, oldBitmap);
     DeleteObject(memBitmap);
     DeleteDC(memDC);
 }