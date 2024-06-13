#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

// ����ڵ�ṹ��
struct HuffmanNode {
    char data;             // �ڵ��ַ�
    int freq;              // �ڵ�Ƶ��
    HuffmanNode* left;     // ���ӽڵ�
    HuffmanNode* right;    // ���ӽڵ�

    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// �Ƚ��������ȶ�����Ҫʹ��
struct compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->freq > r->freq;
    }
};

// ʹ��̰���㷨����Huffman��
HuffmanNode* buildHuffmanTree(std::unordered_map<char, int>& freqMap) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, compare> minHeap;

    for (auto pair : freqMap) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    while (minHeap.size() != 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* top = new HuffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    return minHeap.top();
}

// �ݹ��ȡHuffman����
void getHuffmanCodes(HuffmanNode* root, std::string str, std::unordered_map<char, std::string>& huffmanCode) {
    if (!root) {
        return;
    }

    if (root->data != '$') {
        huffmanCode[root->data] = str;
    }

    getHuffmanCodes(root->left, str + "0", huffmanCode);
    getHuffmanCodes(root->right, str + "1", huffmanCode);
}

// ��ӡHuffman����
void printHuffmanCodes(std::unordered_map<char, std::string>& huffmanCode) {
    std::cout << "Character With their Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        std::cout << pair.first << " " << pair.second << "\n";
    }
}

int main() {
    std::string text = "this is an example for huffman encoding";

    // ͳ��ÿ���ַ���Ƶ�ʣ�ʹ����map
    std::unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }

    // ����Huffman��
    HuffmanNode* root = buildHuffmanTree(freqMap);

    // ��ȡHuffman����
    std::unordered_map<char, std::string> huffmanCode;
    getHuffmanCodes(root, "", huffmanCode);

    // ��ӡHuffman����
    printHuffmanCodes(huffmanCode);

    return 0;
}
