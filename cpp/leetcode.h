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
/* rand example: guess the number */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

//#ifndef CODING_DATAFRAME_H
//#define CODING_DATAFRAME_H

// #include <bits/stdc++.h>

/**
 *
 */

class ListBase {
};

namespace std {
namespace zuoyebang {

}
// namespace fundamental_cpp1 {
// //     作者：LittleJoe
// // 链接：https://www.nowcoder.com/discuss/211668?source_id=discuss_experience_nctrack&channel=-1
// // 来源：牛客网

// class B

// {
//     int b;

// public:
//     virtual ~B() {
//         cout << "B::~B()" << endl;
//     }
// };

// class D : public B

// {
//     int i;

//     int j;

// public:
//     virtual ~D() {
//         cout << "D::~D()" << endl;
//     }
// };

// void test(void) {
//     B *pb = new D[2];

//     pb[1] = xxxx;

//     delete[] pb;

//     return 0;
// }

// } // namespace fundamental_cpp1
namespace correction_of_examination_papers {
// MT26 改考卷
// https://www.nowcoder.com/practice/be65e76a8b394139982047b2b0cec415?tpId=128&tags=&title=&difficulty=&judgeStatus=&rp=1&sourceUrl=&gioEnter=menu
bool helper(vector<int> &a) {
    sort(a.begin(), a.end(), greater<int>());
    int sum = 0;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] > a[0]) return false;
        sum += a[i];
    }
    if (sum < a[0]) return false;
    return true;
}

void test() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    printf("%s", helper(a) ? "Yes" : "No");
}
} // namespace correction_of_examination_papers

namespace company_canteen {
// 美团2021校招笔试-编程题(通用编程试题,第10场) 企业提供原题 [编程题]公司食堂
// https://www.nowcoder.com/question/next?pid=28665343&qid=1371130&tid=62325730
class Solution {
public:
    void solution() {
        int T;
        cin >> T;
        for (int i = 0; i < T; i++) {
            int N;
            string person_num;
            int M;
            string queue;
            cin >> N;
            cin >> person_num;
            cin >> M;
            cin >> queue;

            for (auto person : queue) {
                if (person == 'M') {
                    int seat_idx = person_num.find("1");
                    if (seat_idx != person_num.npos) {
                        person_num[seat_idx]++;
                        cout << ++seat_idx << endl;
                    } else {
                        seat_idx = person_num.find("0");
                        if (seat_idx != person_num.npos) {
                            person_num[seat_idx]++;
                            cout << ++seat_idx << endl;
                        }
                    }
                } else {
                    int seat_idx = person_num.find("0");
                    if (seat_idx != person_num.npos) {
                        person_num[seat_idx]++;
                        cout << ++seat_idx << endl;
                    } else {
                        seat_idx = person_num.find("1");
                        if (seat_idx != person_num.npos) {
                            person_num[seat_idx]++;
                            cout << ++seat_idx << endl;
                        }
                    }
                }
            }
        }
    }

    int partition(vector<int> &nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    int randomized_partition(vector<int> &nums, int l, int r) {
        int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }
    void randomized_quicksort(vector<int> &nums, int l, int r) {
        if (l < r) {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }

    vector<int> sortArray(vector<int> &nums) {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }

    struct Seat {
        int seat_idx;
        int person_num;
    };

    void solution2() {
        int T;
        cin >> T;
        for (int i = 0; i < T; i++) {
            int N;
            string person_num;
            int M;
            string queue;
            cin >> N;
            cin >> person_num;
            cin >> M;
            cin >> queue;

            vector<int> person_num_in_seat;
            vector<Seat> seats_array;

            int seat_idx_in_struct = 0;
            for (auto person_num_in_seat_char : person_num) {
                int person_num_in_seat_int = person_num_in_seat_char - '0';
                person_num_in_seat.push_back(person_num_in_seat_int);
                Seat seat;
                seat.seat_idx = seat_idx_in_struct;
                seat_idx_in_struct++;
                seat.person_num = person_num_in_seat_int;
                seats_array.push_back(seat);
            }

            // person_num_in_seat_sorted = sortArray(person_num_in_seat);

            for (auto person : queue) {
                if (person == 'M') {
                    int seat_idx = person_num.find("1");
                    if (seat_idx != person_num.npos) {
                        person_num[seat_idx]++;
                        cout << ++seat_idx << endl;
                    } else {
                        seat_idx = person_num.find("0");
                        if (seat_idx != person_num.npos) {
                            person_num[seat_idx]++;
                            cout << ++seat_idx << endl;
                        }
                    }
                } else {
                    int seat_idx = person_num.find("0");
                    if (seat_idx != person_num.npos) {
                        person_num[seat_idx]++;
                        cout << ++seat_idx << endl;
                    } else {
                        seat_idx = person_num.find("1");
                        if (seat_idx != person_num.npos) {
                            person_num[seat_idx]++;
                            cout << ++seat_idx << endl;
                        }
                    }
                }
            }
        }
    }
};

void test_company_canteen() {
    Solution *solution = new Solution();
    solution->solution2();
}
} // namespace company_canteen

namespace elimination_score {
// 美团2021校招笔试-编程题(通用编程试题,第10场) 企业提供原题 [编程题]淘汰分数
// https://www.nowcoder.com/test/question/9c4a4e879b4f49939dfaebea8948f976?pid=28665343&tid=62320284
class Solution {
public:
    int partition(vector<int> &nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    int randomized_partition(vector<int> &nums, int l, int r) {
        int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }
    void randomized_quicksort(vector<int> &nums, int l, int r) {
        if (l < r) {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }

    vector<int> sortArray(vector<int> &nums) {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }

    void solution() {
        int n;
        int x;
        int y;
        int score;
        vector<int> score_array;
        while (cin >> n) {
            cin >> x;
            cin >> y;
            for (int i = 0; i < n; i++) {
                cin >> score;
                score_array.push_back(score);
            }
            vector<int> sorted_score_array = sortArray(score_array);
            for (int i = 0; i < n; i++) {
                int low_score_num = i + 1;
                int high_score_num = n - low_score_num;
                if (low_score_num >= x && low_score_num <= y && high_score_num >= x && high_score_num <= y) {
                    cout << sorted_score_array[i];
                    return;
                }
            }
            cout << -1;
        }
    }
};
} // namespace elimination_score

namespace single_number_iii {
// 260. 只出现一次的数字 III https://leetcode.cn/problems/single-number-iii/
class Solution {
public:
    virtual vector<int> singleNumber(vector<int> &nums) = 0;
};
} // namespace single_number_iii

namespace count_of_smaller_numbers_after_self {
// 315. 计算右侧小于当前元素的个数 https://leetcode.cn/problems/count-of-smaller-numbers-after-self/
class Solution {
public:
    virtual vector<int> countSmaller(vector<int> &nums) = 0;
};
} // namespace count_of_smaller_numbers_after_self

namespace insert_into_a_binary_search_tree {
// 701. 二叉搜索树中的插入操作 https://leetcode.cn/problems/insert-into-a-binary-search-tree/
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
class Solution {
public:
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
    virtual TreeNode *insertIntoBST(TreeNode *root, int val) = 0;
};
} // namespace insert_into_a_binary_search_tree

namespace minimum_absolute_difference_in_bst {
// 530. 二叉搜索树的最小绝对差 https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
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
class Solution {
public:
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
    virtual int getMinimumDifference(TreeNode *root) = 0;
};
} // namespace minimum_absolute_difference_in_bst

namespace minimum_insertion_steps_to_make_a_string_palindrome {
// 1312. 让字符串成为回文串的最少插入次数 https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/
class Solution {
public:
    virtual int minInsertions(string s) = 0;
};
} // namespace minimum_insertion_steps_to_make_a_string_palindrome

namespace maximum_product_subarray {
// 152. 乘积最大子数组 https://leetcode.cn/problems/maximum-product-subarray/
class Solution {
public:
    virtual int maxProduct(vector<int> &nums) = 0;
};
} // namespace maximum_product_subarray

namespace fan_zhuan_dan_ci_shun_xu_lcof {
// 剑指 Offer 58 - I. 翻转单词顺序 https://leetcode.cn/problems/fan-zhuan-dan-ci-shun-xu-lcof/
class Solution {
public:
    virtual string reverseWords(string s) = 0;
};
} // namespace fan_zhuan_dan_ci_shun_xu_lcof

namespace intersection_of_two_arrays_ii {
// 350. 两个数组的交集 II https://leetcode.cn/problems/intersection-of-two-arrays-ii/
class Solution {
public:
    virtual vector<int> intersect(vector<int> &nums1, vector<int> &nums2) = 0;
};
} // namespace intersection_of_two_arrays_ii

namespace binary_tree_paths {
// 257. 二叉树的所有路径 https://leetcode.cn/problems/binary-tree-paths/
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
class Solution {
public:
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
    virtual vector<string> binaryTreePaths(TreeNode *root) = 0;
};
} // namespace binary_tree_paths

namespace shu_zu_zhong_de_ni_xu_dui_lcof {
// 剑指 Offer 51. 数组中的逆序对 https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
class Solution {
public:
    virtual int reversePairs(vector<int> &nums) = 0;
};
} // namespace shu_zu_zhong_de_ni_xu_dui_lcof

namespace longest_palindrome {
// 409. 最长回文串 https://leetcode.cn/problems/longest-palindrome/
class Solution {
public:
    virtual int longestPalindrome(string s) = 0;
};
} // namespace longest_palindrome

namespace twenty_four_game {
// 679. 24 点游戏 https://leetcode.cn/problems/24-game/
class Solution {
public:
    virtual bool judgePoint24(vector<int> &cards) = 0;
};
} // namespace twenty_four_game

namespace sort_characters_by_frequency {
// 451. 根据字符出现频率排序 https://leetcode.cn/problems/sort-characters-by-frequency/
class Solution {
public:
    virtual string frequencySort(string s) = 0;
};
} // namespace sort_characters_by_frequency

namespace fan_zhuan_lian_biao_lcof {
// 剑指 Offer 24. 反转链表 https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) :
            val(x), next(NULL) {
        }
    };
    virtual ListNode *reverseList(ListNode *head) = 0;
};
} // namespace fan_zhuan_lian_biao_lcof

namespace queue_reconstruction_by_height {
// 406. 根据身高重建队列 https://leetcode.cn/problems/queue-reconstruction-by-height/
class Solution {
public:
    virtual vector<vector<int>> reconstructQueue(vector<vector<int>> &people) = 0;
};
} // namespace queue_reconstruction_by_height

namespace valid_anagram {
// 242. 有效的字母异位词 https://leetcode.cn/problems/valid-anagram/
class Solution {
public:
    virtual bool isAnagram(string s, string t) = 0;
};
} // namespace valid_anagram

namespace delete_node_in_a_linked_list {
// 237. 删除链表中的节点 https://leetcode.cn/problems/delete-node-in-a-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) :
            val(x), next(NULL) {
        }
    };
    virtual void deleteNode(ListNode *node) = 0;
};
} // namespace delete_node_in_a_linked_list

namespace rotting_oranges {
// 994. 腐烂的橘子 https://leetcode.cn/problems/rotting-oranges/
class Solution {
public:
    virtual int orangesRotting(vector<vector<int>> &grid) = 0;
};
} // namespace rotting_oranges

namespace add_binary {
// 67. 二进制求和 https://leetcode.cn/problems/add-binary/
class Solution {
public:
    virtual string addBinary(string a, string b) = 0;
};
} // namespace add_binary

namespace replace_elements_with_greatest_element_on_right_side {
// 1299. 将每个元素替换为右侧最大元素 https://leetcode.cn/problems/replace-elements-with-greatest-element-on-right-side/
class Solution {
public:
    virtual vector<int> replaceElements(vector<int> &arr) = 0;
};
} // namespace replace_elements_with_greatest_element_on_right_side

namespace determine_if_a_point_is_inside_a_triangle {
// 如何判断一个点是否在三角形内？ https://mp.weixin.qq.com/s/UK7ilkFeEDQeVWvLDHbuKA
// 评测地址：https://www.nowcoder.com/questionTerminal/f9c4290baed0406cbbe2c23dd687732c
namespace solution1 {
struct Point {
    double x;
    double y;
};

double getDist(Point p1, Point p2) {
    //两点之间计算距离公式
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
double getArea(Point p1, Point p2, Point p3) {
    double a = getDist(p1, p2);
    double b = getDist(p2, p3);
    double c = getDist(p1, p3);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
bool isInTriangle(Point p1, Point p2, Point p3, Point o) {
    double s1 = getArea(p1, p2, o);
    double s2 = getArea(p2, p3, o);
    double s3 = getArea(p3, p1, o);
    double s = getArea(p1, p2, p3);
    return s1 + s2 + s3 == s; //此处没有用fabs(a-b)<eps比较，是方便大家理解思路
}
void test() {
    Point p1, p2, p3, o;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    cin >> o.x >> o.y;
    bool flag = isInTriangle(p1, p2, p3, o);
    if (flag)
        puts("Yes");
    else
        puts("No");
}
} // namespace solution1

namespace solution2 {
struct Point {
    double x;
    double y;
};
double product(Point p1, Point p2, Point p3) {
    //首先根据坐标计算p1p2和p1p3的向量，然后再计算叉乘
    // p1p2 向量表示为 (p2.x-p1.x,p2.y-p1.y)
    // p1p3 向量表示为 (p3.x-p1.x,p3.y-p1.y)
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}
bool isInTriangle(Point p1, Point p2, Point p3, Point o) {
    //保证p1，p2，p3是逆时针顺序
    if (product(p1, p2, p3) < 0) return isInTriangle(p1, p3, p2, o);
    if (product(p1, p2, o) > 0 && product(p2, p3, o) > 0 && product(p3, p1, o) > 0)
        return true;
    return false;
}
void test() {
    Point p1, p2, p3, o;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    cin >> o.x >> o.y;
    bool flag = isInTriangle(p1, p2, p3, o);
    if (flag)
        puts("Yes");
    else
        puts("No");
}
} // namespace solution2

} // namespace determine_if_a_point_is_inside_a_triangle

namespace serialize_and_deserialize_binary_tree {
// 297. 二叉树的序列化与反序列化 https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
        }
    };

    // Encodes a tree to a single string.
    virtual string serialize(TreeNode *root) = 0;

    // Decodes your encoded data to tree.
    virtual TreeNode *deserialize(string data) = 0;
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
} // namespace serialize_and_deserialize_binary_tree

namespace nim_game {
// 292. Nim 游戏 https://leetcode.cn/problems/nim-game/
class Solution {
public:
    virtual bool canWinNim(int n) = 0;
};
} // namespace nim_game

namespace add_digits {
// 258. 各位相加 https://leetcode.cn/problems/add-digits/
class Solution {
public:
    virtual int addDigits(int num) = 0;
};
} // namespace add_digits

namespace range_addition_ii {
// 598. 范围求和 II https://leetcode.cn/problems/range-addition-ii/
class Solution {
public:
    virtual int maxCount(int m, int n, vector<vector<int>> &ops) = 0;
};

} // namespace range_addition_ii

namespace single_number_ii {
// 137. 只出现一次的数字 II https://leetcode.cn/problems/single-number-ii/
class Solution {
public:
    virtual int singleNumber(vector<int> &nums) = 0;
};
} // namespace single_number_ii

namespace matchsticks_to_square {
// 473. 火柴拼正方形 https://leetcode.cn/problems/matchsticks-to-square/
class Solution {
public:
    virtual bool makesquare(vector<int> &matchsticks) = 0;
};
} // namespace matchsticks_to_square

namespace find_peak_element {
// 162. 寻找峰值 https://leetcode.cn/problems/find-peak-element/
class Solution {
public:
    virtual int findPeakElement(vector<int> &nums) = 0;
};
} // namespace find_peak_element

namespace self_dividing_numbers {
// 728. 自除数 https://leetcode.cn/problems/self-dividing-numbers/
class Solution {
public:
    virtual vector<int> selfDividingNumbers(int left, int right) = 0;
};
} // namespace self_dividing_numbers

namespace longest_duplicate_substring {
// 1044. 最长重复子串 https://leetcode.cn/problems/longest-duplicate-substring/
class Solution {
public:
    virtual string longestDupSubstring(string s) = 0;
};
} // namespace longest_duplicate_substring

namespace er_cha_sou_suo_shu_yu_shuang_xiang_lian_biao_lcof {
// 剑指 Offer 36. 二叉搜索树与双向链表 https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    class Node {
    public:
        int val;
        Node *left;
        Node *right;

        Node() {
        }

        Node(int _val) {
            val = _val;
            left = NULL;
            right = NULL;
        }

        Node(int _val, Node *_left, Node *_right) {
            val = _val;
            left = _left;
            right = _right;
        }
    };
    virtual Node *treeToDoublyList(Node *root) = 0;
};
} // namespace er_cha_sou_suo_shu_yu_shuang_xiang_lian_biao_lcof

namespace shu_ju_liu_zhong_de_zhong_wei_shu_lcof {
// 剑指 Offer 41. 数据流中的中位数 https://leetcode.cn/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    virtual void addNum(int num) = 0;

    virtual double findMedian() = 0;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
} // namespace shu_ju_liu_zhong_de_zhong_wei_shu_lcof

namespace populating_next_right_pointers_in_each_node_ii {
// 117. 填充每个节点的下一个右侧节点指针 II https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    class Node {
    public:
        int val;
        Node *left;
        Node *right;
        Node *next;

        Node() :
            val(0), left(NULL), right(NULL), next(NULL) {
        }

        Node(int _val) :
            val(_val), left(NULL), right(NULL), next(NULL) {
        }

        Node(int _val, Node *_left, Node *_right, Node *_next) :
            val(_val), left(_left), right(_right), next(_next) {
        }
    };
    virtual Node *connect(Node *root) = 0;
};
} // namespace populating_next_right_pointers_in_each_node_ii

namespace perfect_rectangle {
// 391. 完美矩形 https://leetcode.cn/problems/perfect-rectangle/
class Solution {
public:
    virtual bool isRectangleCover(vector<vector<int>> &rectangles) = 0;
};
} // namespace perfect_rectangle

namespace design_in_memory_file_system {
// https://leetcode.cn/problems/design-in-memory-file-system/
}

namespace find_pivot_index {
// 724. 寻找数组的中心下标 https://leetcode.cn/problems/find-pivot-index/
class Solution {
public:
    virtual int pivotIndex(vector<int> &nums) = 0;
};
} // namespace find_pivot_index

namespace triangle {
// 120. 三角形最小路径和 https://leetcode.cn/problems/triangle/
class Solution {
public:
    virtual int minimumTotal(vector<vector<int>> &triangle) = 0;
};
} // namespace triangle

namespace power_of_two {
// 231. 2 的幂 https://leetcode.cn/problems/power-of-two/
class Solution {
public:
    virtual bool isPowerOfTwo(int n) = 0;
};
} // namespace power_of_two

namespace delete_node_in_a_bst {
// 450. 删除二叉搜索树中的节点 https://leetcode.cn/problems/delete-node-in-a-bst/
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
class Solution {
public:
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
    virtual TreeNode *deleteNode(TreeNode *root, int key) = 0;
};
} // namespace delete_node_in_a_bst

namespace missing_number {
// 268. 丢失的数字 https://leetcode.cn/problems/missing-number/
class Solution {
public:
    virtual int missingNumber(vector<int> &nums) = 0;
};
} // namespace missing_number

namespace shu_zhi_de_zheng_shu_ci_fang_lcof {
// 剑指 Offer 16. 数值的整数次方 https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
class Solution {
public:
    virtual double myPow(double x, int n) = 0;
};
} // namespace shu_zhi_de_zheng_shu_ci_fang_lcof

namespace path_with_maximum_gold {
// 1219. 黄金矿工 https://leetcode.cn/problems/path-with-maximum-gold/
class Solution {
public:
    virtual int getMaximumGold(vector<vector<int>> &grid) = 0;
};
} // namespace path_with_maximum_gold

namespace four_num_sum {
// 18. 四数之和 https://leetcode.cn/problems/4sum/
class Solution {
public:
    virtual vector<vector<int>> fourSum(vector<int> &nums, int target) = 0;
};
} // namespace four_num_sum

