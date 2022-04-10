//
// q - https://practice.geeksforgeeks.org/problems/marks-of-pcm2529/1
//


class Marks{
    public:
    int phy;
    int chem;
    int math;
    
    Marks() {
        phy = 0;
        chem = 0;
        math = 0;
    }
    Marks(int x, int y, int z) {
        phy = x;
        chem = y;
        math = z;
    }
};

class Compare {
    public:
    bool operator() (Marks& a, Marks& b) { 
        if(a.phy != b.phy) {
            return a.phy < b.phy;
        }
        else if(a.chem != b.chem) {
            return a.chem > b.chem;
        }
        else {
            return a.math < b.math;
        }
    }
};

class Solution{
    public:
    void customSort (int phy[], int chem[], int math[], int N)
    {
        vector<Marks> a(N);
        for(int i = 0; i < N; i++) {
            Marks m(phy[i], chem[i], math[i]);
            a[i] = m;
        }
        
        sort(a.begin(), a.end(), Compare());
        
        for(int i = 0; i < N; i++) {
            phy[i] = a[i].phy;
            chem[i] = a[i].chem;
            math[i] = a[i].math;
        }
    } 
};


// ==== using lambda function ====

class Solution{
    public:
    void customSort (int phy[], int chem[], int math[], int N)
    {
        auto comp = [](vector<int>& a, vector<int>& b) {
            if(a[0] != b[0]) {
                return a[0] < b[0];
            }
            else if(a[1] != b[1]) {
                return a[1] > b[1];
            }
            else {
                return a[2] < b[2];
            }
        };
        
        vector<vector<int>> arr(N, vector<int> (3));
        for(int i = 0; i < N; i++) {
            arr[i][0] = phy[i];
            arr[i][1] = chem[i];
            arr[i][2] = math[i];
        }
        
        sort(arr.begin(), arr.end(), comp);
        
        for(int i = 0; i < N; i++) {
            phy[i] = arr[i][0];
            chem[i] = arr[i][1];
            math[i] = arr[i][2];
        }
    } 
};
