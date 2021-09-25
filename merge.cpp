#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

// This is a custom comparator for std::set which first considers the length of the string.
// If there's tie comparator will give priority to everse alphabetical  ordering
auto comparator = [&](const string& a, const string& b) {
    if (a.length() == b.length())
    {
        // For equal lengths check revese alphabatical order
        for (size_t i = 0; i < a.length(); ++i)
        {
            if (a[i] == b[i])
                continue;
            return a[i] > b[i];
        }
        return false; // for equel key
    }
    else 
        return a.length() > b.length(); // Typical case: prioritize the lengthier string

};

vector<string> merge(const vector<string>& originalList, const vector<string>& addList, const vector<string>& deleteList)
{   
    //Used custom comparator for the std::set to handle the sorting
    set<string, decltype(comparator)> temp(comparator);
    for (auto& e : originalList)
        temp.emplace(e);

    //Adding
    for (auto& e : addList)
        temp.emplace(e);

    //Delete 
    for (auto& e : deleteList)
        temp.erase(e);

    vector<string> resultList; //Because output should be a list
    resultList.reserve(temp.size());

    for (auto& e : temp)
        resultList.push_back(e);

    return resultList;
};


int main()
{
    /* Original List = ["one", "two", "three", ]
    Add List = ["one", "two", "five", "six"]
    Delete List = ["two", "five"]
    Result List = ['three', 'six', 'one']*/

    vector<string> original = { "one", "two", "three" };
    vector<string> add = { "one", "two", "five", "six" };
    vector<string> delete_ = { "two", "five" };

    vector<string> merged = merge(original, add, delete_);

    for (auto& e : merged)
        cout << e << endl;
    return 0;
}
