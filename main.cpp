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
        for(int j = 0; j < 6; j++){
            for(int k = 0; k < 6; k++){
                if (cubeA[i][j][k] == cubeB[i][j][k]){
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
    for(int i = 0; i < 3; i++){
        newCube[white][0][i] = cube[orange][0][i];
        newCube[red][0][i] = cube[white][0][i];
        newCube[yellow][0][i] = cube[red][0][i];
        newCube[orange][0][i] = cube[yellow][0][i];
    }
    cw(cube[green], newCube[green]);
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
                yellow, green, yellow
            },
            {
                yellow, blue, orange
            }
        },
        {
            {
                green, red, blue
            },
            {
                blue, white, orange
            },
            {
                green, yellow, blue
            }
        },
        {
            {
                yellow, red, red
            },
            {
                white, orange, blue
            },
            {
                yellow, green, white
            }
        },
        {
            {
                blue, green, blue
            },
            {
                orange, yellow, white
            },
            {
                green, red, green
            }
        },
        {
            {
                orange, orange, red
            },
            {
                green, red, yellow
            },
            {
                yellow, blue, red
            }
        },
        {
            {
                white, green, red
            },
            {
                white, blue, red
            },
            {
                orange, white, orange
            }
        }
    };

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                cout << myCube[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }

    int rotated[6][3][3];
    greencw(myCube, rotated);
    copify(myCube, rotated);
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                cout << rotated[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
