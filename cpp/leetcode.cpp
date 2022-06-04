#include "leetcode.h"

// using namespace std;

int Dataframe28FastSorting::quickSelect(std::vector<int> &a, int l, int r, int index) {
    int q = randomPartition(a, l, r);
    if (q == index) {
        return a[q];
    } else {
        return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
    }
}

int Dataframe28FastSorting::randomPartition(std::vector<int> &a, int l, int r) {
    int i = rand() % (r - l + 1) + l;
    std::swap(a[i], a[r]);
    return partition(a, l, r);
}

int Dataframe28FastSorting::partition(std::vector<int> &a, int l, int r) {
    int x = a[r], i = l - 1;
    for (int j = l; j < r; ++j) {
        if (a[j] <= x) {
            std::swap(a[++i], a[j]);
        }
    }
    std::swap(a[i + 1], a[r]);
    return i + 1;
}

int Dataframe28FastSorting::findKthLargest(std::vector<int> &nums, int k) {
    srand(time(0));
    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
}

void Dataframe28HeapSorting::maxHeapify(std::vector<int> &a, int i, int heapSize) {
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

void Dataframe28HeapSorting::buildMaxHeap(std::vector<int> &a, int heapSize) {
    for (int i = heapSize / 2; i >= 0; --i) {
        maxHeapify(a, i, heapSize);
    }
}

int Dataframe28HeapSorting::findKthLargest(std::vector<int> &nums, int k) {
    int heapSize = nums.size();
    buildMaxHeap(nums, heapSize);
    for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
        std::swap(nums[0], nums[i]);
        --heapSize;
        maxHeapify(nums, 0, heapSize);
    }
    return nums[0];
}

int Dataframe46N1::longestValidParentheses(std::string s) {
    int maxans = 0, n = s.length();
    std::vector<int> dp(n, 0);
    for (int i = 1; i < n; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            maxans = std::max(maxans, dp[i]);
        }
    }
    return maxans;
}

int Dataframe46N2::longestValidParentheses(std::string s) {
    int maxans = 0;
    std::stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (stk.empty()) {
                stk.push(i);
            } else {
                maxans = std::max(maxans, i - stk.top());
            }
        }
    }
    return maxans;
}

int Dataframe46N3::longestValidParentheses(std::string s) {
    int left = 0, right = 0, maxlength = 0;
    for (char i : s) {
        if (i == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxlength = std::max(maxlength, 2 * right);
        } else if (right > left) {
            left = right = 0;
        }
    }
    left = right = 0;
    for (int i = (int)s.length() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxlength = std::max(maxlength, 2 * left);
        } else if (left > right) {
            left = right = 0;
        }
    }
    return maxlength;
}

namespace std {
vector<int> turn(string X) {
    int M = 10, N = 2;
    vector<int> vec;
    int data[1010];   //保存M进制下的各个位数
    int output[1010]; //保存N进制下的各个位数
    memset(output, 0, sizeof(output));
    for (int i = 0; i < X.length(); i++) {
        if (isalpha(X[i]))
            data[i] = X[i] - 'A' + 10;
        else
            data[i] = X[i] - '0';
    }
    int sum = 1;
    int d = 0;
    int len = X.length();
    int k = 0;
    while (sum) {
        sum = 0;
        for (int i = 0; i < len; i++) {
            d = data[i] / N;
            sum += d;
            if (i == len - 1) {
                output[k++] = data[i] % N;
            } else {
                data[i + 1] += (data[i] % N) * M;
            }
            data[i] = d;
        }
    }
    if (k == 0) {
        output[k] = 0;
        k--;
    }
    if (k == -1) {
        cout << 0 << endl;
    } else {
        for (int i = 0; i < k; i++) {
            if (output[k - i - 1] > 9)
                // cout<<(char)(output[k-i-1]+ 'a' - 10);
                vec.push_back((char)(output[k - i - 1] + 'a' - 10));
            else
                // cout<<output[k-i-1];
                vec.push_back(output[k - i - 1]);
        }
    }
    return vec;
}

void turn_test() {
    string str;
    cin >> str;
    vector<int> vecs;

    vecs = turn(str);

    vector<int>::iterator iter;
    for (iter = vecs.begin(); iter != vecs.end(); ++iter) {
        cout << *iter;
    }

    cout << endl;

    //        return 0;
}
} // namespace std

