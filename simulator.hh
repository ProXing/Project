//
//  simulator.hh
//  ShipSimulator
//
//  Created by Yaoshuai Zhang on 11/16/15.
//  Copyright © 2015 Xcode. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <Ship.hh>
#include <cstdlib>
using namespace std;

class Simulator {
private:
    vector<Ship*> ships;
    static int rnd(int n) { return abs(rand() % n); }
public:
    Simulator(int n) {
        string types[] = {
            "Cruiser", "Yacht", "CargoShip", "Submarine"
        };
        for (int i = 0; i < n; i++) {
            int r = rnd(3);
            Ship* s;
            switch(r) {
                case 0:
                    s = new Cruiser;
                    break;
                case 1:
                    s = new Yacht;
                    break;
                case 2:
                    s = new CargoShip
                    break;
                default:
                    cout << "Simulation error!\n";
                    exit(-1);
            }
          ships.push_back(v);
        }
    }	
    
    void simulate() {
        for (int i = 0; i < shipis.size(); i++)
            cout << ships[i]->location() << '\n';
        
    }
};