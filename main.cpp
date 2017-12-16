#include <iostream>

using namespace std;

int green = 0;
int white = 1;
int orange = 2;
int yellow = 3;
int red = 4;
int blue = 5;

bool comparee(int cubeA[6][3][3], int cubeB[6][3][3]){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if (cubeA[i][j][k] != cubeB[i][j][k]){
                    return false;
                }
            }
        }
    }
    return true;
}

void copify(int cube[6][3][3], int newCube[6][3][3]){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                newCube[i][j][k] = cube[i][j][k];
            }
        }
    }
}

void cw(int face[3][3], int newFace[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            newFace[j][2 - i] = face[i][j];
        }
    }
}

void ccw(int face[3][3], int newFace[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            newFace[2 - j][i] = face[i][j];
        }
    }
}

void greencw(int cube[6][3][3], int newCube[6][3][3]){
    copify(cube, newCube);

    for(int i = 0; i < 3; i++){
        newCube[white][0][i] = cube[orange][0][i];
        newCube[red][0][i] = cube[white][0][i];
        newCube[yellow][0][i] = cube[red][0][i];
        newCube[orange][0][i] = cube[yellow][0][i];
    }
    cw(cube[green], newCube[green]);
}

void greenccw(int cube[6][3][3], int newCube[6][3][3]){
    copify(cube, newCube);
    for(int i = 0; i < 3; i++){
        newCube[white][0][i] = cube[red][0][i];
        newCube[orange][0][i] = cube[white][0][i];
        newCube[yellow][0][i] = cube[orange][0][i];
        newCube[red][0][i] = cube[yellow][0][i];
    }
    ccw(cube[green], newCube[green]);
}

void whitecw(int cube[6][3][3], int newCube[6][3][3]){
    copify(cube, newCube);
    for(int i = 0; i < 3; i++){
        newCube[orange][i][0] = cube[green][2][i];
        newCube[blue][0][2 - i] = cube[orange][i][0];
        newCube[red][i][2] = cube[blue][0][i];
        newCube[green][2][i] = cube[red][2 - i][2];
    }
    cw(cube[white], newCube[white]);
}

void whiteccw(int cube[6][3][3], int newCube[6][3][3]){
    copify(cube, newCube);
    for(int i = 0; i < 3; i++){
        newCube[green][2][i] = cube[orange][i][0];
        newCube[orange][i][0] = cube[blue][0][2 - i];
        newCube[blue][0][i] = cube[red][i][2];
        newCube[red][2 - i][2] = cube[green][2][i];
    }
    ccw(cube[white], newCube[white]);
}

void orangecw(int cube[6][3][3], int newCube[6][3][3]){
    copify(cube, newCube);
    for(int i = 0; i < 3; i++){
        newCube[green][i][2] = cube[white][i][2];
        newCube[white][i][2] = cube[blue][i][2];
        newCube[blue][i][2] = cube[yellow][2 - i][0];
        newCube[yellow][i][0] = cube[green][2 - i][2];
    }
    cw(cube[orange], newCube[orange]);
}

void orangeccw(int cube[6][3][3], int newCube[6][3][3]){
    copify(cube, newCube);
    for(int i = 0; i < 3; i++){
        newCube[green][i][2] = cube[yellow][2 - i][0];
        newCube[yellow][2 - i][0] = cube[blue][i][2];
        newCube[blue][i][2] = cube[white][i][2];
        newCube[white][i][2] = cube[green][i][2];
    }
    ccw(cube[orange], newCube[orange]);
}

void yellowcw(int cube[6][3][3], int newCube[6][3][3]){
    copify(cube, newCube);
    for(int i = 0; i < 3; i++){
        newCube[red][2 - i][0] = cube[green][0][i];
        newCube[blue][2][i] = cube[red][i][0];
        newCube[orange][2 - i][2] = cube[blue][2][i];
        newCube[green][0][i] = cube[orange][i][2];
    }
    cw(cube[yellow], newCube[yellow]);
}

void yellowccw(int cube[6][3][3], int newCube[6][3][3]){
    copify(cube, newCube);
    for(int i = 0; i < 3; i++){
        newCube[green][0][i] = cube[red][2 - i][0];
        newCube[red][i][0] = cube[blue][2][i];
        newCube[blue][2][i] = cube[orange][2 - i][2];
        newCube[orange][i][2] = cube[green][0][i];
    }
    ccw(cube[yellow], newCube[yellow]);
}