void test_reverse_list() {
    ReverseList *reverse_list_iter = new ReverseListIteration();
    ReverseList *reverse_list_recur = new ReverseListRecursive();
    reverse_list_iter->test();
    reverse_list_recur->test();
}

void test_sqrt_x() {
    SqrtX *sqrt_x_pocket_calculator_algorithms = new SqrtXPocketCalculatorAlgorithms();
    SqrtX *sqrt_x_dichotomous_search = new SqrtXDichotomousSearch();
    SqrtX *sqrt_x_newton_iteration = new SqrtXNewtonIteration();
    sqrt_x_pocket_calculator_algorithms->test();
    sqrt_x_dichotomous_search->test();
    sqrt_x_newton_iteration->test();
}

void test_lru_cache() {
    LRUCache *lru_cache = new LRUCacheHashTablesAndBiDirectionalLinkedTables(2);
    lru_cache->test();
}

void test_sort_an_array() {
    SortAnArray *sort_an_array_quick_sort = new SortAnArrayQuickSort();
    SortAnArray *sort_an_array_heap_sorting = new SortAnArrayHeapsorting();
    SortAnArray *sort_an_array_summarize_sort = new SortAnArraySummarizeSort();
    sort_an_array_quick_sort->test();
    sort_an_array_heap_sorting->test();
    sort_an_array_summarize_sort->test();
}

void test_reverse_nodes_in_k_group() {
    ReverseNodesInKGroup *reverse_nodes_in_k_group_simulation = new ReverseNodesInKGroupSimulation();
    reverse_nodes_in_k_group_simulation->test();
}

void test_kth_largest_element_in_an_array() {
    KthLargestElementInAnArray *kth_largest_element_in_an_array_selection_methods_based_on_fast_sorting = new KthLargestElementInAnArraySelectionMethodsBasedOnFastSorting();
    KthLargestElementInAnArray *kth_largest_element_in_an_array_selection_methods_based_on_heap_sorting = new KthLargestElementInAnArraySelectionMethodsBasedOnHeapSorting();

    kth_largest_element_in_an_array_selection_methods_based_on_fast_sorting->test();
    kth_largest_element_in_an_array_selection_methods_based_on_heap_sorting->test();
}

void test_three_sum() {
    ThreeSum *three_sum_sorting_plus_double_pointer = new ThreeSumSortingPlusDoublePointer();
    three_sum_sorting_plus_double_pointer->test();
}

void test_create_binary_tree_from_descriptions() {
    createBinaryTreeFromDescriptions *create_binary_tree_from_descriptions_hash_table = new createBinaryTreeFromDescriptionsHashTable();
    create_binary_tree_from_descriptions_hash_table->test();
}

void test_binary_tree_zigzag_level_order_traversal() {
    binaryTreeZigzagLevelOrderTraversal *binary_tree_zigzag_level_order_traversal_breadth_first_traversal = new binaryTreeZigzagLevelOrderTraversalBreadthFirstTraversal();
    binary_tree_zigzag_level_order_traversal_breadth_first_traversal->test();
}

void test_best_time_to_buy_and_sell_stock() {
    bestTimeToBuyAndSellStock *best_time_to_buy_and_sell_stock_violence = new bestTimeToBuyAndSellStockViolence();
    bestTimeToBuyAndSellStock *best_time_to_buy_and_sell_stock_one_traversal = new bestTimeToBuyAndSellStockOneTraversal();
    best_time_to_buy_and_sell_stock_violence->test();
    best_time_to_buy_and_sell_stock_one_traversal->test();
}

