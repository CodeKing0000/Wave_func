#include <iostream>
#include <vector>

class Game_map {
    
    int height_;
    int length_;
    std::vector <int> main_map_;

public:

    Game_map(int height_, int length_, std::vector <int> main_map_);

    void print_map(std::vector <int> obj) {
        for(int i = 0; i <= obj.size(); i++) {
            std::cout << obj.at(i);
        }
    }

    void find_way(std::vector <int> obj) {
        for(int i = 0; i <= obj.size(); i++) {
            if(obj.at(i) == 2) {
                for(int j = 0; j <= obj.size(); j++) {
                    if(obj.at(i-1) != 1) {
                        obj.at(i-1)--;
                    }
                    if(obj.at(i+1) != 1) {
                        obj.at(i+1)--;
                    }
                    if(obj.at(i-length_) != 1) {
                        obj.at(i-length_)--;
                    }
                    if(obj.at(i+length_) == 1) {
                        obj.at(i+length_)--;
                    }
                }
            }
        }
        std::cout << 'There is no player on the map!';
    }

    int height() {
        return height_;
    }
    int length() {
        return length_;
    }
    std::vector <int> main_map() {
        return main_map_;
    }

};

int main() {
    std::vector <int> a = {
        1,1,1,1,1,
        1,2,0,0,1,
        1,0,1,1,1,
        1,0,0,0,3,
        1,1,1,1,1
    }

    

}

// 1 1 1 1 1 1 1 1 1 1
// 1 2 0 1 0 0 0 0 0 1
// 1 0 0 1 0 0 1 0 0 1
// 1 0 0 1 0 0 1 0 0 3
// 1 0 0 0 0 0 1 0 0 1
// 1 0 0 0 0 0 0 0 0 1
// 1 1 1 1 1 1 1 1 1 1