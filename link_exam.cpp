#include<iostream>
using namespace std;

    class Node{
        public:

            int data;
            Node* next;

            Node(int data){
                this->data = data;
                this->next = NULL;
            }
    };

    class Linklist{
        public:

        Node* head;
        int count;

        Linklist(){
            this->head = NULL;
            this->count = 0;
        }

        void insertBegin(int data){
            Node *newnode = new Node(data);
            newnode->next = head;
            this->head = newnode;
            count++;
            cout<<"Insert at begin done...."<<endl;
        }
        
        void reading(){

            if(count == 0){
                cout<<"Node is ematy..."<<endl;
                return;
            }

            Node *temp = this->head;
            while (temp!= NULL)
            {
                cout<<temp->data<<",";
                temp = temp->next;
            }
            
        }

        void readbyPos(int pos){

            if(count==0){
                cout<<"Node is ematy..."<<endl;
                return;
            }

            if(pos==1){
                cout<<head->data<<endl;
                return;
            }

            if(pos > count || pos < 0){
                cout<<"Invalid pos Node size is "<<count<<" and your position is "<<pos<<" So enter valid position"<<endl;
                return;
            }

            Node *temp = this->head;
            for(int i=1;i < pos-1;i++){
                temp = temp->next;
            }
            cout<<temp->next->data<<endl;

        }

        void deleteNode(int pos){

            if(count==0){
                cout<<"Node is ematy..."<<endl;
                return;
            }
            
            if(pos > count || pos < 0){
                cout<<"Invalid pos Node size is "<<count<<" and your position is "<<pos<<" So enter valid position"<<endl;
                return;
            }
            
            Node *temp = this->head;
            if(pos==1){
                this->head = temp->next;
            }
            for(int i=1;i < pos-1;i++){
                temp = temp->next; 
            }
            temp->next = temp->next->next;
            cout<<"Delete Succsesfully..."<<endl;
        }

        void revNode(){
            
            if(count == 0){
                cout<<"Node is ematy..."<<endl;
                return;
            }

            if(count == 1){
                cout<<"Can't reverce there have only "<<count<<"Node..."<<endl;
                return;
            }

            Node *prv = NULL;
            Node *temp = this->head;
            Node *next = NULL;

            while (temp != NULL)
            {
                next = temp->next;
                temp->next = prv;
                prv = temp;
                temp = next;
            }
            this->head = prv;
            cout<<"Reverce node sucsessfully..."<<endl;
            
        }

    };



int main(){

    Linklist link;
    int n;
    
    do
    {
        cout<<"Welcome..."<<endl;
        cout<<"If you want add node at beginnig press 1"<<endl;
        cout<<"If you want display node press 2"<<endl;
        cout<<"If you want search node by position press 3"<<endl;
        cout<<"If you want delete node press 4"<<endl;
        cout<<"If you want revers node press 5"<<endl;
        cout<<"If you want to exit press 0"<<endl;
        cout<<"Enter any one choice :- ";
        cin>>n;

        switch (n)
        {
        case 1:
                int data;
                cout<<"-----Add node at beginning-----"<<endl<<endl;
                cout<<"Enter data for new node :- ";
                cin>>data;
                link.insertBegin(data);
                cout<<endl<<endl;
            break;
        case 2:
                cout<<"-----Reading-----"<<endl<<endl;
                link.reading();
                cout<<endl<<endl;
            break;
        case 3:
                int pos;
                cout<<"-----Search by position-----"<<endl<<endl;
                cout<<"Enter position for view node :- ";
                cin>>pos;
                link.readbyPos(pos);
                cout<<endl<<endl;
            break;
        case 4:
                int pos1;
                cout<<"-----Delete node-----"<<endl<<endl;
                cout<<"Enter position for delete :- ";
                cin>>pos1;
                link.deleteNode(pos1);
                cout<<endl<<endl;
            break;
        case 5:
                cout<<"-----Reverce node-----"<<endl<<endl;
                link.revNode();
                cout<<endl<<endl;
            break;
        case 0:
                cout<<"Thank you !"<<endl;
            break;
        default:
                cout<<"Enter valid choice...."<<endl;
            break;
        }


    } while (n!=0);
    


    return 0;
}
