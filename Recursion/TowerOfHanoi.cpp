#include<iostream>
using namespace std;

void toh(int disk, int tower1id, int tower2id, int tower3id)
{
    /*  
    from -> tower1id
    to -> tower2id
    using -> tower3id
    */

    if (disk==0)
    {
        return;
    }

    toh (disk-1, tower1id, tower3id, tower2id);

    cout<<disk<<"["<<tower1id<<" -> "<<tower2id<<"]"<<endl;

    toh (disk-1, tower3id, tower2id, tower1id);
}

int  main() 
{
    int disks, tower1, tower2, tower3;

    cin>>disks;
    cin>>tower1>>tower2>>tower3;
    
    /*  
    source -> tower1
    destination -> tower2
    auxuillary -> tower3
    */

    toh(disks, tower1, tower2, tower3);

    return 0;
}