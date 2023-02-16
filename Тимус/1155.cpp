//
// Created by Asus on 16.02.2023
//
#include <iostream>

using namespace std;


int main() {

    int A, B, C, D, E, F, G, H;
    cin >> A >> B >> C >> D >> E >> F >> G >> H;
    int overall_summ = A + B + C + D + E + F + G + H;


    if (overall_summ % 2 != 0 || A + C + F + H != B + D + E + G) {
        cout << "IMPOSSIBLE";
    } else {
        while (A != 0 && B != 0) {
            cout << "AB-\n";
            A--;
            B--;
        }
        while (A != 0 && D != 0) {
            cout << "AD-\n";
            A--;
            D--;
        }
        while (A != 0 && E != 0) {
            cout << "AE-\n";
            A--;
            E--;
        }
        while (A != 0 && G != 0) {
            cout << "BF+\nAB-\nFG-\n";
            A--;
            G--;
        }
        while (B != 0 && C != 0) {
            cout << "BC-\n";
            B--;
            C--;
        }
        while (B != 0 && F != 0) {
            cout << "BF-\n";
            B--;
            F--;
        }
        while (B != 0 && H != 0) {
            cout << "AE+\nBA-\nEH-\n";
            B--;
            H--;
        }
        while (C != 0 && D != 0) {
            cout << "CD-\n";
            C--;
            D--;
        }
        while (C != 0 && G != 0) {
            cout << "CG-\n";
            C--;
            G--;
        }
        while (C != 0 && E != 0) {
            cout << "BF+\nCB-\nEF-\n";
            C--;
            E--;
        }
        while (D != 0 && H != 0) {
            cout << "DH-\n";
            D--;
            H--;
        }
        while (E != 0 && F != 0) {
            cout << "EF-\n";
            E--;
            F--;
        }
        while (E != 0 && H != 0) {
            cout << "EH-\n";
            E--;
            H--;
        }
        while (G != 0 && F != 0) {
            cout << "GF-\n";
            G--;
            F--;
        }
        while (G != 0 && H != 0) {
            cout << "GH-\n";
            G--;
            H--;
        }
        while (F != 0 && D != 0) {
            cout << "CG+\nCD-\nGF-\n";
            F--;
            D--;
        }
        return 0;
    }

}


