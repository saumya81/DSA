//The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. 
//The Graph is represented as adjancency matrix, and the matrix denotes the weight of the edegs (if it exists) else -1.
 

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	  int INF = INT_MAX;
		int n = matrix.size();
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][j] == -1)
					matrix[i][j] = INF;
			}
		}
		
		for (int k = 0; k < n; ++k) {
		    for (int i = 0; i < n; ++i) {
		        for (int j = 0; j < n; ++j) {
		            if (matrix[i][k] < INF && matrix[k][j] < INF and matrix[i][k] + matrix[k][j] < INF)
		                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]); 
		        }
		    }
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][j] >= INF)
					matrix[i][j] = -1;
			}
		}
	}
};
