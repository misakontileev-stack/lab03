#Laboratory work III

Данная лабораторная работа посвещена изучению систем автоматизации сборки проекта на примере CMake

```sh
$ open https://cmake.org/
```

##Tasks

1. Создать публичный репозиторий с названием lab03 на сервисе GitHub
2. Ознакомиться со ссылками учебного материала
3. Выполнить инструкцию учебного материала
4. Составить отчет и отправить ссылку личным сообщением в Slack

##Tutorial

```sh
$ export GITHUB_USERNAME=<имя_пользователя>

$ cd ${GITHUB_USERNAME}/workspace

$ pushd .
```

```sh
Вывод:

~/misakontileev/workspace/projects/lab03 ~/misakontileev/workspace/projects/lab03
```

```sh
$ source scripts/activate
```

```sh
$ git clone https://github.com/${GITHUB_USERNAME}/lab02.git projects/lab03
```

```sh
Вывод:

Клонирование в «projects/lab03»...
remote: Enumerating objects: 61, done.
remote: Counting objects: 100% (61/61), done.
remote: Compressing objects: 100% (44/44), done.
remote: Total 61 (delta 21), reused 40 (delta 12), pack-reused 0 (from 0)
Получение объектов: 100% (61/61), 18.37 КиБ | 3.67 МиБ/с, готово.
Определение изменений: 100% (21/21), готово.
```

```sh
$ cd projects/lab03

$ git remote remove origin

$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab03.git
```

```sh
$ g++ -std=c++11 -I./include -c sources/print.cpp

$ ls print.o
```

```sh
Вывод:

print.o
```

```sh
$ nm print.o | grep print
```

```sh
Вывод:

0000000000000000 T _Z5printRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSo
000000000000002a T _Z5printRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSt14basic_ofstreamIcS2_E
```

```sh
$ ar rvs print.a print.o
```

```sh
Вывод:

ar: создаётся print.a
a - print.o
```

```sh
$ file print.a
```

```sh
Вывод:

print.a: current ar archive
```

```sh
$ g++ -std=c++11 -I./include -c examples/example1.cpp

$ ls example1.o
```

```sh
Вывод:

example1.o
```

```sh
$ g++ example1.o print.a -o example1
```

```sh
$ ./example1 && echo
```

```sh
Вывод:

hello
```

```sh
$ g++ -std=c++11 -I./include -c examples/example2.cpp
```

```sh
$ nm example2.o
```

```sh
Вывод:

0000000000000000 V DW.ref.__gxx_personality_v0
                 U __gxx_personality_v0
0000000000000000 T main
                 U __stack_chk_fail
                 U _Unwind_Resume
                 U _Z5printRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSt14basic_ofstreamIcS2_E
                 U _ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode
                 U _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev
0000000000000000 W _ZNSt15__new_allocatorIcED1Ev
0000000000000000 W _ZNSt15__new_allocatorIcED2Ev
0000000000000000 n _ZNSt15__new_allocatorIcED5Ev
                 U _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
                 U _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
                 U _ZSt21ios_base_library_initv
0000000000000000 r _ZStL19piecewise_construct
```

```sh
$ g++ example2.o print.a -o example2

$ ./example2
```

```sh
$ cat log.txt && echo
```

```sh
Вывод:

hello
```

```sh
$ rm -rf example1.o example2.o print.o

$ rm -rf print.a

$ rm -rf example1 example2

$ rm -rf log.txt
```

```sh
$ cat > CMakeLists.txt <<EOF

cmake_minimum_required(VERSION 3.4)
project(print)
EOF
```

```sh
$ cat >> CMakeLists.txt <<EOF

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
EOF
```

```sh
$ cat >> CMakeLists.txt <<EOF

add_library(print STATIC \${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
EOF
```

```sh
$ cat >> CMakeLists.txt <<EOF

include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/include)
EOF
```

```sh
$ cmake -H. -B_build
```

```sh
Вывод:

CMake Deprecation Warning at CMakeLists.txt:1 (cmake_minimum_required):
  Compatibility with CMake < 3.5 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value or use a ...<max> suffix to tell
  CMake that the project does not need compatibility with older versions.


-- The C compiler identification is GNU 13.3.0
-- The CXX compiler identification is GNU 13.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.3s)
-- Generating done (0.0s)
-- Build files have been written to: /home/misha/misakontileev/workspace/projects/lab03/_build
```

```sh
$ cmake --build _build
```

```sh
Вывод:

[ 50%] Building CXX object CMakeFiles/print.dir/sources/print.cpp.o
[100%] Linking CXX static library libprint.a
[100%] Built target print
```

```sh
$ cat >> CMakeLists.txt <<EOF

add_executable(example1 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
add_executable(example2 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)
EOF
```

```sh
$ cat >> CMakeLists.txt <<EOF

target_link_libraries(example1 print)
target_link_libraries(example2 print)
EOF
```

```sh
$ cmake --build _build
```

```sh
Вывод:

CMake Deprecation Warning at CMakeLists.txt:1 (cmake_minimum_required):
  Compatibility with CMake < 3.5 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value or use a ...<max> suffix to tell
  CMake that the project does not need compatibility with older versions.


-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/misha/misakontileev/workspace/projects/lab03/_build
[ 33%] Built target print
[ 50%] Building CXX object CMakeFiles/example1.dir/examples/example1.cpp.o
[ 66%] Linking CXX executable example1
[ 66%] Built target example1
[ 83%] Building CXX object CMakeFiles/example2.dir/examples/example2.cpp.o
[100%] Linking CXX executable example2
[100%] Built target example2
```

```sh
$ cmake --build _build --target print
```

```sh
Вывод:

[100%] Built target print
```

```sh
$ cmake --build _build --target example1
```

```sh
Вывод:

[ 50%] Built target print
[100%] Built target example1
```

```sh
$ cmake --build _build --target example2
```

```sh
Вывод:

[ 50%] Built target print
[100%] Built target example2
```

```sh
$ ls -la _build/libprint.a
```

```sh
Вывод:

-rw-rw-r-- 1 misha misha 2246 мар 17 16:10 _build/libprint.a
```

```sh
$ _build/example1 && echo
```

```sh
Вывод:

hello
```

```sh
$ _build/example2
```

```sh
$ cat log.txt && echo

```sh
Вывод:

hello
```

```sh
$ rm -rf log.txt
```

```sh
$ git clone https://github.com/tp-labs/lab03 tmp
```

```sh
Вывод:

Клонирование в «tmp»...
remote: Enumerating objects: 91, done.
remote: Counting objects: 100% (30/30), done.
remote: Compressing objects: 100% (9/9), done.
remote: Total 91 (delta 23), reused 21 (delta 21), pack-reused 61 (from 1)
Получение объектов: 100% (91/91), 1.02 МиБ | 3.33 МиБ/с, готово.
Определение изменений: 100% (41/41), готово.
```

```
$ mv -f tmp/CMakeLists.txt .

$ rm -rf tmp
```

```sh
$ cat CMakeLists.txt
```

```sh
Вывод:

cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build examples" OFF)

project(print)

add_library(print STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)

target_include_directories(print PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

if(BUILD_EXAMPLES)
  file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
  foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(${EXAMPLE_NAME} print)
    install(TARGETS ${EXAMPLE_NAME}
      RUNTIME DESTINATION bin
    )
  endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
endif()

install(TARGETS print
    EXPORT print-config
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT print-config DESTINATION cmake)
```

```sh
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
```

```sh
Вывод:

CMake Deprecation Warning at CMakeLists.txt:1 (cmake_minimum_required):
  Compatibility with CMake < 3.5 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value or use a ...<max> suffix to tell
  CMake that the project does not need compatibility with older versions.


-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/misha/misakontileev/workspace/projects/lab03/_build
```

```sh
$ cmake --build _build --target install
```

```sh
Вывод:

[100%] Built target print
Install the project...
-- Install configuration: ""
-- Installing: /home/misha/misakontileev/workspace/projects/lab03/_install/lib/libprint.a
-- Installing: /home/misha/misakontileev/workspace/projects/lab03/_install/include
-- Installing: /home/misha/misakontileev/workspace/projects/lab03/_install/include/print.hpp
-- Installing: /home/misha/misakontileev/workspace/projects/lab03/_install/cmake/print-config.cmake
-- Installing: /home/misha/misakontileev/workspace/projects/lab03/_install/cmake/print-config-noconfig.cmake
```

```sh
$ sudo snap install tree
```

```sh
Вывод:

[sudo] пароль для misha: 
tree 2.1.3+pkg-5852 от 林博仁 Buo-ren Lin (brlin) installed
```

```sh
$ git add CMakeLists.txt

$ git commit -m"added CMakeLists.txt"
```

```sh
Вывод:

[master d69dac5] added CMakeLists.txt
 1 file changed, 36 insertions(+)
 create mode 100644 CMakeLists.txt
```
```sh
$ git push origin master
```

Report

$ popd
$ export LAB_NUMBER=03
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gist REPORT.md

Homework

Представьте, что вы стажер в компании "Formatter Inc.".
Задание 1

Вам поручили перейти на систему автоматизированной сборки CMake. Исходные файлы находятся в директории formatter_lib. В этой директории находятся файлы для статической библиотеки formatter. Создайте CMakeList.txt в директории formatter_lib, с помощью которого можно будет собирать статическую библиотеку formatter.
Задание 2

У компании "Formatter Inc." есть перспективная библиотека, которая является расширением предыдущей библиотеки. Т.к. вы уже овладели навыком созданием CMakeList.txt для статической библиотеки formatter, ваш руководитель поручает заняться созданием CMakeList.txt для библиотеки formatter_ex, которая в свою очередь использует библиотеку formatter.
Задание 3

Конечно же ваша компания предоставляет примеры использования своих библиотек. Чтобы продемонстрировать как работать с библиотекой formatter_ex, вам необходимо создать два CMakeList.txt для двух простых приложений:

    hello_world, которое использует библиотеку formatter_ex;
    solver, приложение которое испольует статические библиотеки formatter_ex и solver_lib.

Удачной стажировки!
