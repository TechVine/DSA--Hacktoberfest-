class MyCalendarThree {
    TreeMap<Integer,Integer>mp = new TreeMap<>();
     int maxCount = 0;
     public MyCalendarThree() {
         
     }
     
     public int book(int start, int end) {
      int count = 0;
      mp.put(start,mp.getOrDefault(start,0)+1);
      mp.put(end,mp.getOrDefault(end,0)-1);
     for(Map.Entry<Integer,Integer>e :mp.entrySet())
         { 
          int x = e.getValue();
          count = count + x;
         maxCount = Math.max(maxCount,count);
      }
     return maxCount;
     }
 }
 