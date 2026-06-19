#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm> // 為了之後使用 sort()
#include <cstdlib>

using namespace std;

// define a struct named Student
struct Student {
    string id;
    string name;
    int score;
};

// Template function
template <class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
T getMin(T a, T b) {
    return (a < b) ? a : b;
}

void displayMenu() {
    cout << "\n學生成績管理系統" << endl;
    cout << "1. Add student" << endl;
    cout << "2. List all students" << endl;
    cout << "3. Sort by score" << endl;
    cout << "4. Search by id" << endl;
    cout << "5. Show statistics" << endl;
    cout << "0. Exit" << endl;
    cout << "請選擇功能(0-5): ";
}

int main() {
    system("chcp 65001 > nul"); // 強制終端機使用 UTF-8 編碼
    // use map to store, use student number as key and use Student as value 
    map<string, Student> students; 
    int choice;

    while (true) {
        displayMenu();
        
        if (!(cin >> choice)) { 
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "無效輸入，請重新輸入數字！\n";
            continue;
        }

        if (choice == 0) {
            cout << "系統結束，掰掰！\n";
            break;
        }

        switch (choice) {
            case 1:
                cout << "\n[執行] 新增學生資料...\n";
                {
                    string id, name;
                    int score;
                    
                    cout << "請輸入學號: ";
                    cin >> id;

                    // Check if the student number is exist or not
                    if (students.find(id) != students.end()) {
                        cout << "錯誤：學號 " << id << " 輸入之學號已存在，請重新確認！\n";
                    } else {
                        cout << "請輸入姓名: ";
                        cin >> name;
                        cout << "請輸入成績: ";
                        cin >> score;

                        // wirte the data in
                        students[id] = {id, name, score};
                        cout << "成功新增學生資料！\n";
                    }
                }
                break;

            case 2:
                cout << "\n[執行] 列出所有學生...\n";
                // check if the map has any data
                if (students.empty()) {
                    cout << "目前沒有任何學生資料！\n";
                } else {
                    cout << "-----------------------------------\n";
                    cout << "學號\t\t姓名\t\t成績\n";
                    cout << "-----------------------------------\n";
                    
                    for (const auto& pair : students) {
                        cout << pair.second.id << "\t\t" 
                             << pair.second.name << "\t\t" 
                             << pair.second.score << "\n";
                    }
                    cout << "-----------------------------------\n";
                }
                break;

            case 3:
                cout << "\n[執行] 依成績排序...\n";
                if (students.empty()) {
                    cout << "目前沒有任何學生資料可以排序！\n";
                } else {
                    vector<Student> sortedStudents;
                    for (const auto& pair : students) {
                        sortedStudents.push_back(pair.second);
                    }

                    sort(sortedStudents.begin(), sortedStudents.end(), [](const Student& a, const Student& b) {
                        return a.score > b.score;
                    });

                    cout << "---------------------------------\n";
                    cout << "學號\t\t姓名\t\t成績\n";
                    cout << "-----------------------------------\n";
                    for (const auto& s : sortedStudents) {
                        cout << s.id << "\t\t" << s.name << "\t\t" << s.score << "\n";
                    }
                    cout << "----------------------------------\n";
                }
                break;

            case 4:
                cout << "\n[執行] 依學號查詢...\n";
                {
                    string targetId;
                    cout << "請輸入要查詢的學號: ";
                    cin >> targetId;

                    // use find() to find key
                    auto it = students.find(targetId);
                    
                    if (it != students.end()) {
                        cout << "找到學生資料：\n";
                        cout << "學號: " << it->second.id << "\n"
                             << " 姓名: " << it->second.name << "\n"
                             << "  成績: " << it->second.score << "\n";
                    } else {
                        cout << "找不到學號為 " << targetId << " 的學生！\n";
                    }
                }
                break;
    
            case 5:
                cout << "\n[執行] 顯示成績統計...\n";
                if (students.empty()) {
                    cout << "目前沒有任何學生資料可以統計！\n";
                } else {
                    int sum = 0;
                    int passCount = 0;
                    int failCount = 0;
                    
                    auto firstStudent = students.begin();
                    int maxScore = firstStudent->second.score;
                    int minScore = firstStudent->second.score;

                    for (const auto& pair : students) {
                        int currentScore = pair.second.score;
                        // The sum of the score
                        sum += currentScore;
                        
                        // pass or not
                        if (currentScore >= 60) {
                            passCount++;
                        } else {
                            failCount++;
                        }
                        
                        maxScore = getMax<int>(maxScore, currentScore);
                        minScore = getMin<int>(minScore, currentScore);
                    }

                    // compute the average
                    double average = static_cast<double>(sum) / students.size();

                    // 輸出統計結果
                    cout << "\n";
                    cout << "總人數: " << students.size() << " 人\n";
                    cout << "全班平均: " << average << " 分\n";
                    cout << "最高分: " << maxScore << " 分\n";
                    cout << "最低分: " << minScore << " 分\n";
                    cout << "及格人數: " << passCount << " 人\n";
                    cout << "不及格人數: " << failCount << " 人\n";
                    cout << "\n";
                }
                break;

            default:
                cout << "無效選項，請選擇 0 到 5 之間的數字！\n";
                break;
        }
    }

    return 0;
}