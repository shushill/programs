
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_CHAR 256

class SuffixTreeNode{
	public:
	class SuffixTreeNode *children[MAX_CHAR];
	class SuffixTreeNode *suffixLink;
	ll start, *end, suffixIndex;
};
typedef class SuffixTreeNode Node;

class SuffixTree{
	Node *root, *lastNewNode, *activeNode;
	ll activeEdge, activeLength;
	ll remainingSuffixCount, leafEnd;
	ll *rootEnd, *splitEnd;
	ll size;
	string str;
	public:
		SuffixTree();
		SuffixTree( string);
		void extendSuffixTree( ll);
		void buildSuffixTree( string);
		Node *newNode( ll, ll*);
		ll walkDown( Node*);
		ll edgeLength( Node*);
		void setSuffixIndex( Node*, ll);
		void print( ll, ll);
		bool check(Node*,string);
		bool isSubstr(string);
};

SuffixTree::SuffixTree()
{
	root = NULL;
	lastNewNode = NULL;
	activeNode = NULL;
	activeEdge = -1;
	activeLength = 0;
	remainingSuffixCount = 0;
	leafEnd = -1;
	rootEnd = NULL;
	splitEnd = NULL;
	size = -1;
}

SuffixTree::SuffixTree( string s)
{
	root = NULL;
	lastNewNode = NULL;
	activeNode = NULL;
	activeEdge = -1;
	activeLength = 0;
	remainingSuffixCount = 0;
	leafEnd = -1;
	rootEnd = NULL;
	splitEnd = NULL;
	size = -1;
	buildSuffixTree( s);
}

Node *SuffixTree::newNode( ll start, ll *end)
{
	Node *newnode = new Node;
	for( ll i = 0; i < MAX_CHAR; i++)
		newnode->children[i] = NULL;

	newnode->suffixLink = root;
	newnode->start = start;
	newnode->end = end;
	newnode->suffixIndex = -1;
	return newnode;
}

void SuffixTree::print( ll start, ll end)
{
	while( start <= end)
	{
		printf("%c", str[start]);
		start++;
	}
}

void SuffixTree::setSuffixIndex( Node *root, ll height)
{
	if( root == NULL)
		return;

	if( *(root->end) == (size - 1))
	{
		print( *(root->end) - height + 1, *(root->end));
	}
	bool leaf = true;
	for ( ll i = 0; i < MAX_CHAR; i++)
	{
		if ( root->children[i] != NULL)
		{
			leaf = false;
			setSuffixIndex(root->children[i], height + edgeLength(root->children[i]));
		}
	}
	if(leaf)
	{
		root->suffixIndex = size - height;
		cout << " " << root->suffixIndex << "\n";
	}
}

ll SuffixTree::edgeLength(Node *n)
{
	return *(n->end) - (n->start) + 1;
}

ll SuffixTree::walkDown(Node *currNode)
{
	if (activeLength >= edgeLength(currNode))
	{
		activeEdge += edgeLength(currNode);
		activeLength -= edgeLength(currNode);
		activeNode = currNode;
		return 1;
	}
	return 0;
}

void SuffixTree::extendSuffixTree( ll pos)
{
	leafEnd = pos;
	remainingSuffixCount++;
	lastNewNode = NULL;
	while( remainingSuffixCount > 0)
	{
		if( activeLength == 0)
		{
			activeEdge = pos;
		}

		if( activeNode->children[str[activeEdge]] == NULL)
		{
			activeNode->children[str[activeEdge]] = newNode( pos, &leafEnd);
			if (lastNewNode != NULL)
			{
				lastNewNode->suffixLink = activeNode;
				lastNewNode = NULL;
			}

		}
		else
		{
			Node *next = activeNode->children[str[activeEdge]];
			if (walkDown(next))
			{
				continue;
			}
			if (str[next->start + activeLength] == str[pos])
			{
				if(lastNewNode != NULL && activeNode != root)
				{
					lastNewNode->suffixLink = activeNode;
					lastNewNode = NULL;
				}

				activeLength++;
				break;
			}
			splitEnd = new ll;
			*splitEnd = next->start + activeLength - 1;

			Node *split = newNode(next->start, splitEnd);
 			activeNode->children[str[activeEdge]] = split;

			split->children[str[pos]] = newNode(pos, &leafEnd);
			next->start += activeLength;
			split->children[str[next->start]] = next;

			if (lastNewNode != NULL)
			{
				lastNewNode->suffixLink = split;
			}
			lastNewNode = split;
		}
		remainingSuffixCount--;
		if (activeNode == root && activeLength > 0)
		{
			activeLength--;
			activeEdge = pos - remainingSuffixCount + 1;
		}
		else if (activeNode != root)
		{
			activeNode = activeNode->suffixLink;
		}

	}
}

void SuffixTree::buildSuffixTree( string s)
{
	str = s;
	str = str + "$";
	size = str.size();
	rootEnd = new ll;
	*rootEnd = -1;
	root = newNode( -1, rootEnd);
	activeNode = root;
	for( ll i = 0; i < size; i++)
	{
		extendSuffixTree( i);
	}
	setSuffixIndex( root, 0);
}

bool SuffixTree::check(Node *root,string s){
	ll len=s.length();
	if(len==0)
		return true;
	for ( ll i = 0; i < MAX_CHAR; i++)
	{
		if ( root->children[i] != NULL)
		{
			Node *c=root->children[i];
			ll st=c->start,en=*(c->end),j=0;
			while(st<=en&&j<len&&str[st]==int(s[j]))
			{
				st++;
				j++;
			}
			if(j==len)
				return true;
			if(st>en)
				return check(c,s.substr(j,len-1));
		}
	}
	return false;

}
bool SuffixTree::isSubstr(string s)
{
	return check(root,s);
}
int main()
{
	SuffixTree s;
	s.buildSuffixTree("xyzxy");
	cout<<s.isSubstr("zxy")<<endl;
	cout<<s.isSubstr("xxy")<<endl;
	return 0;
}
