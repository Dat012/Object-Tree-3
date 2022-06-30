#include "Major.h"
#include "Base.h"
#include "Heir2.h"
#include "Heir3.h"
#include "Heir4.h"
#include "Heir5.h"
#include "Heir6.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Major::bild_tree_objects()  // Строим дерево объектов на основе введенных данных
{
	Base *cur_obj = this;  // Создаем основной объект, который равен this по умолчанию
	cur_obj->class_number = 1;  // Номер класса корневого объекта 1

	Base *cp = nullptr;  // Создаем объект наследник, который будет в векторе объекта выше
	string root_name;  // Имя корневого объекта
	string parent_path;  // Имя родителя по отношению к объекту, введенному ниже
	string heir_name;  // Имя наследника для родителя, введенного выше
	int cl_number;
	cin >> root_name;  // Вводим имя корневого объекта
	cur_obj->set_name(root_name);  // Имя текущего объекта теперь равно имени корневого объекта
	cur_obj->set_object_path("/");
	cin >> parent_path >> heir_name >> cl_number;  // На следующей строке вводим имя родительского объекта
	while (parent_path != "endtree")  // Цикл по вводу имен parent + heir
	{
		if (parent_path != cur_obj->get_object_path())  // Если имя родителя не равно имени текущего объекта,
		{
			cur_obj = get_object(parent_path);  // то текущим объектом становится наследник, которого мы ввели после родителя
		}
		switch (cl_number)
		{
			case 2:
				cp = new Heir2(cur_obj, heir_name);  // Создаем объект наследника, родителем которого является текущий объект
				break;
			case 3:
				cp = new Heir3(cur_obj, heir_name);  // Создаем объект наследника, родителем которого является текущий объект
				break;
			case 4:
				cp = new Heir4(cur_obj, heir_name);  // Создаем объект наследника, родителем которого является текущий объект
				break;
			case 5:
				cp = new Heir5(cur_obj, heir_name);  // Создаем объект наследника, родителем которого является текущий объект
				break;
			case 6:
				cp = new Heir6(cur_obj, heir_name);  // Создаем объект наследника, родителем которого является текущий объект
		}
		cp->class_number = cl_number;
		cp->set_object_path(cp->get_parent()->get_object_path() + heir_name + "/");
		//cout << cp->get_name() << ": " << cp->get_object_root()->get_name() << endl;
		cin >> parent_path;
		if (parent_path == "endtree")
		{

			cp->get_object_root()->print_tree();
			string command;
			string heir_path;
			Base* found_object;
			while (true)
			{
				cin >> command >> heir_path;
				if (command == "FIND") {
					found_object = this->get_object(heir_path);
					if (found_object != nullptr)
					{
						cout << heir_path << "     Object name: " << found_object->get_name();
					}
				} else if (command == "SET") {
					*this = this->get_object(heir_path);
				} else if (command == "END") {
					break;
				}
				//Base* ready = cp->get_object_root()->get_object(heir_name);
				//int r;
				//cin >> r;
				//ready->set_readiness(r);
			}
			break;
		}
		/* if (parent_name == "endtree")
		{
			while (cin)
			{
				cin >> heir_name;
				if (heir_name == "q") {
					break;
				}
				Base* ready = cp->get_object_root()->get_object(heir_name);
				int r;
				cin >> r;
				ready->set_readiness(r);
			}
			break;
		} */
		cin >> heir_name >> cl_number;  // Далее опять вводим родителя и наследника
	}
}

void Major::exec_app()  //  Метод запуска приложения
{
	//this->print_tree_old();  // Печатаем все дерево
	this->print_tree();
}