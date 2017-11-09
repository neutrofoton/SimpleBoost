//
//  main.cpp
//  SimpleBoost
//
//  Created by neutro code on 11/9/17.
//  Copyright © 2017 Neutro Cpp. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

#include <boost/iostreams/tee.hpp>
#include <boost/iostreams/stream.hpp>
using namespace boost;
using namespace boost::iostreams;

int main(int argc, const char * argv[]) {
    
    typedef tee_device<ostream, ofstream> TeeDevice;
    typedef stream<TeeDevice> TeeStream;
    
    ofstream ofs("/Users/neutro/Workspace/cpp/sample.txt");
    
    TeeDevice my_tee(cout, ofs);
    TeeStream my_split(my_tee);
    
    my_split << "Hello, World!\n";
    
    my_split.flush();
    my_split.close();
    
    return 0;
}
