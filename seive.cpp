#include <iostream>
using namespace std;
bool seive[10001]={false};
int main() {
	
	// your code here
	
	
	for(int i=2;i<10001;i++)
	{
		if(seive[i]==false)
		{
			for(int j=i*i;j<10001;j=j+i)
			{
				seive[j]=true;
			}
		}
	}
	
		for(int i=2;i<10001;i++){
			if(seive[i]==false)
			cout<<i;
		}

	return 0;
}
