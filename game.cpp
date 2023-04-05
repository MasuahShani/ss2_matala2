#include "game.hpp"

Game(Player& p1, Player& p2)
{
    this->p1=p1;
    this->p2=p2;
    this->situations="";
    this->lastTurn="";
    this->winer=0;
    this->drowns=0;

}    
~Game(){}
void playTurn()
{
    if(p1.stacksize()==0)
    {
        if(p1.getWinings()>p2.getWinings())
        {
            this->winer=1;
        }
        else if (p1.getWinings()<p2.getWinings())
        {
            this->winer=2;
        }
        else
        {
            this->winer=-1;
        }
        
        cout << "GAME OVER" << endl;
        return;
    }
    if(p1.stacksize()==1)
    {
        if(p1_card>p2_card)///ךא אתחלתי את זה.. אחכ עם הכרטיסים עצמם
        {
            p1.addWin(card_p1);/////cardd!!!
            (this->situations)+=p1.getName()+" played "+p1_str+" "+p2.getName()+" played "+p2_str+". "+p1.getName()+" wins. ";
            (this->lastTurn)=p1.getName()+" played "+p1_str+" "+p2.getName()+" played "+p2_str+". "+p1.getName()+" wins. ";
            
        }
        else if(p1_card<p2_card)
        {
            p2.addWin(card_p2);
            (this->situations)+=p2.getName()+" played "+p2_str+" "+p1.getName()+" played "+p1_str+". "+p2.getName()+" wins. ";
            (this->lastTurn)=p2.getName()+" played "+p2_str+" "+p1.getName()+" played "+p1_str+". "+p2.getName()+" wins. ";
            
        }
        if(p1.getWinings()>p2.getWinings())
        {
            this->winer=1;
        }
        else if (p1.getWinings()<p2.getWinings())
        {
            this->winer=2;
        }
        else
        {
            this->winer=-1;
        }
        
        cout << "GAME OVER" << endl;
        return;
    }

    מערך של קלפים, נכניס אליו את הקלף הראשון מכל חבילה
    int p1_card_num=p1.getNumCard();
    int p2_card_num=p2.getNumCard();
    string p1_str=p1.cardToString();
    string p2_str=p2.cardToString();
    if(p1_card_num>p2_card_num)
    {
        p1.addWin(card_p1);
        (this->situations)+=p1.getName()+" played "+p1_str+" "+p2.getName()+" played "+p2_str+". "+p1.getName()+" wins. ";
        (this->lastTurn)=p1.getName()+" played "+p1_str+" "+p2.getName()+" played "+p2_str+". "+p1.getName()+" wins. ";
        return;
    }
    else if(p1_card<p2_card)
    {
        p2.addWin();
        (this->situations)+=p2.getName()+" played "+p2_str+" "+p1.getName()+" played "+p1_str+". "+p2.getName()+" wins. ";
        (this->lastTurn)=p2.getName()+" played "+p2_str+" "+p1.getName()+" played "+p1_str+". "+p2.getName()+" wins. ";
        return;
    }
    else
    {
        (this->lastTurn)="";
        while (p1.stacksize()>2 && p1_card==p2_card)
        {
            (this->drowns)++;
            //להכניס למערך קלף נוסף ואז עוד קלף ואותו לקחת
            int p1_card=p1.getNumCard();
            int p2_card=p2.getNumCard();
            string p1_str=p1.cardToString();
            string p2_str=p2.cardToString();

            if(p1.stacksize()<2 && p1_card==p2_card)
            {
                //לחלק את הקלפים שבערימה חצי חצי לשחקנים, לא באותו סדר
            }
            
            (this->situations)+=p1.getName()+" played "+p1_str+" "+p2.getName()+" played "+p2_str+". draw. ";
            (this->lastTurn)+=p1.getName()+" played "+p1_str+" "+p2.getName()+" played "+p2_str+". draw. ";
            

        }
        if(p1.stacksize()==1)
        {
            //צריך לבדוק מה לעשות במקרה כזה כי יש 2 קלפים אחרונים
            // אם כל הקלפים אותו דבר לא טוב

        }
        if(p1_card>p2_card)
        {
            p1.addWin();
            (this->situations)+=p1.getName()+" played "+p1_str+" "+p2.getName()+" played "+p2_str+". "+p1.getName()+" wins. ";
            (this->lastTurn)=p1.getName()+" played "+p1_str+" "+p2.getName()+" played "+p2_str+". "+p1.getName()+" wins. ";
            return;
        }
        else if(p1_card<p2_card)
        {
            p2.addWin();
            (this->situations)+=p2.getName()+" played "+p2_str+" "+p1.getName()+" played "+p1_str+". "+p2.getName()+" wins. ";
            (this->lastTurn)=p2.getName()+" played "+p2_str+" "+p1.getName()+" played "+p1_str+". "+p2.getName()+" wins. ";
            return;
        }
        
    }
}

    void printLastTurn()
    {
        cout << this->lastTurn << endl;
    }
    void playAll()
    {
        while (this->winer==0)
        {
            playTurn();
        }
        
    }
    void printWiner()
    {
        if(this->winer==0)
        {
            cout << "There is no winer yet" << endl;
        }
        else if(this->winer==-1)
        {
            cout << "Draw" << endl;
        }
        else if(this->winer==1)
        {
            cout << p1.getName() << endl;
        }
        else if(this->winer==2)
        {
            cout << p2.getName() << endl;
        }
    }
    void printLog()
    {
        cout << this->situations << andl;
    }
    void printStats()
    {
        cout << p1.getName() + "stats:" << andl;
        cout << "win rate: "+p1.getWinings()+ " cards won"

    }