namespace longest_increasing_path_in_a_matrix {
// 329. 矩阵中的最长递增路径 https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/
class Solution {
public:
    virtual int longestIncreasingPath(vector<vector<int>> &matrix) = 0;
};
} // namespace longest_increasing_path_in_a_matrix

namespace maximum_width_of_binary_tree {
// 662. 二叉树最大宽度 https://leetcode.cn/problems/maximum-width-of-binary-tree/
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
class Solution {
public:
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
    virtual int widthOfBinaryTree(TreeNode *root) = 0;
};
} // namespace maximum_width_of_binary_tree

namespace lru_cache_lcci {
// 面试题 16.25. LRU 缓存 https://leetcode.cn/problems/lru-cache-lcci/
class LRUCache {
public:
    LRUCache(int capacity) {
    }

    virtual int get(int key) = 0;

    virtual void put(int key, int value) = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
} // namespace lru_cache_lcci

namespace minimum_depth_of_binary_tree {
// 111. 二叉树的最小深度 https://leetcode.cn/problems/minimum-depth-of-binary-tree/
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
class Solution {
public:
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
    virtual int minDepth(TreeNode *root) = 0;
};
} // namespace minimum_depth_of_binary_tree

namespace diagonal_traverse {
// 498. 对角线遍历 https://leetcode.cn/problems/diagonal-traverse/
class Solution {
public:
    virtual vector<int> findDiagonalOrder(vector<vector<int>> &mat) = 0;
};
} // namespace diagonal_traverse

namespace happy_number {
// 202. 快乐数 https://leetcode.cn/problems/happy-number/
class Solution {
public:
    virtual bool isHappy(int n) = 0;
};
} // namespace happy_number

namespace largest_rectangle_in_histogram {
// 84. 柱状图中最大的矩形 https://leetcode.cn/problems/largest-rectangle-in-histogram/
class Solution {
public:
    virtual int largestRectangleArea(vector<int> &heights) = 0;
};
} // namespace largest_rectangle_in_histogram

namespace course_schedule {
// 207. 课程表 https://leetcode.cn/problems/course-schedule/
class Solution {
public:
    virtual bool canFinish(int numCourses, vector<vector<int>> &prerequisites) = 0;
};
} // namespace course_schedule

namespace er_cha_shu_zhong_he_wei_mou_yi_zhi_de_lu_jing_lcof {
// 剑指 Offer 34. 二叉树中和为某一值的路径 https://leetcode.cn/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
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
class Solution {
public:
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
    virtual vector<vector<int>> pathSum(TreeNode *root, int target) = 0;
};
} // namespace er_cha_shu_zhong_he_wei_mou_yi_zhi_de_lu_jing_lcof

namespace find_the_index_of_the_first_occurrence_in_a_string {
// 28. 找出字符串中第一个匹配项的下标 https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
class Solution {
public:
    virtual int strStr(string haystack, string needle) = 0;
};
} // namespace find_the_index_of_the_first_occurrence_in_a_string

namespace insert_delete_getrandom_o1_duplicates_allowed {
// 381. O(1) 时间插入、删除和获取随机元素 - 允许重复 https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/
class RandomizedCollection {
public:
    RandomizedCollection() {
    }

    virtual bool insert(int val) = 0;

    virtual bool remove(int val) = 0;

    virtual int getRandom() = 0;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
} // namespace insert_delete_getrandom_o1_duplicates_allowed

namespace jump_game_ii {
// 45. 跳跃游戏 II https://leetcode.cn/problems/jump-game-ii/
class Solution {
public:
    virtual int jump(vector<int> &nums) = 0;
};
} // namespace jump_game_ii

namespace subarray_sum_equals_k {
// 560. 和为 K 的子数组 https://leetcode.cn/problems/subarray-sum-equals-k/
class Solution {
public:
    virtual int subarraySum(vector<int> &nums, int k) = 0;
};
} // namespace subarray_sum_equals_k

namespace liang_ge_lian_biao_de_di_yi_ge_gong_gong_jie_dian_lcof {
// 剑指 Offer 52. 两个链表的第一个公共节点 https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) :
            val(x), next(NULL) {
        }
    };
    virtual ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) = 0;
};
} // namespace liang_ge_lian_biao_de_di_yi_ge_gong_gong_jie_dian_lcof

namespace cong_shang_dao_xia_da_yin_er_cha_shu_iii_lcof {
// 剑指 Offer 32 - III. 从上到下打印二叉树 III https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
        }
    };
    virtual vector<vector<int>> levelOrder(TreeNode *root) = 0;
};
} // namespace cong_shang_dao_xia_da_yin_er_cha_shu_iii_lcof

namespace number_of_connected_components_in_an_undirected_graph {
// https://leetcode.cn/problems/number-of-connected-components-in-an-undirected-graph/
}

namespace shortest_unsorted_continuous_subarray {
// 581. 最短无序连续子数组 https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/
class Solution {
public:
    virtual int findUnsortedSubarray(vector<int> &nums) = 0;
};
} // namespace shortest_unsorted_continuous_subarray

namespace chou_shu_lcof {
// 剑指 Offer 49. 丑数 https://leetcode.cn/problems/chou-shu-lcof/
class Solution {
public:
    virtual int nthUglyNumber(int n) = 0;
};
} // namespace chou_shu_lcof

namespace russian_doll_envelopes {
// 354. 俄罗斯套娃信封问题 https://leetcode.cn/problems/russian-doll-envelopes/
class Solution {
public:
    virtual int maxEnvelopes(vector<vector<int>> &envelopes) = 0;
};
} // namespace russian_doll_envelopes

namespace eight_queens_lcci {
// 面试题 08.12. 八皇后 https://leetcode.cn/problems/eight-queens-lcci/
class Solution {
public:
    virtual vector<vector<string>> solveNQueens(int n) = 0;
};
} // namespace eight_queens_lcci

namespace palindrome_partitioning {
// 131. 分割回文串 https://leetcode.cn/problems/palindrome-partitioning/
class Solution {
public:
    virtual vector<vector<string>> partition(string s) = 0;
};
} // namespace palindrome_partitioning

namespace convert_sorted_array_to_binary_search_tree {
// 108. 将有序数组转换为二叉搜索树 https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
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
class Solution {
public:
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
    virtual TreeNode *sortedArrayToBST(vector<int> &nums) = 0;
};
} // namespace convert_sorted_array_to_binary_search_tree

namespace split_array_largest_sum {
// 410. 分割数组的最大值 https://leetcode.cn/problems/split-array-largest-sum/
class Solution {
public:
    virtual int splitArray(vector<int> &nums, int m) = 0;
};
} // namespace split_array_largest_sum

namespace longest_subarray_of_1s_after_deleting_one_element {
// 1493. 删掉一个元素以后全为 1 的最长子数组 https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/
class Solution {
public:
    virtual int longestSubarray(vector<int> &nums) = 0;
};
} // namespace longest_subarray_of_1s_after_deleting_one_element

namespace search_insert_position {
// 35. 搜索插入位置 https://leetcode.cn/problems/search-insert-position/
class Solution {
public:
    virtual int searchInsert(vector<int> &nums, int target) = 0;
};
} // namespace search_insert_position

namespace flip_equivalent_binary_trees {
// 951. 翻转等价二叉树 https://leetcode.cn/problems/flip-equivalent-binary-trees/
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
class Solution {
public:
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
    virtual bool flipEquiv(TreeNode *root1, TreeNode *root2) = 0;
};
} // namespace flip_equivalent_binary_trees

namespace find_minimum_in_rotated_sorted_array_ii {
// 154. 寻找旋转排序数组中的最小值 II https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/
class Solution {
public:
    virtual int findMin(vector<int> &nums) = 0;
};
} // namespace find_minimum_in_rotated_sorted_array_ii

namespace remove_all_adjacent_duplicates_in_string_ii {
// 1209. 删除字符串中的所有相邻重复项 II https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string-ii/
class Solution {
public:
    virtual string removeDuplicates(string s, int k) = 0;
};
} // namespace remove_all_adjacent_duplicates_in_string_ii

namespace kth_smallest_element_in_a_bst {
// 230. 二叉搜索树中第K小的元素 https://leetcode.cn/problems/kth-smallest-element-in-a-bst/
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
class Solution {
public:
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
    virtual int kthSmallest(TreeNode *root, int k) = 0;
};
} // namespace kth_smallest_element_in_a_bst

namespace di_yi_ge_zhi_chu_xian_yi_ci_de_zi_fu_lcof {
// 剑指 Offer 50. 第一个只出现一次的字符 https://leetcode.cn/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
class Solution {
public:
    virtual char firstUniqChar(string s) = 0;
};
} // namespace di_yi_ge_zhi_chu_xian_yi_ci_de_zi_fu_lcof

namespace integer_to_roman {
// 12. 整数转罗马数字 https://leetcode.cn/problems/integer-to-roman/
class Solution {
public:
    virtual string intToRoman(int num) = 0;
};
} // namespace integer_to_roman

namespace minimum_falling_path_sum {
// 931. 下降路径最小和 https://leetcode.cn/problems/minimum-falling-path-sum/
class Solution {
public:
    virtual int minFallingPathSum(vector<vector<int>> &matrix) = 0;
};
} // namespace minimum_falling_path_sum

namespace word_break {
// 139. 单词拆分 https://leetcode.cn/problems/word-break/
class Solution {
public:
    virtual bool wordBreak(string s, vector<string> &wordDict) = 0;
};
} // namespace word_break

namespace reverse_pairs {
// 493. 翻转对 https://leetcode.cn/problems/reverse-pairs/
class Solution {
public:
    virtual int reversePairs(vector<int> &nums) = 0;
};
} // namespace reverse_pairs

namespace basic_calculator_iv {
// 770. 基本计算器 IV https://leetcode.cn/problems/basic-calculator-iv/
class Solution {
public:
    virtual vector<string> basicCalculatorIV(string expression, vector<string> &evalvars, vector<int> &evalints) = 0;
};
} // namespace basic_calculator_iv

namespace ba_shu_zu_pai_cheng_zui_xiao_de_shu_lcof {
// 剑指 Offer 45 https://leetcode.cn/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
class Solution {
public:
    virtual string minNumber(vector<int> &nums) = 0;
};
} // namespace ba_shu_zu_pai_cheng_zui_xiao_de_shu_lcof

namespace rotate_matrix_lcci {
// 面试题 01.07. 旋转矩阵 https://leetcode.cn/problems/rotate-matrix-lcci/
class Solution {
public:
    virtual void rotate(vector<vector<int>> &matrix) = 0;
};
} // namespace rotate_matrix_lcci

namespace n_queens {
// 51. N 皇后 https://leetcode.cn/problems/n-queens/
class Solution {
public:
    virtual vector<vector<string>> solveNQueens(int n) = 0;
};
} // namespace n_queens

namespace number_of_sub_arrays_of_size_k_and_average_greater_than_or_equal_to_threshold {
// 1343. 大小为 K 且平均值大于等于阈值的子数组数目 https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
class Solution {
public:
    virtual int numOfSubarrays(vector<int> &arr, int k, int threshold) = 0;
};
} // namespace number_of_sub_arrays_of_size_k_and_average_greater_than_or_equal_to_threshold

namespace word_ladder {
// 127. 单词接龙 https://leetcode.cn/problems/word-ladder/
class Solution {
public:
    virtual int ladderLength(string beginWord, string endWord, vector<string> &wordList) = 0;
};
} // namespace word_ladder

namespace network_delay_time {
// 743. 网络延迟时间 https://leetcode.cn/problems/network-delay-time/
class Solution {
public:
    virtual int networkDelayTime(vector<vector<int>> &times, int n, int k) = 0;
};
} // namespace network_delay_time

namespace insert_interval {
// 57. 插入区间 https://leetcode.cn/problems/insert-interval/
class Solution {
public:
    virtual vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) = 0;
};
} // namespace insert_interval

namespace integer_break {
// 343. 整数拆分 https://leetcode.cn/problems/integer-break/
class Solution {
public:
    virtual int integerBreak(int n) = 0;
};
} // namespace integer_break

namespace remove_covered_intervals {
// 1288. 删除被覆盖区间 https://leetcode.cn/problems/remove-covered-intervals/
class Solution {
public:
    virtual int removeCoveredIntervals(vector<vector<int>> &intervals) = 0;
};
} // namespace remove_covered_intervals

namespace da_yin_cong_1dao_zui_da_de_nwei_shu_lcof {
// 剑指 Offer 17. 打印从1到最大的n位数 https://leetcode.cn/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/
class Solution {
public:
    virtual vector<int> printNumbers(int n) = 0;
};
} // namespace da_yin_cong_1dao_zui_da_de_nwei_shu_lcof

namespace delete_and_earn {
// 740. 删除并获得点数 https://leetcode.cn/problems/delete-and-earn/
class Solution {
public:
    virtual int deleteAndEarn(vector<int> &nums) = 0;
};
} // namespace delete_and_earn

namespace all_nodes_distance_k_in_binary_tree {
// 863. 二叉树中所有距离为 K 的结点 https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
        }
    };
    virtual vector<int> distanceK(TreeNode *root, TreeNode *target, int k) = 0;
};
} // namespace all_nodes_distance_k_in_binary_tree

namespace maximal_rectangle {
// 85. 最大矩形 https://leetcode.cn/problems/maximal-rectangle/
class Solution {
public:
    virtual int maximalRectangle(vector<vector<char>> &matrix) = 0;
};
} // namespace maximal_rectangle

namespace baby_names_lcci {
// 面试题 17.07. 婴儿名字  https://leetcode.cn/problems/baby-names-lcci/
class Solution {
public:
    virtual vector<string> trulyMostPopular(vector<string> &names, vector<string> &synonyms) = 0;
};
} // namespace baby_names_lcci

namespace find_k_length_substrings_with_no_repeated_characters {
// https://leetcode.cn/problems/find-k-length-substrings-with-no-repeated-characters/
}

namespace meeting_rooms_ii {
// https://leetcode.cn/problems/meeting-rooms-ii/
}

namespace daily_temperatures {
// 739. 每日温度 https://leetcode.cn/problems/daily-temperatures/
class Solution {
public:
    virtual vector<int> dailyTemperatures(vector<int> &temperatures) = 0;
};
} // namespace daily_temperatures

namespace design_file_system {
// https://leetcode.cn/problems/design-file-system/
}

namespace split_array_into_fibonacci_sequence {
// 842. 将数组拆分成斐波那契序列 https://leetcode.cn/problems/split-array-into-fibonacci-sequence/
class Solution {
public:
    virtual vector<int> splitIntoFibonacci(string num) = 0;
};
} // namespace split_array_into_fibonacci_sequence

namespace validate_binary_search_tree {
// 98 https://leetcode.cn/problems/validate-binary-search-tree/
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
class Solution {
public:
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
    virtual bool isValidBST(TreeNode *root) = 0;
};
} // namespace validate_binary_search_tree
namespace shu_zu_zhong_shu_zi_chu_xian_de_ci_shu_ii_lcof {
// 剑指 Offer 56 - II https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
class Solution {
public:
    virtual int singleNumber(vector<int> &nums) = 0;
};
} // namespace shu_zu_zhong_shu_zi_chu_xian_de_ci_shu_ii_lcof
namespace top_k_frequent_elements {
// 347 https://leetcode.cn/problems/top-k-frequent-elements/
class Solution {
public:
    virtual vector<int> topKFrequent(vector<int> &nums, int k) = 0;
};
} // namespace top_k_frequent_elements
namespace maximum_depth_of_n_ary_tree {
// 559 https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    class Node {
    public:
        int val;
        vector<Node *> children;

        Node() {
        }

        Node(int _val) {
            val = _val;
        }

        Node(int _val, vector<Node *> _children) {
            val = _val;
            children = _children;
        }
    };
    virtual int maxDepth(Node *root) = 0;
};
} // namespace maximum_depth_of_n_ary_tree
namespace combination_sum_ii {
// 40 https://leetcode.cn/problems/combination-sum-ii/
class Solution {
public:
    virtual vector<vector<int>> combinationSum2(vector<int> &candidates, int target) = 0;
};
} // namespace combination_sum_ii
namespace set_matrix_zeroes {
// 73 https://leetcode.cn/problems/set-matrix-zeroes/
class Solution {
public:
    virtual void setZeroes(vector<vector<int>> &matrix) = 0;
};
} // namespace set_matrix_zeroes
namespace minimum_size_subarray_sum {
// 209 https://leetcode.cn/problems/minimum-size-subarray-sum/
class Solution {
public:
    virtual int minSubArrayLen(int target, vector<int> &nums) = 0;
};
} // namespace minimum_size_subarray_sum
namespace increasing_subsequences {
// 491 https://leetcode.cn/problems/increasing-subsequences/
class Solution {
public:
    virtual vector<vector<int>> findSubsequences(vector<int> &nums) = 0;
};
} // namespace increasing_subsequences
namespace summary_ranges {
// 228 https://leetcode.cn/problems/summary-ranges/
class Solution {
public:
    virtual vector<string> summaryRanges(vector<int> &nums) = 0;
};
} // namespace summary_ranges
namespace combination_sum {
// 39 https://leetcode.cn/problems/combination-sum/
class Solution {
public:
    virtual vector<vector<int>> combinationSum(vector<int> &candidates, int target) = 0;
};
} // namespace combination_sum
namespace count_complete_tree_nodes {
// 222 https://leetcode.cn/problems/count-complete-tree-nodes/
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
class Solution {
public:
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
    virtual int countNodes(TreeNode *root) = 0;
};
} // namespace count_complete_tree_nodes
namespace unique_binary_search_trees_ii {
// 95 https://leetcode.cn/problems/unique-binary-search-trees-ii/
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
class Solution {
public:
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
    virtual vector<TreeNode *> generateTrees(int n) = 0;
};
} // namespace unique_binary_search_trees_ii
namespace license_key_formatting {
// 482 https://leetcode.cn/problems/license-key-formatting/
class Solution {
public:
    virtual string licenseKeyFormatting(string s, int k) = 0;
};
} // namespace license_key_formatting
namespace maximum_product_of_three_numbers {
// 628 https://leetcode.cn/problems/maximum-product-of-three-numbers/
class Solution {
public:
    virtual int maximumProduct(vector<int> &nums) = 0;
};
} // namespace maximum_product_of_three_numbers
namespace subtree_of_another_tree {
// 572 https://leetcode.cn/problems/subtree-of-another-tree/
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
class Solution {
public:
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
    virtual bool isSubtree(TreeNode *root, TreeNode *subRoot) = 0;
};
} // namespace subtree_of_another_tree
namespace peak_index_in_a_mountain_array {
// 852 https://leetcode.cn/problems/peak-index-in-a-mountain-array/
class Solution {
public:
    virtual int peakIndexInMountainArray(vector<int> &arr) = 0;
};
} // namespace peak_index_in_a_mountain_array
namespace reverse_string {
// 344 https://leetcode.cn/problems/reverse-string/
class Solution {
public:
    virtual void reverseString(vector<char> &s) = 0;
};
} // namespace reverse_string
namespace shortest_path_visiting_all_nodes {
// 847 https://leetcode.cn/problems/shortest-path-visiting-all-nodes/
class Solution {
public:
    virtual int shortestPathLength(vector<vector<int>> &graph) = 0;
};
} // namespace shortest_path_visiting_all_nodes
namespace add_two_numbers_ii {
// 445 https://leetcode.cn/problems/add-two-numbers-ii/
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
class Solution {
public:
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
    virtual ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) = 0;
};
} // namespace add_two_numbers_ii
namespace longest_valid_parentheses {
// 32 https://leetcode.cn/problems/longest-valid-parentheses/
class Solution {
public:
    virtual int longestValidParentheses(string s) = 0;
};
} // namespace longest_valid_parentheses

