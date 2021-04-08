#include<iostream>
using namespace std;
int main ()
    {
    int iTestCase=1;
    int iVisitNumber;
    int iStart;
    int iPair[2];
    bool bVisit[101][101];
    int iStack[100][2];
    int iCounter;
    int iMaxLen;
    int iFinish;
    int i,j;
    
    
    while (cin >> iVisitNumber)
        {
        if (iVisitNumber==0)
            break;
            
        for (i=0;i<101;i++)
            {
            for (j=0;j<101;j++)
                bVisit[i][j]=false;
			}
            
        iMaxLen=0;    
        iFinish=0;
            
        cin >> iStart;
        
        while (cin >> iPair[0] >> iPair[1])
            {
            if (iPair[0]==0)
                break;
                
            bVisit[iPair[0]][iPair[1]]=true;
			}
			
		
		iStack[0][0]=iStart;
		iStack[0][1]=0;
		iCounter=1;
		
		while (iCounter>0)
		    {
		    iCounter--;
		    iStack[iCounter][1]++;
		    
		    while (iStack[iCounter][1]<=iVisitNumber)
		        {
		        int iNow=iStack[iCounter][0];
		        int iNext=iStack[iCounter][1];
		        
		        if (bVisit[iNow][iNext])
		            {
		            iCounter++;
		            iStack[iCounter][0]=iStack[iCounter-1][1];
		            iStack[iCounter][1]=1;
					}
				else
				    iStack[iCounter][1]++;
				}
				
			if (iMaxLen<iCounter)
			    {
			    iMaxLen=iCounter;
			    iFinish=iStack[iCounter][0];
				}
			else if (iMaxLen==iCounter && iFinish>iStack[iCounter][0])
			    iFinish=iStack[iCounter][0];
			}
			
		
		cout << "Case " << iTestCase << ": The longest path from " << iStart << " has length "
		     << iMaxLen << ", finishing at " << iFinish << "." << endl;
		     
		iTestCase++;
		}
	}
