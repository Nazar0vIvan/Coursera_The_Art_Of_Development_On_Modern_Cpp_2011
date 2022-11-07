#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main(){
  map<string, set<string>> synonyms; // key - слово, value - множество синонимов слова

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i){
    string operation_code;
    cin >> operation_code;
    if (operation_code == "ADD"){
      string word1, word2;
      cin >> word1 >> word2;
      synonyms[word1].insert(word2);
      synonyms[word2].insert(word1);
    }
    else if (operation_code == "COUNT"){
      string word;
      cin >> word;
      cout << synonyms[word].size() << endl;
    }
    else if (operation_code == "CHECK"){
      string word1, word2;
      cin >> word1 >> word2;
      if (synonyms[word1].count(word2) == 1){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}
