class Vector2D {
public:
    vector<vector<int>> data;
    vector<vector<int>>::iterator it_row;
    vector<int>::iterator it_col;
    Vector2D(vector<vector<int>>& vec2d) {
        data = vec2d;
        it_row = data.begin();
        while (it_row != data.end() && 
                (*it_row).begin() == (*it_row).end()) {
            ++it_row;        
        }
        if (it_row != data.end()) it_col = (*it_row).begin();
    }

    int next() {
        int ret = -1;
        if (!hasNext()) return ret;
        ret = *it_col++;
        while (it_col == (*it_row).end()) {
            if (++it_row == data.end()) break;
            it_col = (*it_row).begin();
        }
        return ret;
    }

    bool hasNext() {
        return it_row != data.end();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
