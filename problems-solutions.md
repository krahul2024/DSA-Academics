* Count of Subarrays with sum = k 

```python
    
    # handles only positive values 
    while j < len(arr): 
        if sum < target : sum += target 
        if sum == target : ans , sum, i = ans +1, sum - arr[i], i += 1
        elif sum > target : sum, i = sum - arr[i], i+1 
        if sum < target : j += 1 
    return ans 


    # handles all the types of values 
    count, sum, ans = {}, 0, 0 
    for x in arr : 
        sum += x 
        if sum == target : ans += 1 
        ans += count.get(sum - target, 0) 
        count[sum] = count.get(sum, 0) + 1 
    return ans 

```

* Count of Subarrays divisible by k 

```python
    sum_, count = 0, {0 : 1} 
    for x in arr : 
        sum_ = int((sum_ + x) % k )
        count[sum_] = count.get(sum_, 0) + 1
    return sum([(x*(x-1)) // 2 for x in count.values()])

```

* Longest subarray with unique elements*


```c++
    // time complexity is nlogn

    void longest_sub(arr, n){
        int i=0, j=0, s=0, e=0, ans=0; 
        map<int,int>m; 

        while(j < n){
            if(!m[a[j]]) m[a[j]]++; // if the element is not encountered earlier then mark it as counted
            else if(m[a[i]]){
                while(a[i] != a[j]) m[a[i++]]--; 
                i++; 
            }
            if(ans < (j-i+1)) ans = j - i + 1, s = i, e = j; 
            j++; 
        }

        // print the length of longest subarray 
        cout<<ans<<'\n'; 
        for(int i=s; i<=e; i++)cout<<a[i]<<' '; 
    }

```

* Length of the longest subarray with sum k 

```python
    
        sum, ans, m = 0, [-1, -2], {}
        
        for i,x in enumerate(arr): 
            sum += x 
            if sum == k : ans = [1, i+1]
            if m.get(sum, 0) == 0 : m[sum] = i+1 
            if m.get(sum - k, 0) != 0 : 
                x, y = m[sum - k], i+1 
                if y - x > ans[1] - ans[0] + 1 : 
                    ans = [x+1, y]
        
        return ans # index of the subarray elements(inclusive)

```

* Largest subarray with equal no. of 0s and 1s

*The approach is similar to above problem, we just have to replace all the 0s with -1 and find the largest subarray with 0 sum.*
```py

    sum, ans, m = 0, [-1, -2], {}

    for i in range(len(arr)): 
        if arr[i] == 0 : arr[i] = -1 
        sum += arr[i] 

        if sum == 0 : ans = [1, i+1]
        if m.get(sum, 0) == 0 : m[sum] = i+1 
        if m.get(sum, 0) != 0 : 
            x, y = m[sum], i+1
            if y - x > ans[1] - ans[0] + 1 : 
                ans = [x+1, y]

    return ans 
```
* Largest product of two elements in an array 

*Approach is to get two most mins and two most maxes and then compare their products and return those(best approach), a bit naive approach is to sort and compare the product, most naive approach is to calculate product of all pairs and then compare them*

* Counting Rooms

*Approach for this problem is to start with one index and mark all the reachable indexes as unreachable and count all of this as a single room, then look for next room and continue doing this*
```cpp
    /*
        input is matrix of # and ., . meaning a floor and # meaning a wall.
    */ 

    void count_rooms(int i, int j){
        if(i < 0 or j < 0 or i >= n or j >= m or a[i][j] == '#') return; 
        a[i][j] = '#', f(i, j+1), f(i, j-1), f(i+1, j), f(i-1, j); 
    }

    // count the rooms using the function above 
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(a[i][j] == '.') ans++, f(i, j); 

```
* Labyrinth 

*This is a basic path finding problem using bfs, given source and destination, we have to find the path from source to destination(if exists) else output No, can be solved using basic bfs algorithm*
```cpp
    
    queue<pair<int,int>>q; 
    q.push(source);
    vis[source.first][source.second] = true ; 

    while(!q.empty()){
        int i = q.font().first, j = q.front().second(); 
        q.pop(); 
        if(i >=0 and j >= 0 and i < n and j < m and a[i][j] == 'B'){
            ans = 1 ; break; 
        }

        // traverse the neighbors 
        for(int x=-1; x<=1 ; x+=2){
            if(i+x >= 0 and i+x < n and !vis[i+x][j] and a[i+x][j] != '#')
                vis[i+x][j] = true, q.push({i+x, j}), parent[i+x][j] = {i, j}; 
            if(j+x >= 0 and j+x < m and !vis[i][j+x] and a[i][j+x] != '#')
                vis[i][j+x] = true , q.push({i, j+x}), parent[i][j+x] = {i, j}; 
        }
    } 

    // if we found a path from source to destination 
    if(ans){
        string path = ""; 
        pair<int, int>temp = e ; 
        while(true){
            int x = temp.first, y = temp.second; 
            temp = parent[x][y]; 
            int x1 = temp.first, y1 = temp.second, xdiff = x-x1, ydiff = y-y1; 
            if(x1 == -1) break; 
            if(xdiff != 0) path += (xdiff == 1 ? 'D' : 'U'); 
            else if(ydiff != 0) path += (ydiff == 1 ? 'R' : 'L'); 
        }
        reverse(begin(path), end(path)); 
        cout<<"YES\n"<<path.size()<<'\n'<<path<<'\n'; 
    }

    // if no path found 
    else cout<<"NO"; 

```