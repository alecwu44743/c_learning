#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

struct node{
    char c;
    int value;
    node *left, *right;

    node(char c, int value, node *left, node *right) : 
        c(c), value(value), left(left), right(right) 
    {
    }
};

struct cmp{
    bool operator()(node const& a, node const& b){
        return a.value > b.value;
    }
};

// build code
template <typename T>
void buildcode(T &char_code, node *root, string code){
    if(root->left == nullptr && root->right == nullptr){
        char_code[root->c] = code;
        return;
    }

    buildcode(char_code, root->left, code + "0");
    buildcode(char_code, root->right, code + "1");
}

void compress(){
    ifstream INPUT_TXT;
    ofstream OUTPUT_TXT, COMPRESS_BIN;
    stringstream ss;

    string input, output_code = "", output_compress = "";

    map<char, int> cnt; cnt['\0'] = 1;
    map<char, string> char_code;

    priority_queue<node, vector<node>, cmp> pq;

    INPUT_TXT.open("input.txt");
    OUTPUT_TXT.open("code.txt");

    ss << INPUT_TXT.rdbuf();
    input = ss.str();
    INPUT_TXT.close();

    // count the number of each character
    for(auto ch : input){
        if(cnt.find(ch) == cnt.end()){ // if not found
            cnt[ch] = 1;
        }
        else{
            cnt[ch]++;
        }
    }

    // push all the characters into the priority queue
    for(auto data : cnt){
        node tmp(data.first, data.second, nullptr, nullptr);
        pq.push(tmp);
    }

    // build the huffman tree
    while(pq.size() > 1){
        node *left = new node(pq.top().c, pq.top().value, pq.top().left, pq.top().right);
        pq.pop();

        node *right = new node(pq.top().c, pq.top().value, pq.top().left, pq.top().right);
        pq.pop();

        pq.push(node('\0', left->value + right->value, left, right));
    }

    // build the code
    node *root = new node(pq.top().c, pq.top().value, pq.top().left, pq.top().right);
    pq.pop();
    buildcode(char_code, root, "");

    // write the code into the code.txt
    for(auto data : char_code){
        stringstream ss;
        ss << (int)data.first;
        output_code = output_code + ss.str() + " " + data.second + "\n";
    }
    OUTPUT_TXT << output_code;
    OUTPUT_TXT.close();

    // write the compressed file into the compress.bin
    COMPRESS_BIN.open("compress", ios::binary);
    for(auto ch : input){
        output_compress += char_code[ch];
    }
    output_compress += char_code['\0']; // add the end of file

    // padding the last byte
    if(output_compress.size() % 8 != 0){
        output_compress += string(8 - output_compress.size() % 8, '0');
    }

    // write the compressed file into the compress.bin
    int bytes_string[output_compress.size() / 8 + 1];
    int index = 0;
    for(int i = 0; i < output_compress.size(); i += 8){
        string tmp = output_compress.substr(i, 8);
        bytes_string[index++] = stoi(tmp, nullptr, 2); // convert binary string to int
    }

    for(int i = 0; i < index; i++){
        COMPRESS_BIN.put(bytes_string[i]);
    }

    COMPRESS_BIN.close();
}


void decompress(){
    ifstream CODE_TXT, COMPRESS_BIN;
    ofstream OUTPUT_TXT;

    string code, output = "", output_compress = "";
    map<string, char> code_char;
    vector <int> bytes_string;

    stringstream ss;
    string s_code, s_char;

    CODE_TXT.open("code.txt");
    COMPRESS_BIN.open("compress", ios::binary);

    // read the compressed file
    char ch;
    while(COMPRESS_BIN){
        COMPRESS_BIN.get(ch);

        bytes_string.push_back((int)ch);
    }
    COMPRESS_BIN.close();

    for(auto data : bytes_string){
        string tmp = bitset<8>(data).to_string();
        output_compress += tmp;
    }

    while(CODE_TXT){
        CODE_TXT >> s_char >> s_code;
        // cout << s_char << " " << s_code << endl;
        code_char[s_code] = (char)stoi(s_char);

    }
    CODE_TXT.close();

    bool isEND = false;
    for(int i = 0; i < output_compress.size(); i++){
        code += output_compress[i];
        if(code_char.find(code) != code_char.end()){
            if(code_char[code] == '\0'){
                isEND = true;
                break;
            }
            output += code_char[code];
            code = "";
        }
    }

    OUTPUT_TXT.open("output.txt");
    OUTPUT_TXT << output;
    OUTPUT_TXT.close();
}



int main(){
    compress();
    decompress();
}
// https://www.nytimes.com/2022/12/20/technology/elon-musk-twitter-resign.html
// https://www.nytimes.com/2022/12/20/technology/elon-musk-twitter-resign.html?unlocked_article_code=4w8K5UfwmfknR3vGOlCGVW9sJHS26Ji18ZAMM0uDPwO3zyUI9dGBN5h01EPPhifSeNuulkqID1mCJiogYw_xQSn48lVI9cU6uxQ0MSgKbgx_GBn9KTsZiqoN5QRww8U2eKmWNe8qV_gQMnjJPA0Y87cDA6GcdA91vlFMfs72TC3h9SC3-zGpX3HHS3oriraETh7ftA9LTKu_vk8nvvulgxSinEFQepEG2L2NhTotkjRbrZWNCQAf6kbZfhVGZFap2aYS8VTdfK4hngKZPSlrvOdcd2R50kiLqiBqMK4sAUP3_ys2wBekIs6QAliJnsqNf-Rb_YEs7jaIUjniOIWIdelIkGfPLQ&smid=share-url