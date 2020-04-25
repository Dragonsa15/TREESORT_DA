#include<bits/stdc++.h>
using namespace std;

// void PrintTree(map<int,pair<int,int>> Tree,int N)
// {
// 	for(int i=1;i<N+1;i++)
//     {
//         cout<<i<<":"<<Tree[i].first<<" "<<Tree[i].second<<endl;
//     }
// }

int NumberSwaps(map<int,pair<int,int>>& Tree,map<int,pair<int,int>>& Max_Min,int index)
{
    //Checking if the given node is a leaf by seeing if the left child is -1
	if(Tree[index].first == -1)
	{
		//cout<<Tree[index].second;
        //Setting max and min of the leaf child as the value of the node 
        //Which is stored in the right child of the left node
		Max_Min[index].first = Tree[index].second;
		Max_Min[index].second = Tree[index].second;
		
        //As no swaps done so we return 0
        return 0;
	}
	else
	{
		//Recursively finding the minimum number of swaps in left and right child
        int lft = NumberSwaps(Tree,Max_Min,Tree[index].first);
		int rgt = NumberSwaps(Tree,Max_Min,Tree[index].second);
        //cout<<Tree[index].first<<" "<<Max_Min[Tree[index].first].first<<" "<<Tree[index].second<<" " <<Max_Min[Tree[index].second].second<<endl;
        
        if(lft == -1 || rgt == -1)
        {
            return -1;
        }
        //No need to do swapping if the max of left child is lesser than the 
        //min of the right child
        else
        {
            if(Max_Min[Tree[index].first].first <= Max_Min[Tree[index].second].second)
		    {
		    	Max_Min[index].first = Max_Min[Tree[index].second].first;
		    	Max_Min[index].second = Max_Min[Tree[index].first].second;

		    	return lft + rgt;
		    }

            //The one and only need to do swapping is when the Min of left child
            //is greater then the max of right child
		    else if(Max_Min[Tree[index].first].second >= Max_Min[Tree[index].second].first)
		    {
		    	Max_Min[index].first = Max_Min[Tree[index].first].first;
		    	Max_Min[index].second = Max_Min[Tree[index].second].second;
    
		    	return lft + rgt + 1;
		    }

            //if it doesn't satisfy the above conditions then that means 
            //there are some overlapping in the values in the left and right child
            //Thus, no amount of swapping possible can lexiographically and numerically
            // sort this tree
		
            else
		    {
		    	return -1;
		    }
        }
        

	}
}
int main()
{
    //A Tree map to store the left and right child of a node index
    map<int,pair<int,int>> Tree;
    
    //A Tree map to store the max and min of the subtree from the node index
    map<int,pair<int,int>> Max_Min;

    //t = testcases  ;   N = no. of nodes
    int t,N;
    cin>>t;
    while(t--)
    {
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int l,r;
            cin>>l>>r;

            //Storing the left and right child of the node
            Tree[i+1] = make_pair(l,r);
            
            //Making the Max and min respectively as the least and highest values
            Max_Min[i+1] = make_pair(0,1000000);
        }
        
        //PrintTree(Tree,N);
        cout << NumberSwaps(Tree,Max_Min,1) << "\n";
    }
    return 0;
}