//
// Created by 36636 on 2021/11/13.
//
#pragma once

#include <vector>
#include <iostream>
#include <sstream>
#include <stack>

#include <cstring>
#include <ctype.h>
#include <cstdio>
#include <string.h>
#include <stdio.h> /* printf */
#include <math.h>  /* log */
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <tuple> // std::tuple, std::make_tuple, std::tie
#include <algorithm>
#include <functional>
#include <array>
#include <string_view>
#include <queue>

//#ifndef CODING_DATAFRAME_H
//#define CODING_DATAFRAME_H

/**
 *
 */

class ListBase {
};

class numberOfIslands {
public:
    void test() {
        test_case1();
        test_case2();
        // test_case3();
    }

protected:
    /**
     * @brief
     *
     * @link https://leetcode.cn/problems/number-of-islands/
     *
     * @param grid
     * @return int
     */
    virtual int numIslands(std::vector<std::vector<char>> &grid) {
        return 0;
    }

    void test_case1() {
        std::vector<std::vector<char>> grid =
            {{'1', '1', '1', '1', '0'},
             {'1', '1', '0', '1', '0'},
             {'1', '1', '0', '0', '0'},
             {'0', '0', '0', '0', '0'}};

        int ans = 1;
        int res = numIslands(grid);
    }

    void test_case2() {
        std::vector<std::vector<char>> grid =
            {{'1', '1', '0', '0', '0'},
             {'1', '1', '0', '0', '0'},
             {'0', '0', '1', '0', '0'},
             {'0', '0', '0', '1', '1'}};

        int ans = 3;
        int res = numIslands(grid);
    }
};

class numberOfIslandsDepthFirstSearch : public numberOfIslands {
private:
    void dfs(std::vector<std::vector<char>> &grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
    }

public:
    /**
     * @brief
     *
     * @link https://leetcode.cn/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
     *
     * @param grid
     * @return int
     */
    int numIslands(std::vector<std::vector<char>> &grid) override {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};

class numberOfIslandsBreadthFirstSearch : public numberOfIslands {
public:
    /**
     * @brief
     *
     * @link https://leetcode.cn/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
     *
     * @param grid
     * @return int
     */
    int numIslands(std::vector<std::vector<char>> &grid) override {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    grid[r][c] = '0';
                    std::queue<std::pair<int, int>> neighbors;
                    neighbors.push({r, c});
                    while (!neighbors.empty()) {
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first, col = rc.second;
                        if (row - 1 >= 0 && grid[row - 1][col] == '1') {
                            neighbors.push({row - 1, col});
                            grid[row - 1][col] = '0';
                        }
                        if (row + 1 < nr && grid[row + 1][col] == '1') {
                            neighbors.push({row + 1, col});
                            grid[row + 1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col - 1] == '1') {
                            neighbors.push({row, col - 1});
                            grid[row][col - 1] = '0';
                        }
                        if (col + 1 < nc && grid[row][col + 1] == '1') {
                            neighbors.push({row, col + 1});
                            grid[row][col + 1] = '0';
                        }
                    }
                }
            }
        }

        return num_islands;
    }
};

class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class numberOfIslands {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        UnionFind uf(grid);
        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r-1][c] == '1') uf.unite(r * nc + c, (r-1) * nc + c);
                    if (r + 1 < nr && grid[r+1][c] == '1') uf.unite(r * nc + c, (r+1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c-1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c+1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
                }
            }
        }

        return uf.getCount();
    }
};


class bestTimeToBuyAndSellStock {
public:
    void test() {
        test_case1();
        test_case2();
        // test_case3();
    }

protected:
    /**
     * @brief
     *
     * @link https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
     *
     * @param prices
     * @return int
     */
    virtual int maxProfit(std::vector<int> &prices) {
        return 0;
    }

    void test_case1() {
        std::vector<int> prices = {7, 1, 5, 3, 6, 4};
        int ans = 5;
        int res = maxProfit(prices);
    }

    void test_case2() {
        std::vector<int> prices = {7, 6, 4, 3, 1};
        int ans = 0;
        int res = maxProfit(prices);
    }
};

class bestTimeToBuyAndSellStockViolence : public bestTimeToBuyAndSellStock {
public:
    /**
     * @brief
     *
     * @link https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solution/121-mai-mai-gu-piao-de-zui-jia-shi-ji-by-leetcode-/
     *
     * @param prices
     * @return int
     */
    int maxProfit(std::vector<int> &prices) override {
        int n = (int)prices.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = std::max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};

class bestTimeToBuyAndSellStockOneTraversal : public bestTimeToBuyAndSellStock {
public:
    /**
     * @brief
     *
     * @link https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solution/121-mai-mai-gu-piao-de-zui-jia-shi-ji-by-leetcode-/
     *
     * @param prices
     * @return int
     */
    int maxProfit(std::vector<int> &prices) override {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price : prices) {
            maxprofit = std::max(maxprofit, price - minprice);
            minprice = std::min(price, minprice);
        }
        return maxprofit;
    }
};

