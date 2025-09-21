class Solution {
public:
    int findKthNumber(int m, int n, int k) {
   
//     int d;
//  vector<vector<int>> mul(n,vector<int>(m));
 
//         for(int i=0;i<n;i++){
//      for( int j=0;j<m;j++){
         
//          mul[i][j]=(i+1)*(j+1);
//      }
//         }
//    vector<int> res;
//    for(int i=0;i<n;i++){
//      for( int j=0;j<m;j++){
//    res.push_back(mul[i][j]);
// }
// }
// int s=res.size();

// sort(res.begin(),res.end());
// for(int i=0;i<s;i++){
//     if(k-1==i)
//  d=res[i];
// }


//     return d;

//     }
int low = 1, high = m * n;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(mid / i, n);
        }    
        if (count < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }   
    return low;
}
};