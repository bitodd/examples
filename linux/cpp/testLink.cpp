#include "cstdio"
#include "cstring"
#include "iostream"
#include "map"
#include "memory"
#include "sstream"

using std::string;
using std::endl;
using std::cout;
using std::map;
using std::stringstream;

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
    Node* createNodeList();
    void addData();
    int findNode(Node* node);
    int removeNode(Node* node);
    int modifyNode(Node* node);
    void printNode(Node* node);
private:
    int insertNode(Node* node);
private:
    void int2string(const int i, string& str);
};

void NodeHandler::int2string(const int i, string& str)
{
    std::stringstream ss;
    ss<<i;
    str = str + "_" + ss.str();
}


void NodeHandler::printNode(Node* node) 
{
    cout<<"to print"<<endl;
    int num = 0;
    while(node->next != NULL)
    {
        num++;
        cout<<"num:"<<num<<"name:"<<node->info->name<<",age:"<<node->info->age<<endl;
        node = node->next;
    }
}

int NodeHandler::insertNode(Node* node)
{
    if(!node) return -1;
#if 0
    Info* g_info = new Info;
    g_node.info = g_info;
    g_node.info->age = node->info->age;
    g_node.info->name = node->info->name;
#endif
    node->next = node;
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
Node* NodeHandler::createNodeList()
{
    Node* head, *pf, *pb;
    for( auto i = 0 ; i <10; ++i )
    {
        pb = new Node;
        Info* info = new Info;
        pb->info = info;
        pb->info->age = (20+i);
        
        string name  = "miaomiao";
        int2string(i+1, name);
        pb->info->name = name;

        if( i==0 ) 
        {
            head = pf = pb;
        }
        else
        {
            pf->next = pb;
        }
        pf=pb;
    }
    pb->next = NULL;
    return head;
}
void NodeHandler::addData()
{

    for(auto i = 0 ; i <10; ++i)
    {
        Node* node = new Node;
        Info* info = new Info;
        node->info = info;
        node->info->age = (20+i);
        string name  = "miaomiao";
        int2string(i, name);
        node->info->name = name;
        g_node.next = node;
        insertNode(node);
    }

}

int main() {
    
    NodeHandler nodeHandler;
    Node* node = nodeHandler.createNodeList();
    nodeHandler.printNode(node);
    return 0;
}
