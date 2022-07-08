#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string asf)
{
    if (str.size() == 0)
    {
        cout<<asf<<endl;

        return;
    }
    
    for (int call = 1; call <= 2 && call <= str.size(); call++)
    {
        int number = stoi(str.substr(0, call));

        if (number >= 1 && number <= 26)
        {
            string print;

            print.push_back(number+96);

            string ros = str.substr(call);

            if (ros[0] != '0')
            {
                printEncoding(ros, asf + print);
            }
        }
    }
    
}

int main()
{
    string str;

    cin>>str;

    printEncoding(str,"");

    return 0;   

}