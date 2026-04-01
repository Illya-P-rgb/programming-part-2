#include "Table.hpp"

Table::Table() : rows(0), cols(0) {}

Table::Table(int rows, int cols) : rows(rows), cols(cols) {}

int Table::getRows() const {
    return rows;
}

int Table::getCols() const {
    return cols;
}