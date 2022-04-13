#include "../std_lib_facilities.h"

struct Item{
    string name;
    int iid;
    double value;
    //Item(){};
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
ostream& operator<<(ostream& output,const vector<Item>& MyVector){
    for(int i = 0;i<MyVector.size();++i){
        output << MyVector[i].name << " " << MyVector[i].iid << " " << MyVector[i].value << endl;
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
struct Cmp_by_valu
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
    vector<Item> vi;
    Item item;
    ifstream data_file("data.txt");
    while (data_file >> item)
    {
        vi.push_back(item);
    }
    vi.insert(vi.end(),Item("Horse schoe",99,12.34));
    vi.insert(vi.end(),Item("Cannon S400",9988,499.95));
    
    vector<Item>:: iterator it;
    it=find_if(vi.begin(),vi.end(),NAMEFINDER("Korte"));
    vi.erase(it);
    it=find_if(vi.begin(),vi.end(),NAMEFINDER("Málna"));
    vi.erase(it);

    it=find_if(vi.begin(),vi.end(),IIDFINDER(5));
    vi.erase(it);
    it=find_if(vi.begin(),vi.end(),IIDFINDER(6));
    vi.erase(it);

    

    cout << vi;
    sort(vi.begin(),vi.end(),Cmp_by_name());
    cout << endl;
    cout << vi;
    sort(vi.begin(),vi.end(),Cmp_by_iid());
    cout << endl;
    cout << vi;
    sort(vi.begin(),vi.end(),Cmp_by_valu());
    cout << endl;
    cout << vi;
    cout << vi.size();
}
