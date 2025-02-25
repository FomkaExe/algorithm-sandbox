#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <array>
#include <map>
#include <unordered_map>
#include <set>

int xorAllNums_LC_2425(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> nums3(nums1.size() * nums2.size());
    for (int i = 0; i < nums1.size(); ++i) {
        for (int j = 0; j < nums2.size(); ++j) {
            nums3[i+j] = nums1[i] ^ nums2[j];
        }
    }
    int res = nums3[0] ^ nums3[1];
    for (int k = 2; k < nums3.size(); ++k) {
        res = res ^ nums3[k];
    }
    return res;

}

uint32_t reverseBits_LC_190(uint32_t n) {
    int j = 31;
    for (int i = 0; i < j; ++i, --j) {
        uint32_t temp_i = (n >> i)&1;
        uint32_t temp_j = (n >> j)&1;
        // n = (n & ~((uint32_t)1 << i)) | (((n >> j)&1) << i);
        // n = (n & ~((uint32_t)1 << j)) | (((n >> i)&1) << j);
        n = (n & ~((uint32_t)1 << i)) | (temp_j << i);
        n = (n & ~((uint32_t)1 << j)) | (temp_i << j);
    }
    return n;
}

int hammingDistance_LC_461(int x, int y) {
    int count = 0;
    while (x != 0 && y != 0) {
        if (x&1 ^ y&1) {
            ++count;
        }
        x >>= 1;
        y >>= 1;
    }
    return count;
}

bool hasAlternatingBits_LC_693(int n) {
    while (n) {
        if (n&1 == (n >> 1)&1) {
            return false;
        }
        n >>= 1;
    }
    return true;
}

int findMSBPos(int n) {
    for (int i = 0; 1 << i < n; ++i) {
        if ((n >> i)&1 && ((n >> i + 1) == 0)) {
            return i;
        }
    }
    return 0;
}

int findMSBValue(int n) {
    for (int i = 0; 1 << i < n; ++i) {
        if ((n >> i)&1 && ((n >> i + 1) == 0)) {
            return 1 << i;
        }
    }
    return 0;
}

int findComplement(int num) {
    int msb = 0;
    int tmp = num;
    while (tmp >>= 1) {
        ++msb;
    }
    return (num ^ ((1 << (msb + 1)) - 1));
}

std::vector<std::vector<int>> subsets_LC_78(std::vector<int>& nums) {
        int n = nums.size() - 1;
        int mask = (1 << nums.size()) - 1;
        std::vector<std::vector<int>> ans{std::vector<int>{}};
        while (mask) {
            int tempMask = mask;
            std::vector<int> tempVec;
            int i = 0;
            while (tempMask != 0) {
                if (tempMask&1) {
                    tempVec.push_back(nums[n - i]);
                }
                tempMask >> 1;
                i++;
            }
            ans.push_back(tempVec);
            mask--;
        }
        return ans;
}

void weirdAlgorithm_CSES() {
    long long n;
    std::cin >> n;
    std::string res = std::to_string(n) + " ";
    while (n != 1) {
        if (n%2 == 0) {
            n /= 2;
            res += std::to_string(n) + " ";
        } else {
            n = (n * 3) + 1;
            res += std::to_string(n) + " ";
        }
    }
    std::cout << res;
}

void missingNumber_CSES() {
    long long n;
    std::cin >> n;
    long long input;
    std::vector<long long> v;
    while (std::cin >> input) {
        v.push_back(input);
    }
    if (n == 2) {
        if (v[0] == 1) {
            n = 2;
        } else {
            n = 1;
        }
    } else {
        std::sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] != v[i - 1] + 1) {
                n = v[i-1] + 1;
                break;
            }
        }
    }
    std::cout << n;
    return;
}

void repetitions_CSES() {
    std::string input;
    std::cin >> input;
    if (input.size() < 2) {
        std::cout << 1;
        return;
    }
    unsigned int res = 1;
    unsigned int counter = 1;
    for (unsigned int i = 1; i < input.size(); ++i) {
        if (input[i - 1] == input[i]) {
            ++counter;
        } else {
            if (counter > res) {
                res = counter;
                counter = 1;
            } else {
                counter = 1;
            }
        }
    }
    if (counter > res) {
        res = counter;
    }
    std::cout << res;
    return;
}

