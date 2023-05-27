//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    Node* findMedian(Node* head){
        if(!head)
            return head;
        Node* slow = head;
        Node* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* reverse(Node* head){
        Node* prev = NULL,*forw;
        Node* curr = head;
        while(curr){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    
    void updateValue(Node* &firstTail,Node* &head){
        Node* ptr = head;
        while(firstTail){
            int temp = ptr->data;
            ptr->data = firstTail->data-temp;
            firstTail->data = temp;
            ptr = ptr->next;
            firstTail = firstTail->next;
        }
    }
    
    Node* modifyTheList(struct Node *head){
        //add code here.
        if(!head)
            return head;
    
        Node* firstTail = findMedian(head); // tail of first half
        Node* secHead = firstTail->next; // head of second half
    
        Node* prev = reverse(secHead);
        
        firstTail->next = prev;
        Node* ptr = head;
        firstTail = firstTail->next;
        
        updateValue(firstTail,head);
    
        firstTail = findMedian(head);
        secHead = firstTail->next;
        
        prev = reverse(secHead);
        firstTail->next = prev;
        return head;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends