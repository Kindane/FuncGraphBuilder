# Function Graphic Builder

Построение графиков функций. На данный момент этот проект находится на сдании разработки, но вы уже можете узнать решения квадратной и линейной функций.<br>
Я тажке собираюсь добавить ещё парочку элементарных функций, а именно: дробно-линейную, показательную и разные тригонометрические функции,
а потом буду думать как мне их рисовать.<br>

## Dependencies

У вас просто должен быть установлен  `openGL` и `cmake`, или хотя-бы просто `gcc`.

## Installation

В первую очередь вам нужно будет клонировать данный git-репозиторий себе на устройство, потом перейти в директорию с репозиторием и вписать данную
команду:
    **$ mkdir build; cd build; cmake ..**
из-за того что проект находится на стадии разработки вам
нужно будет самим корректировать executable файл в [CMakeLists.txt](CMakeLists.txt), а именно функцию `add_executable`, в которой будет
необходимо менять название файла, который вы хотите скомпилировать. `dot.c` ИЗ ФУНКЦИИ НЕ УДАЛЯТЬ, всё сломается!



