class Entry{
    public:
    int id{};
    int startTime{};
    int subcallTime{};
    
    Entry(int id, int time):id(id),startTime(time),subcallTime(0){};
};

class Solution {
public:
    vector<int>parse(string&str){
        int sz = str.size();
        vector<int>result(sz);
        for(int i = 0; i < sz; i++){
            if(str[i]==':')
                str[i] = ' ';
        }
        int id;
        string type;
        int time;
            
        istringstream iss(str);
               
        iss>>id >> type >> time;
        
        return{id,type=="start",time};
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>result(n);
        stack<Entry>log_stack;
        log_stack.push({0,0});
        for(int i = 0; i < logs.size(); i++){
            vector<int>v = parse(logs[i]);
            int id = v[0];
            bool type = v[1];
            int time = v[2];
            
            if(type)
                log_stack.push({id,time});
            else{
                Entry e = log_stack.top();
                log_stack.pop();
                int id = e.id;
                int sTime = e.startTime;
                int total = time-sTime+1;
                int exclusive = total-e.subcallTime;
                
                Entry e_parent = log_stack.top();
                log_stack.pop();
                e_parent.subcallTime+=total;
                log_stack.push(e_parent);
                
                result[id]+=exclusive;
            }
        }
        return result;
    }
};

/*
SOLUTION and EXPLANATION:
1) Firstly, it's pretty clear that a STACK is needed 
in the solution.   We need to define what an ENTRY would be!
The stack entry would be defined using an ID, a start time, 
and a subcall time.  Build the class for this, and don't 
forget about the initializers!

2) We have a bunch of 'log' entries.  We need a way of 
parsing them.  To do so, we can use a parsing function!
a) Removes/replaces the colon.   We change the colon to a ' '
b) Uses an istringstream, where istringstream iss(str)
c) We split the string into THREE things:  
an id, a boolean variable we'll call type, and time
d) The boolean variable simply asks:
is ("start"==type)?  We return {id,type=="start",time}

3) Next up, we immediate define our result within the 
exclusiveTime function!
vector<int>result(n);
stack<Entry>log_stack;
To allow easier coding:   log_stack.push({0,0})  
(id, startTime), remember?

4) We then iterate through the log of calls
First of all, we need to parse out the calls.
vector<int>v = parse(logs[i]);
int id = v[0];
bool type = v[1];
int time = v[2];

5) if(type) --->  If we have a start, then we know 
that we need to PUSH the entry into the stack.  SO:
if(type)
log_stack.push({id,time});

6) The else-condition is where it all happens!
a) We grab the entry from the top of the stack, and 
extract the ID and START TIME for that entry
b) We need to calculate a TOTAL (which is time-START TIME+1) 
and a variable EXCLUSIVE (which is TOTAL-e.subcallTime)
bii) In summary, we pop the top of the stack, and get an 
ID and time.  We then calculate a TOTAL and EXCLUSIVE
c) We then need to update subsequent stack entries.  We 
start by popping the top of the stack, calling this entry e_parent
d) We use TOTAL to update e_parent's subcall time entry:
e_parent.subcallTime+=total;
e) We push e_parent back into the stack!
log_stack.push(e_parent)
f) EXCLUSIVE is for our eventual result vector!!!!
result[id]+=exclusive;
7) Return the result!
*/
