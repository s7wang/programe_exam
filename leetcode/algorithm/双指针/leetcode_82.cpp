/**
 * @file leetcode_82.cpp
 * @author wangs7
 * @brief leetcode.82.删除排序链表中的重复元素II
 * @version 0.1
 * @date 2022-09-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* getInput(int N) {
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    for (int i=0; i<N; ++i) {
        int num;
        cin >> num;
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    cur = head;
    head = head->next;
    delete cur;

    return head;
}

ListNode* deleteDuplicates(ListNode* head) {
    // 特殊情况处理
    if (head == nullptr || head->next == nullptr)
        return head;
    // 挂一个假头节点
    ListNode* newHead = new ListNode(0);
    newHead->next = head;
    ListNode *cur = head, *front = newHead;
    // 循环处理
    while (cur != nullptr) {
        int value = cur->val;
        // 当遇到重复值时cur一直向后遍历 直到cur的值不同
        while (cur->next != nullptr && cur->next->val == value) {
            cur = cur->next;
        }
        // 如果没遇到相同的节点 向后移动
        if (front->next == cur) {
            front = front->next;
            cur = cur->next;
        }
        else { //有相同的节点
            // 裁剪链表
            ListNode *tmp = front->next;
            front->next = cur->next;
            cur->next = nullptr;
            cur = front->next;
            // 清理被剪掉的链表
            while (tmp != nullptr){
                ListNode* p = tmp->next;
                delete tmp;
                tmp = p;
            }   
        }
        
    } 
    // 更新头指针
    head = newHead->next;
    // 释放假头节点
    delete newHead;
    return head;
}
int main(int argc, const char** argv) {
    int N;
    cin >> N;

    ListNode* head = getInput(N);
    ListNode* res = deleteDuplicates(head);

    for (auto cur = res; cur != nullptr; cur = cur->next) {
        cout << cur->val << " ";
    }
    cout << endl;

    return 0;
}