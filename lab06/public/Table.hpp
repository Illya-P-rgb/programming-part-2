#ifndef TABLE_HPP
#define TABLE_HPP

class Table {
private:
    int rows_;
    int cols_;

public:
    Table();
    Table(int rows, int cols);

    int getRows() const;
    int getCols() const;
    int getCellCount() const;
};

#endif