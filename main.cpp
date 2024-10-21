#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct krawedz
{
    int w2;

    int waga;
};

    typedef vector<vector<krawedz> > tgraf;


void Czytaj(tgraf &Graf)
{
    int n, m, w1;
    krawedz kraw;
    ifstream we("graf_1.txt");
    we>>n>>m;
    Graf.resize(n);
    for (int i=0; i<m; i++)
    {
        we>>w1>>kraw.w2>>kraw.waga;
        Graf[w1].push_back(kraw);
    }
    we.close();
}

void Dijkstra(tgraf Graf, int pocz, vector<int> &Koszt)
{
    krawedz kraw;
    int i, j, k, w1;
    vector<bool> Odwiedzone;
    Odwiedzone.resize(Graf.size(),false);
    Koszt[pocz]=0;
    for (i=0;i<Graf.size()-1;i++)
    {
        k=0; while (Odwiedzone[k]) k++; w1=k;
        for (j=k+1;j<Graf.size();j++)
            if (!Odwiedzone[j] && Koszt[j]<Koszt[w1]) w1=j;
        Odwiedzone[w1]=true;
        for (j=0; j<Graf[w1].size();j++)
        {
            kraw=Graf[w1][j];
            if (!Odwiedzone[kraw.w2] &&
                Koszt[w1]+kraw.waga<Koszt[kraw.w2])
                Koszt[kraw.w2]=Koszt[w1]+kraw.waga;
        }


    }
}




int main()
{
    tgraf Graf;
    Czytaj(Graf);
    vector<int> Koszt;
    Koszt.resize(Graf.size(),1000);
    int pocz;
    cout<<"Numer wierzcholka poczatkowego: ";
    cin>>pocz;
    Dijkstra(Graf,pocz,Koszt);
    cout<<"Koszt dojscia z wierzcholka: "<<pocz;
    cout<<" do wierzcholka:"<<endl;
    for (int i=0;i<Graf.size();i++)
        if (i!=pocz) cout<<i<<": "<<Koszt[i]<<endl;
    return 0;
}