void increasingArray_CSES() {
    unsigned long long vSize;
    std::cin >> vSize;
    unsigned long long input;
    std::vector<unsigned long long> v;
    while (std::cin >> input) {
        v.push_back(input);
    }
    unsigned long long moves = 0;
    unsigned long long temp = 0;
    for (int i = 1; i < vSize; ++i) {
        if (v[i - 1] > v[i]) {
            temp = v[i-1] - v[i];
            v[i] += temp;
            moves += temp;
        }
    }
    std::cout << moves;
}

void permutations_CSES() {
    // std::ifstream fin("./tests/1.in");
    // std::ofstream fout("./tests/1out.out");
    uint32_t n;
    // fin >> n;
    std::cin >> n;
    std::vector<uint32_t> v;
    if (n == 1) {
        std::cout << 1;
        return;
    }
    if (n < 4) {
        std::cout << "NO SOLUTION";
        return;
    }
    for (int i = 2; i <= n; i += 2) {
        v.push_back(i);
    }
    for (int i = 1; i <= n; i += 2) {
        v.push_back(i);
    }
    int i = 0;
    while (i < v.size()) {
        // fout << v[i];
        std::cout <<  v[i] << " ";
        ++i;
    }
    // return;
}

void numberSpiral_CSES() {
        // Input
    uint64_t n, input;
    std::cin >> n;
    std::vector<std::pair<uint64_t, uint64_t>> v;
    std::vector<uint64_t> res(n, 0);
    for (int i = 0; i < n; ++i) {
        uint64_t y, x;
        std::cin >> y;
        std::cin >> x;
        v.push_back(std::pair<uint64_t, uint64_t>(y, x));
    }

    // Algorithm
    for (int i = 0; i < n; ++i) {
        if (v[i].first > v[i].second) {         // y > x
            if (v[i].first % 2 == 0) { // y is even
                uint64_t temp = v[i].first * v[i].first;
                temp -= v[i].second - 1;
                res[i] = temp;
            } else {                   // y is odd
                uint64_t temp = (v[i].first - 1) * (v[i].first - 1) + 1;
                temp += v[i].second - 1;
                res[i] = temp;
            }
        } else if (v[i].first < v[i].second) {  // y < x
            if (v[i].second % 2 == 0)  { // x is even
                uint64_t temp = (v[i].second - 1) *( v[i].second - 1) + 1;
                temp += v[i].first - 1;
                res[i] = temp;
            } else {                     // x is odd
                uint64_t temp = v[i].second * v[i].second;
                temp -= v[i].first - 1;
                res[i] = temp;
            }
        } else {                                // y == x
            res[i] = v[i].first * v[i].first - (v[i].first - 1);
        }
    }

    // Output
    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << '\n';
    }
    return;
}

uint16_t subarraySum_LC_560(std::vector<uint16_t> &nums, uint16_t k) {
    int l = 0, r = 0, count = 0;
    uint16_t sum = nums[l];
    while (true)
    {
        if (sum > k)
        {
            if (l == r && l + 1 < nums.size())
            {
                ++r;
                ++l;
                sum = nums[r];
            }
            else if (l < r)
            {
                sum -= nums[l];
                ++l;
            }
            else
            {
                break;
            }
        }
        else if (sum < k)
        {
            if (r + 1 < nums.size())
            {
                ++r;
                sum += nums[r];
            }
            else
            {
                break;
            }
        }
        else if (sum == k)
        {
            ++count;
            if (r + 1 < nums.size())
            {
                ++r;
                sum += nums[r];
            }
            else
            {
                break;
            }
        }
    }
    return count;
}

void nearestSmallerValues_CSES() {
    uint32_t n;
    std::cin >> n;
    std::vector<uint32_t> arr;
    uint32_t val;
    while (std::cin >> val) {
        arr.push_back(val);
    }

    std::stack<std::pair<uint32_t, uint32_t>> st;
    for (unsigned int i = 0; i < arr.size(); ++i) {
        while (!st.empty() && st.top().first >= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            std::cout << 0 << ' ';
        } else {
            std::cout << st.top().second << ' ';
        }
        st.push(std::make_pair(arr[i], i + 1));
    }
    return;
}