class binaryTreeZigzagLevelOrderTraversal;

class createBinaryTreeFromDescriptions {
public:
    void test() {
        test_case1();
        test_case2();
        // test_case3();
    }

protected:
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     * };
     */

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() :
            val(0), left(nullptr), right(nullptr) {
        }
        TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
        }
        TreeNode(int x, TreeNode *left, TreeNode *right) :
            val(x), left(left), right(right) {
        }
    };

    /**
     * @brief Create a Binary Tree object
     *
     * @link https://leetcode-cn.com/problems/create-binary-tree-from-descriptions/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
     *
     * @param descriptions
     * @return TreeNode*
     */
    virtual TreeNode *createBinaryTree(std::vector<std::vector<int>> &descriptions) {
        return nullptr;
    }

    void test_case1() {
        std::vector<std::vector<int>> descriptions = {{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
        std::vector<int> ans = {50, 20, 80, 15, 17, 19};
        TreeNode *res = createBinaryTree(descriptions);
    }

    void test_case2() {
        std::vector<std::vector<int>> descriptions = {{1, 2, 1}, {2, 3, 0}, {3, 4, 1}};
        // std::vector<int> ans = {1,2,null,null,3,4};
        TreeNode *res = createBinaryTree(descriptions);
    }

private:
    TreeNode *binary_tree_;
    friend class binaryTreeZigzagLevelOrderTraversal;
};

class createBinaryTreeFromDescriptionsHashTable : public createBinaryTreeFromDescriptions {
public:
    /**
     * @brief Create a Binary Tree object
     *
     * @link https://leetcode.cn/problems/create-binary-tree-from-descriptions/solution/gen-ju-miao-shu-chuang-jian-er-cha-shu-b-sqrk/
     *
     * @param descriptions
     * @return TreeNode*
     */
    TreeNode *createBinaryTree(std::vector<std::vector<int>> &descriptions) override {
        std::unordered_map<int, bool> isRoot;      // 数值对应的节点是否为根节点的哈希表
        std::unordered_map<int, TreeNode *> nodes; // 数值与对应节点的哈希表
        for (const auto &d : descriptions) {
            int p = d[0];
            int c = d[1];
            bool left = d[2];
            if (!isRoot.count(p)) {
                isRoot[p] = true;
            }
            isRoot[c] = false;
            // 创建或更新节点
            if (!nodes.count(p)) {
                nodes[p] = new TreeNode(p);
            }
            if (!nodes.count(c)) {
                nodes[c] = new TreeNode(c);
            }
            if (left) {
                nodes[p]->left = nodes[c];
            } else {
                nodes[p]->right = nodes[c];
            }
        }
        // 寻找根节点
        int root = -1;
        for (const auto &[val, r] : isRoot) {
            if (r) {
                root = val;
                break;
            }
        }
        return nodes[root];
    }
};

class binaryTreeZigzagLevelOrderTraversal : public createBinaryTreeFromDescriptions {
public:
    binaryTreeZigzagLevelOrderTraversal() {
        create_binary_tree_from_descriptions_hash_table_ = new createBinaryTreeFromDescriptionsHashTable();
    }

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

protected:
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     * };
     */
    // struct TreeNode {
    //     int val;
    //     TreeNode *left;
    //     TreeNode *right;
    //     TreeNode() :
    //         val(0), left(nullptr), right(nullptr) {
    //     }
    //     TreeNode(int x) :
    //         val(x), left(nullptr), right(nullptr) {
    //     }
    //     TreeNode(int x, TreeNode *left, TreeNode *right) :
    //         val(x), left(left), right(right) {
    //     }
    // };

    /**
     * @brief
     *
     * @link https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
     *
     * @param root
     * @return std::vector<std::vector<int>>
     */
    virtual std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
        return {};
    }

    void test_case1() {
        std::vector<std::vector<int>> binary_tree_descriptions = {{3, 9, 1}, {3, 20, 0}, {20, 15, 1}, {20, 7, 0}};
        // binary_tree_ = create_binary_tree_from_descriptions_hash_table_->createBinaryTree(binary_tree_descriptions);
        TreeNode *input_binary_tree = create_binary_tree_from_descriptions_hash_table_->createBinaryTree(binary_tree_descriptions);
        std::vector<std::vector<int>> ans = {{3}, {20, 9}, {15, 7}};
        std::vector<std::vector<int>> res = zigzagLevelOrder(input_binary_tree);
    }

    void test_case2() {
        // std::vector<std::vector<int>> binary_tree_descriptions = {{3, 9, 1}, {3, 20, 0}, {20, 15, 1}, {20, 7, 0}};
        TreeNode *input_binary_tree = new TreeNode(1);
        std::vector<std::vector<int>> ans = {{1}};
        std::vector<std::vector<int>> res = zigzagLevelOrder(input_binary_tree);
    }

    void test_case3() {
        // std::vector<std::vector<int>> binary_tree_descriptions = {{3, 9, 1}, {3, 20, 0}, {20, 15, 1}, {20, 7, 0}};
        TreeNode *input_binary_tree = nullptr;
        std::vector<std::vector<int>> ans = {};
        std::vector<std::vector<int>> res = zigzagLevelOrder(input_binary_tree);
    }

    createBinaryTreeFromDescriptions *create_binary_tree_from_descriptions_hash_table_;
};

