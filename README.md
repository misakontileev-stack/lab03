# lab02

Laboratory work II

Данная лабораторная работа посвещена изучению систем контроля версий на примере Git.

$ open https://git-scm.com

Tasks

    1. Создать публичный репозиторий с названием lab02 и с лиценцией MIT
    2. Сгенирировать токен для доступа к сервису GitHub с правами repo
    3. Ознакомиться со ссылками учебного материала
    4. Выполнить инструкцию учебного материала
    5. Составить отчет и отправить ссылку личным сообщением в Slack

Tutorial

$ export GITHUB_USERNAME=<имя_пользователя>
$ export GITHUB_EMAIL=<адрес_почтового_ящика>
$ export GITHUB_TOKEN=<сгенирированный_токен>
$ alias edit=<nano|vi|vim|subl>

$ cd ${GITHUB_USERNAME}/workspace
$ source scripts/activate

$ mkdir ~/.config
$ cat > ~/.config/hub <<EOF
github.com:
- user: ${GITHUB_USERNAME}
  oauth_token: ${GITHUB_TOKEN}
  protocol: https
EOF
$ git config --global hub.protocol https

$ mkdir projects/lab02 && cd projects/lab02
$ git init
$ git config --global user.name ${GITHUB_USERNAME}
$ git config --global user.email ${GITHUB_EMAIL}
# check your git global settings
$ git config -e --global
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab02.git
$ git pull origin master
$ touch README.md
$ git status
$ git add README.md
$ git commit -m"added README.md"
$ git push origin master

Добавить на сервисе GitHub в репозитории lab02 файл .gitignore со следующем содержимом:

*build*/
*install*/
*.swp
.idea/

$ git pull origin master
$ git log

$ mkdir sources
$ mkdir include
$ mkdir examples
$ cat > sources/print.cpp <<EOF
#include <print.hpp>

void print(const std::string& text, std::ostream& out)
{
  out << text;
}

void print(const std::string& text, std::ofstream& out)
{
  out << text;
}
EOF

$ cat > include/print.hpp <<EOF
#include <fstream>
#include <iostream>
#include <string>

void print(const std::string& text, std::ofstream& out);
void print(const std::string& text, std::ostream& out = std::cout);
EOF

$ cat > examples/example1.cpp <<EOF
#include <print.hpp>

int main(int argc, char** argv)
{
  print("hello");
}
EOF

$ cat > examples/example2.cpp <<EOF
#include <print.hpp>

#include <fstream>

int main(int argc, char** argv)
{
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
EOF

$ edit README.md

$ git status
$ git add .
$ git commit -m"added sources"
$ git push origin master

Report

$ cd ~/workspace/
$ export LAB_NUMBER=02
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER}.git tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gist REPORT.md

# Homework
## Part I

1. Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).

Создан репозиторий lab02.

2. Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдещем шаге.

3. Создайте файл hello_world.cpp в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу Hello world на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку using namespace std;.

```sh
$ nano hello_world.cpp
```

4. Добавьте этот файл в локальную копию репозитория.

```sh
$ git add hello_world.cpp
```

5. Закоммитьте изменения с осмысленным сообщением.

```sh
$ git commit -m "Был добавлен файл hello_world.cpp и реализована программа вывода"
```

Вывод: [master d08687d] Был добавлен файл hello_world.cpp и реализована программа вывода
 1 file changed, 7 insertions(+)
 create mode 100644 hello_world.cpp

6. Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение Hello world from @name, где @name имя пользователя.

```sh
$ nano hello_world.cpp
```

Теперь программа выглядит так:

```sh
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout<<"Введите свое имя: ";
    cin>>name;
    cout << "Hello world from " << name<< endl;
    return 0;
}
```

7. Закоммитьте новую версию программы. Почему не надо добавлять файл повторно git add?

```sh
$ git commit -am "Изменен файл hello_world.cpp"
```

Вывод: 

[master 6dda9fd] Изменен файл hello_world.cpp
 1 file changed, 5 insertions(+), 1 deletion(-)

