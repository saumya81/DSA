class Solution {
public:
    int compareVersion(string version1, string version2) {
        string s="";
        vector<int> v1;
        vector<int> v2;
        for(int i=0;i<version1.length();i++)
        {
            if(version1[i]=='.')
          {                
                v1.push_back(stoi(s));
                s="";
            }
            else{
                s=s+version1[i];
            }
        }
        v1.push_back(stoi(s));
        s="";
         for(int i=0;i<version2.length();i++)
        {
            if(version2[i]=='.')
          {                
                v2.push_back(stoi(s));
                s="";
            }
            else{
                s=s+version2[i];
            }
        }
         v2.push_back(stoi(s));
        int i=0,j=0;
//case "1.2"  "1.3" or "1.3" "1.2"
        while(i<v1.size()&&j<v2.size())
        {
            if(v1[i]>v2[i])
                return 1;
            else if(v1[i]<v2[i])
                return -1;
            i++;
            j++;
        }
 //case "1.0.1.1"  "1.0.1"      
     while(i<v1.size())
    { 
           if(v1[i]>0)
            return 1;
            i++;
       }
//case "1.0"  "1.0.1"
     while(j<v2.size())
         {
                if(v2[j]>0)
                return -1;
                j++;
         }
        
//case "1.0"  "1.0.0"
            return 0;
    }
};