void redcw(int cube[6][3][3], int newCube[6][3][3]){
    copify(cube, newCube);
    for(int i = 0; i < 3; i++){
        newCube[green][i][0] = cube[yellow][2 - i][2];
        newCube[yellow][i][2] = cube[blue][2 - i][0];
        newCube[blue][i][0] = cube[white][i][0];
        newCube[white][i][0] = cube[green][i][0];
    }
    cw(cube[red], newCube[red]);
}

void redccw(int cube[6][3][3], int newCube[6][3][3]){
    copify(cube, newCube);
    for(int i = 0; i < 3; i++){
        newCube[green][i][0] = cube[white][i][0];
        newCube[white][i][0] = cube[blue][i][0];
        newCube[blue][i][0] = cube[yellow][2 - i][2];
        newCube[yellow][i][2] = cube[green][2 - i][0];
    }
    ccw(cube[red], newCube[red]);
}

void bluecw(int cube[6][3][3], int newCube[6][3][3]){
    copify(cube, newCube);
    for(int i = 0; i < 3; i++){
        newCube[white][2][i] = cube[red][2][i];
        newCube[orange][2][i] = cube[white][2][i];
        newCube[yellow][2][i] = cube[orange][2][i];
        newCube[red][2][i] = cube[yellow][2][i];
    }
    cw(cube[blue], newCube[blue]);
}

void blueccw(int cube[6][3][3], int newCube[6][3][3]){
    copify(cube, newCube);
    for(int i = 0; i < 3; i++){
        newCube[white][2][i] = cube[orange][2][i];
        newCube[red][2][i] = cube[white][2][i];
        newCube[yellow][2][i] = cube[red][2][i];
        newCube[orange][2][i] = cube[yellow][2][i];
    }
    ccw(cube[blue], newCube[blue]);
}

void pickTurn(int preMove[6][3][3], int index, int postMove[6][3][3]){
    copify(preMove, postMove);
    if (index == 0){
        greencw(preMove, postMove);
    }
    else if (index == 1){
        greenccw(preMove, postMove);
    }
    else if (index == 2){
        whitecw(preMove, postMove);
    }
    else if (index == 3){
        whiteccw(preMove, postMove);
    }
    else if (index == 4){
        orangecw(preMove, postMove);
    }
    else if (index == 5){
        orangeccw(preMove, postMove);
    }
    else if (index == 6){
        yellowcw(preMove, postMove);
    }
    else if (index == 7){
        yellowccw(preMove, postMove);
    }
    else if (index == 8){
        redcw(preMove, postMove);
    }
    else if (index == 9){
        redccw(preMove, postMove);
    }
    else if (index == 10){
        bluecw(preMove, postMove);
    }
    else{
        blueccw(preMove, postMove);
    }
}

