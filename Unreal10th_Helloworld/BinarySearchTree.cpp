#include <iostream>
#include "BinarySearchTree.h"

//소멸자
BinarySearchTree::~BinarySearchTree()
{
    DestroyTree(Root);
}

//키 삽입
void BinarySearchTree::Insert(int InKey)
{
    Root = InsertNode(Root, InKey);
}

//키 검색 - 찾은 노드 반환
TreeNode* BinarySearchTree::Search(int InKey)
{
    return SearchNode(Root, InKey);
}

//키 삭제
void BinarySearchTree::Delete(int InKey)
{
    Root = DeleteNode(Root, InKey);
} 

//전위 순회 출력 (정렬된 순서)
void BinarySearchTree::PrintPreOrder() const
{
    printf("PreOrder : ");
    PreOrderTraversal(Root);
    printf("\n");
}

//중위 순회 출력
void BinarySearchTree::PrintInOrder() const
{
    printf("InOrder : ");
    InOrderTraversal(Root);
    printf("\n");
}

//후위 순회 출력
void BinarySearchTree::PrintPostOrder() const
{
    printf("PostOrder : ");
    PostOrderTraversal(Root);
    printf("\n");
}

//노드 삽입 (재귀), node는 서브 루트임
TreeNode* BinarySearchTree::InsertNode(TreeNode* InNode, int InKey)
{
    if (InNode == nullptr)
    {
        return new TreeNode(InKey);    //서브루트가 null이면 그곳에 새 노드 만들어서 연결되게 하기
    }

    if (InKey < InNode->Key)
    {
        InNode->Left = InsertNode(InNode->Left, InKey);     //입력하려는 키가 현재 노드의 값보다 작으면 왼쪽 서브트리에 추가
    }
    else if (InKey > InNode->Key)
    {
        InNode->Right = InsertNode(InNode->Right, InKey);   //크면 오른쪽에 추가
    }
    //else
    //{
    //    트리에서는 키가 중복되면 안됨! 중복된 키는 무시
    //}

    return InNode;
}

//노드 삭제 
TreeNode* BinarySearchTree::DeleteNode(TreeNode* InNode, int InKey)
{
    if (InNode == nullptr)
    {
        return InNode;
    }

    if (InKey < InNode->Key)
    {
        InNode->Left = DeleteNode(InNode->Left, InKey);
    }
    else if (InKey > InNode->Key)
    {
        InNode->Right = DeleteNode(InNode->Right, InKey);
    }
    else
    {
        //삭제할 노드를 찾았다
        if (InNode->Left == nullptr)
        {
            //왼쪽 자식이 없다. 자식이 둘 다 없다.
            TreeNode* Temp = InNode->Right;
            delete InNode;
            return Temp;
        }
        else if (InNode->Right == nullptr)
        {
            TreeNode* Temp = InNode->Left;
            delete InNode;
            return Temp;
        }

        //두 자식이 모두 있는 경우 => 오른쪽 서브트리의 최소값으로 대체
        TreeNode* Temp = FindMinNode(InNode->Right);
        InNode->Key = Temp->Key;
        InNode->Right = DeleteNode(InNode->Right, Temp->Key);
    }
        
    return InNode;
}

//노드 검색
TreeNode* BinarySearchTree::SearchNode(TreeNode* InNode, int InKey)
{
    if (InNode == nullptr)
    {
        return nullptr;     //못찾음
    }

    if (InKey < InNode->Key)
    {
        return SearchNode(InNode->Left, InKey);     //찾는중
    }
    else if (InKey > InNode->Key)
    {
        return SearchNode(InNode->Right, InKey);    //찾는중
    }  
    else
    {
        return InNode;      //찾았다
    }
}

//최소값 노드 찾기
TreeNode* BinarySearchTree::FindMinNode(TreeNode* InNode)
{
    while (InNode != nullptr && InNode->Left != nullptr)
    {
        InNode = InNode->Left;
    }
    return InNode;
}

//전위 순회
void BinarySearchTree::PreOrderTraversal(const TreeNode* InNode) const
{
    if (InNode != nullptr)
    {
        printf("%d ", InNode->Key);
        PreOrderTraversal(InNode->Left);
        PreOrderTraversal(InNode->Right);
    }
}

//중위 순회
void BinarySearchTree::InOrderTraversal(const TreeNode* InNode) const
{
    if (InNode != nullptr)
    {
        InOrderTraversal(InNode->Left);
        printf("%d ", InNode->Key);
        InOrderTraversal(InNode->Right);
    }
}

//후위 순회
void BinarySearchTree::PostOrderTraversal(const TreeNode* InNode) const
{
    if (InNode != nullptr)
    {
        PostOrderTraversal(InNode->Left);
        PostOrderTraversal(InNode->Right);
        printf("%d ", InNode->Key);
    }
}

//트리 삭제
void BinarySearchTree::DestroyTree(TreeNode* InNode)
{
    if (InNode != nullptr)
    {
        DestroyTree(InNode->Left);      //왼쪽 서브트리 삭제하고
        DestroyTree(InNode->Right);     //오른쪽 서브트리 삭제하고
        delete InNode;                  //나를 지워라 (후위순회하며 삭제하기)
    }
}
