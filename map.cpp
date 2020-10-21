#include <iostream>
#include <vector>

using namespace std;

Map::Map(){
    difficult = 20;
    area = makeMap(40,40);
}
Map::Map(int x) {
    difficult = x;
    area = Map::makeMap(x,x);
    fillMap();
}

vector<vector<int>> Map::getMap(){
    return area;
}
void Map::fillMap(){
    for (int x=0;x<area.size();x++) {
        for (int y=0;y<area[0].size();y++){
            if (area[x][y] == 1) {
                // add stuff to the maze, like treasure, or monsters, and the exit :^) 
                // treasure = 3
                // monster = 2
                // trap? = 4 (TODO) 
                // exit = 5? (TODO) (place this nonrandomly, and last 
                int chance = rand() % 100 + 1;
                if (chance == 100) {
                    area[x][y] = 3;
                }
                else if (chance >= 95) {
                    area[x][y] = 2;
                }
            }
        }
    }
}
// call this with either -1, 0 or 1 in one of the numbers, not both LOL 
int Map::move(int x,int y) {
    if (x != 0 && x+playerx < area.size() && x+playerx > 0) {
        if (area[playerx+x][playery] != 0){ playerx += x; }    
    }
    if (y != 0 && y + playery < area[0].size() && y+playery > 0) {
        if (area[playerx][playery+y] != 0){ playery += y; }
    }
    return area[playerx][playery];
    }
// in this implementation, 1= a wall, while 0 = a hall, or traversable area
vector<vector<int>> Map::generateHalls(vector<vector<int>> vec,int x,int y) {
    int len = vec.size()/5 + rand() % vec.size()/3;
    len = len + difficult;
    int intermediate;
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
    intermediate = x;
    for (int i = 0-len/2; i < len/2; i++){
    //for(int i=x-len/2;i<x+len/2;i++){
        intermediate = x + i;    
        if (intermediate > 0 && intermediate < vec.size()-1){
            vec[intermediate][y]=1;
        }
    }
    intermediate = y;
    for ( int i = 0-len/2;i<len/2;i++){
    //for(int i=y-len/2;i<y+len/2;i++){
        intermediate = y +i;
        if (intermediate > 0 && intermediate < vec[0].size()-1){
            vec[x][intermediate]=1;
        }
    }
    //make a perimeter around the outside edge 
    for (int i=0;i<vec.size();i++){
        vec[i][0] = 0;
        vec[i][vec[0].size()-2] = 0;
    }
    for (int i=0;i<vec[0].size();i++){
        vec[0][i]=0;
        vec[vec.size()-2][i] = 0;
    }
    return vec;
}

vector<vector<int>> Map::generateRooms(vector<vector<int>> vec) {
    int numrooms = vec[0].size()/3;
    //cout << numrooms << endl;
    while(numrooms > 0) {


        int rsize = 3 + rand() % vec.size()/5;
        int p1 = 1 + rand() % vec.size()-rsize;
        int p2 = 1 + rand() % vec[0].size()-rsize;
        int rmp = 1+rand() % rsize;
        //cout << "p1: " << p1 << " p2: " << p2 << " rsize: " << rsize << endl;
        for (int i=p1;i<p1 +rsize;i++){
            for (int j=p2;j<p2 + rsize;j++){
                if (i < vec.size() && j < vec[0].size()){
                    vec[i][j] = 1;
                }
            }
        }
        //cout << "we get here" << endl;
        vec = generateHalls(vec,p1+rmp,p2+rmp);
        numrooms--;
    }
    return vec;
}

vector<vector<int>> Map::makeMap(int x,int y) {
    //int x = 80;
    //int y = 80;
    vector<vector<int>> map(x,vector<int>(y,0));

    map = generateRooms(map);
    //map = traverse(map);
    // This part prints out the map
    //for(int xi =0;xi<x;xi++){
    //    for( int yi=0;yi<y;yi++){
    //        if (map[xi][yi] == 1) {
    //            cout << "*";
    //        }
    //        else {
    //            cout << " ";
    //        }
            //cout <<  << " ";
    //   }
    //    cout << endl;
    //}
    return map;


}
void Map::printMap(){
        for(int xi =0;xi<area.size()-1;xi++){
        for( int yi=0;yi<area[0].size()-1;yi++){
            if (area[xi][yi] == 1) {
                cout << ".";
            }
            else if (area[xi][yi] == 2) {//monster
                cout << "M";
            }
            else if (area[xi][yi] == 3) {//treasure
                cout << "T";
            }
            else if (area[xi][yi] == 4) {//trap
                cout << "&";
            }
            else {// wall LOL ( this is zero ) 
                cout << "*";
            }
        }
        cout << endl;
}
}

// this main is temporary, just proving that a map object can be generated basically. 
//int ma22in(){
 //   srand(time(NULL));
    //int a = 6;
    //int b = 8;
 //   vector<vector<int>> m = makemap(50,50);
 //   return 1;
//}
