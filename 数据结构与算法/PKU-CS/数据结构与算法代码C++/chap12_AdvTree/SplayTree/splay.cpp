//��չ����ʹ�ô���
//����������ͳ��һ���ļ��еĵ���
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <cstdlib> 
#include "Splay.h"

using namespace std;

class Word 
{//�������Դ洢���ʵ���
public:
    Word() 
	{
        freq = 1;
    }
    int operator== (const Word& ir) const {
        return strcmp(word,ir.word) == 0;
    }
    int operator< (const Word& ir) const {
        return strcmp(word,ir.word) < 0;
    }
private:
    char *word;  //����
    int freq;    //ʹ��Ƶ��
    friend class WordSplay;
};

class WordSplay : public SplayTree<Word> 
{//ʹ����չ������һ�����ڴ����ʵ���
public:
    WordSplay() 
	{
        differentWords = wordCnt = 0;
    }
    void run(ifstream&,char*);
private:
    int differentWords, // ��ͬ�ĵ�����
        wordCnt;        // ͬһ�����ʳ�����������
    void visit(SplayingNode<Word>*);
};

void WordSplay::visit(SplayingNode<Word> *p) 
{
    differentWords++;
    wordCnt += p->info.freq;
}

void WordSplay::run(ifstream& fIn, char *fileName) 
{
    char ch = ' ', i;
    char s[100];
    Word rec;
    while (!fIn.eof()) {
        while (1)
            if (!fIn.eof() && !isalpha(ch)) // �ӹ����ַ�
                 fIn.get(ch);
            else break;
        if (fIn.eof())       
             break;
        for (i = 0; !fIn.eof() && isalpha(ch); i++) {
             s[i] = toupper(ch);
             fIn.get(ch);
        }
        s[i] = '\0';
        if (!(rec.word = new char[strlen(s)+1])) {
             cerr << "No room for new words.\n";
             exit(1);
        }
        strcpy(rec.word,s);
        Word *p = search(rec);
        if (p == 0)
             insert(rec);
        else p->freq++;
    }
    inorder();
    cout << "\n\nFile " << fileName
         << " contains " << wordCnt << " words among which "
         << differentWords << " are different\n";
}

int main(int argc, char* argv[])
{
    char fileName[80];
    WordSplay splayTree;
    if (argc != 2) {
         cout << "����һ������ͳ�Ƶ��ļ�: ";
         cin  >> fileName;
    }
    else strcpy(fileName,argv[1]);
    ifstream fIn(fileName);
    if (fIn.fail()) {
        cerr << "Cannot open " << fileName << endl;
        return 1;
    }
    splayTree.run(fIn,fileName);
    fIn.close();
    return 0;
}
