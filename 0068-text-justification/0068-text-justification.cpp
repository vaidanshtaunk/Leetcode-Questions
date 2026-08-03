class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans;
        int n = words.size();
        int i = 0;

        while(i < n) {

            int j = i;
            int lineLength = 0;

            // Find how many words fit in current line
            while(j < n && lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            // Last line OR only one word
            if(j == n || gaps == 0) {

                for(int k = i; k < j; k++) {
                    line += words[k];
                    if(k != j - 1)
                        line += " ";
                }

                while(line.size() < maxWidth)
                    line += " ";
            }
            else {

                int totalSpaces = maxWidth - lineLength;
                int spaceEach = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                for(int k = i; k < j; k++) {

                    line += words[k];

                    if(k != j - 1) {

                        int spaces = spaceEach;

                        if(extra > 0) {
                            spaces++;
                            extra--;
                        }

                        line += string(spaces, ' ');
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};