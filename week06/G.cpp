#include <iostream>

using namespace std;

struct Atom{
    string name;
    int A;
    int Z;
};

Atom alpha(Atom X){
    Atom N;
    N.A = X.A - 4;
    N.Z = X.Z - 2;
    return N;
}

Atom beta_plus(Atom X){
    Atom N;
    N.A = X.A;
    N.Z = X.Z - 1;
    return N;
}

Atom beta_minus(Atom X){
    Atom N;
    N.A = X.A;
    N.Z = X.Z + 1;  
    return N;
}

Atom get_reagent_by_name(string name, Atom atoms[]){
    int i = 0;
    while (true){
        if (atoms[i].name == name){
            return atoms[i];
        }
        i++;
    }
}

string is_in_elements(Atom X, unsigned N, Atom atoms[]){
    for (int i = 0; i < N; i++){
        if ((atoms[i].Z == X.Z)&(atoms[i].A == X.A)){
            return atoms[i].name;
        }
    }
    return "NO DATA";
}

void reaction(string reac, string reag, unsigned N, Atom atoms[]){
    if (reac == "alpha"){
        cout << is_in_elements(alpha(get_reagent_by_name(reag, atoms)), N,  atoms) << endl;
    } else if (reac == "beta+"){
        cout << is_in_elements(beta_plus(get_reagent_by_name(reag, atoms)), N, atoms) << endl;
    } else if (reac == "beta-"){
        cout << is_in_elements(beta_minus(get_reagent_by_name(reag, atoms)), N, atoms) << endl;
    }
}

int main(){
    unsigned N;
    unsigned M;
    cin >> N;
    Atom elements[N];
    for (int i = 0; i < N; i++){
        Atom P;
        cin >> P.name >> P.A >> P.Z;
        elements[i] = P;
    }
    cin >> M;
    string reactions[M][2];
    for (int i = 0; i < M; i++){
        cin >> reactions[i][0] >> reactions[i][1];
    }
    for (int i = 0; i < M; i++){
        reaction(reactions[i][1], reactions[i][0], N, elements);
    }
    return 0;
}