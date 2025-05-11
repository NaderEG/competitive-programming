class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<int> indices(position.size());
        for(int i = 0; i < indices.size(); i++) {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(), [&position](int i1, int i2) {
            return position[i1] > position[i2];
        });
        vector<int> stack;
        for (int index : indices) {
            if(stack.size() > 0) {
                int first_car = stack.back();
                int second_car = index;

                if(((double)(target-position[first_car]))/speed[first_car] < (double)((target-position[second_car]))/speed[second_car]) {
                    stack.push_back(index);
                }
            }
            else {
                stack.push_back(index);
            }
        } 
        return stack.size();
    }
};
