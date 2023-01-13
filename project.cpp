#include <iostream>
using namespace std;

class Rectangle{
    protected:
        int x, y;
    public:
        Rectangle(int i, int j){
            x = i;
            y = j;
        }
        
}

class Ball : public Rectangle{
    private :
        int moving_direction;//0 means stable, 1 means right up, 2 means right down, 3 means left down, 4 means left up

        bool go_up(){
            if(y > 0):
                y -= 1;
                return true;
            return false;
        }
        bool go_down(){
            if(y + 1 < Y_SIZE_OF_LED):
                y += 1;
                return true;
            return false;
        }
        bool go_left(){
            if(x > 0):
                x -= 1;
                return true;
            return false;
        }
        bool go_right(){
            if(x + 1 < X_SIZE_OF_LED):
                x += 1;
                return true;
            return false;
        }
    public :
        Ball(){
            ballInit();
        }
        void ballInit(){
            x = X_CENTER;
            y = Y_CENTER;
            moving_direction = 0;
        }
        bool move(){
            switch(moving_direction){
                case 1:
                    if(!go_up()){
                        moving_direction = 2;
                        go_down();
                    }
                    if(!go_right()){
                        moving_direction = 0;
                        x = X_CENTER;
                        y = Y_CENTER;
                        return true;
                    }
                    return false;
                case 2:
                    if(!go_down()){
                        moving_direction = 3;
                        go_up();
                    }
                    if(!go_left()){
                        moving_direction = 0;
                        x = X_CENTER;
                        y = Y_CENTER;
                        return true;
                    }
                    return false;
                case 3:
                    if(!go_down()){
                        moving_direction = 2;
                        go_up();
                    }
                    if(!go_left()){
                        moving_direction = 0;
                        x = X_CENTER;
                        y = Y_CENTER;
                        return true;
                    }
                    return false;
                case 4:
                    if(!go_up()){
                        moving_direction = 2;
                        go_down();
                    }
                    if(!go_left()){
                        moving_direction = 0;
                        x = X_CENTER;
                        y = Y_CENTER;
                        return true;
                    }
                    return false;
                default:
                    return false;
            }
        }
}

class Controller : public Rectangle{
        private:
            int left0Right1;
    public:
        Controller(int i){
            // 0 for left controller, 1 for right controller
            left0Right1 = i;
            controllerInit();
        }

        void controllerInit(){
            if(left0Right1 == 0){
                y = Y_CENTER;
                x = 0;
            }
            else{
                y = Y_CENTER;
                x = X_SIZE_OF_LED - 1;
            }
        }

        bool go_up(){
            if(y > 0):
                y -= 1;
                return true;
            return false;
        }
        bool go_down(){
            if(y + 3 < Y_SIZE_OF_LED):
                y += 1;
                return true;
            return false;
        }
    public :
        void move(int moving_direction){
            //0 for stable, 1 for up, 2 for down
            switch(moving_direction){
                case 1:
                    go_up();
                case 2:
                    go_down();
            }
        }
}


int main() {
  return 0;
}