class Solution {
public:
   vector<int> nextGreaterElements(vector<int>& v) {
	   int n = v.size();
	   vector<int> res(n, -1);
	   stack<int> pos;
           for (int i = 0; i < 2 * n; ++i) {
		while (!pos.empty() && v[i%n] > v[pos.top()]){
		   res[pos.top()] = v[i % n];
		   pos.pop();
            	}
		if (i < n)
		   pos.push(i);
		}
	   return res;
   }
};
