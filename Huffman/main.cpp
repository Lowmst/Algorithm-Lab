#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

// 定义节点结构体
struct HuffmanNode {
    char data;             // 节点字符
    int freq;              // 节点频率
    HuffmanNode* left;     // 左子节点
    HuffmanNode* right;    // 右子节点

    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// 比较器，优先队列需要使用
struct compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->freq > r->freq;
    }
};

// 使用贪心算法构建Huffman树
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

// 递归获取Huffman编码
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

// 打印Huffman编码
void printHuffmanCodes(std::unordered_map<char, std::string>& huffmanCode) {
    std::cout << "Character With their Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        std::cout << pair.first << " " << pair.second << "\n";
    }
}

int main() {
    std::string text = "this is an example for huffman encoding";

    // 统计每个字符的频率，使用了map
    std::unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }

    // 构建Huffman树
    HuffmanNode* root = buildHuffmanTree(freqMap);

    // 获取Huffman编码
    std::unordered_map<char, std::string> huffmanCode;
    getHuffmanCodes(root, "", huffmanCode);

    // 打印Huffman编码
    printHuffmanCodes(huffmanCode);

    return 0;
}
