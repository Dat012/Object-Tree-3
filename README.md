# Object-Tree-3
Постановка задачи
Иметь возможность доступа из текущего объекта к любому объекту системы, «мечта» разработчика программы.
В составе базового класса реализовать метод получения указателя на любой объект в составе дерева иерархии объектов согласно пути (координаты). В качестве параметра методу передать путь (координату) объекта. Координата задается в следующем виде:
/ - корневой объект
//"имя объекта" - поиск объекта по уникальному имени от корневого (для однозначности уникальность требуется в рамках дерева);
. - текущий объект
«имя объекта 1»[/«имя объекта 2»] . . . - относительная координата от текущего объекта
/«имя объекта 1»[/«имя объекта 2»] . . . - абсолютная координата от текущего объекта
Примеры
/
//ob_3
.
ob_2/ob_3
ob_2
/ob_1/ob_2/ob_3
Если координата пустая строка или объект не найден, то вернуть нулевой указатель.
Система содержит объекты пяти классов, не считая корневого. Номера классов: 2,3,4,5,6.
Состав и иерархия объектов строиться посредством ввода исходных данных. Ввод организован как в версии No 2 курсовой работы. Единственное различие, в строке ввода первым указано не наименование головного объекта, а абсолютный путь к нему.
При построении дерева уникальность наименования относительно множества непосредственно подчиненных объектов для любого головного объекта соблюдены.
Добавить проверку допустимости исходной сборки. Собрать дерево невозможно, если по заданной координате головной объект не найден (например, ошибка в наименовании или еще не расположен на дереве объектов).
Система отрабатывает следующие команды:
SET «координата» – устанавливает текущий объект; FIND «координата»– находит объект относительно
текущего;
END              –  завершает  функционирование  системы
(выполнение программы).
Изначально, корневой объект для системы является текущим. При вводе данных в названии команд ошибок нет. Условия уникальности имен объектов для однозначной отработки соответствующих команд соблюдены.
