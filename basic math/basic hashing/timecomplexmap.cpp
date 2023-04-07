//what is the time complexity of this map???
 
//both storing and fetching take log(N) time in best, average and worst cases.

//if map<int, int> was changed to undordered map, time complexity in best and avg case would be constant
//worst case would take linear time 
//if it takes O(N) then code takes N^2 as fetching/storing happens inside a for loop

//first use unordered map, if it shows time limit exceeded, then use ordered.