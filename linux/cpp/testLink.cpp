#include "cstdio"
#include "cstring"
#include "iostream"
#include "map"
#include "memory"

using std::string;
using std::endl;
using std::cout;
using std::map;

struct Info {
    Info() {
    }
    string name;
    int age;
};

struct Node {
    Node* next;
    Info* info;
};

Node g_node;

class NodeHandler {
public:
    int findNode(Node* node);
    int removeNode(Node* node);
    int insertNode(Node* node);
    int modifyNode(Node* node);
};

int NodeHandler::insertNode(Node* node)
{
    if(!node) return -1;
    g_node.info->age = node->info->age;
    g_node.info->name = node->info->name;
    g_node.next = NULL;
    return 0;
}

int NodeHandler::removeNode(Node* node) 
{

}

int NodeHandler::modifyNode(Node* node) 
{

}

int NodeHandler::findNode(Node* node)
{
    while(g_node.next != NULL)
    {
        if(g_node.next->info->name == node->info->name)
        {
            cout<<"find this node! name:"<<node->info->name<<",age:"<<node->info->age<<endl;
            return 0 ;
        }
        g_node.next++;

    }
}


int main() {

    Info* g_info = new Info;
    g_node.info = g_info;

    NodeHandler nodeHandler;
    Node* node1 = new Node;
    Info* info = new Info;
    node1->info = info;
    node1->info->age = 28;
    node1->info->name = "miaomiao";
    nodeHandler.insertNode(node1);

    return 0;
}
