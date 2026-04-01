#ifndef TABLE_HPP
#define TABLE_HPP

class Table {
private:
    int rows;
    int cols;

public:
    Table();
    Table(int rows, int cols);

    int getRows() const;
    int getCols() const;
};

#endif