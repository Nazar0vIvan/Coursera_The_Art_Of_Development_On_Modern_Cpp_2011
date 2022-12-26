# Изучение нового языка

### Условие

Студента попросили написать класс `Learner`,` помогающий изучать иностранный язык. В публичном интерфейсе класса должны быть две функции:  

```c++
int Learn(const vector<string>& words);
vector<string> KnownWords();
```
Функция `Learn` должна получать порцию слов, "запоминать" их и возвращать количество различных новых слов. Функция `KnownWords` должна возвращать отсортированный по алфавиту список всех выученных слов. В списке не должно быть повторов.

Студент написал следующее решение этой задачи, однако оно почему-то работает очень медленно. Вам надо его ускорить.

Вам дан файл `learner.cpp` с медленным решением задачи. Не меняя публичный интерфейс класса `Learner`, найдите в нём узкие места, исправьте их и сдайте переделанный класс в тестирующую систему.

[learner.cpp](source/learner.cpp)

Ваш код будет тестироваться так:

```c++
int main() {
  Learner learner;
  string line;
  while (getline(cin, line)) {
    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
      words.push_back(word);
    }
    cout << learner.Learn(words) << "\n";
  }
  cout << "=== known words ===\n";
  for (auto word : learner.KnownWords()) {
    cout << word << "\n";
  }
}
```