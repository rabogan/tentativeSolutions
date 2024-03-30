class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
/*1a*/  sort(events.begin(),events.end());
        
/*1b*/  priority_queue<int,vector<int>,greater<int>>minHeap;
        int attended = 0;
        int event = 0;
        int sz = events.size();
        
/*2*/   for(int day = 1; event < sz || !minHeap.empty(); day++){
/*3*/       while(!minHeap.empty() && minHeap.top() < day)
                minHeap.pop();
    
/*4*/       if(event < sz && minHeap.empty())
                day = max(day,events[event][0]);
                
/*5*/       while(event < sz && events[event][0]<=day)
                minHeap.push(events[event++][1]);
    
/*6*/       if(!minHeap.empty()){
                attended++;
                minHeap.pop();
            }
        }
        return attended;
    }
};
/*
1a) Sorting the events from day-start order is important!
1b) Get the number attended, the event itself, 
and the size of events.  Our minHeap will be used to use
to store the 'end day' of our events 

2) We're iterating by day!  Event must be less than size; 
minHeap must have something in it!
The heap will maintain only when the events will end, and 
all elements in the heap are active (i.e. started some time ago)
We will get rid of events that end sooner compared to others

3) Remove all events that are already finished!
Just look for minHeap elements LESS THAN the current day,
and pop them. With each 'day', we remove all the old events

4) Optimisation!  If our event is < size, and our minHeap
has elements...then change day to the max of day and 
events[event][0].  We are simply JUMPING TO THE NEXT DAY 
(if our heap is empty and event < sz) INSTEAD OF simply 
iterating through a bunch of useless unused days!

5) We're iterating from the last added event
While event < sz AND the current events's start day is <= day...
...push events[event++][1] into the minHeap!
Each event is ONLY added to the heap once!

6) Make sure you get the event ending first!
*/
