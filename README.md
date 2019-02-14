Класс Translator позволяет сохранять двуязычные пары слов 
и затем переводить слова с одного языка на другой с использованием уже добавленных пар
Более конкретно, объект 'obj' типа Translator допускает следующие действия:
1.Создание с помощью конструктора по умолчанию. В этом случае база переводов пуста.
2.Добавление двуязычной пары: obj.Add(source, target). После такого вызова считается, 
что слово source на языке 1 соответствует слову target на языке 
3.Переданные в метод Add строки могут быть уничтожены раньше объекта Translator.
4.Перевод с языка 1 на язык 2: obj.TranslateForward(source). 
Если ранее уже был вызов obj.Add(source_copy, target)для некоторой строки target и строки source_copy, равной source 
(или являющейся ей), нужно вернуть target. Если такого вызова не было, нужно вернуть пустую строку. 
Если таких вызовов было несколько, нужно вернуть target для последнего из них.
5.Перевод с языка 2 на язык 1: obj.TranslateBackward(target). 
Если ранее уже был вызов obj.Add(source, target_copy)для некоторой строки source и строки target_copy, 
равной target (или являющейся ей), нужно вернуть source. Если такого вызова не было, нужно вернуть пустую строку. 
Если таких вызовов было несколько, нужно вернуть source для последнего из них.

