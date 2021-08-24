#include<iostream>
#include<string>
#include<vector>

using namespace std;

string keymap[10] = {".;", "abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

vector<string> getKPC(string number)
{
    if (number.size()==0)
    {
        vector<string> base;

        base.push_back("");

        return base;
    }
    
   int firstDigit = number[0]-'0';
   
   vector<string> restOfString = getKPC(number.substr(1));
   
   string codeToAdd = keymap[firstDigit];

   vector <string> ans;
   
   for (int idx = 0; idx < codeToAdd.size(); idx++)
   {
       for (int curr = 0; curr < restOfString.size(); curr++)
       {
            ans.push_back(codeToAdd[idx] + restOfString[curr]);   
       }
   }

   return ans;
   
}

int main()
{
    string number;

    cin>>number;

    vector<string> ans = getKPC(number);

    int count = 0;

    cout << '[';

    for (string str : ans)
    {
        if (count != ans.size() - 1)
        {
            cout << str << ", ";
        }

        else
        {
            cout << str;
        }

        count++;
    }

    cout << ']';
    
    return 0;

}