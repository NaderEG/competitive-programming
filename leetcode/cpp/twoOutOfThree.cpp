class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> set1;
        set<int> set2;
        set<int> set3;

        for(int n : nums1) {
            set1.insert(n);
        }
        for(int m : nums2) {
            set2.insert(m);
        }
        for(int o : nums3) {
            set3.insert(o);
        }

        set<int> intersection1;

        set_intersection(
            set1.begin(), set1.end(),
            set2.begin(), set2.end(),
            inserter(intersection1, intersection1.begin())
        );
        set<int> intersection2;
        set_intersection(
            set2.begin(), set2.end(),
            set3.begin(), set3.end(),
            inserter(intersection2, intersection2.begin())
        );
        set<int> intersection3;
        set_intersection(
            set1.begin(), set1.end(),
            set3.begin(), set3.end(),
            inserter(intersection3, intersection3.begin())
        );

        set<int> temp_union;
        set<int> final_union;

        set_union(
            intersection1.begin(), intersection1.end(),
            intersection2.begin(), intersection2.end(),
            inserter(temp_union, temp_union.begin())
        );
        set_union(
            intersection3.begin(), intersection3.end(),
            temp_union.begin(), temp_union.end(),
            inserter(final_union, final_union.begin())
        );
        vector<int> res;
        for(int val : final_union) {
            res.push_back(val);
        }
        return res;

        
    }
};