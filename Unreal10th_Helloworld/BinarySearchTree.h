#pragma once

struct TreeNode
{
	int Key = 0;
	TreeNode* Left = nullptr;
	TreeNode* Right = nullptr;

	TreeNode() = default;
	TreeNode(int InKey) : Key(InKey) {}
};

class BinarySearchTree
{
public:
	BinarySearchTree() = default;
	~BinarySearchTree();

	void Insert(int InKey);
	void Delete(int InKey);
	TreeNode* Search(int InKey);

	void PrintPreOrder() const;		//전위순회
	void PrintInOrder() const;		//중위순회
	void PrintPostOrder() const;	//후위순회

	inline bool IsEmpty() const { return Root == nullptr; }

private:
	TreeNode* Root = nullptr;

	TreeNode* InsertNode(TreeNode* InNode, int InKey);
	TreeNode* DeleteNode(TreeNode* InNode, int InKey);
	TreeNode* SearchNode(TreeNode* InNode, int InKey);
	TreeNode* FindMinNode(TreeNode* InNode);	// InNode를 루트로 하는 서브트리에서 키값이 가장 작은 노드를 찾는 함수

	void PreOrderTraversal(const TreeNode* InNode) const;
	void InOrderTraversal(const TreeNode* InNode) const;
	void PostOrderTraversal(const TreeNode* InNode) const;

	void DestroyTree(TreeNode* InNode);
};