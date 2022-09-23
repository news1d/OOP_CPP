#include <iostream>
#include "classes.h"

int main() {
    srand(time(0));

    // 2. Реализовать метод генерации каталога книг разного объема, авторов, жанров и ограничений.
    // 3. Реализовать метод поиска нужной книги по критериям отбора: возраст посетителя, предпочтительный объем, жанр, при этом должна браться первая книга.
    Library catalog;
    catalog.createCatalog();
    catalog.print();
    Visitor Person(17, "Medium", "Fantasy", 3);
    catalog.seacrhBook(Person);

    // 4. Реализовать метод чтения книги посетителем. Длительность чтения зависит от объема книги и скорости чтения отдельного посетителя.
    Book anotherBook("Becoming The Elements", 30, 12, "Romance", "Ricky Henry");
    Person.reading(anotherBook);

    // 5. Реализовать метод запроса посетителем книги из библиотеки и ее прочтения.
    catalog.searchNread(Person);


    return 0;
}
