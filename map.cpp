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
}// comment to test

vector<vector<int>> Map::getMap(){
    return area;
}//asdhjahsdkjhakjshdkahskdjhakj
void Map::repopulate(int num){// this method tries to add some new stuff to the map when you visit an exit... or something... whenever you call it really, but it makes it so that the map doesn;t become empty with no way to progress
  for (int x=0;x<num;x++){
    int p1 = 1 + rand() % area.size()-1;
    int p2 = 1 + rand() % area[0].size()-1;
      if (area[p1][p2] == 1) {
        int chance = rand() % 100 + 1;
        if (chance == 100) {
            area[p1][p2] = 3;
        }
        else if (chance >= 95) {
            area[p1][p2] = 2;
        }
      }
  }
}
void Map::fillMap(){
    //creates three exits on the map, placed randomly
    int exitfound = 3;
    while (exitfound) {
        int p1 = 1 + rand() % area.size()-1;
        int p2 = 1 + rand() % area[0].size()-1;
        if (area[p1][p2] == 1) {
            area[p1][p2] = 5;
            exitfound --;
        }
    }

    for (int x=0;x<area.size();x++) {
        for (int y=0;y<area[0].size();y++){
            if (area[x][y] == 1) {
                // add stuff to the maze, like treasure, or monsters, and the exit :^)
                // treasure = 3
                // monster = 2
                // trap? = 4 (TODO)
                // exit = 5? (TODO) (place this nonrandomly, and last
                int chance = rand() % 100 + 1;
                if (chance >= 99) {
                    area[x][y] = 3;
                }
                else if (chance >= 91) {
                    area[x][y] = 2;
                }
            }
        }
    }
    // this part generates a starting location for the player
    // I think mathematically it will always work, but I'm not gonna try and prove that
    int found = 1;
    int x=0;
    int y=0;
    while (found) {
        if (area[x][y] == 1) {
            area[x][y] = 6;
            found --; // if a starting location is found, stop looping, and set the playerx and y coordinates.
            playerx = x;
            playery = y;
        }
        x++;
        y++;

    }
}
// call this with either -1, 0 or 1 in one of the numbers, not both LOL
int Map::move(int x,int y) {
  int fight =0;
    if (area[playerx][playery] != 5){
      area[playerx][playery] = 1;
  }
    if (x != 0 && x+playerx < area.size() && x+playerx > 0) {
        if (area[playerx+x][playery] != 0){ playerx += x; }
    }
    if (y != 0 && y + playery < area[0].size() && y+playery > 0) {
        if (area[playerx][playery+y] != 0){ playery += y; }
    }
    if (area[playerx][playery] == 2){// hit a monster
      fight = 1;
    }
    else if (area[playerx][playery] == 3) { // hit treasure
      fight = 2;
    }
    else if (area[playerx][playery] == 5) {// hit an exit
      fight = 3;
    }

    if (area[playerx][playery] != 5){// if you hit the exit, you don't overright it ?
      area[playerx][playery] = 6;
    }
    return fight;
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
    vector<vector<int>> map(x,vector<int>(y,0));

    map = generateRooms(map);
    return map;


}
void Map::printMap(){// I guess we have to hope that the school computers use a modern version of windows
//   ANSI escape color codes :
//
// Name            FG  BG
// Black           30  40
// Red             31  41
// Green           32  42
// Yellow          33  43
// Blue            34  44
// Magenta         35  45
// Cyan            36  46
// White           37  47
// Bright Black    90  100
// Bright Red      91  101
// Bright Green    92  102
// Bright Yellow   93  103
// Bright Blue     94  104
// Bright Magenta  95  105
// Bright Cyan     96  106
// Bright White    97  107

        for(int xi =0;xi<area.size()-1;xi++){
        for( int yi=0;yi<area[0].size()-1;yi++){
            if (area[xi][yi] == 1) {
                cout << " ";
            }
            else if (area[xi][yi] == 2) {//monster
                cout << "\x1B[91mM\x1B[37m";
            }
            else if (area[xi][yi] == 3) {//treasure
                cout << "\x1B[33mT\x1B[37m";
            }
            else if (area[xi][yi] == 4) {//trap ( currently unused )
                cout << "\x1B[34m&\x1B[37m";
            }
            else if (area[xi][yi] == 6) {//character
                cout << "\x1B[36mO\x1B[37m";
            }
            else if (area[xi][yi] == 5) {// Exit !!
                cout << "\x1B[32mE\x1B[37m";
            }
            else {// wall LOL ( this is zero )
                cout << char(178);
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
