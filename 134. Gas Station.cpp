/*

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.



*/





class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		unsigned n = gas.size();
		int start;
		for(int i = 0; i < n; ++i){
			if(gas[i] - cost[i] < 0)
				continue;
			else{
				int sum_gas = 0;
				start = i;
				int j, count;
				for(j = i, count = 0; count < n; ++j, ++count){
					unsigned index = j%n;
					sum_gas += (gas[index] - cost[index]);
					if(sum_gas < 0){
						i = j;
						start = -1;
						break;
					}
				}
				if(count == n)
					return start;
			}
		}
		return -1;
	}
};
