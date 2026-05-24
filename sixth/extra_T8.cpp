#include <iostream>
#include <string>

using namespace std;

// 定义链表节点结构体
struct Node {
    int studentId;        // 学号
    string name;          // 姓名
    Node* next;           // 指向下一个节点的指针

    Node(int id, const string& name) : studentId(id), name(name), next(nullptr) {}
};

// 函数1：创建链表
void create(Node*& head) {
    int n;
    cout << "Please enter the number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of nodes must be greater than 0!" << endl;
        return;
    }

    Node* current = nullptr;

    for (int i = 0; i < n; ++i) {
        int id;
        string name;
        cout << "please enter" << i + 1 << " node's id and name: ";
        cin >> id >> name;

        Node* newNode = new Node(id, name);  // 创建新节点
        if (head == nullptr) {
            head = newNode;  // 第一个节点
        } else {
            current->next = newNode;  // 将当前节点指向新节点
        }
        current = newNode;  // 更新当前节点为新节点
    }
}

// 函数2：输出链表
void print(Node* head) {
    if (head == nullptr) {
        cout << "The linked list is empty!" << endl;
        return;
    }

    Node* current = head;
    cout << "The linked list:" << endl;
    while (current != nullptr) {
        cout << "studentId: " << current->studentId << ", name: " << current->name << endl;
        current = current->next;
    }
}

// 函数3：删除指定学号的节点
void del(Node*& head, int studentId) {
    if (head == nullptr) {
        cout << "The linked list is empty!can't delete" << endl;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    // 如果要删除的是头节点
    if (head->studentId == studentId) {
        Node* temp = head;
        head = head->next;  // 将头节点指向下一个节点
        delete temp;        // 释放头节点内存
        cout << "delete" << studentId << "'s node success" << endl;
        return;
    }

    // 查找要删除的节点
    while (current != nullptr && current->studentId != studentId) {
        prev = current;
        current = current->next;
    }

    // 如果节点不存在
    if (current == nullptr) {
        cout << "can't find " << studentId << "'s node" << endl;
        return;
    }

    // 删除指定节点
    prev->next = current->next;
    delete current;
    cout << "delete " << studentId << " 's node success" << endl;
}

// 函数4：向链表中插入一个新节点
void insert(Node*& head, int studentId, const string& name, int position) {
    Node* newNode = new Node(studentId, name);
    
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        cout << "insert success" << endl;
        return;
    }

    Node* current = head;
    int count = 1;
    while (current != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "the position is out of range" << endl;
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
    cout << "insert the node in" << position << " is success" << endl;
}

int main() {
    Node* head = nullptr;  // 初始化头指针为空

    // 创建链表
    create(head);

    // 输出链表
    print(head);

    // 删除指定节点
    int delId;
    cout << "Please enter the studentId you want to delete: ";
    cin >> delId;
    del(head, delId);

    // 输出链表
    print(head);

    // 插入新节点
    int insertId;
    string insertName;
    int position;
    cout << "Please enter the studentId, name and position you want to insert: ";
    cin >> insertId >> insertName >> position;
    insert(head, insertId, insertName, position);

    // 输出链表
    print(head);

    return 0;
}
