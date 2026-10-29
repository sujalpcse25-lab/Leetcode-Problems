
class Solution {
    vector<vector<int>> g;
    vector<int> parent, depth, sz, heavy, head, pos, val, seg;
    int timer;

    void buildTree(int n) {
        vector<int> order, st = {0};
        parent[0] = -1;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
            order.push_back(u);

            for (int v : g[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back(v);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            sz[u] = 1;
            heavy[u] = -1;

            for (int v : g[u]) {
                if (v == parent[u]) continue;
                sz[u] += sz[v];

                if (heavy[u] == -1 || sz[v] > sz[heavy[u]]) {
                    heavy[u] = v;
                }
            }
        }

        timer = 0;
        vector<pair<int, int>> chains = {{0, 0}};

        while (!chains.empty()) {
            auto [u, h] = chains.back();
            chains.pop_back();

            while (u != -1) {
                head[u] = h;
                pos[u] = timer++;

                for (int v : g[u]) {
                    if (v != parent[u] && v != heavy[u]) {
                        chains.push_back({v, v});
                    }
                }

                u = heavy[u];
            }
        }
    }

    void build(int node, int l, int r, vector<int>& a) {
        if (l == r) {
            seg[node] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);
        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    void update(int node, int l, int r, int p, int x) {
        if (l == r) {
            seg[node] = x;
            return;
        }

        int mid = (l + r) / 2;

        if (p <= mid)
            update(node * 2, l, mid, p, x);
        else
            update(node * 2 + 1, mid + 1, r, p, x);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return seg[node];

        int mid = (l + r) / 2;
        int res = 0;

        if (ql <= mid)
            res ^= query(node * 2, l, mid, ql, qr);

        if (qr > mid)
            res ^= query(node * 2 + 1, mid + 1, r, ql, qr);

        return res;
    }

    int pathQuery(int u, int v, int n) {
        int mask = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            mask ^= query(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v]) swap(u, v);

        mask ^= query(1, 0, n - 1, pos[u], pos[v]);
        return mask;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        g.assign(n, {});

        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        sz.assign(n, 0);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        val.resize(n);

        buildTree(n);

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            val[i] = 1 << (s[i] - 'a');
            a[pos[i]] = val[i];
        }

        seg.assign(4 * n, 0);
        build(1, 0, n - 1, a);

        vector<bool> ans;

        for (string& q : queries) {
            string op;
            int u;
            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                string c;
                ss >> c;
                val[u] = 1 << (c[0] - 'a');
                update(1, 0, n - 1, pos[u], val[u]);
            } else {
                int v;
                ss >> v;

                int mask = pathQuery(u, v, n);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
