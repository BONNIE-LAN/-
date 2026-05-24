#include <iostream>
using namespace std;

// 定义链表节点
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// 定义链表类
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // 在链表头部插入节点
    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 删除链表中指定值的节点
    void remove(int val) {
        if (head == nullptr)
            return;

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next!= nullptr && current->next->data!= val)
            current = current->next;

        if (current->next!= nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // 打印链表中的所有节点值
    void print() {
        Node* current = head;
        while (current!= nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // 析构函数，释放链表节点的内存
    ~LinkedList() {
        while (head!= nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int val;

    // 输入整数并插入链表
    cout << "请输入整数，以-1结束输入：" << endl;
    while (cin >> val && val!= -1) {
        list.insert(val);
    }

    // 输入要删除的整数
    cout << "请输入要删除的整数：" << endl;
    cin >> val;

    // 删除指定值的节点
    list.remove(val);

    // 打印删除操作后链表中的所有节点值
    cout << "删除操作后链表中的所有节点值为：" << endl;
    list.print();

    return 0;
}
