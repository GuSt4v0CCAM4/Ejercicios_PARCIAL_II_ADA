#include <iostream>
#include <vector>
using namespace std;


class Moneda {
public:

    int valor;

    Moneda(int v) {
        valor = v;
    }

    int getValor() {
        return valor;
    }
};

int main() {
    int t,n,v;
    cin>>t;
    while(t--){
        cin>>n;

        vector<Moneda> monedas;
        for(int i=0;i<n;i++){
            cin >> v;
            Moneda m(v);
            monedas.push_back(m);
        }
        int curSum = 0, res=0;
        for(int i=0;i<n;i++){
            if(n-1 == i || curSum+monedas[i].getValor()<monedas[i+1].getValor()){
                curSum += monedas[i].getValor();
                res++;
            }

        }


        cout<<res<<endl;
    }
}
