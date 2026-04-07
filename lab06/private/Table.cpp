#include "Table.hpp"

Table::Table() : rows_(0), cols_(0) {}

Table::Table(int rows, int cols) : rows_(rows), cols_(cols) {}

int Table::getRows() const {
    return rows_;
}

int Table::getCols() const {
    return cols_;
}

int Table::getCellCount() const {
    return rows_ * cols_;
}