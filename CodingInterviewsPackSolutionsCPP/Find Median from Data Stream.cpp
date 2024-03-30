class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num<=maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);
        
        while(maxHeap.size()<minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        while(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()>minHeap.size())
            return maxHeap.top();
        return (maxHeap.top()+minHeap.top())/2.0;
    }
};

/*
OUR SOLUTION:
We want to find the median from all current numbers.  TIP: When you see middle/median, consider 2-3 DS (lower, upper, and maybe the middle too)
In this solution, our logic is simple:
1)  We'll keep TWO heaps
A)  A maxHeap for the LOWER values
B)  A minHeap for the HIGHER values
We want to make sure the size of each each heap either:
i)  Stay EQUAL (i.e. left/lower maxHeap's size == right/higher right heap's size)
ii) Stay such that the LEFT/lower MAX-HEAP is bigger by one.
Why?
Well, if the two heaps are equal in size, we find the MEDIAN by taking the tops of each, and dividing by 2.0
e.g.  [10 20 30] [50 60 70] ---> 30 + 50 are tops...and 40.0 is the median :)
If the two heaps are not equal, it means we have engineered it so that LEFT HEAP = RIGHT HEAP +1.  The median is the top of the left heap, like so:
e.g. [10 20 30 40] [50 60 70]  ---> left = right+1 (sizes)...MEDIAN is the top of the left max_heap, which is 40

So, step by step:
1)  Keep two heaps: a maxHeap for left/lower; a minHeap for right/higher
2)  When adding, we simply compare the new value to the TOP value in  LEFT (or an empty pq)
If newValue<=left.top(), then we add to that pq safely.
Otherwise, add newValue to right :)
3)  We need to make sure that left (maxHeap) is the same size as right (minHeap) OR: left's size+1==right's size
3a) If left is less than right in size, then we need to PUSH right's top() into left
3b) If left's size is greater than right's size+1, then we need to push left's top into right!
4)   The calculation of the median is EASY!
a)  If the sizes are equal, we take the tops, and divide by 2.0
b)  If not, we grab the top of the left heap!
*/
