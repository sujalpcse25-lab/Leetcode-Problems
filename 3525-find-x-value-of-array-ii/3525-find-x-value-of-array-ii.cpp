class Solution {
    struct Node {
        int product;
        int count[5];

        Node() {
            product = 1;
            for (int i = 0; i < 5; i++)
                count[i] = 0;
        }
    };

    vector<Node> tree;
    int K;

    Node combine(Node left, Node right) {
        Node res;

        res.product = (left.product * right.product) % K;

        for (int i = 0; i < K; i++)
            res.count[i] = left.count[i];

        for (int i = 0; i < K; i++) {
            int rem = (left.product * i) % K;
            res.count[rem] += right.count[i];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            int rem = nums[l] % K;
            tree[node].product = rem;
            tree[node].count[rem] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, int value) {
        if (l == r) {
            int rem = value % K;

            tree[node].product = rem;

            for (int i = 0; i < K; i++)
                tree[node].count[i] = 0;

            tree[node].count[rem] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, value);
        else
            update(node * 2 + 1, mid + 1, r, pos, value);

        tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(node * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(node * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return combine(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {

        K = k;

        int n = nums.size();
        tree.resize(4 * n + 5);

        build(nums, 1, 0, n - 1);

        vector<int> answer;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start, n - 1);

            answer.push_back(res.count[x]);
        }

        return answer;
    }
};