    "LeetCode" ["Leet", "Code"]
     ^^^^

�õ� dict �� word, ���ȷ���Ƿ����ÿ��� break? ��Ŀ�и������ӣ��ж������ܼ򵥣����ȴ� word �ĵ�һ����ĸ��ʼ������������ pos == 3 ��λ��ʱ������ "Leet" �� dict ���м�¼����ô������ pos == 4 ��ʼ�������� pos == 7 ��ʱ�򣬷��� "Code" Ҳ�� dict ���м�¼����ʱ�������Ѿ��ߵ� word ��ĩβ��ǡ�ý�����������Ϊ break �ɹ���

����һ��������˼·����Ϊ��

```cpp
auto subBeg = s.cbegin();
for (auto subEnd = subBeg; subEnd != s.cend(); ++subEnd)
     if (dict.find(string(subBeg, subEnd)) != dict.end()) subBeg = subEnd;
//                                                        ^^^^^^^^^^^^^^^
return dict.find(string(subBeg, s.cend())) != dict.end();
```

�̶����У���ͨ�����������ȫ�������⡣

����δ�����߼�Ӳ������ subBeg ÿһ���ҵ�����������ƣ����ʧһЩ�Ӵ���ƥ�䣬�����⣿�����ӣ�

     "aaaaaaa", ["aaaa", "aaa"]
      ^^^```^

��������������߼������ջ᷵�� false, ��Ϊÿһ�β��ҵĶ��� "aaa", ����ʣ�µ� "a" �޷�ƥ�䡣��������������"aaaa" ���Ӵ�����Զ�޷�����֤��

��ʱ���룬��������� "aaa" ���£��ܷ�ÿ�� find �ɹ����� key �� dict ��ɾ����ò��������ȷ������ͨ�ˡ�

����� dict ���ĳһ�� key ��ľ���Ҫ������γ�����ƴ�� s �أ����������ӣ�

     "bb", ["a", "b"]
      ^`

���Է��֣��������ƥ���ϵ�һ�� "b", �̶�ɾ��֮����ô�ڶ��� "b" ����Զ�޷�ƥ�䣬�Ӷ�����Ϊ�� false, ����ش��ˡ�

�淳��ɾ���϶����߲�ͨ�ˣ������Ǳ�һ�㣬ÿһ�� find �ɹ�֮�󣬶�ȥ�࿴һ�ۣ�����ʣ�µ��Ӵ��ܷ�Ҳ find �ϣ�������ԣ�ֱ�Ӿͷ��� true �ˡ�

```cpp
auto subBeg = s.cbegin();
for (auto subEnd = subBeg; subEnd != s.cend(); ++subEnd)
     if (dict.find(string(subBeg, subEnd)) != dict.end()) {
          subBeg = subEnd;
          if (dict.find(string(subBeg, s.cend())) != dict.end()) return true;
     }
return false;
```

��Ȼ�е㹷β�����ĸо�������ȷ��ʹ��������ȫ����������һ����ͨ����

��Ȼ������һЩ����������磺

     "a", ["a"]
      ^

��Ҫ�������жϣ�

     if (dict.find(s) != dict.end()) return true;

���������ܶ���ʼ���ǽ�����Ӳ������Ʃ������������

     "goalspecial", ["go","goal","goals","special"]
        ^^^^^^^^^

�������������߼�������ƥ���� "go", Ȼ�� `subBeg` ���Ѿ������� 'a', �ⲿ���Ӵ����������Ҳ��ƥ�䲻���ˣ������һ��ʼ�Ƿָ�ɣ�"goal" + "special", ��ôǡ��ƥ���ϡ�

������ô�������ĴݲУ�����Ӧ�ÿ��Ը��ܵ�**Ӳ��**�����ںδ��ˡ���һ�� find �ɹ���Ӧ�ò���������ѡ������

1. `subEnd` �������ƣ���������ƥ�䡣
2. `subBeg` ���ƣ���������ƥ�䡣

ÿһ�� find �ɹ���������������֧����ô������һ������Ȼ��˼·�����ǣ�����ε����ﲻ�� `subBeg`������һ�ε���������ÿһ�� find �ɹ������Ƕ����˿̵� `subEnd` ����¼��������һ�ε�����ֱ�ӴӼ�¼�� `subEnd` ��ʼ���������Ͳ���������©�ˡ�

��Ȼ��ÿһ�ε��������Ƕ��������ж�ʣ�µ��Ӵ����Ƿ��ܹ�ƥ�䣬������ԣ�ֱ�ӷ��� true, ��һ���߼����䡣

�ʣ�������Ҫһ���������洢 `subEnd`, �������£�

```cpp
if (dict.find(s) != dict.end()) return true;

std::vector<string::const_iterator> cache{s.cbegin()};

for (auto subEnd = s.cbegin(); subEnd != s.cend(); ++subEnd)

     for (auto subBeg : cache)

          if (subBeg < subEnd && dict.find(string(subBeg, subEnd)) != dict.end()) {

               if (dict.find(string(subEnd, s.cend())) != dict.end()) return true;

               cache.push_back(subEnd); break;

          }

return false;
```

�ύ��AC.
