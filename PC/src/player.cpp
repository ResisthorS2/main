#ifndef CELL_H
#include "cell.h"
#endif

#ifndef PLAYER_H
#include "player.h"
#endif



Player::Player()
{
    cell_north = new Cell;
    cell_south = new Cell;
    cell_east = new Cell;
    cell_west = new Cell;
    orientation = north;
}

Player::~Player()
{

}

int Player::getOrientation()
{
    return orientation;
}

void Player::setImageCell(Cell *cell)
{

}

void Player::operator=(Cell* cell)
{
    this->type = cell->getType();
    this->setImageCell(cell);
    this->setLocked(cell->getLocked());
    this->setCellAround(north, cell->getCellAround(north));
    this->setCellAround(south, cell->getCellAround(south));
    this->setCellAround(east, cell->getCellAround(east));
    this->setCellAround(west, cell->getCellAround(west));
}