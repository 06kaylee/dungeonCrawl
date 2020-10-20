#include <iostream>
#include <vector>
#include <time.h>
using namespace std;


// in this implementation, 1= a wall, while 0 = a hall, or traversable area
vector<vector<int>> generateHalls(vector<vector<int>> vec,int x,int y) {
    int len = 10 + rand() % 40;
    if (x > vec.size()-1){
        x = vec.size()-2;
    }
    else if ( x< 2) {
        x = 2;
    }
    if (y > vec[0].size()-1){
        y = vec[0].size()-2;
    }
    else if (y < 2){
        y = 2;
    }
    for(int i=x-len/2;i<x+len;i++){
        if (i > 0 && i < vec.size()-1){
            vec[i][y]=0;
        }
    }
    for(int i=y-len/2;i<y+len;i++){
        if (i > 0 && i < vec[0].size()-1){
            vec[x][i]=0;
        }
    }
    return vec;
}
vector<vector<int>> generateRooms(vector<vector<int>> vec) {
    int numrooms = vec[0].size()/3;
    //cout << numrooms << endl;
    while(numrooms > 0) {


        int rsize = 3 + rand() % vec.size()/5;
        int p1 = 1 + rand() % vec.size()-rsize;
        int p2 = 1 + rand() % vec[0].size()-rsize;
        int rmp = 4+rand() % rsize;
        //cout << "p1: " << p1 << " p2: " << p2 << " rsize: " << rsize << endl;
        for (int i=p1;i<p1 +rsize;i++){
            for (int j=p2;j<p2 + rsize;j++){
                if (i < vec.size() && j < vec[0].size()){
                    vec[i][j] = 0;
                }
            }
        }
        //cout << "we get here" << endl;
        vec = generateHalls(vec,p1+rmp,p2+rmp);
        numrooms--;
    }
    return vec;
}

vector<vector<int>> makemap(int x,int y) {
    //int x = 80;
    //int y = 80;
    vector<vector<int>> map(x,vector<int>(y,1));

    map = generateRooms(map);
    //map = traverse(map);
    // This part prints out the map
    for(int xi =0;xi<x;xi++){
        for( int yi=0;yi<y;yi++){
            if (map[xi][yi] == 1) {
                cout << "*";
            }
            else {
                cout << " ";
            }
            //cout <<  << " ";
        }
        cout << endl;
    }
    return map;


}


// this main is temporary, just proving that a map object can be generated basically. 
int main(){
    srand(time(NULL));
    //int a = 6;
    //int b = 8;
    vector<vector<int>> m = makemap(50,50);
    return 1;
}
