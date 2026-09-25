class Solution {
public:
    set<string> s;

    void dfs(string exp) {
        int j = exp.find('}');

        if (j == string::npos) {
            s.insert(exp);
            return;
        }

        int i = exp.rfind('{', j);

        string left = exp.substr(0, i);
        string right = exp.substr(j + 1);

        string inside = exp.substr(i + 1, j - i - 1);

        int start = 0;

        for (int k = 0; k <= inside.size(); k++) {
            if (k == inside.size() || inside[k] == ',') {
                string part = inside.substr(start, k - start);

                dfs(left + part + right);

                start = k + 1;
            }
        }
    }

    vector<string> braceExpansionII(string expression) {
        dfs(expression);

        return vector<string>(s.begin(), s.end());
    }
};