namespace excel_sheet_column_title {
class Solution {
public:
    /**
     * @brief 168 https://leetcode.cn/problems/excel-sheet-column-title/
     *
     * @param columnNumber
     * @return string
     */
    virtual string convertToTitle(int columnNumber) = 0;
};
} // namespace excel_sheet_column_title
namespace rotate_image {
class Solution {
public:
    /**
     * @brief  48 https://leetcode.cn/problems/rotate-image/
     *
     * @param matrix
     */
    virtual void rotate(vector<vector<int>> &matrix) = 0;
};
} // namespace rotate_image
namespace diameter_of_binary_tree {
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
class Solution {
public:
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
     * @brief  543 https://leetcode.cn/problems/diameter-of-binary-tree/
     *
     * @param root
     * @return int
     */
    virtual int diameterOfBinaryTree(TreeNode *root) = 0;
};
} // namespace diameter_of_binary_tree
namespace find_in_mountain_array {
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    class MountainArray {
    public:
        int get(int index);
        int length();
    };
    /**
     * @brief  1095 https://leetcode.cn/problems/find-in-mountain-array/
     *
     * @param target
     * @param mountainArr
     * @return int
     */
    virtual int findInMountainArray(int target, MountainArray &mountainArr) = 0;
};
} // namespace find_in_mountain_array
namespace shun_shi_zhen_da_yin_ju_zhen_lcof {
class Solution {
public:
    /**
     * @brief  剑指 Offer 29 https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
     *
     * @param matrix
     * @return vector<int>
     */
    virtual vector<int> spiralOrder(vector<vector<int>> &matrix) = 0;
};
} // namespace shun_shi_zhen_da_yin_ju_zhen_lcof
namespace pascals_triangle {
class Solution {
public:
    /**
     * @brief  118 https://leetcode.cn/problems/pascals-triangle/
     *
     * @param numRows
     * @return vector<vector<int>>
     */
    virtual vector<vector<int>> generate(int numRows) = 0;
};
} // namespace pascals_triangle
namespace fei_bo_na_qi_shu_lie_lcof {
class Solution {
public:
    /**
     * @brief  剑指 Offer 10- I https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/
     *
     * @param n
     * @return int
     */
    virtual int fib(int n) = 0;
};
} // namespace fei_bo_na_qi_shu_lie_lcof
namespace shu_zu_zhong_zhong_fu_de_shu_zi_lcof {
class Solution {
public:
    /**
     * @brief  剑指 Offer 03 https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
     *
     * @param nums
     * @return int
     */
    virtual int findRepeatNumber(vector<int> &nums) = 0;
};
} // namespace shu_zu_zhong_zhong_fu_de_shu_zi_lcof
namespace sum_of_subarray_minimums {
class Solution {
public:
    /**
     * @brief  907 https://leetcode.cn/problems/sum-of-subarray-minimums/
     *
     * @param arr
     * @return int
     */
    virtual int sumSubarrayMins(vector<int> &arr) = 0;
};
} // namespace sum_of_subarray_minimums
namespace move_zeroes {
class Solution {
public:
    /**
     * @brief  283 https://leetcode.cn/problems/move-zeroes/
     *
     * @param nums
     */
    virtual void moveZeroes(vector<int> &nums) = 0;
};
} // namespace move_zeroes
namespace bu_yong_jia_jian_cheng_chu_zuo_jia_fa_lcof {
class Solution {
public:
    /**
     * @brief  剑指 Offer 65. https://leetcode.cn/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/
     *
     * @param a
     * @param b
     * @return int
     */
    virtual int add(int a, int b) = 0;
};
} // namespace bu_yong_jia_jian_cheng_chu_zuo_jia_fa_lcof
namespace contains_duplicate {
class Solution {
public:
    /**
     * @brief  217 https://leetcode.cn/problems/contains-duplicate/
     *
     * @param nums
     * @return true
     * @return false
     */
    virtual bool containsDuplicate(vector<int> &nums) = 0;
};
} // namespace contains_duplicate
namespace product_of_array_except_self {
class Solution {
public:
    /**
     * @brief  238 https://leetcode.cn/problems/product-of-array-except-self/
     *
     * @param nums
     * @return vector<int>
     */
    virtual vector<int> productExceptSelf(vector<int> &nums) = 0;
};
} // namespace product_of_array_except_self
namespace best_time_to_buy_and_sell_stock_iii {
class Solution {
public:
    /**
     * @brief  123 https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
     *
     * @param prices
     * @return int
     */
    virtual int maxProfit(vector<int> &prices) = 0;
};
} // namespace best_time_to_buy_and_sell_stock_iii

namespace random_pick_with_weight {
class Solution {
public:
    /**
     * @brief Construct a new Solution object 528 https://leetcode.cn/problems/random-pick-with-weight/
     *
     * @param w
     */
    Solution(vector<int> &w) {
    }

    virtual int pickIndex() = 0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
} // namespace random_pick_with_weight
namespace burst_balloons {
class Solution {
public:
    /**
     * @brief 312 https://leetcode.cn/problems/burst-balloons/
     *
     * @param nums
     * @return int
     */
    virtual int maxCoins(vector<int> &nums) = 0;
};
} // namespace burst_balloons
namespace avoid_flood_in_the_city {
class Solution {
public:
    /**
     * @brief 1488 https://leetcode.cn/problems/avoid-flood-in-the-city/
     *
     * @param rains
     * @return vector<int>
     */
    virtual vector<int> avoidFlood(vector<int> &rains) = 0;
};
} // namespace avoid_flood_in_the_city
namespace number_of_longest_increasing_subsequence {
class Solution {
public:
    /**
     * @brief 673 https://leetcode.cn/problems/number-of-longest-increasing-subsequence/
     *
     * @param nums
     * @return int
     */
    virtual int findNumberOfLIS(vector<int> &nums) = 0;
};
} // namespace number_of_longest_increasing_subsequence
namespace shu_de_zi_jie_gou_lcof {
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
        }
    };
    /**
     * @brief 剑指 Offer 26 https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/
     *
     * @param A
     * @param B
     * @return true
     * @return false
     */
    virtual bool isSubStructure(TreeNode *A, TreeNode *B) = 0;
};
} // namespace shu_de_zi_jie_gou_lcof
namespace max_points_on_a_line {
class Solution {
public:
    /**
     * @brief 149 https://leetcode.cn/problems/max-points-on-a-line/
     *
     * @param points
     * @return int
     */
    virtual int maxPoints(vector<vector<int>> &points) = 0;
};
} // namespace max_points_on_a_line

namespace house_robber_iii {
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
class Solution {
public:
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
     * @brief 337 https://leetcode.cn/problems/house-robber-iii/
     *
     * @param root
     * @return int
     */
    virtual int rob(TreeNode *root) = 0;
};
} // namespace house_robber_iii
namespace kth_largest_element_in_a_stream {
class KthLargest {
public:
    /**
     * @brief Construct a new Kth Largest object 703 https://leetcode.cn/problems/kth-largest-element-in-a-stream/
     *
     * @param k
     * @param nums
     */
    KthLargest(int k, vector<int> &nums) {
    }

    virtual int add(int val) = 0;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
} // namespace kth_largest_element_in_a_stream
namespace interleaving_string {
class Solution {
public:
    /**
     * @brief 97 https://leetcode.cn/problems/interleaving-string/
     *
     * @param s1
     * @param s2
     * @param s3
     * @return true
     * @return false
     */
    virtual bool isInterleave(string s1, string s2, string s3) = 0;
};
} // namespace interleaving_string
namespace yuan_quan_zhong_zui_hou_sheng_xia_de_shu_zi_lcof {
class Solution {
public:
    /**
     * @brief 剑指 Offer 62 https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
     *
     * @param n
     * @param m
     * @return int
     */
    virtual int lastRemaining(int n, int m) = 0;
};
} // namespace yuan_quan_zhong_zui_hou_sheng_xia_de_shu_zi_lcof
namespace merge_intervals {
class Solution {
public:
    /**
     * @brief 56 https://leetcode.cn/problems/merge-intervals/
     *
     * @param intervals
     * @return vector<vector<int>>
     */
    virtual vector<vector<int>> merge(vector<vector<int>> &intervals) = 0;
};
} // namespace merge_intervals
namespace compress_string_lcci {
class Solution {
public:
    /**
     * @brief 面试题 01.06 https://leetcode.cn/problems/compress-string-lcci/
     *
     * @param S
     * @return string
     */
    virtual string compressString(string S) = 0;
};
} // namespace compress_string_lcci
namespace shu_zu_zhong_chu_xian_ci_shu_chao_guo_yi_ban_de_shu_zi_lcof {
class Solution {
public:
    /**
     * @brief 剑指 Offer 39 https://leetcode.cn/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
     *
     * @param nums
     * @return int
     */
    virtual int majorityElement(vector<int> &nums) = 0;
};
} // namespace shu_zu_zhong_chu_xian_ci_shu_chao_guo_yi_ban_de_shu_zi_lcof
namespace longest_substring_with_at_least_k_repeating_characters {
class Solution {
public:
    /**
     * @brief 395 https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/
     *
     * @param s
     * @param k
     * @return int
     */
    virtual int longestSubstring(string s, int k) = 0;
};
} // namespace longest_substring_with_at_least_k_repeating_characters
namespace swap_nodes_in_pairs {
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
class Solution {
public:
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
    /**
     * @brief 24 https://leetcode.cn/problems/swap-nodes-in-pairs/
     *
     * @param head
     * @return ListNode*
     */
    virtual ListNode *swapPairs(ListNode *head) = 0;
};
} // namespace swap_nodes_in_pairs
namespace candy {
class Solution {
public:
    /**
     * @brief 135 https://leetcode.cn/problems/candy/
     *
     * @param ratings
     * @return int
     */
    virtual int candy(vector<int> &ratings) = 0;
};
} // namespace candy
namespace shortest_distance_to_a_character {
class Solution {
public:
    /**
     * @brief 821 https://leetcode.cn/problems/shortest-distance-to-a-character/
     *
     * @param s
     * @param c
     * @return vector<int>
     */
    virtual vector<int> shortestToChar(string s, char c) = 0;
};
} // namespace shortest_distance_to_a_character
namespace two_sum_ii_input_array_is_sorted {
class Solution {
public:
    /**
     * @brief 167 https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
     *
     * @param numbers
     * @param target
     * @return vector<int>
     */
    virtual vector<int> twoSum(vector<int> &numbers, int target) = 0;
};
} // namespace two_sum_ii_input_array_is_sorted

namespace string_compression {
class Solution {
public:
    /**
     * @brief 443 https://leetcode.cn/problems/string-compression/
     *
     * @param chars
     * @return int
     */
    virtual int compress(vector<char> &chars) = 0;
};
} // namespace string_compression
namespace binary_tree_postorder_traversal {
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
class Solution {
public:
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
     * @brief 145 https://leetcode.cn/problems/binary-tree-postorder-traversal/
     *
     * @param root
     * @return vector<int>
     */
    virtual vector<int> postorderTraversal(TreeNode *root) = 0;
};
} // namespace binary_tree_postorder_traversal
namespace implement_stack_using_queues {
class MyStack {
public:
    /**
     * @brief Construct a new My Stack object 225 https://leetcode.cn/problems/implement-stack-using-queues/
     *
     */
    MyStack() {
    }

    virtual void push(int x) = 0;

    virtual int pop() = 0;

    virtual int top() = 0;

    virtual bool empty() = 0;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
} // namespace implement_stack_using_queues
namespace maximum_swap {
class Solution {
public:
    /**
     * @brief 670 https://leetcode.cn/problems/maximum-swap/
     *
     * @param num
     * @return int
     */
    virtual int maximumSwap(int num) = 0;
};
} // namespace maximum_swap
namespace coin_change_2 {
class Solution {
public:
    /**
     * @brief 518 https://leetcode.cn/problems/coin-change-2/
     *
     * @param amount
     * @param coins
     * @return int
     */
    virtual int change(int amount, vector<int> &coins) = 0;
};
} // namespace coin_change_2
namespace permutation_in_string {
class Solution {
public:
    /**
     * @brief 567 https://leetcode.cn/problems/permutation-in-string/
     *
     * @param s1
     * @param s2
     * @return true
     * @return false
     */
    virtual bool checkInclusion(string s1, string s2) = 0;
};
} // namespace permutation_in_string
namespace powx_n {
class Solution {
public:
    /**
     * @brief 50 https://leetcode.cn/problems/powx-n
     *
     * @param x
     * @param n
     * @return double
     */
    virtual double myPow(double x, int n) = 0;
};
} // namespace powx_n

namespace reverse_integer {
class Solution {
public:
    /**
     * @brief 7 https://leetcode.cn/problems/reverse-integer/
     *
     * @param x
     * @return int
     */
    virtual int reverse(int x) = 0;
};
} // namespace reverse_integer
namespace rt_ao_a1hdf0h1_pa_vx_rj_fz_a {
string sub(string a, string b) {
    string res = "";
    int borrow = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0) {
        int x = i >= 0 ? a[i] - '0' : 0;
        int y = j >= 0 ? b[j] - '0' : 0;
        int z = (x - borrow - y + 10) % 10;
        res += '0' + z;
        borrow = x - borrow - y < 0 ? 1 : 0;
        i--, j--;
    }
    reverse(res.begin(), res.end());
    //删除前导0。循环条件是res.size()-1是为防止"0000"的情况
    int pos;
    for (pos = 0; pos < res.size() - 1; pos++) {
        if (res[pos] != '0') break;
    }
    return res.substr(pos);
}

bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

/**
 * @brief https://mp.weixin.qq.com/s/RtAoA1hdf0h1PaVxRj_fzA
 *
 * @param num1
 * @param num2
 * @return string
 */
string subStrings(string num1, string num2) {
    string res;
    if (cmp(num1, num2)) {
        res = sub(num2, num1);
        if (res != "0") res.insert(0, "-");
    } else
        res = sub(num1, num2);
    return res;
}

void test() {
    string a, b, c;
    cin >> a >> b;
    cout << subStrings(a, b) << endl;
}
} // namespace rt_ao_a1hdf0h1_pa_vx_rj_fz_a
namespace factorial_trailing_zeroes {
class Solution {
public:
    /**
     * @brief 172 https://leetcode.cn/problems/factorial-trailing-zeroes/
     *
     * @param n
     * @return int
     */
    virtual int trailingZeroes(int n) = 0;
};
} // namespace factorial_trailing_zeroes
namespace basic_calculator {
class Solution {
public:
    /**
     * @brief 224 https://leetcode.cn/problems/basic-calculator/
     *
     * @param s
     * @return int
     */
    virtual int calculate(string s) = 0;
};
} // namespace basic_calculator
namespace max_area_of_island {
class Solution {
public:
    /**
     * @brief 695 https://leetcode.cn/problems/max-area-of-island/
     *
     * @param grid
     * @return int
     */
    virtual int maxAreaOfIsland(vector<vector<int>> &grid) = 0;
};
} // namespace max_area_of_island
namespace remove_duplicate_letters {
class Solution {
public:
    /**
     * @brief 316 https://leetcode.cn/problems/remove-duplicate-letters/
     *
     * @param s
     * @return string
     */
    virtual string removeDuplicateLetters(string s) = 0;
};
} // namespace remove_duplicate_letters
namespace find_number_in_2d_array {
class Solution {
public:
    /**
     * @brief 剑指 Offer 04 https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
     *
     * @param matrix
     * @param target
     * @return true
     * @return false
     */
    virtual bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) = 0;
};
} // namespace find_number_in_2d_array
namespace is_subsequence {
class Solution {
public:
    /**
     * @brief 392 https://leetcode.cn/problems/is-subsequence/
     *
     * @param s
     * @param t
     * @return true
     * @return false
     */
    virtual bool isSubsequence(string s, string t) = 0;
};
} // namespace is_subsequence
namespace longest_palindrome_subseq {
class Solution {
public:
    /**
     * @brief 516 https://leetcode.cn/problems/longest-palindromic-subsequence/
     *
     * @param s
     * @return int
     */
    virtual int longestPalindromeSubseq(string s) = 0;
};
} // namespace longest_palindrome_subseq

namespace k_closest {
class Solution {
public:
    /**
     * @brief 973 https://leetcode.cn/problems/k-closest-points-to-origin/
     *
     * @param points
     * @param k
     * @return vector<vector<int>>
     */
    virtual vector<vector<int>> kClosest(vector<vector<int>> &points, int k) = 0;
};
} // namespace k_closest
namespace check_subarray_sum {
class Solution {
public:
    /**
     * @brief 523 https://leetcode.cn/problems/continuous-subarray-sum/
     *
     * @param nums
     * @param k
     * @return true
     * @return false
     */
    virtual bool checkSubarraySum(vector<int> &nums, int k) = 0;
};
} // namespace check_subarray_sum
namespace num_squares {
class Solution {
public:
    /**
     * @brief 279 https://leetcode.cn/problems/perfect-squares/
     *
     * @param n
     * @return int
     */
    virtual int numSquares(int n) = 0;
};
} // namespace num_squares
namespace three_sum_closest {
class Solution {
public:
    /**
     * @brief 16 https://leetcode.cn/problems/3sum-closest/
     *
     * @param nums
     * @param target
     * @return int
     */
    virtual int threeSumClosest(vector<int> &nums, int target) = 0;
};
} // namespace three_sum_closest
namespace hamming_weight {
class Solution {
public:
    /**
     * @brief 191 https://leetcode.cn/problems/number-of-1-bits/
     *
     * @param n
     * @return int
     */
    virtual int hammingWeight(uint32_t n) = 0;
};
} // namespace hamming_weight
namespace judge_square_sum {
class Solution {
public:
    /**
     * @brief 633 https://leetcode.cn/problems/sum-of-square-numbers/
     *
     * @param c
     * @return true
     * @return false
     */
    virtual bool judgeSquareSum(int c) = 0;
};
} // namespace judge_square_sum
namespace reverse_words {
class Solution {
public:
    /**
     * @brief 557 https://leetcode.cn/problems/reverse-words-in-a-string-iii/
     *
     * @param s
     * @return string
     */
    virtual string reverseWords(string s) = 0;
};
} // namespace reverse_words
namespace num_rabbits {
class Solution {
public:
    /**
     * @brief 781 https://leetcode.cn/problems/rabbits-in-forest/
     *
     * @param answers
     * @return int
     */
    virtual int numRabbits(vector<int> &answers) = 0;
};
} // namespace num_rabbits
namespace num_ways {
class Solution {
public:
    /**
     * @brief 剑指 Offer 10- II https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
     *
     * @param n
     * @return int
     */
    virtual int numWays(int n) = 0;
};
} // namespace num_ways
namespace max_profit {
class Solution {
public:
    /**
     * @brief 309 https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
     *
     * @param prices
     * @return int
     */
    virtual int maxProfit(vector<int> &prices) = 0;
};
} // namespace max_profit
namespace remove_duplicates {
class Solution {
public:
    /**
     * @brief 1047 https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
     *
     * @param s
     * @return string
     */
    virtual string removeDuplicates(string s) = 0;
};
} // namespace remove_duplicates

namespace implement_trie_prefix_tree {
class Trie {
public:
    /**
     * @brief Construct a new Trie object 208 https://leetcode.cn/problems/implement-trie-prefix-tree/
     *
     */
    Trie() {
    }

    virtual void insert(string word) = 0;
    virtual bool search(string word) = 0;

    virtual bool startsWith(string prefix) = 0;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
} // namespace implement_trie_prefix_tree
namespace container_with_most_water {
class Solution {
public:
    /**
     * @brief 11 https://leetcode.cn/problems/container-with-most-water/
     *
     * @param height
     * @return int
     */
    virtual int maxArea(vector<int> &height) = 0;
};
} // namespace container_with_most_water
namespace regular_expression_matching {
class Solution {
public:
    /**
     * @brief 10 https://leetcode.cn/problems/regular-expression-matching/
     *
     * @param s
     * @param p
     * @return true
     * @return false
     */
    virtual bool isMatch(string s, string p) = 0;
};
} // namespace regular_expression_matching
namespace find_median_from_data_stream {
class MedianFinder {
public:
    /**
     * @brief Construct a new Median Finder object 295 https://leetcode.cn/problems/find-median-from-data-stream/
     *
     */
    MedianFinder() {
    }

    virtual void addNum(int num) = 0;

