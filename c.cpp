#include <iostream>
#include <vector>
#include <queue>

class Game_map {
    
    int height_;
    int length_;
    std::vector <int> main_map_;

public:

    Game_map(int h, int l, std::vector <int> m) : height_(h), length_(l), main_map_(m) {};
    ~Game_map() {}

    void print_map() {
        for(int i = 0; i < main_map_.size(); i++) {
            if(i % length_ == 0 && i != 0) {
                if(i == main_map_.size()) {
                    std::cout << main_map_.at(i) << std::endl;
                }
                else {
                    std::cout << main_map_.at(i) << ' ' << std::endl;
                }
            }

            else {  
                std::cout << main_map_.at(i) << ' ';
            }
             
        }
    }

    void find_way(Game_map obj) {
        int f = 0;
        for(int g = 0; g < main_map_.size(); g++) {
            if(main_map_.at(g) == 2) {
                f = 2;
            }
        }
        if(f != 2) {
            std::cout << "There is no player on the map!" << std::endl;
        }
        
        int player_pos;
        for(int i = 0; i < main_map_.size(); i++) {
            if(main_map_.at(i) == 2) {
                player_pos = main_map_.at(i);
            }
        }

        std::queue<int> q;
        q.push(player_pos);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            int current_val = main_map_.at(curr);
            std::vector <int> neighbors = { -1, 1, -length_, length_ };

            for (int offset = 0; offset < neighbors.size(); offset++) {
                int next = curr + offset;

                if (next < 0 || next >= main_map_.size()) continue;
                if (offset == 1 && next % length_ == 0) continue;
                if (offset == -1 && curr % length_ == 0) continue;

                if (main_map_.at(next) == 0) { 
                    main_map_.at(next) = current_val - 1;
                    q.push(next);
                }
            }
        }
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
    };

    Game_map object = {5,5,a};
    object.print_map();
    //object.find_way(object);
    //Game_map::print_map(object);

}

// 1 1 1 1 1 1 1 1 1 1
// 1 2 0 1 0 0 0 0 0 1
// 1 0 0 1 0 0 1 0 0 1
// 1 0 0 1 0 0 1 0 0 3
// 1 0 0 0 0 0 1 0 0 1
// 1 0 0 0 0 0 0 0 0 1
// 1 1 1 1 1 1 1 1 1 1