Git уже отслеживает все файлы и добавляет их автоматически.

8. Запуште изменения в удалёный репозиторий.

```sh
$ git push origin master
```

Вывод:

Username for 'https://github.com': misakontileev
Password for 'https://misakontileev@github.com': 
Перечисление объектов: 7, готово.
Подсчет объектов: 100% (7/7), готово.
При сжатии изменений используется до 4 потоков
Сжатие объектов: 100% (6/6), готово.
Запись объектов: 100% (6/6), 867 байтов | 867.00 КиБ/с, готово.
Всего 6 (изменений 1), повторно использовано 0 (изменений 0), повторно использовано пакетов 0
remote: Resolving deltas: 100% (1/1), done.
To https://github.com/misakontileev-stack/lab02.git
   3693016..6dda9fd  master -> master

9. Проверьте, что история коммитов доступна в удалёный репозитории.

```sh
$ git log
```

Вывод:

commit 6dda9fd049f7cf0bf163424f5f3440a7903a8b5b (HEAD -> master, origin/master)
Author: misha <@gmail.com>
Date:   Tue Mar 3 14:14:54 2026 +0300

    Изменен файл hello_world.cpp

commit d08687d820138109bc70520a38a2238bcac93611
Author: misha <@gmail.com>
Date:   Tue Mar 3 14:05:52 2026 +0300

    Был добавлен файл hello_world.cpp и реализована программа вывода

commit 3693016e4efa5be29728a7b81b8fac6a4d1222f8
Author: misakontileev-stack <misakontileev@gmail.com>
Date:   Tue Mar 3 13:50:39 2026 +0300

    Add .gitignore

commit ef4a6df66b341a52d96f633102e14ab4406606c6
Author: misakontileev-stack <misakontileev@gmail.com>
Date:   Tue Mar 3 12:51:32 2026 +0300

    Initial commit

## Part II

Note: Работать продолжайте с теми же репоззиториями, что и в первой части задания.

1. В локальной копии репозитория создайте локальную ветку patch1.

```sh
$ git checkout -b patch1
```

Вывод:

Переключились на новую ветку «patch1»

2. Внесите изменения в ветке patch1 по исправлению кода и избавления от using namespace std;.

```sh
$ nano hello_world.cpp
```

Теперь код вышлядит так:

```sh
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Введите свое имя: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << std:: endl;
    return 0;
}
```

3. commit, push локальную ветку в удалённый репозиторий.

```sh
$ git commit -am "Удалена строчка кода: using namespace std, и к каждой строчке добавлено: std::"
```

Вывод:

[patch1 81a86ff] Удалена строчка кода: using namespace std, и к каждой строчке добавлено: std::
 1 file changed, 4 insertions(+), 5 deletions(-)

```sh
$ Username for 'https://github.com': misakontileev
Password for 'https://misakontileev@github.com': 
Перечисление объектов: 5, готово.



5. Создайте pull-request patch1 -> master.
6. В локальной копии в ветке patch1 добавьте в исходный код комментарии.
7. commit, push.
8. Проверьте, что новые изменения есть в созданном на шаге 5 pull-request
9. В удалённый репозитории выполните слияние PR patch1 -> master и удалите ветку patch1 в удаленном репозитории.
10. Локально выполните pull.
11. С помощью команды git log просмотрите историю в локальной версии ветки master.
12. Удалите локальную ветку patch1.

Part III

Note: Работать продолжайте с теми же репоззиториями, что и в первой части задания.

1. Создайте новую локальную ветку patch2.
2. Измените code style с помощью утилиты clang-format. Например, используя опцию -style=Mozilla.
3. commit, push, создайте pull-request patch2 -> master.
4. В ветке master в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.
5. Убедитесь, что в pull-request появились конфликтны.
6. Для этого локально выполните pull + rebase (точную последовательность команд, следует узнать самостоятельно). Исправьте конфликты.
7. Сделайте force push в ветку patch2
8. Убедитель, что в pull-request пропали конфликтны.
9. Вмержите pull-request patch2 -> master.