    virtual double findMedian() = 0;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
} // namespace find_median_from_data_stream
namespace shortest_palindrome {
class Solution {
public:
    /**
     * @brief 214 https://leetcode.cn/problems/shortest-palindrome/
     *
     * @param s
     * @return string
     */
    virtual string shortestPalindrome(string s) = 0;
};
} // namespace shortest_palindrome

namespace best_time_to_buy_and_sell_stock_ii {
class Solution {
public:
    /**
     * @brief 122 https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
     *
     * @param prices
     * @return int
     */
    virtual int maxProfit(vector<int> &prices) = 0;
};
} // namespace best_time_to_buy_and_sell_stock_ii

namespace the_minimum_number_of_the_rotation_array {
class Solution {
public:
    /**
     * @brief 剑指 Offer 11 https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
     *
     * @param numbers
     * @return int
     */
    virtual int minArray(vector<int> &numbers) = 0;
};
} // namespace the_minimum_number_of_the_rotation_array
namespace number_of_provinces {
class Solution {
public:
    /**
     * @brief 547 https://leetcode.cn/problems/number-of-provinces/
     *
     * @param isConnected
     * @return int
     */
    virtual int findCircleNum(vector<vector<int>> &isConnected) = 0;
};
} // namespace number_of_provinces
namespace maximum_sum_of_consecutive_subarrays {
class Solution {
public:
    /**
     * @brief 剑指 Offer 42 https://leetcode.cn/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
     *
     * @param nums
     * @return int
     */
    virtual int maxSubArray(vector<int> &nums) = 0;
};
} // namespace maximum_sum_of_consecutive_subarrays
namespace partition_array_into_three_parts_with_equal_sum {
class Solution {
public:
    /**
     * @brief 1013 https://leetcode.cn/problems/partition-array-into-three-parts-with-equal-sum/
     *
     * @param arr
     * @return true
     * @return false
     */
    virtual bool canThreePartsEqualSum(vector<int> &arr) = 0;
};
} // namespace partition_array_into_three_parts_with_equal_sum
namespace one_away_lcci {
class Solution {
public:
    /**
     * @brief 面试题 01.05 https://leetcode.cn/problems/one-away-lcci/
     *
     * @param first
     * @param second
     * @return true
     * @return false
     */
    virtual bool oneEditAway(string first, string second) = 0;
};
} // namespace one_away_lcci
namespace remove_duplicates_from_sorted_list {
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
class Solution {
public:
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
    /**
     * @brief 83 https://leetcode.cn/problems/remove-duplicates-from-sorted-list/
     *
     * @param head
     * @return ListNode*
     */
    virtual ListNode *deleteDuplicates(ListNode *head) = 0;
};
} // namespace remove_duplicates_from_sorted_list
namespace the_smallest_k_numbers {
class Solution {
public:
    /**
     * @brief Get the Least Numbers object 剑指 Offer 40 https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/
     *
     * @param arr
     * @param k
     * @return vector<int>
     */
    virtual vector<int> getLeastNumbers(vector<int> &arr, int k) = 0;
};
} // namespace the_smallest_k_numbers

namespace a_sequence_of_continuous_positive_numbers_whose_sum_is_s {
class Solution {
public:
    /**
     * @brief 剑指 Offer 57 - II. https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
     *
     * @param target
     * @return vector<vector<int>>
     */
    virtual vector<vector<int>> findContinuousSequence(int target) = 0;
};
} // namespace a_sequence_of_continuous_positive_numbers_whose_sum_is_s
namespace zigzag_level_order {
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
class Solution {
public:
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
     * @brief 103 https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
     *
     * @param root
     * @return vector<vector<int>>
     */
    virtual vector<vector<int>> zigzagLevelOrder(TreeNode *root) = 0;
};
} // namespace zigzag_level_order
namespace intersection {
class Solution {
public:
    /**
     * @brief 349 https://leetcode.cn/problems/intersection-of-two-arrays/
     *
     * @param nums1
     * @param nums2
     * @return vector<int>
     */
    virtual vector<int> intersection(vector<int> &nums1, vector<int> &nums2) = 0;
};
} // namespace intersection
namespace median_sliding_window {
class Solution {
public:
    /**
     * @brief 480 https://leetcode.cn/problems/sliding-window-median/
     *
     * @param nums
     * @param k
     * @return vector<double>
     */
    virtual vector<double> medianSlidingWindow(vector<int> &nums, int k) = 0;
};
} // namespace median_sliding_window
namespace sum_numbers {
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
class Solution {
public:
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
     * @brief 129 https://leetcode.cn/problems/sum-root-to-leaf-numbers/
     *
     * @param root
     * @return int
     */
    virtual int sumNumbers(TreeNode *root) = 0;
};
} // namespace sum_numbers

namespace to_hex {
class Solution {
public:
    /**
     * @brief 405 https://leetcode.cn/problems/convert-a-number-to-hexadecimal/
     *
     * @param num
     * @return string
     */
    virtual string toHex(int num) = 0;
};
} // namespace to_hex

namespace path_sum {
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
class Solution {
public:
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
     * @brief 113 https://leetcode.cn/problems/path-sum-ii/
     *
     * @param root
     * @param targetSum
     * @return vector<vector<int>>
     */
    virtual vector<vector<int>> pathSum(TreeNode *root, int targetSum) = 0;
};
} // namespace path_sum

namespace next_permutation_solution {
class Solution {
public:
    /**
     * @brief 31. Next Permutation https://leetcode.cn/problems/next-permutation/
     *
     * @param nums
     */
    virtual void nextPermutation(vector<int> &nums) = 0;
};
} // namespace next_permutation_solution

namespace find_the_duplicate_number {
class Solution {
public:
    /**
     * @brief 287. Find the Duplicate Number https://leetcode.cn/problems/find-the-duplicate-number/
     *
     * @param nums
     * @return int
     */
    virtual int findDuplicate(vector<int> &nums) = 0;
};
} // namespace find_the_duplicate_number

namespace search_a_2d_matrix_ii {
class Solution {
public:
    /**
     * @brief 240. Search a 2D Matrix II https://leetcode.cn/problems/search-a-2d-matrix-ii/
     *
     * @param matrix
     * @param target
     * @return true
     * @return false
     */
    virtual bool searchMatrix(vector<vector<int>> &matrix, int target) = 0;
};
} // namespace search_a_2d_matrix_ii

namespace validate_ip_address {
class Solution {
public:
    /**
     * @brief 468. Validate IP Address https://leetcode.cn/problems/validate-ip-address/
     *
     * @param queryIP
     * @return string
     */
    virtual string validIPAddress(string queryIP) = 0;
};
} // namespace validate_ip_address

namespace first_missing_positive {
class Solution {
public:
    /**
     * @brief 41. First Missing Positive https://leetcode.cn/problems/first-missing-positive/
     *
     * @param nums
     * @return int
     */
    virtual int firstMissingPositive(vector<int> &nums) = 0;
};
} // namespace first_missing_positive

namespace binary_tree_level_order_traversal_ii {
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
class Solution {
public:
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
     * @brief 107. Binary Tree Level Order Traversal II https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
     *
     * @param root
     * @return vector<vector<int>>
     */
    virtual vector<vector<int>> levelOrderBottom(TreeNode *root) = 0;
};
} // namespace binary_tree_level_order_traversal_ii

namespace kth_smallest_element_in_a_sorted_matrix {
class Solution {
public:
    /**
     * @brief 378 https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/
     *
     * @param matrix
     * @param k
     * @return int
     */
    virtual int kthSmallest(vector<vector<int>> &matrix, int k) = 0;
};
} // namespace kth_smallest_element_in_a_sorted_matrix

namespace find_first_and_last_position_of_element_in_sorted_array {
class Solution {
public:
    /**
     * @brief 34 https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
     *
     * @param nums
     * @param target
     * @return vector<int>
     */
    virtual vector<int> searchRange(vector<int> &nums, int target) = 0;
};
} // namespace find_first_and_last_position_of_element_in_sorted_array

namespace distinct_subsequences {
class Solution {
public:
    /**
     * @brief 115 https://leetcode.cn/problems/distinct-subsequences/
     *
     * @param s
     * @param t
     * @return int
     */
    virtual int numDistinct(string s, string t) = 0;
};
} // namespace distinct_subsequences
namespace sudoku_solver {
class Solution {
public:
    /**
     * @brief 37 https://leetcode.cn/problems/sudoku-solver/
     *
     * @param board
     */
    virtual void solveSudoku(vector<vector<char>> &board) = 0;
};
} // namespace sudoku_solver
namespace top_k_frequent_words {
class Solution {
public:
    /**
     * @brief 692 https://leetcode.cn/problems/top-k-frequent-words/
     *
     * @param words
     * @param k
     * @return vector<string>
     */
    virtual vector<string> topKFrequent(vector<string> &words, int k) = 0;
};
} // namespace top_k_frequent_words
namespace jump_game {
class Solution {
public:
    /**
     * @brief 55 https://leetcode.cn/problems/jump-game/
     *
     * @param nums
     * @return true
     * @return false
     */
    virtual bool canJump(vector<int> &nums) = 0;
};
} // namespace jump_game
namespace reorder_list {
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
class Solution {
public:
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
    /**
     * @brief 143 https://leetcode.cn/problems/reorder-list/
     *
     * @param head
     */
    virtual void reorderList(ListNode *head) = 0;
};
} // namespace reorder_list
namespace unique_paths_ii {
class Solution {
public:
    /**
     * @brief 63 https://leetcode.cn/problems/unique-paths-ii/
     *
     * @param obstacleGrid
     * @return int
     */
    virtual int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) = 0;

    void test() {
    }

    void test_case1() {
    }
};
} // namespace unique_paths_ii
namespace invert_binary_tree {
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
class Solution {
public:
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
     * @brief 226 https://leetcode.cn/problems/invert-binary-tree/
     *
     * @param root
     * @return TreeNode*
     */
    virtual TreeNode *invertTree(TreeNode *root) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        // 示例 1：
        // 输入：root = [4,2,7,1,3,6,9]
        // 输出：[4,7,2,9,6,3,1]
        TreeNode *node1 = new TreeNode(4);
        TreeNode *node2 = new TreeNode(2);
        TreeNode *node3 = new TreeNode(7);
        TreeNode *node4 = new TreeNode(1);
        TreeNode *node5 = new TreeNode(3);
        TreeNode *node6 = new TreeNode(6);
        TreeNode *node7 = new TreeNode(9);
        node1->left = node2;
        node1->right = node3;
        node2->left = node4;
        node2->right = node5;
        node3->left = node6;
        node3->right = node7;

        TreeNode *root = node1;
        TreeNode *res = invertTree(root);
    }
    void test_case2() {
        // 示例 2：
        // 输入：root = [2,1,3]
        // 输出：[2,3,1]
        TreeNode *node1 = new TreeNode(2);
        TreeNode *node2 = new TreeNode(1);
        TreeNode *node3 = new TreeNode(3);
        node1->left = node2;
        node1->right = node3;

        TreeNode *root = node1;
        TreeNode *res = invertTree(root);
    }
    void test_case3() {
        // 示例 3：
        // 输入：root = []
        // 输出：[]
        TreeNode *root = nullptr;
        TreeNode *res = invertTree(root);
    }
};
} // namespace invert_binary_tree
namespace gas_station {
class Solution {
public:
    /**
     * @brief 134 https://leetcode.cn/problems/gas-station/
     *
     * @param gas
     * @param cost
     * @return int
     */
    virtual int canCompleteCircuit(vector<int> &gas, vector<int> &cost) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1:
        // 输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
        // 输出: 3
        // 解释:
        // 从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
        // 开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
        // 开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
        // 开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
        // 开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
        // 开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
        // 因此，3 可为起始索引。
        vector<int> gas = {1, 2, 3, 4, 5};
        vector<int> cost = {3, 4, 5, 1, 2};
        int res = canCompleteCircuit(gas, cost);
    }

    void test_case2() {
        // 示例 2:
        // 输入: gas = [2,3,4], cost = [3,4,3]
        // 输出: -1
        // 解释:
        // 你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
        // 我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
        // 开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
        // 开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
        // 你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
        // 因此，无论怎样，你都不可能绕环路行驶一周。
        vector<int> gas = {2, 3, 4};
        vector<int> cost = {3, 4, 3};
        int res = canCompleteCircuit(gas, cost);
    }
};
} // namespace gas_station
namespace remove_duplicates_from_sorted_array {
class Solution {
public:
    /**
     * @brief 26 https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
     *
     * @param nums
     * @return int
     */
    virtual int removeDuplicates(vector<int> &nums) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：nums = [1,1,2]
        // 输出：2, nums = [1,2,_]
        // 解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
        vector<int> nums = {1, 1, 2};
        int res = removeDuplicates(nums);
    }
    void test_case2() {
        // 示例 2：
        // 输入：nums = [0,0,1,1,1,2,2,3,3,4]
        // 输出：5, nums = [0,1,2,3,4]
        // 解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
        vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int res = removeDuplicates(nums);
    }
};
} // namespace remove_duplicates_from_sorted_array

namespace design_hash_map {
class MyHashMap {
public:
    /**
     * @brief Construct a new My Hash Map object 706 https://leetcode.cn/problems/design-hashmap/
     *
     */
    MyHashMap() {
    }

    virtual void put(int key, int value) = 0;

    virtual int get(int key) = 0;

    virtual void remove(int key) = 0;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
} // namespace design_hash_map

namespace minimum_path_sum {
class Solution {
public:
    /**
     * @brief 64 https://leetcode.cn/problems/minimum-path-sum/
     *
     * @param grid
     * @return int
     */
    virtual int minPathSum(vector<vector<int>> &grid) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
        // 输出：7
        // 解释：因为路径 1→3→1→1→1 的总和最小。
        vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
        int res = minPathSum(grid);
    }

    void test_case2() {
        // 示例 2：
        // 输入：grid = [[1,2,3],[4,5,6]]
        // 输出：12
        vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
        int res = minPathSum(grid);
    }
};
} // namespace minimum_path_sum
namespace implementing_a_queue_with_two_stacks {
class CQueue {
public:
    /**
     * @brief Construct a new CQueue object 剑指 Offer 09 https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
     *
     */
    CQueue() {
    }

    virtual void appendTail(int value) = 0;

    virtual int deleteHead() = 0;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
} // namespace implementing_a_queue_with_two_stacks

namespace remove_k_digits {
class Solution {
public:
    /**
     * @brief
     * 402. Remove K Digits https://leetcode.cn/problems/remove-k-digits/
     *
     * @param num
     * @param k
     * @return string
     */
    virtual string removeKdigits(string num, int k) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        // 示例 1 ：
        // 输入：num = "1432219", k = 3
        // 输出："1219"
        // 解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 。
        string num = "1432219";
        int k = 3;
        string res = removeKdigits(num, k);
    }
    void test_case2() {
        // 示例 2 ：
        // 输入：num = "10200", k = 1
        // 输出："200"
        // 解释：移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
        string num = "10200";
        int k = 1;
        string res = removeKdigits(num, k);
    }
    void test_case3() {
        // 示例 3 ：
        // 输入：num = "10", k = 2
        // 输出："0"
        // 解释：从原数字移除所有的数字，剩余为空就是 0 。
        string num = "10";
        int k = 2;
        string res = removeKdigits(num, k);
    }
};
} // namespace remove_k_digits

namespace sqrt_x {
class Solution {
public:
    /**
     * @brief
     * 69. Sqrt(x) https://leetcode.cn/problems/sqrtx/
     *
     * @param x
     * @return int
     */
    virtual int mySqrt(int x) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：x = 4
        // 输出：2
        int x = 4;
        int res = mySqrt(x);
    }
    void test_case2() {
        // 示例 2：
        // 输入：x = 8
        // 输出：2
        // 解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
        int x = 8;
        int res = mySqrt(x);
    }
};
} // namespace sqrt_x

namespace odd_even_linked_list {
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
class Solution {
public:
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
    /**
     * @brief
     * 328. Odd Even Linked List https://leetcode.cn/problems/odd-even-linked-list/
     *
     * @param head
     * @return ListNode*
     */
    virtual ListNode *oddEvenList(ListNode *head) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1:
        // 输入: head = [1,2,3,4,5]
        // 输出: [1,3,5,2,4]
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(3);
        ListNode *node4 = new ListNode(4);
        ListNode *node5 = new ListNode(5);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;

        ListNode *head = node1;
        ListNode *res = oddEvenList(head);
    }

    void test_case2() {
        // 示例 2:
        // 输入: head = [2,1,3,5,6,4,7]
        // 输出: [2,3,6,7,1,5,4]
        ListNode *node1 = new ListNode(2);
        ListNode *node2 = new ListNode(1);
        ListNode *node3 = new ListNode(3);
        ListNode *node4 = new ListNode(5);
        ListNode *node5 = new ListNode(6);
        ListNode *node6 = new ListNode(4);
        ListNode *node7 = new ListNode(7);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;
        node5->next = node6;
        node6->next = node7;

        ListNode *head = node1;
        ListNode *res = oddEvenList(head);
    }
};
} // namespace odd_even_linked_list

namespace unique_paths {
class Solution {
public:
    /**
     * @brief
     * 62. Unique Paths https://leetcode.cn/problems/unique-paths/
     *
     * @param m
     * @param n
     * @return int
     */
    virtual int uniquePaths(int m, int n) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
        test_case4();
    }

    void test_case1() {
        // 示例 1：
        // 输入：m = 3, n = 7
        // 输出：28
        int m = 3;
        int n = 7;
        int res = uniquePaths(m, n);
    }

    void test_case2() {
        // 示例 2：
        // 输入：m = 3, n = 2
        // 输出：3
        // 解释：
        // 从左上角开始，总共有 3 条路径可以到达右下角。
        // 1. 向右 -> 向下 -> 向下
        // 2. 向下 -> 向下 -> 向右
        // 3. 向下 -> 向右 -> 向下
        int m = 3;
        int n = 2;
        int res = uniquePaths(m, n);
    }

    void test_case3() {
        // 示例 3：
        // 输入：m = 7, n = 3
        // 输出：28
        int m = 7;
        int n = 3;
        int res = uniquePaths(m, n);
    }

    void test_case4() {
        // 示例 4：
        // 输入：m = 3, n = 3
        // 输出：6
        int m = 3;
        int n = 3;
        int res = uniquePaths(m, n);
    }
};
} // namespace unique_paths

namespace excel_sheet_column_number {
class Solution {
public:
    /**
     * @brief
     * 171. Excel Sheet Column Number https://leetcode.cn/problems/excel-sheet-column-number/
     *
     * @param columnTitle
     * @return int
     */
    virtual int titleToNumber(string columnTitle) = 0;

    // 例如：
    // A -> 1
    // B -> 2
    // C -> 3
    // ...
    // Z -> 26
    // AA -> 27
    // AB -> 28
    // ...

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        // 示例 1:
        // 输入: columnTitle = "A"
        // 输出: 1
        string columnTitle = "A";
        int res = titleToNumber(columnTitle);
    }
    void test_case2() {
        // 示例 2:
        // 输入: columnTitle = "AB"
        // 输出: 28
        string columnTitle = "AB";
        int res = titleToNumber(columnTitle);
    }
    void test_case3() {
        // 示例 3:
        // 输入: columnTitle = "ZY"
        // 输出: 701
        string columnTitle = "ZY";
        int res = titleToNumber(columnTitle);
    }
};
} // namespace excel_sheet_column_number

namespace middle_of_the_linked_list {
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
class Solution {
public:
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
    /**
     * @brief
     * 876. Middle of the Linked List https://leetcode.cn/problems/middle-of-the-linked-list/
     *
     * @param head
     * @return ListNode*
     */
    virtual ListNode *middleNode(ListNode *head) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：[1,2,3,4,5]
        // 输出：此列表中的结点 3 (序列化形式：[3,4,5])
        // 返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
        // 注意，我们返回了一个 ListNode 类型的对象 ans，这样：
        // ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(3);
        ListNode *node4 = new ListNode(4);
        ListNode *node5 = new ListNode(5);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;