std::vector<uint32_t> bracketsMatching_CSA(std::string str) {
    // ")(()))"
    std::vector<uint32_t> indArr(str.size(), 0);
    std::stack<uint32_t> st;
    /*
        if balanced return indices array
        if unbalanced return empty array
    */
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            st.push(i);
        }

        if (str[i] == ')') {
            if (!st.empty()) {
                indArr[st.top()] = i;
                indArr[i] = st.top();
                st.pop();
            } else {
                return std::vector<uint32_t>();
            }
        }
    }

    if (!st.empty()) {
        return std::vector<uint32_t>();
    }

    return indArr;
}

int numSubarrayProductLessThanK_LC_713(std::vector<int> &nums, int k)
{
    uint32_t l = 0, r = 0;
    uint32_t product = nums[l];
    uint16_t counter = (nums.size() * (nums.size() + 1) / 2);
    while (true)
    {
        if (product < k)
        {
            if (r + 1 >= nums.size())
            {
                break;
            }
            r++;
            product *= nums[r];
        }
        else if (product >= k)
        {
            counter--;
            if (r + 1 < nums.size())
            {
                r++;
                product *= nums[r];
            }
            else if (l + 1 < nums.size() && r + 1 >= nums.size())
            {
                product /= nums[l];
                l++;
            }
            else if (l + 1 >= nums.size() && r + 1 >= nums.size())
            {
                break;
            }
            else if (l == r)
            {
                l++;
                r++;
                product = nums[l];
            }
        }
    }
    return counter;
}

std::vector<int> nextGreaterElement_LC_496(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> result = nums1;
    for (int i = 0; i < nums1.size(); ++i) {
        result[i] = -1;
        bool greater = false;
        for (int j = 0; j < nums2.size(); ++j) {
            if (greater) {
                if (nums1[i] < nums2[j]) {
                    result[i] = nums2[j];
                    break;
                }
            }
            if (nums1[i] == nums2[j]) {
                greater = true;
            }
        }
    }
    return result;
}

int evalRPN_LC_150(std::vector<std::string>& tokens) {
    std::stack<int> stack;
    int res = std::stoi(tokens.front());
    for (int i = 1; i < tokens.size(); ++i) {
        if (tokens[i] == "+") {
            int t = stack.top();
            stack.pop();
            res += t;
            break;
        } else if (tokens[i] == "-") {
            int t = stack.top();
            stack.pop();
            res -= t;
            break;
        } else if (tokens[i] == "*") {
            int t = stack.top();
            stack.pop();
            res *= t;
            break;
        } else if (tokens[i] == "/") {
            int t = stack.top();
            stack.pop();
            res /= t;
                break;
        } else {
            stack.push(std::stoi(tokens[i]));
            break;
        }
    }
    return res;
}

bool isHappy_LC_202(int n) {
    std::unordered_map<int, int> hashTable;
    hashTable[n]++;
    while (n != 1) {
        int temp = 0;
        while (n != 0) {
            temp += (n%10) * (n%10);
            n /= 10;
        }
        n = temp;
        if (hashTable[n] < 2) {
            hashTable[n]++;
        } else {
            return false;
        }
    }
    return true;
}

void twoKnightCSES() {
    // fuck CSES
}

void twoSetsCSES() {
    // fuck CSES
}

void bitStringsCSES() {
    // fuck CSES
}

int lengthOfLongestSubstringSet_LC_3(std::string s) {
    std::set<char> set;
    set.insert(s[0]);
    int l = 0;
    int r = 0;
    int maxSize = 1;
    int tempSize = 1;
    while (r < s.size() - 1) {
        if (!set.count(s[r+1])) {
            ++tempSize;
            ++r;
            set.insert(s[r]);
        } else {
            maxSize = tempSize > maxSize ? tempSize : maxSize;
            if (l < r) {
                set.erase(s[l]);
                --tempSize;
                ++l;
            } else {
                set.erase(s[l]);
                ++l;
                ++r;
                set.insert(s[r]);
            }
        }
    }
    maxSize = tempSize > maxSize ? tempSize : maxSize;
    return maxSize;
}

int main() {

}
