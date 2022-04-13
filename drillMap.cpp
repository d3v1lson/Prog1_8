#include "../std_lib_facilities.h"



//function to read
void READ(map<string,int>& MyMap){
    string s;
    int i;
    cin >> s >> i;
    MyMap.insert(pair<string,int>(s,i));
}

template <typename key,typename value>
ostream& operator<<(ostream& output, const map<key,value>& MyMap){
    for (const auto& p : MyMap)
        cout << p.first << ": " << p.second << '\n';

    return output;
}
template <typename key,typename value>
void swapper(map<key,value>& MyMap, map<value,key>& MyMap2){
    for(auto p:MyMap){
        MyMap2[p.second] = p.first;
    }
}

int main(){
    //inserting part
    map<string,int> msi = {
        {"egy",1},
        {"ketto",2},
        {"harom",3},
        {"negy",4},
        {"ot",5},
        {"hat",6},
        {"het",7},
        {"nyolc",8},
        {"kilenc",9},
        {"tiz",10}
    };
   
        
    cout << msi;
    cout << endl;
    /* így is végig lehet rajta menni
    for (const auto& p : msi)
        cout << p.first << ": " << p.second << '\n';
    */

    //erasing part
    //-> "az osztály tagjainak pointeren keresztüli elérése"
    map<string,int>::iterator it;

    it=msi.find("nyolc");
    for(it=msi.begin(); it!=msi.end();++it){
        cout << it->first << " => " << it->second << endl;
    }

    /*
    for(int i=0;i<10;++i)
    {
        READ(msi);
    }
    */
    cout << endl;
    cout << msi;

    cout << endl;
    int sum;
    for(const auto& p : msi){
        sum+=p.second;
    }
    cout << sum << endl;

    //9.next
    map<int,string> mis;
    swapper(msi,mis);
    cout << mis;

}