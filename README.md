# 學生成績管理系統 (C++ STL 整合應用)

這是一個使用 C++ STL (Standard Template Library) 實作的簡易學生成績管理系統。本專案為 C++ Template 延伸自主練習作業的第 2 週整合應用小專題。

## 系統功能
1.新增學生資料 (包含重複學號防呆機制)
2.列出所有學生
3.依成績降冪排序
4.依學號查詢學生
5.顯示成績統計 (使用自定義 Template function 計算最高/最低分)

## 開發與編譯環境
* 語言標準：C++17
* 測試環境：Windows / g++ 編譯器

## 如何編譯與執行
請在終端機 (Terminal) 中切換至本專案所在的目錄，並依序輸入以下指令：

### 1.編譯程式碼
bash
g++ -std=c++17 main.cpp -o main

2.執行程式
Windows 系統：
Bash
.\main.exe

Mac / Linux 系統：
Bash
./main
