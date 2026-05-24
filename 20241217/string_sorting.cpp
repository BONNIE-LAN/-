#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    // 检查命令行参数
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
        return 1;
    }

    // 打开输入文件
    std::ifstream fin(argv[1]);
    if (!fin) {
        std::cerr << "无法打开输入文件: " << argv[1] << std::endl;
        return 1;
    }

    // 使用 set 来自动去重并排序单词
    std::set<std::string> wordSet;
    std::string word;

    // 读取文件中的所有单词
    while (fin >> word) {
        wordSet.insert(word);  // 插入 set 中，set 会自动去重和排序
    }
    fin.close();

    // 打开输出文件
    std::ofstream fout(argv[2]);
    if (!fout) {
        std::cerr << "无法打开输出文件: " << argv[2] << std::endl;
        return 1;
    }

    // 输出结果到文件
    for (const auto& w : wordSet) {
        fout << w << " ";
    }

    fout.close();
    std::cout << "处理完成，结果已写入 " << argv[2] << std::endl;
    return 0;
}
