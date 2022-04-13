#include "../std_lib_facilities.h"

int main(){
    //beolvas
    vector<double> vd;
    ifstream data_file("data2.txt");
    double d;
    while (data_file>>d)
    {
        vd.push_back(d);
    }
    //filling vi
    vector<int> vi;
    for(const auto& p : vd){
        vi.push_back(p);
    }
    
    for(int i = 0;i<vd.size();++i){
        cout << vd[i] << " - " << vi[i] << endl;
    }
    //difference between vi and vd
    cout << endl;
    double osszeg;
    for(int i = 0;i<vd.size();++i){
        osszeg+=vd[i];
    }
    int osszeg2;
    for(int i = 0;i<vd.size();++i){
        osszeg2+=vi[i];
    }
    cout << osszeg << endl;
    cout << "Difference:  " << osszeg-osszeg2 << endl;

    //reverse vd
    reverse(vd.begin(),vd.end());
    cout << endl;
       
    for(int i = 0;i<vd.size();++i){
        cout << vd[i] << " - " << vi[i] << endl;
    }

    //computing mean(átlag) && copying to vd2
    cout << endl;
    double mean = osszeg/vd.size();
    vector<double> vd2;
    cout << "Mean value in vd: " << mean << endl;
    for(int i = 0;i<vd.size();++i){
        if(vd[i]< mean){
            vd2.push_back(vd[i]);
        }
    }

    sort(vd2.begin(),vd2.end());
    for(int i = 0;i<vd2.size();++i){
        cout << vd2[i] << endl;
    }
}
