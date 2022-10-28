class Solution {
    public int searchInsert(int[] a, int target) 
    {
        int ans = -1;
        int beg = 0, end = a.length-1;
        while(beg<=end)
        {
            int mid = (beg+end)/2;
            if(a[mid]==target)
                return mid;
            else if(a[mid] < target)
            {
                ans = mid;
                beg = mid+1;
            }
            else
                end = mid-1;
        }
        return ans+1;
    }
}
