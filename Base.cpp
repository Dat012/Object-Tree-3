#include "Base.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

Base::Base(Base *parent, string name)  // Конструктор для объектов иерархии
{
	this->parent = parent;  // Присваиваем родителя, переданного в аргументах
	this->name = name;  // Присваиваем имя, переданное в аргументах
	readiness = 0;
	if (parent != nullptr)  // Если родитель, создаваемого объекта не нулевой,
	{
		parent->heirs.push_back(this);  // то мы добавляем этот объект в вектор родителя
	}
}

void Base::set_name(string name)  // Присваиваем имя объекту
{
	this->name = name;
}

string Base::get_name()  // Получаем имя объекта
{
	return name;
}

int Base::get_readiness() const
{
	return readiness;
}

Base *Base::get_object_root()
{
	if (parent == nullptr) {
		return this;
	}
	Base* parent_previous = parent;

	while (parent_previous->parent != nullptr) {
		parent_previous = parent_previous->parent;
	}
	return parent_previous;
}

Base *Base::get_object(string path)
{
	string name;
	if (path.substr(0, 2) == "//") {  // 1. Если путь задан в формате //ob_1
		name = path.substr(2);
		if (this->name == name)
			return this;
	} else if (path[0] == '/' && path.length() > 1) {  // 2. Если путь задан в формате /ob_1/ob_2/ob_3
		name = path.substr(path.find("/") + 1, path.find("/", path.find("/") + 1) - 1);  // Получение имени объекта после /
		if (this->name == name)
			return this;
	} else if (path[0] == '.') {  // 3. Если путь задан в формате .
		return this;
	} else if (path[0] == '/' && path.length() == 1) {  // 4. Если путь задан в формате /
		return this->get_object_root();
	} else {  // 5. Если путь задан в формате ob_1/ob_2/ob_3
		if (path.find("/") != string::npos) {
			name = path.substr(0, path.find("/"));
		} else {
			name = path;
		}
		if (this->name == name)
			return this;
	}

	for (int i = 0; i < heirs.size(); ++i)
	{
		if (name == heirs[i]->get_name()) {
			path = path.substr(path.find(name) + name.length(), path.length());
			Base* res = heirs[i]->get_object(path);
			if (res != nullptr)
			{
				return res;
			}
		}
	}
	return nullptr;
}

void Base::set_object_path(const string &objectPath)
{
	object_path = objectPath;
}

const string &Base::get_object_path() const
{
	return object_path;
}

/* void Base::print_tree_old()  // Печатаем весь вектор объекта, который вызвал этот метод
{
	if (this->parent == nullptr)
	{  // Если у объекта нет parent, то печатаем его в соответствии с условием задачи
		cout << this->get_name() << "\n";
		cout << this->get_name() << "  ";
	}
	for (int i = 0; i < heirs.size() - 1; i++)  // Выводим весь вектор объекта до последнего объекта невключительно
	{
		cout << heirs[i]->get_name() << "  ";  // С двумя пробелами
	}
	cout << heirs[heirs.size() - 1]->get_name();  // Последний объект выводим без пробела

	for (int j = 0; j < heirs.size(); j++)
	{
		if (!heirs[j]->heirs.empty())  // Если вектор parent не пустой
		{
			cout << "\n" << heirs[j]->get_name() << "  ";
			heirs[j]->print_tree_old();  // , то печатаем наследников
		}
	}
} */

void Base::print_tree()
{
	cout << "Object tree\n";
	print_objects(0);
}

void Base::print_objects(int level)
{
	string space;
	if (level > 0) {
		space.append(4 * level, ' ');
	}
	cout << space << get_name();

	level++;
	if (heirs.empty()) {
		return;
	}
	for (int i = 0; i < heirs.size(); ++i)
	{
		cout << endl;
		heirs[i]->print_objects(level);
	}
	level--;
}

int Base::set_readiness(int readiness2)
{
	this->readiness = what_readiness(readiness2);
}

int Base::what_readiness(int readiness2) {
	if (parent == nullptr) {
		return readiness2;
	} else if (parent->readiness == 0) {
		return 0;
	} else {
		readiness2 = parent->what_readiness(readiness2);
		return readiness2;
	}
}

void Base::set_parent(Base *parent)  // Устанавливаем parent для текущего объекта
{
	if (this->parent !=
		nullptr)  // Если у объекта уже есть родитель, то мы удаляем текущий объект из списка наследников этого родителя
	{
		this->parent->heirs.erase(find(this->parent->heirs.begin(), this->parent->heirs.end(), this));
	}
	this->parent = parent;  // Присваиваем родителя объекту
	parent->heirs.push_back(this);  // Добавляем в вектор этого родителя текущий объект
}

/*void Base::set_parent(Base *parent)
{
	if (parent)
	{
		this->parent=parent;
		parent->heirs.push_back(this);
	}
}*/

Base *Base::get_parent()  // Возвращаем родителя текущего объекта
{
	return parent;
}