class binaryTreeZigzagLevelOrderTraversalBreadthFirstTraversal : public binaryTreeZigzagLevelOrderTraversal {
public:
    /**
     * @brief
     *
     * @link https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/solution/er-cha-shu-de-ju-chi-xing-ceng-xu-bian-l-qsun/
     *
     * @param root
     * @return std::vector<std::vector<int>>
     */
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) override {
        std::vector<std::vector<int>> ans;
        if (!root) {
            return ans;
        }

        std::queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        bool isOrderLeft = true;

        while (!nodeQueue.empty()) {
            std::deque<int> levelList;
            int size = nodeQueue.size();
            for (int i = 0; i < size; ++i) {
                auto node = nodeQueue.front();
                nodeQueue.pop();
                if (isOrderLeft) {
                    levelList.push_back(node->val);
                } else {
                    levelList.push_front(node->val);
                }
                if (node->left) {
                    nodeQueue.push(node->left);
                }
                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }
            ans.emplace_back(std::vector<int>{levelList.begin(), levelList.end()});
            isOrderLeft = !isOrderLeft;
        }

        return ans;
    }
};

class ThreeSum {
public:
    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    /**
     * @brief
     *
     * @link https://leetcode.cn/problems/3sum/
     *
     */
protected:
    virtual std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        return {{}};
    }

    void test_case1() {
        std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
        std::vector<std::vector<int>> ans = {{-1, -1, 2}, {-1, 0, 1}};
        std::vector<std::vector<int>> res = threeSum(nums);
    }

    void test_case2() {
        std::vector<int> nums = {};
        std::vector<std::vector<int>> ans = {};
        std::vector<std::vector<int>> res = threeSum(nums);
    }

    void test_case3() {
        std::vector<int> nums = {0};
        std::vector<std::vector<int>> ans = {};
        std::vector<std::vector<int>> res = threeSum(nums);
    }
};

/**
 * @brief
 *
 * @link https://leetcode.cn/problems/3sum/solution/san-shu-zhi-he-by-leetcode-solution/
 *
 */

class ThreeSumSortingPlusDoublePointer : public ThreeSum {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) override {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};

class KthLargestElementInAnArray {
public:
    void test() {
        test_case1();
        test_case2();
        // test_case3();
    }

protected:
    /**
     * @brief
     *
     * @link https://leetcode.cn/problems/kth-largest-element-in-an-array/
     *
     * @param nums
     * @param k
     * @return int
     */
    virtual int findKthLargest(std::vector<int> &nums, int k) {
        return 0;
    }

    void test_case1() {
        std::vector<int> nums = {3, 2, 1, 5, 6, 4};
        int k = 2;
        int ans = 5;
        int res = findKthLargest(nums, k);
        std::cout << "test case 1" << std::endl;
    }

    void test_case2() {
        std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        int k = 4;
        int ans = 4;
        int res = findKthLargest(nums, k);
        std::cout << "test case 2" << std::endl;
    }
};

/**
 * @brief
 *
 * @link https://leetcode.cn/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/
 *
 */
