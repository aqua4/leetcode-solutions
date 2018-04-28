class Solution {
public:
   int compareVersion(string version1, string version2)
{
    int iLength1 = version1.size(), iLength2 = version2.size();
    string sVersion1, sVersion2;
    int iStart1 = 0, iStart2 = 0, iPoint1 = 0, iPoint2 = 0, iVersion1, iVersion2;
    while(iStart1 < iLength1 || iStart2 < iLength2)
    {
        if(iStart1 >= iLength1)
            iVersion1 = 0;
        else
        {
            iPoint1 = version1.find_first_of('.', iStart1);
            if(-1 == iPoint1)
                iPoint1 = iLength1;
            sVersion1.assign(version1, iStart1, iPoint1 - iStart1);
            iVersion1 = stoi(sVersion1);
        }
        if(iStart2 >= iLength2)
            iVersion2 = 0;
        else
        {
            iPoint2 = version2.find_first_of('.', iStart2);
            if(-1 == iPoint2)
                iPoint2 = iLength2;
            sVersion2.assign(version2, iStart2, iPoint2 - iStart2);
            iVersion2 = stoi(sVersion2);
        }
        if(iVersion1 > iVersion2)
            return 1;
        else if(iVersion1 < iVersion2)
            return -1;
        else
        {
            iStart1 = iPoint1 + 1;
            iStart2 = iPoint2 + 1;
        }
    }
    return 0;
    }
};