        ListNode *head = node1;
        ListNode *res = middleNode(head);
    }

    void test_case2() {
        // 示例 2：
        // 输入：[1,2,3,4,5,6]
        // 输出：此列表中的结点 4 (序列化形式：[4,5,6])
        // 由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(3);
        ListNode *node4 = new ListNode(4);
        ListNode *node5 = new ListNode(5);
        ListNode *node6 = new ListNode(6);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;
        node5->next = node6;

        ListNode *head = node1;
        ListNode *res = middleNode(head);
    }
};
} // namespace middle_of_the_linked_list

namespace repeated_substring_pattern {
class Solution {
public:
    /**
     * @brief
     * 459. Repeated Substring Pattern https://leetcode.cn/problems/repeated-substring-pattern/
     *
     * @param s
     * @return true
     * @return false
     */
    virtual bool repeatedSubstringPattern(string s) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        // 示例 1:
        // 输入: s = "abab"
        // 输出: true
        // 解释: 可由子串 "ab" 重复两次构成。
        string s = "abab";
        bool res = repeatedSubstringPattern(s);
    }
    void test_case2() {
        // 示例 2:
        // 输入: s = "aba"
        // 输出: false
        string s = "aba";
        bool res = repeatedSubstringPattern(s);
    }
    void test_case3() {
        // 示例 3:
        // 输入: s = "abcabcabcabc"
        // 输出: true
        // 解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
        string s = "abcabcabcabc";
        bool res = repeatedSubstringPattern(s);
    }
};
} // namespace repeated_substring_pattern

namespace house_robber {
class Solution {
public:
    /**
     * @brief
     * 198. House Robber https://leetcode.cn/problems/house-robber/
     *
     * @param nums
     * @return int
     */
    virtual int rob(vector<int> &nums) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：[1,2,3,1]
        // 输出：4
        // 解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
        //      偷窃到的最高金额 = 1 + 3 = 4 。
        vector<int> nums = {1, 2, 3, 1};
        int res = rob(nums);
    }
    void test_case2() {
        // 示例 2：
        // 输入：[2,7,9,3,1]
        // 输出：12
        // 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
        //      偷窃到的最高金额 = 2 + 9 + 1 = 12 。
        vector<int> nums = {2, 7, 9, 3, 1};
        int res = rob(nums);
    }
};
} // namespace house_robber

namespace same_tree {
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
class Solution {
public:
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
     * @brief
     * 100. Same Tree https://leetcode.cn/problems/same-tree/
     *
     * @param p
     * @param q
     * @return true
     * @return false
     */
    virtual bool isSameTree(TreeNode *p, TreeNode *q) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        // 示例 1：
        // 输入：p = [1,2,3], q = [1,2,3]
        // 输出：true
        TreeNode *node1 = new TreeNode(1);
        TreeNode *node2 = new TreeNode(2);
        TreeNode *node3 = new TreeNode(3);
        node1->left = node2;
        node1->right = node3;

        TreeNode *node4 = new TreeNode(1);
        TreeNode *node5 = new TreeNode(2);
        TreeNode *node6 = new TreeNode(3);
        node4->left = node5;
        node4->right = node6;

        TreeNode *p = node1;
        TreeNode *q = node4;
        bool res = isSameTree(p, q);
    }

    void test_case2() {
        // 示例 2：
        // 输入：p = [1,2], q = [1,null,2]
        // 输出：false
        TreeNode *node1 = new TreeNode(1);
        TreeNode *node2 = new TreeNode(2);
        node1->left = node2;

        TreeNode *node3 = new TreeNode(1);
        TreeNode *node4 = new TreeNode(2);
        node3->right = node4;

        TreeNode *p = node1;
        TreeNode *q = node3;
        bool res = isSameTree(p, q);
    }
    void test_case3() {
        // 示例 3：
        // 输入：p = [1,2,1], q = [1,1,2]
        // 输出：false
        TreeNode *node1 = new TreeNode(1);
        TreeNode *node2 = new TreeNode(2);
        TreeNode *node3 = new TreeNode(1);
        node1->left = node2;
        node1->right = node3;

        TreeNode *node4 = new TreeNode(1);
        TreeNode *node5 = new TreeNode(1);
        TreeNode *node6 = new TreeNode(2);
        node4->left = node5;
        node4->right = node6;

        TreeNode *p = node1;
        TreeNode *q = node4;
        bool res = isSameTree(p, q);
    }
};
} // namespace same_tree

namespace rotate_array {
class Solution {
public:
    /**
     * @brief
     * 189. Rotate Array https://leetcode.cn/problems/rotate-array/
     *
     * @param nums
     * @param k
     */
    virtual void rotate(vector<int> &nums, int k) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1:
        // 输入: nums = [1,2,3,4,5,6,7], k = 3
        // 输出: [5,6,7,1,2,3,4]
        // 解释:
        // 向右轮转 1 步: [7,1,2,3,4,5,6]
        // 向右轮转 2 步: [6,7,1,2,3,4,5]
        // 向右轮转 3 步: [5,6,7,1,2,3,4]
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
        int k = 3;
        rotate(nums, k);
    }

    void test_case2() {
        // 示例 2:
        // 输入：nums = [-1,-100,3,99], k = 2
        // 输出：[3,99,-1,-100]
        // 解释:
        // 向右轮转 1 步: [99,-1,-100,3]
        // 向右轮转 2 步: [3,99,-1,-100]
        vector<int> nums = {-1, -100, 3, 99};
        int k = 2;
        rotate(nums, k);
    }
};
} // namespace rotate_array

namespace maximum_length_of_repeated_subarray {
class Solution {
public:
    /**
     * @brief
     * 718. Maximum Length of Repeated Subarray https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
     *
     * @param nums1
     * @param nums2
     * @return int
     */
    virtual int findLength(vector<int> &nums1, vector<int> &nums2) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
        // 输出：3
        // 解释：长度最长的公共子数组是 [3,2,1] 。
        vector<int> nums1 = {1, 2, 3, 2, 1};
        vector<int> nums2 = {3, 2, 1, 4, 7};
        int res = findLength(nums1, nums2);
    }

    void test_case2() {
        // 示例 2：
        // 输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
        // 输出：5
        vector<int> nums1 = {0, 0, 0, 0, 0};
        vector<int> nums2 = {0, 0, 0, 0, 0};
        int res = findLength(nums1, nums2);
    }
};
} // namespace maximum_length_of_repeated_subarray

namespace restore_ip_addresses {
class Solution {
public:
    /**
     * @brief
     * 93. Restore IP Addresses https://leetcode.cn/problems/restore-ip-addresses/
     *
     * @param s
     * @return vector<string>
     */
    virtual vector<string> restoreIpAddresses(string s) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        // 示例 1：
        // 输入：s = "25525511135"
        // 输出：["255.255.11.135","255.255.111.35"]
        string s = "25525511135";
        vector<string> res = restoreIpAddresses(s);
    }
    void test_case2() {
        // 示例 2：
        // 输入：s = "0000"
        // 输出：["0.0.0.0"]
        string s = "0000";
        vector<string> res = restoreIpAddresses(s);
    }
    void test_case3() {
        // 示例 3：
        // 输入：s = "101023"
        // 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
        string s = "101023";
        vector<string> res = restoreIpAddresses(s);
    }
};
} // namespace restore_ip_addresses

namespace minimum_window_substring {
class Solution {
public:
    /**
     * @brief
     * 76. Minimum Window Substring https://leetcode.cn/problems/minimum-window-substring/
     *
     * @param s
     * @param t
     * @return string
     */
    virtual string minWindow(string s, string t) = 0;
    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        // 示例 1：
        // 输入：s = "ADOBECODEBANC", t = "ABC"
        // 输出："BANC"
        string s = "ADOBECODEBANC";
        string t = "ABC";
        string res = minWindow(s, t);
    }
    void test_case2() {
        // 示例 2：
        // 输入：s = "a", t = "a"
        // 输出："a"
        string s = "a";
        string t = "a";
        string res = minWindow(s, t);
    }
    void test_case3() {
        // 示例 3:
        // 输入: s = "a", t = "aa"
        // 输出: ""
        // 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
        // 因此没有符合条件的子字符串，返回空字符串。
        string s = "a";
        string t = "aa";
        string res = minWindow(s, t);
    }
};
} // namespace minimum_window_substring

namespace remove_duplicates_from_sorted_list_ii {
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
class Solution {
public:
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
    /**
     * @brief
     * 82. Remove Duplicates from Sorted List II https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/
     *
     * @param head
     * @return ListNode*
     */
    virtual ListNode *deleteDuplicates(ListNode *head) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：head = [1,2,3,3,4,4,5]
        // 输出：[1,2,5]
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(3);
        ListNode *node4 = new ListNode(3);
        ListNode *node5 = new ListNode(4);
        ListNode *node6 = new ListNode(4);
        ListNode *node7 = new ListNode(5);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;
        node5->next = node6;
        node6->next = node7;

        ListNode *head = node1;
        ListNode *res = deleteDuplicates(head);
    }

    void test_case2() {
        // 示例 2：
        // 输入：head = [1,1,1,2,3]
        // 输出：[2,3]
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(1);
        ListNode *node3 = new ListNode(1);
        ListNode *node4 = new ListNode(2);
        ListNode *node5 = new ListNode(3);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;

        ListNode *head = node1;
        ListNode *res = deleteDuplicates(head);
    }
};
} // namespace remove_duplicates_from_sorted_list_ii

// namespace sort_an_array {
// class Solution {
// public:
//     vector<int> sortArray(vector<int> &nums) {
//     }
// };
// } // namespace sort_an_array

namespace search_a_2d_matrix {
class Solution {
public:
    /**
     * @brief
     * 74. Search a 2D Matrix https://leetcode.cn/problems/search-a-2d-matrix/
     *
     * @param matrix
     * @param target
     * @return true
     * @return false
     */
    virtual bool searchMatrix(vector<vector<int>> &matrix, int target) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
        // 输出：true
        vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
        int target = 3;
        bool res = searchMatrix(matrix, target);
    }

    void test_case2() {
        // 示例 2：
        // 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
        // 输出：false
        vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
        int target = 13;
        bool res = searchMatrix(matrix, target);
    }
};
} // namespace search_a_2d_matrix

namespace edit_distance {
class Solution {
public:
    /**
     * @brief
     * 72. Edit Distance https://leetcode.cn/problems/edit-distance/
     *
     * @param word1
     * @param word2
     * @return int
     */
    virtual int minDistance(string word1, string word2) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：word1 = "horse", word2 = "ros"
        // 输出：3
        // 解释：
        // horse -> rorse (将 'h' 替换为 'r')
        // rorse -> rose (删除 'r')
        // rose -> ros (删除 'e')
        string word1 = "horse";
        string word2 = "ros";
        int res = minDistance(word1, word2);
    }
    void test_case2() {
        // 示例 2：
        // 输入：word1 = "intention", word2 = "execution"
        // 输出：5
        // 解释：
        // intention -> inention (删除 't')
        // inention -> enention (将 'i' 替换为 'e')
        // enention -> exention (将 'n' 替换为 'x')
        // exention -> exection (将 'n' 替换为 'c')
        // exection -> execution (插入 'u')
        string word1 = "intention";
        string word2 = "execution";
        int res = minDistance(word1, word2);
    }
};
} // namespace edit_distance

namespace construct_binary_tree_from_preorder_and_inorder_traversal {
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
class Solution {
public:
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
     * @brief
     * 105. Construct Binary Tree from Preorder and Inorder Traversal https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
     * @param preorder
     * @param inorder
     * @return TreeNode*
     */
    virtual TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1:
        // 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
        // 输出: [3,9,20,null,null,15,7]
        vector<int> preorder = {3, 9, 20, 15, 7};
        vector<int> inorder = {9, 3, 15, 20, 7};
        TreeNode *res = buildTree(preorder, inorder);
    }

    void test_case2() {
        // 示例 2:
        // 输入: preorder = [-1], inorder = [-1]
        // 输出: [-1]
        vector<int> preorder = {-1};
        vector<int> inorder = {-1};
        TreeNode *res = buildTree(preorder, inorder);
    }
};
} // namespace construct_binary_tree_from_preorder_and_inorder_traversal

namespace longest_common_prefix {
class Solution {
public:
    /**
     * @brief
     * 14. Longest Common Prefix https://leetcode.cn/problems/longest-common-prefix/
     *
     * @param strs
     * @return string
     */
    virtual string longestCommonPrefix(vector<string> &strs) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：strs = ["flower","flow","flight"]
        // 输出："fl"
        vector<string> strs = {"flower", "flow", "flight"};
        string res = longestCommonPrefix(strs);
    }

    void test_case2() {
        // 示例 2：
        // 输入：strs = ["dog","racecar","car"]
        // 输出：""
        // 解释：输入不存在公共前缀。
        vector<string> strs = {"dog", "racecar", "car"};
        string res = longestCommonPrefix(strs);
    }
};

} // namespace longest_common_prefix

namespace design_circular_queue {
class MyCircularQueue {
public:
    /**
     * @brief Construct a new My Circular Queue object
     * 622. Design Circular Queue https://leetcode.cn/problems/design-circular-queue/
     *
     * @param k
     */
    MyCircularQueue(int k) {
    }

    virtual bool enQueue(int value) = 0;

    virtual bool deQueue() = 0;

    virtual int Front() = 0;

    virtual int Rear() = 0;

    virtual bool isEmpty() = 0;

    virtual bool isFull() = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
} // namespace design_circular_queue

class reverseLinkedListIi {
public:
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
    /**
     * @brief
     * 92. Reverse Linked List II https://leetcode.cn/problems/reverse-linked-list-ii/
     *
     * @param head
     * @param left
     * @param right
     * @return ListNode*
     */
    virtual ListNode *reverseBetween(ListNode *head, int left, int right) = 0;
    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：head = [1,2,3,4,5], left = 2, right = 4
        // 输出：[1,4,3,2,5]
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(3);
        ListNode *node4 = new ListNode(4);
        ListNode *node5 = new ListNode(5);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;

        ListNode *head = node1;
        int left = 2;
        int right = 4;
        ListNode *res = reverseBetween(head, left, right);
    }

    void test_case2() {
        // 示例 2：
        // 输入：head = [5], left = 1, right = 1
        // 输出：[5]
        ListNode *node1 = new ListNode(5);

        ListNode *head = node1;
        int left = 1;
        int right = 1;
        ListNode *res = reverseBetween(head, left, right);
    }
};

class superEggDropQ {
public:
    /**
     * @brief
     * 887. Super Egg Drop https://leetcode.cn/problems/super-egg-drop/
     *
     * @param k
     * @param n
     * @return int
     */
    virtual int superEggDrop(int k, int n) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        // 示例 1：
        // 输入：k = 1, n = 2
        // 输出：2
        // 解释：
        // 鸡蛋从 1 楼掉落。如果它碎了，肯定能得出 f = 0 。
        // 否则，鸡蛋从 2 楼掉落。如果它碎了，肯定能得出 f = 1 。
        // 如果它没碎，那么肯定能得出 f = 2 。
        // 因此，在最坏的情况下我们需要移动 2 次以确定 f 是多少。
        int k = 1;
        int n = 2;
        int res = superEggDrop(k, n);
    }

    void test_case2() {
        // 示例 2：
        // 输入：k = 2, n = 6
        // 输出：3
        int k = 2;
        int n = 6;
        int res = superEggDrop(k, n);
    }

    void test_case3() {
        // 示例 3：
        // 输入：k = 3, n = 14
        // 输出：4
        int k = 3;
        int n = 14;
        int res = superEggDrop(k, n);
    }
};

class rotateList {
public:
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
    /**
     * @brief
     * 61. Rotate List https://leetcode.cn/problems/rotate-list/
     *
     * @param head
     * @param k
     * @return ListNode*
     */
    virtual ListNode *rotateRight(ListNode *head, int k) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：head = [1,2,3,4,5], k = 2
        // 输出：[4,5,1,2,3]
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(3);
        ListNode *node4 = new ListNode(4);
        ListNode *node5 = new ListNode(5);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;

        ListNode *head = node1;
        int k = 2;
        ListNode *res = rotateRight(head, k);
    }

    void test_case2() {
        // 示例 2：
        // 输入：head = [0,1,2], k = 4
        // 输出：[2,0,1]
        ListNode *node1 = new ListNode(0);
        ListNode *node2 = new ListNode(1);
        ListNode *node3 = new ListNode(2);
        node1->next = node2;
        node2->next = node3;

        ListNode *head = node1;
        int k = 4;
        ListNode *res = rotateRight(head, k);
    }
};

class largestNumberBase {
public:
    /**
     * @brief
     * 179. Largest Number https://leetcode.cn/problems/largest-number/
     *
     * @param nums
     * @return string
     */
    virtual string largestNumber(vector<int> &nums) = 0;
    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：nums = [10,2]
        // 输出："210"
        vector<int> nums = {10, 2};
        string res = largestNumber(nums);
    }

    void test_case2() {
        // 示例 2：
        // 输入：nums = [3,30,34,5,9]
        // 输出："9534330"
        vector<int> nums = {3, 30, 34, 5, 9};
        string res = largestNumber(nums);
    }
};

class sortColorsQ {
public:
    /**
     * @brief
     * 75. Sort Colors https://leetcode.cn/problems/sort-colors/
     *
     * @param nums
     */
    virtual void sortColors(vector<int> &nums) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：nums = [2,0,2,1,1,0]
        // 输出：[0,0,1,1,2,2]
        vector<int> nums = {2, 0, 2, 1, 1, 0};
        sortColors(nums);
    }

    void test_case2() {
        // 示例 2：
        // 输入：nums = [2,0,1]
        // 输出：[0,1,2]
        vector<int> nums = {2, 0, 1};
        sortColors(nums);
    }
};

class longestConsecutiveSequence {
public:
    /**
     * @brief
     * 128. Longest Consecutive Sequence https://leetcode.cn/problems/longest-consecutive-sequence/
     *
     * @param nums
     * @return int
     */
    virtual int longestConsecutive(vector<int> &nums) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：nums = [100,4,200,1,3,2]
        // 输出：4
        // 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
        vector<int> nums = {100, 4, 200, 1, 3, 2};
        int res = longestConsecutive(nums);
    }

    void test_case2() {
        // 示例 2：
        // 输入：nums = [0,3,7,2,5,8,4,6,0,1]
        // 输出：9
        vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        int res = longestConsecutive(nums);
    }
};

class checkCircularDependencies {
public:
    /**
     * @brief
     * 补充题：检测循环依赖 https://mp.weixin.qq.com/s/pCRscwKqQdYYN7M1Sia7xA
     *
     * @param n
     * @param prerequisites
     * @return vector<int>
     */
    vector<int> haveCircularDependency(int n, vector<vector<int>> &prerequisites) {
        vector<vector<int>> g(n); //邻接表存储图结构
        vector<int> indeg(n);     //每个点的入度
        vector<int> res;          //存储结果序列
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0], b = prerequisites[i][1];
            g[a].push_back(b);
            indeg[b]++;
        }
        queue<int> q;
        //一次性将入度为0的点全部入队
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) q.push(i);
        }
        while (q.size()) {
            int t = q.front();
            q.pop();
            res.push_back(t);
            //删除边时，将终点的入度-1。若入度为0，果断入队
            for (int i = 0; i < g[t].size(); i++) {
                int j = g[t][i];
                indeg[j]--;
                if (indeg[j] == 0) {
                    q.push(j);
                }
            }
        }
        if (res.size() == n)
            return res;
        else
            return {};
    }

    void test() {
        test_case1();
    }

    void test_case1() {
        // 依赖关系是[[0,2],[1,2],[2,3],[2,4]]
        int n = 5;
        vector<vector<int>> prerequisites = {{0, 2}, {1, 2}, {2, 3}, {2, 4}};
        vector<int> res = haveCircularDependency(n, prerequisites);
    }
};

