# TREESORT_DA

Creating a tree sort algorithm for the Codechef question SORT THE LEAVES.

## Problem Statement:

You are given a binary tree which has 2 or none trees on each of the nodes.Each of the nodes have an index between 1 and N(number 
of nodes) and each of the leaf nodes have a key associated with them which lief between 1 and L(no. of leaf nodes).

To each leaf, we can assign a string in the following way:

Each leaf node can be associated with a simple path Sl=v1,v2,…,vl from the root to leaf vl
- the string Svl assigned to leaf vl has length l−1; 
- for each valid i, Si is 'L' if vi+1 is the left son of vi or 'R' if it's the right son of vi

Our aim is to make out tree leaf sorted i.e for ever leaf if key of oe leaf is greater than the key of the other leaf then their string follow the same realtion as well in a lexiographical manner.

