#ifndef _MODELNODE_H_
#define _MODELNODE_H_
#include <memory>
#include <string>
#include <vector>

class ModelNode
{
public:
	ModelNode(std::string name) : m_name(name){}
	~ModelNode() {}

	std::string GetName() {
		return m_name;
	}
	bool HasChildren() {
		return !m_children.empty();
	}
	std::vector<std::shared_ptr<ModelNode>> GetChildren() {
		return m_children;
	}

	void AddChild(std::shared_ptr<ModelNode> newNode) {
		m_children.push_back(newNode);
	}

private:
	std::string m_name;
	std::vector<std::shared_ptr<ModelNode>> m_children;
};

#endif