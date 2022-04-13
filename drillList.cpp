#include "../std_lib_facilities.h"

struct Item{
    string name;
    int iid;
    double value;
    Item():name(),iid(0),value(0){}
    Item(string n, int id, double val) {
        name = n;
        iid = id;
        value = val;
    }
};
istream& operator>>(istream& input,Item& address){
    input >> address.name;
    input >> address.iid;
    input >> address.value;
    return input;
}
ostream& operator<<(ostream& output, const list<Item>& MyList){
    for(auto it = MyList.begin(); it != MyList.end(); ++it )
    {
        output << (*it).name << " " << (*it).iid << " " << (*it).value << endl;
        //*it egy memória cím és az (*it) felfedi a memóriacímen lévő értéket
    }
    return output;
}

struct Cmp_by_name
{
    bool operator()(const Item& a, const Item& b) const{
        return a.name < b.name;
    }
};

struct Cmp_by_iid{
    bool operator()(const Item& a, const Item& b) const{
        return a.iid < b.iid;
    }
};
struct Cmp_by_value
{
    bool operator()(const Item& a, const Item& b) const {
        return a.value > b.value;
    }
};

struct NAMEFINDER
{
    string name;
    public:
        NAMEFINDER(const string& s):name(s){}
        bool operator()(const Item& a)
        {
            return a.name == name;
        }
};
struct IIDFINDER
{
    int iid;
    public:
        IIDFINDER(const int& a):iid(a){}
        bool operator()(const Item& a)
        {
            return a.iid == iid;
        }
};


int main(){
    list<Item> li;
    Item item;
    ifstream data_file("data.txt");
    while (data_file >> item)
    {
        li.push_back(item);
    }
    li.insert(li.end(),Item("Horse schoe",99,12.34));
    li.insert(li.end(),Item("Cannon S400",9988,499.95));

    list<Item>:: iterator it;
    it=find_if(li.begin(),li.end(),NAMEFINDER("Korte"));
    li.erase(it);
    it=find_if(li.begin(),li.end(),NAMEFINDER("Málna"));
    li.erase(it);

    it=find_if(li.begin(),li.end(),IIDFINDER(5));
    li.erase(it);
    it=find_if(li.begin(),li.end(),IIDFINDER(6));
    li.erase(it);


    cout << li;
    li.sort(Cmp_by_name());
    cout << endl;
    cout << li;
    li.sort(Cmp_by_iid());
    cout << endl;
    cout << li;
    li.sort(Cmp_by_value());
    cout << endl;
    cout << li;
    cout << li.size();



}