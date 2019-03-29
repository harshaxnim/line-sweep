#ifndef node_h
#define node_h
// node.h

class node
{
public:
	
	node(float value) : m_value(value) { m_leftChild = nullptr; m_rightChild = nullptr; };
	
	node(float value, node *leftChild, node *rightChild)
		: m_value(value)
		, m_leftChild(leftChild)
		, m_rightChild(rightChild)
		{};

	float m_value             = 0.0f;
	int m_nodeCount           = 1;
	int m_balanceFactor       = 0;
	int m_height              = 1;
	node *m_leftChild         = nullptr;
	node *m_rightChild        = nullptr;
	void *m_info              = nullptr;
	static void (*callBack)(const node &callingNode);

	typedef enum
	{
		lowestToHighest
	} traversal_mode;

	bool operator<(const node &rightOperand);
	bool operator<=(const node &rightOperand);
	bool operator>(const node &rightOperand);
	bool operator>=(const node &rightOperand);

	node * insert(float val, void *info = nullptr);
	node * remove(float val);
	void traverse(traversal_mode mode);
	void update();
	node * balance();
	void print();
	
	node * leftRotation();
	node * rightRotation();
	
	node * leftLeftCase();
	node * leftRightCase();
	node * rightLeftCase();
	node * rightRightCase();
};

#endif