class spiralMatrixIi {
public:
    /**
     * @brief
     * 59. Spiral Matrix II https://leetcode.cn/problems/spiral-matrix-ii/
     *
     * @param n
     * @return vector<vector<int>>
     */
    virtual vector<vector<int>> generateMatrix(int n) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：n = 3
        // 输出：[[1,2,3],[8,9,4],[7,6,5]]
        int n = 3;
        vector<vector<int>> res = generateMatrix(n);
    }
    void test_case2() {
        // 示例 2：
        // 输入：n = 1
        // 输出：[[1]]
        int n = 1;
        vector<vector<int>> res = generateMatrix(n);
    }
};

class palindromeNumber {
public:
    /**
     * @brief
     * 9. Palindrome Number https://leetcode.cn/problems/palindrome-number/
     *
     * @param x
     * @return true
     * @return false
     */
    virtual bool isPalindrome(int x) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        // 示例 1：
        // 输入：x = 121
        // 输出：true
        int x = 121;
        bool res = isPalindrome(x);
    }

    void test_case2() {
        // 示例 2：
        // 输入：x = -121
        // 输出：false
        // 解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
        int x = -121;
        bool res = isPalindrome(x);
    }

    void test_case3() {
        // 示例 3：
        // 输入：x = 10
        // 输出：false
        // 解释：从右向左读, 为 01 。因此它不是一个回文数。
        int x = 10;
        bool res = isPalindrome(x);
    }
};

class contiguousArray {
public:
    /**
     * @brief
     * 525. Contiguous Array https://leetcode.cn/problems/contiguous-array/
     *
     * @param nums
     * @return int
     */
    virtual int findMaxLength(vector<int> &nums) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1:
        // 输入: nums = [0,1]
        // 输出: 2
        // 说明: [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
        vector<int> nums = {0, 1};
        int res = findMaxLength(nums);
    }

    void test_case2() {
        // 示例 2:
        // 输入: nums = [0,1,0]
        // 输出: 2
        // 说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
        vector<int> nums = {0, 1, 0};
        int res = findMaxLength(nums);
    }
};

class removeNthNodeFromEndOfList {
public:
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
    /**
     * @brief
     * 19. Remove Nth Node From End of List https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
     *
     * @param head
     * @param n
     * @return ListNode*
     */
    virtual ListNode *removeNthFromEnd(ListNode *head, int n) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        // 示例 1：
        // 输入：head = [1,2,3,4,5], n = 2
        // 输出：[1,2,3,5]
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(3);
        ListNode *node4 = new ListNode(4);
        ListNode *node5 = new ListNode(5);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;

        ListNode *head = node1;
        int n = 2;
        ListNode *res = removeNthFromEnd(head, n);
    }

    void test_case2() {
        // 示例 2：
        // 输入：head = [1], n = 1
        // 输出：[]
        ListNode *node1 = new ListNode(1);

        ListNode *head = node1;
        int n = 1;
        ListNode *res = removeNthFromEnd(head, n);
    }

    void test_case3() {
        // 示例 3：
        // 输入：head = [1,2], n = 1
        // 输出：[1]
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(2);
        node1->next = node2;

        ListNode *head = node1;
        int n = 1;
        ListNode *res = removeNthFromEnd(head, n);
    }
};

class compareVersionNumbers {
public:
    /**
     * @brief
     * 165. Compare Version Numbers https://leetcode.cn/problems/compare-version-numbers/
     *
     * @param version1
     * @param version2
     * @return int
     */
    virtual int compareVersion(string version1, string version2) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        // 示例 1：
        // 输入：version1 = "1.01", version2 = "1.001"
        // 输出：0
        // 解释：忽略前导零，"01" 和 "001" 都表示相同的整数 "1"
        string version1 = "1.01";
        string version2 = "1.001";
        int res = compareVersion(version1, version2);
    }

    void test_case2() {
        // 示例 2：
        // 输入：version1 = "1.0", version2 = "1.0.0"
        // 输出：0
        // 解释：version1 没有指定下标为 2 的修订号，即视为 "0"
        string version1 = "1.0";
        string version2 = "1.0.0";
        int res = compareVersion(version1, version2);
    }

    void test_case3() {
        // 示例 3：
        // 输入：version1 = "0.1", version2 = "1.1"
        // 输出：-1
        // 解释：version1 中下标为 0 的修订号是 "0"，version2 中下标为 0 的修订号是 "1" 。0 < 1，所以 version1 < version2
        string version1 = "0.1";
        string version2 = "1.1";
        int res = compareVersion(version1, version2);
    }
};

class decodeStringQ {
public:
    /**
     * @brief
     * 394. Decode String https://leetcode.cn/problems/decode-string/
     *
     * @param s
     * @return string
     */
    virtual string decodeString(string s) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
        test_case4();
    }

    void test_case1() {
        // 示例 1：
        // 输入：s = "3[a]2[bc]"
        // 输出："aaabcbc"
        string s = "3[a]2[bc]";
        string res = decodeString(s);
    }

    void test_case2() {
        // 示例 2：
        // 输入：s = "3[a2[c]]"
        // 输出："accaccacc"
        string s = "3[a2[c]]";
        string res = decodeString(s);
    }

    void test_case3() {
        // 示例 3：
        // 输入：s = "2[abc]3[cd]ef"
        // 输出："abcabccdcdcdef"
        string s = "2[abc]3[cd]ef";
        string res = decodeString(s);
    }

    void test_case4() {
        // 示例 4：
        // 输入：s = "abc3[cd]xyz"
        // 输出："abccdcdcdxyz"
        string s = "abc3[cd]xyz";
        string res = decodeString(s);
    }
};

class mergeSortedArray {
public:
    /**
     * @brief
     * 88. Merge Sorted Array https://leetcode.cn/problems/merge-sorted-array/
     *
     * @param nums1
     * @param m
     * @param nums2
     * @param n
     */
    virtual void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        // 示例 1：
        // 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
        // 输出：[1,2,2,3,5,6]
        // 解释：需要合并 [1,2,3] 和 [2,5,6] 。
        // 合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。

        vector<int> nums1 = {1, 2, 3, 0, 0, 0};
        int m = 3;
        vector<int> nums2 = {2, 5, 6};
        int n = 3;
        merge(nums1, m, nums2, n);
    }

    void test_case2() {
        // 示例 2：
        // 输入：nums1 = [1], m = 1, nums2 = [], n = 0
        // 输出：[1]
        // 解释：需要合并 [1] 和 [] 。
        // 合并结果是 [1] 。

        vector<int> nums1 = {1};
        int m = 1;
        vector<int> nums2 = {};
        int n = 0;
        merge(nums1, m, nums2, n);
    }

    void test_case3() {
        // 示例 3：
        // 输入：nums1 = [0], m = 0, nums2 = [1], n = 1
        // 输出：[1]
        // 解释：需要合并的数组是 [] 和 [1] 。
        // 合并结果是 [1] 。
        // 注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。

        vector<int> nums1 = {0};
        int m = 0;
        vector<int> nums2 = {1};
        int n = 1;
        merge(nums1, m, nums2, n);
    }
};

class majorityElementQ {
public:
    /**
     * @brief
     * 169. Majority Element https://leetcode.cn/problems/majority-element/
     *
     * @param nums
     * @return int
     */
    virtual int majorityElement(vector<int> &nums) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 示例 1：
        // 输入：nums = [3,2,3]
        // 输出：3

        vector<int> nums = {3, 2, 3};
        int res = majorityElement(nums);
    }

    void test_case2() {
        // 示例 2：
        // 输入：nums = [2,2,1,1,1,2,2]
        // 输出：2
        vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
        int res = majorityElement(nums);
    }
};

class convertsTheIpAddressToADecimalInteger {
public:
    /**
     * @brief
     * Converts the IP address to a decimal integer https://mp.weixin.qq.com/s/UWCuEtNS2kuAuDY-eIbghg
     *
     */
    void test() {
        string ip;
        unsigned num;
        while (cin >> ip) {
            cin >> num;
            cout << ipToInt(ip) << endl;
            cout << intToIp(num) << endl;
        }
    }
    unsigned ipToInt(string ip) {
        int l = ip.size();
        vector<int> ipList;
        // split
        for (int i = 0; i < l; i++) {
            int j = i;
            while (j < l && ip[j] != '.') j++;
            ipList.push_back(stoi(ip.substr(i, j - i)));
            i = j;
        }
        int n = ipList.size();
        unsigned res = 0;
        for (int i = 0; i < n; i++) {
            res = res << 8 | ipList[i];
        }
        return res;
    }

    string intToIp(unsigned num) {
        vector<string> ipList;
        string res = "";
        for (int i = 0; i < 4; i++) {
            string seg = to_string(num & 255);
            ipList.push_back(seg);
            num = num >> 8;
        }
        reverse(ipList.begin(), ipList.end());
        for (int i = 0; i < 4; i++) {
            if (i == 3)
                res += ipList[i];
            else
                res += ipList[i] + '.';
        }
        return res;
    }
};

class binaryTreeRightSideView {
public:
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
     * @brief
     * 199. Binary Tree Right Side View https://leetcode.cn/problems/binary-tree-right-side-view/
     *
     * @param root
     * @return vector<int>
     */
    virtual vector<int> rightSideView(TreeNode *root) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        // 示例 1:
        // 输入: [1,2,3,null,5,null,4]
        // 输出: [1,3,4]
        TreeNode *node1 = new TreeNode(1);
        TreeNode *node2 = new TreeNode(2);
        TreeNode *node3 = new TreeNode(3);
        TreeNode *node4 = new TreeNode(5);
        TreeNode *node5 = new TreeNode(4);
        node1->left = node2;
        node1->right = node3;
        node2->right = node4;
        node3->right = node5;

        TreeNode *root = node1;
        vector<int> res = rightSideView(root);
    }

    void test_case2() {
        // 示例 2:
        // 输入: [1,null,3]
        // 输出: [1,3]
        TreeNode *node1 = new TreeNode(1);
        TreeNode *node2 = new TreeNode(3);
        node1->right = node2;

        TreeNode *root = node1;
        vector<int> res = rightSideView(root);
    }

    void test_case3() {
        // 示例 3:
        // 输入: []
        // 输出: []

        TreeNode *root = nullptr;
        vector<int> res = rightSideView(root);
    }
};

class houseRobberIi {
public:
    /**
     * @brief
     * 213. House Robber II https://leetcode.cn/problems/house-robber-ii/
     *
     * @param nums
     * @return int
     */
    virtual int rob(vector<int> &nums) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        // 示例 1：
        // 输入：nums = [2,3,2]
        // 输出：3
        // 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

        vector<int> nums = {2, 3, 2};
        int res = rob(nums);
    }

    void test_case2() {
        // 示例 2：
        // 输入：nums = [1,2,3,1]
        // 输出：4
        // 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
        //      偷窃到的最高金额 = 1 + 3 = 4 。

        vector<int> nums = {1, 2, 3, 1};
        int res = rob(nums);
    }

    void test_case3() {
        // 示例 3：
        // 输入：nums = [1,2,3]
        // 输出：3

        vector<int> nums = {1, 2, 3};
        int res = rob(nums);
    }
};

class copyListWithRandomPointer {
public:
    class Node {
    public:
        int val;
        Node *next;
        Node *random;

        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
    };
    /**
     * @brief
     * 138. Copy List with Random Pointer https://leetcode.cn/problems/copy-list-with-random-pointer/
     *
     * @param head
     * @return Node*
     */
    virtual Node *copyRandomList(Node *head) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        // 示例 1：
        // 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
        //                  0        1      2      3     4
        //                 node1   node2   node3  node4  node5
        // 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
        Node *node1 = new Node(7);
        Node *node2 = new Node(13);
        Node *node3 = new Node(11);
        Node *node4 = new Node(10);
        Node *node5 = new Node(1);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;
        node1->random = nullptr;
        node2->random = node1;
        node3->random = node5;
        node4->random = node3;
        node5->random = node1;

        Node *head = node1;
        Node *res = copyRandomList(head);
    }
    void test_case2() {
        // 示例 2：
        // 输入：head = [[1,1],[2,1]]
        //                 0     1
        //               node1  node2
        // 输出：[[1,1],[2,1]]
        Node *node1 = new Node(1);
        Node *node2 = new Node(2);
        node1->next = node2;
        node1->random = node2;
        node2->random = node2;

        Node *head = node1;
        Node *res = copyRandomList(head);
    }
    void test_case3() {
        // 示例 3：
        // 输入：head = [[3,null],[3,0],[3,null]]
        //                  0       1      2
        //                node1   node2  node3
        // 输出：[[3,null],[3,0],[3,null]]
        Node *node1 = new Node(3);
        Node *node2 = new Node(3);
        Node *node3 = new Node(3);
        node1->next = node2;
        node2->next = node3;
        node1->random = nullptr;
        node2->random = node1;
        node3->random = nullptr;

        Node *head = node1;
        Node *res = copyRandomList(head);
    }
};

class generateParentheses {
public:
    /**
     * @brief
     * 22. Generate Parentheses https://leetcode.cn/problems/generate-parentheses/
     *
     * @param n
     * @return vector<string>
     */
    virtual vector<string> generateParenthesis(int n) = 0;

    void test() {
        test_case1();
        test_case2();
    }
    void test_case1() {
        // 示例 1：
        // 输入：n = 3
        // 输出：["((()))","(()())","(())()","()(())","()()()"]
        int n = 3;
        vector<string> res = generateParenthesis(n);
    }

    void test_case2() {
        // 示例 2：
        // 输入：n = 1
        // 输出：["()"]
        int n = 1;
        vector<string> res = generateParenthesis(n);
    }
};

class validPalindrome {
public:
    /**
     * @brief
     * 125. Valid Palindrome https://leetcode.cn/problems/valid-palindrome/
     *
     * @param s
     * @return true
     * @return false
     */
    virtual bool isPalindrome(string s) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        //输入: s = "A man, a plan, a canal: Panama"
        string s = "A man, a plan, a canal: Panama";
        bool res = isPalindrome(s);
    }
    void test_case2() {
        //输入：s = "race a car"
        string s = "race a car";
        bool res = isPalindrome(s);
    }
    void test_case3() {
        //输入：s = " "
        string s = " ";
        bool res = isPalindrome(s);
    }
};

class sortListQ {
public:
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
    /**
     * @brief
     * 148. Sort List https://leetcode.cn/problems/sort-list/
     *
     * @param head
     * @return ListNode*
     */
    virtual ListNode *sortList(ListNode *head) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        //输入：head = [4,2,1,3]
        ListNode *node1 = new ListNode(4);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(1);
        ListNode *node4 = new ListNode(3);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;

        ListNode *head = node1;
        ListNode *res = sortList(head);
    }
    void test_case2() {
        //输入：head = [-1,5,3,4,0]
        ListNode *node1 = new ListNode(-1);
        ListNode *node2 = new ListNode(5);
        ListNode *node3 = new ListNode(3);
        ListNode *node4 = new ListNode(4);
        ListNode *node5 = new ListNode(0);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;

        ListNode *head = node1;
        ListNode *res = sortList(head);
    }
    void test_case3() {
        //输入：head = []
        ListNode *head = nullptr;
        ListNode *res = sortList(head);
    }
};

class subsetsQ {
public:
    /**
     * @brief
     * 78. Subsets https://leetcode.cn/problems/subsets/
     *
     * @param nums
     * @return vector<vector<int>>
     */
    virtual vector<vector<int>> subsets(vector<int> &nums) = 0;

    void test() {
        test_case1();
        test_case2();
    }
    void test_case1() {
        //输入：nums = [1,2,3]
        vector<int> nums = {1, 2, 3};
        vector<vector<int>> res = subsets(nums);
    }
    void test_case2() {
        //输入：nums = [0]
        vector<int> nums = {0};
        vector<vector<int>> res = subsets(nums);
    }
};

class singleNumberQ {
public:
    /**
     * @brief
     * 136. Single Number
     * https://leetcode.cn/problems/single-number/
     *
     * @param nums
     * @return int
     */
    virtual int singleNumber(vector<int> &nums) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 输入: [2,2,1]
        vector<int> nums = {2, 2, 1};
        int res = singleNumber(nums);
    }

    void test_case2() {
        // 输入: [4,1,2,1,2]
        vector<int> nums = {4, 1, 2, 1, 2};
        int res = singleNumber(nums);
    }
};

class shuffleAnArray {
    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(nums);
     * vector<int> param_1 = obj->reset();
     * vector<int> param_2 = obj->shuffle();
     */
public:
    /**
     * @brief Construct a new Solution object
     * 384. Shuffle an Array
     * https://leetcode.cn/problems/shuffle-an-array/
     *
     * @param nums
     */
    shuffleAnArray(vector<int> &nums) {
    }

    virtual vector<int> reset() = 0;

    virtual vector<int> shuffle() = 0;
};

class trappingRainWater {
public:
    /**
     * @brief
     * 42. Trapping Rain Water
     * https://leetcode.cn/problems/trapping-rain-water/
     *
     * @param height
     * @return int
     */
    virtual int trap(vector<int> &height) = 0;

    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        // 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
        vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        int res = trap(height);
    }
    void test_case2() {
        // 输入：height = [4,2,0,3,2,5]
        vector<int> height = {4, 2, 0, 3, 2, 5};
        int res = trap(height);
    }
};

class mergeKSortedLists {
public:
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
    /**
     * @brief
     * 23. Merge k Sorted Lists
     * https://leetcode.cn/problems/merge-k-sorted-lists/
     *
     * @param lists
     * @return ListNode*
     */
    virtual ListNode *mergeKLists(vector<ListNode *> &lists) = 0;

    void test() {
        test_case1();
        test_case2();
        test_case3();
    }
    void test_case1() {
        // 输入：lists = [[1,4,5],[1,3,4],[2,6]]
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(4);
        ListNode *node3 = new ListNode(5);
        node1->next = node2;
        node2->next = node3;
        ListNode *list1 = node1;

        ListNode *node4 = new ListNode(1);
        ListNode *node5 = new ListNode(3);
        ListNode *node6 = new ListNode(4);
        node4->next = node5;
        node5->next = node6;
        ListNode *list2 = node4;

        ListNode *node7 = new ListNode(2);
        ListNode *node8 = new ListNode(6);
        node7->next = node8;
        ListNode *list3 = node7;

        vector<ListNode *> lists = {list1, list2, list3};
        ListNode *res = mergeKLists(lists);
    }

    void test_case2() {
        // 输入：lists = []
        vector<ListNode *> lists = {};
        ListNode *res = mergeKLists(lists);
    }

    void test_case3() {
        // 输入：lists = [[]]
        ListNode *list1 = nullptr;
        vector<ListNode *> lists = {list1};
        ListNode *res = mergeKLists(lists);
    }
};

class constructBinaryTreeFromInorderAndPostorderTraversal {
public:
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
     * @brief
     * 106. Construct Binary Tree from Inorder and Postorder Traversal
     * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
     *
     * @param inorder
     * @param postorder
     * @return TreeNode*
     */
    virtual TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) = 0;

    void test() {
        // 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
        vector<int> inorder = {9, 3, 15, 20, 7};
        vector<int> postorder = {9, 15, 7, 20, 3};
        TreeNode *res = buildTree(inorder, postorder);

        // 输入：inorder = [-1], postorder = [-1]
        vector<int> inorder_2 = {-1};
        vector<int> postorder_2 = {-1};
        TreeNode *res_2 = buildTree(inorder_2, postorder_2);
    }
};

class MinStack {
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */
public:
    /**
     * @brief Construct a new Min Stack object
     * 155. Min Stack
     * https://leetcode.cn/problems/min-stack/
     *
     */
    MinStack() {
    }

    virtual void push(int val) = 0;
    virtual void pop() = 0;
    virtual int top() = 0;
    virtual int getMin() = 0;
};

class binaryTreePreorderTraversal {
public:
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
     * @brief
     * 144. Binary Tree Preorder Traversal
     * https://leetcode.cn/problems/binary-tree-preorder-traversal/
     *
     * @param root
     * @return vector<int>
     */
    virtual vector<int> preorderTraversal(TreeNode *root) = 0;

