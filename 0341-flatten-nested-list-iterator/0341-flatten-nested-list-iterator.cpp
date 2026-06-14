class NestedIterator {
public:
    vector<int> nums;
    int idx = 0;

    void flatten(vector<NestedInteger>& nestedList) {

        for(auto &x : nestedList) {

            if(x.isInteger()) {
                nums.push_back(x.getInteger());
            }

            else {
                flatten(x.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {

        flatten(nestedList);
    }

    int next() {

        return nums[idx++];
    }

    bool hasNext() {

        return idx < nums.size();
    }
};