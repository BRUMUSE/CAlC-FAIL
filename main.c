/*
 ============================================================================
 Name        : Files.c
 Author      : BRUMUSE
 Version     : 3.0
 Copyright   :
 Description : Чтобы пользоваться калькулятором нужно ввести знаечния во входной файл.
               Для 's':
               '+' - "Сложение";
               '-' - "Вычитание";
               '*' - "Умножение";
               '/' - "Деление";
               '^' - "Возведение в степень";
               '!' - "Факториал".
               Для 'v':
               '+' - сложение векторов, '-' - вычитание векторов, '*' - скалярное произведение векторов
               Повторный запуск программы:
               1 - да;
               0 - нет;
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Переменные для получения символов для работы с операциями
    char operation, symbol;
    // Переменные для получения и записи значений из файла
    float firstValue, secondValue, result;
    // Переменная для факториала и степени
    int n;
    // Переменные для работы с массивом
    int size, index;
    // Переменные для обозначения массивов
    int *vec1, *vec2, *vec3, res = 0;
    // Рестарт
    int restart;
    FILE *inFile, *outFile;
    char inpath[256];
    char outpath[256];


    do
    {
        // Путь входа
        puts("Enter the path to the input file. (Example: D:\\inFile.txt): ");
        scanf("%s", inpath);
        // Переменная для того, чтобы открывать файл для чтения значений, который указали выше
        inFile = fopen(inpath, "r");
        // Путь выхода
        puts("Enter the outpath to open the file with output values. (Example: D:\\outFile.txt): ");
        scanf("%s", outpath);
        // Переменная для того, чтобы открывать файл для записи значений, который указали выше
        outFile = fopen(outpath, "w");

        // Проверка пути
        if ((inFile == NULL) || outFile == NULL)
        {
            puts("Error: Invalid file inpath!");
        }

        // Получаем символ(+, -, *, /, ^, !) из файла ввходных значений
        fscanf(inFile, "%c ", &symbol);
        // Получаем символ операции(s, v) из файла ввходных значений
        fscanf(inFile, "%c ", &operation);

        if ((symbol == '+') && (operation == 's'))
        {
            puts("+, s\nCalculating ...\nCheck the output file");
            fscanf(inFile, "%f", &firstValue);
            fprintf(outFile, "%f ", firstValue);
            fscanf(inFile, "%f", &secondValue);
            fprintf(outFile, "+ %f", secondValue);
            fprintf(outFile, " = %f", firstValue + secondValue);
            // Закрытие входного файла
            fclose(outFile);
            // Закрытие выходного файла
            fclose(inFile);
        }
        if ((symbol == '-') && (operation == 's'))
        {
            puts("-, s\nCalculating ...\nCheck the output file");
            fscanf(inFile, "%f", &firstValue);
            fprintf(outFile, "%f ", firstValue);
            fscanf(inFile, "%f", &secondValue);
            fprintf(outFile, "- %f", secondValue);
            fprintf(outFile, " = %f", firstValue - secondValue);
            // Закрытие входного файла
            fclose(outFile);
            // Закрытие выходного файла
            fclose(inFile);
        }
        if ((symbol == '*') && (operation == 's'))
        {
            puts("*, s\nCalculating ...\nCheck the output file");
            fscanf(inFile, "%f", &firstValue);
            fprintf(outFile, "%f ", firstValue);
            fscanf(inFile, "%f", &secondValue);
            fprintf(outFile, "* %f", secondValue);
            fprintf(outFile, " = %f", firstValue * secondValue);
            // Закрытие входного файла
            fclose(outFile);
            // Закрытие выходного файла
            fclose(inFile);
        }
        if ((symbol == '/') && (operation == 's'))
        {
            puts("/, s\nCalculating ...\nCheck the output file");
            fscanf(inFile, "%f", &firstValue);
            fprintf(outFile, "%f ", firstValue);
            fscanf(inFile, "%f", &secondValue);
            fprintf(outFile, "/ %f", secondValue);
            if (secondValue == 0)
            {
                fprintf(outFile, " - Error!");
            }
            else
            {
                fprintf(outFile, " = %f", firstValue / secondValue);
            }
            // Закрытие входного файла
            fclose(outFile);
            // Закрытие выходного файла
            fclose(inFile);
        }
        if ((symbol == '^') && (operation == 's'))
        {
            puts("^, s\nCalculating ...\nCheck the output file");
            fscanf(inFile, "%f", &firstValue);
            fprintf(outFile, "%f ", firstValue);
            fscanf(inFile, "%d", &n);
            fprintf(outFile, "^ %d", n);
            result = 1;
            // Цикл, который будет длиться до того момента, пока 'n' больше '0' и с каждым разом 'result' будет увеличиваться
            for (; n > 0; n--)
            {
                result *= firstValue;
            }
            fprintf(outFile, " = %f", result);
            // Закрытие входного файла
            fclose(outFile);
            // Закрытие выходного файла
            fclose(inFile);
        }
        if ((symbol == '!') && (operation == 's'))
        {
            puts("!, s\nCalculating ...\nCheck the output file");
            fscanf(inFile, "%f", &firstValue);
            fprintf(outFile, "%f", firstValue);
            fprintf(outFile, "!");
            if (firstValue == 0)
            {
                fprintf(outFile, " = %f", firstValue + 1);
            }
            else
            {
                result = 1;
                // Цикл, который каждый раз умножает 'result' на увеличенное значение 'n' до того момента, пока 'n' <= 'firstValue'
                for (n = 1; n <= firstValue; n++)
                {
                    result *= n;
                }
                fprintf(outFile, " = %f", result);
            }
            // Закрытие входного файла
            fclose(outFile);
            // Закрытие выходного файла
            fclose(inFile);
        }
        if ((symbol == '+') && (operation == 'v'))
        {
            puts("+, v\nCalculating ...\nCheck the output file");
            // Считывание длины векторов
            fscanf(inFile, "%d ", &size);
            // Выделение памяти для первого вектора
            vec1 = malloc(size*sizeof(int));
            fprintf(outFile, "(");
            // Цикл, который сохраняет значения первого вектора в выделенную память(в массив)
            for (index = 0; index < size; index++)
            {
                // Считывание значений первого вектора
                fscanf(inFile, "%d", &vec1[index]);
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outFile, "%d ", vec1[index]);
                }
                else
                {
                    fprintf(outFile, "%d)", vec1[index]);
                }
            }
            fprintf(outFile, " + ");
            // Выделение памяти для второго вектора
            vec2 = malloc(size*sizeof(int));
            fprintf(outFile, "(");
            // Цикл, который сохраняет значения второго вектора в выделенную память(в массив)
            for (index = 0; index < size; index++)
            {
                // Считывание значений второго вектора
                fscanf(inFile, "%d", &vec2[index]);
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outFile, "%d ", vec2[index]);
                }
                else
                {
                    fprintf(outFile, "%d)", vec2[index]);
                }
            }
            fprintf(outFile, " = ");
            fprintf(outFile, "(");
            // Цикл, который по очереди складывает значения, которые находятся в определенном индексе массива
            for (index = 0; index < size; index++)
            {
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outFile ,"%d ", vec1[index] + vec2[index]);
                }
                else
                {
                    fprintf(outFile ,"%d)", vec1[index] + vec2[index]);
                }
            }
            // Освобождене памяти первого массива
            free(vec1);
            // Освобождене памяти второго массива
            free(vec2);
            // Закрытие входного файла
            fclose(outFile);
            // Закрытие выходного файла
            fclose(inFile);
        }
        if ((symbol == '-') && (operation == 'v'))
        {
            puts("-, v\nCalculating ...\nCheck the output file");
            // Считывание длины первого вектора
            fscanf(inFile, "%d ", &size);
            // Выделение памяти для первого вектора
            vec1 = malloc(size*sizeof(int));
            fprintf(outFile, "(");
            // Цикл, который сохраняет значения первого вектора в выделенную память(в массив)
            for (index = 0; index < size; index++)
            {
                // Считывание значений первого вектора
                fscanf(inFile, "%d", &vec1[index]);
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outFile, "%d ", vec1[index]);
                }
                else
                {
                    fprintf(outFile, "%d)", vec1[index]);
                }
            }
            fprintf(outFile, " - ");
            // Выделение памяти для второго вектора
            vec2 = malloc(size*sizeof(int));
            fprintf(outFile, "(");
            // Цикл, который сохраняет значения второго вектора в выделенную память(в массив)
            for (index = 0; index < size; index++)
            {
                // Считывание значений второго вектора
                fscanf(inFile, "%d", &vec2[index]);
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outFile, "%d ", vec2[index]);
                }
                else
                {
                    fprintf(outFile, "%d)", vec2[index]);
                }
            }
            fprintf(outFile, " = ");
            fprintf(outFile, "(");
            // Цикл, который по очереди складывает значения, которые находятся в определенном индексе массива
            for (index = 0; index < size; index++)
            {
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outFile ,"%d ", vec1[index] - vec2[index]);
                }
                else
                {
                    fprintf(outFile ,"%d)", vec1[index] - vec2[index]);
                }
            }
            // Освобождене памяти первого массива
            free(vec1);
            // Освобождене памяти второго массива
            free(vec2);
            // Закрытие входного файла
            fclose(outFile);
            // Закрытие выходного файла
            fclose(inFile);
        }
        if ((symbol == '*') && (operation == 'v'))
        {
            puts("*, v\nCalculating ...\nCheck the output file");
            // Считывание длины первого вектора
            fscanf(inFile, "%d ", &size);
            // Выделение памяти для первого вектора
            vec1 = malloc(size*sizeof(int));
            fprintf(outFile, "(");
            // Цикл, который сохраняет значения первого вектора в выделенную память(в массив)
            for (index = 0; index < size; index++)
            {
                // Считывание значений первого вектора
                fscanf(inFile, "%d", &vec1[index]);
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outFile, "%d ", vec1[index]);
                }
                else
                {
                    fprintf(outFile, "%d)", vec1[index]);
                }
            }
            fprintf(outFile, " * ");
            // Выделение памяти для второго вектора
            vec2 = malloc(size*sizeof(int));
            fprintf(outFile, "(");
            // Цикл, который сохраняет значения второго вектора в выделенную память(в массив)
            for (index = 0; index < size; index++)
            {
                // Считывание значений второго вектора
                fscanf(inFile, "%d", &vec2[index]);
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outFile, "%d ", vec2[index]);
                }
                else
                {
                    fprintf(outFile, "%d)", vec2[index]);
                }
            }
            fprintf(outFile, " = ");
            vec3 = malloc(size*sizeof(int));
            // Цикл, который по очереди умножает значения, которые находятся в определенном индексе массива,
            // а затем в переменную 'res' записывается сумма самой перменной 'res' и значений индексов
            for (index = 0; index < size; index++)
            {
                vec3[index] = vec1[index] * vec2[index];
                res += vec3[index];
            }
            fprintf(outFile, "%d", res);
            // Освобождене памяти первого массива
            free(vec1);
            // Освобождене памяти второго массива
            free(vec2);
            // Освобождене памяти третьего массива
            free(vec3);
            // Закрытие входного файла
            fclose(outFile);
            // Закрытие выходного файла
            fclose(inFile);
        }
        puts("Restart? 1/0: 1 - Yes, 0 - No");
        scanf("%d", &restart);
    }
    while (restart != 0);
}