//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    void calculateSum(Node* node, int distance, int& sum) {
        if (!node) return;
        sum += node->data;
        if (distance == 0) return;
        calculateSum(node->left, distance - 1, sum);
        calculateSum(node->right, distance - 1, sum);
    }

    int findHomeAndCalculateSum(Node* node, int home, int distance, int& sum) {
        if (!node) return -1;
        if (node->data == home) {
            calculateSum(node, distance, sum);
            return distance - 1;
        }
        int remainingDistance = findHomeAndCalculateSum(node->left, home, distance, sum);
        if (remainingDistance != -1) {
            sum += node->data;
            if (remainingDistance >= 1) calculateSum(node->right, remainingDistance - 1, sum);
            return remainingDistance - 1;
        }
        remainingDistance = findHomeAndCalculateSum(node->right, home, distance, sum);
        if (remainingDistance != -1) {
            sum += node->data;
            if (remainingDistance >= 1) calculateSum(node->left, remainingDistance - 1, sum);
            return remainingDistance - 1;
        }
        return -1;
    }
    
    int ladoos(Node* root, int home, int distance) {
        int sum = 0;
        findHomeAndCalculateSum(root, home, distance, sum);
        return sum;
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends
