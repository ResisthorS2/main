#include <iostream>


#define CELL_H



#define LOCKED 1
#define UNLOCKED 0


#define VIDE 0  
#define COULOIR 1  
#define DOORNORTH 2  
#define DOORSOUTH 3  
#define DOOREAST 4  
#define DOORWEST 5  


const int NONE=-1;
const int north=0;
const int south=1;
const int east=2;
const int west=3;
const int maxRoom=20;

std::string RESET  = "\x1b[0m";
std::string BLACK  = "\x1b[30m";      /* Black */
std::string RED    = "\x1b[31m";      /* Red */
std::string GREEN  = "\x1b[32m";      /* Green */
std::string YELLOW = "\x1b[33m";      /* Yellow */
std::string BLUE   = "\x1b[34m";      /* Blue */
std::string MAGENTA = "\x1b[35m";      /* Magenta */
std::string CYAN   = "\x1b[36m";      /* Cyan */
std::string WHITE  = "\x1b[37m";      /* White */




struct Coordinate
{
    int x;
    int y;
};
typedef Coordinate Coordinate;

class Cell
{
    public:
        Cell();
        Cell(int type);
        virtual ~Cell();
        /** @brief retourne le type de la Cell @return int{vide = 0, couloir = 1, classe = 2,}*/
        int getType();
        /** @brief retourne un int selon si la Cell est vérouillée @return 0 = UNLOCKED, 1 = LOCKED */
        void setType(int type);
        virtual void setImageCell(Cell *cell);
        std::string printCellTerminal(int line);
        void printCell();
        Cell* enterCell();
        std::string imageCell[3][3];
        void setLocked(int locked);
        int getLocked();
        void setCellAround(int orientation, Cell* cell);
        Cell *getCellAround(int orientation);
        void cpyEnterFrom(int *enterFrom);
        

    private:
        int type;
        Cell* cell_north;
        Cell* cell_south;
        Cell* cell_east;
        Cell* cell_west;
        int *enterFrom; /** @brief Tu peux entrer quand tu proviens de ____ NONE=-1, north=0, south=1, east=2, west=3 */
        int locked; /** @brief 0 = UNLOCKED, 1 = LOCKED */
        int keyToUnlock;
        //Minigame minigame[];
};
