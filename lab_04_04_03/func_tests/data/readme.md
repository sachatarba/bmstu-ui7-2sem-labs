# Тесты для лабораторной работы №4

## Входные данные 
Произвольная строка, длинной не более 256 символов

## Выходные данные 
Выводится только "YES" или "NO", в зависимости от результата

## Позитивные тесты:
- 01 - Правильный ввод номера телефона вместе с кодом страны из одной цифры
- 02 - Аналогично первому, только без кода страны
- 03 - Аналогично первому, только код страны сожержит 25 цифр
- 04 - Неправильный формат ввода номера телефона (4 цифры в коде оператора)
- 05 - Неправильный формат ввода номера телефона (очень много цифр в последнем блоке номера), так же строка содержит максимальный подаваемый рамзер
- 06 - Неправильный формат ввода номера телефона (4 цифры в первом блоке номера)
- 07 - Неправильный формат ввода номера телефона (3 цифры во втором блоке номера)
- 08 - Неправильный формат ввода номера телефона (3 цифры в третьем блоке номера)
- 09 - Неправильный формат ввода номера телефона (2 цифры в первом блоке номера)
- 10 - Неправильный формат ввода номера телефона (1 цифра во втором блоке номера)
- 11 - Неправильный формат ввода номера телефона (1 цифра в третьем блоке номера), так же строка содержит максимальный подаваемый размер
- 12 - Неправильный формат ввода номера телефона (строка начинается с "+", далее содержит буквы), так же строка содержит максимальынй подаваемый размер

## Негативный тесты:
- 01 - Пустая строка