    void test() {
        // 输入：root = [1,null,2,3]
        TreeNode *node1 = new TreeNode(1);
        TreeNode *node2 = new TreeNode(2);
        TreeNode *node3 = new TreeNode(3);
        node1->right = node2;
        node2->left = node3;
        TreeNode *root = node1;
        vector<int> res = preorderTraversal(root);

        // 输入：root = []
        TreeNode *node1_2 = nullptr;
        TreeNode *root_2 = node1_2;
        vector<int> res_2 = preorderTraversal(root_2);

        // 输入：root = [1]
        TreeNode *node1_3 = new TreeNode(1);
        TreeNode *root_3 = node1_3;
        vector<int> res_3 = preorderTraversal(root_3);

        // 输入：root = [1,2]
        TreeNode *node1_4 = new TreeNode(1);
        TreeNode *node2_4 = new TreeNode(2);
        node1_4->left = node2_4;
        TreeNode *root_4 = node1_4;
        vector<int> res_4 = preorderTraversal(root_4);

        // 输入：root = [1,null,2]
        TreeNode *node1_5 = new TreeNode(1);
        TreeNode *node2_5 = new TreeNode(2);
        node1_5->right = node2_5;
        TreeNode *root_5 = node1_5;
        vector<int> res_5 = preorderTraversal(root_5);
    }
};

class maximumDepthOfBinaryTree {
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
public:
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
     * @brief
     * 104. Maximum Depth of Binary Tree
     * https://leetcode.cn/problems/maximum-depth-of-binary-tree/
     *
     * @param root
     * @return int
     */
    virtual int maxDepth(TreeNode *root) = 0;

    void test() {
        // 给定二叉树 [3,9,20,null,null,15,7]，
        /**
         * @brief
         *  3
           / \
          9  20
            /  \
           15   7
         *
         */
        TreeNode *node1 = new TreeNode(3);
        TreeNode *node2 = new TreeNode(9);
        TreeNode *node3 = new TreeNode(20);
        TreeNode *node4 = new TreeNode(15);
        TreeNode *node5 = new TreeNode(7);
        node1->left = node2;
        node1->right = node3;
        node3->left = node4;
        node3->right = node5;
        TreeNode *root = node1;
        int res = maxDepth(root);
    }
};

class permutations {
public:
    /**
     * @brief
     * 46. Permutations
     * https://leetcode.cn/problems/permutations/
     *
     * @param nums
     * @return vector<vector<int>>
     */
    virtual vector<vector<int>> permute(vector<int> &nums) = 0;

    void test() {
        // 输入：nums = [1,2,3]
        vector<int> nums = {1, 2, 3};
        vector<vector<int>> res = permute(nums);

        // 输入：nums = [0,1]
        vector<int> nums_2 = {0, 1};
        vector<vector<int>> res_2 = permute(nums_2);

        // 输入：nums = [1]
        vector<int> nums_3 = {1};
        vector<vector<int>> res_3 = permute(nums_3);
    }
};

class slidingWindowMaximum {
public:
    /**
     * @brief
     * 239. Sliding Window Maximum
     * https://leetcode.cn/problems/sliding-window-maximum/
     *
     * @param nums
     * @param k
     * @return vector<int>
     */
    virtual vector<int> maxSlidingWindow(vector<int> &nums, int k) = 0;

    void test() {
        // 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
        vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
        int k = 3;
        vector<int> res = maxSlidingWindow(nums, k);

        // 输入：nums = [1], k = 1
        vector<int> nums_2 = {1};
        int k_2 = 1;
        vector<int> res_2 = maxSlidingWindow(nums_2, k_2);
    }
};

class targetSum {
public:
    /**
     * @brief
     * 494. Target Sum
     * https://leetcode.cn/problems/target-sum/
     *
     * @param nums
     * @param target
     * @return int
     */
    virtual int findTargetSumWays(vector<int> &nums, int target) = 0;

    void test() {
        // 输入：nums = [1,1,1,1,1], target = 3
        vector<int> nums = {1, 1, 1, 1, 1};
        int target = 3;
        int res = findTargetSumWays(nums, target);

        // 输入：nums = [1], target = 1
        vector<int> nums_1 = {1};
        int target_1 = 1;
        int res_1 = findTargetSumWays(nums_1, target_1);
    }
};

class validParenthesisString {
public:
    /**
     * @brief
     * 678. Valid Parenthesis String
     * https://leetcode.cn/problems/valid-parenthesis-string/
     *
     * @param s
     * @return true
     * @return false
     */
    virtual bool checkValidString(string s) = 0;

    void test() {
        // 输入: "()"
        string s = "()";
        bool res = checkValidString(s);

        // 输入: "(*)"
        string s_2 = "(*)";
        bool res_2 = checkValidString(s_2);

        // 输入: "(*))"
        string s_3 = "(*))";
        bool res_3 = checkValidString(s_3);
    }
};

class lowestCommonAncestorOfABinaryTree {
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     * };
     */
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
        }
    };
    /**
     * @brief
     * 236. Lowest Common Ancestor of a Binary Tree
     * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
     *
     * @param root
     * @param p
     * @param q
     * @return TreeNode*
     */
    virtual TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) = 0;

    void test() {
        // root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
        /**
         * @brief https://microsoftapc-my.sharepoint.com/personal/shouyanxiang_microsoft_com/_layouts/OneNote.aspx?id=%2Fpersonal%2Fshouyanxiang_microsoft_com%2FDocuments%2FShouyan%20%40%20Microsoft&wd=target%28alg.one%7C0040694C-6C64-48A8-BC2B-4B8594F79257%2Fnode1%7C10666695-59BE-4A48-8033-74DC3CD21D0A%2F%29onenote:https://microsoftapc-my.sharepoint.com/personal/shouyanxiang_microsoft_com/Documents/Shouyan%20@%20Microsoft/alg.one#node1&section-id={0040694C-6C64-48A8-BC2B-4B8594F79257}&page-id={10666695-59BE-4A48-8033-74DC3CD21D0A}&object-id={944774AB-FC8F-48A2-8A6F-5ABC2B16BB98}&24
         *
         */
        TreeNode *node1 = new TreeNode(3);
        TreeNode *node2 = new TreeNode(5);
        TreeNode *node3 = new TreeNode(1);
        TreeNode *node4 = new TreeNode(6);
        TreeNode *node5 = new TreeNode(2);
        TreeNode *node6 = new TreeNode(0);
        TreeNode *node7 = new TreeNode(8);
        TreeNode *node8 = new TreeNode(7);
        TreeNode *node9 = new TreeNode(4);
        node1->left = node2;
        node1->right = node3;
        node2->left = node4;
        node2->right = node5;
        node3->left = node6;
        node3->right = node7;
        node5->left = node8;
        node5->right = node9;
        TreeNode *root = node1;
        TreeNode *p = node2;
        TreeNode *q = node3;
        TreeNode *res = lowestCommonAncestor(root, p, q);

        // 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
        TreeNode *node1_2 = new TreeNode(3);
        TreeNode *node2_2 = new TreeNode(5);
        TreeNode *node3_2 = new TreeNode(1);
        TreeNode *node4_2 = new TreeNode(6);
        TreeNode *node5_2 = new TreeNode(2);
        TreeNode *node6_2 = new TreeNode(0);
        TreeNode *node7_2 = new TreeNode(8);
        TreeNode *node8_2 = new TreeNode(7);
        TreeNode *node9_2 = new TreeNode(4);
        node1_2->left = node2_2;
        node1_2->right = node3_2;
        node2_2->left = node4_2;
        node2_2->right = node5_2;
        node3_2->left = node6_2;
        node3_2->right = node7_2;
        node5_2->left = node8_2;
        node5_2->right = node9_2;
        TreeNode *root_2 = node1_2;
        TreeNode *p_2 = node2_2;
        TreeNode *q_2 = node9_2;
        TreeNode *res_2 = lowestCommonAncestor(root_2, p_2, q_2);

        // 输入：root = [1,2], p = 1, q = 2
        TreeNode *node1_3 = new TreeNode(1);
        TreeNode *node2_3 = new TreeNode(2);
        node1_3->left = node2_3;
        TreeNode *root_3 = node1_3;
        TreeNode *p_3 = node1_3;
        TreeNode *q_3 = node2_3;
        TreeNode *res_3 = lowestCommonAncestor(root_3, p_3, q_3);
    }
};

class linkedListCycleIi {
public:
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) :
            val(x), next(NULL) {
        }
    };
    /**
     * @brief
     * 142. Linked List Cycle II
     * https://leetcode.cn/problems/linked-list-cycle-ii/
     *
     * @param head
     * @return ListNode*
     */
    virtual ListNode *detectCycle(ListNode *head) = 0;

    void test() {
        ListNode *node1 = new ListNode(3);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(0);
        ListNode *node4 = new ListNode(-4);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node2;
        ListNode *head = node1;
        ListNode *res = detectCycle(head);

        ListNode *node1_2 = new ListNode(1);
        ListNode *node2_2 = new ListNode(2);
        node1_2->next = node2_2;
        node2_2->next = node1_2;
        ListNode *head_2 = node1_2;
        ListNode *res_2 = detectCycle(head_2);

        ListNode *node1_3 = new ListNode(1);
        ListNode *head_3 = node1_3;
        ListNode *res_3 = detectCycle(head_3);
    }
};

class spiralMatrix {
public:
    /**
     * @brief
     * 54. Spiral Matrix
     * https://leetcode.cn/problems/spiral-matrix/
     *
     * @param matrix
     * @return vector<int>
     */
    virtual vector<int> spiralOrder(vector<vector<int>> &matrix) = 0;

    void test() {
        // [[1,2,3],[4,5,6],[7,8,9]]
        vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        vector<int> res = spiralOrder(matrix);

        //  [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
        vector<vector<int>> matrix_2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        vector<int> res_2 = spiralOrder(matrix_2);
    }
};

class balancedBinaryTree {
public:
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
     * @brief
     * 110. Balanced Binary Tree
     * https://leetcode.cn/problems/balanced-binary-tree/
     *
     * @param root
     * @return true
     * @return false
     */
    virtual bool isBalanced(TreeNode *root) = 0;

    void test() {
        TreeNode *node1 = new TreeNode(3);
        TreeNode *node2 = new TreeNode(9);
        TreeNode *node3 = new TreeNode(20);
        TreeNode *node4 = new TreeNode(15);
        TreeNode *node5 = new TreeNode(7);
        node1->left = node2;
        node1->right = node3;
        node3->left = node4;
        node3->right = node5;
        TreeNode *root = node1;
        bool res = isBalanced(root);

        //  [1,2,2,3,3,null,null,4,4]
        // https://microsoftapc-my.sharepoint.com/personal/shouyanxiang_microsoft_com/_layouts/OneNote.aspx?id=%2Fpersonal%2Fshouyanxiang_microsoft_com%2FDocuments%2FShouyan%20%40%20Microsoft&wd=target%28alg.one%7C0040694C-6C64-48A8-BC2B-4B8594F79257%2Fnode1%7CBFAA0CC9-BA17-4790-ABB3-950987620CB3%2F%29onenote:https://microsoftapc-my.sharepoint.com/personal/shouyanxiang_microsoft_com/Documents/Shouyan%20@%20Microsoft/alg.one#node1&section-id={0040694C-6C64-48A8-BC2B-4B8594F79257}&page-id={BFAA0CC9-BA17-4790-ABB3-950987620CB3}&object-id={5455637A-3681-4FA3-8CF1-0509AEF427E3}&21
        TreeNode *node1_2 = new TreeNode(1);
        TreeNode *node2_2 = new TreeNode(2);
        TreeNode *node3_2 = new TreeNode(2);
        TreeNode *node4_2 = new TreeNode(3);
        TreeNode *node5_2 = new TreeNode(3);
        TreeNode *node6_2 = new TreeNode(4);
        TreeNode *node7_2 = new TreeNode(4);
        node1_2->left = node2_2;
        node1_2->right = node3_2;
        node2_2->left = node4_2;
        node2_2->right = node5_2;
        node4_2->left = node6_2;
        node4_2->right = node7_2;
        TreeNode *root_2 = node1_2;
        bool res_2 = isBalanced(root_2);

        TreeNode *root_3 = nullptr;
        bool res_3 = isBalanced(root_3);
    }
};

class reverseWordsInAString {
public:
    /**
     * @brief
     * 151. Reverse Words in a String
     * https://leetcode.cn/problems/reverse-words-in-a-string/
     *
     * @param s
     * @return string
     */
    virtual string reverseWords(string s) = 0;

    void test() {
        string s = "the sky is blue";
        string res = reverseWords(s);

        string s_2 = "  hello world  ";
        string res_2 = reverseWords(s_2);

        string s_3 = "a good   example";
        string res_3 = reverseWords(s_3);
    }
};

class MyQueue {
    /**
     * @brief Construct a new My Queue object
     * 232. Implement Queue using Stacks
     * https://leetcode.cn/problems/implement-queue-using-stacks/
     *
     */
    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue* obj = new MyQueue();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->peek();
     * bool param_4 = obj->empty();
     */
public:
    MyQueue() {
    }
    virtual void push(int x) = 0;

    virtual int pop() = 0;

    virtual int peek() = 0;

    virtual bool empty() = 0;
};

class multiplyStrings {
public:
    /**
     * @brief
     * 43. Multiply Strings
     * https://leetcode.cn/problems/multiply-strings/
     *
     * @param num1
     * @param num2
     * @return string
     */
    virtual string multiply(string num1, string num2) = 0;

    void test() {
        string num1 = "2";
        string num2 = "3";
        string res = multiply(num1, num2);

        string num1_2 = "123";
        string num2_2 = "456";
        string res_2 = multiply(num1_2, num2_2);
    }
};

class pathSum {
public:
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
     * @brief
     * 112. Path Sum
     * https://leetcode.cn/problems/path-sum/
     *
     * @param root
     * @param targetSum
     * @return true
     * @return false
     */
    virtual bool hasPathSum(TreeNode *root, int targetSum) = 0;

    void test() {
        TreeNode *node1 = new TreeNode(5);
        TreeNode *node2 = new TreeNode(4);
        TreeNode *node3 = new TreeNode(8);
        TreeNode *node4 = new TreeNode(11);
        TreeNode *node5 = new TreeNode(13);
        TreeNode *node6 = new TreeNode(4);
        TreeNode *node7 = new TreeNode(7);
        TreeNode *node8 = new TreeNode(2);
        TreeNode *node9 = new TreeNode(1);
        // 二叉树图
        // https://microsoftapc-my.sharepoint.com/:u:/r/personal/shouyanxiang_microsoft_com/_layouts/15/doc.aspx?sourcedoc=%7B3ceba639-1b1b-47f9-b064-d30dfd3c0639%7D&action=edit&or=PrevCreateNew&wdnewandopenct=0
        node1->left = node2;
        node1->right = node3;
        node2->left = node4;
        node3->left = node5;
        node3->right = node6;
        node4->left = node7;
        node4->right = node8;
        node6->right = node9;
        TreeNode *root_1 = node1;
        int targetSum_1 = 22;
        bool res_1 = hasPathSum(root_1, targetSum_1);

        TreeNode *node1_2 = new TreeNode(1);
        TreeNode *node2_2 = new TreeNode(2);
        TreeNode *node3_2 = new TreeNode(3);
        node1_2->left = node2_2;
        node1_2->right = node3_2;
        TreeNode *root_2 = node1_2;
        int targetSum_2 = 5;
        bool res_2 = hasPathSum(root_2, targetSum_2);

        TreeNode *root_3 = nullptr;
        int targetSum_3 = 0;
        bool res_3 = hasPathSum(root_3, targetSum_3);
    }
};

class theKToPenultimateNodeInTheLinkedList {
public:
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) :
            val(x), next(NULL) {
        }
    };
    /**
     * @brief Get the Kth From End object
     *  The k-to-penultimate node in the linked list
     * 剑指 Offer 22. 链表中倒数第k个节点
     * https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
     *
     * @param head
     * @param k
     * @return ListNode*
     */
    virtual ListNode *getKthFromEnd(ListNode *head, int k) = 0;

    void test() {
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(3);
        ListNode *node4 = new ListNode(4);
        ListNode *node5 = new ListNode(5);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;

        ListNode *head_1 = node1;
        int k_1 = 2;
        ListNode *res_1 = getKthFromEnd(head_1, k_1);

        // ListNode *head_2 = ;
        // int k_2 = ;
        // ListNode *res_2 = getKthFromEnd(head_2, k_2);

        // ListNode *head_3 = ;
        // int k_3 = ;
        // ListNode *res_3 = getKthFromEnd(head_3, k_3);
    }
};

class coinChangeBase {
public:
    /**
     * @brief
     * 322. Coin Change
     * https://leetcode.cn/problems/coin-change/
     *
     * @param coins
     * @param amount
     * @return int
     */
    virtual int coinChange(vector<int> &coins, int amount) = 0;

    void test() {
        vector<int> coins_1 = {1, 2, 5};
        int amount_1 = 11;
        int res_1 = coinChange(coins_1, amount_1);

        vector<int> coins_2 = {2};
        int amount_2 = 3;
        int res_2 = coinChange(coins_2, amount_2);

        vector<int> coins_3 = {1};
        int amount_3 = 0;
        int res_3 = coinChange(coins_3, amount_3);
    }
};
class basicCalculatorIi {
public:
    /**
     * @brief
     * 227. Basic Calculator II
     * https://leetcode.cn/problems/basic-calculator-ii/
     *
     * @param s
     * @return int
     */
    virtual int calculate(string s) = 0;

    void test() {
        string s_1 = "3+2*2";
        int res_1 = calculate(s_1);

        string s_2 = " 3/2 ";
        int res_2 = calculate(s_2);

        string s_3 = " 3+5 / 2 ";
        int res_3 = calculate(s_3);
    }
};

class findAllDuplicatesInAnArray {
public:
    /**
     * @brief
     * 442. Find All Duplicates in an Array
     * https://leetcode.cn/problems/find-all-duplicates-in-an-array/
     *
     * @param nums
     * @return vector<int>
     */
    virtual vector<int> findDuplicates(vector<int> &nums) = 0;

    void test() {
        vector<int> nums_1 = {4, 3, 2, 7, 8, 2, 3, 1};
        vector<int> res_1 = findDuplicates(nums_1);

        vector<int> nums_2 = {1, 1, 2};
        vector<int> res_2 = findDuplicates(nums_2);

        vector<int> nums_3 = {1};
        vector<int> res_3 = findDuplicates(nums_3);
    }
};

class LFUCache {
    /**
     * Your LFUCache object will be instantiated and called as such:
     * LFUCache* obj = new LFUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */
public:
    /**
     * @brief Construct a new LFUCache object
     * 460. LFU 缓存
     * https://leetcode.cn/problems/lfu-cache/
     *
     * @param capacity
     */
    LFUCache(int capacity) {
    }

    virtual int get(int key) {
        return -1;
    }

    virtual void put(int key, int value) {
    }
};

class theKthLargestNodeOfTheBinarySearchTree {
protected:
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     * };
     */
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
        }
    };

    void test() {
        TreeNode *node1_1 = new TreeNode(3);
        TreeNode *node2_1 = new TreeNode(1);
        TreeNode *node3_1 = new TreeNode(4);
        TreeNode *node4_1 = new TreeNode(2);
        node1_1->left = node2_1;
        node1_1->right = node3_1;
        node2_1->left = nullptr;
        node2_1->right = node4_1;
        TreeNode *root_1 = node1_1;
        int res_1 = kthLargest(root_1, 1);

        TreeNode *node1_2 = new TreeNode(5);
        TreeNode *node2_2 = new TreeNode(3);
        TreeNode *node3_2 = new TreeNode(6);
        TreeNode *node4_2 = new TreeNode(2);
        TreeNode *node5_2 = new TreeNode(4);
        TreeNode *node6_2 = new TreeNode(1);
        node1_2->left = node2_2;
        node1_2->right = node3_2;
        node2_2->left = node4_2;
        node2_2->right = node5_2;
        node4_2->left = node6_2;
        TreeNode *root_2 = node1_2;
        int res_2 = kthLargest(root_2, 3);
    }

    /**
     * @brief
     * 剑指 Offer 54. 二叉搜索树的第k大节点
     * https://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
     *
     * @param root
     * @param k
     * @return int
     */
    virtual int kthLargest(TreeNode *root, int k) {
        return -1;
    }
};