class KthLargestElementInAnArraySelectionMethodsBasedOnFastSorting : public KthLargestElementInAnArray {
private:
    int quickSelect(std::vector<int> &a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(std::vector<int> &a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        std::swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(std::vector<int> &a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                std::swap(a[++i], a[j]);
            }
        }
        std::swap(a[i + 1], a[r]);
        return i + 1;
    }

public:
    int findKthLargest(std::vector<int> &nums, int k) override {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

/**
 * @brief
 *
 * @link https://leetcode.cn/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/
 *
 */
class KthLargestElementInAnArraySelectionMethodsBasedOnHeapSorting : public KthLargestElementInAnArray {
private:
    void maxHeapify(std::vector<int> &a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        }
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            std::swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(std::vector<int> &a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    }

public:
    int findKthLargest(std::vector<int> &nums, int k) override {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            std::swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};

class ReverseNodesInKGroup {
public:
    void test() {
        test_case1();
        test_case2();
        // test_case3();
    }

protected:
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode() : val(0), next(nullptr) {}
     *     ListNode(int x) : val(x), next(nullptr) {}
     *     ListNode(int x, ListNode *next) : val(x), next(next) {}
     * };
     */
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() :
            val(0), next(nullptr) {
        }
        ListNode(int x) :
            val(x), next(nullptr) {
        }
        ListNode(int x, ListNode *next) :
            val(x), next(next) {
        }
    };

    ListNode *create_list_from_vec(const std::vector<int> &list) {
        ListNode *head = nullptr;
        ListNode *l = nullptr;
        for (auto val : list) {
            auto *n = new ListNode(val);
            if (l) {
                l->next = n;
                l = l->next;
            } else {
                l = n;
                head = l;
            }
        }
        return head;
    }

    /**
     * @brief
     *
     * @link https://leetcode.cn/problems/reverse-nodes-in-k-group/
     *
     * @param head
     * @param k
     * @return ListNode*
     */
    virtual ListNode *reverseKGroup(ListNode *head, int k) {
        return nullptr;
    }

    void test_case1() {
        std::vector<int> list = {1, 2, 3, 4, 5};
        ListNode *input_list = create_list_from_vec(list);
        int k = 2;
        ListNode *output_list = reverseKGroup(input_list, k);
        std::cout << "test case 1" << std::endl;
    }

    void test_case2() {
        std::vector<int> list = {1, 2, 3, 4, 5};
        ListNode *input_list = create_list_from_vec(list);
        int k = 3;
        ListNode *output_list = reverseKGroup(input_list, k);
        std::cout << "test case 2" << std::endl;
    }
};

/**
 * @brief
 *
 * @link https://leetcode.cn/problems/reverse-nodes-in-k-group/solution/k-ge-yi-zu-fan-zhuan-lian-biao-by-leetcode-solutio/
 *
 */
class ReverseNodesInKGroupSimulation : public ReverseNodesInKGroup {
private:
    // 翻转一个子链表，并且返回新的头与尾
    std::pair<ListNode *, ListNode *> myReverse(ListNode *head, ListNode *tail) {
        ListNode *prev = tail->next;
        ListNode *p = head;
        while (prev != tail) {
            ListNode *nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) override {
        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *pre = hair;

        while (head) {
            ListNode *tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode *nex = tail->next;
            // 这里是 C++17 的写法，也可以写成
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            std::tie(head, tail) = myReverse(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};

class SortAnArray {
public:
    void test() {
        test_case1();
        test_case2();
        // test_case3();
    }

protected:
    /**
     * @brief https://leetcode.cn/problems/sort-an-array/
     *
     * @param nums
     * @return std::vector<int>
     */
    virtual std::vector<int> sortArray(std::vector<int> &nums) {
        return {};
    }

    void test_case1() {
        std::vector<int> nums = {5, 2, 3, 1};
        std::vector<int> res = sortArray(nums);
        std::vector<int> ans = {1, 2, 3, 5};
        std::cout << "test case 1" << std::endl;
    }

    void test_case2() {
        std::vector<int> nums = {5, 1, 1, 2, 0, 0};
        std::vector<int> res = sortArray(nums);
        std::vector<int> ans = {0, 0, 1, 1, 2, 5};
        std::cout << "test case 2" << std::endl;
    }
};

/**
 * @brief https://leetcode.cn/problems/sort-an-array/solution/pai-xu-shu-zu-by-leetcode-solution/
 *
 */
class SortAnArrayQuickSort : public SortAnArray {
private:
    int partition(std::vector<int> &nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                std::swap(nums[i], nums[j]);
            }
        }
        std::swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    int randomized_partition(std::vector<int> &nums, int l, int r) {
        int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        std::swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }
    void randomized_quicksort(std::vector<int> &nums, int l, int r) {
        if (l < r) {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }

public:
    std::vector<int> sortArray(std::vector<int> &nums) override {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};

/**
 * @brief https://leetcode.cn/problems/sort-an-array/solution/pai-xu-shu-zu-by-leetcode-solution/
 *
 */
class SortAnArrayHeapsorting : public SortAnArray {
    void maxHeapify(std::vector<int> &nums, int i, int len) {
        for (; (i << 1) + 1 <= len;) {
            int lson = (i << 1) + 1;
            int rson = (i << 1) + 2;
            int large;
            if (lson <= len && nums[lson] > nums[i]) {
                large = lson;
            } else {
                large = i;
            }
            if (rson <= len && nums[rson] > nums[large]) {
                large = rson;
            }
            if (large != i) {
                std::swap(nums[i], nums[large]);
                i = large;
            } else {
                break;
            }
        }
    }
    void buildMaxHeap(std::vector<int> &nums, int len) {
        for (int i = len / 2; i >= 0; --i) {
            maxHeapify(nums, i, len);
        }
    }
    void heapSort(std::vector<int> &nums) {
        int len = (int)nums.size() - 1;
        buildMaxHeap(nums, len);
        for (int i = len; i >= 1; --i) {
            std::swap(nums[i], nums[0]);
            len -= 1;
            maxHeapify(nums, 0, len);
        }
    }

public:
    std::vector<int> sortArray(std::vector<int> &nums) override {
        heapSort(nums);
        return nums;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/sort-an-array/solution/pai-xu-shu-zu-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/**
 * @brief https://leetcode.cn/problems/sort-an-array/solution/pai-xu-shu-zu-by-leetcode-solution/
 *
 *
 */
class SortAnArraySummarizeSort : public SortAnArray {
private:
    std::vector<int> tmp;
    void mergeSort(std::vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1;
        int cnt = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[cnt++] = nums[i++];
            } else {
                tmp[cnt++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[cnt++] = nums[i++];
        }
        while (j <= r) {
            tmp[cnt++] = nums[j++];
        }
        for (int i = 0; i < r - l + 1; ++i) {
            nums[i + l] = tmp[i];
        }
    }

public:
    std::vector<int> sortArray(std::vector<int> &nums) {
        tmp.resize((int)nums.size(), 0);
        mergeSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/sort-an-array/solution/pai-xu-shu-zu-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class SqrtX {
public:
    void test() {
        test_case1();
        test_case2();
        // test_case3();
    }

protected:
    /**
     * @brief
     *
     * @link https://leetcode-cn.com/problems/sqrtx/ @endlink
     *
     * @param x
     * @return int
     */
    virtual int mySqrt(int x) = 0;

    void test_case1() {
        int x = 4;
        int res = mySqrt(x);
        int ans = 2;
    }

    /**
     * @brief Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
     *
     */
    void test_case2() {
        int x = 8;
        int res = mySqrt(x);
        int ans = 2;
    }
};

/**
 * @brief
 *
 * @link https://leetcode.cn/problems/sqrtx/solution/x-de-ping-fang-gen-by-leetcode-solution/
 *
 */
class SqrtXPocketCalculatorAlgorithms : public SqrtX {
public:
    int mySqrt(int x) override {
        if (x == 0) {
            return 0;
        }
        int ans = std::exp(0.5 * std::log(x));
        return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }
};

/**
 * @brief
 *
 * @link https://leetcode.cn/problems/sqrtx/solution/x-de-ping-fang-gen-by-leetcode-solution/
 *
 */
class SqrtXDichotomousSearch : public SqrtX {
public:
    int mySqrt(int x) override {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

/**
 * @brief
 *
 * @link https://leetcode.cn/problems/sqrtx/solution/x-de-ping-fang-gen-by-leetcode-solution/
 *
 */
class SqrtXNewtonIteration : public SqrtX {
public:
    int mySqrt(int x) override {
        if (x == 0) {
            return 0;
        }

        double C = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};

class LRUCache {
public:
    /**
     * @link https://leetcode-cn.com/problems/lru-cache/
     * @brief
     * @param capacity
     */
    LRUCache(int capacity) {
    }

    virtual ~LRUCache() {
    }

    virtual int get(int key) {
        return 0;
    }

    virtual void put(int key, int value) {
    }

    void test() {
        test_case1();
        // test_case2();
        // test_case3();
    }

private:
    void test_case1() {
        put(1, 1);
        put(2, 2);
        int get_out1 = get(1);
        put(3, 3);
        int get_out2 = get(2);
        put(4, 4);
        int get_out3 = get(1);
        int get_out4 = get(3);
        int get_out5 = get(4);
    }

    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */
};

class LRUCacheHashTablesAndBiDirectionalLinkedTables : public LRUCache {
private:
    struct DLinkedNode {
        int key, value;
        DLinkedNode *prev;
        DLinkedNode *next;
        DLinkedNode() :
            key(0), value(0), prev(nullptr), next(nullptr) {
        }
        DLinkedNode(int _key, int _value) :
            key(_key), value(_value), prev(nullptr), next(nullptr) {
        }
    };

    std::unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int size;
    int capacity;

private:
    void addToHead(DLinkedNode *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode *node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode *removeTail() {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    /**
     * @link https://leetcode-cn.com/problems/lru-cache/solution/lruhuan-cun-ji-zhi-by-leetcode-solution/
     * @brief
     * @param _capacity
     */
    LRUCacheHashTablesAndBiDirectionalLinkedTables(int _capacity) :
        capacity(_capacity), size(0), LRUCache(_capacity) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) override {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) override {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode *node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode *removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        } else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
};

class LongestSubstringWithoutRepeatingCharacters {
public:
    LongestSubstringWithoutRepeatingCharacters() {
    }

    virtual ~LongestSubstringWithoutRepeatingCharacters() {
    }

    /**
     * @link https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
     * @brief
     * @param s
     * @return
     */
    virtual int lengthOfLongestSubstring(std::string s) {
    }

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

private:
    void test_case1() {
        std::string s = "abcabcbb";
        int res = lengthOfLongestSubstring(s);
        int ans = 3;
    }
    void test_case2() {
        std::string s = "bbbbb";
        int res = lengthOfLongestSubstring(s);
        int ans = 1;
    }
    void test_case3() {
        std::string s = "pwwkew";
        int res = lengthOfLongestSubstring(s);
        int ans = 3;
    }
};

class LongestSubstringWithoutRepeatingCharactersSlidingWindow : public LongestSubstringWithoutRepeatingCharacters {
public:
    int lengthOfLongestSubstring(std::string s) override {
        // 哈希集合，记录每个字符是否出现过
        std::unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = std::max(ans, rk - i + 1);
        }
        return ans;
    }
};

class ReverseList : public ListBase {
public:
    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

protected:
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode() : val(0), next(nullptr) {}
     *     ListNode(int x) : val(x), next(nullptr) {}
     *     ListNode(int x, ListNode *next) : val(x), next(next) {}
     * };
     */
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() :
            val(0), next(nullptr) {
        }

        ListNode(int x) :
            val(x), next(nullptr) {
        }

        ListNode(int x, ListNode *next) :
            val(x), next(next) {
        }
    };

    ListNode *create_list_from_vec(const std::vector<int> &list) {
        ListNode *head = nullptr;
        ListNode *l = nullptr;
        for (auto val : list) {
            auto *n = new ListNode(val);
            if (l) {
                l->next = n;
                l = l->next;
            } else {
                l = n;
                head = l;
            }
        }
        return head;
    }

    /**
     * @link https://leetcode-cn.com/problems/reverse-linked-list/
     * @param head
     * @return
     */
    virtual ListNode *reverseList(ListNode *head) = 0;

    void test_case1() {
        std::vector<int> list_vec = {1, 2, 3, 4, 5};
        ListNode *head = create_list_from_vec(list_vec);
        ListNode *result = reverseList(head);
        std::cout << "test case1" << std::endl;
    }

    void test_case2() {
        std::vector<int> list_vec = {1, 2};
        ListNode *head = create_list_from_vec(list_vec);
        ListNode *result = reverseList(head);
        std::cout << "test case2" << std::endl;
    }

    void test_case3() {
        std::vector<int> list_vec = {};
        ListNode *head = create_list_from_vec(list_vec);
        ListNode *result = reverseList(head);
        std::cout << "test case3" << std::endl;
    }
};

class ReverseListIteration : public ReverseList {
public:
    /**
     * @link
     * https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode-solution-d1k2/
     *
     * @param head
     *
     * @return
     */
    ListNode *reverseList(ListNode *head) override {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

class ReverseListRecursive : public ReverseList {
public:
    /**
     * @link
     * https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode-solution-d1k2/
     *
     * @param head
     * @return
     */
    ListNode *reverseList(ListNode *head) override {
        if (!head || !head->next) {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

class Dataframe23Iteration {
public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) :
            val(x), next(nullptr) {
        }
    };

    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

private:
};

class Dataframe28 {
public:
    /**
     *
     * @param nums
     * @param k
     * @return
     */
    virtual int findKthLargest(std::vector<int> &nums, int k) = 0;

    void test_case1() {
        std::vector<int> nums = {3, 2, 1, 5, 6, 4};
        int k = 2;
        int ans = findKthLargest(nums, k);

        std::cout << "expected: 5 "
                  << "actual: " << ans << std::endl;
    }

    void test_case2() {
        std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        int k = 4;
        int ans = findKthLargest(nums, k);

        std::cout << "expected: 4 "
                  << "actual: " << ans << std::endl;
    }

    void test() {
        test_case1();
        test_case2();
    }
};

//
// Created by 36636 on 2021/11/13.
//

class Dataframe28FastSorting : public Dataframe28 {
public:
    int quickSelect(std::vector<int> &a, int l, int r, int index);

    int randomPartition(std::vector<int> &a, int l, int r);

    int partition(std::vector<int> &a, int l, int r);

    int findKthLargest(std::vector<int> &nums, int k) override;
};

class Dataframe28HeapSorting : public Dataframe28 {
public:
    void maxHeapify(std::vector<int> &a, int i, int heapSize);

    void buildMaxHeap(std::vector<int> &a, int heapSize);

    int findKthLargest(std::vector<int> &nums, int k) override;
};

class Dataframe34 {
public:
    struct ListNode {
        int val;
        ListNode *next;

        explicit ListNode(int x) :
            val(x), next(nullptr) {
        }
    };

protected:
    static ListNode *create_from_list(const std::vector<int> &list) {
        ListNode *head = nullptr;
        ListNode *l = nullptr;
        for (auto val : list) {
            auto *n = new ListNode(val);
            if (l) {
                l->next = n;
                l = l->next;
            } else {
                l = n;
                head = l;
            }
        }
        return head;
    }

    static std::vector<int> to_list(ListNode *l) {
        std::vector<int> v;
        while (l->next) {
            v.push_back(l->val);
            l = l->next;
        }
        v.push_back(l->val);
        return v;
    }

    static void print_vector(const std::vector<int> &v) {
        for (auto val : v) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

public:
    virtual ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) = 0;

    void test_case1() {
        auto *n1 = new ListNode(2);
        auto *n2 = new ListNode(4);
        auto *n3 = new ListNode(3);
        n1->next = n2;
        n2->next = n3;
        ListNode *l1 = n1;

        auto *n4 = new ListNode(5);
        auto *n5 = new ListNode(6);
        auto *n6 = new ListNode(4);
        n4->next = n5;
        n5->next = n6;
        ListNode *l2 = n4;

        ListNode *ans = addTwoNumbers(l1, l2);
        std::cout << "actual: 7 0 8 " << std::endl;
        print_vector(to_list(ans));
    }

    void test_case2() {
        auto *n1 = new ListNode(0);
        ListNode *l1 = n1;

        auto *n2 = new ListNode(0);
        ListNode *l2 = n2;

        ListNode *ans = addTwoNumbers(l1, l2);
        std::cout << "actual: 0 " << std::endl;
        print_vector(to_list(ans));
    }

    void test_case3() {
        std::vector<int> l1_v = {9, 9, 9, 9, 9, 9, 9};
        std::vector<int> l2_v = {9, 9, 9, 9};

        ListNode *l1 = create_from_list(l1_v);
        ListNode *l2 = create_from_list(l2_v);
        ListNode *ans = addTwoNumbers(l1, l2);

        std::cout << "actual: 8 9 9 9 0 0 0 1" << std::endl;
        print_vector(to_list(ans));
    }

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }
};

class Dataframe34Endingwithzero : public Dataframe34 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) override {
        int len1 = 1; //记录l1的长度
        int len2 = 1; //记录l2的长度
        ListNode *p = l1;
        ListNode *q = l2;
        while (p->next != nullptr) //获取l1的长度
        {
            len1++;
            p = p->next;
        }
        while (q->next != nullptr) //获取l2的长度
        {
            len2++;
            q = q->next;
        }
        if (len1 > len2) // l1较长，在l2末尾补零
        {
            for (int i = 1; i <= len1 - len2; i++) {
                q->next = new ListNode(0);
                q = q->next;
            }
        } else // l2较长，在l1末尾补零
        {
            for (int i = 1; i <= len2 - len1; i++) {
                p->next = new ListNode(0);
                p = p->next;
            }
        }
        p = l1;
        q = l2;
        bool count = false;          //记录进位
        auto *l3 = new ListNode(-1); //存放结果的链表
        ListNode *w = l3;            // l3的移动指针
        int i = 0;                   //记录相加结果
        while (p != nullptr && q != nullptr) {
            i = count + p->val + q->val;
            w->next = new ListNode(i % 10);
            count = i >= 10;
            w = w->next;
            p = p->next;
            q = q->next;
        }
        if (count) //若最后还有进位
        {
            w->next = new ListNode(1);
            w = w->next;
        }
        return l3->next;
    }
};

class Dataframe34NonAlignedZero : public Dataframe34 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) override {
        auto *head = new ListNode(-1); //存放结果的链表
        ListNode *h = head;            //移动指针
        int sum = 0;                   //每个位的加和结果
        bool carry = false;            //进位标志
        while (l1 != nullptr || l2 != nullptr) {
            sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carry)
                sum++;
            h->next = new ListNode(sum % 10);
            h = h->next;
            carry = sum >= 10;
        }
        if (carry) {
            h->next = new ListNode(1);
        }
        return head->next;
    }
};

class Dataframe46 {
public:
    Dataframe46() = default;

    virtual ~Dataframe46() = default;

    virtual int longestValidParentheses(std::string s) = 0;

    void test() {
        input_s_.emplace_back("(()");
        input_s_.emplace_back(")()())");
        input_s_.emplace_back("");
        ref_ans_.push_back(2);
        ref_ans_.push_back(4);
        ref_ans_.push_back(0);
        for (const auto &s : input_s_) {
            ans_.push_back(longestValidParentheses(s));
        }
        std::cout << "Dataframe46 test end" << std::endl;
    }

private:
    std::vector<std::string> input_s_;
    std::vector<int> ans_;
    std::vector<int> ref_ans_;
};

class Dataframe46N1 : public Dataframe46 {
public:
    int longestValidParentheses(std::string s) override;

private:
};

class Dataframe46N2 : public Dataframe46 {
public:
    int longestValidParentheses(std::string s) override;

private:
};

class Dataframe46N3 : public Dataframe46 {
public:
    int longestValidParentheses(std::string s) override;

private:
};

namespace std {
class ConvertLargeNumbersFromDecimalToBinary {
public:
    bool isAllZero(char *str) {
        for (int i = 0; i < length; i++) {
            if ((int)str[i] != 0) {
                return false;
            }
        }
        return true;
    }

    void convert() {
        scanf("%s", sp);
        length = strlen(sp);
        //下面把ascii码值转换成整数值 十进制0对应ascii码的48
        for (int i = 0; i < length; i++) {
            sp[i] -= 48;
        }
        if (isAllZero(sp)) cout << "0" << endl;
        int counter = 0;
        //循环直到数组里所有数都为0
        while (!isAllZero(sp)) {
            int pre = 0;
            for (int i = 0; i < length; i++) {
                //除2取余
                int temp = (sp[i] + pre * 10) / 2;
                pre = (sp[i] + pre * 10) % 2;
                sp[i] = temp;
            }
            res[counter] = pre;
            counter++;
        }
        cout << "counter is " << counter << endl;
        for (int i = counter - 1; i >= 0; i--) {
            cout << res[i] << " ";
        }
        //            return 0;
    }

private:
    char sp[100];
    int res[100];
    int n, length;
};
} // namespace std

//
// class Dataframe35 {
// protected:
//    void print_vector(std::vector<double> v) {
//        for (auto val: v) {
//            std::cout << val << " ";
//        }
//        std::cout << std::endl;
//    }
//
// public:
//    virtual std::vector<double> intersection(std::vector<int> &start1, std::vector<int> &end1, std::vector<int> &start2,
//                                             std::vector<int> &end2) = 0;
//
//    void test_case1() {
//        std::vector<int> start1 = {0, 0};
//        std::vector<int> end1 = {1, 0};
//        std::vector<int> start2 = {1, 1};
//        std::vector<int> end2 = {0, -1};
//        std::vector<double> ans = intersection(start1, end1, start2, end2);
//        std::cout << "expect: {0.5, 0} " << std::endl;
//        print_vector(ans);
//
//    }
//
//    void test_case2() {
//        std::vector<int> start1 = {0, 0};
//        std::vector<int> end1 = {1, 0};
//        std::vector<int> start2 = {1, 1};
//        std::vector<int> end2 = {0, -1};
//        std::vector<double> ans = intersection(start1, end1, start2, end2);
//        std::cout << "expect: {0.5, 0} " << std::endl;
//        print_vector(ans);
//
//    }
//
//    void test_case3() {
//        std::vector<int> l1_v = {9, 9, 9, 9, 9, 9, 9};
//        std::vector<int> l2_v = {9, 9, 9, 9};
//
//        ListNode *l1 = create_from_list(l1_v);
//        ListNode *l2 = create_from_list(l2_v);
//        ListNode *ans = addTwoNumbers(l1, l2);
//
//        std::cout << "actual: 8 9 9 9 0 0 0 1" << std::endl;
//        print_vector(to_list(ans));
//
//    }
//
//
//    void test() {
//        test_case1();
//        test_case2();
//        test_case3();
//    }
//};

//#endif //CODING_DATAFRAME_H