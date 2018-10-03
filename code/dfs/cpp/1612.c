#include "dfs.h"

DFS::DFS()
    :VisualGraph()
{
}

void DFS::initializeAnimation()
{
    setMenu(false);
    m_operations.push_back([=, this](){ getNode(_currentNode)->setColor(Qt::yellow); colorNode(_currentNode); });
    dfs(_currentNode);
    m_animationInitialized= true;
    m_currentStepInAnimation= 0;
    m_numberOfStepsInAnimation= m_operations.size();
}

void DFS::dfs(int index_of_current_node)
{
    Node * node = getNode(index_of_current_node);
    node->setVisited(true);
    NodeList neighbours_list = getNeighbours(index_of_current_node);
    foreach(int curr_node, neighbours_list) {
        if (!getNode(curr_node)->visited()) {
            m_operations.push_back([=, this](){getEdge(index_of_current_node, curr_node)->setColor(Qt::yellow); colorEdge(index_of_current_node, curr_node); emit highlightLine(6); });
            m_operations.push_back([=, this](){ getNode(curr_node)->setColor(Qt::yellow); colorNode(curr_node); emit highlightLine(0);});
            dfs(curr_node);
        }
    }
}
