class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (!rowIndex) return vector<int> {1};
        vector<int> a={1};
        vector<int> v={1};
        bool b=0;
        for (int i=1;i<rowIndex;i++) {
            for (int j=1;j<a.size();j++) {
                v[j]=a[j]+a[j-1];
            }
            if (!b) {
                v.push_back(a[a.size()-1]*2);
                b=1;
            } else b=0;
            a=v;
        }
        if (!b) {
            for (int i=v.size()-1;i>=0;i--) v.push_back(v[i]);
        } else {
            for (int i=v.size()-2;i>=0;i--) v.push_back(v[i]);
        }
        return v;
    }
};