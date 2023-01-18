#include "Control.h"
#include "snake.h"
#include "Board.h"
#include <vector>
#include <windows.h>
Control::Control(std::vector <snake *> sn ,player pp)
{
    p = pp;
    s = sn;
}

void Control::updatekay(char d)
{
    p.move(d);

}
void Control::updetesnake()
{

    for(size_t i =0 ; i<s.size() ; i++)
    {
        s[i]->move(p);
    }
}

bool Control::finished()
{
    bool f ;
    f =false;
    for(size_t i =0 ; i<s.size() ; i++)
    {
        if((s[i]->get_x() == p.get_x()) && (s[i]->get_y() == p.get_y()))
            f = true;
    }
    return f;
}
std::string Control::getboard()
{
    std::string st="";
    for(int i=0 ; i<Board::get_maxx()+2 ; i++)
        st =st + "#";
    st = st +"\n";
    for(int k=0 ; k<Board::get_maxy()-1 ;k++)
    {
        st = st +"#" ;
        for(int j=0 ; j < Board::get_maxx() ; j++)
        {
            bool isp = false;
            if(p.ishere(j,k))
            {
                st = st + "P" ;
                isp = true;
            }
            else
                {
                    for(size_t i=0 ; i <s.size() ; i++ )
                    {
                        if(s[i]->ishere(j , k))
                        {
                            st = st + "O" ;
                            isp = true;
                            i = s.size();
                        }
                    }
                }
            if(!isp)
                st = st + " ";

        }
        st = st +"#\n";

    }
    for(int i=0 ; i<Board::get_maxx()+2 ; i++)
        st =st + "#";
    return st;
}
