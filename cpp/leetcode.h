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

//#ifndef CODING_DATAFRAME_H
//#define CODING_DATAFRAME_H

/**
 *
 */

class ListBase {
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
    }

    void test_case1() {
        std::vector<int> nums = {5, 2, 3, 1};
        std::vector<int> res = sortArray(nums);
        std::vector<int> ans = {1, 2, 3, 5};
    }

    void test_case2() {
        std::vector<int> nums = {5, 1, 1, 2, 0, 0};
        std::vector<int> res = sortArray(nums);
        std::vector<int> ans = {0, 0, 1, 1, 2, 5};
    }
};

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
    int randomized_partition(std::vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        std::swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }
    void randomized_quicksort(std::vector<int>& nums, int l, int r) {
        if (l < r) {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};

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
        if (len1 > len2) //l1较长，在l2末尾补零
        {
            for (int i = 1; i <= len1 - len2; i++) {
                q->next = new ListNode(0);
                q = q->next;
            }
        } else //l2较长，在l1末尾补零
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
        ListNode *w = l3;            //l3的移动指针
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
//class Dataframe35 {
//protected:
//    void print_vector(std::vector<double> v) {
//        for (auto val: v) {
//            std::cout << val << " ";
//        }
//        std::cout << std::endl;
//    }
//
//public:
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