int doMoves(int cube[6][3][3], int step, int compare[6][3][3]){
    if (step == 0){
        if (comparee(cube, compare)){
            return 0;
        }
        return doMoves(cube, ++step, compare);
    }

    if (step == 1){
        for(int i = 0; i < 12; i++){
            int nextMove[6][3][3];
            pickTurn(cube, i, nextMove);
            if(comparee(nextMove, compare)){
                return 1;
            }
        }
        return doMoves(cube, ++step, compare);
    }

    if (step == 2){
        for(int a = 0; a < 12; a++){
            int nextA[6][3][3];
            pickTurn(cube, a, nextA);
            for(int b = 0; b < 12; b++){
                int nextB[6][3][3];
                pickTurn(nextA, b, nextB);
                if(comparee(nextB, compare)){
                    return step;
                }
            }
        }
        return doMoves(cube, ++step, compare);
    }

    if (step == 3){
        for(int a = 0; a < 12; a++){
            int nextA[6][3][3];
            pickTurn(cube, a, nextA);
            for(int b = 0; b < 12; b++){
                int nextB[6][3][3];
                pickTurn(nextA, b, nextB);
                for(int c = 0; c < 12; c++){
                    int nextC[6][3][3];
                    pickTurn(nextB, c, nextC);
                    if(comparee(nextC, compare)){
                        return step;
                    }
                }
            }
        }
        return doMoves(cube, ++step, compare);
    }

    if (step == 4){
        for(int a = 0; a < 12; a++){
            int nextA[6][3][3];
            pickTurn(cube, a, nextA);
            for(int b = 0; b < 12; b++){
                int nextB[6][3][3];
                pickTurn(nextA, b, nextB);
                for(int c = 0; c < 12; c++){
                    int nextC[6][3][3];
                    pickTurn(nextB, c, nextC);
                    for(int d = 0; d < 12; d++){
                        int nextD[6][3][3];
                        pickTurn(nextC, d, nextD);
                        if(comparee(nextD, compare)){
                            return step;
                        }
                    }
                }
            }
        }
        return doMoves(cube, ++step, compare);
    }

    if (step == 5){
        for(int a = 0; a < 12; a++){
            int nextA[6][3][3];
            pickTurn(cube, a, nextA);
            for(int b = 0; b < 12; b++){
                int nextB[6][3][3];
                pickTurn(nextA, b, nextB);
                for(int c = 0; c < 12; c++){
                    int nextC[6][3][3];
                    pickTurn(nextB, c, nextC);
                    for(int d = 0; d < 12; d++){
                        int nextD[6][3][3];
                        pickTurn(nextC, d, nextD);
                        for(int e = 0; e < 12; e++){
                            int nextE[6][3][3];
                            pickTurn(nextD, e, nextE);
                            if(comparee(nextE, compare)){
                                return step;
                            }
                        }
                    }
                }
            }
        }
        return doMoves(cube, ++step, compare);
    }

    if (step == 6){
        for(int a = 0; a < 12; a++){
            int nextA[6][3][3];
            pickTurn(cube, a, nextA);
            for(int b = 0; b < 12; b++){
                int nextB[6][3][3];
                pickTurn(nextA, b, nextB);
                for(int c = 0; c < 12; c++){
                    int nextC[6][3][3];
                    pickTurn(nextB, c, nextC);
                    for(int d = 0; d < 12; d++){
                        int nextD[6][3][3];
                        pickTurn(nextC, d, nextD);
                        for(int e = 0; e < 12; e++){
                            int nextE[6][3][3];
                            pickTurn(nextD, e, nextE);
                            for(int f = 0; f < 12; f++){
                                int nextF[6][3][3];
                                pickTurn(nextE, f, nextF);
                                if(comparee(nextF, compare)){
                                    return step;
                                }
                            }
                        }
                    }
                }
            }
        }
        return doMoves(cube, ++step, compare);
    }


    return -1;
}

int main()
{
    int solve[6][3][3];
    for (int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                solve[i][j][k] = i;
            }
        }
    }
    int myCube[6][3][3] = {
        {
            {
                white, orange, white
            },
            {
                white, green, blue
            },
            {
                blue, red, orange
            }
        },
        {
            {
                orange, blue, green
            },
            {
                green, white, orange
            },
            {
                red, yellow, green
            }
        },
        {
            {
                white, white, red
            },
            {
                blue, orange, orange
            },
            {
                red, yellow, blue
            }
        },
        {
            {
                blue, green, blue
            },
            {
                white, yellow, white
            },
            {
                yellow, orange, orange
            }
        },
        {
            {
                orange, green, yellow
            },
            {
                red, red, red
            },
            {
                green, green, white
            }
        },
        {
            {
                green, blue, yellow
            },
            {
                yellow, blue, red
            },
            {
                yellow, yellow, red
            }
        }
    };

    int rotated1[6][3][3];
    pickTurn(solve, 11, rotated1);
    int rotated2[6][3][3];
    pickTurn(rotated1, 2, rotated2);
    int rotated3[6][3][3];
    pickTurn(rotated2, 7, rotated3);
    int rotated4[6][3][3];
    pickTurn(rotated3, 10, rotated4);
    int rotated5[6][3][3];
    pickTurn(rotated4, 0, rotated5);
    int rotated6[6][3][3];
    pickTurn(rotated5, 3, rotated6);


    cout << doMoves(solve, 0, myCube);

    return 0;
}
