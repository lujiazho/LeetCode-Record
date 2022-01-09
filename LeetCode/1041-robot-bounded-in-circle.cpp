///////////////////////////////////////////////////////////////////////////////////////////////
// kind of like math, we only need to check the location of robot within 4 rounds.
// Because if the robot cannot reach 0,0 within 4 rounds, it will never reach 0,0 again
////////////////
// Time Complexity: O(n), n equals to the length of instructions
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int i=0, j=0, face=0; // 0: "north", 1: "south", 2: "east", 3: "west"
        for (int a=0 ; a<4 ; a++){
            for (int b=0 ; b<instructions.length() ; b++){
                if (instructions[b] == 'G'){
                    switch (face){
                        case 0:
                            j += 1;
                            break;
                        case 1:
                            j -= 1;
                            break;
                        case 2:
                            i += 1;
                            break;
                        case 3:
                            i -= 1;
                            break;
                    }
                }else{
                    switch (face){
                        case 0:
                            if (instructions[b] == 'L'){
                                face = 3;
                            }else{
                                face = 2;
                            }
                            break;
                        case 1:
                            if (instructions[b] == 'L'){
                                face = 2;
                            }else{
                                face = 3;
                            }
                            break;
                        case 2:
                            if (instructions[b] == 'L'){
                                face = 0;
                            }else{
                                face = 1;
                            }
                            break;
                        case 3:
                            if (instructions[b] == 'L'){
                                face = 1;
                            }else{
                                face = 0;
                            }
                            break;
                    }
                }
            }
            if (i == 0 and j == 0){
                return true;
            }
        }
        return false;
    }
};