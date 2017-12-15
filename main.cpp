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

void pickTurn(preMove, index, postMove){
    copify(preMove, postMove);
    if (index == 0){
        greencw(preMove, postMove);
    }
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
    bluecw(solve, rotated1);

    int rotated2[6][3][3];
    blueccw(rotated1, rotated2);

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                cout << rotated2[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
