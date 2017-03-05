/*
 * Filename   SimplifyPath.cc
 * CreateTime 2017-03-04 20:03:22
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string simplipyPath(string const &path)
    {
        vector<string> dirs;

        for (auto i = path.begin(); i != path.end(); ) {
            ++i;

            auto j = find(i, path.end(), '/');
            auto dir = string(i, j);

            if (!dir.empty() && dir != ".") {
                if (dir == "..") {
                    if (!dir.empty()) {
                        dir.pop_back();
                    }
                } else {
                    dirs.push_back(dir);
                }
            }
            
            i = j;
        }

        stringstream out;
        if (dirs.empty()) {
            out << "/";

        } else {
            for (auto dir : dirs) {
                out << '/' << dir;
            }
        }

        return out.str();
    }
};

