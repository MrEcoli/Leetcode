class Solution {
public:
	string addBinary(string a, string b) {
		if (a.size() < b.size()){
			return addBinary(b, a);
		}
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());


		int n = b.size(), m = a.size();

		int over_flow = 0;

		for (int i = 0; i != m; ++i){
			int ta = a[i]-'0', tb = i < n ? b[i] - '0': 0;
			a[i] = (ta + tb + over_flow) % 2 + '0';
			over_flow = (ta + tb + over_flow) / 2;
		}

		if (over_flow){
			a.push_back(over_flow + '0');
		}
		reverse(a.begin(), a.end());
		
		return a;

	}
};