void test_number_of_islands() {
    numberOfIslands *number_of_islands_depth_first_search = new numberOfIslandsDepthFirstSearch();
    numberOfIslands *number_of_islands_breadth_first_search = new numberOfIslandsBreadthFirstSearch();
    numberOfIslands *number_of_islands_disjoint_set_data_structure = new numberOfIslandsDisjointSetDataStructure();
    number_of_islands_depth_first_search->test();
    number_of_islands_breadth_first_search->test();
    number_of_islands_disjoint_set_data_structure->test();
}

void test_merge_two_sorted_lists() {
    mergeTwoSortedLists *merge_two_sorted_lists_recursion = new mergeTwoSortedListsRecursion();
    mergeTwoSortedLists *merge_two_sorted_lists_iterate = new mergeTwoSortedListsIterate();
    merge_two_sorted_lists_recursion->test();
    merge_two_sorted_lists_iterate->test();
}

void test_longest_substring_without_repeating_characters() {
    longestSubstringWithoutRepeatingCharacters *longest_substring_without_repeating_characters_slide_the_window = new longestSubstringWithoutRepeatingCharacters();
    longest_substring_without_repeating_characters_slide_the_window->test();
}

void test_search_in_rotated_sorted_array() {
    searchInRotatedSortedArray *search_in_rotated_sorted_array_binary_lookup = new searchInRotatedSortedArrayBinaryLookup();
    search_in_rotated_sorted_array_binary_lookup->test();
}

void test_lfu_cache() {
}

namespace std {
namespace elimination_score {
void test_elimination_score() {
    Solution *solution = new Solution();
    solution->solution();
}
} // namespace elimination_score

// namespace company_canteen {
// void test_company_canteen() {
//     Solution *solution = new Solution();
//     solution->solution();
// }
// } // namespace company_canteen

} // namespace std

int main() {
    std::correction_of_examination_papers::test();

    // std::elimination_score::test_elimination_score();
    // std::company_canteen::test_company_canteen();
    // TestReverseList();
    // TestSqrtX();
    // TestLRUCache();
    // TestSortAnArray();
    // TestReverseNodesInKGroup();
    // TestKthLargestElementInAnArray();
    // test_three_sum();
    // testcreate_binary_tree_from_descriptions();
    // test_binary_tree_zigzag_level_order_traversal();
    // test_three_sum();
    // test_best_time_to_buy_and_sell_stock();
    // test_number_of_islands();
    // test_merge_two_sorted_lists();
    // test_longest_substring_without_repeating_characters();

    //    Dataframe28 *dataframe28_fast_sorting = new Dataframe28FastSorting();
    //    dataframe28_fast_sorting->test();
    //    Dataframe28 *dataframe28_heap_sorting = new Dataframe28HeapSorting();
    //    dataframe28_heap_sorting->test();

    //    Solution sol;
    //    int numCourses=4;
    //    std::vector<std::vector<int>> prerequisites={{0,1},{1,2},{2,3}};
    //    sol.canFinish(numCourses,prerequisites);

    //    Dataframe34 *df1 = new Dataframe34Endingwithzero();
    //    Dataframe34 *df2 = new Dataframe34NonAlignedZero();
    //    df1->test();
    //    df2->test();

    //    Dataframe46 *df46_1 = new Dataframe46N1();
    //    Dataframe46 *df46_2 = new Dataframe46N2();
    //    Dataframe46 *df46_3 = new Dataframe46N3();
    //    df46_1->test();
    //    df46_2->test();
    //    df46_3->test();

    //    std::turn_test();

    //    std::ConvertLargeNumbersFromDecimalToBinary *convert_obj = new std::ConvertLargeNumbersFromDecimalToBinary();
    //    convert_obj->convert();
    //    std::cout << std::endl;
    //    std::cout << "test end" << std::endl;
    return 0;
}