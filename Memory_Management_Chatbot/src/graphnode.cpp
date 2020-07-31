#include "graphedge.h"
#include "graphnode.h"
#include <memory>
GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
   // _chatBot->SetCurrentNode(this);
  //refer to knowledge https://knowledge.udacity.com/questions/238550
  //_chatBot is now a variable not a pointer
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
   // newNode->MoveChatbotHere(_chatBot);
     newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////
	// cannot do pass by value for unique_ptr
  //_childEdges is a vector of unique_ptr and we can't create a copy of unique_ptr.
    //return _childEdges[index];
    return (_childEdges[index]).get();

    ////
    //// EOF STUDENT CODE
}