class binaryTreeLevelOrderTraversal {
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

    void test() {
        TreeNode *node1_1 = new TreeNode(3);
        TreeNode *node2_1 = new TreeNode(9);
        TreeNode *node3_1 = new TreeNode(20);
        TreeNode *node4_1 = new TreeNode(15);
        TreeNode *node5_1 = new TreeNode(7);
        node1_1->left = node2_1;
        node1_1->right = node3_1;
        node3_1->left = node4_1;
        node3_1->right = node5_1;
        TreeNode *root_1 = node1_1;
        vector<vector<int>> res_1 = levelOrder(root_1);

        TreeNode *node1_2 = new TreeNode(1);
        TreeNode *root_2 = node1_2;
        vector<vector<int>> res_2 = levelOrder(root_2);

        TreeNode *node1_3 = nullptr;
        TreeNode *root_3 = node1_3;
        vector<vector<int>> res_3 = levelOrder(root_3);
    }

    /**
     * @brief
     * 102. Binary Tree Level Order Traversal
     * https://leetcode.cn/problems/binary-tree-level-order-traversal/
     *
     * @param root
     * @return vector<vector<int>>
     */
    virtual vector<vector<int>> levelOrder(TreeNode *root) {
        return {};
    }
};

class medianOfTwoSortedArrays {
protected:
    void test() {
        vector<int> nums1_1 = {1, 3};
        vector<int> nums2_1 = {2};
        double res_1 = findMedianSortedArrays(nums1_1, nums2_1);

        vector<int> nums1_2 = {1, 2};
        vector<int> nums2_2 = {3, 4};
        double res_2 = findMedianSortedArrays(nums1_2, nums2_2);
    }

    /**
     * @brief
     * 4. Median of Two Sorted Arrays
     * https://leetcode.cn/problems/median-of-two-sorted-arrays/
     *
     * @param nums1
     * @param nums2
     * @return double
     */
    virtual double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        return -1;
    }
};

class longestCommonSubsequenceQ {
public:
    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        string text1 = "abcde";
        string text2 = "ace";
        int res = longestCommonSubsequence(text1, text2);
    }
    void test_case2() {
        string text1 = "abc";
        string text2 = "abc";
        int res = longestCommonSubsequence(text1, text2);
    }
    void test_case3() {
        string text1 = "abc";
        string text2 = "def";
        int res = longestCommonSubsequence(text1, text2);
    }

protected:
    /**
     * @brief
     * 1143. Longest Common Subsequence
     * https://leetcode.cn/problems/longest-common-subsequence/
     * @param text1
     * @param text2
     * @return int
     */
    virtual int longestCommonSubsequence(string text1, string text2) {
        return -1;
    }
};

class longestPalindromicSubstring {
public:
    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        string s = "babad";
        string res = longestPalindrome(s);
    }
    void test_case2() {
        string s = "cbbd";
        string res = longestPalindrome(s);
    }

protected:
    /**
     * @brief
     * 5. Longest Palindromic Substring
     * https://leetcode.cn/problems/longest-palindromic-substring/
     *
     * @param s
     * @return string
     */
    virtual string longestPalindrome(string s) {
        return "";
    }
};

class linkedListCycle {
public:
    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        ListNode *head = build_list_node_for_test_case1();
        bool res = hasCycle(head);
    }
    void test_case2() {
        ListNode *head = build_list_node_for_test_case2();
        bool res = hasCycle(head);
    }
    void test_case3() {
        ListNode *head = build_list_node_for_test_case3();
        bool res = hasCycle(head);
    }

protected:
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) :
            val(x), next(NULL) {
        }
    };

    ListNode *build_list_node_for_test_case1() {
        ListNode *N1 = new ListNode(3);
        ListNode *N2 = new ListNode(2);
        ListNode *N3 = new ListNode(0);
        ListNode *N4 = new ListNode(-4);

        N1->next = N2;
        N2->next = N3;
        N3->next = N4;
        N4->next = N2;

        return N1;
    }
    ListNode *build_list_node_for_test_case2() {
        ListNode *N1 = new ListNode(1);
        ListNode *N2 = new ListNode(2);

        N1->next = N2;
        N2->next = N1;

        return N1;
    }
    ListNode *build_list_node_for_test_case3() {
        ListNode *N1 = new ListNode(1);

        return N1;
    }
    /**
     * @brief
     *
     * 141. Linked List Cycle
     * https://leetcode.cn/problems/linked-list-cycle/
     *
     * @param head
     * @return true
     * @return false
     */
    virtual bool hasCycle(ListNode *head) {
        return false;
    }
};

class validParentheses {
public:
    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        string s = "()";
        bool res = isValid(s);
    }
    void test_case2() {
        string s = "()[]{}";
        bool res = isValid(s);
    }
    void test_case3() {
        string s = "(]";
        bool res = isValid(s);
    }

protected:
    /**
     * @brief
     * 20. Valid Parentheses
     * https://leetcode.cn/problems/valid-parentheses/
     *
     *
     * @param s
     * @return true
     * @return false
     */
    virtual bool isValid(string s) {
        return false;
    }
};

class climbingStairs {
public:
    void test() {
        test_case1();
        test_case2();
    }

    void test_case1() {
        int n = 2;
        int res = climbStairs(n);
    }
    void test_case2() {
        int n = 3;
        int res = climbStairs(n);
    }

protected:
    virtual int climbStairs(int n) {
        return -1;
    }
};

class twoSumQ {
public:
    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

    void test_case1() {
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        vector<int> res = twoSum(nums, target);
    }
    void test_case2() {
        vector<int> nums = {3, 2, 4};
        int target = 6;
        vector<int> res = twoSum(nums, target);
    }
    void test_case3() {
        vector<int> nums = {3, 3};
        int target = 6;
        vector<int> res = twoSum(nums, target);
    }

protected:
    virtual vector<int> twoSum(vector<int> &nums, int target) {
        return {};
    }
};

class implementRand10UsingRand7 {
public:
    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

protected:
    // The rand7() API is already defined for you.
    // int rand7();
    // @return a random integer in the range 1 to 7
    int rand7() {
        /* initialize random seed: */
        srand(time(NULL));
        int rand7 = rand() % 7 + 1;
        return rand7;
    }

    virtual int rand10() {
        return -1;
    }

    void test_case1() {
        int res = rand10();
    }
    void test_case2() {
        int res1 = rand10();
        int res2 = rand10();
    }
    void test_case3() {
        int res1 = rand10();
        int res2 = rand10();
        int res3 = rand10();
    }
};

class palindromeLinkedList {
public:
    void test() {
        test_case1();
        test_case2();
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

    ListNode *build_list_node_for_test_case1() {
        ListNode *N1 = new ListNode(1);
        ListNode *N2 = new ListNode(2);
        ListNode *N3 = new ListNode(2);
        ListNode *N4 = new ListNode(1);

        N1->next = N2;
        N2->next = N3;
        N3->next = N4;

        return N1;
    }

    ListNode *build_list_node_for_test_case2() {
        ListNode *N1 = new ListNode(1);
        ListNode *N2 = new ListNode(2);

        N1->next = N2;

        return N1;
    }

    virtual bool isPalindrome(ListNode *head) {
        return false;
    }

    void test_case1() {
        ListNode *head = build_list_node_for_test_case1();
        bool res = isPalindrome(head);
    }
    void test_case2() {
        ListNode *head = build_list_node_for_test_case2();
        bool res = isPalindrome(head);
    }
};

class stringToIntegerAtoi {
public:
    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

protected:
    virtual int myAtoi(string s) {
        return -1;
    }
    void test_case1() {
        string s = "42";
        int res = myAtoi(s);
    }
    void test_case2() {
        string s = "   -42";
        int res = myAtoi(s);
    }
    void test_case3() {
        string s = "4193 with words";
        int res = myAtoi(s);
    }
};

} // namespace std

class binarySearch {
public:
    void test() {
        test_case1();
        test_case2();
    }

protected:
    virtual int search(std::vector<int> &nums, int target) {
        return -1;
    }

    void test_case1() {
        std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
        int target = 9;
        int res = search(nums, target);
    }
    void test_case2() {
        std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
        int target = 2;
        int res = search(nums, target);
    }
};

class addStringsQ {
public:
    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

protected:
    virtual std::string addStrings(std::string num1, std::string num2) {
        return "";
    }
    void test_case1() {
        std::string num1 = "11";
        std::string num2 = "123";
        std::string res = addStrings(num1, num2);
    }
    void test_case2() {
        std::string num1 = "456";
        std::string num2 = "77";
        std::string res = addStrings(num1, num2);
    }
    void test_case3() {
        std::string num1 = "0";
        std::string num2 = "0";
        std::string res = addStrings(num1, num2);
    }
};

class maximumSubarray {
public:
    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

protected:
    virtual int maxSubArray(std::vector<int> &nums) {
        return -1;
    }

    void test_case1() {
        std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int res = maxSubArray(nums);
    }
    void test_case2() {
        std::vector<int> nums = {1};
        int res = maxSubArray(nums);
    }
    void test_case3() {
        std::vector<int> nums = {5, 4, -1, 7, 8};
        int res = maxSubArray(nums);
    }
};

class sortAnArray {
public:
    void test() {
        test_case1();
        test_case2();
    }

protected:
    /**
     * @brief
     * 912. Sort an Array
     * https://leetcode.cn/problems/sort-an-array/
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
    }
    void test_case2() {
        std::vector<int> nums = {5, 1, 1, 2, 0, 0};
        std::vector<int> res = sortArray(nums);
    }
};

class intersectionOfTwoLinkedLists {
public:
    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

protected:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) :
            val(x), next(NULL) {
        }
    };

    void build_input_data_structure_for_test_case1() {
        ListNode *A1 = new ListNode(4);
        ListNode *A2 = new ListNode(1);

        ListNode *B1 = new ListNode(5);
        ListNode *B2 = new ListNode(6);
        ListNode *B3 = new ListNode(1);

        ListNode *pub1 = new ListNode(8);
        ListNode *pub2 = new ListNode(4);
        ListNode *pub3 = new ListNode(5);

        A1->next = A2;
        A2->next = pub1;

        B1->next = B2;
        B2->next = B3;
        B3->next = pub1;

        pub1->next = pub2;
        pub2->next = pub3;

        headA_ = A1;
        headB_ = B1;
    }

    void build_input_data_structure_for_test_case2() {
        ListNode *A1 = new ListNode(1);
        ListNode *A2 = new ListNode(9);
        ListNode *A3 = new ListNode(1);

        ListNode *B1 = new ListNode(3);

        ListNode *pub1 = new ListNode(2);
        ListNode *pub2 = new ListNode(4);

        A1->next = A2;
        A2->next = A3;
        A3->next = pub1;

        B1->next = pub1;

        pub1->next = pub2;

        headA_ = A1;
        headB_ = B1;
    }

    void build_input_data_structure_for_test_case3() {
        ListNode *A1 = new ListNode(2);
        ListNode *A2 = new ListNode(6);
        ListNode *A3 = new ListNode(4);

        ListNode *B1 = new ListNode(1);
        ListNode *B2 = new ListNode(5);

        A1->next = A2;
        A2->next = A3;

        B1->next = B2;

        headA_ = A1;
        headB_ = B1;
    }

    /**
     * @brief Get the Intersection Node object
     * 160. Intersection of Two Linked Lists
     * https://leetcode.cn/problems/intersection-of-two-linked-lists/
     *
     * @link https://leetcode.cn/problems/intersection-of-two-linked-lists/ @endlink
     * @param headA
     * @param headB
     * @return ListNode*
     */
    virtual ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        return nullptr;
    }

    void test_case1() {
        build_input_data_structure_for_test_case1();
        ListNode *res = getIntersectionNode(headA_, headB_);
    }
    void test_case2() {
        build_input_data_structure_for_test_case2();
        ListNode *res = getIntersectionNode(headA_, headB_);
    }
    void test_case3() {
        build_input_data_structure_for_test_case3();
        ListNode *res = getIntersectionNode(headA_, headB_);
    }

private:
    ListNode *headA_;
    ListNode *headB_;
};

class searchInRotatedSortedArray {
public:
    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

protected:
    /**
     * @brief
     * 33. Search in Rotated Sorted Array
     * https://leetcode.cn/problems/search-in-rotated-sorted-array/
     *
     *
     * @link https://leetcode.cn/problems/search-in-rotated-sorted-array/ @endlink
     *
     * @param nums
     * @param target
     * @return int
     */
    virtual int search(std::vector<int> &nums, int target) {
        return -1;
    }

    void test_case1() {
        std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 0;
        int res = search(nums, target);
    }
    void test_case2() {
        std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 3;
        int res = search(nums, target);
    }
    void test_case3() {
        std::vector<int> nums = {1};
        int target = 0;
        int res = search(nums, target);
    }
};

class searchInRotatedSortedArrayBinaryLookup : public searchInRotatedSortedArray {
public:
    /**
     * @brief
     * @link https://leetcode.cn/problems/search-in-rotated-sorted-array/solution/sou-suo-xuan-zhuan-pai-xu-shu-zu-by-leetcode-solut/ @endlink
     *
     * @param nums
     * @param target
     * @return int
     */
    int search(std::vector<int> &nums, int target) override {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

class longestSubstringWithoutRepeatingCharacters {
public:
    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

protected:
    /**
     * @brief
     * @link https://leetcode.cn/problems/longest-substring-without-repeating-characters/ @endlink
     *
     * @param s
     * @return int
     */
    virtual int lengthOfLongestSubstring(std::string s) {
        return 0;
    }

    void test_case1() {
        std::string s = "abcabcbb";
        int res = lengthOfLongestSubstring(s);
    }
    void test_case2() {
        std::string s = "bbbbb";
        int res = lengthOfLongestSubstring(s);
    }
    void test_case3() {
        std::string s = "pwwkew";
        int res = lengthOfLongestSubstring(s);
    }
};

class longestSubstringWithoutRepeatingCharactersSlideTheWindow : public longestSubstringWithoutRepeatingCharacters {
public:
    /**
     * @brief
     * @link https://leetcode.cn/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/ @endlink
     *
     * @param s
     * @return int
     */
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
class mergeTwoSortedLists {
public:
    void test() {
        test_case1();
        test_case2();
        test_case3();
    }

protected:
    //   Definition for singly-linked list.
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

    class ListNodeBuilder {
    private:
        // Function to insert node
        void insert(ListNode **root, int val) {
            ListNode *temp = new ListNode();
            temp->val = val;
            temp->next = *root;
            *root = temp;
        }

        void display(ListNode *root) {
            while (root != NULL) {
                std::cout << root->val << " ";
                root = root->next;
            }
        }

    public:
        ListNode *array_to_list(int arr[], int n) {
            ListNode *root = NULL;
            for (int i = n - 1; i >= 0; i--) {
                insert(&root, arr[i]);
            }
            return root;
        }

        ListNode *vector_to_list(std::vector<int> arr) {
            ListNode *root = NULL;
            int n = arr.size();
            for (int i = n - 1; i >= 0; i--) {
                insert(&root, arr[i]);
            }
            return root;
        }
    };

    /**
     * @brief
     * @link https://leetcode.cn/problems/merge-two-sorted-lists/ @endlink
     *
     * @param list1
     * @param list2
     * @return ListNode*
     */
    virtual ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        return nullptr;
    }

    void test_case1() {
        std::vector<int> list1_vector = {1, 2, 4};
        std::vector<int> list2_vector = {1, 3, 4};
        ListNodeBuilder *list_node_builder = new ListNodeBuilder();
        ListNode *list1 = list_node_builder->vector_to_list(list1_vector);
        ListNode *list2 = list_node_builder->vector_to_list(list2_vector);
        ListNode *res = mergeTwoLists(list1, list2);
    }

    void test_case2() {
        std::vector<int> list1_vector = {};
        std::vector<int> list2_vector = {};
        ListNodeBuilder *list_node_builder = new ListNodeBuilder();
        ListNode *list1 = list_node_builder->vector_to_list(list1_vector);
        ListNode *list2 = list_node_builder->vector_to_list(list2_vector);
        ListNode *res = mergeTwoLists(list1, list2);
    }

    void test_case3() {
        std::vector<int> list1_vector = {};
        std::vector<int> list2_vector = {0};
        ListNodeBuilder *list_node_builder = new ListNodeBuilder();
        ListNode *list1 = list_node_builder->vector_to_list(list1_vector);
        ListNode *list2 = list_node_builder->vector_to_list(list2_vector);
        ListNode *res = mergeTwoLists(list1, list2);
    }
};

class mergeTwoSortedListsRecursion : public mergeTwoSortedLists {
public:
    /**
     * @brief
     * @link https://leetcode.cn/problems/merge-two-sorted-lists/solution/he-bing-liang-ge-you-xu-lian-biao-by-leetcode-solu/ @endlink
     *
     * @param l1
     * @param l2
     * @return ListNode*
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) override {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

class mergeTwoSortedListsIterate : public mergeTwoSortedLists {
public:
    /**
     * @brief
     * @link https://leetcode.cn/problems/merge-two-sorted-lists/solution/he-bing-liang-ge-you-xu-lian-biao-by-leetcode-solu/ @endlink
     *
     * @param l1
     * @param l2
     * @return ListNode*
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) override {
        ListNode *preHead = new ListNode(-1);

        ListNode *prev = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;
    }
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
     * 200. Number of Islands
     * https://leetcode.cn/problems/number-of-islands/
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

// class UnionFind {
// public:
//     UnionFind(std::vector<std::vector<char>> &grid) {
//         count = 0;
//         int m = grid.size();
//         int n = grid[0].size();
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j] == '1') {
//                     parent.push_back(i * n + j);
//                     ++count;
//                 } else {
//                     parent.push_back(-1);
//                 }
//                 rank.push_back(0);
//             }
//         }
//     }

//     int find(int i) {
//         if (parent[i] != i) {
//             parent[i] = find(parent[i]);
//         }
//         return parent[i];
//     }

//     void unite(int x, int y) {
//         int rootx = find(x);
//         int rooty = find(y);
//         if (rootx != rooty) {
//             if (rank[rootx] < rank[rooty]) {
//                 std::swap(rootx, rooty);
//             }
//             parent[rooty] = rootx;
//             if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
//             --count;
//         }
//     }

//     int getCount() const {
//         return count;
//     }

// private:
//     std::vector<int> parent;
//     std::vector<int> rank;
//     int count;
// };

class numberOfIslandsDisjointSetDataStructure : public numberOfIslands {
public:
    /**
     * @brief
     * @link https://leetcode.cn/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
     *
     * @param grid
     * @return int
     */
    int numIslands(std::vector<std::vector<char>> &grid) override {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        UnionFind uf(grid);
        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r - 1][c] == '1') uf.unite(r * nc + c, (r - 1) * nc + c);
                    if (r + 1 < nr && grid[r + 1][c] == '1') uf.unite(r * nc + c, (r + 1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c - 1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c + 1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
                }
            }
        }

        return uf.getCount();
    }

private:
    class UnionFind {
    public:
        UnionFind(std::vector<std::vector<char>> &grid) {
            count = 0;
            int m = grid.size();
            int n = grid[0].size();
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == '1') {
                        parent.push_back(i * n + j);
                        ++count;
                    } else {
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
                    std::swap(rootx, rooty);
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
        std::vector<int> parent;
        std::vector<int> rank;
        int count;
    };
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
     * 121. Best Time to Buy and Sell Stock
     * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
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
     * 103. Binary Tree Zigzag Level Order Traversal
     * https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
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
     * 25. Reverse Nodes in k-Group
     * https://leetcode.cn/problems/reverse-nodes-in-k-group/
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

class addTwoNumbersBase {
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
    /**
     * @brief
     * 2. Add Two Numbers
     * https://leetcode.cn/problems/add-two-numbers/
     *
     * @param l1
     * @param l2
     * @return ListNode*
     */
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

class Dataframe34Endingwithzero : public addTwoNumbersBase {
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

class Dataframe34NonAlignedZero : public addTwoNumbersBase {
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