1) create.c, converter.c и Makefile, загружаются в одну деректорию 
2) Открывается терминал и переводится в деректорию с файлами: cd (деректория)" 
3) Пишется команда "make" 
4) Получается 2 программы: converter и capture

Запуск программы Capture:

1) Открывается терминал и переводится в деректорию с файлами: cd (деректория)" 
2) Запускаем программу с аргументами: ширина ячейки, высота ячейки, количество столбцов, количество строк, ответы 
5) В итоге получаем заполненный бланк
Пример заполнения аргументов: "[путь к программе] 10 10 4 6 1 2 3 1 3 4 > pic.pbm" 

Запуск программы Converter:

1) Открывается терминал и переводится в деректорию с файлами: cd (деректория)"
2) Запускаем программу с аргументами: путь к файлу 
6)В итоге получаем конвертированное изображение
Пример заполнения аргументов: "(путь к программе) (путь к изображению) > ./pic.pbm"
