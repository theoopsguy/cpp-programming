#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> ourmap;

    //insert
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    ourmap["def"] = 2;

    //find or access
    cout<<ourmap.at("abc")<<endl;
    cout<<ourmap["abc"]<<endl;

    //cout<<ourmap.at("ghi")<<endl;   //will give error if not found

    cout<<"size: "<<ourmap.size()<<endl;
    cout<<ourmap["ghi"]<<endl;  //will insert with a key 0 if not found
    cout<<"size: "<<ourmap.size()<<endl;

    //check presence
    if (ourmap.count("ghi") > 0) {
        cout<<"ghi is present"<<endl;
    }

    //erase
    ourmap.erase("ghi");
    cout<<"size: "<<ourmap.size()<<endl;
    
    return 0;
}